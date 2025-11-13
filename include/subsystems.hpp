#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

extern Drive chassis;

// Your motors, sensors, etc. should go here.  Below are examples

// inline pros::Motor intake(1);
// inline pros::adi::DigitalIn limit_switch('A');
inline pros::Motor intake2(17);  // Intake motor on port 17
inline pros::Motor intake1(7);  // Intake motor on port 17
inline ez::Piston Ramp('H');
inline ez::Piston Stopper('G');
inline ez::Piston Matchloader('F');
//inline pros::Motor BigBigBooster(17);  // Intake motor on port 17
//inline ez::Piston Bruhh('B'); // (BigBigBooster piston)
//inline ez::Piston IDK('D'); // (Match Loaders)
//inline ez::Piston Aligner('G');