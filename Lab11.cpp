// Program creates a client roster with a todo list (array) of tasks that need to be performed for each client

#include <iostream>
#include <array>
#include <string>

using namespace std;

bool isInt(const string &str); // Checks if string is an integer
unsigned int getPositiveIntFromUser(unsigned int lowerBound, const string &prompt, const string &errorMessage);

struct Client
{
    string name;
    string address;
    string *tasks;
    unsigned int numTasks; // Stores array size for tasks
    ~Client()
    {
        if (tasks)
            delete[] tasks;
        tasks = nullptr;
    }
};

int main()
{
    // Initialize variables
    // string userInput = "";
    int numClientsToInput = 0;
    Client *clientRoster = nullptr; // Will be used to point to array of clients

    // Get number of clients validation loop
    numClientsToInput = getPositiveIntFromUser(0, "How many clients would you like to input (0 to exit): ", "Invalid. Please enter an integer > 0.");

    // Now that we have a valid int, let's create a client roster of that size
    // clientRoster = new Client[numClientsToInput];

    // Deallocate heap elements and nullify pointers
    delete[] clientRoster;
    clientRoster = nullptr;

    return 0;
}

// Check if input is an integer
bool isInt(const string &str)
{
    for (char c : str)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }
    return true;
}

// Validation loop that returns int >= 0
unsigned int getPositiveIntFromUser(unsigned int lowerBound, const string &prompt, const string &errorMessage)
{
    string userInput;
    while (true)
    {
        cout << prompt;
        getline(cin, userInput);
        if (isInt(userInput) && stoi(userInput) > 0)
        {
            return stoi(userInput);
        }
        else
        {
            cout << "\t" << errorMessage << endl;
        }
    }
}