//*****************************************************************************
//                            Includes
//*****************************************************************************
#include "WarmupSourceGradual.h"
#include "PDParamContainer.h"
#include "TEC.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
extern fpc fpc;
extern PDParamContainer parameters;
using namespace std;

    //*****************************************************************************
    //                            Implementation
    //*****************************************************************************

    //########################################################
    //  Constructor / destructor
    //########################################################
    PDWarmupSourceGradual::PDWarmupSourceGradual():
        m_state(STATE_IDLE),
        m_TEC(),
        //m_fpc(),
        //m_parameters(parameters),
        m_warmupGradualNeeded(false),
        m_warmupGradualStarted(false),
	    m_step(0)
{
}
PDWarmupSourceGradual::~PDWarmupSourceGradual()
{
}

    //########################################################
    //  getName:
    //########################################################
    void PDWarmupSourceGradual::getName()
    {
        cout << "Warm Up Source Gradual \n";
        //m_parameters.fillParams();
    }

    //########################################################
    //  Abort:
    //########################################################
    int PDWarmupSourceGradual::abort()
    {
       int r(0);
        if (m_warmupGradualStarted)
        {
            r = m_TEC.finishWarmup();
            m_warmupGradualStarted = false;
        }
        m_state = STATE_IDLE;
	    m_step = 0;
        return r;
    }

    //########################################################
    //  GetProgress:
    //########################################################
    int PDWarmupSourceGradual::getProgress(float &progress)
    {
        if (STATE_WAIT_FOR_END_OF_FIRING_PATTERN_STEP == m_state)
        {
            progress = (m_step+1)/3.0f;
        }
        else
        {
            progress = 1.0f;
        }
    return 0;
    }

    //########################################################
    //  Execute:
    //########################################################
    int PDWarmupSourceGradual::execute()
    {
    int r;
	//Number of Warmups that are in the parameters
	int count = parameters.getSize();
	count = parameters.getSize();
	//Counter used to assign if a warmup is needed and at what DC
	int i = 0;
	//Int used to determine if the Warmup is needed
	int j = 0;
    switch (m_state)
    {
        case STATE_IDLE:
        {
        	//Loop through the parameters to find a DC that is within constraints
        	for(i = 0; i < count-1; i++)
        	{
        		if(parameters.FPDutyCycle[i] < fpc.FPCMaxDutyCycle)
        			j++;
        		//break;
        	}

        	m_warmupGradualNeeded = ((j == 0) ? false : true);
        	m_step = j;

        	//If we have already executed the maximum param duty cycle
        	//if(parameters.FPDutyCycle[m_step] > fpc.FPCMaxDutyCycle)
        	//{
        	//	m_state = STATE_WAIT_FOR_END_OF_FIRING_PATTERN;
        	//	m_warmupGradualNeeded = false;
        	//}

        	//If needed, then communicate with TEC to start a warmup
        	if (m_warmupGradualNeeded)
        	{
        		cout << "\t\t\t\tWarmup Source Gradual started.\n";
        		r = m_TEC.startWarmup();

        		if (r==0)
        		{
        			m_warmupGradualStarted = true;
            		r = setFiringPattern(m_step);
        		}
        		else
        		{
        			m_state = STATE_WAIT_FOR_END_OF_FIRING_PATTERN;
        			m_warmupGradualStarted = true;
        		}
            //break;
        	}
        	else
        	{
        		cout << "No Warmup action is required\n";
        		m_state = STATE_WAIT_FOR_END_OF_FIRING_PATTERN;
        	}
        }
        case STATE_WAIT_FOR_END_OF_FIRING_PATTERN:
        {
            //response.m_response = IPDAE_RESPONSE_ACTION_COMPLETED;
            if (m_warmupGradualStarted)
            {
                r = m_TEC.finishWarmup();
                m_warmupGradualStarted = false;
                m_warmupGradualNeeded = false;
            }
            m_state = STATE_IDLE;
			m_step = 0;
            cout << "\t\t\t\tWarmup Source Gradual completed.\n";
            break;
        }
        default:
        {
            cout << "Warmup Source Gradual action is in an unknown state.\n";
            r = 1;
            break;
        }
    }
    if (0 != r)
    {
        cout << "Warmup Source Gradual action failed.\n";
        //response.m_response = IPDAE_RESPONSE_ACTION_FAILED;
        abort();
    }
    return r;
}

//########################################################
//  setFiringPattern:
//########################################################
int PDWarmupSourceGradual::setFiringPattern(int step)
{
    int r(0);
    r = setUsingDutyCycle();

    return r;
}

//########################################################
//  setUsingDutyCycle:
//########################################################
int PDWarmupSourceGradual::setUsingDutyCycle()
{
    int r(0);

	if(fpc.FPCMaxDutyCycle < parameters.FPDutyCycle[m_step])
    {
		cout << fpc.FPCMaxDutyCycle;
    	cout << ", ";
    	cout << parameters.FPDutyCycle[m_step];
    	cout << "\n";
		cout << "Duty Cycle requested is too large, using constraint value of ";
    	cout << (fpc.FPCMaxDutyCycle)*100;
    	cout << "% D.C\n";
    	//parameters.FPDutyCycle[m_step] = fpc.FPCMaxDutyCycle;
    	cout << "\n";
    	r = 0;
    }
	else
	{
		cout << "Performing a Warmup @ ";
		cout << (parameters.FPDutyCycle[m_step])*100.0;
		cout << "% D.C\n";
	}

    if (0 == r)
    {
        //response.m_response = IPDAE_RESPONSE_START_FIRING_PATTERN;
    }
    return r;
}
