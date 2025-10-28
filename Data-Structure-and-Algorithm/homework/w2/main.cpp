#include <iostream>
#include "utils/Hero.hpp" // this is custom include header file

int main(){
    // implement your code to test the functional of Hero class here ...
    // [This will score by automate testing too.]

    Hero Knight("Richard", 50, 50, 25, "Sword");
    Hero Enemy("Rascal", 40, 15, 10, "Bow and Arrow");

    cout<< "Hero Stats"<< endl;
    Knight.info();
    cout << endl;
    Enemy.info();
    cout<< endl;

    cout<<"Battle begins!! (Rascal is ambushing Richard so it makes sense that he will attack first)" << endl;
    cout<<endl;
    Enemy.strike(Knight);
    cout<<endl;
    cout<<"Now Richard's turn" << endl;
    cout<<endl;
    Knight.strike(Enemy);

    return 0;
}