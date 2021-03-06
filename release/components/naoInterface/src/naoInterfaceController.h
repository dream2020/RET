 /** @file naoInterfaceController.h 
  *
  * Version 1.0
  * 
  * Generated by YarpGenerator, Emmanuel Senft, PLYM
  *
  *
  * \defgroup DREAM_cognitiveComponent naoInterface
  * 
  * Main class with code, use the yarpInterface class to communicate with the other components.
  * 
  * \section lib_sec Libraries
  *
  * None
  *
  * \section in_files_sec Input Data Files
  *
  * None
  *
  * \section out_data_sec Output Data Files
  *
  * None
  *
  * \author 
  * 
  * <James Kennedy>, <Plymouth University>  
  * 
  * Copyright (C) 2014 DREAM Consortium
  * 
  */

/* 
 * Copyright (C) 2014 DREAM Consortium
 * FP7 Project 611391 co-funded by the European Commission
 *
 * Author:  James Kennedy, Plymouth University 
 * Email:   james.kennedy@plymouth.ac.uk 
 * Website: www.dream2020.eu 
 * 
 * This file is part of DREAM.
 * 
 * DREAM is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * DREAM is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with DREAM.  If not, see <http://www.gnu.org/licenses/>.
 */
 
 /* 
  * Audit Trail
  * -----------
  * 22/06/2016 Version 1.0: ... (James Kennedy)
  */ 
 
#ifndef NAOINTERFACECONTROLLER
#define NAOINTERFACECONTROLLER

#include <iostream>
#include <string>
#include <vector>

class NaoInterfaceYarpInterface;
class NaoInterfaceModule;

class NaoInterfaceController{
private:
	NaoInterfaceYarpInterface* _yarpInterface;
	NaoInterfaceModule* _module;
	bool _Bconnected;
	bool _BusingSimulator;
	static const char * const behavioursHardCoded[];
	static const char * const bodyList[];
	std::vector<std::string> _behavioursHardCoded;
	std::vector<std::string> _behaviourFromConfig;
public:
	/* class methods */
	NaoInterfaceController(NaoInterfaceYarpInterface *yarpInterface, std::string ip, int port, std::vector<std::string> behaviourFromConfig, float initialVolume);
   //Need to add the methods calling/being called by the YarpInterface

	void enableRobot(bool enable, int stepId);
	void closeHand(bool rightHand, bool close, int stepId);
	void getFromMoveHand(bool rightHand, float x, float y, float z, float roll, int stepId);
	void getFromMoveTorso(float x, float y, float z, int stepId);
	void say(std::string sentence, int stepId);
	void getFromMoveSequence(int stepId, int seqId);
	bool runBehaviour(int stepId, std::string behaviourName);
	void getFromMoveSequence(int stepId, int seqId, int arg1, int arg2, int arg3);
	void moveHead(float x, float y, float z, float speed, int stepId);
	void pointAt(std::vector<std::vector<float>> goals, bool rightArm, int stepId);
	std::vector<float> calculateShoulderPitchElbowRoll(float x, float y, float z, float armPitch);
	void sensors(std::string  name, bool value);
	void stopAllBehaviours(int stepId);
};

#endif
