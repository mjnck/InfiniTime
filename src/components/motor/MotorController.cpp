#include "MotorController.h"
#include <hal/nrf_gpio.h>
#include "systemtask/SystemTask.h"

using namespace Pinetime::Controllers;

MotorController::MotorController(Controllers::Settings& settingsController) : settingsController {settingsController} {
  nrf_gpio_cfg_output(pinMotor);
  nrf_gpio_pin_set(pinMotor);
  motorTimer = xTimerCreate("MotorTimer", 0, pdFALSE, this, StopMotor);
}

void MotorController::SetDuration(uint8_t motorDuration) {
  if (settingsController.GetVibrationStatus() == Controllers::Settings::Vibration::OFF) {
    return;
  }
  if (xTimerChangePeriod(motorTimer, pdMS_TO_TICKS(motorDuration), 0) == pdPASS) {
    if (xTimerStart(motorTimer, 0) == pdPASS) {
      nrf_gpio_pin_clear(pinMotor);
    }
  }
}

void MotorController::StopMotor(void* p_context) {
  nrf_gpio_pin_set(pinMotor);
}
