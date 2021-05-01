#pragma once
#include<iostream>
#include <string>

using namespace std;
class Player
{

private:
	string firstName, lastName;
	int playerID, teamID;

public:
	void setFirstName(string fNam);
	void setLastName(string lNam);

	void setPlayerID(int pID);
	void setTeamID(int tID);

	string getFirstName();
	string getLastName();

	int getPlayerID();
	int getTeamID();

	Player();

	string toString();

};

