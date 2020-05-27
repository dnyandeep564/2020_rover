#include <ros/ros.h>
#include <std_msgs/Float64.h>

int main(int argc,char** argv)
{
	ros::init(argc, argv, "command");
	ros::NodeHandle nh;
	
	ros::Publisher centre_right_pub = nh.advertise<std_msgs::Float64>("rover/bogie_right_wheel_rm_controller/command",1);

	ros::Rate loopRate(10);

	while(ros::ok())
	{
		std_msgs::Float64 msg;
		msg.data = 10.0;
		centre_right_pub.publish(msg);
		loopRate.sleep();
	}	
	return 0;
}
