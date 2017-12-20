/* 
 * Copyright (C) 2014 DREAM Consortium
 * FP7 Project 611391 co-funded by the European Commission
 *
 * Author:  Erik Billing, University of Skovde 
 * Email:   erik.billing@his.se 
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
  * xx/xx/xx Version 1.0: ... (authorName)
  */ 

#include "sensoryInterpretationLogger.h"

int main(int argc, char *argv[])
{
	/* initilize yarp network */
	yarp::os::Network yarp;

	/* create the module */
	SensoryInterpretationLogger sensoryInterpretationLogger;

	/* prepare and configure the resource finder */
	yarp::os::ResourceFinder rf;
	rf.setVerbose(true);
	rf.setDefaultConfigFile("sensoryInterpretationLogger.ini");             // can be overridden by --from parameter
	rf.setDefaultContext("components/sensoryInterpretationLogger/config");   // can be overridden by --context parameter
	rf.configure("DREAM_ROOT",argc, argv);

	/* run the module: runModule() calls configure first, and if successful, it then runs */
	sensoryInterpretationLogger.runModule(rf);

	return 0;
}