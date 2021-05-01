#pragma once
#include <ios>
#include <vector>
#include "Player.h"

using namespace std;


class Team
{
private:
    int teamID;
    vector<Player> players;
    int totalScore;

public:
    void setTeamID(int tID);
    void setPlayers(vector<Player> setPlayers);
    void setScore(int num);
    int getScore();
    int getTeamID();
    vector<Player> getPlayers();
    Team();
    string toString();

};

