//standard i/o & string libraries
#include <iostream>
#include <string>
//library needed to deal with regular expressions
//library required by Sleep() & SetConsoleTitleA 
#include <Windows.h>
//instead of importing all of "std" namespace, only the functions required by the program are imported
using std::cout;//output
using std::cin;//input
using std::endl;//go to new line
using std::string;//string data type

class DFA

{
private:
    //declaring and initializing states
    static const int q1 = 1;//Start state
    static const int q2 = 2;//alphabet
    static const int q3 = 3;//@
    static const int q4 = 4;//alphabet
    static const int q5 = 5;//.
    static const int q6 = 6;//c
    static const int q7 = 7;//o
    static const int q8 = 8;//m => accept state
    static const int q9 = 9;//trap
    //store current state
    int currentState;
    //function to process characters of string one by one and return the state where it's currently being processed
    static int cases(int x, char y)
    {
        switch (x)
        {
        case q1:
            //first state, go trap if there's an "@" or ".", else go state 2
            switch (y)
            {
            case '@':
                return q9;
            case '.':
                return q9;
            case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g':
            case 'h': case 'i': case 'j': case 'k': case 'l': case 'm': case 'n':
            case 'o': case 'p': case 'q': case 'r': case 's': case 't': case 'u':
            case 'v': case 'w': case 'x': case 'y': case 'z':
                return q2;
            default:
                return q9;
            }
        case q2:
            switch (y)
            {
                //if it's a charcter, stay in state 2
            case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g':
            case 'h': case 'i': case 'j': case 'k': case 'l': case 'm': case 'n':
            case 'o': case 'p': case 'q': case 'r': case 's': case 't': case 'u':
            case 'v': case 'w': case 'x': case 'y': case 'z':
                return q2;
                //if after the alphabet there's an '@'
                //move to state 3
            case '@':
                return q3;
                //else if there's a "." => return state 1 
            case '.':
                return 1;
            default:
                return q9;
            }
            //state 3
        case q3:
            switch (y)
            {
                //if the "@" is followed by an alphabet go to q4
            case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g':
            case 'h': case 'i': case 'j': case 'k': case 'l': case 'm': case 'n':
            case 'o': case 'p': case 'q': case 'r': case 's': case 't': case 'u':
            case 'v': case 'w': case 'x': case 'y': case 'z':
                return q4;
                //else if there exists anohter "@" or the "@" is followed by a "." or any other illegal character => move to trap 
            case '.':
                return q9;
                //go trap is there's an @
            case '@':
                return q9;
            default:
                return q9;
            }
            //case 4
        case q4:
            //if there's an alphabet, stay in q4
            switch (y)
            {
            case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g':
            case 'h': case 'i': case 'j': case 'k': case 'l': case 'm': case 'n':
            case 'o': case 'p': case 'q': case 'r': case 's': case 't': case 'u':
            case 'v': case 'w': case 'x': case 'y': case 'z':
                return q4;
                //if there's a "." => go next state (state 5)
            case '.':
                return q5;
                //go trap is there's an @
            case '@':
                return q9;
            default:
                return q9;
            }
            //if the next character after the "." is a "c" => go to q6 , go back to q4
        case q5: switch (y)
        {
        case 'a': case 'b': case 'd': case 'e': case 'f': case 'g':
        case 'h': case 'i': case 'j': case 'k': case 'l': case 'm': case 'n':
        case 'o': case 'p': case 'q': case 'r': case 's': case 't': case 'u':
        case 'v': case 'w': case 'x': case 'y': case 'z':
            return q4;
        case 'c':
            return q6;
        default:
            return q9;
        }
        case q6: switch (y)
        {
            //if the character is not 'o' go back to q4
        case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g':
        case 'h': case 'i': case 'j': case 'k': case 'l': case 'm': case 'n':
        case 'p': case 'q': case 'r': case 's': case 't': case 'u':
        case 'v': case 'w': case 'x': case 'y': case 'z':
            return q4;
            //move to q7 if it's an 'o'
        case 'o':
            return q7;
            //return to q5 if there's a '.'
        case '.':
            return q5;
        default:
            return q9;
        }
               //if the letter is m => go to accept state, else return q4
        case q7: switch (y)
        {
        case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g':
        case 'h': case 'i': case 'j': case 'k': case 'l': case 'n':
        case 'p': case 'q': case 'r': case 's': case 't': case 'u':
        case 'v': case 'w': case 'x': case 'y': case 'z':
            return q4;
            //go to final state if there's an 'm'
        case 'm':
            return q8;
            //return to q5 if there's a '.'
        case '.':
            return q5;
        default:
            return q9;
        }
               //when in state 7, if the next character is not m, return to state 4
        case q8: switch (y)
        {
        case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g':
        case 'h': case 'i': case 'j': case 'k': case 'l': case 'm': case 'n':
        case 'o': case 'p': case 'q': case 'r': case 's': case 't': case 'u':
        case 'v': case 'w': case 'x': case 'y': case 'z':
            return q4;
            //else if there's a '.' ,return to q5
        case '.':
            return q5;
        default:
            return q9;
        }
        default:
            return q9;
        }
    }

public:

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    void setState()
    {
        //starts traversing states from q1 as start state
        currentState = q1;
    }
    //void function to check and print if email is accepted
    void chkDfa(string email)
    {

        bool isAccepted = false;
        for (size_t i = 0; i < email.length(); i++)
        {
            char s = email[i];
            currentState = cases(currentState, s);
            cout << "Character [" << s << "] processed in state: [" << currentState << "]" << endl;
            //Accept state is q7, if the current state stops at q7, print that email is accepted by the dfa
            if (currentState == q8)
            {
                
                isAccepted = true;
                
            }
            else
            {
                
                isAccepted = false;

            }
        }
        //if rejected, print reject
        if (!isAccepted)
        {
            SetConsoleTextAttribute(h, 4);
            cout << "Rejected Email Format" << endl;
            SetConsoleTextAttribute(h, 7);
        }
        //else print accepted
        else
        {
            SetConsoleTextAttribute(h, 2);
            cout << "Accepted Email Format" << endl;
            SetConsoleTextAttribute(h, 7);
        }
        cout << "" << endl;
    }
    void stdName()
    {
        /*
            printing my name & ID	:O
        */
        cout << " _____             _            _  ______             _____                    ___       _____  _          " << endl;
        Sleep(500);
        cout << "/  __ \\           | |          | | | ___ \\        _  |_   _|                  / _ \\     /  ___|| |         " << endl;
        Sleep(500);
        cout << "| /  \\/  ___    __| |  ___   __| | | |_/ / _   _ (_)   | |   ___  _ __ ___   / /_\\ \\    \\ `--. | | __ _ __ " << endl;
        Sleep(500);
        cout << "| |     / _ \\  / _` | / _ \\ / _` | | ___ \\| | | |      | |  / __|| '_ ` _ \\  |  _  |     `--. \\| |/ /| '__|" << endl;
        Sleep(500);
        cout << "| \\__/\\| (_) || (_| ||  __/| (_| | | |_/ /| |_| | _   _| |_ \\__ \\| | | | | | | | | | _  /\\__/ /|   < | |   " << endl;
        Sleep(500);
        cout << " \\____/ \\___/  \\__,_| \\___| \\__,_| \\____/  \\__, |(_)  \\___/ |___/|_| |_| |_| \\_| |_/(_) \\____/ |_|\\_\\|_|   " << endl;
        Sleep(500);
        cout << "                                            __/ |                                                          " << endl;
        Sleep(500);
        cout << "                                           |___/ ID: 10118075                                                     " << endl;
        Sleep(500);
        cout << endl;
    }
};
int main()
{
    DFA d1;
    char choice;
    string email;
    int counter = 1;
    while (1)
    {
        cout << "Enter 'y' To Check An Email Or 'n' To Exit: ";
        cin >> choice;
        if (choice == 'y')
        {
            cout << "Enter An Email: ";
            cin >> email;
            cout << endl;
            cout << "Email [" << counter << "] is: [" << email << "] " << endl << endl;
            d1.setState();
            d1.chkDfa(email);
            counter++;
        }
        else if (choice == 'n')
        {
            cout << "End program\n\n\n" << endl;
            d1.stdName();
            exit(0);
        }
        else
            cout << "Invalid Input\n" << endl;

    }
}

