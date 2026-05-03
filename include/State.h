#pragma once

extern bool IS_PAUSED;
extern bool IS_SOFT_PAUSED;
extern bool RUNNING_BOT;
// extern bool RAN_ONCE; // used to not auto click loadout until ran once
extern bool needThread;

class State {
public:
  static void checkInGame();
  static void checkState();
  static void changeState();
  static void endThreads();
};