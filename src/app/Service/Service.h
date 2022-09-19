#ifndef __SERVICE_H__
#define __SERVICE_H__

#include <string>
#include <wiringPi.h>
#include "View.h"
#include "LightState.h"

class Service
{
private:
    int lightState;
    int mode;
    int timerMode;
    View *view;
    bool bDistanceLight;

public:
    Service(View *viewer);
    virtual ~Service();
    void updateState(std::string strState);
    void updateDistance(int distance);
};

#endif /* __SERVICE_H__ */