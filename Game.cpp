#include "Game.h"

//getters and setters for Game's Properties
void Game::setGameID(int gID)
{
	gameID = gID;
}

void Game::setTeams(vector<Team> teamSetter)
{
	teams = teamSetter;
}

int Game::getGameID()
{
	return gameID;
}

vector<Team> Game::getTeams()
{
	return teams;
}

//default constructor for game
Game::Game()
{
	gameID = 0;
}

//toString or pritning gameID property to screen
string Game::toString()
{
	string result = to_string(gameID);
	return result;
}