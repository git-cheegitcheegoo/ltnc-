#include<iostream>
#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;

int cards[4][4];


void createRandomCard()
{
    int taken=1,x,y;
    while (taken)
    {
        int x = rand() % 4;
        int y = rand() % 4;
        if (cards[x][y]==0)
            { taken=0;
            cards[x][y]=2;
    };
}
}



void newGame()
{
    for (int i=0; i<4; i++)
        for (int j=0; j<4; j++)
            cards[i][j]=0;
    createRandomCard();

}

void printInterface()
{
    system("cls");
    for (int i=0; i<4; i++)
   {
      for (int j=0; j<4; j++)
            if (cards[i][j]==0)
                cout << setw(5) << "*";
            else
                cout << setw(5) << cards[i][j];
        cout << endl;
   }
   cout << "n: new game, q: quit game, a: left, d: right, s: down, w:up"<< endl;
}

bool doLeft()
        {
            bool isDo = false;
            for (int x = 0; x < 4; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    for (int y1 = y + 1; y1 < 4; y1++)
                    {
                        if (cards[x][y1] > 0)
                        {
                            if (cards[x][y] == 0)
                            {
                                cards[x][y] = cards[x][y1];
                                cards[x][y1] = 0;
                                y--;
                                isDo = true;
                            }
                            else if (cards[x][y] == cards[x][y1])
                            {
                                cards[x][y] *= 2;
                                cards[x][y1] = 0;

                                isDo = true;
                            }
                            break;
                        }
                    }
                }
            }
            if(isDo)
                createRandomCard();
            return isDo;
        }

        bool doRight()
        {
            bool isDo = false;
            for (int x = 0; x < 4; x++)
            {
                for (int y = 3; y >= 1; y--)
                {
                    for (int y1 = y - 1; y1 >= 0; y1--)
                    {
                        if (cards[x][y1] > 0)
                        {
                            if (cards[x][y] == 0)
                            {
                                cards[x][y] = cards[x][y1];
                                cards[x][y1] = 0;
                                y++;
                                isDo = true;
                            }
                            else if (cards[x][y] == cards[x][y1])
                            {
                                cards[x][y] *= 2;
                                cards[x][y1] = 0;

                                isDo = true;

                            }
                            break;
                        }
                    }
                }
            }
            if (isDo)
                createRandomCard();
            return isDo;
        }

        bool doDown()
        {
            bool isDo = false;
            for (int y = 0; y < 4; y++)
            {
                for (int x = 3; x >= 1; x--)
                {
                    for (int x1 = x - 1; x1 >= 0; x1--)
                    {
                        if (cards[x1][y] > 0)
                        {
                            if (cards[x][y] == 0)
                            {
                                cards[x][y] = cards[x1][y];
                                cards[x1][y] = 0;
                                x++;
                                isDo = true;
                            }
                            else if (cards[x][y] == cards[x1][y])
                            {
                                cards[x][y] *= 2;
                                cards[x1][y] = 0;

                                isDo = true;
                            }
                            break;
                        }
                    }
                }
            }
            if (isDo)
                createRandomCard();
            return isDo;
        }

        bool doUp()
        {
            bool isDo = false;
            for (int y = 0; y < 4; y++)
            {
                for (int x = 0; x < 3; x++)
                {
                    for (int x1 = x + 1; x1 < 4; x1++)
                    {
                        if (cards[x1][y] > 0)
                        {
                            if (cards[x][y] == 0)
                            {
                                cards[x][y] = cards[x1][y];
                                cards[x1][y] = 0;
                                x--;
                                isDo = true;
                            }
                            else if (cards[x][y] == cards[x1][y])
                            {
                                cards[x][y] *= 2;
                                cards[x1][y] = 0;
                                isDo = true;

                            }
                            break;
                        }
                    }
                }
            }
            if (isDo)
                createRandomCard();
            return isDo;
        }
bool Wincheck()
{
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<4; j++)
            if (cards[i][j]==2048)

            return true;

    }
    return false;
}

int main()
{
    newGame();
    while (true)
    {
        printInterface();
        if (Wincheck())
            {
                cout << "You Win!";
                break;
            };
        char command;
        cin >> command;
        if (command=='n')
            newGame();
        else if (command=='q')
            break;
        else
        {
            if (command=='w') doUp();
            if (command=='d') doRight();
            if (command=='s') doDown();
            if (command=='a') doLeft();
        }
    }
    return 0;
}
