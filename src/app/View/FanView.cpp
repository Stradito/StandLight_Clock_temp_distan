#include "FanView.h"

FanView::FanView(int pwmPin, LCD *lcd)
{
    this->pwmPin = pwmPin;
    this->lcd = lcd;
    fanMode = STOP;
    sprintf(buff, "S");
}

FanView::~FanView()
{
}

void FanView::setState(int fanMode, int temp)
{
    switch (fanMode)
    {
    case STOP:
        Stop();
        break;
    
    case RUN:
        Run();
        break;
    
    case AUTO:
        Auto(temp);
        break;
    }
}

void FanView::fanView()
{
    lcd->WriteStringXY(1, 9, buff);
}

void FanView::FanStart()
{
    softPwmWrite(pwmPin, 70);
}

void FanView::FanStop()
{
    softPwmWrite(pwmPin, 0);
}

void FanView::Run()
{
    FanStart();
    sprintf(buff, "R");
}
void FanView::Stop()
{
    FanStop();
    sprintf(buff, "S");
}
void FanView::Auto(int temp)
{
    if (temp >= 29)
    {
        FanStart();
    }
    else
    {
        FanStop();
    }
    sprintf(buff, "A");
}