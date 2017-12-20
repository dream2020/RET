 /** @file wp3StubYarpInterface.h 
  *
  * Version 1.0
  * 
  * Generated by YarpGenerator, Emmanuel Senft, PLYM
  *
  *
  * \defgroup DREAM_cognitiveComponent wp3Stub
  * 
  * Class used to provided a simpler interface between the main code and the YARP layer.
  * Provide an output function sending data for each port, and an input function called 
  * when a message is received on a port.
  * 
  * \section lib_sec Libraries
  *
  * - YARP.
  *
  * \section portsc_sec Ports Created
  *
  * <b>Port types </b>
  *
  *	BufferedPort<VectorOf<double>>		getEyeGazeIn;
  *	BufferedPort<VectorOf<double>>		getGripLocationIn;
  *	BufferedPort<VectorOf<double>>		getHeadGazeIn;
  *	BufferedPort<VectorOf<double>>		getObjectTableDistanceIn;
  *	BufferedPort<VectorOf<double>>		getObjectsIn;
  *	BufferedPort<VectorOf<double>>		identifyFaceIn;
  *	BufferedPort<VectorOf<double>>		identifyFaceExpressionIn;
  *	BufferedPort<VectorOf<double>>		identifyObjectIn;
  *	BufferedPort<VectorOf<int>>		identifyTrajectoryIn;
  *	BufferedPort<VectorOf<double>>		trackFaceIn;
  *	BufferedPort<VectorOf<double>>		trackObjectIn;
  *	BufferedPort<VectorOf<double>>		trackHandIn;
  *	BufferedPort<VectorOf<double>>		getSoundDirectionIn;
  *	BufferedPort<VectorOf<int>>		checkMutualGazeOut;
  *	BufferedPort<VectorOf<double>>		getFacesOut;
  *	BufferedPort<VectorOf<double>>		getSoundDirectionOut;
  *	BufferedPort<VectorOf<double>>		identifyFaceExpressionOut;
  *	BufferedPort<Bottle>		recognizeSpeechOut;
  *	BufferedPort<VectorOf<double>>		getEyeGazeOut;
  *	BufferedPort<VectorOf<double>>		getEyesOut;
  *	BufferedPort<VectorOf<double>>		getArmAngleOut;
  *	BufferedPort<VectorOf<double>>		getBodyOut;
  *	BufferedPort<VectorOf<double>>		getGripLocationOut;
  *	BufferedPort<VectorOf<double>>		getBodyPoseOut;
  *	BufferedPort<VectorOf<double>>		getHandsOut;
  *	BufferedPort<VectorOf<double>>		getHeadOut;
  *	BufferedPort<VectorOf<double>>		getHeadGazeOut;
  *	BufferedPort<VectorOf<double>>		getObjectsOut;
  *	BufferedPort<VectorOf<double>>		getObjectTableDistanceOut;
  *	BufferedPort<VectorOf<double>>		identifyFaceOut;
  *	BufferedPort<VectorOf<double>>		identifyObjectOut;
  *	BufferedPort<VectorOf<double>>		identifyTrajectoryOut;
  *	BufferedPort<VectorOf<int>>		identifyVoiceOut;
  *	BufferedPort<VectorOf<double>>		trackFaceOut;
  *	BufferedPort<VectorOf<double>>		trackObjectOut;
  *	BufferedPort<VectorOf<double>>		getHeadGazePointOut;
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
  * <Emmanuel Senft>, <PLYM>  
  * 
  * Copyright (C) 2014 DREAM Consortium
  * 
  */

/* 
 * Copyright (C) 2014 DREAM Consortium
 * FP7 Project 611391 co-funded by the European Commission
 *
 * Author:  Emmanuel Senft, PLYM 
 * Email:   emmanuel.senft@plymouth.ac.uk 
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
  * 20/09/2016 Version 1.0: ... (Emmanuel Senft)
  */ 
 
#ifndef WP3STUBYARPINTERFACE
#define WP3STUBYARPINTERFACE

#include <iostream>
#include <string>
#include <vector>

#include <yarp/sig/all.h>
#include <yarp/os/all.h>
#include <yarp/os/RFModule.h>
#include <yarp/os/Network.h>
#include <yarp/os/Thread.h>

using namespace yarp::os; 
using namespace yarp::sig;

class Wp3StubThread;
class Wp3StubController;

class Wp3StubYarpInterface{
private:
	Wp3StubThread* _yarpThread;
   Wp3StubController* _controller;
public:
	/* class methods */
	Wp3StubYarpInterface();
   void init(Wp3StubThread* yarpThread, Wp3StubController* controller);
	void getFromGetEyeGaze(VectorOf<double> data);
	void getFromGetGripLocation(VectorOf<double> data);
	void getFromGetHeadGaze(VectorOf<double> data);
	void getFromGetObjectTableDistance(VectorOf<double> data);
	void getFromGetObjects(VectorOf<double> data);
	void getFromIdentifyFace(VectorOf<double> data);
	void getFromIdentifyFaceExpression(VectorOf<double> data);
	void getFromIdentifyObject(VectorOf<double> data);
	void getFromIdentifyTrajectory(VectorOf<int> data);
	void getFromTrackFace(VectorOf<double> data);
	void getFromTrackObject(VectorOf<double> data);
	void getFromTrackHand(VectorOf<double> data);
	void getFromGetSoundDirection(VectorOf<double> data);
	void sendToCheckMutualGaze(bool mutualGaze);
	void sendToGetFaces(VectorOf<double> data);
	void sendToGetSoundDirection(VectorOf<double> data);
	void sendToIdentifyFaceExpression(VectorOf<double> data);
	void sendToRecognizeSpeech(Bottle data);
    void sendToGetEyeGaze();
    int randi(int lo, int hi);
	void sendToGetEyes(VectorOf<double> data);
	void sendToGetArmAngle(VectorOf<double> data);
	void sendToGetBody(VectorOf<double> data);
	void sendToGetGripLocation(VectorOf<double> data);
	void sendToGetBodyPose(VectorOf<double> data);
	void sendToGetHands(VectorOf<double> data);
	void sendToGetHead(VectorOf<double> data);
	void sendToGetHeadGaze(VectorOf<double> data);
	void sendToGetObjects(VectorOf<double> data);
	void sendToGetObjectTableDistance(VectorOf<double> data);
	void sendToIdentifyFace(VectorOf<double> data);
	void sendToIdentifyObject(VectorOf<double> data);
	void sendToIdentifyTrajectory(VectorOf<double> data);
	void sendToIdentifyVoice(VectorOf<int> data);
	void sendToTrackFace(VectorOf<double> data);
	void sendToTrackObject(VectorOf<double> data);
	void sendToGetHeadGazePoint(VectorOf<double> data);
};

#endif