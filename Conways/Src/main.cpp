#include <iostream>
#include <time.h>  
#include <stdlib.h>
#include <ctime>
#include <thread>
#include <chrono>
#include "cell.h"
using namespace std;
using namespace std::chrono_literals;

void mapUpdate(int mapWidth, int mapHeight, cell *cellMap[]);

void userInput(cell *cellMap[], int mapWidth);

void randomMap(int mapWidth, int mapHeight, cell *cellMap[]);

int main(int argCount, char *arg[])
{
    int mapWidth = 50;
    int mapHeight = 50;
    int mapTotal = mapWidth * mapHeight;

    cell *cellMap[mapTotal];

    if(argCount == 1)
    {
        srand(time(NULL)); 
    }
    if(argCount == 2)
    {
        // srand(atoi(arg[1]));
        srand((int)*(int*)arg[1]);
    }

    for(int loop = 0; loop < mapTotal; loop++)
    {
        cellMap[loop] = new cell;
    }

    for(int loopY = 0; loopY < mapHeight; loopY++)
    {
        for(int loopX = 0; loopX < mapWidth; loopX++)
        {
            cellMap[(loopX + (loopY * mapHeight))]->initialization(loopX,loopY, mapWidth);
        }
    }


    for(int loop = 0; loop < mapTotal; loop++)
    {
        cellMap[loop]->boarderCheck(mapWidth, mapHeight);
    }

    // userInput(cellMap, mapWidth);
    randomMap(mapWidth, mapHeight, cellMap);

    char input = 'x';

    while(input == 'x')
    {

        mapUpdate(mapWidth, mapHeight, cellMap);

        // cout << "'x' TO CONTINUE... " << endl;
        // cin.get(input);
        // cin.ignore(100, '\n');

        for(int loop = 0; loop < mapTotal; loop++)
        {
            cellMap[loop]->update(mapWidth, mapHeight, cellMap);
        }

        for(int loop = 0; loop < mapTotal; loop++)
        {
            cellMap[loop]->updateAlive(mapWidth, mapHeight);
        }

        std::this_thread::sleep_for(100ms);

    }
}

void userInput(cell *cellMap[], int mapWidth)
{
    int inputX;
    int inputY;

    while(inputX > -1)
    {
        cout << "Enter cell X cord: ";
        cin >> inputX;
        cin.ignore(100, '\n');

        if(inputX > -1)
        {
            cout << "Enter cell Y cord: ";
            cin >> inputY;
            cin.ignore(100, '\n');

            if(inputY > -1)
            {
                cellMap[(inputX + (inputY * mapWidth))]->create(inputX, inputY, mapWidth);
            }
        }
    
 

    }
}

void mapUpdate(int mapWidth, int mapHeight, cell *cellMap[])
{

    for(int loopY = 0; loopY < mapWidth; loopY++)
    {
        for(int loopX = 0; loopX < mapWidth; loopX++)
        {
            cout << " " << cellMap[(loopX + (loopY * mapHeight))]->getDisplay();
        }
        cout << endl;

    }
}

void randomMap(int mapWidth, int mapHeight, cell *cellMap[])
{
    int inputX;
    int inputY;

    for(int loop = 0; loop < mapHeight * mapWidth /2; loop++)
    {
        inputX = rand() % mapWidth;
        inputY = rand() % mapHeight;

        if(cellMap[(inputX + (inputY * mapWidth))]->getAlive() == false)
        {
            cellMap[(inputX + (inputY * mapWidth))]->create(inputX, inputY, mapWidth);
        }
        else
        {
            loop--;
        }
    }
}
