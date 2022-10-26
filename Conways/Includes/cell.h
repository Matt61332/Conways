#pragma once

class cell
{
private:

    static const char LIVEDIS = 'O';
    static const char DEADDIS = ' ';

    int xCord;
    int yCord;
    int position;
    bool alive;
    bool nextAlive;
    char display;

    

public:
    int getXCord();
    int getYCord();
    int getPosition();
    bool getAlive();

    void setXCord(int x);
    void setYCord(int y);

    void update(int worldWidth, int worldHeight, cell *cellMap[]);

    bool deathCheck(int worldWidth, cell *cellMap[]);

    bool liveCheck(int worldWidth, cell *cellMap[]);

    void setDisplay();

    void initialization(int x, int y, int worldWidth);

    void create(int x, int y, int worldWidth);

    void boarderCheck(int worldWidth, int worldHeight);

    char getDisplay();

    void updateAlive(int worldWidth, int worldHeight);
};