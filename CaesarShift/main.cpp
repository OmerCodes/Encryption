#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

string Caesar();

// Letter Array, slightly more inefficient than using the default character values but easier.
char Letters[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

int main()
{
    // Generate the random numbers needed for random key generation
    srand (time(NULL));
    // Print the Output of the Caesar Function
    cout << endl << Caesar();
    return 0;
}

string Caesar()
{
    // Initiallize various variables
    string input;
    int key;
    string output2;
    int CaesarInput;
    int CaesarInput2;
    char TempArray[1000];
    int LoopInteger;
    int TempDumpJ;

    cout << "Would You like to:" << endl << "1. Encrypt" << endl << "2. Decrypt" << endl;
    cin >> CaesarInput;
    if(CaesarInput == 1)
    {
        cout << "Enter the Unencrypted Plaintext:";
        cin >> input;
        string output(input.length(), '*');
        cout << "Would you like to:" << endl << "1. Generate a Random Key" << endl << "2. Enter a Key" << endl;
        cin >> CaesarInput2;
        if(CaesarInput2 == 1)
        {
            key = rand() % 25 + 1;
        }
        if(CaesarInput2 == 2)
        {
            cout << "Please enter your key (1-26): ";
            cin >> key;
        }
        cout << endl << "Your Key:" << key << endl;

        for(int i=0; i<input.length(); i++)
        {
            for(int j=0; j<26; j++)
            {
                if(input[i] == Letters[j])
                {
                    TempDumpJ = j;
                }
            }

            LoopInteger = i;

            output[i] = Letters[(TempDumpJ+key)%26];
        }
        //cout << output << endl;
        return output;
    }
    if(CaesarInput == 2)
    {
        cout << "Enter the Unencrypted Plaintext:";
        cin >> input;
        string output(input.length(), '*');
        cout << "Please enter your key (1-26): ";
        cin >> key;
        for(int i=0; i<input.length(); i++)
        {
            for(int j=0; j<26; j++)
            {
                if(input[i] == Letters[j])
                {
                    TempDumpJ = j;
                }
            }

            LoopInteger = i;

            output[i] = Letters[(TempDumpJ-key)%26];
        }
        //cout << output << endl;
        return output;
    }
    return 0;
}
