#include <iostream>
#include "TUI.h"
#include "Logger.h"

int main() {
    TUI app;
    Logger::openFile();
    Logger::write("Program Started");
    app.run();
}