#include "Controller.h"

Controller::Controller(Service *serv, ClockService *clockServ, TempHumidService *tempHumidService,  FanService *fanService)
{
    service = serv;
    clockService = clockServ;
    this->fanService = fanService;
    this->temHumidService = tempHumidService;
    lightState = LIGHT_OFF;
}

Controller::~Controller()
{
}

void Controller::updateEvent(std::string strBtn)
{
    if (strBtn == "modeButton")
    {
        service->updateState("modeButton");
    }
    if (strBtn == "powerButton")
    {
        service->updateState("powerButton");
    }
    if (strBtn == "playButton")
    {
        service->updateState("playButton");
    }
    if (strBtn == "clockUpdate")
    {
        clockService->updateEvent();
    }
    
}

void Controller::updateFan(std::string strBtn, int temp)
{
    if (strBtn == "fanButton")
    {
        fanService->updateFan("fanUpdate", temp);
    }
    if (strBtn == "Temp")
    {
        fanService->updateFan("Temp", temp);
    }
}

void Controller::updateTempHumid(DHT_Data dhtData)
{
    temHumidService->updateEvent(dhtData);
}

void Controller::updateDistance(int distance, int temp)
{
    service->updateDistance(distance);
    fanService->updateDistance(distance, temp);
}