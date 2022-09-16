#ifndef __LISTENER_H__
#define __LISTENER_H__

#include "wiringPi.h"
#include "Button.h"
#include "ClockCheck.h"
#include "Controller.h"
#include "DHT11.h"
#include "DHT_Data.h"

class Listener
{
private :
    Button *powerButton;
    Button *modeButton;
    DHT11 *dht11;
    ClockCheck *clockCheck;
    Controller *controller;

public:
    Listener(Button *powerButton, Button *modeButton, Controller *control, ClockCheck *clock, DHT11 *dht11);
    ~Listener();
    void checkEvent();
};

#endif /* __LISTENER_H__ */