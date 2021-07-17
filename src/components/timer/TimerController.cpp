#include "TimerController.h"
#include "systemtask/SystemTask.h"

using namespace Pinetime::Controllers;

void TimerCallback(TimerHandle_t xTimer) {
  auto* controller = static_cast<TimerController*>(pvTimerGetTimerID(xTimer));
  controller->OnTimerEnd();
}

TimerController::TimerController() {
  timer = xTimerCreate("Timer", 0, pdFALSE, this, TimerCallback);
}

void TimerController::StartTimer(uint32_t duration) {
  xTimerChangePeriod(timer, pdMS_TO_TICKS(duration), 0);
  xTimerStart(timer, 0);
}

uint32_t TimerController::GetTimeRemaining() {
  if (IsRunning()) {
    TickType_t remainingTime = xTimerGetExpiryTime(timer) - xTaskGetTickCount();
    return (remainingTime * 1000 / configTICK_RATE_HZ);
  }
  return 0;
}

void TimerController::StopTimer() {
  xTimerStop(timer, 0);
}

bool TimerController::IsRunning() {
  return (xTimerIsTimerActive(timer) == pdTRUE);
}

void TimerController::OnTimerEnd() {
  systemTask->PushMessage(System::Messages::OnTimerDone);
}

void TimerController::Register(Pinetime::System::SystemTask* systemTask) {
  this->systemTask = systemTask;
}
