#include "path02.h"
#include <iostream>
#include <raylib.h>
#include <vector>

#include "../../Controller/controller.h"

void runWindow02() {

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);

    Controller controller;

    controller.initKeyBindings(KEY_A, []() {std::cout << "A" << std::endl;}, Controller::ModNone);
    controller.initKeyBindings(KEY_A, []() {std::cout << "SHIFT + A" << std::endl;}, Controller::ModShift);

    InitWindow(800, 600, "Raylib C++ Example");


    while (!WindowShouldClose()) {

        controller.scanKeyBindings();

        BeginDrawing();
        ClearBackground(BLACK);



        EndDrawing();
    }

    CloseWindow();
}
