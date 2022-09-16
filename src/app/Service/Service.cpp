#include "Service.h"

Service::Service(View *viewer)
{
    view = viewer;
    lightState = LIGHT_OFF;
    bDistanceLight = false;
}

Service::~Service()
{

}

void Service::updateState(std::string strState)
{
    switch (lightState)
    {
        case LIGHT_OFF:
            if (strState == "powerButton") {
                lightState = LIGHT_1;
                view->setState(lightState);
            }
        break;

        case LIGHT_1:
            if (strState == "modeButton") {
                lightState = LIGHT_2;
                view->setState(lightState);
            }
            else if (strState == "powerButton" || strState == "overTemp") {
                lightState = LIGHT_OFF;
                view->setState(lightState);
            }
        break;
        case LIGHT_2:
            if (strState == "modeButton") {
                lightState = LIGHT_3;
                view->setState(lightState);
            }
            else if (strState == "powerButton" || strState == "overTemp") {
                lightState = LIGHT_OFF;
                view->setState(lightState);
            }
        break;
        case LIGHT_3:
            if (strState == "modeButton") {
                lightState = LIGHT_4;
                view->setState(lightState);
            }
            else if (strState == "powerButton" || strState == "overTemp") {
                lightState = LIGHT_OFF;
                view->setState(lightState);
            }
        break;
        case LIGHT_4:
            if (strState == "modeButton") {
                lightState = LIGHT_5;
                view->setState(lightState);
            }
            else if (strState == "powerButton" || strState == "overTemp") {
                lightState = LIGHT_OFF;
                view->setState(lightState);
            }
        break;
        case LIGHT_5:
            if (strState == "modeButton") {
                lightState = LIGHT_1;
                view->setState(lightState);
            }
            else if (strState == "powerButton" || strState == "overTemp") {
                lightState = LIGHT_OFF;
                view->setState(lightState);
            }
        break;
    }
}

void Service::updateDistance(int distance)
{
    static int count;

    printf("distance : %d\n", distance);

    if (distance > 50 || distance < 0)
    {
        count++;
        if (count > 10) {
            bDistanceLight = false;
        }
    }
    else
    {
        count = 0;
        bDistanceLight = true;
    }

    if (bDistanceLight) {
        view->setState(lightState);
    }
    else {
        view->setState(LIGHT_OFF);
    }c
}