//Test File for Project 6. Georgia Koda 2023.

#include "Cavern.hpp"

int main(){
    Cavern cavern("creatures.csv");


//UNKNOWN STACK

cavern.initializeUnknownStack();
std::stack<Creature*> ukStack = cavern.getUnknownStack();
cavern.setAttacks(ukStack);

while (!ukStack.empty()) {
    Creature* critter = ukStack.top();
    ukStack.pop();
    std::cout << critter->getName() << " Attacks: " << std::endl;
    std::queue<Attack> attackQ = critter->getAttackQueue();
   
    while (!attackQ.empty()){
        Attack a = attackQ.front();
        attackQ.pop();

        std::cout << "Name: " << a.name_ << std::endl;
        std::cout << "Type: ";
        for (int i = 0; i < a.type_.size(); i++){
            std::cout << a.type_[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "Damage: ";
        for (int i = 0; i < a.damage_.size(); i++){
            std::cout << a.damage_[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "\n";
    }
}


//ALIEN STACK

cavern.initializeAlienStack();
std::stack<Creature*> alienStack = cavern.getAlienStack();
cavern.setAttacks(alienStack);

while (!alienStack.empty()) {
    Creature* critter = alienStack.top();
    alienStack.pop();
    std::cout << critter->getName() << " Attacks: " << std::endl;
    std::queue<Attack> attackQ = critter->getAttackQueue();
   
    while (!attackQ.empty()){
        Attack a = attackQ.front();
        attackQ.pop();
        std::cout << "Name: " << a.name_ << std::endl;
        std::cout << "Type: ";
        for (int i = 0; i < a.type_.size(); i++){
            std::cout << a.type_[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "Damage: ";
        for (int i = 0; i < a.damage_.size(); i++){
            std::cout << a.damage_[i] << " ";
        }
        std::cout << std::endl;
    }
}



//MYSTICAL STACK

cavern.initializeMysticalStack();
std::stack<Creature*> mStack = cavern.getMysticalStack();
cavern.setAttacks(mStack);

while (!mStack.empty()) {
    Creature* critter = mStack.top();
    mStack.pop();
    std::cout << critter->getName() << " Attacks: " << std::endl;
    std::queue<Attack> attackQ = critter->getAttackQueue();
   
    while (!attackQ.empty()){
        Attack a = attackQ.front();
        attackQ.pop();
        std::cout << "Name: " << a.name_ << std::endl;
        std::cout << "Type: ";
        for (int i = 0; i < a.type_.size(); i++){
            std::cout << a.type_[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "Damage: ";
        for (int i = 0; i < a.damage_.size(); i++){
            std::cout << a.damage_[i] << " ";
        }
        std::cout << std::endl;
    }
}


//UNDEAD STACK

cavern.initializeUndeadStack();
std::stack<Creature*> udStack = cavern.getUndeadStack();
cavern.setAttacks(udStack);

while (!udStack.empty()) {
    Creature* critter = udStack.top();
    udStack.pop();
    std::cout << critter->getName() << " Attacks: " << std::endl;
    std::queue<Attack> attackQ = critter->getAttackQueue();
   
    while (!attackQ.empty()){
        Attack a = attackQ.front();
        attackQ.pop();
        std::cout << "Name: " << a.name_ << std::endl;
        std::cout << "Type: ";
        for (int i = 0; i < a.type_.size(); i++){
            std::cout << a.type_[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "Damage: ";
        for (int i = 0; i < a.damage_.size(); i++){
            std::cout << a.damage_[i] << " ";
        }
        std::cout << std::endl;
    }
}



return 0;
}