// Program creates a client roster with a todo list (array) of tasks that need to be performed for each client

#include <iostream>
#include <iomanip>
#include <array>
#include <string>

using namespace std;

struct Client
{
    static size_t numOfClients;
    string name;
    string address;
    string *tasks;
    unsigned int numTasks; // Stores array size for tasks
    Client()
    {
        ++numOfClients;
    }
    ~Client()
    {
        if (tasks)
            delete[] tasks;
        tasks = nullptr;
    }
};

size_t Client::numOfClients = 0; // Required initialization outside of struct. C++, why are you like this?

bool isInt(const string &str);                                                                                  // Checks if string is an integer
unsigned int getPositiveIntFromUser(unsigned int lowerBound, const string &prompt, const string &errorMessage); // Collect an integer >= 0 from user
void inputClient(Client *cPtr);                                                                                 // Prompts user to input client information
void displayClient(const Client *const cPtr);                                                                   // Displays client information for given client

int main()
{
    // Initialize variables
    const string DIVIDER = string(30, '*');
    int numClientsToInput = 0;
    Client *clientRosterPtr = nullptr; // Will be used to point to array of clients

    // Get number of clients validation loop
    numClientsToInput = getPositiveIntFromUser(0, "How many clients would you like to input (0 to exit): ", "Invalid. Please enter an integer >= 0.");

    // Now that we have a valid int, let's create a client roster of that size
    clientRosterPtr = new Client[numClientsToInput]; // clientRosterPtr now points to new array of clients

    // Loop through array to create client profiles
    cout << endl << "++ INPUT NEW CLIENT INFO ++" << endl; // Input message
    for (size_t i = 0; i < numClientsToInput; i++)
    {
        cout << "Client #" << i + 1 << endl;
        inputClient(&clientRosterPtr[i]);
        cout << endl;
    }
    cout << DIVIDER << endl
         << endl; // Input completion message

    // Loop through array to output client profiles
    cout << "== NEW CLIENT ROSTER ==" << endl; // Roster output message
    for (size_t i = 0; i < Client::numOfClients; i++)
    {
        cout << "Client #" << i + 1 << endl;
        displayClient(&clientRosterPtr[i]);
        cout << endl;
    }
    cout << DIVIDER << endl;

    // Deallocate heap elements and nullify pointers
    delete[] clientRosterPtr;
    clientRosterPtr = nullptr;

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
unsigned int getPositiveIntFromUser(unsigned int lowerBound, const string &prompt, const string &errorMessage = "Invalid.")
{
    string userInput;
    while (true)
    {
        cout << prompt;
        getline(cin, userInput);
        if (isInt(userInput) && stoi(userInput) >= lowerBound)
        {
            return stoi(userInput);
        }
        else
        {
            cout << "\t" << errorMessage << endl;
        }
    }
}

// Prompts user to input client information
void inputClient(Client *cPtr)
{
    cout << "Client name: ";
    getline(cin, cPtr->name);
    cout << "Client address: ";
    getline(cin, cPtr->address);
    cPtr->numTasks = getPositiveIntFromUser(0, "How many tasks would you like to input for client: ", "Invalid. Please enter an integer >= 0.");

    // Now that we have the number of tasks to input, populate array and prompt user to input tasks
    cPtr->tasks = new string[cPtr->numTasks]; // Create new array to hold tasks
    for (size_t i = 0; i < cPtr->numTasks; i++)
    {
        cout << "Please enter task #" << i + 1 << ": ";
        getline(cin, cPtr->tasks[i]);
    }
}

// Displays client information for given client
void displayClient(const Client *const cPtr)
{
    cout << "Client name: " << cPtr->name << endl;
    cout << "Client address: " << cPtr->address << endl;

    // Output all tasks related to client
    for (size_t i = 0; i < cPtr->numTasks; i++)
    {
        cout << "Task #" << i + 1 << ": " << cPtr->tasks[i] << endl;
    }
}