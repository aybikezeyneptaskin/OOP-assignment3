#ifndef FACTION_H
#define FACTION_H
#include <iostream>
#include <cstring>

using namespace std;

class Faction{

protected:
  string name;
  Faction* first_enemy;
  Faction* second_enemy;
  int units;
  int attackpt;
  int healthpt;
  int regennum;
  int tothealth;
  bool alive;

public:
  Faction* Next= NULL;
  //constructors
  Faction(string name="", int units=0, int attackpt=0, int healthpt=0, int regennum=0, int tothealth=0, bool alive=true, Faction* first_enemy=NULL, Faction* second_enemy=NULL);
  Faction(const Faction &ptr);
  ~Faction();

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
  void AssignEnemies(Faction*,Faction*);
  virtual void PerformAttack() = 0;
  virtual void ReceiveAttack(string,int) = 0;
  virtual int PurchaseWeapons(int) = 0;
  virtual int PurchaseArmors(int) = 0;
  virtual void Print();
  void EndTurn();

};


#endif