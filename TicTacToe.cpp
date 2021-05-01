#include "TicTacToe.h"
#include "Game.h"
#include<iostream>
#include<string>
using namespace std;
void ticTacToe::setMark(string setMark)
{
    teamMark = setMark;
}

string ticTacToe::getMark()
{
    return teamMark;
}
///////////mark = X or O 
///////////need a function to switch between players 
////////// thinking instead of just switching symbols after every turm like last code, we assign each team a symbol and swap teams, very "pick Team 1(x) or Team 2(O)" type vibes

///////////team win
void ticTacToe::setWin(string toWin)
{
    win = toWin;
}

string ticTacToe::getWin()
{
    return win;
}


void ticTacToe::setInput(int TheInput)
{
    input = TheInput;
}

int ticTacToe::getInput()
{
    return input;
}

void ticTacToe::setTeam(int TheTeam)
{
    team = TheTeam;
}

int ticTacToe::getTeam()
{
    return team;
}

void ticTacToe::toWin()
{
    //add code
}
////////// need to set win condtion as per the vectors 
////////// "if teamMark holds x place in vector 1 and x place in vector 2 and x place in vector 3 = win" type vibes    


/////Gameboard

void ticTacToe::setBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}


void ticTacToe::PlayInput()
{
    int input;
    cout << "Enter the number of the field: ";
    cin >> input; // x or o]
    if (input == 1)
    {
        board[0][0] = teamMark;
    }
    else if (input == 2)
    {
        board[0][1] = teamMark;
    }
    else if (input == 3)
    {
        board[0][2] = teamMark;
    }
    else if (input == 4)
    {
        board[1][0] = teamMark;
    }
    else if (input == 5)
    {
        board[1][1] = teamMark;
    }
    else if (input == 6)
    {
        board[1][2] = teamMark;
    }
    else if (input == 7)
    {
        board[2][0] = teamMark;
    }
    else if (input == 8)
    {
        board[2][1] = teamMark;
    }
    else if (input == 9)
    {
        board[2][2] = teamMark;
    }

}

///////////need help getting the teamMark to appear on the board

void ticTacToe::TogglePlayer(vector<Team>loadingTeams) {
    if (teamMark == "X") {
        teamMark = "O";
        cout << loadingTeams.at(1).toString();
    }
    else {
        teamMark = "X";
        cout << loadingTeams.at(0).toString();

    }
}

string ticTacToe::TheRowCondition() {
    //Player 1
    if (board[0][0] == "X" && board[0][1] == "X" && board[0][2] == "X") {
        return "X";
    }
    if (board[1][0] == "X" && board[1][1] == "X" && board[1][2] == "X") {
        return "X";
    }
    if (board[2][0] == "X" && board[2][1] == "X" && board[2][2] == "X") {
        return "X";
    }

    if (board[0][0] == "X" && board[1][0] == "X" && board[2][0] == "X") {
        return "X";
    }
    if (board[0][1] == "X" && board[1][1] == "X" && board[2][1] == "X") {
        return "X";
    }
    if (board[0][2] == "X" && board[1][2] == "X" && board[2][2] == "X") {
        return "X";
    }

    if (board[0][0] == "X" && board[1][1] == "X" && board[2][2] == "X") {
        return "X";
    }
    if (board[2][0] == "X" && board[1][1] == "X" && board[0][2] == "X") {
        return "X";
    }
    if (board[0][0] == "O" && board[0][1] == "O" && board[0][2] == "O") {
        return "O";
    }
    if (board[1][0] == "O" && board[1][1] == "O" && board[1][2] == "O") {
        return "O";
    }
    if (board[2][0] == "O" && board[2][1] == "O" && board[2][2] == "O") {
        return "O";
    }

    if (board[0][0] == "O" && board[1][0] == "O" && board[2][0] == "O") {
        return "O";
    }
    if (board[0][1] == "O" && board[1][1] == "O" && board[2][1] == "O") {
        return "O";
    }
    if (board[0][2] == "O" && board[1][2] == "O" && board[2][2] == "O") {
        return "O";
    }

    if (board[0][0] == "O" && board[1][1] == "O" && board[2][2] == "O") {
        return "O";
    }
    if (board[2][0] == "O" && board[1][1] == "O" && board[0][2] == "O") {
        return "O";
    }
    return "/";
}





void ticTacToe::runTicTacToe(vector<Team>loadingTeams) {
    int team;
    cout << "Welcome to Tic-Tac-Toe!!" << endl;
    system("CLS");
    while (1) {
        setBoard();
        cout << "Board constructed..." << endl;
        PlayInput();
        TogglePlayer(loadingTeams);
        if (TheRowCondition() == "X") {
            cout << "X wins!";
            cout << loadingTeams.at(0).toString();
            break;
        }
        else if (TheRowCondition() == "O") {
            cout << "O wins!";
            cout << loadingTeams.at(1).toString();
            break;
        }
        // setMove();//needs arguments to pass, its a setter

         //win condition
         // call this in the main 
    }
}
///////////// need help with syntax and overall setup of functions and vectors to make the board. 

ticTacToe::ticTacToe()
{
    teamMark = "X";
    win = "noWin";
    input = 0;
    team = 1;
}
