#pragma once

#include <FreeRTOS.h>
#include <timers.h>
#include "components/settings/Settings.h"

namespace Pinetime {
  namespace Controllers {
    static constexpr uint8_t pinMotor = 16;

    class MotorController {
    public:
      MotorController(Controllers::Settings& settingsController);
      void SetDuration(uint8_t motorDuration);

    private:
      Controllers::Settings& settingsController;
      static void StopMotor(void* p_context);
      TimerHandle_t motorTimer;
    };
  }
}
