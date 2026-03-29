#include "drivecode/scoring.hpp"
#include "drivecode/objects.hpp"


pros::Motor scoring(0);

int scoringState = 0;
bool button2Pressed = false;

void updateScoring() {
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
        if(!button2Pressed) {
            scoringState+=1;
            button2Pressed = true;
            if(scoringState == 0) {
                scoring.move_velocity(0);
            } else if(scoringState == 1) {
                scoring.move_velocity(600);
                scoringState=-1;
            }
        }
    } else {
        button2Pressed = false;
    }
}

int midgoalState = 0;
bool button3Pressed = false;

void updateMidgoal() {
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
        if(!button3Pressed) {
            midgoalState+=1;
            button3Pressed = true;
            if(midgoalState == 0) {
                scoring.move_velocity(0);
            } else if(midgoalState == 1) {
                scoring.move_velocity(-600);
                midgoalState=-1;
            }
        }
    } else {
        button3Pressed = false;
    }
}


int lowgoalState = 0;
bool button4Pressed = false;
pros::adi::AnalogOut lowgoal('A');

void updateLowgoal() {
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
        if(!button4Pressed) {
            lowgoalState+=1;
            button4Pressed = true;
            if(lowgoalState == 0) {
                scoring.move_velocity(0);
                lowgoal.set_value(false);
            } else if(lowgoalState == 1) {
                scoring.move_velocity(-600);
                lowgoal.set_value(true);
                lowgoalState=-1;
            }
        }
    } else {
        button4Pressed = false;
    }
}