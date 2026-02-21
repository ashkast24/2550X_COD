#include "main.h"

/////
// For installation, upgrading, documentations, and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

// These are out of 127
const int DRIVE_SPEED = 110;
const int TURN_SPEED = 90;
const int SWING_SPEED = 110;

///
// Constants
///
void default_constants() {
  // P, I, D, and Start I
  chassis.pid_drive_constants_set(15.0, 0.0, 135.0);         // Fwd/rev constants, used for odom and non odom motions
  chassis.pid_heading_constants_set(11.0, 0.0, 20.0);        // Holds the robot straight while going forward without odom
  chassis.pid_turn_constants_set(5, 0, 42, 0);               // Turn in place constants
  chassis.pid_swing_constants_set(6.0, 0.0, 65.0);           // Swing constants (DON'T USE THIS)
  chassis.pid_odom_angular_constants_set(2.0, 0.0, 20.0);    // Angular control for odom motions (using angle that you provide). Angular is for Position. This is PURE PERSUIT
  chassis.pid_odom_boomerang_constants_set(3.5, 0.0, 20.0);  // Angular control for boomerang motions (using angle that it percieves as the best angle to turn to). Boomerang is for Angle

  // Ask what these constants mean and about which of these constants to use; Ask if I still need to tune pid_turn_constants since im using odom so odom_angular_constants should be enough. Ask if odom_boomerang_constants are really necessary.
  // Ask if I just need to tune these constants, then wheel diameter and then distance to center of the robot and then I can proceed to making autons.
  //  Ask which one of the turning commands works best and is the one that I should use for turning in autons.

  // Tune Drive PID and Turn PID, then tune wheel diameter, then distance to center of the robot. Then tune odom_angular_constants and odom_boomerang_constants. Then make autons using pid_odom_set for driving and pid_turn_set for turning. Use example autons below for help with functions.

  // Exit conditions
  chassis.pid_turn_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_swing_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_drive_exit_condition_set(50_ms, 1_in, 100_ms, 3_in, 100_ms, 250_ms);
  chassis.pid_odom_turn_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 750_ms);
  chassis.pid_odom_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 500_ms, 750_ms);
  chassis.pid_turn_chain_constant_set(3_deg);
  chassis.pid_swing_chain_constant_set(5_deg);
  chassis.pid_drive_chain_constant_set(3_in);

  // Slew constants
  chassis.slew_turn_constants_set(5_deg, 50);
  chassis.slew_drive_constants_set(3_in, 50);
  chassis.slew_swing_constants_set(3_in, 80);

  // The amount that turns are prioritized over driving in odom motions
  // - if you have tracking wheels, you can run this higher.  1.0 is the max
  // Tune odom pid constants first, then set this
  chassis.odom_turn_bias_set(0.9);

  chassis.odom_look_ahead_set(7_in);           // This is how far ahead in the path the robot looks at
  chassis.odom_boomerang_distance_set(16_in);  // This sets the maximum distance away from target that the carrot point can be
  chassis.odom_boomerang_dlead_set(0.625);     // This handles how aggressive the end of boomerang motions are

  chassis.pid_angle_behavior_set(ez::shortest);  // Changes the default behavior for turning, this defaults it to the shortest path there
}

///
// My Autonomous
///
void my_custom_auton() {

  const int DRIVE_SPEED_1 = 75;
  const int DRIVE_SPEED_2 = 50;
  const int DRIVE_SPEED_3 = 110;
  const int DRIVE_SPEED_4 = 20;
  const int DRIVE_SPEED_5 = 90;
  const int DRIVE_SPEED_6 = 100;


  Matchloader.set(false);  // up
  chassis.pid_wait();
  chassis.pid_drive_set(10_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
  intake1.move(127);
  
  chassis.pid_drive_set(25_in, DRIVE_SPEED_2);
  pros::delay(500);
  Matchloader.set(true);  // down
  chassis.pid_wait();
  pros::delay(1000);
  /*chassis.pid_wait();
  chassis.pid_drive_set(-20_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(30_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_turn_set(-90_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-20_in, DRIVE_SPEED);
  pros::delay(500);
  intake1.move(127);
  intake2.move(127);
  pros::delay(1500);
  intake2.move(0);
  Matchloader.set(true);  // down
  chassis.pid_wait();
  chassis.pid_drive_set(30_in, DRIVE_SPEED);
  pros::delay(300);
  chassis.pid_drive_set(-30_in, DRIVE_SPEED);
  pros::delay(500);
  intake2.move(127);
*/



 





  
}

///
// My Second Custom Auton
///
void my_second_auton() {
  const int DRIVE_SPEED_1 = 75;
  const int DRIVE_SPEED_2 = 50;
  const int DRIVE_SPEED_3 = 110;
  const int DRIVE_SPEED_4 = 20;
  const int DRIVE_SPEED_5 = 90;
  const int DRIVE_SPEED_6 = 100;

// 4 + 3   B A L L   A U T O N O M O U S    C O D E
  
//APPROACH MATCHLOADER

  Matchloader.set(true);  // down 
  intake1.move(127);

  chassis.drive_brake_set(pros::E_MOTOR_BRAKE_HOLD); 
  Front_approach_to_distance(700, 50, 2000);
  pros::delay(200);
  

  chassis.drive_brake_set(pros::E_MOTOR_BRAKE_HOLD);
  chassis.pid_turn_set(-90_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_targets_reset();
  chassis.drive_sensor_reset();
  chassis.drive_set(0, 0);

  chassis.drive_brake_set(pros::E_MOTOR_BRAKE_HOLD); 
  pros::delay(200);
  Front_approach_to_distance(350, 50, 2000);
  pros::delay(200);
  chassis.drive_brake_set(pros::E_MOTOR_BRAKE_HOLD);
  pros::delay(250);

//BACK UP FROM MATCHLOADER AND SCORE IN HIGH GOAL

  pros::delay(50);
  chassis.pid_turn_set(-90_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-30_in, DRIVE_SPEED);
  pros::delay(500);
  intake1.move(127);
  intake2.move(127);
  pros::delay(1000);
  intake1.move(0);
  intake2.move(0);
  Matchloader.set(false);  // up  


//HEAD TO MID GOAL

  chassis.pid_targets_reset();
  chassis.drive_sensor_reset();
  chassis.drive_set(0, 0);

  chassis.drive_brake_set(pros::E_MOTOR_BRAKE_HOLD); 
  pros::delay(200);
  Front_approach_to_distance(575, 50, 2000);
  pros::delay(200);
  chassis.drive_brake_set(pros::E_MOTOR_BRAKE_HOLD);
  
  chassis.pid_turn_set(135_deg, TURN_SPEED);
  chassis.pid_wait();
  intake1.move(75);
  chassis.pid_drive_set(45_in, DRIVE_SPEED_2);
  chassis.pid_wait();
  pros::delay(1000);
  chassis.pid_wait();
  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-13_in, DRIVE_SPEED);
  pros::delay(200);
  MidPiston.set(true); // down
  intake2.move(50);
  

  
  /*chassis.pid_targets_reset();
  chassis.drive_sensor_reset();
  chassis.drive_set(0, 0);

  chassis.drive_brake_set(pros::E_MOTOR_BRAKE_HOLD); 
  pros::delay(200);
  Front_approach_to_distance(300, 50, 2000);
  pros::delay(200);
  chassis.drive_brake_set(pros::E_MOTOR_BRAKE_HOLD);
  pros::delay(1000);
  
  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_drive_set(-30_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_targets_reset();
  chassis.drive_sensor_reset();
  chassis.drive_set(0, 0);

  chassis.drive_brake_set(pros::E_MOTOR_BRAKE_HOLD); 
  pros::delay(200);
  Front_approach_to_distance(630, 50, 2000);
  pros::delay(200);
  chassis.drive_brake_set(pros::E_MOTOR_BRAKE_HOLD);
  pros::delay(1000);

  chassis.pid_turn_set(-90_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-15_in, DRIVE_SPEED);
  pros::delay(500);
  intake2.move(127);
*/












  
}

///
// My Skills Auton
///
void my_skills_auton() {
  const int DRIVE_SPEED_1 = 75;
  const int DRIVE_SPEED_2 = 50;
  const int DRIVE_SPEED_3 = 110;
  const int DRIVE_SPEED_4 = 25;
  const int DRIVE_SPEED_5 = 90;
  const int DRIVE_SPEED_6 = 100;

  
  
  // APPROACH MATCHLOADER

  Matchloader.set(true);  // down  
  intake1.move(127);
  intake2.move(-127);

  chassis.drive_brake_set(pros::E_MOTOR_BRAKE_HOLD); 
  Front_approach_to_distance(700, 50, 2000);
  pros::delay(200);
  

  chassis.drive_brake_set(pros::E_MOTOR_BRAKE_HOLD);
  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_targets_reset();
  chassis.drive_sensor_reset();
  chassis.drive_set(0, 0);

  chassis.drive_brake_set(pros::E_MOTOR_BRAKE_HOLD); 
  pros::delay(200);
  Front_approach_to_distance(350, 50, 2000);
  pros::delay(200);
  chassis.drive_brake_set(pros::E_MOTOR_BRAKE_HOLD);
  pros::delay(2500);
  intake1.move(-127);
  pros::delay(200);
  intake1.move(127);
  pros::delay(500);


  //BACK UP FROM MATCHLOADER

  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-15_in, DRIVE_SPEED, true);
  Matchloader.set(false);  // up
  chassis.pid_wait();
  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();


  chassis.pid_turn_set(180_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_wait();
  chassis.pid_drive_set(18_in, DRIVE_SPEED, true);
  chassis.pid_wait();


  chassis.pid_turn_set(-90_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(85_in, DRIVE_SPEED_5, true);
  chassis.pid_wait();
  chassis.pid_turn_set(-90_deg, TURN_SPEED);
  chassis.pid_wait();


  chassis.pid_targets_reset();
  chassis.drive_sensor_reset();
  chassis.drive_set(0, 0);

  chassis.drive_brake_set(pros::E_MOTOR_BRAKE_HOLD); 
  pros::delay(200);
  Front_approach_to_distance(700, 50, 2000);
  pros::delay(200);
  chassis.drive_brake_set(pros::E_MOTOR_BRAKE_HOLD); 

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();


  //SCORE BALLS FROM 1ST MATCHLOADER -> 1ST HIGH GOAL

  chassis.pid_targets_reset();
  chassis.drive_sensor_reset();
  chassis.drive_set(0, 0);

  chassis.drive_brake_set(pros::E_MOTOR_BRAKE_HOLD); 
  pros::delay(200);
  Front_approach_to_distance(660, 50, 2000);  pros::delay(200);
  pros::delay(200);
  chassis.drive_brake_set(pros::E_MOTOR_BRAKE_HOLD); 


  chassis.pid_turn_set(-90_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-21_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  intake2.move(-127);
  pros::delay(500);
  intake2.move(127);
  pros::delay(2500);



  //APPROACH 2ND MATCHLOADER AND SCORE IN 1ST HIGH GOAL 

  Matchloader.set(true);  // down
  intake2.move(-127);
  chassis.pid_wait();
  chassis.pid_drive_set(15_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_turn_set(-96_deg, TURN_SPEED, true);
  chassis.pid_wait();



  chassis.pid_targets_reset();
  chassis.drive_sensor_reset();
  chassis.drive_set(0, 0);

  chassis.drive_brake_set(pros::E_MOTOR_BRAKE_HOLD); 
  pros::delay(200);
  Front_approach_to_distance(370, 50, 2000);
  pros::delay(200);
  chassis.drive_brake_set(pros::E_MOTOR_BRAKE_HOLD); 
  pros::delay(2500);
  
  intake1.move(-127);
  pros::delay(200);
  intake1.move(127);
  pros::delay(500);


  chassis.pid_turn_set(-93_deg, TURN_SPEED, true);
  chassis.pid_wait();
  chassis.pid_drive_set(-26_in, DRIVE_SPEED, true);
  Matchloader.set(false);  // up
  chassis.pid_wait();
  chassis.pid_drive_set(-10_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  intake2.move(-127);
  pros::delay(500);
  intake2.move(127);
  pros::delay(2500);
  chassis.pid_wait();




  //chassis.odom_xyt_set(0_in, 0_in, -90_deg);


  //APPROACH 3RD MATCHLOADER

  chassis.pid_turn_set(180_deg, TURN_SPEED, true);
  chassis.pid_wait();
  chassis.pid_drive_set(85_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_turn_set(180_deg, TURN_SPEED, true);
  chassis.pid_wait();


  chassis.pid_targets_reset();
  chassis.drive_sensor_reset();
  chassis.drive_set(0, 0);

  chassis.drive_brake_set(pros::E_MOTOR_BRAKE_HOLD); 
  pros::delay(200);
  Front_approach_to_distance(700, 50, 2000);
  pros::delay(200);
  chassis.drive_brake_set(pros::E_MOTOR_BRAKE_HOLD); 

  chassis.pid_turn_set(-90_deg, TURN_SPEED, true);
  chassis.pid_wait();
  Matchloader.set(true);  // down
  intake2.move(-127);
  chassis.pid_wait();

  chassis.pid_targets_reset();
  chassis.drive_sensor_reset();
  chassis.drive_set(0, 0);

  chassis.drive_brake_set(pros::E_MOTOR_BRAKE_HOLD); 
  pros::delay(200);
  Front_approach_to_distance(350, 50, 2000);
  pros::delay(200);
  chassis.drive_brake_set(pros::E_MOTOR_BRAKE_HOLD); 
  pros::delay(2500);

  intake1.move(-127);
  pros::delay(200);
  intake1.move(127);
  pros::delay(500);

  chassis.pid_turn_set(-90_deg, TURN_SPEED, true);
  chassis.pid_wait();
  chassis.pid_drive_set(-15_in, DRIVE_SPEED, true);
  Matchloader.set(false);  // up
  chassis.pid_wait();
  chassis.pid_turn_set(-90_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(18_in, DRIVE_SPEED, true);
  chassis.pid_wait();


  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(85_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_targets_reset();
  chassis.drive_sensor_reset();
  chassis.drive_set(0, 0);

  chassis.drive_brake_set(pros::E_MOTOR_BRAKE_HOLD); 
  pros::delay(200);
  Front_approach_to_distance(700, 50, 2000);
  pros::delay(200);
  chassis.drive_brake_set(pros::E_MOTOR_BRAKE_HOLD); 


  chassis.pid_turn_set(180_deg, TURN_SPEED);
  chassis.pid_wait();


  //SCORE BALLS FROM 3RD MATCHLOADER -> 2ND HIGH GOAL

  chassis.pid_targets_reset();
  chassis.drive_sensor_reset();
  chassis.drive_set(0, 0);

  chassis.drive_brake_set(pros::E_MOTOR_BRAKE_HOLD); 
  pros::delay(200);
  Front_approach_to_distance(660, 50, 2000);
  pros::delay(200);
  chassis.drive_brake_set(pros::E_MOTOR_BRAKE_HOLD); 


  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-21_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  intake2.move(-127);
  pros::delay(500);
  intake2.move(127);
  pros::delay(2500);
  chassis.pid_wait();

  //APPROACH 4TH MATCHLOADER AND SCORE IN 2ND HIGH GOAL 

  Matchloader.set(true);  // down  
  intake2.move(-127);
  chassis.pid_wait();
  chassis.pid_drive_set(15_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_turn_set(96_deg, TURN_SPEED, true);
  chassis.pid_wait();

  chassis.pid_targets_reset();
  chassis.drive_sensor_reset();
  chassis.drive_set(0, 0);

  chassis.drive_brake_set(pros::E_MOTOR_BRAKE_HOLD); 
  pros::delay(200);
  Front_approach_to_distance(330, 50, 2000);
  pros::delay(200);
  chassis.drive_brake_set(pros::E_MOTOR_BRAKE_HOLD); 
  pros::delay(2500);
  
  intake1.move(-127);
  pros::delay(200);
  intake1.move(127);
  pros::delay(500);

  chassis.pid_turn_set(93_deg, TURN_SPEED, true);
  chassis.pid_wait();
  chassis.pid_drive_set(-26_in, DRIVE_SPEED, true);
  Matchloader.set(false);  // up
  chassis.pid_wait();
  chassis.pid_drive_set(-10_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  intake2.move(127);
  pros::delay(2500);
  intake2.move(-127);
  chassis.pid_wait();
  pros::delay(2500);

  chassis.pid_turn_set(45_deg, TURN_SPEED, true);
  chassis.pid_wait();
  chassis.pid_drive_set(30_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  Matchloader.set(true);  // down
  chassis.pid_wait();
  chassis.pid_drive_set(45_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  Matchloader.set(false);  // up






  
















  /*chassis.pid_turn_set(-90_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-17_in, DRIVE_SPEED);
  chassis.pid_wait();
  //intake1.move(127);
  //intake2.move(127);
  pros::delay(2000);
  //intake1.move(0);
  //intake2.move(0);
  pros::delay(2000);
  
  //APPROACH 2ND MATCH LOADER

  chassis.pid_targets_reset();
  chassis.drive_sensor_reset();
  chassis.drive_set(0, 0);
  
  pros::delay(200);
  //matchloader.set(true);  // down
  //intake1.move(127);


  chassis.drive_brake_set(pros::E_MOTOR_BRAKE_HOLD); 
  pros::delay(200);
  Front_approach_to_distance(400, 50, 2000);
  pros::delay(200);
  chassis.drive_brake_set(pros::E_MOTOR_BRAKE_HOLD);
  
  pros::delay(2000);
  //intake1.move(0);

  //BACK UP FROM 2ND MATCH LOADER

  pros::delay(50);
  chassis.pid_wait();
  chassis.pid_drive_set(-15_in, DRIVE_SPEED);
  //matchloader.set(false);  // up
  */





















 










  




  
}

///
// Drive Example
///
void drive_example() {
  // The first parameter is target inches
  // The second parameter is max speed the robot will drive at
  // The third parameter is a boolean (true or false) for enabling/disabling a slew at the start of drive motions
  // for slew, only enable it when the drive distance is greater than the slew distance + a few inches

  // Front_approach_to_distance(600.0, 25, 5000);
  // chassis.pid_wait();
  // chassis.pid_drive_set(-10_in, DRIVE_SPEED);

  // chassis.pid_drive_set(-12_in, DRIVE_SPEED);
  // chassis.pid_wait();

  // chassis.pid_drive_set(-12_in, DRIVE_SPEED);
  // chassis.pid_wait();
}

///
// Turn Example
///
void turn_example() {
  // The first parameter is the target in degrees
  // The second parameter is max speed the robot will drive at

  chassis.pid_turn_set(90_deg, TURN_SPEED, true);
  chassis.pid_wait();

  // chassis.pid_wait();

  // chassis.pid_turn_set(0_deg, TURN_SPEED);
  // chassis.pid_wait();

  // chassis.pid_drive_set(10_in, DRIVE_SPEED, true);
}

///
// Combining Turn + Drive
///
void drive_and_turn() {
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-24_in, DRIVE_SPEED, true);
  chassis.pid_wait();
}

///
// Wait Until and Changing Max Speed
///
void wait_until_change_speed() {
  // pid_wait_until will wait until the robot gets to a desired position

  // When the robot gets to 6 inches slowly, the robot will travel the remaining distance at full speed
  chassis.pid_drive_set(24_in, 30, true);
  chassis.pid_wait_until(6_in);
  chassis.pid_speed_max_set(DRIVE_SPEED);  // After driving 6 inches at 30 speed, the robot will go the remaining distance at DRIVE_SPEED
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  // When the robot gets to -6 inches slowly, the robot will travel the remaining distance at full speed
  chassis.pid_drive_set(-24_in, 30, true);
  chassis.pid_wait_until(-6_in);
  chassis.pid_speed_max_set(DRIVE_SPEED);  // After driving 6 inches at 30 speed, the robot will go the remaining distance at DRIVE_SPEED
  chassis.pid_wait();
}

///
// Swing Example
///
void swing_example() {
  // The first parameter is ez::LEFT_SWING or ez::RIGHT_SWING
  // The second parameter is the target in degrees
  // The third parameter is the speed of the moving side of the drive
  // The fourth parameter is the speed of the still side of the drive, this allows for wider arcs

  chassis.pid_swing_set(ez::LEFT_SWING, 45_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, 0_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, 45_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::LEFT_SWING, 0_deg, SWING_SPEED, 45);
  chassis.pid_wait();
}

///
// Motion Chaining
///
void motion_chaining() {
  // Motion chaining is where motions all try to blend together instead of individual movements.
  // This works by exiting while the robot is still moving a little bit.
  // To use this, replace pid_wait with pid_wait_quick_chain.
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  // Your final motion should still be a normal pid_wait
  chassis.pid_drive_set(-24_in, DRIVE_SPEED, true);
  chassis.pid_wait();
}

///
// Auto that tests everything
///
void combining_movements() {
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, -45_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-24_in, DRIVE_SPEED, true);
  chassis.pid_wait();
}

///
// Interference example
///
void tug(int attempts) {
  for (int i = 0; i < attempts - 1; i++) {
    // Attempt to drive backward
    printf("i - %i", i);
    chassis.pid_drive_set(-12_in, 127);
    chassis.pid_wait();

    // If failsafed...
    if (chassis.interfered) {
      chassis.drive_sensor_reset();
      chassis.pid_drive_set(-2_in, 20);
      pros::delay(1000);
    }
    // If the robot successfully drove back, return
    else {
      return;
    }
  }
}

// If there is no interference, the robot will drive forward and turn 90 degrees.
// If interfered, the robot will drive forward and then attempt to drive backward.
void interfered_example() {
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  if (chassis.interfered) {
    tug(3);
    return;
  }

  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
}

///
// Odom Drive PID
///
void odom_drive_example() {
  // This works the same as pid_drive_set, but it uses odom instead!
  // You can replace pid_drive_set with pid_odom_set and your robot will
  // have better error correction.

  chassis.pid_odom_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_odom_set(-12_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_odom_set(-12_in, DRIVE_SPEED);
  chassis.pid_wait();
}

///
// Odom Pure Pursuit
///
void odom_pure_pursuit_example() {
  // Drive to 24, 24 and pass through 0, 24 on the way, with slew
  intake1.move(127);
  chassis.pid_odom_set({{0_in, 10_in, 0_deg}, fwd, DRIVE_SPEED},
                       true);
  chassis.pid_wait();
  chassis.pid_odom_set({{20_in, 10_in, 90_deg}, rev, DRIVE_SPEED},
                       true);
  chassis.pid_wait();
  chassis.pid_turn_set(-135_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(10_in, DRIVE_SPEED, true);
  intake2.move(-127);
  chassis.pid_wait();
  // chassis.pid_drive_set(30_in, DRIVE_SPEED, true);
  // chassis.pid_wait();
  // chassis.pid_turn_set(-135_deg, TURN_SPEED);
  // Bruhh.set(true);
  // chassis.pid_drive_set(-24_in, DRIVE_SPEED, true);
  // chassis.pid_wait();
  // chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  // Bruhh.set(false);
  // chassis.pid_turn_set(90_deg, TURN_SPEED);
  // chassis.pid_drive_set(52_in, DRIVE_SPEED, true);
  // chassis.pid_wait();
  // chassis.pid_turn_set(135_deg, TURN_SPEED);
  // chassis.pid_drive_set(-24_in, DRIVE_SPEED, true);
  // chassis.pid_wait();

  // Drive to 0, 0 backwards
  // chassis.pid_odom_set({{0_in, 0_in}, rev, DRIVE_SPEED},
  // true);
  // chassis.pid_wait();
}

///
// Odom Pure Pursuit Wait Until
///
void odom_pure_pursuit_wait_until_example() {
  chassis.pid_odom_set({{{0_in, 24_in}, fwd, DRIVE_SPEED},
                        {{12_in, 24_in}, fwd, DRIVE_SPEED},
                        {{24_in, 24_in}, fwd, DRIVE_SPEED}},
                       true);
  chassis.pid_wait_until_index(1);  // Waits until the robot passes 12, 24
  // Intake.move(127);  // Set your intake to start moving once it passes through the second point in the index
  chassis.pid_wait();
  // Intake.move(0);  // Turn the intake off
}

///
// Odom Boomerang
///
void odom_boomerang_example() {
  chassis.pid_odom_set({{24_in, 24_in, 90_deg}, fwd, DRIVE_SPEED},
                       true);
  chassis.pid_wait();

  // chassis.pid_odom_set({{0_in, 0_in, 0_deg}, rev, DRIVE_SPEED},
  // true);
  // chassis.pid_wait();
}

///
// Odom Boomerang Injected Pure Pursuit
///
void odom_boomerang_injected_pure_pursuit_example() {
  chassis.pid_odom_set({{{0_in, 24_in, 45_deg}, fwd, DRIVE_SPEED},
                        {{12_in, 24_in}, fwd, DRIVE_SPEED},
                        {{24_in, 24_in}, fwd, DRIVE_SPEED}},
                       true);
  chassis.pid_wait();

  chassis.pid_odom_set({{0_in, 0_in, 0_deg}, rev, DRIVE_SPEED},
                       true);
  chassis.pid_wait();
}

///
// Calculate the offsets of your tracking wheels
///
void measure_offsets() {
  // Number of times to test
  int iterations = 10;

  // Our final offsets
  double l_offset = 0.0, r_offset = 0.0, b_offset = 0.0, f_offset = 0.0;

  // Reset all trackers if they exist
  if (chassis.odom_tracker_left != nullptr) chassis.odom_tracker_left->reset();
  if (chassis.odom_tracker_right != nullptr) chassis.odom_tracker_right->reset();
  if (chassis.odom_tracker_back != nullptr) chassis.odom_tracker_back->reset();
  if (chassis.odom_tracker_front != nullptr) chassis.odom_tracker_front->reset();

  for (int i = 0; i < iterations; i++) {
    // Reset pid targets and get ready for running an auton
    chassis.pid_targets_reset();
    chassis.drive_imu_reset();
    chassis.drive_sensor_reset();
    chassis.drive_brake_set(MOTOR_BRAKE_HOLD);
    chassis.odom_xyt_set(0_in, 0_in, 0_deg);
    double imu_start = chassis.odom_theta_get();
    double target = i % 2 == 0 ? 90 : 270;  // Switch the turn target every run from 270 to 90

    // Turn to target at half power
    chassis.pid_turn_set(target, 63, ez::raw);
    chassis.pid_wait();
    pros::delay(250);

    // Calculate delta in angle
    double t_delta = util::to_rad(fabs(util::wrap_angle(chassis.odom_theta_get() - imu_start)));

    // Calculate delta in sensor values that exist
    double l_delta = chassis.odom_tracker_left != nullptr ? chassis.odom_tracker_left->get() : 0.0;
    double r_delta = chassis.odom_tracker_right != nullptr ? chassis.odom_tracker_right->get() : 0.0;
    double b_delta = chassis.odom_tracker_back != nullptr ? chassis.odom_tracker_back->get() : 0.0;
    double f_delta = chassis.odom_tracker_front != nullptr ? chassis.odom_tracker_front->get() : 0.0;

    // Calculate the radius that the robot traveled
    l_offset += l_delta / t_delta;
    r_offset += r_delta / t_delta;
    b_offset += b_delta / t_delta;
    f_offset += f_delta / t_delta;
  }

  // Average all offsets
  l_offset /= iterations;
  r_offset /= iterations;
  b_offset /= iterations;
  f_offset /= iterations;

  // Set new offsets to trackers that exist
  if (chassis.odom_tracker_left != nullptr) chassis.odom_tracker_left->distance_to_center_set(l_offset);
  if (chassis.odom_tracker_right != nullptr) chassis.odom_tracker_right->distance_to_center_set(r_offset);
  if (chassis.odom_tracker_back != nullptr) chassis.odom_tracker_back->distance_to_center_set(b_offset);
  if (chassis.odom_tracker_front != nullptr) chassis.odom_tracker_front->distance_to_center_set(f_offset);
}

// . . .
// Make your own autonomous functions here!
// . . .

///
// Test: Read Sensor 10 Times
///

void test_read_sensor() {
  ez::screen_print("Reading sensor...", 1);

  for (int i = 0; i < 10; ++i) {
    double dist = get_left_distance_from_center_mm();  // read the sensor
    std::string msg = "Read " + std::to_string(i + 1) + ": " + util::to_string_with_precision(dist) + " mm";
    ez::screen_print(msg, i + 2);                  // print to screen (line i+2)
    printf("Sensor read %d: %.1f mm\n", i, dist);  // also print to terminal
    pros::delay(200);                              // wait 200 ms between reads
  }

  ez::screen_print("Done!", 8);
}

/*
 * This is custom function that you can make to do something more specific that isn't already built in.
 * In this case, this function will use the front distance sensor to approach a wall to a target distance.
 * It will drive forward until it is within the target distance of the wall, and it will do this for a maximum amount of time.
 * This is useful for lining up with a wall or approaching a goal.
 * The function uses a simple proportional control loop to drive toward the target distance, and it also has some extra features like ramping down the speed when  * it gets close and checking for stability before exiting.
 * You can call this function in your autons or even in opcontrol to have the robot approach a wall to a certain distance. Just make sure to tune the parameters   * (like the target distance, speed, and timeout) for your specific use case and robot.
 */
void Front_approach_to_distance(double target_mm, int max_speed, int timeout_ms) {
  // 1000.0 25 5000

  const int SAMPLES = 5;           // Averaging 5 samples for smooth, reliable readings
  const int STABLE_REQUIRED = 3;   // Require 3 consecutive stable readings before exiting
  const double TOL_MM = 10.0;      // margin of error for being "at target"
  const double RAMP_DIST = 100.0;  // start slowing down when within this distance of target
  const int MIN_POWER = 20;        // minimum power to actually move the robot
  const int LOOP_DELAY_MS = 20;    // delay between control loop iterations

  int elapsed = 0;
  int stable = 0;

  printf("=======================================================\n");
  printf("Ashrith debugging 1 - target: %.1f mm, speed: %d, timeout: %d ms\n", target_mm, max_speed, timeout_ms);

  ez::screen_print("Approaching wall...", 1);

  // Main control loop: keep running until we hit the timeout (no matter what happens)
  // Program exits the loop if it reaches the target distance from the wall through the break statements, but this timeout is a safety in case something goes wrong and the robot can't reach the target distance
  while (elapsed < timeout_ms) {
    double sum = 0.0;
    // samples for averaging - this helps smooth out the sensor readings and makes the control more reliable
    for (int i = 0; i < SAMPLES; i++) {
      sum += get_front_distance_from_center_mm();
      pros::delay(LOOP_DELAY_MS);
      elapsed += LOOP_DELAY_MS;
    }
    double mean_dist = sum / SAMPLES;

    printf("Ashrith debugging 2 - sum: %.1f, elapsed: %d ms, mean_dist: %.1f mm\n", sum, elapsed, mean_dist);

    // If we go past the target distance, we can exit the loop and proceed to next step
    if (mean_dist <= target_mm) {
      ez::screen_print("At/inside target distance!", 2);
      printf("Ashrith debugging 3 - mean_dist: %.1f mm is within target distance %.1f mm\n", mean_dist, target_mm);
      break;
    }

    // Extra diagnostics: raw sensor debug
    // double raw = frontDist.get(); // mm (sensor raw)
    // printf("Ashrith debugging 1b - raw sensor: %.1f mm\n", raw);

    // Wall Despawned / too far. Likely not to happen as long as the robot starts at a reasonale distance from the wall,
    // but this is a safety check
    if (mean_dist > 1500.0) {
      ez::screen_print("No wall detected!", 2);
      printf("Ashrith debugging 4 - mean_dist: %.1f mm is too far, likely no wall\n", mean_dist);
      break;
    }

    // Emergency safety: if robot gets very close, stop now
    // const double MIN_SAFE_MM = 75.0; // don't let robot get closer than this
    // if (mean_dist <= MIN_SAFE_MM) {
    //   ez::screen_print("EMERGENCY STOP: too close!", 2);
    //   break;
    // }

    // Direction & ramping
    // The further we are from the target, the faster we should go (up to max speed), and the closer we get, the more we should slow down for finer control. If we're past the target (negative error), we need to back up, otherwise we drive forward.
    double error = mean_dist - target_mm;  // how far we are from the target distance (positive if we're too far, negative if we overshot)

    // Stability check: require consecutive in-tolerance readings
    // This helps prevent overshooting and ensures we are actually at the target distance before exiting
    // If the error is within the tolerance, increment stable counter, otherwise reset it
    // If we have enough consecutive stable readings, we can exit the loop
    if (fabs(error) <= TOL_MM) {
      if (++stable >= STABLE_REQUIRED) {
        ez::screen_print("At target distance!", 2);
        printf("Ashrith debugging 5 - error: %.1f mm, max_speed: %d, stable: %d\n", error, max_speed, stable);
        break;
      }
    } else {
      stable = 0;
    }

    int use_speed = max_speed;
    if (fabs(error) <= RAMP_DIST) {
      // Ramp down speed as we approach target for finer control
      use_speed = std::max(max_speed / 3, MIN_POWER);
    }
    use_speed = std::max(use_speed, MIN_POWER);

    // DRIVE FORWARD (move all left & right motors at SPEED)
    for (auto& motor : chassis.left_motors) motor.move(use_speed);
    for (auto& motor : chassis.right_motors) motor.move(use_speed);

    double left_vel = chassis.left_motors[0].get_actual_velocity();
    double right_vel = chassis.right_motors[0].get_actual_velocity();
    double left_pos = chassis.left_motors[0].get_position();
    double right_pos = chassis.right_motors[0].get_position();
    printf("Ashrith debugging 5b - CMD=%d | Lvel=%.2f Rvel=%.2f | Lpos=%.2f Rpos=%.2f\n", use_speed, left_vel, right_vel, left_pos, right_pos);
  }

  // STOP ALL MOTORS - explicitly set move to 0 for all motors to ensure the robot stops moving after the loop
  for (auto& motor : chassis.left_motors) motor.move(0);
  for (auto& motor : chassis.right_motors) motor.move(0);
  printf("Ashrith debugging 5c - stopped motors\n");
  pros::delay(50);  // small delay to ensure motors have time to stop

  printf("Ashrith debugging 6 - finished loop, elapsed: %d ms\n", elapsed);
  
}
