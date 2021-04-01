#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
using namespace std;

//Function takes 2 dimensional array and the number of random pairs
//of indices produced which will be used to fill the array
int** populateArray(int **Matrix, int initialiser, int N)
{

    int count = 0;
    while (count < N)
    {
        int i = rand() % (100 + 0);
        int j = rand() % (100 + 0);
        if (Matrix[i][j] == initialiser)
        {
            //Then we know that the random position has an undefined value
            //So we just give that position a 1
            Matrix[i][j] = 1;
        }
        else
        {
            Matrix[i][j] += 1;
        }
        count++;
    }
    return Matrix;
}



//Function for creating the square matrix of size N and filling each index in it with
//the number known as initialiser.
int **arrayCreate(int size, int initialiser, int Populace_Number)
{
    int **MultiArray = new int *[size];
    for (int i = 0; i < size; i++)
    {
        MultiArray[i] = new int[size]; //Making 2 Dimensional array by indexing with i and rows are the same number as column
    } 
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            MultiArray[i][j] = initialiser;
        }
    }
    return populateArray(MultiArray, initialiser, Populace_Number);
}

void searchValidEntries(int XL, int YL, int XH, int YH, int **Matrix)

/*
    Now we set our loops for checking within the box from the values given
    We will have a for loop with a nested for loop. Outer loop for the rows
    Inner loop for the columns. Outer loop is for starting and stopping the 
    checking at the first index and ending by a range of the calculated height
    Similar for the inner loop which is meant for how many elements horizontally
    should be checked
     */

{
    int height = abs(XH - XL);
    int base = abs(YH - YL);
    for (int i = (XL - height); i < XL + 1; i++)
    {

        for (int j = YH - base; j < YH + 1; j++)
        {
            if (Matrix[i][j] != 1)
            {
                cout << i << ","
                     << " " << j << ";"
                     << " " << Matrix[i][j] << "\n"
                     << "-- DONE --\n";
            }
        }
    }
}

void cleanUp(int **arrayToClean, int size)
{
    for (int i = 0; i < size; ++i)
    {
        delete[] arrayToClean[i];
    }
    delete[] arrayToClean;
}

int main(int argc, char const *argv[])
{
    int **A = arrayCreate(101, 0, 2000);
    searchValidEntries(80,1,100,10,A);
    // searchValidEntries(10,20,40,79,A);
    // searchValidEntries(1,90,100,100,A);
    // searchValidEntries(40,30,70,60,A);
    // searchValidEntries(50,50,70,70,A);
    // cleanUp(A,101);

    return 0;
}
