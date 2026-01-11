#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * Algorithm Challenge – Level 3 | #40 Join String (Function Overloading)
 *
 * This program demonstrates the concept of function overloading by providing multiple versions of the same function name.
 *
 * The JoinString function is implemented in two different forms:
 * 1. Accepts a vector<string>
 * 2. Accepts a string array with its length
 *
 * Although both functions share the same name, the compiler distinguishes between them based on their parameter lists (function signature), not the function name itself.
 *
 * This challenge reinforces understanding of:
 * - Function overloading
 * - API design consistency
 * - Working with different data containers
 */

// Joins strings stored in a vector using a delimiter
string JoinString(vector<string> VecString, string Delim)
{
    string Result = ""; // Stores the final joined string

    // Range-based loop to traverse the vector
    for (string &STR : VecString)
    {
        // Append current element followed by the delimiter
        Result = Result + STR + Delim;
    }

    // Remove the extra delimiter added after the last element
    return Result.substr(0, Result.length() - Delim.length());
}

// Joins strings stored in a traditional array using a delimiter
string JoinString(string arrString[], short Length, string Delim)
{
    string Result = ""; // Stores the final joined string

    // Classic loop to traverse the array using its length
    for (short i = 0; i < Length; i++)
    {
        // Append array element followed by the delimiter
        Result = Result + arrString[i] + Delim;
    }

    // Remove the trailing delimiter
    return Result.substr(0, Result.length() - Delim.length());
}

int main()
{
    // Example using vector<string>
    vector<string> VecString = {"Mohammed", "Fahad", "Salim", "Alya"};

    // Example using string array
    string arrString[] = {"Mohammed", "Fahad", "Salim", "Alya"};

    cout << "Vector After Join:" << endl;
    cout << JoinString(VecString, " - ") << endl;

    cout << "\nArray After Join:" << endl;
    cout << JoinString(arrString, 4, " : ") << endl;

    /*
     * Key idea:
     * The programmer calls the same function name (JoinString), but passes different parameter types.
     *
     * The compiler selects the correct function version
     * based solely on the function signature (parameters), not on the function name.
     */

    return 0;
}
