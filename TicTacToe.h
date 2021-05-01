#pragma once
//#include "Game.h"
#include <iostream>
#include <vector>
using namespace std;

class ticTacToe //: public Game
{


private:
    string teamMark;
    string win;
    string board[3][3] =
    {
      {"1","2","3"},
      {"4","5","6"},
      {"7","8","9"},
    };
    int input;
    int team;





public:
    void setMark(string setMark);
    string getMark();

    void setWin(string toWin);
    string getWin();

    //dont forget all of your getter/setters
    void setInput(int TheInput);
    int getInput();

    void setTeam(int TheTeam);
    int getTeam();
    string TheRowCondition();
    void toWin();
    void setBoard();
    void TogglePlayer();
    void runTicTacToe();
    void PlayInput();
    ticTacToe();

    void printShow();
};