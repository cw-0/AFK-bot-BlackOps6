#pragma once

extern bool IS_PAUSED;
extern bool needThread;

class State {
public:
    static void checkState();
    static void changeState();
    static void endThread();
};