#include "raylib.h"
#include <iostream>

int main()
{
   //variables for, circle and rectangle
    int windowWidth = 800;
    int windowHeight = 450;
    int circleRadius;
    int circleX = 400;
     int circleY = 225;
     //variables for rectangle
     int axeLength;
    int axeX = 300;
    int axeY = 225;
    //axe edges
    int lAxeX = axeX;
    int rAxeX = axeX + axeLength;
    int uAxeY = axeY;
    int bAxeY = axeY + axeLength;
    //direction of the rectangle
    int direction = 10;
    //circle edges
    int lCirclex=circleX - circleRadius;
    int rCirclex=circleX + circleRadius;
    int uCircleY=circleY - circleRadius;
    int bCircleY=circleY + circleRadius;
    //boolean for collision
    bool collisionWithAxe = false;


    std::cout << "Enter Radius of the circle" << std::endl;
    std::cin >> circleRadius;
    if (circleRadius < 0) circleRadius = 25;

    std::cout << "Enter length of the rectangle" << std::endl;
    std::cin >> axeLength;
    if (axeLength < 0) axeLength = 50;

    InitWindow(windowWidth, windowHeight, "go on then");

   

    SetTargetFPS(60); // Set the game to run at 60 frames-per-second

    while (WindowShouldClose() == false)
    {
         BeginDrawing();
        ClearBackground(WHITE);

        if (collisionWithAxe==false)
            {
              DrawText("GAME OVER!", 400, 200, 20, RED);  
            }
            else{
       
        DrawCircle(circleX, circleY, circleRadius, VIOLET);
        DrawRectangle(axeX, axeY, axeLength, axeLength, GREEN);


        if (axeX + axeLength >= windowWidth || axeX <= 0) direction = -direction;
        axeX += direction;

        if (IsKeyDown(KEY_D) && circleX < windowWidth) circleX += 10;
        if (IsKeyDown(KEY_A) && circleX > 0) circleX -= 10;
        if (IsKeyDown(KEY_W) && circleY > 0) circleY -= 10;
        if (IsKeyDown(KEY_S) && circleY < windowHeight) circleY += 10;
       
            
        }
        EndDrawing();
    }
    }

