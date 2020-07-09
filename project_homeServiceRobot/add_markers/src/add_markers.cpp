#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include "std_msgs/String.h"
#include <nav_msgs/Odometry.h>
#include <string.h>

void odomCallback(nav_msgs::Odometry data)
{
    double x,y,w;
    x = data.pose.pose.position.x;
    y = data.pose.pose.position.y;
    w = data.pose.pose.orientation.w;

    ROS_INFO("x: %1.2f, y: %1.2f, z: %1.2f",(float)x, (float)y ,(float)w);
}

int main( int argc, char** argv )
{
  ros::init(argc, argv, "add_markers");
  ros::NodeHandle n;
  ros::Rate r(1);
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);

  ros::Subscriber marker_sub = n.subscribe("odom", 1000, odomCallback); //nav_msgs/Odometry.msg


  ROS_INFO("Before while loop");
//   while (ros::ok())
//   {
    ROS_INFO("in");

    // %EndTag(INIT)%

    // Set our initial shape type to be a cube
    // %Tag(SHAPE_INIT)%
    uint32_t shape = visualization_msgs::Marker::CUBE;
    // %EndTag(SHAPE_INIT)%

    // %Tag(MARKER_INIT)%

    visualization_msgs::Marker marker;

    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
    marker.header.frame_id = "/map";
    marker.header.stamp = ros::Time::now();


    // %EndTag(MARKER_INIT)%

    // Set the namespace and id for this marker.  This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
    // %Tag(NS_ID)%
    marker.ns = "add_markers";
    marker.id = 0;

    // %EndTag(NS_ID)%

    // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
    // %Tag(TYPE)%
    marker.type = shape;

    // %EndTag(TYPE)%

    // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
    // %Tag(ACTION)%
    marker.action = visualization_msgs::Marker::ADD;
    // %EndTag(ACTION)%

    // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
    // %Tag(POSE)%
    marker.pose.position.x = -3.45;
    marker.pose.position.y = -2.87;
    marker.pose.orientation.w = 0.00247;

    // %EndTag(POSE)%

    // Set the scale of the marker -- 1x1x1 here means 1m on a side
    // %Tag(SCALE)%
    marker.scale.x = 0.15;
    marker.scale.y = 0.15;
    marker.scale.z = 0.15;

    // %EndTag(SCALE)%

    // Set the color -- be sure to set alpha to something non-zero!
    // %Tag(COLOR)%
    marker.color.r = 1.0f;
    marker.color.g = 0.0f;
    marker.color.b = 0.0f;
    marker.color.a = 1.0;

    // %EndTag(COLOR)%

    // %Tag(LIFETIME)%



    // marker.lifetime = ros::Duration();



    // %EndTag(LIFETIME)%

    // Publish the marker
    // %Tag(PUBLISH)%
    while (marker_pub.getNumSubscribers() < 1)
    {
        if (!ros::ok())
        {
        return 0;
        }
        ROS_WARN_ONCE("Please create a subscriber to the marker");
        sleep(1);
    }

    marker_pub.publish(marker);

    ros::Duration(5.0).sleep();

    marker.action = visualization_msgs::Marker::DELETE;

    marker_pub.publish(marker);

    ros::Duration(5.0).sleep();

    marker.pose.position.x = 1.0;
    marker.pose.position.y = -2.85;
    marker.pose.orientation.w = -0.0014;

    marker.action = visualization_msgs::Marker::ADD;

    marker_pub.publish(marker);





    // %EndTag(PUBLISH)%

        // Cycle between different shapes
    // %Tag(CYCLE_SHAPES)%


        // switch (shape)
        // {
        // case visualization_msgs::Marker::CUBE:
        //   shape = visualization_msgs::Marker::SPHERE;
        //   break;
        // case visualization_msgs::Marker::SPHERE:
        //   shape = visualization_msgs::Marker::ARROW;
        //   break;
        // case visualization_msgs::Marker::ARROW:
        //   shape = visualization_msgs::Marker::CYLINDER;
        //   break;
        // case visualization_msgs::Marker::CYLINDER:
        //   shape = visualization_msgs::Marker::CUBE;
        //   break;
        // }

    ros::spin();
    // %EndTag(CYCLE_SHAPES)%
    return 0;
    // %Tag(SLEEP_END)%
        // r.sleep();
//   }
// %EndTag(SLEEP_END)%
}
// %EndTag(FULLTEXT)%