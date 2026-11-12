#pragma once
#include <iostream>
#include <string>
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
