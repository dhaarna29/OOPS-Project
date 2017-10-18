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
    cout<<"Enter Username: ";
    cin>>username;
    cout<<"Enter a Password: "; //will add the details of the password later for eg. 8 letter or lowercase and shit
    cin>>password;
}


