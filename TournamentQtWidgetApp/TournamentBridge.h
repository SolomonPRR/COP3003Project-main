#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <stdexcept>

class Team {
private:
    std::string name = " ";
    int wins = 0, losses = 0, totalPoints = 0;

public:
    Team(std::string newName) {
        name = newName;
    }

    std::string getName() const {
        return name;
    }

    int getWins() {
        return wins;
    }

    int getLosses() {
        return losses;
    }

    int getPoints() {
        return totalPoints;
    }
    ~Team() {
        
    }
};

class Match {
private:
    Team team1, team2;
    int t1Score =0 , t2Score =0 ;

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

        if (team == 1 || team == 2) {
            if (ourScore > theirScore) {
                return "WIN";
            }
            else if (ourScore < theirScore) {
                return "LOSS";
            }
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
    int round = 1, match = 1, totalTeams;

public:
    Tournament(int totalTeams) : totalTeams(totalTeams) {

    }


    bool addTeam(const std::string& name)
    {
        if (name.empty())
            return false;

        for (auto& team : teams)
        {
            if (team.getName() == name)
                return false;
        }

        teams.push_back(Team(name));
        return true;
    }

	void clearTeams()
	{
        teams.clear();
	}

	int getTotalTeams() const {
		return static_cast<int>(teams.size());
	}

	const std::vector<Team>& getTeams() const {
		return teams;
	}

    /*void nextMatch() {
        if (match > totalMatches) {
            // No more matches to be played.
            return;
        }
        else {
            match++; // Placeholder.
        }
    }*/

	void removeTeam(const std::string& name) {
		for (auto it = teams.begin(); it != teams.end(); ++it) {
			if (it->getName() == name) {
				teams.erase(it);
				return;
			}
		}
	}

    void nextRound() {
        // Each Team vs Team is considered a "Match", once all teams have played a match, the current "Round" ends, progressing until the end of the Tournament.
        // Only 2 Tournament Sizes will be supported, 8, and 4 Teams. Doing this any differently will require more work, and is currently outside of our scope.
        // 8 Teams: 3 Rounds, 7 Matches
            // Round 1: Team 1 vs Team 2, Team 3 vs Team 4, Team 5 vs Team 6, Team 7 vs Team 8
            // Round 2: Team 1/2 vs Team 3/4, Team 5/6 vs Team 7/8, Team 9/10 vs Team 11/12, Team 13/14 vs Team 15/16
            // Round 3: Team 1/2/3/4 vs Team 5/6/7/8
        // 4 Teams: 2 Rounds, 3 Matches
            // Round 1: Team 1 vs Team 2, Team 3 vs Team 4
            // Round 2: Team 1/2 vs Team 3/4
    }
};