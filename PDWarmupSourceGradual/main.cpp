/*======Inclusions==========*/


#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
#include "Structs.h"
#include "ScannerSim.h"
#include "WarmupSourceGradual.h"
#include "TEC.h"
#include "Req.h"
#include "FPC.h"


/*======Definitions=========*/

int main (void);


/*========Main==============*/

fpc fpc;
PDParamContainer parameters;

int main (void) {
    /*Initialize*/
	//float progress;
	parameters.fillParams();
	ScannerSim Scanner;
	//PDParamContainer parameters;
	//cout << parameters.getSize();
	Scanner.sendASCReq(REQ_WARMUP);
	fpc.FPCMaxDutyCycle = 0.50;
	Scanner.sendASCReq(REQ_WARMUP);
	fpc.FPCMaxDutyCycle = 0.70;
	Scanner.sendASCReq(REQ_WARMUP);
	fpc.FPCMaxDutyCycle = 0.90;
	Scanner.sendASCReq(REQ_WARMUP);
	Scanner.sendASCReq(REQ_WARMUP);
	fpc.FPCMaxDutyCycle = 0.15;
	Scanner.sendASCReq(REQ_WARMUP);
	//PDParamContainer parameters;
	//fpc fpc;
	//fpc.FPCMaxDarktime = 0.0;
	//fpc.FPCMaxDutyCycle = 1.0;
	//fpc.FPCMaxGateTime = 0.00001;
	//fpc.FPCMaxRepeatTimes = 1;




    /*parameters.FPDarktime = 0.0;

    parameters.FPRepeatTimes = 1;

    parameters.FPDutyCycle[0] = 0.30;
    parameters.FPDutyCycle[1] = 0.60;
    parameters.FPDutyCycle[2] = 0.90;

    parameters.FPGateTime[0] = 0.00001;
    parameters.FPGateTime[1] = 0.00001;
    parameters.FPGateTime[2] = 0.00001;*/

    //PDWarmupSourceGradual PDAction(fpc, parameters);

    //PDAction.getName();
    //PDAction.execute();
    //PDAction.getProgress(progress);

    exit(0);
}
