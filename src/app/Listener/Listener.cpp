#include "Listener.h"

Listener::Listener(Button *powerButton, Button *modeButton, Controller *control, ClockCheck *clock, DHT11 *dht11 ,UltraSonic *ultraSonic)
{
    this->powerButton = powerButton;
    this->modeButton = modeButton;
    this->dht11 = dht11;
    controller = control;
    clockCheck = clock;
    this->ultraSonic = ultraSonic;
}

Listener::~Listener()
{
}

void Listener::checkEvent()
{
    if (modeButton->getState() == RELEASE_ACTIVE)
    {
        controller->updateEvent("modeButton");
    }

    if (powerButton->getState() == RELEASE_ACTIVE)
    {
        controller->updateEvent("powerButton");
    }
    

    if (clockCheck->isUpdate())
    {
        controller->updateEvent("clockUpdate");
    }

    static unsigned int prevTempHumidTime = 0;
    if (millis() - prevTempHumidTime > 2000) {
        prevTempHumidTime = millis();
        DHT_Data dhtData = dht11->readData();
        if (!dhtData.error)
        {
            controller->updateTempHumid(dhtData);
            if (dhtData.Temp >= 31)
            {
                controller->updateEvent("overTemp");
            }
        }
    }

    static unsigned int prevUltraSonicTime = 0;
    if (millis() - prevUltraSonicTime > 1000) {
        prevUltraSonicTime = millis();
        int distance = ultraSonic->readDistance();
        controller->updateDistance(distance);
    }
}