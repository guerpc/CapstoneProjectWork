#include "Hangman.h"
#include "Game.h"

void Hangman::printHangman(int current) // prints the current Hangman ACII
{
    switch (current)
    {
    case 0:
        cout << "  +---+  " << endl;
        cout << "  |   |  " << endl;
        cout << "      |  " << endl;
        cout << "      |  " << endl;
        cout << "      |  " << endl;
        cout << "      |  " << endl;
        cout << "=========" << endl;
        break;
    case 1:
        cout << "  +---+  " << endl;
        cout << "  |   |  " << endl;
        cout << "  O   |  " << endl;
        cout << "      |  " << endl;
        cout << "      |  " << endl;
        cout << "      |  " << endl;
        cout << "=========" << endl;
        break;
    case 2:
        cout << "  +---+  " << endl;
        cout << "  |   |  " << endl;
        cout << "  O   |  " << endl;
        cout << "  |   |  " << endl;
        cout << "      |  " << endl;
        cout << "      |  " << endl;
        cout << "=========" << endl;
        break;
    case 3:
        cout << "  +---+  " << endl;
        cout << "  |   |  " << endl;
        cout << "  O   |  " << endl;
        cout << " /|   |  " << endl;
        cout << "      |  " << endl;
        cout << "      |  " << endl;
        cout << "=========" << endl;
        break;
    case 4:
        cout << "  +---+  " << endl;
        cout << "  |   |  " << endl;
        cout << "  O   |  " << endl;
        cout << " /|\\  |  " << endl;
        cout << "      |  " << endl;
        cout << "      |  " << endl;
        cout << "=========" << endl;
        break;
    case 5:
        cout << "  +---+  " << endl;
        cout << "  |   |  " << endl;
        cout << "  O   |  " << endl;
        cout << " /|\\  |  " << endl;
        cout << " /    |  " << endl;
        cout << "      |  " << endl;
        cout << "=========" << endl;
        break;
    case 6:
        cout << "  +---+  " << endl;
        cout << "  |   |  " << endl;
        cout << "  O   |  " << endl;
        cout << " /|\\  |  " << endl;
        cout << " / \\  |  " << endl;
        cout << "      |  " << endl;
        cout << "=========" << endl;
        break;
    }
}
void Hangman::setWords(vector<string> wordList) //reads into text file and sets it equal to the private member words
{
    ifstream textWords;
    textWords.open("Hangman.txt");
    string input;
    if (textWords.is_open())
    {
        while (textWords >> input)
        {
            wordList.push_back(input);
        }
        words = wordList; //setter for words
    }
}

vector <string> Hangman::getWords()
{
    return words;
}

string Hangman::getRandomWords() //gets the answer for each game ran
{
    int index = rand() % words.size();
    answer = words.at(index);
    return answer; //gets the private answer 
}

bool Hangman::runHangMan(string test) //runs each game of hangman (code for hangman (check inside) )
{
    unsigned long wordSize = test.length();
    vector<char> correctWord;
    for (int i = 0; i < wordSize; i++)
    {
        correctWord.push_back(test.at(i)); //this transfers the correctWord found from getRandomWords() into a char vector
    }
    vector<char> lines; //will be used to show the words _ _ _ _ as the program runs each index found will replace the underscore
    for (int i = 0; i < wordSize; i++)
    {
        lines.push_back('_'); //by default it will be only be underscores
    }
    int progress = 0; // keeps track of the displaying of hangman 
    int lives = 6; //how many lives you have left until you lose
    int amtWrongLetters = 0; //used for the word bank/ all the wrong letters chosen
    bool foundWord = false; //sees if the letter is found on the correct word
    bool win = false;
    bool point = false;
    vector <char> wrong; // list of the wrong letters
    cout << endl;
    cout << "Welcome to Hangman!!!" << endl;
    cout << "Currently there are " << teams.size() << " teams" << endl;
    cout << "Are you ready? Press a key to begin." << endl;
    cin.get();
    while (lives >= 0)
    {
        char letter1;
        Hangman::printHangman(progress);
        cout << "Your word has " << wordSize << " letters" << endl;
        cout << "You have " << lives << " lives left!" << endl;
        cout << endl;
        for (int j = 0; j < wordSize; j++) //Intially will be _ _ _ _ but as each letter gets found it will replace each index of the underline like this _ _ _ d _ _ a
        {
            cout << lines.at(j) << " ";
        }
        cout << endl;
        cout << "Word bank: ";
        if (wrong.size() > 0) // will display all wrong letters
        {
            for (int j = 0; j < amtWrongLetters; j++)
            {
                cout << wrong.at(j) << " ";
            }
        }
        else
        {
            cout << "None" << endl; // used for the start of the game where there are no wrong Letters
        }
        cout << endl;
        cout << "Start guessing:";
        if (lines == correctWord) // once all lines were replaced by correctWord the game win end and user wins
        {
            cout << "You win" << endl;
            return true;
        }
        cin >> letter1; //input
        for (int j = 0; j < wordSize; j++)
        {
            if (correctWord.at(j) == letter1) //check each index of the correctWord and see if it matches the user inputed char
            {
                lines.at(j) = correctWord.at(j); //replaces the index of the lines _ _ _ _ to the correct input the user _ _ a _
                foundWord = true; // skips the next if statement
            }
        }

        if (foundWord == false) //if the for loop search doesn't find any index of the correct Word enter here
        {
            for (int j = 0; j < wordSize; j++)
            {
                if (letter1 != correctWord.at(j)) //subtracts lives and add display counter and wrongLetters and pushes that into the wrongLetter vector and breaks
                {
                    cout << "Wrong letter!" << endl;
                    lives--;
                    progress++;
                    wrong.push_back(letter1);
                    amtWrongLetters++;
                    break;
                }
            }
        }
        foundWord = false; // after the while loop interation it will put the foundWord as false each while loop interation
    } // end of while loop

    if (win != true)
    {
        cout << "You lose!" << endl;
        cout << "Thanks for playing!" << endl;
        return false; // this will be used to determine who many wins each team has
    }
    else
    {
        return true; // this will be used to determine who many wins each team has
    }
}

void Hangman::teamRunning(vector <Team> allTeamsHolder) // this is used for the teams playing hangman (multiplayer)
{
    vector<Player> playerList;
    int rounds; // Each round will be done after the both teams played
    int displayRound = 1; //displays current round
    int point = 0; //how many wins/points team 1 has
    int point2 = 0; //how many wins/points team 2 has

    cout << "Welcome to multiplayer Hangman!" << endl;
    cout << "How many rounds would you like to go for?" << endl;
    cout << "(A new round will start after each team plays one game of Hangman)" << endl;
    cin >> rounds;
    cout << "The team with the most rounds won wins!" << endl;
    while (rounds > 0)
    {
        for (int u = 0; u < allTeamsHolder.size(); u++)
        {
            //displays the teams
            playerList = allTeamsHolder.at(u).getPlayers();
            cout << "ROUND: " << displayRound << endl;
            cout << "Team " << allTeamsHolder.at(u).getTeamID() << " is playing" << endl;
            cout << "Team " << allTeamsHolder.at(u).getTeamID() << " contains: " << endl;
            for (int k = 0; k < playerList.size(); k++) //displays the players within each team
            {
                cout << playerList.at(k).getFirstName() << " " << playerList.at(k).getLastName() << endl;
            }
            srand(time(0)); //first line of the code
            vector <string> wordSetter;                          //////// 
            wordSetter = Hangman::getWords();                    //////// this is used for each run for hangman
            Hangman::setWords(wordSetter);                       //////// 
            string correctWord = Hangman::getRandomWords();      ////////
            if (u == 0) //checks for team index 0
            {
                if (runHangMan(correctWord) == true)
                {
                    point++; //adds a win
                }
            }
            else if (u == 1) //checks for team index 1
            {
                if (runHangMan(correctWord) == true)
                {
                    point2++; //adds a win
                }
            }
        }
        rounds--; // after one while loop iteration subtract one round played (game will be done after rounds is 0)
        displayRound++;
    }
    allTeamsHolder.at(0).setScore(point); //After the the while loop is done fully add all the point for team 1 onto the private
    allTeamsHolder.at(1).setScore(point2); //After the the while loop is done fully add all the point for team 2 onto the private
    vector <int> num; // will be used for the max algorithms  
    cout << endl;
    cout << "Total wins" << endl;
    for (int i = 0; i < allTeamsHolder.size(); i++) // displays each team total wins/points and pushes that into a vector <int> num
    {
        cout << "Team " << allTeamsHolder.at(i).getTeamID() << ": " << allTeamsHolder.at(i).getScore() << " Points" << endl;
        num.push_back(allTeamsHolder.at(i).getScore());
    }
    if (allTeamsHolder.at(0).getScore() == allTeamsHolder.at(1).getScore()) // if tied, display tie
    {
        cout << "Its a tie!" << endl;
    }
    else //else run through the max algorithm to find the index in the allTeamsHolder vector
    {
        int max = num.at(0);
        int index = 0;
        for (int i = 1; i < allTeamsHolder.size(); i++)
        {
            if (num.at(i) > max)
            {
                max = num.at(i);
                index = i; // found index
            }
        }
        cout << "Winner: Team " << allTeamsHolder.at(index).getTeamID() << endl; //display the index after finding it
    }
}
