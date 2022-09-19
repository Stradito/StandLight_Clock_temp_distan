#ifndef FANVIEW_H
#define FANVIEW_H

#include <wiringPi.h>
#include <softPwm.h>
#include "LCD.h"
#include "FanState.h"

class FanView
{
private:
    int pwmPin;
    int fanMode;
    char buff[3];
    LCD *lcd;

public:
    FanView(int pwmPin, LCD *lcd);
    ~FanView();
    void setState(int fanMode, int temp);
    void fanView();
    void FanStart();
    void FanStop();
    void Run();
    void Stop();
    void Auto(int temp);
};

#endif