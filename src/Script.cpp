//
// Created by Caden on 4/29/2026.
//

#include "Script.h"

#include <random>

#include <iostream>
#include "Movement.h"
#include <thread>

std::random_device rd2;
std::mt19937 ranGen(rd2());

void Script::lookEyeLevel() {
    Movement::rotate(0, -9000, 225, 0);
    Movement::rotate(0, 3800, 190, 0);

}

void Script::sprayAuto(int seconds) {
    Movement::rightMouseHold();
    Movement::leftMouseHold(true);
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
    Movement::leftMouseRelease();
    Movement::rightMouseRelease();
}

void Script::spraySemi(int shots) {
    Movement::rightMouseHold();
    for (int i = shots; i > 0; i--) {
        Movement::leftMouseClick();
        std::uniform_real_distribution<double> randDelay(0.023, .39);
        std::this_thread::sleep_for(std::chrono::duration<double>(randDelay(ranGen)));
    }
    Movement::rightMouseRelease();
}

void Script::dropShotSemi(int shots) {
    Movement::prone();
    Script::spraySemi(shots);
} // end drop shot

void Script::dropShotAuto(int duration) {
    Movement::prone();
    Script::sprayAuto(duration);
} // end drop shot



void Script::runAndJump(int duration, int sprint, bool slide) {
    Movement::move(duration, "forward", "none", sprint, slide);
    Movement::jump();
}

void Script::randomScript() {
    ;
}

// TODO: MOVE THESE TO Presets.cpp
void Script::commonSoldier() {
    Movement::move(1, "forward", "none", 2, true);
    Script::spraySemi(3);
    Movement::skipKillcam();
    Movement::move(1, "forward", "none", 2, true);
    Movement::skipKillcam();
    Script::spraySemi(3);
    Movement::move(1, "forward", "none", 2, true, true);
    Movement::skipKillcam();
    Movement::move(1, "forward", "none", 2, true);
    Movement::skipKillcam();
    Script::dropShotAuto(3);
    Movement::skipKillcam();
    Movement::move(3, "forward", "none", 2, true);
    Movement::skipKillcam();
    Movement::rotate(6000, -250, 200, 0);
    Script::spraySemi(3);
    Movement::skipKillcam();
    Script::sprayAuto(1);
    Movement::skipKillcam();
    Movement::move(1, "forward", "right", 2, true);
    Movement::skipKillcam();
    Movement::move(1, "forward", "left", 2, true);
    Movement::skipKillcam();
    Movement::jump();
    Movement::skipKillcam();
    Movement::grenade();
    Movement::skipKillcam();
    Script::sprayAuto(3);
    Movement::skipKillcam();
    Movement::rotate(9000, 0, 200, 1);
    Movement::skipKillcam();
    Movement::rotate(-18000, 0, 100, 1);
    Movement::skipKillcam();
    Movement::move(3, "forward", "none", 2, true);
    Movement::skipKillcam();
    Movement::rotate(-6000, -250, 600, 0);
    Movement::skipKillcam();
    Movement::changeWeapon();
    Movement::skipKillcam();
    Script::dropShotSemi(12);
    Movement::skipKillcam();
    Movement::changeWeapon();
    Movement::skipKillcam();
    Movement::move(2, "forward", "none", 2, true, true);
    Movement::skipKillcam();
    Script::sprayAuto(1);
    Movement::skipKillcam();
}

void Script::crackhead() {
    std::cout << "CRACKHEAD\n";
    Movement::move(1, "forward", "none", 2, true, true);
    Movement::skipKillcam();
    Script::spraySemi(3);
    Movement::rotate(50000, 0, 50, 1);
    Movement::skipKillcam();
    Script::spraySemi(3);
    Movement::skipKillcam();
    Movement::move(1, "forward", "none", 2, true, true);
    Script::spraySemi(3);
    Movement::skipKillcam();
    Movement::rotate(-50000, 0, 150, 1);
    Script::spraySemi(3);
    Movement::skipKillcam();
    Script::spraySemi(3);
    Movement::skipKillcam();
    Movement::move(1, "forward", "none", 2, true, true);
    Script::spraySemi(3);
    Movement::skipKillcam();
    Movement::jump();
    Script::spraySemi(3);
    Movement::skipKillcam();
    Script::spraySemi(3);
    Movement::skipKillcam();
    Movement::rotate(50000, 0, 200, 1);
    Script::spraySemi(3);
    Movement::skipKillcam();
    Script::dropShotAuto(3);
    Movement::skipKillcam();

}

