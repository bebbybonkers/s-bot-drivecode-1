#pragma once
#include "main.h"
#include "objects.hpp"

extern pros::adi::AnalogOut hood;

extern int hoodState;
extern bool hoodButtonPressed;

void updateHood();