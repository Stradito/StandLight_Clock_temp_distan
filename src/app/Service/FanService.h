#ifndef FANSERVICE_H
#define FANSERVICE_H

#include <string>
#include "FanView.h"
#include "FanState.h"

class FanService
{
private:
    int fanMode;
    bool bFanMode;
    FanView *fanView;

public:
    FanService(FanView *fan);
    ~FanService();
    void updateFan(std::string strFan, int temp);
    void updateDistance(int distance, int temp);
};

#endif