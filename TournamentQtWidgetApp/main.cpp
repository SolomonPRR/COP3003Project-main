#include "TournamentQtWidgetApp.h"
#include <QtWidgets/QApplication>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>

class Team {
private:
    std::string name = " ";
    int wins = 0, losses = 0, draws = 0, totalPoints = 0, winStreak = 0, wlr = 0; // Win/Loss Ratio between 100 and 0.
    bool eliminated = false;

public:
    Team(std::string newName) {
        name = newName;
    }

    std::string getName() {
        return name;
    }

    int getWins() {
        return wins;
    }

    int getLosses() {
        return losses;
    }

    int getDraws() {
        return draws;
    }

    int getPoints() {
        return totalPoints;
    }

    int getStreak() {
        return winStreak;
    }

    bool getEliminated() {
        return eliminated;
    }

    void eliminate() {
        eliminated = true;
    }

    void resetElimination() {
        eliminated = false;
    }

    double getWLR() {
        if (wins + losses == 0) {
            wlr = 0;
        }
        else { // All just to make sure it rounds correctly. AI assistance was used here.
            wlr = static_cast<int>(std::round(static_cast<double>(wins) * 100 / (wins + losses)));
        }
        return wlr;
    }

    void tally(std::string result, int points) {
        totalPoints += points;
        if (result == "WIN") {
            wins++;
            winStreak++;
        }
        else if (result == "LOSS") {
            losses++;
            winStreak = 0;
        }
        else {
            draws++;
            winStreak = 0;
        }
    }
};

class Match {
private:
    Team team1, team2;
    int t1Score, t2Score;

public:
    Match(Team first, Team second) : team1(first), team2(second) {}

    Team getTeam(int team) {
        if (team == 1) {
            return team1;
        }
        else if (team == 2) {
            return team2;
        }
    }

    int getScore(int team) {
        if (team == 1) {
            return t1Score;
        }
        else if (team == 2) {
            return t2Score;
        }
    };

    // Returns the result of the match for the specified team (1 or 2) as a string: "WIN", "LOSS", or "DRAW".
    std::string getResult(int team) {
        int ourScore, theirScore;
        if (team == 1) {
            ourScore = t1Score;
            theirScore = t2Score;
        }
        else if (team == 2) {
            ourScore = t2Score;
            theirScore = t1Score;
        }

        if (ourScore > theirScore) {
            return "WIN";
        }
        else if (ourScore < theirScore) {
            return "LOSS";
        }
        else {
            return "DRAW";
        }
    }

    void addPoints(int team, int points) {
        if (team == 1) {
            t1Score += points;
        }
        else if (team == 2) {
            t2Score += points;
        }
    }
};

class Tournament {
private:
    std::vector<Team> teams;
    int round = 1, match = 1, totalTeams, totalMatches, totalRounds;

public:
    Tournament(int totalTeams, int totalMatches) : totalTeams(totalTeams), totalMatches(totalMatches) {
		// Put all teams into the teams vector, and set all to not eliminated. (Needs GUI Implementation for this)
		// for (int i = 0; i < totalTeams; ++i) {
		//    teams.push_back(Team( [Grab Info From GUI] ));
		//    teams[i].resetElimination();
        // }

        if (teams.size() != 4 && teams.size() != 8 && teams.size() != 16) {
			// Cancel the Tournament creation somehow or just terminate the program with an error message. Should never get to this point.
            exit(1);
		}
        else if (totalTeams == 4) {
            totalMatches = 3;
            totalRounds = 2;
        }
        else if (totalTeams == 8) {
            totalMatches = 7;
			totalRounds = 3;
        }
        else if (totalTeams == 16) {
            totalMatches = 15;
			totalRounds = 4;
        }
    }

    // I don't believe this is how we will be adding teams in the end product, but this can be used for testing in the meantime.
    // This might actually get moved outside of this class, depends on how I want to go about it.
    void addTeam() {

        std::string name;

        std::cout << "\nEnter team name: ";
        std::getline(std::cin, name);

        teams.push_back(Team(name));

        std::cout << name << "\nWelcome to the tournament!\n" << "\nYour team was added\n";
    }

    // Not entirely sure what we'll be using this for, but I will leave it here.
    void showTeams() {
        if (teams.empty()) {
            std::cout << "No teams have been added yet.\n";
            return;
        }
        std::cout << "Teams in the tournament:\n";

        for (int i = 0; i < teams.size(); ++i) {
            std::cout << i + 1 << ". " << teams[i].getName() << "\n";
        }
    }

    void nextMatch() {
		if (match > totalMatches) {
            // No more matches to be played.
			return;
		}
		else {
			match++; // Placeholder.
		}
    }

    void nextRound() {
		// Each Team vs Team is considered a "Match", once all teams have played a match, the current "Round" ends, progressing until the end of the Tournament.
        // Only 3 Tournament Sizes will be supported, 16, 8, and 4 Teams. Doing this any differently will require more work, and is currently outside of our scope.
		// 16 Teams: 4 Rounds, 15 Matches
			// Round 1: Team 1 vs Team 2, Team 3 vs Team 4, Team 5 vs Team 6, Team 7 vs Team 8, Team 9 vs Team 10, Team 11 vs Team 12, Team 13 vs Team 14, Team 15 vs Team 16
			// Round 2: Team 1/2 vs Team 3/4, Team 5/6 vs Team 7/8, Team 9/10 vs Team 11/12, Team 13/14 vs Team 15/16
			// Round 3: Team 1/2/3/4 vs Team 5/6/7/8, Team 9/10/11/12 vs Team 13/14/15/16
			// Round 4: Team 1/2/3/4/5/6/7/8 vs Team 9/10/11/12/13/14/15/16
		// 8 Teams: 3 Rounds, 7 Matches
            // Round 1: Team 1 vs Team 2, Team 3 vs Team 4, Team 5 vs Team 6, Team 7 vs Team 8
            // Round 2: Team 1/2 vs Team 3/4, Team 5/6 vs Team 7/8, Team 9/10 vs Team 11/12, Team 13/14 vs Team 15/16
			// Round 3: Team 1/2/3/4 vs Team 5/6/7/8
		// 4 Teams: 2 Rounds, 3 Matches
            // Round 1: Team 1 vs Team 2, Team 3 vs Team 4
            // Round 2: Team 1/2 vs Team 3/4
        if (round < totalRounds) {
            round++; // Unfortunately, still a Placeholder.
        }
        else {
            // Nothing for now.
        }
    }

    // Will be called at the end of each Match.
    void removeLoser(Match match) {
        std::string Loser;

        if (match.getResult(1) == "WIN") {
            Loser = match.getTeam(2).getName();
        }
        else if (match.getResult(1) == "LOSE") {
            Loser = match.getTeam(1).getName();
        }
        else
        {
            // Both Teams lose
			for (std::vector<Team>::iterator it = teams.begin(); it != teams.end(); ++it) {
				if (it->getName() == match.getTeam(1).getName() || it->getName() == match.getTeam(2).getName()) {
					std::cout << "Team " << it->getName() << " has been eliminated from the tournament.\n";
					teams[it].eliminate();
				}
			}
            return;
        }

        // Remove the team that lost from the team vector
        for (std::vector<Team>::iterator it = teams.begin(); it != teams.end(); ++it) {
            if (it->getName() == Loser) {
                std::cout << "Team " << Loser << " has been eliminated from the tournament.\n";
				teams[it].eliminate();
            }
        }
    }
};

int main(int argc, char* argv[])
{

    QApplication app(argc, argv);
    TournamentQtWidgetApp window;
    window.show();
    return app.exec();

    Tournament tournament(0, 0);

    while (true) {
        std::cout << "1. Add Team\n";
        std::cout << "2. Show Teams\n";
        std::cout << "3. Next Round\n4. Exit\n";
        int choice;
        std::cin >> choice;
        std::cin.ignore();
        if (choice == 1) {
            tournament.addTeam();
        }
        else if (choice == 2)
        {
            tournament.showTeams();

        }
        else if (choice == 3) {
            tournament.nextRound();
        }
        else if (choice == 4) {
            break;
        }
        else {
            std::cout << "Invalid choice. Choose one of the numbers given\n";
        }
    }
}