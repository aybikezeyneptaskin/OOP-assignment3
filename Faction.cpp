#include "Faction.h"

//CONSTRUCTORS
Faction::Faction(string name, int units, int attackpt, int healthpt, int regennum, int tothealth, bool alive, Faction* first_enemy, Faction* second_enemy){
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

Faction::Faction(const Faction& ptr){
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

Faction::~Faction(){}

//FUNCTIONS

void Faction::AssignEnemies(Faction* fac1,Faction* fac2){
    first_enemy=fac1;
    second_enemy=fac2;
}

void Faction::Print(){
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

void Faction::EndTurn(){
    tothealth = healthpt*units;
    units = units + regennum;
    if(units<0) units=0;
    tothealth = healthpt*units;
    if(units==0) alive=false;
}