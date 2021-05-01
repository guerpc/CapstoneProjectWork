#include"Player.h"
#include"Game.h"
#include"Functions.h"
#include"Hangman.h"
#include"TicTacToe.h"
#include<fstream>
#include<string>


/// ############################################
/// Method: GamesSubMenu
/// Description: launches the program's games. 
/// ############################################
void GamesSubMenu()
{
    system("CLS");

    int subChoice;

    cout << "1. Hangman" << endl;
    cout << "2. Tic Tac Toe" << endl;
    cout << "3. Return to main menu" << endl;

    cin >> subChoice;

    switch (subChoice)
    {
    case 1:
        system("CLS");
        cout << "case 1" << endl;
        cout << "Hangman" << endl;
        runHangMan();
        break;
    case 2:
        system("CLS");
        cout << "case 2" << endl;
        cout << "Tic Tac Toe" << endl;       
        runningTicTacToe();
        break;
    case 3:
        system("CLS");
        cout << "case 3" << endl;
        cout << "Return to main menu" << endl;
        ShowMenu();
        break;
    default:
        system("CLS");
        cout << "default" << endl;
        break;
    }
}

/// ############################################
/// Method: ShowMenu
/// Description: launches the program's main menu. 
/// ############################################
void ShowMenu()
{
    int choice;

    cout << "1. Teams Menu" << endl;
    cout << "2. Games Menu" << endl;
    cout << "3. Exit" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "case 1" << endl;
        system("CLS");
        teamsMenu();
            break;
    case 2:
        cout << "case 3" << endl;
        cout << "Game Menu" << endl;
        system("CLS");
        GamesSubMenu();
        break;
    case 3:
        cout << "case 4" << endl;
        system("CLS");
        break;
    default:
        cout << "default" << endl;
        system("CLS");
        break;
    }
}

/// ############################################
/// Method: createTeam
/// Description: Creates a new instance of team,
///     then allows the user to input team data       
/// ############################################
void createTeam()
{
    int howManyPlayers;
    Team newTeam;
    string playerName;
    Player newPlayer;
    vector<Player> newPlayers;
    cout << "Please select how many players will be on this team." << endl;
    cin >> howManyPlayers;
    for (int i = 0; i < howManyPlayers; i++)
    {
        cin >> playerName;
        newPlayer.setFirstName(playerName);
        newPlayers.push_back(newPlayer);
        newTeam.setPlayers(newPlayers);
    }
    //cout << newTeam.toString();//testing lines
}

/// ############################################
/// Method: loadDataBase
/// Description: Takes a list of teams, then
/// fills that list with teams, that are filled
/// with players, found line by line in a text file.
/// Example File
/// (1,phil,guerrero)(2,test,lname)
/// (1, mike, Heey)(2, Faee, Naaae)(3, test, TTTTT)  
/// ############################################
void loadDataBase(vector<Team>& teamsOneTwo)
{

    //file i/o stuff
    fstream teamFile;
    fstream printTeamsFile;
    teamFile.open("teams.txt");
    vector<Player> loadTeamPlayers;
    vector<Team> loadTeams;

    //temp holders
    //holds temporary variables
    Team tempTeam;
    Player tempPlayer;
    vector<Player> loadPlayers;
    string getFirst, getLast, fileLine, playerString, stringTemp, stringPID;
    int commaIndex, secondCommaIndex, leftParen, rightParen;
    //team
    int getTID = tempTeam.getTeamID();
    int getSize = tempTeam.getTeamID();
    //Player 
    string setFirst;
    string setLast;
    int setPID;
    //   example file
    //   (1,phil,guerrero)(2,test,lname)
    //   (1,mike,Heey)(2,Faee,Naaae)(3,test,TTTTT)

    char comma = ',';
    char leftParenthesis = '(';
    char rightParenthesis = ')';
    int i = 0;//teamSize//TeamID      

    if (teamFile.is_open())
    {
        while (getline(teamFile, fileLine))
        {
            string copyFileLine;
            string nextPlayerInLine;

            if (nextPlayerInLine.size() == std::string::npos)
            {
                copyFileLine = nextPlayerInLine;
            }
            else
            {
                //when moving to the next line in fileLine
                //clearing out the old loadPlayers
                loadPlayers.clear();
                copyFileLine = fileLine;
            }

            //copyFileLine = fileLine;
            leftParen = copyFileLine.find(leftParenthesis);
            rightParen = copyFileLine.find(rightParenthesis);

            i++;
            tempTeam.setTeamID(i);//setting team id = to first team in file line

            while (leftParen != std::string::npos)//&& leftParen != std::string::npos
            {
                //pulling player from (playerID,FirstName,LastName)
                //playerString = playerID,FirstName,LastName
                //example: 1,Phil,Guerrero
                playerString = copyFileLine.substr(leftParen + 1, rightParen - 1);

                //get the id from the player
                commaIndex = playerString.find(comma);//first comma
                stringPID = playerString.substr(0, commaIndex);//playerID
                setPID = stoi(stringPID);//converting from string to int
                tempPlayer.setPlayerID(setPID);//setting playerID

                //get the first name of the player
                string snipPID = playerString.substr(commaIndex + 1);
                int secondCommaIndex = snipPID.find(comma);//second comma
                setFirst = playerString.substr(commaIndex + 1, secondCommaIndex);//FirstName
                tempPlayer.setFirstName(setFirst);

                //get the last name of the player            
                setLast = snipPID.substr(secondCommaIndex + 1, playerString.length());//LastName 
                tempPlayer.setLastName(setLast);
                tempPlayer.setTeamID(i);
                loadPlayers.push_back(tempPlayer);

                // finding the next player between ( )            
                stringTemp = copyFileLine.substr(leftParen, rightParen + 1);
                nextPlayerInLine = copyFileLine.substr(stringTemp.size(), copyFileLine.size());
                leftParen = nextPlayerInLine.find(leftParenthesis); //0
                rightParen = nextPlayerInLine.find(rightParenthesis); //13  

                //overwriting copyFileLine, removing the current temp player from the string
                copyFileLine = nextPlayerInLine;
            }
            //loading players into current team
            tempTeam.setPlayers(loadPlayers);
            //cout << tempTeam.toString();
            //adding current team to the list of teams
            loadTeams.push_back(tempTeam);

            teamsOneTwo = loadTeams;
        }
        // cout << "out while loop" << endl;//testing line
    }
    teamFile.close();
    // cout << "out while loop" << endl;//testing line
    // cout << loadTeam.toString();//testing line

}

/// ############################################
/// Method: pickTeamsAndPlayers
/// DescriptioN: Lets the user fill teamOne and TeamTwo
/// with players, and stores both teams into a list of
/// teams, at 0 and 1, then passes it back into
/// a list of teams passed into this function.
/// ############################################
void pickTeamsAndPlayers(vector<Team>& teamsOneTwo)
{
    Team teamOne;
    Team teamTwo;
    vector<Team> tempTeamsList;
    Player tempPlayer;
    string userInput;
    vector<Player> teamPlayers;
    int tempNumPlayers;
    teamOne.setTeamID(1);
    teamTwo.setTeamID(2);

    cout << "How many players are on Team One?: " << endl;
    cin >> tempNumPlayers;
    teamPlayers.resize(tempNumPlayers);
    teamOne.setPlayers(teamPlayers);//set teamOne Size
    for (int i = 1; i <= tempNumPlayers; i++)
    {

        cout << "Please Enter team One Player First Name: " << endl;
        cin >> userInput;
        tempPlayer.setFirstName(userInput);
        cout << "Please Enter team One Player Last Name: " << endl;
        cin >> userInput;
        tempPlayer.setLastName(userInput);
        tempPlayer.setPlayerID(i);
        tempPlayer.setTeamID(1);
        teamPlayers.at(i - 1) = tempPlayer;
    }
    teamOne.setPlayers(teamPlayers);

    cout << teamOne.toString();
    ///////////////////////
    /// Team Two Starts here
    //////////////////////

    cout << "How many players are on Team Two?: " << endl;
    cin >> tempNumPlayers;
    teamPlayers.resize(tempNumPlayers);
    teamTwo.setPlayers(teamPlayers);//set teamTwo Size
    for (int i = 1; i <= tempNumPlayers; i++)
    {

        cout << "Please Enter team One Player First Name: " << endl;
        cin >> userInput;
        tempPlayer.setFirstName(userInput);
        cout << "Please Enter team One Player Last Name: " << endl;
        cin >> userInput;
        tempPlayer.setLastName(userInput);
        tempPlayer.setPlayerID(i);
        tempPlayer.setTeamID(2);
        teamPlayers.at(i - 1) = tempPlayer;
    }
    teamTwo.setPlayers(teamPlayers);

    cout << teamTwo.toString();

    tempTeamsList.push_back(teamOne);
    tempTeamsList.push_back(teamTwo);
    teamsOneTwo = tempTeamsList;
}

/// ############################################
/// Method: runHangMan
/// DescriptioN: Creates an instance of hangman
/// sets the teams for hangman and runs hangman,
/// before returning to the game menu at the end
/// ############################################
void runHangMan()
{
    Player tempPlayer;
    string userInput;
    vector<Player> teamPlayers;
    vector <Team> allTeamsHolder;

    int pick;
    cout << "Enter 1 to pick teams or 2 to load teams." << endl;
    cin >> pick;

    if (pick == 1)
    {
        pickTeamsAndPlayers(allTeamsHolder);

    }
    else if (pick == 2)
    {
        loadDataBase(allTeamsHolder);
    }
    Hangman hangman;
    hangman.setGameID(1);
    hangman.setTeams(allTeamsHolder);
    hangman.teamRunning(allTeamsHolder);
    pressOneToContinue();
    GamesSubMenu();
}

/*unused 
void programHolder()
{
    Team teamOne;
    Team teamTwo;
    vector<Team> tempTeamsList;
    Player tempPlayer;
    string userInput;
    vector<Player> teamPlayers;

}*/


/// ############################################
/// Method: teamsMenu
/// DescriptioN: Displays a menu for creating new teams
/// copying teams from file to new files, and
/// showing the contents of teams in teams.txt,
/// so long as teams.txt follows the correct format
/// ############################################
void teamsMenu()
{
    int subChoice;
    cout << "Are you copying from teams.txt or creating a new list of teams?" << endl;
    cout << "1. Creating a new list of Teams and write to a new file." << endl;
    cout << "2. Copying teams.txt to a new file." << endl;
    cout << "3. Show teams in teams.txt" << endl;
    cout << "4. Return to Main Menu" << endl;

    cin >> subChoice;

    switch (subChoice)
    {
    case 1:
        cout << "case 1" << endl;
        writeTeamsToFile(subChoice);
        teamsMenu();
        break;
    case 2:
        cout << "case 2" << endl;
        writeTeamsToFile(subChoice);
        teamsMenu();
        break;
    case 3:
        cout << "Case 3" << endl;
        showTeams();
        teamsMenu();
        break;
    case 4:
        cout << "case 3" << endl;
        ShowMenu();
        break;
    default:
        cout << "default" << endl;
        break;
    }

}
/// ############################################
/// Method: teamsMenu
/// DescriptioN: Displays a menu for creating new teams
/// copying teams from file to new files, and
/// showing the contents of teams in teams.txt,
/// so long as teams.txt follows the correct format
/// ############################################
void writeTeamsToFile(int& choice)
{
    Team tempTeam;
    vector<Team> tempTeamsList;
    Player tempPlayer;
    string userInput;
    vector<Player> teamPlayers;
    ofstream writeFile;
    string fileName;
 
    cout << "Please enter a name for the file you wish to write your list of teams to." << endl;
    cin >> fileName;

    writeFile.open(fileName);
   
    if (choice == 1)
    {
        pickTeamsAndPlayers(tempTeamsList);
    }
    else if (choice == 2)
    {
        loadDataBase(tempTeamsList);
    }

    for (int i = 0; i < tempTeamsList.size(); i++)
    { 
         tempTeam = tempTeamsList.at(i);
        for (int x = 0; x < tempTeam.getPlayers().size(); x++)
        { 
            teamPlayers = tempTeam.getPlayers(); 

            tempPlayer = teamPlayers.at(x);

            writeFile << "(" << tempPlayer.getPlayerID() << "," << tempPlayer.getFirstName() <<
                "," << tempPlayer.getLastName() << ")";
        }
        writeFile << endl;
    }
    writeFile << endl;

    writeFile.close();

    pressOneToContinue();
    teamsMenu();
}
/// ############################################
/// Method: showTeams
/// DescriptioN: Displays the contest of a list
/// of teams, and shows the players in each position
/// of each team to screen
/// ############################################
void showTeams() 
{
    Team tempTeam;
    vector<Team> tempTeamsList;
    Player tempPlayer;
    vector<Player> teamPlayers;
    system("CLS");
    cout << "Showing teams from teams.txt file: " << endl;
    loadDataBase(tempTeamsList);
    for (int i = 0; i < tempTeamsList.size(); i++)
    {
        tempTeam = tempTeamsList.at(i);
        for (int x = 0; x < tempTeam.getPlayers().size(); x++)
        {
            teamPlayers = tempTeam.getPlayers();

            tempPlayer = teamPlayers.at(x);

        }
        cout << tempTeam.toString();
    }
    pressOneToContinue();
}
/// ############################################
/// Method: pressOneToContinue
/// DescriptioN: a quick function for clearing
/// the current screen before proceeding
/// ############################################
void pressOneToContinue()
{
    string userInput;
    cout << "enter 1 to continue" << endl;
    cin >> userInput;
    while (userInput != "1")
    {
        cout << endl;
        cout << "enter 1 to continue" << endl;
        cin >> userInput;
    }
    system("CLS");
}
/// ############################################
/// Method: runningTicTacToe
/// DescriptioN: runs ticTacToe
/// ############################################
void runningTicTacToe()
{
    ticTacToe t1;
    t1.runTicTacToe();
    pressOneToContinue();
    GamesSubMenu();
}