#include "raylib.h"
#include <iostream>

int main()
{
    // Window and game variables
    int windowWidth = 800;
    int windowHeight = 450;
    int circleRadius;
    int circleX = 400;
    int circleY = 225;
    int axeLength;
    int axeX = 300;
    int axeY = 225;
    int direction = 10;
    bool collisionWithAxe = false;

    std::cout << "Enter Radius of the circle" << std::endl;
    std::cin >> circleRadius;
    if (circleRadius < 0) circleRadius = 25;

    std::cout << "Enter length of the rectangle" << std::endl;
    std::cin >> axeLength;
    if (axeLength < 0) axeLength = 50;

    InitWindow(windowWidth, windowHeight, "Dodge the Axe!");
    SetTargetFPS(60);

    double immunityStart = GetTime();
    bool immune = true;

    while (!WindowShouldClose())
    {
        // Handle immunity for first 2 seconds
        if (immune && (GetTime() - immunityStart >= 2.0))
        {
            immune = false;
        }

        // Move axe horizontally
        if (axeX + axeLength >= windowWidth || axeX <= 0) direction = -direction;
        axeX += direction;

        // Move circle up/down if no collision
        if (!collisionWithAxe)
        {
            if (IsKeyDown(KEY_W) && circleY - circleRadius > 0) circleY -= 10;
            if (IsKeyDown(KEY_S) && circleY + circleRadius < windowHeight) circleY += 10;
        }

        // Calculate edges for collision detection
        int lAxeX = axeX;
        int rAxeX = axeX + axeLength;
        int uAxeY = axeY;
        int bAxeY = axeY + axeLength;

        int lCircleX = circleX - circleRadius;
        int rCircleX = circleX + circleRadius;
        int uCircleY = circleY - circleRadius;
        int bCircleY = circleY + circleRadius;

        // Collision detection (AABB) with immunity
        if (!immune)
        {
            collisionWithAxe =
                rAxeX >= lCircleX &&
                lAxeX <= rCircleX &&
                bAxeY >= uCircleY &&
                uAxeY <= bCircleY;
        }
        else
        {
            collisionWithAxe = false;
        }

        BeginDrawing();
        ClearBackground(WHITE);

        if (collisionWithAxe)
        {
            DrawText("GAME OVER!", 320, 200, 40, RED);
            EndDrawing();
            WaitTime(1.0);
            break;
        }
        else
        {
            DrawCircle(circleX, circleY, circleRadius, VIOLET);
            DrawRectangle(axeX, axeY, axeLength, axeLength, GREEN);
            if (immune)
            {
                DrawText("IMMUNE!", 350, 20, 30, BLUE);
            }
        }

        EndDrawing();
    }

    CloseWindow();
}