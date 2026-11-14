#include "path02.h"
#include <iostream>
#include <raylib.h>
#include <vector>

#include "rcamera.h"
#include "../../Controller/controller.h"

void runWindow02() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);

    Controller controller;
    float fov = 45.0f;
    Camera3D camera = {0};
    camera.up = {0, 1.0, 0.0};
    camera.fovy = { fov };
    camera.projection = CAMERA_PERSPECTIVE;
    camera.position = {0.0, 5.0, 5.0};
    camera.target = {0, 0, 0};

    controller.initKeyBindings(KEY_A, []() {std::cout << "A" << std::endl;}, Controller::ModNone);
    controller.initKeyBindings(KEY_A, []() {std::cout << "SHIFT + A" << std::endl;}, Controller::ModShift);

    InitWindow(800, 600, "Raylib C++ Example");


    while (!WindowShouldClose()) {

        controller.scanKeyBindings();
        if (IsKeyDown(KEY_RIGHT)) {
            auto spd = 2.0f * GetFrameTime();
            CameraYaw(&camera, spd, true);
        }
        if (IsKeyDown(KEY_LEFT)) {
            auto spd = 2.0f * GetFrameTime();
            CameraYaw(&camera, -spd, true);
        }


        BeginDrawing();
        ClearBackground(BLACK);

        BeginMode3D(camera);

        DrawGrid(50, 1.0f);

        EndMode3D();

        EndDrawing();
    }

    CloseWindow();
}
