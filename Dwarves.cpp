#include "Dwarves.h"

//CONSTRUCTORS
Dwarves::Dwarves(string name, int units, int attackpt, int healthpt, int regennum, int tothealth, bool alive, Faction* first_enemy, Faction* second_enemy):Faction(name,units,attackpt,healthpt,regennum,tothealth,alive,first_enemy,second_enemy){
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

Dwarves::Dwarves(const Dwarves& ptr){
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

Dwarves::~Dwarves(){}

//FUNCTIONS

void Dwarves::PerformAttack(){
    if(first_enemy->IsAlive()==0 && second_enemy->IsAlive()==1){
        second_enemy->ReceiveAttack("Dwarves",units*attackpt);
    }else if(second_enemy->IsAlive()==0 && first_enemy->IsAlive()==1){
        first_enemy->ReceiveAttack("Dwarves",units*attackpt);
    }
    else if(first_enemy->IsAlive()==1 && second_enemy->IsAlive()==1){
        first_enemy->ReceiveAttack("Dwarves",(units/2)*attackpt);
        second_enemy->ReceiveAttack("Dwarves",(units-(units/2))*attackpt);
    }
}
void Dwarves::ReceiveAttack(string name,int damage){
    units = units - damage/healthpt;
    tothealth=units*healthpt;
}

int Dwarves::PurchaseWeapons(int weaponpoint){
    attackpt = attackpt + weaponpoint; 
   return weaponpoint*10; 
}
int Dwarves::PurchaseArmors(int armorpoint){
    healthpt = healthpt + (2 * armorpoint);
    tothealth = units*healthpt; 
    return armorpoint*3;
}

void Dwarves::Print(){
    cout<<"\"Taste the power of our axes!\""<<endl;
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

