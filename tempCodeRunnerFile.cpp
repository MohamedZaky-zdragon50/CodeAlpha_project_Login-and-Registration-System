#include<iostream>
#include <fstream>
#include <string>

using namespace std;

void registerUser ()
{
    string username , Password;
    cout << "enter your username: " ;
    cin >> username ;
    cout << "enter your Password: " ;    
    cin >> Password ;


 ofstream file ; 
 file.open (username + ".txt");
 file << username << endl << Password ;
 file.close();

cout << "Registration Successful!\n";

};




bool loginuser ()
{
    string username , Password , storedUser , storedPass ;
    cout << "enter your username: " ;
    cin >> username;
    cout << "enter your Password: ";
    cin >> Password;

    ifstream file (username + ".txt");
    if(file.is_open())
    {
     getline(file , storedUser );
     getline(file , storedPass );
    
     if (username == storedUser && Password == storedPass)
        {
        cout << "Login Successful!\n";
        return true ;
        }
     else
     {
         cout << "Invalid Username or Password.\n";
         return false ;
     }
    
    }

    else
    {
        cout << "User does not exist.\n";
        return false ;
    }


};



int main()
{
     cout << "Welcome to the User Management System!\n";
    cout << "Please choose an option: \n";
    cout << "1. Register\n2. Login\nEnter choice: ";
 
    int choice ;
    cin >> choice ;

    if (choice == 1)
    {
        registerUser ();
    }
    else if (choice == 2)
    {
        loginuser ();
    }
    else 
    {
        cout << "Invalid choice.\n";
    }

return 0 ;
};


