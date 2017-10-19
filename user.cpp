#include "user.h"

user::user()
{
    //ctor
}

user::~user()
{
    //dtor
}

void user::getdetails()
{
    cout<<"Enter your details\n";
    cout<<"Enter Username: ";
    cin>>username;
    cout<<"\nEnter a Password: "; //will add the details of the password later for eg. 8 letter or lowercase and shit
    cin>>password;
}


