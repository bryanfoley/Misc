/*
 * PDAE.h
 *
 *  Created on: May 5, 2013
 *      Author: bfoley
 */

#ifndef PDAE_H_
#define PDAE_H_

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

class PDWarmupSourceGradual;
class PDParamContainer;
class fpc;

class AE
{
		public:
			//########################################################
		    //  Constructor / Destructor
		    //########################################################
		    AE();
		    virtual ~AE();

		    int sendPDReq(ScannerSimReq Request);
		    int receiveASCReq(ScannerSimReq Request);

		    PDParamContainer m_parameters;
		    PDWarmupSourceGradual m_PDAction;

		private:
		    //fpc &m_fpc;

};


#endif /* PDAE_H_ */
