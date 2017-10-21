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

int main()
{
    int i;
    shopping phone[4];
    phone[0].name = "PHONE 1";
    phone[0].colour = "Matte Black";
    phone[0].cost = "Rs. 2999";
    phone[0].camera = "8MP primary camera and 5MP front facing camera";
    phone[0].memory = "2GB RAM, 16GB internal memory expandable up to 32GB and dual SIM (micro+micro)";

    phone[1].name = "PHONE 2";
    phone[1].colour = "Glossy Grey";
    phone[1].cost = "Rs. 4999";
    phone[1].camera = "10MP primary camera and 8MP front facing camera";
    phone[1].memory = "3GB RAM, 32GB internal memory with micro SD card";

    phone[2].name = "PHONE 3";
    phone[2].colour = "Cream Pie";
    phone[2].cost = "Rs. 7999";
    phone[2].camera = "14MP primary camera and 6MP front facing camera";
    phone[2].memory = "4GB RAM, 64GB internal memory expandable up to 128GB with micro SD card";


    phone[3].name = "PHONE 4";
    phone[3].colour = "Gold";
    phone[3].cost = "Rs. 9999";
    phone[3].camera = "10MP primary camera and 8MP front facing camera";
    phone[3].memory = "3GB RAM, 32GB internal memory with Hybrid SIM slot: Supports nano SIM / Micro SIM / MicroSD card";

    cout<<"Phones available right now are\n\n";

    for(int i = 0; i < 4; i++)
    {
        cout<<phone[i].name<<"\n";
        cout<<phone[i].colour<<"\n";
        cout<<phone[i].cost<<"\n";
        cout<<phone[i].camera<<"\n";
        cout<<phone[i].memory<<"\n\n";
    }

    return 0;
}
