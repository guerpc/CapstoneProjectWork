#include "Team.h"
#include "Player.h"

//team getter/setters below
void Team::setScore(int num)
{
    totalScore = num;
}
int Team::getScore()
{
    return totalScore;
}
void Team::setTeamID(int tID)
{
    teamID = tID;
}
void Team::setPlayers(vector<Player> setPlayers)
{
    players = setPlayers;
}

int Team::getTeamID()
{
    return teamID;
}
vector<Player> Team::getPlayers()
{
    return players;
}
//team default constructor
Team::Team()
{
    totalScore = 0;
    teamID = 0;
}
//for pritning teamm's players, ID, and Size to screen by string
string Team::toString()
{
    string printTeams, printPlayers;
    int playersSize = this->getPlayers().size();
    for (int i = 0; i < playersSize; i++)
    {
        printPlayers += getPlayers().at(i).toString() + "\n";
    }
    printTeams = "Team ID:" + to_string(teamID) + "\n" +
        "Team Size: " + to_string(playersSize) + "\n" +
        printPlayers;

    return printTeams;
}

