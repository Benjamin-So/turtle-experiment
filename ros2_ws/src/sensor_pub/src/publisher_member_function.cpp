#include <chrono>
#include <memory>

// ROS Libraries
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "geometry_msgs/msg/wrench_stamped.hpp"
#include <random>

// Supporting File
#include "rft_com_library/RFT_COM.h"

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
#define ROS_RFT_SERIAL_SW_VER	"VER 0.0.1(Read Only)"


CRT_RFT_UART RFT_SENSOR;


using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
 * member function as a callback from the timer. */

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
    RFT_SENSOR.rqst_FT_Continuous();
  
    // Create a new WrenchStamped message
    auto wrench_msg = std::make_unique<geometry_msgs::msg::WrenchStamped>();

    // Fill in the header
    wrench_msg->header.stamp = this->now();
    wrench_msg->header.frame_id = "base_link"; // example frame_id

    RCLCPP_INFO(this->get_logger(), "m_bConnected: %s", RFT_SENSOR.readWorker() ? "true" : "false");

    wrench_msg->wrench.force.x = RFT_SENSOR.m_RFT_IF_PACKET.m_rcvdForce[1];
    wrench_msg->wrench.force.y = RFT_SENSOR.m_RFT_IF_PACKET.m_rcvdForce[1];
    wrench_msg->wrench.force.z = RFT_SENSOR.m_RFT_IF_PACKET.m_rcvdForce[2];
    wrench_msg->wrench.torque.x = RFT_SENSOR.m_RFT_IF_PACKET.m_rcvdForce[3];
    wrench_msg->wrench.torque.y = RFT_SENSOR.m_RFT_IF_PACKET.m_rcvdForce[4];
    wrench_msg->wrench.torque.z = RFT_SENSOR.m_RFT_IF_PACKET.m_rcvdForce[5];

    // Publish the message
    pub_->publish(std::move(wrench_msg));
  }

  rclcpp::Publisher<geometry_msgs::msg::WrenchStamped>::SharedPtr pub_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<WrenchPublisher>();

  // initialize COM port
  if( RFT_SENSOR.openPort( (char*)g_com_port.c_str(), g_baud_rate ) == false )
	{
		RCLCPP_ERROR(node->get_logger(), "COM Port Open Error");
		return 0;
	}
  else{
    RCLCPP_ERROR(node->get_logger(), "COM Port Opened Successfully");
  }
  RFT_SENSOR.m_RFT_IF_PACKET.setDivider(g_force_divider, g_torque_divider);

  rclcpp::spin(node);

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

  rclcpp::shutdown();
  return 0;
}
