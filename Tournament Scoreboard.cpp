#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

class Team {
private:
    std::string name = " ";
    int wins = 0, losses = 0, draws = 0, totalPoints = 0, winStreak = 0, wlr = 0; // Win/Loss Ratio between 200 and 0.

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
    std::vector<Team> teams, matches;
    int round = 1;

public:
    Tournament(int totalTeams, int totalMatches) {
        for (int i = 0; i < totalTeams; ++i) {
            // Needs to be discussed, Placeholder for now.
        }
        for (int i = 0; i < totalMatches; ++i) {
            // Ditto.
        }
    }

    void nextRound() {
        round++; // Placeholder for now.
    }

    void removeLoser(Match match) {
        if (match.getResult(1) == "WIN") {
            // Remove match.getTeam(2) from vector teams
        }
        else if (match.getResult(1) == "LOSE") {
            // Remove match.getTeam(1) from vector teams
        }
        else if (match.getResult(1) == "DRAW") {
            // TBD
        }
    }

    void shuffleBracket() {
        // Undecided addition, TBD
    }

    void enableLD() {
        // Undecided addition, TBD
    }
};

int main()
{
    // Ooga Booga
}
