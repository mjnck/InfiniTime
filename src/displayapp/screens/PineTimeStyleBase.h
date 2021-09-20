#pragma once

#include "Screen.h"
#include <lvgl/src/lv_core/lv_obj.h>

namespace Pinetime {
  namespace Applications {
    namespace Screens {
      class PineTimeStyleBase : public Screen {
      public:
        PineTimeStyleBase(DisplayApp* app, lv_color_t bgColor, lv_color_t timeColor, lv_color_t barColor);

      protected:
        lv_color_t needle_colors[1];
        lv_obj_t* backgroundLabel;
        lv_obj_t* batteryIcon;
        lv_obj_t* batteryPlug;
        lv_obj_t* bleIcon;
        lv_obj_t* calendarBar1;
        lv_obj_t* calendarBar2;
        lv_obj_t* calendarCrossBar1;
        lv_obj_t* calendarCrossBar2;
        lv_obj_t* calendarInner;
        lv_obj_t* calendarOuter;
        lv_obj_t* dateDay;
        lv_obj_t* dateDayOfWeek;
        lv_obj_t* dateMonth;
        lv_obj_t* notificationIcon;
        lv_obj_t* sidebar;
        lv_obj_t* stepGauge;
        lv_obj_t* timeAMPM;
        lv_obj_t* timeDD1;
        lv_obj_t* timeDD2;
        lv_obj_t* timebar;
      };
    }
  }
}
