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