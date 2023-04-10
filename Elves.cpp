#include "Elves.h" 

//CONSTRUCTORS
Elves::Elves(string name, int units, int attackpt, int healthpt, int regennum, int tothealth, bool alive, Faction* first_enemy, Faction* second_enemy):Faction(name,units,attackpt,healthpt,regennum,tothealth,alive,first_enemy,second_enemy){
    this->name = name;
    this->units = units;
    this->attackpt = attackpt;
    this->healthpt = healthpt;
    this->regennum = regennum;

    tothealth = healthpt * units;
    this->tothealth = tothealth;

    this->alive = alive; 
    this->first_enemy = first_enemy;
    this->second_enemy = second_enemy;
}

Elves::Elves(const Elves& ptr){
    name=ptr.name;
    units=ptr.units;
    attackpt=ptr.attackpt;
    healthpt=ptr.healthpt;
    regennum=ptr.regennum;
    tothealth=ptr.tothealth;
    alive=ptr.alive;
    first_enemy=ptr.first_enemy;
    second_enemy=ptr.second_enemy;
}

Elves::~Elves(){}

//FUNCTIONS
void Elves::PerformAttack(){
    int tempattack1=attackpt; 
    int tempattack2=attackpt;
    int tempUnits=units;
    if(first_enemy->GetName()=="Dwares"){
        tempattack1 = attackpt*150/100;
    }else tempattack2 = attackpt*150/100;

    if(first_enemy->IsAlive()==0 && second_enemy->IsAlive()==1){
        second_enemy->ReceiveAttack("Elves",units*tempattack2);
    }else if(second_enemy->IsAlive()==0 && first_enemy->IsAlive()==1){
        first_enemy->ReceiveAttack("Elves",units*tempattack1);
    }
    else if(first_enemy->IsAlive()==1 && second_enemy->IsAlive()==1){
        if(first_enemy->GetName()=="Orcs"){
            tempUnits=(units*6/10);
        }else{
            tempUnits=units-(units*6/10);
        }
        first_enemy->ReceiveAttack("Elves",tempUnits*tempattack1);
        second_enemy->ReceiveAttack("Elves",(units-tempUnits)*tempattack2);
    }
}

void Elves::ReceiveAttack(string name,int damage){
    if(name=="Orcs"){
        damage=damage*125/100;
    }else damage=damage*75/100;

    units = units - damage/healthpt;
    tothealth = units*healthpt;
}

int Elves::PurchaseWeapons(int weaponpoint){
    attackpt = attackpt + (2 * weaponpoint); 
    return weaponpoint*15; 
}
int Elves::PurchaseArmors(int armorpoint){
    healthpt = healthpt + (4 * armorpoint);
    tothealth = units*healthpt; 
    return armorpoint*5;
}

void Elves::Print(){
    cout<<"\"You cannot reach our elegance.\""<<endl;
    cout<<"Faction Name:         "<<name<<endl;
    if(alive==1){
    cout<<"Status:               "<<"Alive"<<endl;   
    }
    else{ 
    cout<<"Status:               "<<"Defeated"<<endl; 
    }
    cout<<"Number of Units:      "<<units<<endl;
    cout<<"Attack Point:         "<<attackpt<<endl;
    cout<<"Health Point:         "<<healthpt<<endl;
    cout<<"Unit Regen Number:    "<<regennum<<endl;
    cout<<"Total Faction Health: "<<tothealth<<endl;
}
