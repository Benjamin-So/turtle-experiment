#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/wrench_stamped.hpp"

class WrenchSubscriber : public rclcpp::Node
{
public:
    WrenchSubscriber()
    : Node("wrench_subscriber")
    {
        // Create a subscription to the '/wrench_data' topic
        subscription_ = this->create_subscription<geometry_msgs::msg::WrenchStamped>(
            "/wrench_data", 10,
            std::bind(&WrenchSubscriber::wrenchCallback, this, std::placeholders::_1));
    }

private:
    void wrenchCallback(const geometry_msgs::msg::WrenchStamped::SharedPtr msg)
    {
        // Print the received WrenchStamped message
        RCLCPP_INFO(this->get_logger(), "Received wrench data:");
        RCLCPP_INFO(this->get_logger(), "Force: [%f, %f, %f]", msg->wrench.force.x, msg->wrench.force.y, msg->wrench.force.z);
        RCLCPP_INFO(this->get_logger(), "Torque: [%f, %f, %f]", msg->wrench.torque.x, msg->wrench.torque.y, msg->wrench.torque.z);
    }

    rclcpp::Subscription<geometry_msgs::msg::WrenchStamped>::SharedPtr subscription_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<WrenchSubscriber>());
    rclcpp::shutdown();
    return 0;
}
