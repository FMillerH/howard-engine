#include "path02.h"
#include <iostream>
#include <raylib.h>
#include <vector>

#include "../../ImportedUI/ToolsUI00/DefaultUI/defaultUI.h"
#include "BouncingSquare/Assets/player.h"
#include "BouncingSquare/Assets/map.h"


class Menu;

void runWindow02() {

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);

    InitWindow(800, 600, "Raylib C++ Example");
    float x = 3.0;
    float y = 4.0;
    float z = 4.0;

    float theta = 0.0f;

    Camera3D camera = { 0 };
    camera.position = (Vector3){ x*cos(theta), y, z*sin(theta) }; // position in the xyz plane
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f }; // position toward which camera is pointed
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;


    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(BLACK);

        BeginMode3D(camera);

        DrawCube((Vector3){ .x = 0.0f, .y = 0.0f, .z = 0.0f }, 2.0f, 2.0f, 2.0f, RED);
        DrawCubeWires((Vector3){ .x = 0.0f, .y = 0.0f, .z = 0.0f }, 2.0f, 2.0f, 2.0f, MAROON);

        DrawLine3D({.x = -100.0f, .y = 0.0f, .z = 0.0f}, {.x = 100.0f, .y = 0.0f, .z = 0.0f },  RED);
        DrawLine3D({.x = 0.0f, .y = -100.0f, .z = 0.0f}, {.x = 0.0f, .y = 100.0f, .z = 0.0f },  RED);
        DrawLine3D({.x = 0.0f, .y = 0.0f, .z = -100.0f}, {.x = 0.0f, .y = 0.0f, .z = 100.0f },  RED);



        EndMode3D();



        EndDrawing();
    }

    CloseWindow();
}
