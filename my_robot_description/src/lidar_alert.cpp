#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"

class LidarAlertNode : public rclcpp::Node {
public:
    LidarAlertNode() : Node("lidar_alert_node") {
        subscription_ = this->create_subscription<sensor_msgs::msg::LaserScan>(
            "/scan",
            10, // queue size
            std::bind(&LidarAlertNode::scanCallback, this, std::placeholders::_1));
    }
private:
    void scanCallback(const sensor_msgs::msg::LaserScan::SharedPtr msg) {
        double threshold = 10.0; // detect evrything that is closer then threshold value

        for (auto range : msg->ranges) {
            if (range < threshold) {
                RCLCPP_INFO(this->get_logger(), "Obstacle detected %.2f meters", range);
                break;
            }
        }
    }

    rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr subscription_;

};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<LidarAlertNode>());
    rclcpp::shutdown();
    return 0;
}
