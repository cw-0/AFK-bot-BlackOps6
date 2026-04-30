#include <chrono>
#include <iostream>
#include "State.h"
#include <windows.h>
#include <thread>

#include "Utils.h"

HDC dng = GetDC(NULL);
int CENTER_MINIMAP_X { 152 };
int CENTER_MINIMAP_Y { 175 };
bool IS_PAUSED{};
bool IS_SOFT_PAUSED{};
bool IN_GAME{};
int MISSED_IN_GAME_CHECK = 0;
bool needThread = true;

void State::checkInGame() {
 needThread = true;
 while (needThread) {
  std::this_thread::sleep_for(std::chrono::seconds(1));
  COLORREF c = GetPixel(dng, CENTER_MINIMAP_X, CENTER_MINIMAP_Y);

  int R = (int)GetRValue(c);
  int G = (int)GetGValue(c);
  int B = (int)GetBValue(c);
  // std::cout << "RGB: (" << R << ", " << G << ", " << B << ")\n";

  if (R >= 140 && R <= 240) {
   if (G <= 30) {
    if (B >= 140 && B <= 240) {
     IN_GAME = true;
     IS_SOFT_PAUSED = false; //
     MISSED_IN_GAME_CHECK = 0;
     continue;
    }
   }
  }
  MISSED_IN_GAME_CHECK++;
  if (MISSED_IN_GAME_CHECK >= 3) {
    IN_GAME = false;
    IS_SOFT_PAUSED = true;
   }
 }
 std::cout << "In Game Check Thread Terminated\n";
}

 void State::checkState() {
  if (!IN_GAME) {
   IS_SOFT_PAUSED = true;
  }
  if (IS_PAUSED || IS_SOFT_PAUSED) {
    Utils::clearTerm();
    std::cout << (IS_PAUSED ? "Manually Paused\n" : "Paused. Not In Game\n");
   while (IS_PAUSED || IS_SOFT_PAUSED) {
    ;
   }
   Utils::clearTerm();
   std::cout << "Resumed.\n";
   return;
  } // END IF IS PAUSED

 } // END CHECK STATE

void State::changeState() {
 needThread = true;
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
  std::cout << "Listener Thread Terminated\n";
 }

 void State::endThreads() {
  needThread = false;
 }