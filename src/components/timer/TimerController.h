#pragma once

#include <FreeRTOS.h>
#include <timers.h>

namespace Pinetime {
  namespace System {
    class SystemTask;
  }
  namespace Controllers {

    class TimerController {
    public:
      TimerController();

      void StartTimer(uint32_t duration);

      void StopTimer();

      uint32_t GetTimeRemaining();

      bool IsRunning();

      void OnTimerEnd();

      void Register(System::SystemTask* systemTask);

    private:
      System::SystemTask* systemTask = nullptr;
      TimerHandle_t timer;
    };
  }
}
