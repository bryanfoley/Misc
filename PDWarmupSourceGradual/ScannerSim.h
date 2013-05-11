/*
 * ScannerSim.h
 *
 *  Created on: May 4, 2013
 *      Author: bfoley
 */

#ifndef SCANNERSIM_H_
#define SCANNERSIM_H_
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <string>
#include "PDASC.h"
#include "Structs.h"
#include "Req.h"
//#include "FPC.h"

//class ASC;
//class fpc;

class ScannerSim
{
	public:
    //########################################################
    //  Constructor / Destructor
    //########################################################
    ScannerSim();
    virtual ~ScannerSim();

    //########################################################
    //  sendReq:
    //      Sends a request from the Scanner to AE
    //  Parameters:
    //      Scanner Req
    //      response:
    //          Indicates whether the action is done or whether
    //          a firing pattern should be returned to the scanner
    //  returns:
    //      0
    //########################################################
    int sendASCReq(ScannerSimReq Request);

    //########################################################
    //  receiveReq:
    //      Receives a request from the ASC to Scanner
    //  Parameters:
    //      ASC Response
    //      response:
    //          Indicates whether the action is done or whether
    //          a firing pattern should be returned to the scanner
    //  returns:
    //      0
    //########################################################
    int receiveReq();

private:

    //########################################################
    //  Private member variables
    //########################################################
    // Request:
    //scannerSimReq m_req;
    //Response
    //scannerSimReq m_response;
    // Object to communicate with ASC
    ASC m_ASC;
    // Indicates whether TEC is notified of the start of the warmup
    bool m_requestMade;
    //Indicates which step of the gradual warmup we are on
    int m_step;
};


#endif /* SCANNERSIM_H_ */
