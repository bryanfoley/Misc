/*
 * FPC.cpp
 *
 *  Created on: May 6, 2013
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
#include "FPC.h"

using namespace std;
fpc::fpc()
{
	FPCMaxDarktime = 0.0;
	FPCMaxDutyCycle = .4;
	FPCMaxGateTime = 0.00001;
	FPCMaxRepeatTimes = 1;
	cout << "Created FPC object\n";
}
fpc::~fpc()
{
}


int fpc::fillParams()
{
	int r(0);
	return r;
}

int fpc::writeParams()
{
	int r(0);
	return r;
}



