
#include "Presets.h"

#include <iostream>

#include "Movement.h"
#include "Script.h"
#include "State.h"

void Presets::commonSoldier() {
    std::cout << "Starting Common Soldier.\n";
    State::checkState();
    Movement::move(1, "forward", "none", 2, true);
    Movement::rotate(-12000, -750, 200, 0);
    Script::spraySemi(3);
    Movement::skipKillcam();

    State::checkState();
    Script::lookEyeLevel();
    Movement::move(1, "forward", "none", 2, true);
    Movement::rotate(-8000, 200, 200, 0);
    Movement::skipKillcam();

    State::checkState();
    Script::spraySemi(3);
    Script::lookEyeLevel();
    Movement::move(1, "forward", "none", 2, true, true);
    Movement::skipKillcam();

    State::checkState();
    Movement::move(1, "forward", "none", 2, true);
    Movement::rotate(-16000, -150, 200, 0);
    Movement::skipKillcam();

    State::checkState();
    Script::dropShotAuto(3);
    Movement::skipKillcam();

    State::checkState();
    Movement::move(3, "forward", "none", 2, true);
    Movement::rotate(24000, 50, 200, 0);
    Movement::skipKillcam();

    State::checkState();
    Movement::rotate(-2000, -350, 200, 0);
    Script::spraySemi(3);
    Movement::skipKillcam();

    State::checkState();
    Script::sprayAuto(1);
    Script::lookEyeLevel();
    Movement::rotate(300, 0, 200, 0);
    Movement::skipKillcam();

    State::checkState();
    Movement::move(1, "forward", "right", 2, true);
    Movement::skipKillcam();

    State::checkState();
    Movement::move(1, "forward", "left", 2, true);
    Movement::rotate(30000, 0, 200, 0);
    Movement::skipKillcam();

    State::checkState();
    Movement::jump();
    Script::lookEyeLevel();
    Movement::skipKillcam();

    State::checkState();
    Movement::grenade();
    Movement::rotate(0, -8000, 225, 0);

    Script::lookEyeLevel();
    Movement::skipKillcam();

    State::checkState();
    Script::sprayAuto(3);
    Script::lookEyeLevel();
    Movement::skipKillcam();

    State::checkState();
    Movement::rotate(9000, 0, 200, 1);
    Script::lookEyeLevel();
    Movement::skipKillcam();

    State::checkState();
    Movement::rotate(-18000, 0, 100, 1);
    Movement::skipKillcam();

    State::checkState();
    Movement::move(3, "forward", "none", 2, true);
    Movement::skipKillcam();

    State::checkState();
    Movement::rotate(-6000, -250, 600, 0);
    Movement::skipKillcam();

    State::checkState();
    Movement::changeWeapon();
    Script::lookEyeLevel();
    Movement::skipKillcam();

    State::checkState();
    Script::dropShotSemi(12);
    Movement::skipKillcam();

    State::checkState();
    Movement::changeWeapon();
    Movement::skipKillcam();

    State::checkState();
    Movement::move(2, "forward", "none", 2, true, true);
    Movement::skipKillcam();

    State::checkState();
    Script::sprayAuto(1);
    Movement::skipKillcam();

}

void Presets::crackhead() {
    std::cout << "CRACKHEAD RELEASED\n";
    State::checkState();
    Movement::move(1, "forward", "none", 2, true, true);
    Movement::skipKillcam();

    State::checkState();
    Script::spraySemi(3);
    Movement::rotate(50000, 0, 50, 1);
    Movement::skipKillcam();

    State::checkState();
    Script::spraySemi(3);
    Movement::skipKillcam();

    State::checkState();
    Movement::move(1, "forward", "none", 2, true, true);
    Script::spraySemi(3);
    Movement::skipKillcam();

    State::checkState();
    Movement::rotate(-50000, 0, 150, 1);
    Script::spraySemi(3);
    Movement::skipKillcam();

    State::checkState();
    Script::spraySemi(3);
    Movement::skipKillcam();

    State::checkState();
    Movement::move(1, "forward", "none", 2, true, true);
    Script::spraySemi(3);
    Movement::skipKillcam();

    State::checkState();
    Movement::jump();
    Script::spraySemi(3);
    Movement::skipKillcam();

    State::checkState();
    Script::spraySemi(3);
    Movement::skipKillcam();

    State::checkState();
    Movement::rotate(50000, 0, 200, 1);
    Script::spraySemi(3);
    Movement::skipKillcam();

    State::checkState();
    Script::dropShotAuto(3);
    Movement::skipKillcam();
}

void Presets::randomScripts() {
    //TODO: Add All Moves & Scripts to Array and randomly choose
    ;
}

