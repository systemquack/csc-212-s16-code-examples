//
//  main.cpp
//  Lab2
//

#include <iostream>

using namespace std;

//
// solves the maximum sub-array problem in n^3 time
//
int MaxsubSlow(int *A, int n)
{
    // use m for the maximum partial sum of the array, A
    int m = 0;
    for(int j = 1; j <= n; j++)
    {
        for(int k = j; k <= n; k++)
        {
            // compute the next partial sum
            int s = 0;
            for (int i = j; i <= k; i++)
            {
                s = s + A[i];
            }// end for
            if(s > m)
            {
                // if the partial sum is greater than the biggest so far,
                // store it as the largest sum
                m = s;
            }// end if
        }// end for (k)
    }// end for (j)
    return m;
}// end MaxsubSlow()

int MaxsubFaster(int *A, int n)
{
    // write code here to solve the problem in n^2 time
    int m = 0;
    return m;

}// end MaxsubFaster()

int MaxsubFastest(int *A, int n)
{
    // write code here to solve the problem in linear time
    int m = 0;
    return m;
    
}// end MaxsubFastest()



int main(int argc, const char * argv[]) {

    int number_of_arrays, number_of_elements;
    int *A;

    // read in the inputs from I/O
    cin >> number_of_arrays;
    
    // enter a loop for that many inputs..
    for(int i = 0; i < number_of_arrays; i++)
    {
        // read in the number of elements in the array
        cin >> number_of_elements;
        
        // create the array (because it is indexed from 0, we need an extra element)
        A = new int[number_of_elements + 1];

        // read in each value from the array
        for(int j = 1; j <= number_of_elements; j++)
        {
            cin >> A[j];
        }
        // call MaxsubSlow on this array  (call your other functions for better results..)
        // output the answer
        cout << MaxsubSlow(A, number_of_elements) << endl;
        
        // free the array memory
        delete[] A;
        
    }// end loop (number_of_arrays)
    
    
    return 0;
}// end main
