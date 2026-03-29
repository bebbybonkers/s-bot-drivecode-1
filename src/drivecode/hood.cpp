#include "drivecode/trapdoor.hpp"
#include "drivecode/objects.hpp"

pros::adi::AnalogOut hood('A');

int hoodState = 0;
bool hoodButtonPressed = false;

void updateHood() {
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_X)) { 
        if(!hoodButtonPressed) {
            hoodState++;
            hoodButtonPressed = true;
            if(hoodState == 0) {
                hood.set_value(false); 
            } else if(hoodState == 1) {
                hood.set_value(true);
            } else if(hoodState == 2) {
                hood.set_value(false);
                hoodState = 0;
            }
        }
    } else {
        hoodButtonPressed = false;
    }
}