#include "View.h"
#include <wiringPi.h>

View::View(Led *led1, Led *led2, Led *led3, Led *led4, Led *led5, LCD *lcd)
{
    light1 = led1;
    light2 = led2;
    light3 = led3;
    light4 = led4;
    light5 = led5;
    lightState = LIGHT_OFF;
    mode = BRIGHT;
    timerMode = TIMER_STOP;
    this->lcd = lcd;
}

View::~View()
{

}

void View::setState(int mode, int lightState, int timerMode)
{
    this-> mode = mode;
    this->lightState = lightState;
    this->timerMode = timerMode;
}

void View::lightView()
{
    switch (mode)
    {
    case BRIGHT:
        switch (lightState)
        {
        case LIGHT_OFF:
            lightOff();
            break;
        case LIGHT_1:
            lightOn_1();
            break;
        case LIGHT_2:
            lightOn_2();
            break;
        case LIGHT_3:
            lightOn_3();
            break;
        case LIGHT_4:
            lightOn_4();
            break;
        case LIGHT_5:
            lightOn_5();
            break;
        }
        break;

    case TIMER:
        timerLcd();
        break;
    }
}

void View::lightOn_1()
{
    char buff[30];
    sprintf(buff, "brihgt 1");
    lcd->WriteStringXY(0, 0, buff);
    lcd->backLightOn();
    light1->On();
    light2->Off();
    light3->Off();
    light4->Off();
    light5->Off();
}

void View::lightOn_2()
{
    char buff[30];
    sprintf(buff, "brihgt 2");
    lcd->WriteStringXY(0, 0, buff);
    lcd->backLightOn();
    light1->On();
    light2->On();
    light3->Off();
    light4->Off();
    light5->Off();
}

void View::lightOn_3()
{
    char buff[30];
    sprintf(buff, "brihgt 3");
    lcd->WriteStringXY(0, 0, buff);
    lcd->backLightOn();
    light1->On();
    light2->On();
    light3->On();
    light4->Off();
    light5->Off();
}

void View::lightOn_4()
{
    char buff[30];
    sprintf(buff, "brihgt 4");
    lcd->WriteStringXY(0, 0, buff);
    lcd->backLightOn();
    light1->On();
    light2->On();
    light3->On();
    light4->On();
    light5->Off();
}

void View::lightOn_5()
{
    char buff[30];
    sprintf(buff, "brihgt 5");
    lcd->WriteStringXY(0, 0, buff);
    lcd->backLightOn();
    light1->On();
    light2->On();
    light3->On();
    light4->On();
    light5->On();
}

void View::lightOff()
{
    char buff[30];
    sprintf(buff, "brihgt 0");
    lcd->WriteStringXY(0, 0, buff);
    lcd->backLightOff();
    light1->Off();
    light2->Off();
    light3->Off();
    light4->Off();
    light5->Off();
}

void View::timerLcd()
{
    static unsigned int time;
    static unsigned int freezeTime;
    static unsigned int prevTime;
    static int start;
    static int freeze;
    char buff[30];
    lcd->backLightOn();

    switch (timerMode)
    {
    case TIMER_RUN:
        if (start)
        {
            start = 0;
            prevTime = millis() / 1000;
            freezeTime = 0;
        }
        if (freeze)
        {
            freeze = 0;
            prevTime = millis() / 1000;
        }
        time = millis() / 1000 - prevTime + freezeTime;
        break;

    case TIMER_STOP:
        time = 0;
        freeze = 0;
        start = 1;
        break;

    case TIMER_FREEZE:
        freezeTime = time;
        freeze = 1;
        break;
    }
    sprintf(buff, "%02d:%02d:%02d", time / 360, time / 60, time % 60);
    lcd->WriteStringXY(0, 0, buff);
}