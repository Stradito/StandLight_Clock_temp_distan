#include <iostream>
#include <wiringPi.h>
#include "Button.h"
#include "Led.h"
#include "Listener.h"
#include "Controller.h"
#include "View.h"
#include "Service.h"
#include "LCD.h"
#include "ClockView.h"
#include "ClockService.h"
#include "ClockCheck.h"
#include "I2C.h"
#include "DHT11.h"
#include "TempHumidService.h"
#include "TempHumidView.h"

int main()
{
    std::cout << "Hello World!" << std::endl;

    Button button1(27);
    Button button2(28);
    DHT11 dht(7);
    // DHT_Data dhtData;
    ClockCheck clockCheck;
    Led led1(25);
    Led led2(24);
    Led led3(23);
    Led led4(22);
    Led led5(21);
    LCD lcd(new I2C("/dev/i2c-1", 0x27));
    View view(&led1, &led2, &led3, &led4, &led5, &lcd);
    ClockView clockView(&lcd);
    TempHumidView tempHumidView(&lcd);
    Service service(&view);
    ClockService clockSerivce(&clockView);
    TempHumidService tempHumidService(&tempHumidView);
    Controller control(&service, &clockSerivce, &tempHumidService);
    Listener listener(&button1, &button2, &control, &clockCheck, &dht);
    
    while (1)
    {
        listener.checkEvent();
        view.lightView();
    }

    return 0;
}