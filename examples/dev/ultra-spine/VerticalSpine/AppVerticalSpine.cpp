/*
 * Copyright © 2012, United States Government, as represented by the
 * Administrator of the National Aeronautics and Space Administration.
 * All rights reserved.
 * 
 * The NASA Tensegrity Robotics Toolkit (NTRT) v1 platform is licensed
 * under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * http://www.apache.org/licenses/LICENSE-2.0.
 * 
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific language
 * governing permissions and limitations under the License.
*/

/**
 * @file AppVerticalSpine.cpp
 * @brief Contains the definition function main() for VerticalSpine
 * application.
 * @author Brian Tietz, Drew Sabelhaus
 * @copyright Copyright (C) 2014 NASA Ames Research Center
 * $Id$
 */

// This application
#include "VerticalSpineModel.h"
#include "VerticalSpineBendingController.h"
#include "VerticalSpinePassiveController.h"
// This library
#include "ntrt/core/tgModel.h"
#include "ntrt/core/tgSimViewGraphics.h"
#include "ntrt/core/tgSimulation.h"
#include "ntrt/core/tgWorld.h"
// The C++ Standard Library
#include <iostream>

/**
 * The entry point.
 * @param[in] argc the number of command-line arguments
 * @param[in] argv argv[0] is the executable name
 * @return 0
 */
int main(int argc, char** argv)
{
    std::cout << "AppVerticalSpine" << std::endl;

    // First create the world
    const tgWorld::Config config(981);
    tgWorld world(config); 

    // Second create the view
    const double timestep_physics = 0.0001; // seconds
    const double timestep_graphics = 1.f/60.f; // seconds
    tgSimViewGraphics view(world, timestep_physics, timestep_graphics);

    // Third create the simulation
    tgSimulation simulation(view);

    // Fourth create the models with their controllers and add the models to the
    // simulation
    const int segments = 3; // used to be 5
    VerticalSpineModel* myModel = new VerticalSpineModel(segments);
    
    // If desired, add on a controller now.
    // The model contains a pretension parameter, so for simple equilibrium
    // simulations, no controller is needed.

    VerticalSpinePassiveController* const controller = new VerticalSpinePassiveController();
    //VerticalSpineBendingController* const controller = new VerticalSpineBendingController();
    myModel->attach(controller);

    // Finally, add the model (with attached objects) to the simulation.
    simulation.addModel(myModel);
	
    // Run until the user stops
    simulation.run();

    //Teardown is handled by delete, so that should be automatic
    return 0;
}
