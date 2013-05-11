/*
 * FPC.h
 *
 *  Created on: May 6, 2013
 *      Author: bfoley
 */

#ifndef FPC_H_
#define FPC_H_

//#include "ScannerSim.h"
#include "Req.h"
//#include "PDASC.h"
//#include "PDAE.h"
#include "WarmupSourceGradual.h"
#include "Structs.h"
#include "PDParamContainer.h"
#include "FPC.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>

class fpc
{
public:
	fpc();
	virtual ~fpc();

	float FPCMaxDarktime;
	int FPCMaxRepeatTimes;
	float FPCMaxDutyCycle;
	float FPCMaxGateTime;

	int fillParams();
	int writeParams();

private:
};


#endif /* FPC_H_ */
