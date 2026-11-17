Team Members: Sergio, Dylan, Martha
Project: A Tournament Scoreboard in C++

Operating System: Windows 11 
Compiled in Microsoft Visual Studio

The program is not complete. 

Libraries include: 
   <iostream>,  <iomanip>, <string>, <vector>

Build/Run steps: 
    1.  Open the project on GitHub named Tournament Scoreboard.cpp
    2.  Set classes and needed headers(Libraries)
    3.  Build of your classes and set up what info is needed. 
    4.  Run the program and debug
    5.  Now that the GUI is implemented, run the Qt program.
    6. On the First Window click create tournament
    7. Taken to another window, Tournament Settings, add a number of 4 Teams names, make sure it's not the same name
    8. From there click match and you should be guided to another window, implement the points earned, 
         and click calculate match and it should forward the teams with highest points, and do it again for the next round
    9. After the Winner has been decided, click results page and you should be guided into another window and it should follow the 
         winner and semifinalist. 
   10. For Now you have completed our program. 



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

So far, we have completed a 4-tournament program. 
Linking 4 ui. Files to our main C++ code. 

The GUI provides the general flow of the program, allowing users to team names, input points, and calculate the standings for their tournament. 

Adding Teams- 





Still Needed : 
    Linking an 8-team Tournament. 
    Saving data file. 
   
