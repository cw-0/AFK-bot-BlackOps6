//
// Created by Caden on 4/28/2026.
//

#include <chrono>
#include "State.h"
#include <thread>
#include <iostream>
#include <limits>
#include "Movement.h"
#include "Presets.h"
#include "Script.h"
#include "TUI.h"
#include "Utils.h"

void TUI::run() {
    while (true){
        Utils::clearTerm();
        switch (int choice = menu()) {
            case 0:
                return;

            case 1:
                startBot(5);

            case 2:
                settingsMenu();
            default:
                continue;
        }

    } // END LOOP
} // END RUN

void TUI::printTitle() {
    std::cout << "Black Ops 6 AFK Bot" << '\n';
    std::cout << "\n\n";
}

int TUI::menu() {
    int choice;
    printTitle();

    std::cout << "1. Start\n";
    std::cout << "2. Settings\n";
    std::cout << "0. Exit\n";
    std::cout << std::endl;
    std::cout << "> ";
    std::cin >> choice;
    return choice;


}

void TUI::startBot(int waitTime) {
    //TODO: Add Choice Of Preset
    std::thread listener(State::changeState);
    std::thread inGameCheck(State::checkInGame);
    for (int i = waitTime; i > 0; i--) {
        std::cout << "Starting in " << i << '\n';
        std::this_thread::sleep_for(std::chrono::seconds(1));
        State::checkState();
    }
    Utils::clearTerm();
    for (int i = 0; i < 3; i++) {
        Presets::commonSoldier();
        Presets::crackhead();
    }
    State::endThreads();
}

void TUI::settingsMenu() {
    while (true) {
        Utils::clearTerm();
        printTitle();

        int choice;

        std::cout << "0. Back\n";
        std::cout << "\n";
        std::cout << "> ";
        std::cin >> choice;

        if (choice == 0){
            return;
        }

    } // END LOOP
} // END settingsMenu


