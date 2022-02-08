//standard i/o & string libraries
#include <iostream>
#include <string>
//library needed to deal with regular expressions
//library required by Sleep() & SetConsoleTitleA 
#include <Windows.h>
//library required by system("CLS")
#include <cstdlib>
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
                //else if there's a "." => go trap
            case '.':
                return q9;
                //default state: any illegal char => move to trap 
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
            case '.': return q5;
            case '@': return q9;
            default: return q9;
            }
            //if the next character after the "." is a "c" => go next state , else go trap
        case q5: switch (y)
        {
        case 'c': return q6;
        default: return q9;
        }
               //if the next character after the "c" is an "o", move to next state,else go trap
               //if the next character after the "o" is an "m", move to next state,else go trap
        case q6: switch (y)
        {
        case 'o': return q7;
        default: return q9;
        }
               //if the final character in the email is "m", accept, else go trap
        case q7: switch (y)
        {
        case 'm': return q8;
        default: return q9;
        }
               //q8 accept state
        case q8: switch (y)
        {
        default: return q9;
        }
        default: return q9;
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
    //Change Console Title
    SetConsoleTitleA("Theory of Computation Project");
    //Variable to store the choice of the user when asked to repeat the program
    char repeat;
    //declaring a DFA
    DFA d1;
    do
    {
        //Clear Screen
        system("CLS");
        char choice;
        cout << "Do You Want To Proceed And Enter A String?\n\n";
        cout << "Enter Y or y to continue: ";
        cin >> choice;
        //switch statement based on the user's choice   
        switch (choice)
        {
            //if choice is yes, then program will proceed
        case 'Y':
        case 'y':
        {
            //variable to store number of emails
            int email_count;
            //variable to store emails
            string email;
            //user is asked about the number of emails to process
            cout << "Number of Emails You Want To Process: ";
            cin >> email_count;
            //while loop to process of the number of emails the user want
            int i = 0;
            while (i < email_count)
            {
                //user is asked to enter an email
                cout << "Enter An Email To Check: ";
                cin >> email;
                //printing the email
                cout << "Email [" << i << "] is [" << email << "] " << endl;
                //set start state to q1
                d1.setState();
                //check dfa
                d1.chkDfa(email);
                i++;

            }
            //user is asked if he/she wants to repeat the process
            cout << "Repeat Program?" << endl;
            cout << "Enter Y or y to Repeat: ";
            //user enters his choice
            cin >> repeat;
            //if the user chooses not to repeat, program will terminate in 3 seconds
            if (repeat != 'y' && repeat != 'Y')
            {
                //Clear Screen
                system("CLS");
                d1.stdName();
                cout << "\n\n";
                cout << "\nClosing in: ";
                for (int i = 3; i > 0; i--)
                {
                    cout << i << " ";
                    Sleep(1000);
                }
            }
            break;
        }
        //default switch case, user didn't want to use the program when asked
        default:
            //user is notified of his/her choice and asked to repeat the program or terminate
            cout << "\nYou've chosen not to use the program\n";
            cout << "\nDo you want to repeat the process?\n";
            cout << "Enter Y or y to continue: ";
            cin >> repeat;
            //if the user chooses not to repeat, program will terminate in 3 seconds
            if (repeat != 'y' && repeat != 'Y')
            {
                //Clear Screen
                system("CLS");
                d1.stdName();
                cout << "\n\n";
                cout << "\nClosing in: ";
                for (int i = 3; i > 0; i--)
                {
                    cout << i << " ";
                    Sleep(1000);
                }
            }
            break;
        }
        //end of do-while loop
    } while (repeat == 'y' || repeat == 'Y');
    return 0;
}