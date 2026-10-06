#include "path01.h"

#include <iostream>

#include "raylib.h"
#include <string>

#include "../../Controller/controller.h"
#include "../../Example/exampleGame2D.h"

void runWindow01() {

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);

    InitWindow(800, 600, "Raylib + C++ Example");

    ExampleGame2D game2D;

    bool keysHaveMouse = false;
    Vector2 mouse;
    Vector2 keyMouse;

    std::vector<Vector2> coordinates = {{200, 100},{200, 250},{200, 450},{200, 600}};

    Controller controller;
    int index = 0;


    // int list[351];
    // for (int i = 0; i < 95; i++) {
    //     list[i] = 32 + i;
    // }
    // for (int i = 0; i < 256; i++) {
    //     // 1024 is the "start" of the Russian alphabet
    //     list[95 + i] = 1024 + i;
    // }
    //
    // Font font = LoadFontEx("../JetBrainsMono-Light(1).ttf", 128, list, 351);
    // std::string text = "Test Text for Imported Font";
    // Vector2 vec = {100.0f, 100.0f };
    //
    // if (font.texture.id == 0) {
    //     perror("font failed to load\n");
    // }

    // SetTextureFilter(font.texture, TEXTURE_FILTER_BILINEAR);

    while (!WindowShouldClose()) {

        if (IsKeyPressed(KEY_DOWN)) {
            keysHaveMouse = true;
        }

        if (GetMouseDelta().x != 0 || GetMouseDelta().y != 0) {
            keysHaveMouse = false;
        }

        if (IsKeyPressed(KEY_SPACE)) { //these three 'if' conditionals should run the menu input logic.

            std::cout << "keys in control: " << keysHaveMouse << std::boolalpha << std::endl;

            std::cout << "mouse in control: " << !keysHaveMouse << std::boolalpha << std::endl;

        }



        game2D.updateGame2D();

        BeginDrawing();
        ClearBackground(BLACK);

        game2D.drawGame2D();

        //DrawTextEx(font, text.c_str(), vec, 24, 1.0f, WHITE);


        EndDrawing();
    }

    CloseWindow();
}