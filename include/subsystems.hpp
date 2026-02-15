#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

extern Drive chassis;
//TEST 2

// Your motors, sensors, etc. should go here.  Below are examples

// inline pros::Motor intake(1);
// inline pros::adi::DigitalIn limit_switch('A');
inline pros::Motor intake2(17);  // Intake motor on port 17
inline pros::Motor intake1(15);  // Intake motor on port 15
inline ez::Piston MidPiston('E');
inline ez::Piston Disscore('H');
inline ez::Piston Matchloader('G');
inline pros::Distance leftDist(10); // Distance sensor on port 10
inline pros::Distance frontDist(3); // Distance sensor on port 3

// Sensor offset: distance from sensor face to robot centerline (mm).
// Measure from the sensor's sensing face to the robot center (positive = sensor is to the left of center).
constexpr double Left_DISTANCE_TO_CENTER_MM = 152.4; // <-- measure and replace

// Returns distance from robot center to obstacle on the left in mm.
// If sensor points directly left, robot_center_distance = leftDist.get() + sensor_offset.
// If you mounted differently, adjust sign/geometry accordingly.
inline double get_left_distance_from_center_mm() {
  double raw = leftDist.get(); // mm
  return raw + Left_DISTANCE_TO_CENTER_MM;
}


// Sensor offset: distance from sensor face to robot centerline (mm).
// Measure from the sensor's sensing face to the robot center (positive = sensor is to the left of center).
constexpr double FRONT_FORWARD_OFFSET_MM = 114.3;   // 4.5 in front of robot center
constexpr double FRONT_LATERAL_OFFSET_MM = 127.0;   // 5.0 in left of center (positive = left)


// Returns distance from robot center to obstacle in front in mm.
inline double get_front_distance_from_center_mm() {
  double raw = frontDist.get(); // mm
  int confidence = frontDist.get_confidence(); // 0-63, higher is better
  if (confidence < 5) {
    // If confidence is very low, the reading is likely unreliable. You can choose to ignore it or handle it differently.
    // For now, let's just print a warning and return a large distance to indicate "no reliable reading".
    printf("Ashrith debugging 7 - Warning: Low confidence in front distance reading (%d). Ignoring reading.\n", confidence);
    return 9999.0; // effectively "no obstacle detected"
  }
  return raw + FRONT_FORWARD_OFFSET_MM;
}

// Read the front distance and optionally print it to terminal and brain screen.
inline double read_front_distance_mm(bool show = false, int screen_line = 2) {
  double d = get_front_distance_from_center_mm();
  if (show) {
    printf("Front dist: %.1f mm\n", d);
    char buf[32];
    snprintf(buf, sizeof(buf), "Dist: %.0f mm", d);
    ez::screen_print(buf, screen_line);
  }
  return d;
}

