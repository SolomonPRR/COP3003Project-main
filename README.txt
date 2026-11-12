Team Members: Sergio, Dylan, Martha
Project: A Tournament Scoreboard in C++

Operating System: Windows 11 
Compiled in Microsoft Visual Studio

The program is not complete. Only Setup. 

Libraries include: 
   <iostream>,  <iomanip>, <string>, <vector>

Build/Run steps: 
    1.  Open the project on GitHub named Tournament Scoreboard.cpp
    2.  Set classes and needed headers(Libraries)
    3.  Build of your classes and set up what info is needed. 
    4.  Run the program and debug



3 classes set up: Team, Match, and Tournament

Team Class: 
   Currently sets up the name of the team and the number of Win/Loss ratio
    Each team is set to 0 for all values.

Match Class: 
    Will set up the match between 2 teams, comparing the final scores and finalizing the outcome of the match.
    With said outcome, the team will accumulate points 

Tournament class:
  Is still up for discussion, but the overall outcome is to decide which team comes 1st in the tournament. Removing losing teams 
     and determining the next match for the next round. 

GUI: 
The GUI: Incomplete
As of 11/11/26  the GUI has been implemented in the code. So far, we are able to input the team names and add them in the teams list window. 
In progress is the creating/starting matches task, in which we will be able to show the progression of each team. 
To be determined is the deleting teams/compare team points; this will implement the comparison between each team's matches. Any loser or teams in a draw would lead to the team no longer participating in the tournament. 


Needed dependencies: 
    Connecting the creating matches/deleting teams
