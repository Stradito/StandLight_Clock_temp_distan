#include <iostream>
#include <wiringPi.h>
#include "Button.h"
#include "Led.h"
#include "Listener.h"
#include "Controller.h"
#include "View.h"
#include "Service.h"
#include "ClockService.h"
#include "TempHumidService.h"
#include "FanService.h"
#include "LCD.h"
#include "ClockView.h"
#include "ClockCheck.h"
#include "TempHumidView.h"
#include "FanView.h"
#include "I2C.h"
#include "DHT11.h"
#include "UltraSonic.h"

int main()
{
    std::cout << "Hello World!" << std::endl;

    int pwmPin = 26;

    wiringPiSetup();
    softPwmCreate(pwmPin, 0, 100);

    Button button1(27);
    Button button2(28);
    Button button3(29);
    Button button4(0);
    DHT11 dht(7);
    UltraSonic ultraSonic(5, 4);
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
    FanView fanView(pwmPin, &lcd);
    Service service(&view);
    ClockService clockSerivce(&clockView);
    TempHumidService tempHumidService(&tempHumidView);
    FanService FanService(&fanView);
    Controller control(&service, &clockSerivce, &tempHumidService, &FanService);
    Listener listener(&button1, &button2, &button3, &button4, &control, &clockCheck, &dht, &ultraSonic);
    
    while (1)
    {
        listener.checkEvent();
        view.lightView();
        fanView.fanView();
    }

    return 0;
}