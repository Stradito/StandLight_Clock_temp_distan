#include "TempHumidView.h"

TempHumidView::TempHumidView(LCD *lcd)
{
    this->lcd = lcd;
}

TempHumidView::~TempHumidView()
{
}

void TempHumidView::setTempHumidData(float temp, float humid)
{
    char buff[30];
    if (temp >= 31) {
        sprintf(buff, "Warning");
        lcd->WriteStringXY(0, 10, buff);
        sprintf(buff, "%.1f%%", humid);
        lcd->WriteStringXY(1, 10, buff);
    }
    else{
        sprintf(buff, "%.1fC ", temp);
        lcd->WriteStringXY(0, 10, buff);
        sprintf(buff, "%.1f%% ", humid);
        lcd->WriteStringXY(1, 10, buff);
    }
}