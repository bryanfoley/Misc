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
	parameters.fillParams();
	ScannerSim Scanner;
	Scanner.sendASCReq(REQ_WARMUP);
	fpc.FPCMaxDutyCycle = 0.50;
	Scanner.sendASCReq(REQ_WARMUP);
	fpc.FPCMaxDutyCycle = 0.70;
	Scanner.sendASCReq(REQ_WARMUP);
	fpc.FPCMaxDutyCycle = 0.90;
	Scanner.sendASCReq(REQ_WARMUP);
	Scanner.sendASCReq(REQ_WARMUP);
	fpc.FPCMaxDutyCycle = 0.15;
	Scanner.sendASCReq(REQ_EMPTY);

    exit(0);
}
