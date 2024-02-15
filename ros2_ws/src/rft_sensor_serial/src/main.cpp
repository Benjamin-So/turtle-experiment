#define ROS_RFT_SERIAL_SW_VER	"VER 0.0.1(Read Only)"

// CPP libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <mutex>


// CPP for testing node: DELTE BEFORE PUB
#include <chrono>
#include <functional>
#include <memory>
using namespace std::chrono_literals;

// ROS Libraries
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "geometry_msgs/msg/wrench_stamped.hpp"

// Supporting File
#include "rft_com_library/RFT_COM.h"

// SRV File
#include "rft_interfaces/srv/rft_operation_request.hpp"

/*
	Definitions
*/
#define RFT_SERVICE_OK  			(0)
#define RFT_SERVICE_RQST_TIMEOUT 	(0xF0)

/*
	Global Variables
*/
std::string g_com_port 			= "/dev/ttyUSB0";	// default serial device name...
int 		g_baud_rate 		= 115200;			// default baud-rate serial device...
float		g_force_divider 	= 50.0f;			// for more information to refer the RFT sensor manual
float		g_torque_divider 	= 2000.0f;			// for more information to refer the RFT sensor manual
std::mutex  g_com_port_mutex;

CRT_RFT_UART RFT_SENSOR;

/*
	Funcitions
*/
void init_param(const rclcpp::Node::SharedPtr& node);
bool rft_operation_service(const std::shared_ptr<rft_interfaces::srv::RftOperationRequest::Request> request,
                            std::shared_ptr<rft_interfaces::srv::RftOperationRequest::Response> response,
                            const rclcpp::Node::SharedPtr& node);



// uint8_t rft_response_wait(uint8_t opType);
uint8_t rft_response_wait(uint8_t op_type, const rclcpp::Node::SharedPtr& node);

uint8_t rft_response_display(uint8_t op_type, const rclcpp::Node::SharedPtr& node);

uint8_t rft_send_command(const std::shared_ptr<rft_interfaces::srv::RftOperationRequest::Request> request,
                         const rclcpp::Node::SharedPtr& node);


/*
	The main function of RFT Serial Node.....
	- you can send the operation command using rqt -> service caller
	- you can see the force/torque data using rqt_plot
	  * rqt_plot /RFT_FORCE/wrench/force
	  * rqt_plot /RFT_FORCE/wrench/torque
*/


class SerialParams : public rclcpp::Node
{
public:
    SerialParams() : Node("serial_params_rclcpp") {
        this->declare_parameter("RFT_COM_PORT", g_com_port);
        this->declare_parameter("RFT_COM_BAUD", g_baud_rate);
        this->declare_parameter("RFT_FORCE_DIVIDER", g_force_divider);
        this->declare_parameter("RFT_TORQUE_DIVIDER", g_torque_divider);
        this->declare_parameter("RFT_SERIAL_SW_VER", ROS_RFT_SERIAL_SW_VER);
    }
private:
};

class WrenchPublisher : public rclcpp::Node
{
public:
  WrenchPublisher()
  : Node("wrench_publisher")
  {
    this->declare_parameter("RFT_COM_PORT", g_com_port);
    this->declare_parameter("RFT_COM_BAUD", g_baud_rate);
    this->declare_parameter("RFT_FORCE_DIVIDER", g_force_divider);
    this->declare_parameter("RFT_TORQUE_DIVIDER", g_torque_divider);
    this->declare_parameter("RFT_SERIAL_SW_VER", ROS_RFT_SERIAL_SW_VER);

    // Create a publisher with topic name '/wrench_data' and message type 'geometry_msgs::msg::WrenchStamped'
    pub_ = this->create_publisher<geometry_msgs::msg::WrenchStamped>("/wrench_data", 1);

    // Set the loop rate (in Hz)
    timer_ = this->create_wall_timer(std::chrono::milliseconds(100), std::bind(&WrenchPublisher::publishWrench, this));
  }

private:
  void publishWrench()
  {
    bool isSensorOk = false;
    if (true){
      std::lock_guard<std::mutex> lock(g_com_port_mutex);
      isSensorOk = RFT_SENSOR.readWorker();
      RCLCPP_WARN(this->get_logger(), "isSensorOk %s", isSensorOk ? "true": "false");
      RCLCPP_INFO(this->get_logger(), "m_bConnected: %s", RFT_SENSOR.isConnected() ? "true" : "false");
      RCLCPP_INFO(this->get_logger(), "m_bConnected: %i", RFT_SENSOR.m_nCurrMode);
    }

    if( (RFT_SENSOR.m_nCurrMode == CMD_FT_CONT) && isSensorOk ){
      // Create a new WrenchStamped message
      auto wrench_msg = std::make_unique<geometry_msgs::msg::WrenchStamped>();

      // Fill in the header
      wrench_msg->header.stamp = this->now();
      wrench_msg->header.frame_id = "base_link"; // example frame_id

      float forceX = RFT_SENSOR.m_RFT_IF_PACKET.m_rcvdForce[1];
      float forceY = RFT_SENSOR.m_RFT_IF_PACKET.m_rcvdForce[1];
      float forceZ = RFT_SENSOR.m_RFT_IF_PACKET.m_rcvdForce[2];
      float torqueX = RFT_SENSOR.m_RFT_IF_PACKET.m_rcvdForce[3];
      float torqueY = RFT_SENSOR.m_RFT_IF_PACKET.m_rcvdForce[4];
      float torqueZ = RFT_SENSOR.m_RFT_IF_PACKET.m_rcvdForce[5];

      wrench_msg->wrench.force.x = RFT_SENSOR.m_RFT_IF_PACKET.m_rcvdForce[1];
      wrench_msg->wrench.force.y = RFT_SENSOR.m_RFT_IF_PACKET.m_rcvdForce[1];
      wrench_msg->wrench.force.z = RFT_SENSOR.m_RFT_IF_PACKET.m_rcvdForce[2];
      wrench_msg->wrench.torque.x = RFT_SENSOR.m_RFT_IF_PACKET.m_rcvdForce[3];
      wrench_msg->wrench.torque.y = RFT_SENSOR.m_RFT_IF_PACKET.m_rcvdForce[4];
      wrench_msg->wrench.torque.z = RFT_SENSOR.m_RFT_IF_PACKET.m_rcvdForce[5];

      RCLCPP_INFO(this->get_logger(), "ForceX: %f ForceY: %f ForceZ: %f TorqueX: %f TorqueY: %f TorqueZ: %f ", forceX, forceY, forceZ, torqueX, torqueY, torqueZ);

      // Publish the message
      pub_->publish(std::move(wrench_msg));
    }
  }

  rclcpp::Publisher<geometry_msgs::msg::WrenchStamped>::SharedPtr pub_;
  rclcpp::TimerBase::SharedPtr timer_;
};



int main(int argc, char** argv)
{
  rclcpp::init(argc, argv);
  // Serial Logger Node
  auto node = std::make_shared<SerialParams>();
  
  // initialize parameters
  init_param(node);

	// initialize COM port
  if( RFT_SENSOR.openPort( (char*)g_com_port.c_str(), g_baud_rate ) == false )
	{
		RCLCPP_ERROR(node->get_logger(), "COM Port Open Error");
		return 0;
	}
  else{
    RCLCPP_ERROR(node->get_logger(), "COM Port Opened Successfully");
  }

	// initialize force/torque divider
	RFT_SENSOR.m_RFT_IF_PACKET.setDivider(g_force_divider, g_torque_divider);

  // Create a service server and associate it with the callback function
  rclcpp::Service<rft_interfaces::srv::RftOperationRequest>::SharedPtr service = node ->create_service<rft_interfaces::srv::RftOperationRequest>("op_service", std::bind(rft_operation_service, std::placeholders::_1, std::placeholders::_2, node));

  // Create publisher node 
  auto pub_node = std::make_shared<WrenchPublisher>();

  // Create an executor with two threads
  rclcpp::executors::MultiThreadedExecutor executor;
  // Add the node to the executor
  executor.add_node(node);
  executor.add_node(pub_node);
  executor.spin();

  // Close the serial port before exiting
  bool port_stat = RFT_SENSOR.closePort();

  // close COM port
  if(port_stat== false)
  {
    RCLCPP_ERROR(node->get_logger(), "COM Port Close Error");
  }
  else{
    RCLCPP_INFO(node->get_logger(), "COM Port closed successfully");
  }
  // removed rclcpp:spin()
  rclcpp::shutdown();
  return 0;
}


void init_param(const rclcpp::Node::SharedPtr& node)
{
  // Log whether default/custom params are used
  std::string rftComPort;
  node->get_parameter("RFT_COM_PORT", rftComPort);
  if (rftComPort == g_com_port)
  {
    RCLCPP_INFO(node->get_logger(), "RFT Serial port is using the default value: %s", rftComPort.c_str());
  }
  else{
    RCLCPP_INFO(node->get_logger(), "RFT Serial port is NOT using the default value. Value used is : %s", rftComPort.c_str());
  }

  int gBaudRate;
  node->get_parameter("RFT_COM_BAUD", gBaudRate);
  if (gBaudRate == g_baud_rate)
  {
    RCLCPP_INFO(node->get_logger(), "RFT Baud Rate is using the default value: %d", gBaudRate);
  }
  else{
    RCLCPP_INFO(node->get_logger(), "RFT Baud Rate is NOT using the default value. Value used is : %d", gBaudRate);
  }

  float rftForceDivider;
  node->get_parameter("RFT_FORCE_DIVIDER", rftForceDivider);
  if (rftForceDivider == g_force_divider)
  {
    RCLCPP_INFO(node->get_logger(), "RFT Force Divider is using the default value: %f", rftForceDivider);
  }
  else{
    RCLCPP_INFO(node->get_logger(), "RFT Force Divider is NOT using the default value. Value used is : %f", rftForceDivider);
  }
	

  float rftTorqueDivider;
  node->get_parameter("RFT_TORQUE_DIVIDER", rftTorqueDivider);
  if (rftTorqueDivider == g_torque_divider)
  {
    RCLCPP_INFO(node->get_logger(), "RFT Force Divider is using the default value: %f", rftTorqueDivider);
  }
  else{
    RCLCPP_INFO(node->get_logger(), "RFT Force Divider is NOT using the default value. Value used is : %f", rftTorqueDivider);
  }

	// Check the s/w version.
  std::string rftSerialSoftwareVersion;
  node->get_parameter("RFT_SERIAL_SW_VER", rftSerialSoftwareVersion);
	RCLCPP_INFO(node->get_logger(), "S/W Version is : %s", rftSerialSoftwareVersion.c_str());
}

/*
	service operation...
*/
bool rft_operation_service(const std::shared_ptr<rft_interfaces::srv::RftOperationRequest::Request> request,
                            std::shared_ptr<rft_interfaces::srv::RftOperationRequest::Response> response,
                            const rclcpp::Node::SharedPtr& node)
{
  RCLCPP_INFO(node->get_logger(),"RCVD SERVICE REQUEST: %d, %d, %d, %d", request->op_type, request->param1, request->param2, request->param3);
	uint8_t commandSend = RFT_SERVICE_OK;
	
  //ensure that certain sections of the code are executed by only one thread at a time, preventing potential race conditions.
	std::lock_guard<std::mutex> lock(g_com_port_mutex);
  commandSend = rft_send_command(request, node);
	
  RCLCPP_INFO(node->get_logger(),"Recieved: %d from rft_send_command", commandSend);
	if( commandSend == RFT_SERVICE_OK )
	{
		RCLCPP_INFO(node->get_logger(),"RESPONSE WAIT");
		// Set bias & Stop command doesn't have response packet.
		if( (request->op_type != CMD_SET_BIAS) && (request->op_type != CMD_FT_CONT_STOP) ) 
		{
			response->result = rft_response_wait(request->op_type, node);
		}
	}
	else
	{
		response->result = commandSend;
	}
	
	return true;
}

uint8_t rft_send_command(const std::shared_ptr<rft_interfaces::srv::RftOperationRequest::Request> request,
                         const rclcpp::Node::SharedPtr& node)
{
    RCLCPP_INFO(node->get_logger(),"From within Send Command: %d, %d, %d, %d", request->op_type, request->param1, request->param2, request->param3);
    uint8_t result = RFT_SERVICE_OK;
    switch(request->op_type)
    {
      case CMD_GET_PRODUCT_NAME: //1
        RCLCPP_INFO(node->get_logger(),"RCVD SERVICE REQUEST: get product name");
        RFT_SENSOR.rqst_ProductName();
      break;

      case CMD_GET_SERIAL_NUMBER:		//2 
        RCLCPP_INFO(node->get_logger(),"RCVD SERVICE REQUEST: get serial number");
        RFT_SENSOR.rqst_SerialNumber();
      break;

      case CMD_GET_FIRMWARE_VER: //3
        RCLCPP_INFO(node->get_logger(),"RCVD SERVICE REQUEST: get firmware version");
        RFT_SENSOR.rqst_Firmwareverion();
      break;

      case CMD_SET_ID:					// Only CAN version //4
        RCLCPP_INFO(node->get_logger(),"RCVD SERVICE REQUEST: set ID - is not supported");
        result = NOT_SUPPORTED_CMD;
      break;

      case CMD_GET_ID:					// Only CAN version //5
        RCLCPP_INFO(node->get_logger(),"RCVD SERVICE REQUEST: get ID - is not supported");
        result = NOT_SUPPORTED_CMD;
      break;

      case CMD_SET_COMM_BAUDRATE:			// Only UART version, CAN : 1Mbps Fixed //6
        RCLCPP_INFO(node->get_logger(),"RCVD SERVICE REQUEST: set baud-rate");
        RFT_SENSOR.set_Comm_Speed(request->param1);		
      break;

      case CMD_GET_COMM_BAUDRATE:	// 7
        RCLCPP_INFO(node->get_logger(),"RCVD SERVICE REQUEST: get baud-rate");
        RFT_SENSOR.rqst_CommSpeed();	
      break;

      case CMD_SET_FT_FILTER:	// 8
        RCLCPP_INFO(node->get_logger(),"RCVD SERVICE REQUEST: set filter type");
        RFT_SENSOR.set_FT_Filter_Type(request->param1, request->param2);			
      break;

      case CMD_GET_FT_FILTER:				// 9
        RCLCPP_INFO(node->get_logger(),"RCVD SERVICE REQUEST: get filter type");
        RFT_SENSOR.rqst_FT_Filter_Type();	
      break;

      case CMD_FT_ONCE:	// 10
        RCLCPP_INFO(node->get_logger(),"RCVD SERVICE REQUEST: get force/torque once");
        RFT_SENSOR.rqst_FT();			
      break;

      case CMD_FT_CONT:	//11
        RCLCPP_INFO(node->get_logger(),"RCVD SERVICE REQUEST: get force/torque cont.");
        RFT_SENSOR.rqst_FT_Continuous();
      break;

      case CMD_FT_CONT_STOP:			// 12
        RCLCPP_INFO(node->get_logger(),"RCVD SERVICE REQUEST: stop force/torque  - There is no response packet");
        RFT_SENSOR.rqst_FT_Stop();
      break;

      case CMD_RESERVED_1:	// 13
        result = NOT_SUPPORTED_CMD;		
      break;

      case CMD_RESERVED_2:				// 14
        result = NOT_SUPPORTED_CMD;
      break;

      case CMD_SET_CONT_OUT_FRQ: 	// 15
        RCLCPP_INFO(node->get_logger(),"RCVD SERVICE REQUEST: set output frq.");
        RFT_SENSOR.set_FT_Cont_Interval(request->param1);		
      break;

      case CMD_GET_CONT_OUT_FRQ: // 16
        RCLCPP_INFO(node->get_logger(),"RCVD SERVICE REQUEST: get output frq.");
        RFT_SENSOR.rqst_FT_Cont_Interval();			
      break;

      case CMD_SET_BIAS:		// 17
        RCLCPP_INFO(node->get_logger(),"RCVD SERVICE REQUEST: set bias - There is no response packet and keep the last received commands....");
        RFT_SENSOR.set_FT_Bias(request->param1);			
      break;

      case CMD_GET_OVERLOAD_COUNT: // 18
        RCLCPP_INFO(node->get_logger(),"RCVD SERVICE REQUEST: get overload count");
        RFT_SENSOR.rqst_FT_OverloadCnt();		
      break;
      default:
        result = NOT_SUPPORTED_CMD;
      break;
    }
    return result;
}

/*
	Wait the response packet from the RFT sensor
*/
// uint8_t rft_response_wait(uint8_t opType)
uint8_t rft_response_wait(uint8_t op_type, const rclcpp::Node::SharedPtr& node)
{
	int result = RFT_SERVICE_OK;
  RCLCPP_INFO(node->get_logger(),"rft_response_wait called successfully: recieved op_type: %d", op_type);

	int waitTimeOut = 0;
	
	bool isRcvd = false;
	do
	{
		if( waitTimeOut >= 100 )
		{
			RCLCPP_WARN(node->get_logger(), "RCVD SERVICE TIMEOUT");
			isRcvd = true;
			result = RFT_SERVICE_RQST_TIMEOUT;
		}
		
		if( RFT_SENSOR.m_bIsRcvd_Response_Pkt)
		{
			isRcvd = true;
			rft_response_display(op_type, node);
		}
		
		waitTimeOut++;
		usleep(10000);
		
	}while( isRcvd == false );
	
	return result;
}

/*
	Display the response packet
	The detail of the response packet of the RFT Sensor, Please refer to the manual
*/
uint8_t rft_response_display(uint8_t op_type, const rclcpp::Node::SharedPtr& node)
{
  RCLCPP_INFO(node->get_logger(),"NOW WERE COOKING WITH GAS ");

	uint8_t result = RFT_SERVICE_OK;
	switch ( op_type )
	{
	case CMD_GET_PRODUCT_NAME:
		RCLCPP_INFO(node->get_logger(),"%s", RFT_SENSOR.m_RFT_IF_PACKET.m_rcvd_product_name);
		break;
	case CMD_GET_SERIAL_NUMBER:
		RCLCPP_INFO(node->get_logger(),"%s", RFT_SENSOR.m_RFT_IF_PACKET.m_rcvd_serial_number);
		break;
	case CMD_GET_FIRMWARE_VER:
		RCLCPP_INFO(node->get_logger(),"%s", RFT_SENSOR.m_RFT_IF_PACKET.m_rcvd_firmware_version);
		break;
	case CMD_SET_ID:
		result = NOT_SUPPORTED_CMD;
		break;
	case CMD_GET_ID:
		result = NOT_SUPPORTED_CMD;
		break;
	case CMD_SET_COMM_BAUDRATE:
		RCLCPP_INFO(node->get_logger(),"Cmd Type: %d, Result: %d, Err. Code: %d", RFT_SENSOR.m_RFT_IF_PACKET.m_response_cmd, RFT_SENSOR.m_RFT_IF_PACKET.m_response_result, RFT_SENSOR.m_RFT_IF_PACKET.m_response_errcode );
		result = RFT_SENSOR.m_RFT_IF_PACKET.m_response_errcode;
		break;
	case CMD_GET_COMM_BAUDRATE:
		RCLCPP_INFO(node->get_logger(),"Baud: %d, new Baud: %d", RFT_SENSOR.m_RFT_IF_PACKET.m_rcvd_curr_comm_baudrate, RFT_SENSOR.m_RFT_IF_PACKET.m_rcvd_set_comm_baudrate);
		break;
	case CMD_SET_FT_FILTER:
		RCLCPP_INFO(node->get_logger(),"Cmd Type: %d, Result: %d, Err. Code: %d", RFT_SENSOR.m_RFT_IF_PACKET.m_response_cmd, RFT_SENSOR.m_RFT_IF_PACKET.m_response_result, RFT_SENSOR.m_RFT_IF_PACKET.m_response_errcode );
		result = RFT_SENSOR.m_RFT_IF_PACKET.m_response_errcode;
		break;
	case CMD_GET_FT_FILTER:
		RCLCPP_INFO(node->get_logger(),"filter type: %d, sub. setting: %d", RFT_SENSOR.m_RFT_IF_PACKET.m_rcvd_filter_type, RFT_SENSOR.m_RFT_IF_PACKET.m_rcvd_filter_setting_value);
		break;
	case CMD_FT_ONCE:
		RCLCPP_INFO(node->get_logger(),"%0.3f, %.03f, %.03f, %0.3f, %.03f, %.03f",
		RFT_SENSOR.m_RFT_IF_PACKET.m_rcvdForce[0], RFT_SENSOR.m_RFT_IF_PACKET.m_rcvdForce[1], RFT_SENSOR.m_RFT_IF_PACKET.m_rcvdForce[2],
		RFT_SENSOR.m_RFT_IF_PACKET.m_rcvdForce[3], RFT_SENSOR.m_RFT_IF_PACKET.m_rcvdForce[4], RFT_SENSOR.m_RFT_IF_PACKET.m_rcvdForce[5] );	
		break;
	case CMD_FT_CONT:
		// This response packet is published.. see the while() of main() function.
		RCLCPP_INFO(node->get_logger(),"RFT Force Toque topic will be published...");
		break;
	case CMD_FT_CONT_STOP:
		// THERE IS NO - RESPONSE PACKET
		break;
	case CMD_RESERVED_1:
		result = NOT_SUPPORTED_CMD;
		break;
	case CMD_RESERVED_2:
		result = NOT_SUPPORTED_CMD;
		break;
	case CMD_SET_CONT_OUT_FRQ:
		RCLCPP_INFO(node->get_logger(),"Cmd Type: %d, Result: %d, Err. Code: %d", RFT_SENSOR.m_RFT_IF_PACKET.m_response_cmd, RFT_SENSOR.m_RFT_IF_PACKET.m_response_result, RFT_SENSOR.m_RFT_IF_PACKET.m_response_errcode );
		result = RFT_SENSOR.m_RFT_IF_PACKET.m_response_errcode;
		break;
	case CMD_GET_CONT_OUT_FRQ:
		RCLCPP_INFO(node->get_logger(),"output frq: %d", RFT_SENSOR.m_RFT_IF_PACKET.m_rcvd_tx_frq);
		break;
	case CMD_SET_BIAS:
		// THERE IS NO - RESPONSE PACKET
		break;
	case CMD_GET_OVERLOAD_COUNT:
		RCLCPP_INFO(node->get_logger(),"overload ount: %d, %d, %d, %d, %d, %d", 
		RFT_SENSOR.m_RFT_IF_PACKET.m_rcvdOverloadCnt[0], RFT_SENSOR.m_RFT_IF_PACKET.m_rcvdOverloadCnt[1], RFT_SENSOR.m_RFT_IF_PACKET.m_rcvdOverloadCnt[2],
		RFT_SENSOR.m_RFT_IF_PACKET.m_rcvdOverloadCnt[3], RFT_SENSOR.m_RFT_IF_PACKET.m_rcvdOverloadCnt[4], RFT_SENSOR.m_RFT_IF_PACKET.m_rcvdOverloadCnt[5] );
		break;

	default:
		result = NOT_SUPPORTED_CMD;
		break;
	}	
	
	return result;
}