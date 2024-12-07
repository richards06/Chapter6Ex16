/*
Program Title: Chapter6Ex16
Programmer: Josh Richards
Date: December 7, 2024
Requirements: 

Write a program that displays the contents of the Teams.txt file on the screen and 
prompts the user to enter the name of one of the temas. The program should then display
the number of times that team has won the World Series in the time period from 1903 to
2012.

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void loadFileToVector(const string& filename, vector<string>& vec) {
    ifstream file(filename);
    if (!file) {
        cout << "Error opening file: " << filename << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
        vec.push_back(line);
    }
    file.close();
}

int countOccurrences(const vector<string>& vec, const string& team) {
    return count(vec.begin(), vec.end(), team);
}

void displayTeams(const vector<string>& teams) {
    cout << "Major League Baseball Teams that have won the World Series:\n";
    for (const auto& team : teams) {
        cout << team << endl;
    }
}

string getUserInput() {
    string selectedTeam;
    cout << "\nEnter the name of a team: ";
    getline(cin, selectedTeam);
    return selectedTeam;
}

void displayWins(const string& team, int wins) {
    if (wins > 0) {
        cout << team << " has won the World Series " << wins << " times from 1903 to 2012." << endl;
    }
    else {
        cout << team << " did not win the World Series during the specified time period." << endl;
    }
}

int main() {
    vector<string>teams;
    vector<string> worldSeriesWinners;

    loadFileToVector("Teams.txt", teams);
    loadFileToVector("worldSeriesWinner.txt", worldSeriesWinners);

    displayTeams(teams);

    string selectedTeam = getUserInput();

    int wins = countOccurrences(worldSeriesWinners, selectedTeam);

    displayWins(selectedTeam, wins);

    return 0;
}

