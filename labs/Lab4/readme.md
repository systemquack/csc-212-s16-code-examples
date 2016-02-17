# Lab 4

## Recursion and Recursive Backtracking

### Goal:
  To practice recursion in C++

A function is recursive when it is defined in terms of itself. In programming, it is a 
function that calls itself. In other words, somewhere within the body of the function is
a call to the same function. To avoid getting stuck in an infinite chain of recursive 
calls, the definition of a recursive function must provide a special case or cases where 
no call to the function being defined is made. This special case is called the base case.
In addition, each recursive call of the function is made on a "smaller set of arguments" 
and is assumed to work for such arguments. So in a sense, the argument is getting closer
to the base case with every call. When eventually the base case is reached, the recursion
stops.

Here is an example of computing a factorial with recursion:

``` c++

// recursive factorial function

long fact(long n)  {

   if (n == 0)         // base case, 0! = 1
      return 1;
   else
      return (n * fact(n-1));   // recursive call
}

```

## Task 1

Write a C++ program to recursively remove a character from a 300 character string.
The character you will remove is 'q'.  The strings you will operate on will be available 
to you on the [judge server] (judge.cs.uri.edu), look under task 1. 
(The focus here is on the recursion, so feel free to embellish the program once
you have it working.  Spend no more than 15 minutes on this, if possible.)

## Task 2

Use your debugger to set a breakpoint in your code and watch it execute through a few
recursive calls. Note what is happening and then answer the following question:

In an iterative solution, we would need to store a new string as we build it, or somehow
recopy sections of the input string as the target character is removed.  Your
recursive code shouldn't explicitly have copies or extra storage.  How does the 
recursive solution solve this? To put it another way, where does it store the string it
is working on?

## Task 3

Use the code from the repository called nqueens.cpp in the Lab 4 folder.
[lab folder](https://github.com/URI-CSC/csc-212-s16-code-examples/tree/master/labs)
You will need to to fill in the missing C++ code to finish implementing the n-queens
problem.

### The 8 Queens Problem

The eight queens puzzle is the problem of putting eight chess queens on an 8×8 
chessboard such that none of them is able to capture any other using the standard chess 
queen's moves. The queens must be placed in such a way that no two queens would be able 
to attack each other. Thus, a solution requires that no two queens share the same row, 
column, or diagonal. 

### N Queens

The eight queens puzzle is an example of the more general n queens puzzle of placing n 
queens on an n×n chessboard, where solutions exist only for n = 1 or n ≥ 4. 

For a 1x1 board, there is 1 trivial solution.
There are no solutions for a 2x2 and 3x3 board.  (you should be able to convince yourself
that this is true.)
For a 4x4 board, there are 2 solutions.
...
On an 8x8 board, there are 92 distinct solutions.

### Recursive Backtracking

Usual recursive searches can be exhausting because they are exhaustive. In backtracking, 
we will try one choice and only undo that decision if it doesn't work out. Here is some
generic pseudocode to illustrate the concept:

```

bool Solve( configuration conf)

{

  // Base Case - all recursive functions need at least one base case

  if (no more choices)

  {

    return (conf is goal state)

  }


  for (all available choices)
  {

    try one choice c

      // recursively solve after making the choice

    ok = Solve(conf with choice c made);

    if (ok)
      return true
    else
      unmake choice c
  }

  return false   // we tried all the choices, and no solution was found
}

```

In order to make this code as clear as possible, helper functions can be used. You will 
need to write the code for the is_safe() function. It has only to test if a queen can be
placed at row, col on the board. 

When you have finished the code and it works to your satisfaction, please submit this on
the judge under task 3. 
