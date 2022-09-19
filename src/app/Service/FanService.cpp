#include "FanService.h"

FanService::FanService(FanView *fan)
{
    fanView = fan;
    fanMode = STOP;
    bFanMode = false;
}

FanService::~FanService()
{
}

void FanService::updateFan(std::string strFan, int temp)
{
    static int auto_;
    switch (fanMode)
    {
    case STOP:
        if (strFan == "fanUpdate")
        {
            fanMode = RUN;
            fanView->setState(fanMode, temp);
        }
        break;
    case RUN:
        if (strFan == "fanUpdate")
        {
            fanMode = AUTO;
            fanView->setState(fanMode, temp);
            auto_ = 0;
        }
        break;
    case AUTO:
        if (strFan == "fanUpdate")
        {
            fanMode = STOP;
            auto_ = 1;
            fanView->setState(fanMode, temp);
        }
        if(strFan == "Temp" && auto_ == 1)
        {
            fanView->Auto(temp);
        }
        break;
    }
}

void FanService::updateDistance(int distance, int temp)
{
    static int count;

    if (distance > 50 || distance < 0)
    {
        count++;
        if (count >= 10) {
            bFanMode = false;
        }
    }
    else
    {
        count = 0;
        bFanMode = true;
    }

    if (bFanMode) {
        fanView->setState(fanMode, temp);
    }
    else {
        fanView->setState(STOP, temp);
    }
}