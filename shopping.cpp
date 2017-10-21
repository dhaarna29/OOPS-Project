#include<iostream>
#include "shopping.h"

using namespace std;

shopping::shopping()
{
    //ctor
}

shopping::~shopping()
{
    //dtor
}

void shopping::display()
{
    cout<<"PHONE 1 (Matte Black)\n";
    cout<<"Rs. 2999\nYou save 10%\n";
    cout<<"8MP primary camera and 5MP front facing camera\n";
    cout<<"2GB RAM, 16GB internal memory expandable up to 32GB and dual SIM (micro+micro)\n";

    cout<<"PHONE 2 (Glossy Grey)\n";
    cout<<"Rs. 4999\nYou save 17%\n";
    cout<<"10MP primary camera and 8MP front facing camera\n";
    cout<<"3GB RAM, 32GB internal memory with micro SD card\n";

    cout<<"PHONE 3 (Cream Pie)\n";
    cout<<"Rs. 7999\n";
    cout<<"14MP primary camera and 6MP front facing camera\n";
    cout<<"4GB RAM, 64GB internal memory expandable up to 128GB with micro SD card\n";

    cout<<"PHONE 2 (Gold)\n";
    cout<<"Rs. 9999\nYou save 22%\n";
    cout<<"10MP primary camera and 8MP front facing camera\n";
    cout<<"3GB RAM, 32GB internal memory with Hybrid SIM slot: Supports nano SIM / Micro SIM / MicroSD card\n";
}


