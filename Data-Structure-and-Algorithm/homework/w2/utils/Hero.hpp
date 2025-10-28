#include <iostream>
#include <string>

using namespace std;

class Hero{

    private:
        // Define all the attributes here...
        // [ your code ]
        string name;
        int health;
        int armor;
        int power;
        string weapon;
        
    public:
        // Define the constructor and methods here ...
        Hero(string name, int health, int armor, int power, string weapon){
            // assign each attributes' value from constructor param here...
            // [ your code ]
            this->name = name;
            this->health = health;
            this->armor = armor;
            this->power = power;
            this->weapon = weapon;

        }
    
        void info(){
            // process display hero info here...
            // [ your code ]
            cout<<"Knight : "<< name << endl;
            cout<<"Health : "<< health << endl;
            cout<<"armor : "<< armor << endl;
            cout<<"power : "<< power << endl;
            cout<<"weapon : "<< weapon << endl;

        }

        void strike(Hero& enemy){
            // process the strike logic here...
            // you can add the narative text as well (optional)
            // [ your code ]

            cout<< "Joi mayyy!! " << name << " yk " <<  weapon << " tv vai ah " << enemy.name << endl;

            int remainingPower = power;

            if(enemy.armor > 0) {
                if( remainingPower >= enemy.armor ) {
                    remainingPower -= enemy.armor;
                    enemy.armor = 0;
                } else {
                    enemy.armor -= remainingPower;
                    remainingPower = 0;
                }
            }

            enemy.health -= remainingPower;
            if(enemy.health < 0) enemy.health = 0;

            cout << enemy.name << " now has " << enemy.health << " HP and " << enemy.armor << " armor left." << endl;

        }

        string getName() {
            // this won't eerror when you create the name attribute
            return name;
        }

        // getter methods
        int getHealth() {
            // this won't error when you create the health attribute
            return health;
        }

        int getArmor() {
            // this won't error when you create the armor attribute
            return armor;
        }

        int getPower() {
            // this won't error when you create the power attribute
            return power;
        }
};