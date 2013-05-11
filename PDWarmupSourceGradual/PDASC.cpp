#include "ScannerSim.h"
#include "Req.h"
#include "PDASC.h"
#include "PDAE.h"
#include "Structs.h"
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
ASC::ASC():
		//m_fpc(),
		m_AE()
{
	cout << "Created ASC object\n";
}
ASC::~ASC()
{
}


int ASC::receiveScannerSimReq(ScannerSimReq Request)
{
	int r;
	switch(Request)
	{
		case REQ_WARMUP:
		{
			cout << "\t\tASC has received a request to warmup from the ScannerSim \n";
			r = m_AE.receiveASCReq(Request);
			if (r==0)
			{
				cout << "\t\tRequest to Warmup successfuly sent to AE\n";
			}
			break;
		}

		default:
		{
			cout << "Unknown Request \n";
			break;
		}
	}
	return r;
}

int sendAEReq()
{
	return 0;
}
