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
