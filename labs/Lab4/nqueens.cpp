// Your includes..

//#include <iostream>

using namespace std;

//
//  Function to check if the queen is in a safe place
//
bool is_safe(int *board, int row, int col, int n);

//
//  Recursive Backtracking
//
bool nqueens(int *board, int col, int n);

//
//  Display the board
//
void print_board(int *board, int nq);

//
//  Main
//
int main(int argc, char ** argv)
{
// used for number of queens from command line:
//    if( argc != 2)
//    {
//        cout << "usage: nqueens <number_of_queens>" << endl;
//        return 1;
//    }// end if
    
//    int nq = atoi(argv[1]);
    
// used if number of queens from standard input:
    int nq;
    cin >> nq;
    
    int boardarray[nq * nq];
    int *board = boardarray;
    bool success;
    
    // initialize the board to all zeros
    for(int i=0; i<nq; i++)
    {
        for(int j=0; j<nq; j++)
        {
            boardarray[j * nq + i] = 0;  // same as boardarray[i][j] = 0;
        }
    }
    
    // call the recursive backtracking function to solve n queens
    success = nqueens(board, 0, nq);

    // display the board to show the final position
    if (success)
    {
        print_board(board, nq);
    }
    else
    {
        cout << "no solution found!" << endl;
    }

    return 0;
    
}// end main

//
//  Checks if a queen can be placed at the row,col of board
//  This is only called when queens are placed in previous columns
bool is_safe(int *board, int row, int col, int n)
{
  // implement this !

  // check for row attacks..
  // check for diagonal attacks..

    return true;
    
}// end is_safe


bool nqueens(int *board, int col, int n)
{
    // base case; all queens are placed
    if(col >= n)
    {
        return true;
    }
    
    // try placing a queen in all rows
    for(int i=0; i<n; i++)
    {
        if(is_safe(board, i, col, n))
        {
            board[col * n + i] = 1;
            if(nqueens(board, col+1, n))
            {
                return true;
            }
            else
            {
                // need to backtrack, remove the queen
                board[col * n + i] = 0;
            }
               
        }
    }
    
    return false;

}// end nqueens


void print_board(int *board, int nq)
{
    for(int i=0; i<nq; i++)
    {
        for(int j=0; j<nq; j++)
        {
            if(board[j * nq + i] == 1)
            {
                cout << "Q ";
            }
            else
            {
                cout << ". ";
            }
        }// end j
        cout << endl;
    }// end i
}// end print_board
