//*****************************************************************************
//                            Includes
//****************************************************************************

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <string>
#include "ScannerSim.h"
#include "PDASC.h"
#include "Structs.h"
#include "Req.h"
#include "FPC.h"


using namespace std;

    //*****************************************************************************
    //                            Implementation
    //*****************************************************************************

    //########################################################
    //  Constructor / destructor
    //########################################################
    ScannerSim::ScannerSim():
        m_ASC(),
	    m_requestMade(false),
	    m_step(0)
{
    	cout << "Created a ScannerSim object\n";
}
    ScannerSim::~ScannerSim()
{
}


    //########################################################
    //  sendReq:
    //########################################################
    int ScannerSim::sendASCReq(ScannerSimReq Request)
    {
    	int r;
    	if (Request == REQ_WARMUP)
    	{
    		cout << "\tScannerSim has Received a request! \n";
    		r = m_ASC.receiveScannerSimReq(Request);
    		if (r==0)
    		{
    			cout << "\tRequest to warmup successfuly sent to ASC \n";
    		}
    	}
    	return r;
    }


