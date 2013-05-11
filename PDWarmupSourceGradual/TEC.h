/*
 * TEC.h
 *
 *  Created on: Apr 30, 2013
 *      Author: bfoley
 */

#ifndef TEC_H_
#define TEC_H_

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
#include "Structs.h"
//#include "WarmupSourceGradual.h"

class TEC
{
    public:

        //########################################################
        //  Constructor / Destructor
        //########################################################
        TEC();
        virtual ~TEC();

        //########################################################
        //  startWarmup:
        //      Warms up the source gradually
        //  Parameters:
        //      fpc:
        //          Contains constraints for a potentially new
        //          firing pattern
        //      response:
        //          Indicates whether the action is done or whether
        //          a firing pattern should be returned to the scanner
        //  returns:
        //      0
        //########################################################
        int startWarmup() const;

        //########################################################
        //  finishWarmup:
        //      Warms up the source gradually
        //  Parameters:
        //      fpc:
        //          Contains constraints for a potentially new
        //          firing pattern
        //      response:
        //          Indicates whether the action is done or whether
        //          a firing pattern should be returned to the scanner
        //  returns:
        //      0
        //########################################################
        int finishWarmup() const;

        //########################################################
        //  Functions inherited from PDAction
        //########################################################
        virtual void getName();

    private:

        //########################################################
        //  Enumeration for the possible action states
        //########################################################
        enum TECStates
        {
            STATE_IDLE,
            STATE_WAIT_FOR_END_OF_WARMUP,
            STATE_END_OF_WARMUP
        };


        //########################################################
        //  Private member variables
        //########################################################
        // State of the action:
        TECStates m_state;
        // Object to communicate with TEC
        //ITECProxyClient &m_TEC;
        // Object containing the parameters
        //fpc &m_parameters;
        // Indicates whether TEC is notified of the start of the warmup
        //bool m_warmupGradualStarted;
        //Indicates which step of the gradual warmup we are on
        int m_step;
};


#endif /* TEC_H_ */
