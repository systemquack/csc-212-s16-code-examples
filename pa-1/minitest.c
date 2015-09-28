#include "pa-1.h"
#include <stdio.h>

void text_output(int question_number, bool answer);

//
// This program is a driver to test the first assignment functions.
//  The first 4 are tested.
//
int main(int argc, char** argv)
{
  bool ans;
  int armstrong_test = 8;  // true
  char brackets[5] = "[[]]";  // true
  int perfect_test = 28; // true
  int rotate_test = 1234;
  int r = 1;
  int rotate_test_solution = 2341;
  int rotate_test_ans = 0;


  printf("Testing functions:\n");


  ans = f_armstrong(armstrong_test);
  text_output(1, ans==true);

  ans = f_brackets(brackets);
  text_output(2, ans==true);

  ans = f_perfect(perfect_test);
  text_output(3, ans==true);

  rotate_test_ans = f_rotate(rotate_test,r);
  if(rotate_test_ans == rotate_test_solution)
  {
      ans = true;
  }
  else
  {
      ans = false;
  }
  text_output(4,ans);
}

//
//  This function handles the output for the tests.
//
void text_output(int question_number, bool answer)
{
    printf("Question %d:\n", question_number);
    if(answer == true)
    {
        printf("   Passed!\n\n");
    }
    else
    {
        printf("   Failed!\n\n");
    }
}
