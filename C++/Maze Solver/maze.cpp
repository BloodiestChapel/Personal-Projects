// Programmer:      Dillon Chappell
// Date Started:    12 December 2020
// ----------------------------------------------
// I wanna make a program that solves a maze.    
// I am not sure what the maze will be made of   
// whether it be pixels or characters like "|",  
// "-", or "+". Ideally I would code this in     
// c++ & utilize different search algorrithms    
// like Breadth First or Djikstra. This probably 
// will use recursion to avoid big code walls.   
// ----------------------------------------------

// 13 December 2020, 3:47 PM
// Started project. Running into problems with
// building the actual executable

// 17 December 2020, 12:47 PM
// Figured out good builds to where I can
// consistently build any C++ program I have
// tested... I totally used a scuffed hello world
// program to test it...

// 23 December 2020, 1:08 AM
// Changed approach. The idea now is to make a maze
// that the user can traverse through. Ideally this
// could be modified to accept input from the PC
// itself. For now the user input is a good 1st
// step.

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Maze Dimensions
const int HEIGHT = 10;
const int WIDTH = 10;

// Maze Parts
const char wall = '#';
const char path = ' ';
const char runner = '*';

// Function Prototypes
void printMaze(char maze[][WIDTH], int current_x, int current_y);
bool validMove(char maze[][WIDTH], int newX, int newY);
bool move(char maze[][WIDTH], int &curX, int &curY, int newX, int newY);

// Main function
int main()
{
    // Maze Map
    char maze[HEIGHT][WIDTH] = 
    {
        {'#','#','#','#','#','#','#','#','#','#'},
        {'#',' ','#',' ',' ',' ','#',' ',' ','#'},
        {'#',' ','#',' ','#',' ','#',' ','#','#'},
        {'#',' ','#','#','#',' ',' ',' ',' ','#'},
        {'#',' ',' ',' ','#',' ','#','#',' ','#'},
        {'#',' ','#','#','#',' ',' ','#',' ','#'},
        {'#',' ','#',' ','#',' ','#','#',' ','#'},
        {'#',' ','#',' ','#',' ','#',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ','#',' ','E','#'},
        {'#','#','#','#','#','#','#','#','#','#'}
    };

    int x = 1;
    int y = 1;
    bool foundExit = false;

    srand(time(NULL));

    while(!foundExit)
    {
        printMaze(maze,x,y);

        // cout << "Enter WASD to move...\n";

        char c;
        int rnd = rand() % 4; // Comment out if user input is needed
        // cin >> c;
        c = tolower(c);

        // Random Choice Traversal
        // These statements are for automated maze running.
        // Currently directions are just chosen at random and
        // this can take a long time to finish. Better logic
        // is needed. Comment out if user input is wanted.
        if(rnd == 0)
        {
            c = 'w';
        }
        else if(rnd == 1)
        {
            c = 'a';
        }
        else if(rnd == 2)
        {
            c = 's';
        }
        else
        {
            c = 'd';
        }

        // Move Logic
        // This switch statement looks for input in the form
        // of "WASD" and will move the runner accordingly
        switch (c)
        {
            case 'w':
                if(validMove(maze,x,y-1))
                {
                    foundExit = move(maze,x,y,x,y-1);
                }
                break;
            case 'a':
                if(validMove(maze,x-1,y))
                {
                    foundExit = move(maze,x,y,x-1,y);
                }
                break;
            case 's':
                if(validMove(maze,x,y+1))
                {
                    foundExit = move(maze,x,y,x,y+1);
                }
                break;
            case 'd':
                if(validMove(maze,x+1,y))
                {
                    foundExit = move(maze,x,y,x+1,y);
                }
                break;
        }
    }
    return 0;
}

// Function declarations:
// ----------------------

// Print Maze Function
// Prints the maze for debugging purposes
void printMaze(char maze[][WIDTH], int current_x, int current_y)
{
    for (int y=0; y < HEIGHT; y++)
    {
        for (int x=0; x < WIDTH; x++)
        {
            if ((x==current_x) && (y==current_y))
                cout << runner;
            else
                cout << maze[y][x];
        }
        cout << endl;
    }
}

// Valid Move Function
// Retuns true or false if the move is valid
bool validMove(char maze[][WIDTH], int newX, int newY)
{
    // Check for horizontal edges
    if(newX < 0 || newX >= WIDTH)
    {
        return false;
    }

    // Check for vertical edges
    if(newY < 0 || newY >= HEIGHT)
    {
        return false;
    }

    // Check for walls
    if(maze[newY][newX] == '#')
    {
        return false;
    }

    // If everything is okay, then...
    return true;
}

// Move Function
// Moves runner to new spot and returns true if we find the exit
bool move(char maze[][WIDTH], int &curX, int &curY, int newX, int newY)
{
    bool foundExit = false;

    if(maze[newY][newX] == 'E')
    {
        foundExit = true;
    }

    curX = newX;
    curY = newY;

    return foundExit;
}