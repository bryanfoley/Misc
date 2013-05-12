/*
 * PDAE.cpp
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
#include "FPC.h"
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
AE::AE():
		m_parameters(),
		m_PDAction()
{
	cout << "Created AE object\n";
}
AE::~AE()
{
}


int AE::receiveASCReq(ScannerSimReq Request)
{
	int r;
	switch(Request)
	{
		case REQ_WARMUP:
		{
			cout << "\t\t\tAE has received a request from the ASC\n";
			r = m_parameters.fillParams();
			cout << "\t\t\tRequest to Warmup sent\n";
			r = m_PDAction.execute();
			if (r==0)
			{
					cout << "\t\t\tRequest to warmup successfully executed!\n";
			}
			else
				r=1;
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

int AE::sendPDReq(ScannerSimReq Request)
{
	int r(0);
	return r;
}





