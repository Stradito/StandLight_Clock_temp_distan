#ifndef __LISTENER_H__
#define __LISTENER_H__

#include "wiringPi.h"
#include "Button.h"
#include "ClockCheck.h"
#include "Controller.h"
#include "DHT11.h"
#include "DHT_Data.h"
#include "UltraSonic.h"

class Listener
{
private :
    Button *powerButton;
    Button *modeButton;
    Button *playButton;
    Button *fanButton;
    DHT11 *dht11;
    ClockCheck *clockCheck;
    Controller *controller;
    UltraSonic *ultraSonic;

public:
    Listener(Button *powerButton, Button *modeButton, Button *playButton, Button *fanButton, Controller *control, ClockCheck *clock, DHT11 *dht11, UltraSonic *ultraSonic);
    ~Listener();
    void checkEvent();
};

#endif /* __LISTENER_H__ */