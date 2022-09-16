#ifndef __SERVICE_H__
#define __SERVICE_H__

#include <string>
#include "View.h"
#include "LightState.h"

class Service
{
private:
    int lightState;
    View *view;

public:
    Service(View *viewer);
    virtual ~Service();
    void updateState(std::string strState);
};

#endif /* __SERVICE_H__ */