#pragma once
#include<iostream>
#include <string>

using namespace std;

void GamesSubMenu();
void ShowMenu();
void teamsMenu();
void createTeam();
void loadDataBase(vector<Team>& teamsOneTwo);
void writeTeamsToFile(int& choice);
void showTeams();
void runHangMan();
void pressOneToContinue();
void pickTeamsAndPlayers(vector<Team>& teamsOneTwo);
void runningTicTacToe();

//void programHolder();//unused