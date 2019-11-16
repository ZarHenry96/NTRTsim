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
 * @file AppSUPERball.cpp
 * @brief Contains the definition function main() for the Super Ball applicaiton
 * application.
 * $Id$
 */

// This application
#include "SuperBallModel.h"
#include "SuperBallLearningController.h"
// This library
#include "ntrt/core/terrain/tgBoxGround.h"
#include "ntrt/core/terrain/tgPlaneGround.h"
#include "ntrt/core/tgModel.h"
#include "ntrt/core/tgSimViewGraphics.h"
#include "ntrt/core/tgSimulation.h"
#include "ntrt/core/tgWorld.h"
// Bullet Physics
#include "LinearMath/btVector3.h"
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
    std::cout << "AppSUPERball" << std::endl;

    // First create the ground and world
    
    // Determine the angle of the ground in radians. All 0 is flat
    const double yaw = 0.0;
    const double pitch = 0.0;//M_PI/15.0;
    const double roll = 0.0;
//    const tgBoxGround::Config groundConfig(btVector3(yaw, pitch, roll));
//    // the world will delete this
//    tgBoxGround* ground = new tgBoxGround(groundConfig);

    const tgPlaneGround::Config groundConfig(btVector3(0.0,1.0,0.0));
    // the world will delete this
    tgPlaneGround* ground = new tgPlaneGround(groundConfig);

    
    const tgWorld::Config config(98.1); // gravity, cm/sec^2  Use this to adjust length scale of world.
        // Note, by changing the setting below from 981 to 98.1, we've
        // scaled the world length scale to decimeters not cm.
    tgWorld world(config, ground);

    // Second create the view
    const double timestep_physics = 1.0 / 60.0 / 10.0; // Seconds
    const double timestep_graphics = 1.f /60.f; // Seconds

//    tgSimViewGraphics view(world, timestep_physics, timestep_graphics);
    tgSimView view(world, timestep_physics, timestep_graphics);

    // Third create the simulation
    tgSimulation simulation(view);

    // Fourth create the models with their controllers and add the models to the
    // simulation
    SuperBallModel* const myModel = new SuperBallModel(world);

    // Fifth, select the controller to use. Uncomment desired controller.

    // For the T6RestLengthController, pass in the amount of cable to contract
    // in. This is the "rest length difference": the static offset of cable
    // length between geometric length in equilibrium and the actual rest length
    // of an individual cable. 
    // Note for the above scale of gravity, this is in decimeters.


    SuperBallPrefLengthController* const pTC = new SuperBallPrefLengthController(9);


    // For the T6TensionController,
    // Set the tension of the controller units of kg * length / s^2
    // So 10000 units at this scale is 1000 N

    // T6TensionController* const pTC = new T6TensionController(10000);

    myModel->attach(pTC);
    simulation.addModel(myModel);
    
    // Run for 60 secs
    int simLength=60/timestep_physics;
    int i = 0;
    while (i < 10000)
    {
        simulation.run(simLength);
        simulation.reset();
        i++;
    }

    //Teardown is handled by delete, so that should be automatic
    return 0;
}
