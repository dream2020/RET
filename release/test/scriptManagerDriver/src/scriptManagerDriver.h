 /** @file scriptManagerDriver.h 
  *
  * Version 1.0
  * 
  * 07/07/2016
  * 
  * Generated by YarpGenerator, Emmanuel Senft, PLYM
  *
  * \section component_description Component Description
  *
  * Functionally, the component  does ...xyz...
  * 
  * \section lib_sec Libraries
  *
  * - YARP.
  *
  * \section parameters_sec Parameters
  * 
  * <b>Command-line Parameters </b> 
  * 
  * The following key-value pairs can be specified as command-line parameters 
  * by prefixing \c -- to the key e.g. \c --from file.ini. 
  * The value part can be changed to suit your needs; the default values are 
  * shown below. 
  *
  * - \c from \c scriptManagerDriver.ini 
  *    - specifies the configuration file
  *
  * - \c context \c component/scriptManagerDriver/configuration
  *   - specifies the sub-path from \c $DREAM_ROOT/release
  *   to the configuration file
  *
  * - \c name \c scriptManagerDriver   
  *   - specifies the name of the component (used to form the stem of component port names)  
  *
  *
  * <b>Configuration File Parameters </b>
  *
  * The following key-value pairs can be specified as parameters in the configuration file 
  * (they can also be specified as command-line parameters if you so wish). 
  * The value part can be changed to suit your needs; the default values are shown below. 
  * 
  * Key | Value
  * :-- | :----  
  * _interventionCommandIn | /scriptManagerDriver/interventionCommand:i
  *
  * - description
  *   
  * Key | Value
  * :-- | :---- 
  * _smsStartStopOut | /scriptManagerDriver/smsStartStop:o    
  * _delibStartStopOut | /scriptManagerDriver/delibStartStop:o    
  * _commandSuccessOut | /scriptManagerDriver/commandSuccess:o    
  *
  * - description
  *
  * \section portsa_sec Ports Accessed
  * 
  * - None
  *                      
  * \section portsc_sec Ports Created
  *
  * <b>Input ports</b>
  *
  *  - \c /scriptManagerDriver
  *
  *  - \c /scriptManagerDriver/interventionCommand:i
  *
  * <b>Output ports</b>
  *
  *  - \c /scriptManagerDriver
  *
  *  - \c /scriptManagerDriver/smsStartStop:o
  *  - \c /scriptManagerDriver/delibStartStop:o
  *  - \c /scriptManagerDriver/commandSuccess:o
  *
  * <b>Port types </b>
  *
  * The functional specification only names the ports to be used to communicate with the component 
  * but doesn't say anything about the data transmitted on the ports. This is defined by the following code. 
  *
  * \c BufferedPort<Bottle>		interventionCommandIn; 
  * \c BufferedPort<VectorOf<int>>		smsStartStopOut; 
  * \c BufferedPort<VectorOf<int>>		delibStartStopOut; 
  * \c BufferedPort<VectorOf<int>>		commandSuccessOut; 
  *
  * \section in_files_sec Input Data Files
  *
  * None
  *
  * \section out_data_sec Output Data Files
  *
  * None
  *
  * \section conf_file_sec Configuration Files
  *
  * \c scriptManagerDriver.ini   
  *
  * \section example_sec Example Instantiation of the Component
  * 
  * <tt>scriptManagerDriver --name scriptManagerDriver --context scriptManagerDriver/config --from scriptManagerDriver.ini </tt>
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
  * 07/07/2016 Version 1.0: ... (James Kennedy)
  */ 
 
#ifndef SCRIPTMANAGERDRIVER
#define SCRIPTMANAGERDRIVER

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

class ScriptManagerDriverYarpInterface;
class ScriptManagerDriverController;

class InterventionCommandInAnalyser : public BufferedPort<Bottle>{
   virtual void onRead(Bottle& interventionCommandInData);
   ScriptManagerDriverYarpInterface *_scriptManagerDriverYarpInterface;
public:
   void setScriptManagerDriver(ScriptManagerDriverYarpInterface* yarpInterface);
};



class ScriptManagerDriverThread : public yarp::os::Thread{
private:
	/* class variables */
	yarp::os::BufferedPort<Bottle>* _interventionCommandIn;
	yarp::os::BufferedPort<VectorOf<int>>* _smsStartStopOut;
	yarp::os::BufferedPort<VectorOf<int>>* _delibStartStopOut;
	yarp::os::BufferedPort<VectorOf<int>>* _commandSuccessOut;
	ScriptManagerDriverYarpInterface* _yarpInterface;
	InterventionCommandInAnalyser *_interventionCommandInAnalyser;
	
public:
	/* class methods */
	ScriptManagerDriverThread(BufferedPort<Bottle>* interventionCommandIn, BufferedPort<VectorOf<int>>* smsStartStopOut, BufferedPort<VectorOf<int>>* delibStartStopOut, BufferedPort<VectorOf<int>>* commandSuccessOut);
   void setYarpInterface(ScriptManagerDriverYarpInterface* yarpInterface);
	bool threadInit();
	void threadRelease();
	void sendToSmsStartStop(VectorOf<int> data);
	void sendToDelibStartStop(VectorOf<int> data);
	void sendToCommandSuccess(VectorOf<int> data);
	void run();
};

class ScriptManagerDriver : public yarp::os::RFModule{
private:
	/* module parameters */
	std::string _moduleName;
	std::string _interventionCommandInName;
	std::string _smsStartStopOutName;
	std::string _delibStartStopOutName;
	std::string _commandSuccessOutName;
	std::string _handlerPortName;

	/* class variables */
	yarp::os::BufferedPort<Bottle> _interventionCommandIn;
	yarp::os::BufferedPort<VectorOf<int>> _smsStartStopOut;
	yarp::os::BufferedPort<VectorOf<int>> _delibStartStopOut;
	yarp::os::BufferedPort<VectorOf<int>> _commandSuccessOut;
	yarp::os::Port _handlerPort;

	/* pointer to a new thread */
	ScriptManagerDriverThread* _scriptManagerDriverThread;
	ScriptManagerDriverController* _scriptManagerDriverController;
	ScriptManagerDriverYarpInterface* _scriptManagerDriverYarpInterface;
public:
	/* class methods */
	bool configure(yarp::os::ResourceFinder &rf);
	bool interruptModule();
	bool close();
	bool respond(const yarp::os::Bottle& command, Bottle& reply);
	double getPeriod();
	bool updateModule();
};

#endif