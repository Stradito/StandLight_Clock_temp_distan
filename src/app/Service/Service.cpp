#include "Service.h"

Service::Service(View *viewer)
{
    view = viewer;
    lightState = LIGHT_OFF;
    mode = BRIGHT;
    timerMode = TIMER_STOP;
    bDistanceLight = false;
}

Service::~Service()
{
}

void Service::updateState(std::string strState)
{
    view->setState(mode ,lightState, timerMode);
    
    switch (mode)
    {
    case BRIGHT:
        switch (lightState)
        {
        case LIGHT_OFF:
            if (strState == "powerButton")
            {
                lightState = LIGHT_1;
            }
            break;

        case LIGHT_1:
            if (strState == "playButton")
            {
                lightState = LIGHT_2;
            }
            else if (strState == "powerButton")
            {
                mode = BRIGHT;
                lightState = LIGHT_OFF;
                timerMode = TIMER_STOP;
            }
            else if (strState == "modeButton")
            {
                mode = TIMER;
            }
            break;
        case LIGHT_2:
            if (strState == "playButton")
            {
                lightState = LIGHT_3;
            }
            else if (strState == "powerButton")
            {
                mode = BRIGHT;
                lightState = LIGHT_OFF;
                timerMode = TIMER_STOP;
            }
            else if (strState == "modeButton")
            {
                mode = TIMER;
            }
            break;
        case LIGHT_3:
            if (strState == "playButton")
            {
                lightState = LIGHT_4;
            }
            else if (strState == "powerButton")
            {
                mode = BRIGHT;
                lightState = LIGHT_OFF;
                timerMode = TIMER_STOP;
            }
            else if (strState == "modeButton")
            {
                mode = TIMER;
            }
            break;
        case LIGHT_4:
            if (strState == "playButton")
            {
                lightState = LIGHT_5;
            }
            else if (strState == "powerButton")
            {
                mode = BRIGHT;
                lightState = LIGHT_OFF;
                timerMode = TIMER_STOP;
            }
            else if (strState == "modeButton")
            {
                mode = TIMER;
            }
            break;
        case LIGHT_5:
            if (strState == "playButton")
            {
                lightState = LIGHT_1;
            }
            else if (strState == "powerButton")
            {
                mode = BRIGHT;
                lightState = LIGHT_OFF;
                timerMode = TIMER_STOP;
            }
            else if (strState == "modeButton")
            {
                mode = TIMER;
            }
            break;
        }
        break;
    case TIMER:
        switch(timerMode)
        {
        case TIMER_STOP:
            if(strState == "playButton")
            {
                timerMode = TIMER_RUN;
            }
            else if (strState == "modeButton")
            {
                mode = BRIGHT;
            }
            else if (strState == "powerButton")
            {
                mode = BRIGHT;
                lightState = LIGHT_OFF;
                timerMode = TIMER_STOP;
            }
        break;

        case TIMER_RUN:
            if(strState == "playButton")
            {
                timerMode = TIMER_FREEZE;
            }
            else if (strState == "modeButton")
            {
                mode = BRIGHT;
            }
            else if (strState == "powerButton")
            {
                mode = BRIGHT;
                lightState = LIGHT_OFF;
                timerMode = TIMER_STOP;
            }
        break;

        case TIMER_FREEZE:
            if(strState == "playButton")
            {
                timerMode = TIMER_RUN;
            }
            else if (strState == "modeButton")
            {
                timerMode = TIMER_STOP;
            }
            else if (strState == "powerButton")
            {
                mode = BRIGHT;
                lightState = LIGHT_OFF;
                timerMode = TIMER_STOP;
            }
        break;
        }
    }
}

void Service::updateDistance(int distance)
{
    static int count;

    printf("distance : %d\n", distance);

    if (distance > 50 || distance < 0)
    {
        count++;
        if (count >= 10) {
            bDistanceLight = false;
        }
    }
    else
    {
        count = 0;
        bDistanceLight = true;
    }

    if (bDistanceLight) {
        view->setState(mode ,lightState, timerMode);
    }
    else {
        view->setState(BRIGHT ,LIGHT_OFF, timerMode);
    }
}