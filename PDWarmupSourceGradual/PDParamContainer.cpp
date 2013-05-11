/*
 * PDParamContainer.cpp
 *
 *  Created on: May 5, 2013
 *      Author: bfoley
 */
#include "ScannerSim.h"
#include "Req.h"
#include "PDASC.h"
#include "PDAE.h"
#include "WarmupSourceGradual.h"
#include "Structs.h"
#include "PDParamContainer.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>

using namespace std;

    //*****************************************************************************
    //                            Implementation
    //*****************************************************************************

    //########################################################
    //  Constructor / destructor
    //########################################################
PDParamContainer::PDParamContainer()
{
		FPDarktime = 0.0;

		FPRepeatTimes = 1;

		FPDutyCycle[0] = 0.30;
		FPDutyCycle[1] = 0.60;
		FPDutyCycle[2] = 0.90;

		FPGateTime[0] = 0.00001;
		FPGateTime[1] = 0.00001;
		FPGateTime[2] = 0.00001;
	cout << "Created ParamContainer object\n";
}
PDParamContainer::~PDParamContainer()
{
}


int PDParamContainer::fillParams()
{
	int r(0);
	FPDarktime = 0.0;

	FPRepeatTimes = 1;

	FPDutyCycle[0] = 0.10;
	FPDutyCycle[1] = 0.20;
	FPDutyCycle[2] = 0.30;
	FPDutyCycle[3] = 0.40;
	FPDutyCycle[4] = 0.50;
	FPDutyCycle[5] = 0.60;
	FPDutyCycle[6] = 0.70;
	FPDutyCycle[7] = 0.80;
	FPDutyCycle[8] = 0.90;

	FPGateTime[0] = 0.001;
	FPGateTime[1] = 0.001;
	FPGateTime[2] = 0.001;
	FPGateTime[4] = 0.001;
	FPGateTime[5] = 0.001;
	FPGateTime[6] = 0.001;
	FPGateTime[7] = 0.001;
	FPGateTime[8] = 0.001;


	return r;
}

int PDParamContainer::writeParams()
{
	int r(0);
	return r;
}

int PDParamContainer::getSize()
{
	int count;
	count = sizeof(FPDutyCycle)/sizeof(FPDutyCycle[0]);

	return count;
}




