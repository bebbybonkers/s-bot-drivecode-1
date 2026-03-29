#include "main.h"
#include "objects.hpp"
#include "pros/adi.hpp"

extern pros::Motor scoring;

void updateScoring();
void updateMidgoal();
void updateLowgoal();

extern int scoringState;
extern bool button2Pressed;

extern int midgoalState;
extern bool button3Pressed;

extern int lowgoalState;
extern bool button4Pressed;
extern pros::adi::AnalogOut lowgoal;