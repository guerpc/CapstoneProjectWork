#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include "Game.h"
#pragma once
using namespace std;
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
////Class name: Hangman
////Purpose: fully functioning game of Hangman that makes user guess one word letter by letter
////Written by: Kyoshi Noda
///////////////////////////////////////////////////////
////////////////////////////////////////////////////////
class Hangman : public Game
{
private:
    vector<string>words;
    string answer;
public:
    void setWords(vector<string> wordList);
    vector <string> getWords();
    string getRandomWords();
    void printHangman(int current);
    bool runHangMan(string test);
    void teamRunning(vector <Team> allTeamsHolder);
};
