/*
 * PDASC.h
 *
 *  Created on: May 4, 2013
 *      Author: bfoley
 */
#ifndef PDASC_H_
#define PDASC_H_
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
#include "ScannerSim.h"
#include "Structs.h"
#include "Req.h"
#include "PDAE.h"
#include "FPC.h"

class AE;
class fpc;

class ASC
{
	public:
		//########################################################
	    //  Constructor / Destructor
	    //########################################################
	    ASC();
	    virtual ~ASC();

	    int sendAEReq(ScannerSimReq Request);
	    int receiveScannerSimReq(ScannerSimReq Request);

	private:
	    AE m_AE;

};

#endif /* PDASC_H_ */
