#include <iostream>
#include "State.h"
#include <windows.h>

#include "Utils.h"

bool IS_PAUSED{};
bool needThread = true;

 void State::checkState() {
  if (IS_PAUSED) {
    Utils::clearTerm();
    std::cout << "Paused.\n";
   // std::cout << "Paused.\nWaiting to resume...\n";
   while (IS_PAUSED) {
    ;
   }
   Utils::clearTerm();
   std::cout << "Resumed.\n";
   return;
  } // END IF IS PAUSED
 } // END CHECK STATE

void State::changeState() {
  while (needThread) {
   if (GetKeyState(0xA4) & 0x8000 && !IS_PAUSED) { // Left Alt
    IS_PAUSED = true;
    std::cout << "PAUSING\n";
   }

   if (GetKeyState(0xA5) & 0x8000 && IS_PAUSED) { // Right Alt
    IS_PAUSED = false;
    std::cout << "RESUMING\n";
   }

   if (GetKeyState(0xA3) & 0x8000 && IS_PAUSED) { // Right Ctrl (Force Exit)
    Utils::clearTerm();
    std::cout << "Force Closing.\n";
    // Utils::releaseAllKeys()
    // If its paused all keys 'should' be released, assuming there are no checkState() calls during a hold
    exit(0);
   }

  }
  std::cout << "Thread Terminated\n";
  needThread = true;
 }

 void State::endThread() {
  needThread = false;
 }