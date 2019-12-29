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

#include "ntrt/tgcreator/tgStructure.h"
#include "ntrt/tgcreator/tgUtil.h"

int main(int argc, char** argv)
{
    
    tgStructure* s = new tgStructure();
    
    s->addNode(0, 0, 0, "origin");
    s->addNode(1,1,1, "something");
    
    std::cout << "tgStructure nodes: " << std::endl;
    std::cout << s->getNodes() << std::endl; 
    
}