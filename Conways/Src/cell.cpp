#include "cell.h"

int cell::getXCord()
{
    return xCord;
}

int cell::getYCord()
{
    return yCord;
}

int cell::getPosition()
{
    return position;
}

bool cell::getAlive()
{
    return alive;
}

void cell::setXCord(int x)
{
    xCord = x;
}

void cell::setYCord(int y)
{
    yCord = y;
}

void cell::update(int worldWidth, int worldHeight, cell *cellMap[])
{
    nextAlive = false;

    boarderCheck(worldWidth, worldHeight);

    if(display != '0')
    {
        if(alive)
        {
            nextAlive = deathCheck(worldWidth, cellMap);
        }
        else
        {
            nextAlive = liveCheck(worldWidth, cellMap);
        }
    }
    

}

bool cell::deathCheck(int worldWidth, cell *cellMap[])
{
    int cellCount = 0;
    bool alive = false;


    if(cellMap[(position - 1)]->getAlive() == true)
    {
        cellCount++;
    }

    if(cellMap[(position + 1)]->getAlive() == true)
    {
        cellCount++;
    }

    if(cellMap[(position - (worldWidth + 1))]->getAlive() == true)
    {
        cellCount++;
    }
    
    if(cellMap[(position - (worldWidth))]->getAlive() == true)
    {
        cellCount++;
    }

    if(cellMap[(position - (worldWidth - 1))]->getAlive() == true)
    {
        cellCount++;
    }

    if(cellMap[(position + (worldWidth + 1))]->getAlive() == true)
    {
        cellCount++;
    }

    if(cellMap[(position + (worldWidth))]->getAlive() == true)
    {
        cellCount++;
    }

    if(cellMap[(position + (worldWidth -1))]->getAlive() == true)
    {
        cellCount++;
    }

    if(cellCount == 2 || cellCount == 3)
    {
        alive = true;
    }

    return alive;
}

bool cell::liveCheck(int worldWidth, cell *cellMap[])
{
    int cellCount = 0;
    bool live = false;

    if(cellMap[(position - 1)]->getAlive() == true)
    {
        cellCount++;
    }

    if(cellMap[(position + 1)]->getAlive() == true)
    {
        cellCount++;
    }

    if(cellMap[(position - (worldWidth + 1))]->getAlive() == true)
    {
        cellCount++;
    }
    
    if(cellMap[(position - (worldWidth))]->getAlive() == true)
    {
        cellCount++;
    }

    if(cellMap[(position - (worldWidth - 1))]->getAlive() == true)
    {
        cellCount++;
    }

    if(cellMap[(position + (worldWidth + 1))]->getAlive() == true)
    {
        cellCount++;
    }

    if(cellMap[(position + (worldWidth))]->getAlive() == true)
    {
        cellCount++;
    }

    if(cellMap[(position + (worldWidth -1))]->getAlive() == true)
    {
        cellCount++;
    }

    if(cellCount == 3)
    {
        live = true;
    }

    return live;

}

void cell::setDisplay()
{
    if(alive)
    {
        display = LIVEDIS;
    }
    else
    {
        display = DEADDIS;
    }
}

void cell::initialization(int x, int y, int worldWidth)
{
    xCord = x;
    yCord = y;
    position = (xCord + (yCord * worldWidth));
    alive = false;
    setDisplay();
}

void cell::create(int x, int y, int worldWidth)
{
    alive = true;
    setDisplay();
}

void cell::boarderCheck(int worldWidth, int worldHeight)
{
    if((yCord == (worldHeight - 1)) || (yCord == 0) || (xCord == 0) || (xCord == (worldWidth - 1)))
    {
        display = '0';
    }
}

char cell::getDisplay()
{
    return display;
}

void cell::updateAlive(int worldWidth, int worldHeight)
{
    alive = nextAlive;

    setDisplay();

    boarderCheck(worldWidth, worldHeight);
}