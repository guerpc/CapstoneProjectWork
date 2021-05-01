#pragma once
#include<iostream>
#include<vector>
#include <fstream>
#include "Team.h"

using namespace std;
class Game
{
private:
	int gameID;
protected:
	vector<Team> teams;
public:
	void setGameID(int gID);
	void setTeams(vector<Team> teamSetter);
	int getGameID();
	vector<Team> getTeams();
	string toString();
	Game();
};

