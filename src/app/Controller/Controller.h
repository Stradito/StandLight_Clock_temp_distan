#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include <string>
#include "Service.h"
#include "ClockService.h"
#include "DHT_Data.h"
#include "TempHumidService.h"
#include "FanService.h"

class Controller
{
private:
    int lightState;
    Service *service;
    ClockService *clockService;
    FanService *fanService;
    TempHumidService *temHumidService;

public:
    Controller(Service *serv, ClockService *clockServ, TempHumidService *tempHumidService,  FanService *fanService);
    virtual ~Controller();
    void updateEvent(std::string strBtn);
    void updateTempHumid(DHT_Data dhtData);
    void updateDistance(int distance, int temp);
    void updateFan(std::string strBtn, int temp);
};

#endif /* __CONTROLLER_H__ */