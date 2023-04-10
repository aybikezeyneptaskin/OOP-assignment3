#ifndef DWARVES_H
#define DWARVES_H
#include <iostream>
#include <cstring>
#include "Faction.h"

using namespace std;

class Dwarves:public Faction{
public:
//constructors
Dwarves(string name="", int units=0, int attackpt=0, int healthpt=0, int regennum=0, int tothealth=0, bool alive=true, Faction* first_enemy=NULL, Faction* second_enemy=NULL);
Dwarves(const Dwarves &ptr);
~Dwarves();

 //getters setters
  void SetName(string Name){name=Name;}
  string GetName(){return name;}

  Faction* GetFirst_enemy(){return first_enemy;}
  Faction* GetSecond_enemy(){return second_enemy;}

  void SetUnits(int Units){units=Units;}
  int GetUnit(){return units;}

  void SetAttackpt(int Attackpt){attackpt=Attackpt;}
  int GetAttackpt(){return attackpt;}

  void SetHealthpt(int Healthpt){healthpt=Healthpt;}
  int GetHealthpt(){return healthpt;}

  void SetRegennum(int Regennum){regennum=Regennum;}
  int GetRegennum(){return regennum;}

  void SetTotHealth(int TotHealth){tothealth=TotHealth;}
  int GetTotHealth(){return tothealth;}

  void SetAlive(bool Alive){alive=Alive;}
  bool IsAlive(){return alive;}

  //functions
  void PerformAttack();
  void ReceiveAttack(string,int);
  int PurchaseWeapons(int);
  int PurchaseArmors(int);
  void Print();
};




#endif