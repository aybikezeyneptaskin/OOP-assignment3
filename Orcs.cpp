#include "Orcs.h"

//CONSTRUCTORS
Orcs::Orcs(string name, int units, int attackpt, int healthpt, int regennum, int tothealth, bool alive, Faction* first_enemy, Faction* second_enemy):Faction(name,units,attackpt,healthpt,regennum,tothealth,alive,first_enemy,second_enemy){
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

Orcs::Orcs(const Orcs& ptr){
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

Orcs::~Orcs(){};

//FUNCTIONS
void Orcs::PerformAttack(){
    int tempUnits=units;
    if(first_enemy->IsAlive()==0 && second_enemy->IsAlive()==1){
        second_enemy->ReceiveAttack("Orcs",units*attackpt);
    }else if(second_enemy->IsAlive()==0 && first_enemy->IsAlive()==1){
        first_enemy->ReceiveAttack("Orcs",units*attackpt);
    }
    else if(first_enemy->IsAlive()==1 && second_enemy->IsAlive()==1){
        if(first_enemy->GetName()=="Elves"){
            tempUnits=(units*7/10);
        }else{
            tempUnits=units-(units*7/10);
        }
        first_enemy->ReceiveAttack("Orcs",tempUnits*attackpt);
        second_enemy->ReceiveAttack("Orcs",(units-tempUnits)*attackpt);
    }
}

void Orcs::ReceiveAttack(string name,int damage){
    if(name=="Elves"){
        damage=damage*75/100;
    }else damage=damage*80/100;
    units = units - damage/healthpt;
    tothealth=units*healthpt;
}

int Orcs::PurchaseWeapons(int weaponpoint){
   attackpt = attackpt + (2 * weaponpoint); 
   return weaponpoint*20; 
}
int Orcs::PurchaseArmors(int armorpoint){
    healthpt = healthpt + (3 * armorpoint);
    tothealth = units*healthpt; 
    return armorpoint;
}

void Orcs::Print(){
    cout<<"\"Stop running, you'll only die tired!\""<<endl;
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