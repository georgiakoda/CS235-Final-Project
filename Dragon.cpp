/*
CSCI235 Spring 2024
Project 4 - MycoMorsels
Georgina Woo
Dec 24 2023
Dragon.cpp implements the constructors and private and public functions of the Dragon class
*/

#include "Dragon.hpp"

Dragon::Dragon() : element_(NONE), number_of_heads_(1), flight_(false)
{
    setCategory(MYSTICAL); 
    
}


Dragon::Dragon(const std::string& name, Category category, int hitpoints, int level, bool tame, Element element, int number_of_heads, bool flight) : Creature(name, category, hitpoints, level, tame)
{
    element_ = element;
    if(!setNumberOfHeads(number_of_heads))
    {
        number_of_heads_ = 1;
    }
    flight_ = flight;
}

std::string Dragon::getElement() const
{
    switch(element_)
    {
        case FIRE:
            return "FIRE";
        case WATER:
            return "WATER";
        case EARTH:
            return "EARTH";
        case AIR:
            return "AIR";
        default:
            return "NONE";
    }
}

void Dragon::setElement(const Element& element)
{
    element_ = element;
}

int Dragon::getNumberOfHeads() const
{
    return number_of_heads_;
}

bool Dragon::setNumberOfHeads(const int& number_of_heads)
{
    if(number_of_heads > 0)
    {
        number_of_heads_ = number_of_heads;
        return true;
    }
    else
    {
        return false;
    }
}

bool Dragon::getFlight() const
{
    return flight_;
}

void Dragon::setFlight(const bool& flight)
{
    flight_ = flight;
}


void Dragon::display() const
{
    std::cout << "DRAGON - " << getName() << std::endl;
    std::cout << "CATEGORY: " << getCategory() << std::endl;
    std::cout << "HP: " << getHitpoints() << std::endl;
    std::cout << "LVL: " << getLevel() << std::endl;
    std::cout << "TAME: " << (isTame() ? "TRUE" : "FALSE") << std::endl;
    std::cout << "ELEMENT: " << getElement() << std::endl;
    std::cout << "HEADS: " << getNumberOfHeads() << std::endl;
    std::cout << "IT " << (getFlight() ? "CAN" : "CANNOT") << " FLY" << std::endl;
}



bool Dragon::eatMycoMorsel()
{
    if(getCategory() == "UNDEAD")
    {
        setTame(true);
        setHitpoints(getHitpoints() + 1);
        return false;
    }
    else if(getCategory() == "ALIEN")
    {
        setHitpoints(getHitpoints() + 1);
        return false;
    }
    else if(getCategory() == "MYSTICAL")
    {
        if(getElement() == "FIRE" || getElement() == "EARTH")
        {
            setHitpoints(getHitpoints() + 1);
            return false;
        }
        else if(getHitpoints() == 1)
        {
            return true;
        }
        else
        {
            setHitpoints(getHitpoints() - 1);
            setTame(false);
            return false;
        }
    }
    else
    {
        return false;
    }
}


//NEW PROJECT 6

/**

  * @param: A const reference to int corresponding to the attack to be added to the attack queue.

  * @post: Adds an attack to the attack queue based on the int parameter.

  * Here are the attacks for the Dragon:

  

* 1: Attack name: BITE

*      if ALIEN: 4 PHYSICAL

*      if MYSTICAL: 2 PHYSICAL, and additional damage of 1 [FIRE/WATER/EARTH/AIR] if the Dragon has an elemental affinity of FIRE, WATER, EARTH, or AIR)

*      if UNDEAD: 2 PHYSICAL, 1 POISON

*      if UNKNOWN: 2 PHYSICAL


* 2: Attack name: STOMP

*      if ALIEN: 2 PHYSICAL

*      if MYSTICAL: 1 PHYSICAL, and additional damage of 1 [FIRE/WATER/EARTH/AIR] if the Dragon has an elemental affinity of FIRE, WATER, EARTH, or AIR)

*      if UNDEAD: 1 PHYSICAL, 1 POISON

*      if UNKNOWN: 1 PHYSICAL


* 3: Attack name: [ELEMENTAL BREATH/BAD BREATH], where the name is ELEMENTAL BREATH if the Dragon has an elemental affinity, otherwise it is BAD BREATH

*      if ALIEN: 6 [POISON/FIRE/WATER/EARTH/AIR], where the damage type is the Dragon's elemental affinity if it has one, otherwise it is POISON

*      if MYSTICAL: 3 [POISON/FIRE/WATER/EARTH/AIR], where the damage type is the Dragon's elemental affinity if it has one, otherwise it is POISON

*      if UNDEAD: 3 [POISON/FIRE/WATER/EARTH/AIR], 1 POISON. The damage types and amount are added to the vector as two separate entries, even if both entries are POISON type.

*      if UNKNOWN: 3 [POISON/FIRE/WATER/EARTH/AIR] where the damage type is the Dragon's elemental affinity if it has one, otherwise it is POISON  

*/
void Dragon::addAttack(const int& choice) {

    Attack new_attack;
    switch (choice) {
        case 1: // BITE
            new_attack.name_ = "BITE";

            if (getCategory() == "ALIEN") {

                new_attack.damage_.push_back(4);
                new_attack.type_.push_back("PHYSICAL");
                

            } else if (getCategory() == "MYSTICAL") {

                new_attack.damage_.push_back(2);
                new_attack.type_.push_back("PHYSICAL");
                
                
                if (getElement() == "FIRE" || getElement() == "EARTH" || getElement() == "AIR" || getElement() == "WATER") {
                    new_attack.damage_.push_back(1);
                    new_attack.type_.push_back(getElement());
                 }
                
            } else if (getCategory() == "UNDEAD") {

                new_attack.damage_.push_back(2);
                new_attack.type_.push_back("PHYSICAL");

                new_attack.damage_.push_back(1);
                new_attack.type_.push_back("POISON");
                
            } else if (getCategory() == "UNKNOWN") {

                new_attack.damage_.push_back(2);
                new_attack.type_.push_back("PHYSICAL");
                
             } else {
                break;
             }
            break;

        case 2: 
            new_attack.name_ = "STOMP";

            if (getCategory() == "ALIEN") {
                
                new_attack.damage_.push_back(2);
                new_attack.type_.push_back("PHYSICAL");
                

            } else if (getCategory() == "MYSTICAL") {
                new_attack.damage_.push_back(1);
                new_attack.type_.push_back("PHYSICAL");
                
                if (getElement() == "FIRE" || getElement() == "EARTH" || getElement() == "AIR" || getElement() == "WATER") {
                    new_attack.damage_.push_back(1);
                    new_attack.type_.push_back(getElement());
                } 

            } else if (getCategory() == "UNDEAD") {

                new_attack.damage_.push_back(1);
                new_attack.type_.push_back("PHYSICAL");

                new_attack.damage_.push_back(1);
                new_attack.type_.push_back("POISON");
                
            } else if (getCategory() == "UNKNOWN") { 
                new_attack.damage_.push_back(1);
                new_attack.type_.push_back("PHYSICAL");
                
            } else {
                break;
            }
            break;

        case 3: // ELEMENTAL BREATH / BAD BREATH
            if (getElement() == "FIRE" || getElement() == "EARTH" || getElement() == "AIR" || getElement() == "WATER") {
                new_attack.name_ = "ELEMENTAL BREATH";
            } else {
                new_attack.name_ = "BAD BREATH";
            }

            if (getCategory() == "ALIEN") {

                if (getElement() == "FIRE" || getElement() == "EARTH" || getElement() == "AIR" || getElement() == "WATER") {
                    new_attack.damage_.push_back(6);
                    new_attack.type_.push_back(getElement());
                                    
                } else {
                    new_attack.damage_.push_back(6);
                    new_attack.type_.push_back("POISON");
                }

            } else if (getCategory() == "MYSTICAL") {

                if (getElement() == "FIRE" || getElement() == "EARTH" || getElement() == "AIR" || getElement() == "WATER") {
                    
                    new_attack.damage_.push_back(3);
                    new_attack.type_.push_back(getElement());
                } else {
                    new_attack.damage_.push_back(3);
                    new_attack.type_.push_back("POISON");
                }


            } else if (getCategory() == "UNDEAD") {


                if (getElement() == "FIRE" || getElement() == "EARTH" || getElement() == "AIR" || getElement() == "WATER") {

                    new_attack.damage_.push_back(3);
                    new_attack.type_.push_back(getElement());

                } else {
                    new_attack.damage_.push_back(3);
                    new_attack.type_.push_back("POISON");
                }

                new_attack.damage_.push_back(1);
                new_attack.type_.push_back("POISON");
                

            } else if (getCategory() == "UNKNOWN") { // UNKNOWN
    
                if (getElement() == "FIRE" || getElement() == "EARTH" || getElement() == "AIR" || getElement() == "WATER") {
                    
                    new_attack.damage_.push_back(3);
                    new_attack.type_.push_back(getElement());
                } else {
                    new_attack.damage_.push_back(3);
                    new_attack.type_.push_back("POISON");
                    
                }
            } else {
                break;
            }
            break;
            default:
                break;

    }

    // Add the new attack to the queue
    Creature::addAttack(new_attack);

    
}

/**

  * @post:  displays the attacks of the Dragon in the form:

  *        [DRAGON] Choose an attack (1-3):\n1: BITE\t\t2: STOMP\t\t3: ELEMENTAL BREATH\n

  */
void Dragon::displayAttacks() {

    
    std::cout << "[DRAGON] Choose an attack (1-3):\n";
    std::cout << "1: BITE\t\t2: STOMP\t\t3: ELEMENTAL BREATH\n";
    
}
