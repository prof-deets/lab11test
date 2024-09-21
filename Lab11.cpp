#include <iostream>
using namespace std;

void Reverse(string *&, int);                     // Reverse order of strings in array
string OutputArray(string *&arrPtr, int arrSize); // Output array on 1 line

int main()
{
    // Initialize variables
    int ARRAY_SIZE = 5;
    string *sArrayPtr = new string[ARRAY_SIZE]; // Allocate array of 5 ints

    *(sArrayPtr + 0) = "John";
    *(sArrayPtr + 1) = "Jacob";
    *(sArrayPtr + 2) = "Jingle";
    *(sArrayPtr + 3) = "Heimer";
    *(sArrayPtr + 4) = "Schmidt";

    // Output array before reverse
    cout << "Name array BEFORE reverse: " << OutputArray(sArrayPtr, ARRAY_SIZE) << endl << endl;

    Reverse(sArrayPtr, ARRAY_SIZE); // Reverse order of array strings

    // Output array after reverse
    cout << "Name array AFTER reverse: " << OutputArray(sArrayPtr, ARRAY_SIZE) << endl << endl;

    // Deallocate heap elements and nullify pointers
    delete[] sArrayPtr;
    sArrayPtr = nullptr;

    return 0;
}

// Populate array with user input
void Reverse(string *&arrPtr, int arrSize)
{
    // For array size, loop and exchange index values to reverse array
    string temp = "";
    for (size_t i = 0; i < arrSize / 2; i++) // Loop halfway up array exchanging opposite index values
    {
        temp = *(arrPtr + i);
        *(arrPtr + i) = *(arrPtr + arrSize - 1 - i);
        *(arrPtr + arrSize - 1 - i) = temp;
    }
}

// Output array on one line
string OutputArray(string *&arrPtr, int arrSize)
{
    // For array size, output each value in some kind of formatted way
    string output = "{";
    for (size_t i = 0; i < arrSize; i++)
    {
        if (i > 0)
            output += ", "; // Add ',' and ' ' for each additional value after the first
        output += *(arrPtr + i);
    }
    output += "}";

    return output;
}