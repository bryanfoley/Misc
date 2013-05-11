#ifndef PDWARMUPSOURCEGRADUAL_H_
#define PDWARMUPSOURCEGRADUAL_H_
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
#include "PDParamContainer.h"
#include "TEC.h"
#include "Structs.h"
#include "FPC.h"
//#include "PDAE.h"

class TEC;
class PDParamContainer;
class fpc;

class PDWarmupSourceGradual
{
    public:

        //########################################################
        //  Constructor / Destructor
        //########################################################
        PDWarmupSourceGradual();
        virtual ~PDWarmupSourceGradual();

        //########################################################
        //  Execute:
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
        int execute();

        //########################################################
        //  Functions inherited from PDAction
        //########################################################
        virtual int abort();
        virtual void getName();
        virtual int getProgress(float &progress);

    private:

        //########################################################
        //  Enumeration for the possible action states
        //########################################################
        enum PDWarmupSourceGradualStates
        {
            STATE_IDLE,
            STATE_WAIT_FOR_END_OF_FIRING_PATTERN,
            STATE_WAIT_FOR_END_OF_FIRING_PATTERN_STEP
        };

        //########################################################
        //  Private member functions
        //########################################################
        // Sets the firing pattern
        int setFiringPattern(int step);
        int setUsingDutyCycle();

        //########################################################
        //  Private member variables
        //########################################################
        // State of the action:
        PDWarmupSourceGradualStates m_state;
        // Object to communicate with TEC
        const TEC m_TEC;
        //Object containing the firing pattern constraints
        //fpc &m_fpc;
        // Object containing the parameters
        //PDParamContainer &m_parameters;
        //Indicates if a Gradual Warmup is required
        bool m_warmupGradualNeeded;
        // Indicates whether TEC is notified of the start of the warmup
        bool m_warmupGradualStarted;
        //Indicates which step of the gradual warmup we are on
        int m_step;
};

#endif /* PDWarmupSourceGradual_H_ */
