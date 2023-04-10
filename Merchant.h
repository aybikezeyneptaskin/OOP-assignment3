#ifndef MERCHANT_H
#define MERCHANT_H
#include <iostream>
#include <cstring>
#include "Faction.h"

using namespace std;

class Merchant{
private:
  Faction* first_faction;
  Faction* second_faction;
  Faction* third_faction;
  int weaponpt;
  int armorpt;
  int startweaponpt=weaponpt;
  int startarmorpt=armorpt;
  int revenue;
  
public:
  //constructors
  Merchant(int startweaponpt=0,int startarmorpt=0,int revenue=0,int weaponpt=0,int armorpt=0,Faction* first_faction=NULL,Faction* second_faction=NULL,Faction* third_faction=NULL);
  Merchant(const Merchant& ptr);
  ~Merchant();

  //getters setters
  Faction* GetFirst_faction(){return first_faction;}
  Faction* GetSecond_faction(){return second_faction;}
  Faction* GetThird_faction(){return third_faction;}

  void SetStartweaponpt(int Startweaponpt){startweaponpt=Startweaponpt;}
  int GetStartweaponpt(){return startweaponpt;}

  void SetStartarmorpt(int Startarmorpt){startarmorpt=Startarmorpt;}
  int GetStartarmorpt(){return startarmorpt;}

  void SetRevenue(int Revenue){revenue=Revenue;}
  int GetRevenue(){return revenue;}

  void SetWeaponPoints(int Weaponpt){weaponpt=Weaponpt;}
  int GetWeaponPoints(){return weaponpt;}

  void SetArmorPoints(int Armorpt){armorpt=Armorpt;}
  int GetArmorPoints(){return armorpt;}

  //functions
  void AssignFactions(Faction*,Faction*,Faction*);
  bool SellWeapons(string, int);
  bool SellArmors(string, int);
  void EndTurn();

};


#endif