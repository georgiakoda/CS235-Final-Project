/*
CSCI235 Spring 2024
Project 4 - MycoMorsels
Georgina Woo
Dec 24 2023
Ghoul.cpp implements the constructors and private and public functions of the Ghoul class
*/

#include "Ghoul.hpp"

Ghoul::Ghoul() :  decay_(0), faction_(NONE), transformation_(false)
{
    setCategory(UNDEAD); 
}

Ghoul::Ghoul(const std::string& name, Category category, int hitpoints, int level, bool tame, int decay, Faction faction, bool transformation) : Creature(name, category, hitpoints, level, tame)
{
    if(!setDecay(decay))
    {
        decay_ = 0;
    }
    faction_ = faction;
    transformation_ = transformation;
}

int Ghoul::getDecay() const
{
    return decay_;
}

bool Ghoul::setDecay(const int& decay)
{
    if(decay >= 0)
    {
        decay_ = decay;
        return true;
    }
    else
    {
        return false;
    }
}

std::string Ghoul::getFaction() const
{
    switch(faction_)
    {
        case FLESHGORGER:
            return "FLESHGORGER";
        case SHADOWSTALKER:
            return "SHADOWSTALKER";
        case PLAGUEWEAVER:
            return "PLAGUEWEAVER";
        default:
            return "NONE";
    }
}

void Ghoul::setFaction(const Faction& faction)
{
    faction_ = faction;
}

bool Ghoul::getTransformation() const
{
    return transformation_;
}

void Ghoul::setTransformation(const bool& transformation)
{
    transformation_ = transformation;
}


/**
    @post     : displays Ghoul data in the form:
    GHOUL - [NAME]\n
    CATEGORY: [CATEGORY]\n
    HP: [HITPOINTS]\n
    LVL: [LEVEL]\n
    TAME: [TAME]\n
    DECAY: [DECAY]\n
    FACTION: [FACTION]\n
    IT [CAN/CANNOT] TRANSFORM\n"
    
    Example:
    
*/
void Ghoul::display() const
{
    std::cout << "GHOUL - " << getName() << std::endl;
    std::cout << "CATEGORY: " << getCategory() << std::endl;
    std::cout << "HP: " << getHitpoints() << std::endl;
    std::cout << "LVL: " << getLevel() << std::endl;
    std::cout << "TAME: " << (isTame() ? "TRUE" : "FALSE") << std::endl;
    std::cout << "DECAY: " << getDecay() << std::endl;
    std::cout << "FACTION: " << getFaction() << std::endl;
    std::cout << "IT " << (getTransformation() ? "CAN" : "CANNOT") << " TRANSFORM" << std::endl;
}


bool Ghoul::eatMycoMorsel()
{
    if(getCategory() == "UNDEAD")
    {
        setTame(true);
        setHitpoints(getHitpoints() + 1);
        return false;
    }
    else if(getFaction() == "FLESHGORGER")
    {
        if(isTame())
        {
            setTame(false);
            return false;
        }
        else
        {
            return true;
        }
    }
    else if(getFaction() == "SHADOWSTALKER")
    {
        if(isTame())
        {
            if(getHitpoints() == 1)
            {
                setTame(false);
            }
            else
            {
                setHitpoints(getHitpoints() - 1);
            }
            return false;
        }
        else
        {
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

* Here are the attacks for the Ghoul:

* 

* 1: Attack name: BITE

*   if ALIEN: 4 PHYSICAL

*   if MYSTICAL: 

*      if FLESHGORGER: 2 PHYSICAL

*      if SHADOWSTALKER: 2 PHYSICAL, 1 VOID

*      if PLAGUEWEAVER: 2 PHYSICAL, 1 POISON

*      if NONE: 2 PHYSICAL

*  if UNDEAD: 2 PHYSICAL, 1 POISON

*  if UNKNOWN: 2 PHYSICAL

* 

* 2: 

*  if FLESHGORGER/NONE: 

*      Attack name: CLAW

*      2 PHYSICAL

*  if SHADOWSTALKER:

*     Attack name: SLASH

*     2 PHYSICAL, 1 VOID

* if PLAGUEWEAVER:

*    Attack name: INFECT

*    2 PHYSICAL, 1 POISON

* 

* 3:

*  if FLESHGORGER/NONE:

*     Attack name: FLY SWARM

*     3 PHYSICAL

* if SHADOWSTALKER:

*     Attack name: SHROUD OF DARKNESS

*     2 PHYSICAL, 1 VOID

* if PLAGUEWEAVER:

*     Attack name: PLAGUE CLOUD

*     2 PHYSICAL, 1 POISON

*  

*/
void Ghoul::addAttack(const int& choice) {
    
    Attack new_attack;

    switch(choice) {
        case 1: // BITE
            new_attack.name_ = "BITE";

            if (getCategory() == "ALIEN") {

                new_attack.damage_.push_back(4);
                new_attack.type_.push_back("PHYSICAL");

            } else if (getCategory() == "MYSTICAL") {

                if (getFaction() == "FLESHGORGER"){

                    new_attack.damage_.push_back(2);
                    new_attack.type_.push_back("PHYSICAL");
                   

                } else if (getFaction() == "SHADOWSTALKER") {

                    new_attack.damage_.push_back(2);
                    new_attack.type_.push_back("PHYSICAL");
                    

                    new_attack.damage_.push_back(1);
                    new_attack.type_.push_back("VOID");


                } else if (getFaction() == "PLAGUEWEAVER") {


                    new_attack.damage_.push_back(2);
                    new_attack.type_.push_back("PHYSICAL");
                 

                    new_attack.damage_.push_back(1);
                    new_attack.type_.push_back("POISON");
                } else if (getFaction() == "NONE") { 
                        
                    new_attack.damage_.push_back(2);
                    new_attack.type_.push_back("PHYSICAL");
              
                } else {
                    break;
                }

            } else if (getCategory() == "UNDEAD") {

                new_attack.damage_.push_back(2);
                new_attack.type_.push_back("PHYSICAL");
                

                new_attack.damage_.push_back(1);
                new_attack.type_.push_back("POISON");

            } else if (getCategory() == "UNKNOWN") {
                
                new_attack.damage_.push_back(2);
                new_attack.type_.push_back("PHYSICAL");
               
            } else{
                break;
            }
            break;

        case 2: // Second attack
            if (getFaction() == "FLESHGORGER" || getFaction() == "NONE") {
                new_attack.name_ = "CLAW";
                new_attack.damage_.push_back(2);
                new_attack.type_.push_back("PHYSICAL");

            } else if (getFaction() == "SHADOWSTALKER") {
                new_attack.name_ = "SLASH";
                new_attack.damage_.push_back(2);
                new_attack.type_.push_back("PHYSICAL");
                new_attack.damage_.push_back(1); 
                new_attack.type_.push_back("VOID");

            } else if (getFaction() == "PLAGUEWEAVER") {

                new_attack.name_ = "INFECT";

                new_attack.damage_.push_back(2);
                new_attack.type_.push_back("PHYSICAL");

                new_attack.damage_.push_back(1);
                new_attack.type_.push_back("POISON");
            } else {
                break;
            }
            break;

        case 3: // Third attack
            if (getFaction() == "FLESHGORGER" || getFaction() == "NONE") {
                new_attack.name_ = "FLY SWARM";
                new_attack.damage_.push_back(3);
                new_attack.type_.push_back("PHYSICAL");

            } else if (getFaction() == "SHADOWSTALKER") {
                new_attack.name_ = "SHROUD OF DARKNESS";
                new_attack.damage_.push_back(2);
                new_attack.type_.push_back("PHYSICAL");
                new_attack.damage_.push_back(1); 
                new_attack.type_.push_back("VOID");

            } else if (getFaction() == "PLAGUEWEAVER") {
                new_attack.name_ = "PLAGUE CLOUD";
                
                new_attack.damage_.push_back(2);
                new_attack.type_.push_back("PHYSICAL");
                new_attack.damage_.push_back(1);
                new_attack.type_.push_back("POISON");
                
            } else {
                break;
            }
            
            break;
            default:
                break;

    }


    Creature::addAttack(new_attack);

    
}


/**

  @post     : displays the attacks of the Ghoul in the form:

  [GHOUL] Choose an attack (1-3):\n1: BITE\t\t2: CLAW\t\t3: CLOUD OF DOOM\n

*/
void Ghoul::displayAttacks() {
    
    std::cout << "[GHOUL] Choose an attack (1-3):\n";
    std::cout << "1: BITE\t\t" << "2: CLAW\t\t" << "3: CLOUD OF DOOM\n";
    
    
}
