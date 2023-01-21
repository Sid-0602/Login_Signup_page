#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

void login();
void registration();
void forgot();

int main()
{

    int c;
    cout << "\t\t\t____________________________________________________\n\n\n";
    cout << "\t\t\t                    **Welcome to Login Page **         \n\n\n";
    cout << "\t\t\t___________________      MENU CHOICE   _________________\n\n\n";
    cout << "                                                                 \n\n";
    cout << "\t|   Press 1 to LOGIN            |" << endl;
    cout << "\t| Press 2 to REGISTER            |" << endl;
    cout << "\t| Press 3 to FORGOT PASSWORD         |" << endl;
    cout << "\t| Press 4 to EXIT                     |" << endl;
    cout << "\n\t\t\t  Please enter your choice:             ";

    cin >> c;
    cout << endl;

    switch (c)
    {
    case 1:
        login();
        break;
    case 2:
        registration();
        break;
    case 3:
        forgot();
        break;
    case 4:
        cout << "You have Exited!! Thank you!!";
        break;
    default:
        system("clear screen"); // everytime code is executed, it will clear up the screen.
        cout << "\t\t\t Enter a valid Input: \n"
             << endl;
        main();
    }
}

void login()
{
    int count;
    string userID, password, id, pass;
    system("cls");
    cout << "Pleas enter the username and Password: " << endl;
    cout << "\t\t\t USERNAME ";
    cin >> userID;
    cout << "\t\t\t PASSWORD: ";
    cin >> password;

    // check if username and password is already present in records.

    ifstream input("records.txt");
    while (input >> id >> pass)
    {
        if (id == userID && pass == password)
        {
            count = 1;
            system("cls");
        }
    }
    input.close();

    if (count == 1)
    {
        cout << userID << "\n LOGIN IS SUCCESSFUL!! \n THANK YOU! \n";
        main();
    }
    else
    {
        cout << "\n !! LOGIN ERROR !! \n Please check your username and password! \n";
        main();
    }
}

void registration()
{
    string ruserID, rpassword, rID, rpass;
    system("cls");
    cout << "\t\t\t Enter the USername: ";
    cin >> ruserID;
    cout << "\t\t\t Enter the password: ";
    cin >> rpassword;

    // writing inside the file:

    ofstream f1("records.txtx", ios::app);
    f1 << ruserID << ' ' << rpassword << endl;
    system("cls");
    cout << "\n\t\t\t REGISTRATION SUCCESSFUL!! \n";
    main();
}

void forgot()
{
    int option;
    system("cls");
    cout << "\t\t\t You forget the password? \n";
    cout << "Press 1 tp search your ID by username" << endl;
    cout << " Press 2 to go back to main menu" << endl;
    cout << "\t\t\t ENTER YOUR CHOICE: ";
    cin >> option;
    switch (option)
    {
    case 1:
    {
        int count = 0;
        string suserID, sID, spass;
        cout << "\n\t\t\t ENTER THE CORRECT USERNAME: ";
        cin >> suserID;

        ifstream f2("records.txt");
        while (f2 >> sID >> spass)
        {
            if (sID == suserID)
            {
                count = 1;
            }
            f2.close();
            if (count == 1)
            {
                cout << "\n\n Your Account is found! \n";
                cout << "\n\n Your passwors is: " << spass;
                main();
            }
            else
            {
                cout << "SORRY ACCOUNT NON-EXISTANT!! \n";
                main();
            }
        }
    }

    case 2:
    {
        main();
    }
    default:
        cout << "\t\t\t WRONG INPUT!! TRY AGAIN! " << endl;
        forgot();
    }
}
