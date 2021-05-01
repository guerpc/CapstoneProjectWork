#include "Player.h"

//player's getter/setters below
void Player::setFirstName(string fNam)//sets name
{
	firstName = fNam;
}

void Player::setLastName(string lNam)//sets name
{
	lastName = lNam;
}

void Player::setPlayerID(int pID)
{
	playerID = pID;
}

void Player::setTeamID(int tID)
{
	teamID = tID;
}

string Player::getFirstName()
{
	return firstName;
}

string Player::getLastName()
{
	return lastName;
}

int Player::getPlayerID()
{
	return playerID;
}

int Player::getTeamID()
{
	return teamID;
}

//default constructor for a player
Player::Player()
{
	firstName = "NoFirstName";
	lastName = "NoLastName";
	playerID = 0;
	teamID = 0;
}

//prints a players data to screen
string Player::toString()
{
	//maybe user buffer here?
	string returnPlayerInfo = "Name: " + this->getFirstName() + " " + this->getLastName() + "\n"
		+ "Player ID: " + to_string(playerID) + "\n"
		+ "Team ID: " + to_string(teamID) + "\n";
	return  returnPlayerInfo;
}