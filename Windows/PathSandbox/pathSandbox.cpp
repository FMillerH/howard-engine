#include "pathSandbox.h"

#include <iostream>

#include "raylib.h"
#include <string>

#include "../../Application/application.h"
#include "../../Controller/controller.h"
#include "../../Example/exampleGame2D.h"

void runSandboxPath() {

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);

    InitWindow(800, 600, "Raylib + C++ Example");

    std::unique_ptr<Application> app = std::make_unique<Application>();

    while (!WindowShouldClose()) {

        app->update();





        BeginDrawing();
        ClearBackground(BLACK);

        app->draw();



        EndDrawing();
    }

    CloseWindow();
}
