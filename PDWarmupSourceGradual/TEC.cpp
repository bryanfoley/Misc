/*
 * TEC.cpp
 *
 *  Created on: Apr 30, 2013
 *      Author: bfoley
 */
#include "TEC.h"
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
    TEC::TEC():
        m_state(STATE_IDLE),
	    m_step(0)
{
}
TEC::~TEC()
{
}

    //########################################################
    //  getName:
    //########################################################
    void TEC::getName()
    {
        cout << "TEC Client \n";
    }


    //########################################################
    //  startWarmup:
    //########################################################
    int TEC::startWarmup() const
    {
    	cout << "\t\t\t\t\tRequest to TEC to BEGIN_WARMUP \n";
    	return 0;
    }

    //########################################################
    //  finishWarmup:
    //########################################################
    int TEC::finishWarmup() const
    {
    	cout << "\t\t\t\t\tRequest to TEC to FINISH_WARMUP \n";
    	return 0;
    }
