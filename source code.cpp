#include<iostream>
#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;

int board[4][4];
int lineDirection[] = {1,0,-1,0};
int columnDirection[] = {0,1,0,-1};

pair<int,int> generatenewpos()
{
    int taken=1,line,column;
    while (taken)
    {
        int line = rand() % 4;
        int column = rand() % 4;
        if (board[line][column]==0)
            taken=0;
    }
    return make_pair(line,column);
}

void newGame()
{
    for (int i=0; i<4; i++)
        for (int j=0; j<4; j++)
            board[i][j]=0;
    pair<int,int> pos = generatenewpos();
    int x=pos.first;
    int y=pos.second;
    board[x][y]=2;
}

void printInterface()
{
    for (int i=0; i<4; i++)
   {
      for (int j=0; j<4; j++)
            if (board[i][j]==0)
                cout << "*";
            else
                cout << board[i][j];
        cout << endl;
   }
   cout << "n: new game, q: quit game, a: left, d: right, s: down, w:up"<< endl;
}

bool canDoMove (int line, int column, int nextLine, int nextColumn)
{
    if (nextLine < 0 || nextColumn <0 || nextLine >=4 || nextColumn >=4
        || (board[line][column] != board[nextLine][nextColumn] && board[nextLine][nextColumn] != 0))
        return false;
    return true;
}

void executeMove (int direction)
{
    int startLine = 0, startColumn=0, linestep = 1, columnstep = 1;
    if (direction == 0)
    {
        startLine = 3;
        linestep = -1;
    }
    if (direction == 1)
    {
        startColumn = 3;
        columnstep = -1;
    }
    int movePossible=0;
    for (int i = startLine; i>=0 && i<4; i+=linestep)
        for (int j = startColumn; j >=0 && j<4; j+=columnstep)
        {
            int nextI = i + lineDirection[direction], nextJ = j + columnDirection[direction];
            if (canDoMove(i,j,nextI,nextJ));
            {
                board[nextI][nextJ] +=board[i][j];
                board[i][j]=0;
                movePossible=1;
            }
        }

}
int main()
{
    char command_direction[120];
    command_direction['s'] = 0;
    command_direction['d'] = 1;
    command_direction['w'] = 2;
    command_direction['a'] = 3;
    newGame();
    while (true)
    {
        printInterface();
        char command;
        cin >> command;
        if (command=='n')
            newGame();
        else if (command=='q')
            break;
        else
        {
            int direction = command_direction[command];
            executeMove(direction);
        }
    }
    return 0;
}
