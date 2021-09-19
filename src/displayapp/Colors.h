#pragma once

#include <lvgl/src/lv_misc/lv_color.h>
#include <components/settings/Settings.h>

namespace Pinetime {
  namespace Applications {
    lv_color_t Convert(Controllers::Settings::Colors color);

    namespace Colors {
      static constexpr lv_color_t darkGray = LV_COLOR_MAKE(0x22, 0x22, 0x22);
      static constexpr lv_color_t darkerGray = LV_COLOR_MAKE(0x11, 0x11, 0x11);
      static constexpr lv_color_t accent = LV_COLOR_AQUA;
    }
  }
}
