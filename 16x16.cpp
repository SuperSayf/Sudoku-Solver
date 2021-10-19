//Use suppressed optimizations for faster execution times
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <iostream>
#include <vector>

using namespace std;

#define N 16
#define Nn 4
#define UNASSIGNED 0

//Setup global grid for use
int grid[N][N];
int order[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int tracker[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

void genOrder()
{
    //sorting
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (order[i] < order[j])
            {
                int temp = 0;
                temp = order[i];
                order[i] = order[j];
                order[j] = temp;

                temp = tracker[i];
                tracker[i] = tracker[j];
                tracker[j] = temp;
            }
        }
    }
}

bool isSafe(int row, int col)
{
    //Used in the hidden and naked single

    //Check row and col
    int copy = grid[row][col];
    for (int i = 0; i < N; i++)
    {
        if (grid[row][i] == copy)
        {
            if (i != col)
            {
                return true;
            }
        }
        if (grid[i][col] == copy)
        {
            if (i != row)
            {
                return true;
            }
        }
    }

    //Check block
    int bRow = row / Nn;
    int bCol = col / Nn;

    for (int calcR = bRow * Nn; calcR <= bRow * Nn + (Nn - 1); calcR++)
    {
        for (int calcC = bCol * Nn; calcC <= bCol * Nn + (Nn - 1); calcC++)
        {
            if (grid[calcR][calcC] == copy)
            {
                if (calcR != row)
                {
                    if (calcC != col)
                    {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

int getEmptyCells()
{
    //Return the count of empty cells as an integer
    int count = 0;
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            if (grid[row][col] == UNASSIGNED)
            {
                count++;
            }
        }
    }
    return count;
}

void nakedSingle()
{
    //Naked Single means that in a specific cell only one digit remains possible
    //(the last remaining candidate has no other candidates to hide behind and is thus naked)
    //The digit must then go into that cell.

    int pCand = 0;

    while (pCand != getEmptyCells())
    {
        pCand = getEmptyCells();
        for (int row = 0; row < N; row++)
        {
            for (int col = 0; col < N; col++)
            {
                int pGuesses = 0;
                int value = 0;

                if (grid[row][col] == UNASSIGNED)
                {
                    for (int guessVal = 0; guessVal < N; guessVal++)
                    {
                        grid[row][col] = tracker[guessVal];

                        if (!isSafe(row, col))
                        {
                            value = tracker[guessVal];
                            pGuesses++;
                        }
                    }
                    if (pGuesses != 1)
                    {
                        grid[row][col] = UNASSIGNED;
                    }
                    else
                    {
                        grid[row][col] = value;
                    }
                }
            }
        }
    }
}

void hiddenSingle()
{
    //Hidden Single means that for a given digit and block only one cell is left to place that digit
    //The cell itself has more than one candidate left, the correct digit is thus hidden amongst the rest

    int pCand;

    //Col
    pCand = 0;
    while (pCand != getEmptyCells())
    {
        pCand = getEmptyCells();
        for (int row = 0; row < N; row++)
        {
            for (int value = 0; value < N; value++)
            {
                int colI = 0;
                int pos = 0;

                for (int col = 0; col < N; col++)
                {
                    if (grid[row][col] == UNASSIGNED)
                    {
                        grid[row][col] = tracker[value];

                        if (!isSafe(row, col))
                        {
                            colI = col;
                            pos++;
                        }
                        grid[row][col] = UNASSIGNED;
                    }
                }
                if (pos == 1)
                {
                    grid[row][colI] = tracker[value];
                }
            }
        }
    }

    //Row
    pCand = 0;
    while (pCand != getEmptyCells())
    {
        pCand = getEmptyCells();
        for (int col = 0; col < N; col++)
        {
            for (int value = 0; value < N; value++)
            {
                int rowI = 0;
                int pos = 0;

                for (int row = 0; row < N; row++)
                {
                    if (grid[row][col] == UNASSIGNED)
                    {
                        grid[row][col] = tracker[value];

                        if (!isSafe(row, col))
                        {
                            rowI = row;
                            pos++;
                        }
                        grid[row][col] = UNASSIGNED;
                    }
                }
                if (pos == 1)
                {
                    grid[rowI][col] = tracker[value];
                }
            }
        }
    }

    //Block
    pCand = 0;
    while (pCand != getEmptyCells())
    {
        pCand = getEmptyCells();
        for (int bRow = 0; bRow < Nn; bRow++)
        {
            for (int bCol = 0; bCol < Nn; bCol++)
            {
                for (int value = 0; value < N; value++)
                {
                    int pos = 0;
                    int colI = 0;
                    int rowI = 0;

                    for (int calcR = bRow * Nn; calcR < bRow * Nn + Nn; calcR++)
                    {
                        for (int calcC = bCol * Nn; calcC < bCol * Nn + Nn; calcC++)
                        {
                            if (grid[calcR][calcC] == UNASSIGNED)
                            {
                                grid[calcR][calcC] = tracker[value];

                                if (!isSafe(calcR, calcC))
                                {
                                    rowI = calcR;
                                    colI = calcC;
                                    pos++;
                                }
                                grid[calcR][calcC] = UNASSIGNED;
                            }
                        }
                    }
                    if (pos == 1)
                    {
                        grid[rowI][colI] = tracker[value];
                    }
                }
            }
        }
    }
}

void getSingles()
{
    //Combining hidden single and naked single functions
    int count = 1;
    do
    {
        count = getEmptyCells();
        nakedSingle();
        hiddenSingle();
    } while (count != getEmptyCells());
}

struct candidates
{
    //Keep track of candidates
    bool TF[N] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int track = N + 1;
};

candidates calcCandidates(int row, int col)
{
    candidates cand;

    //Row
    for (int colL = 0; colL < N; colL++)
    {
        if (grid[row][colL] != UNASSIGNED)
        {
            cand.TF[grid[row][colL] - 1] = false;
        }
    }

    //Col
    for (int rowL = 0; rowL < N; rowL++)
    {
        if (grid[rowL][col] != UNASSIGNED)
        {
            cand.TF[grid[rowL][col] - 1] = false;
        }
    }

    //Block
    int bRow = row / Nn;
    bRow *= Nn;
    int bCol = col / Nn;
    bCol *= Nn;

    for (int i = 0; i < Nn; i++)
    {
        for (int j = 0; j < Nn; j++)
        {
            if (grid[bRow + i][bCol + j] != UNASSIGNED)
            {
                cand.TF[grid[bRow + i][bCol + j] - 1] = false;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (cand.TF[i])
        {
            count++;
        }
    }
    cand.track = count;

    return cand;
}

bool isComplete()
{
    //Check if board is complete
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            if (grid[row][col] == UNASSIGNED)
            {
                return false;
            }
        }
    }

    return true;
}

bool solve()
{
    //Start/continue at best row and col on the board
    int best = 17;
    int bestRow;
    int bestCol;

    vector<pair<int, int>> pCand;

    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            if (grid[row][col] == UNASSIGNED)
            {
                candidates cand = calcCandidates(row, col);

                if (cand.track == 1)
                {
                    pCand.push_back(make_pair(row, col));

                    for (int value = 0; value < N; value++)
                        if (cand.TF[tracker[value] - 1])
                        {
                            grid[row][col] = tracker[value];
                            break;
                        }
                }
                else if (cand.track < best)
                {
                    bestRow = row;
                    bestCol = col;
                    best = cand.track;
                }
            }
        }
    }

    if (isComplete())
    {
        return true;
    }

    candidates cand = calcCandidates(bestRow, bestCol);

    //Brute 1..N
    for (int value = 0; value < N; value++)
    {
        if (cand.TF[tracker[value] - 1])
        {
            grid[bestRow][bestCol] = tracker[value];
            if (solve())
            {
                return true;
            }
            grid[bestRow][bestCol] = 0;
        }
    }

    for (int i = 0; i < pCand.size(); i++)
    {
        grid[pCand[i].first][pCand[i].second] = 0;
    }

    return false;
}

int main()
{
    //Fast input
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //Take in NxN input
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            char input;
            cin >> input;
            int num = input;
            if (num < 65)
            {
                grid[row][col] = num - 48;

                //Setup tracker for hidden and naked singles
                order[(num - 48)] += 1;
            }
            else
            {
                grid[row][col] = num - 55;

                //Setup tracker for hidden and naked singles
                order[(num - 55)] += 1;
            }
        }
    }

    //Get order for hidden/naked singles tracker
    //Basically arranges the bruteforce 1..N is terms of the population of each cell
    genOrder();

    //Find cells using hidden and naked singles, and add to grid
    getSingles();

    //Get order for recursion tracker
    //Basically arranges the bruteforce 1..N is terms of the population of each cell
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            order[grid[row][col]] += 1;
        }
    }
    genOrder();

    //Start backtracking with updated grid
    if (solve())
    {
        //Print the grid if solved
        for (int row = 0; row < N; row++)
        {
            if (grid[row][0] > 9)
            {
                char c = (char)(grid[row][0] + 55);
                cout << c;
            }
            else
            {
                cout << grid[row][0];
            }
            for (int col = 1; col < N; col++)
            {
                if (grid[row][col] > 9)
                {
                    char c = (char)(grid[row][col] + 55);
                    cout << ' ' << c;
                }
                else
                {
                    cout << ' ' << grid[row][col];
                }
            }
            cout << "\n";
        }
    }
    else
    {
        //Could not find a solution
        cout << "No Solution"
             << "\n";
    }

    return 0;
}