#include "Service.h"

Service::Service(View *viewer)
{
    view = viewer;
    lightState = LIGHT_OFF;
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