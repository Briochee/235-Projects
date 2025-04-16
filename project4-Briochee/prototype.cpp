//Character.hpp interface changes
virtual void display() const;
virtual void eatTaintedStew();

//Character.cpp implementation changes
void Character::display() const {
    std::cout << getName()
        << " is a Level " << getLevel() << " "
        << getRace() << "."
        << "\nVitality: " << getVitality()
        << "\nMax Armor: " << getArmor()
        << ((isEnemy()) ? "\nThey are an enemy." : "\nThey are not an enemy.") << std::endl;
}

//Barbarian.hpp interface change
//functions do not to be declared as virtual, implicit as overides
//override operation does not need to be used, impicit
    //virtual void display() const override;
    //virtual void eatTaintedStew() override;
void display() const;
void eatTaintedStew();

//Barbarian.cpp implementation changes
void Barbarian::display() const {
    //displays barbarian data as per project specifications
    std::cout << getName() << " is a Level "
        << getLevel() << " " << getRace() << " BARBARIAN."
        << "\nVitality: " << getVitality()
        << "\nArmor: " << getArmor()
        << ((isEnemy()) ? "\nThey are an enemy." : "\nThey are not an enemy.")
        << "\nMain Weapon: " << getMainWeapon()
        << "\nOffhand Weapon: " << getSecondaryWeapon()
        << "\nEnraged: " << ((getEnrage()) ? "TRUE" : "FALSE")
        << "\n\n" << std::endl;
}

void Barbarian::eatTaintedStew(){
    if (getRace() == "UNDEAD"){
        setVitality(getVitality() + 3);
    } else {
        //if character is not UNDEAD their vitality is reduced to 1
        //the barbarian changes its enrage state and weapon accordingly
        setVitality(1);
        //stew toggles set of enrage
        toggleEnrage();
        //if enraged, secondary weapon becomes table, if not primary weapon becomes bucket
        (getEnrage()) ? setSecondaryWeapon("TABLE") : setMainWeapon("BUCKET");
    }
}

//Mage.hpp interface changes
void display() const;
void eatTaintedStew();

//Mage.cpp implementation changes
void Mage::display() const {
    //displays mage data as per project specifications
    std::cout << getName() << " is a Level "
        << getLevel() << " " << getRace() << " MAGE."
        << "\nVitality: " << getVitality()
        << "\nArmor: " << getArmor()
        << ((isEnemy()) ? "\nThey are an enemy." : "\nThey are not an enemy.")
        << "\nSchool of Magic: " << getSchool()
        << "\nWeapon: " << getCastingWeapon()
        << "\nThey " << ((hasIncarnateSummon()) ? "can summon an Incarnate" : "cannot summon an Incarnate")
        << "\n\n" << std::endl;
}

void Mage::eatTaintedStew(){
    if (getRace() == "UNDEAD"){
        setVitality(getVitality() + 3);
    } else {
        //if character is not UNDEAD their vitality is reduced to 1
        //the mage changes vitality as subclass attribute
        setVitality(1);
        
        if (getCastingWeapon() == "WAND"){
            //recovers 2 points of vitality on top of points set by eating stew
            setVitality(getVitality() + 2);
        } else if (getCastingWeapon() == "STAFF"){
            //recovers 2 points of vitality on top of points set by eating stew
            setVitality(getVitality() + 3);
        }

        //if mage has incarnate summon ability, vitality increases by one
        if (hasIncarnateSummon()) {
            setVitality(getVitality() + 1);
        }
    }
}

//Ranger.hpp interface changes
void display() const;
void eatTaintedStew();

//Ranger.cpp implementation changes
void Ranger::display() const {
    //displays ranger data as per project specifications
    std::cout << getName() << " is a Level "
        << getLevel() << " " << getRace() << " RANGER."
        << "\nVitality: " << getVitality()
        << "\nArmor: " << getArmor()
        << ((isEnemy()) ? "\nThey are an enemy." : "\nThey are not an enemy.")
        << "\nAnimal Companion: " << ((getCompanion()) ? "TRUE" : "FALSE")
        << "\nArrows: ";
            //range based loop displays arrow types and quantities
            for (const Arrow& arrow : arrows_){
                std::cout << "\n" << arrow.type_ << ": " << arrow.quantity;
            }
        
        std::cout << "\nAffinities";
            //for loop displays affinities separated by commas
            for (int i = 0; i < 4; i++){
                std::cout << affinities_[i];
                if (!affinities_[i+1].empty()){
                    std::cout << ", ";
                }
            }
        
        std::cout << << "\n\n" << std::endl;
}

void Ranger::eatTaintedStew(){
    //bool to kep track of poison affinity
    bool hasPoison = false;
    //range based loop to determine if ranger has poison affinity
    for (const std::string& affinity : affinities_){
        if (affinity == "POISON"){
            hasPoison = true;
            break;
        }
    }

    if (getRace() == "UNDEAD"){
        setVitality(getVitality() + 3);
    } else {
        //if character is not UNDEAD their vitality is reduced to 1
        //the Ranger changes
        if(hasPoison){
            setVitality(getVitality()/2);
        } else {
            setVitality(1);
        }
        //if Ranger has companion, vitality increases by one
        if (getCompanion()) {
            setVitality(getVitality() + 1);
        }
    }
}

//Scoundrel.hpp interface changes
void display() const;
void eatTaintedStew();

//Scoundrel.cpp implementation changes
void Scoundrel::display() const {
    //displays scoundrel data as per project specifications
    std::cout << getName() << " is a Level "
        << getLevel() << " " << getRace() << " SCOUNDREL."
        << "\nVitality: " << getVitality()
        << "\nArmor: " << getArmor()
        << ((isEnemy()) ? "\nThey are an enemy." : "\nThey are not an enemy.")
        << "\nDagger: " << getDagger()
        << "\nFaction: " << getFaction()
        << "\nDisguise: " << ((hasDisguise()) ? "TRUE" : "FALSE")
        << "\n\n" << std::endl;
}

//random double number genrator
double randDoubleGen(){
    std::random_device randDouble;
    std::mt19937 gen(randDouble());
    std::uniform_real_distribution<double> dist(0.0, 1.0);

    return dist(gen);
}

void Scoundrel::eatTaintedStew(){
    //Scoundrel has 70% chance to gain 4 vitality, 30% chance to reset vitality to 1 and lose dagger
    const bool recoverChance = (randDoubleGen() < 0.70);
    const bool resetChance = (randDoubleGen() < 0.30);

    if (getRace() == "UNDEAD"){
        setVitality(getVitality() + 3);
    } else {
        //if character is not UNDEAD their vitality is reduced to 1
        //the scoundrel changes
        setVitality(1);
        
        //scoundrel specific, if cutpurse gain 3 vitality
        if (getFaction() == "CUTPURSE"){
            setVitality(getVitality() + 3);
        } else if (getFaction() == "SILVERTONGUE" && recoverChance){
            //persuades cook for new stew, recovers 4 vitality points
            setVitality(getVitality() + 4);
        } else if (getFaction() == "SIVLERTONGUE" && resetChance){
            setVitality(1);
            if (getDagger() != "WOOD"){
                setDagger("WOOD");
            }
        }
    }
}

