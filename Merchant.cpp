#include "Merchant.h"

//CONSTRUCTORS
Merchant::Merchant(int startweaponpt,int startarmorpt,int revenue,int weaponpt,int armorpt,Faction* first_faction,Faction* second_faction,Faction* third_faction){
  this->startweaponpt=startweaponpt;
  this->startarmorpt=startarmorpt;
  this->revenue=revenue;
  weaponpt=startweaponpt;
  this->weaponpt=weaponpt;
  armorpt=startarmorpt;
  this->armorpt=armorpt;
  this->first_faction=first_faction;
  this->second_faction=second_faction;
  this->third_faction=third_faction;
}

Merchant::Merchant(const Merchant& ptr){
  startweaponpt=ptr.startweaponpt;
  startarmorpt=ptr.startarmorpt;
  revenue=ptr.revenue;
  weaponpt=ptr.weaponpt;
  armorpt=ptr.armorpt;
  first_faction=ptr.first_faction;
  second_faction=ptr.second_faction;
  third_faction=ptr.third_faction;
}

Merchant::~Merchant(){}

  //FUNCTIONS
  void Merchant::AssignFactions(Faction* fac1,Faction* fac2,Faction* fac3){
      first_faction=fac1;
      second_faction=fac2;
      third_faction=fac3;
  }
  bool Merchant::SellWeapons(string faction, int weaponpoint){
    //PEK BİLEMEDİM orcs dvwarew elves falan ayarla onları
    if(faction == first_faction->GetName()){
      if(first_faction->IsAlive()==1 && weaponpoint<=weaponpt){
      revenue = revenue + first_faction->PurchaseWeapons(weaponpoint);
      cout<<"Weapons sold!"<<endl;
      weaponpt=weaponpt-weaponpoint;
      return true;
      }else if(first_faction->IsAlive()==0){
        cout<<"The faction you want to sell weapons is dead!"<<endl;
        return false;
      }else if(weaponpoint>weaponpt){
        cout<<"You try to sell more weapons than you have in possession."<<endl;
        return false;
      }
    }
    else if(faction==second_faction->GetName()){
      if(second_faction->IsAlive()==1 && weaponpoint<=weaponpt){
      revenue = revenue + second_faction->PurchaseWeapons(weaponpoint);
      cout<<"Weapons sold!"<<endl;
      weaponpt=weaponpt-weaponpoint;
      return true;
      }else if(second_faction->IsAlive()==0){
        cout<<"The faction you want to sell weapons is dead!"<<endl;
        return false;
      }else if(weaponpoint>weaponpt){
        cout<<"You try to sell more weapons than you have in possession."<<endl;
        return false;
      }
    }
      else if(faction==third_faction->GetName()){
      if(third_faction->IsAlive()==1 && weaponpoint<=weaponpt){
      revenue = revenue + third_faction->PurchaseWeapons(weaponpoint);
      cout<<"Weapons sold!"<<endl;
      weaponpt=weaponpt-weaponpoint;
      return true;
      }else if(third_faction->IsAlive()==0){
        cout<<"The faction you want to sell weapons is dead!"<<endl;
        return false;
      }else if(weaponpoint>weaponpt){
        cout<<"You try to sell more weapons than you have in possession."<<endl;
        return false;
      }
    }
  }
  bool Merchant::SellArmors(string faction, int armorpoint){
    if(faction == first_faction->GetName()){
      if(first_faction->IsAlive()==1 && armorpoint<=armorpt){
      revenue = revenue + first_faction->PurchaseArmors(armorpoint);
      cout<<"Armors sold!"<<endl;
      armorpt=armorpt-armorpoint;
      return true;
      }else if(first_faction->IsAlive()==0){
        cout<<"The faction you want to sell armors is dead!"<<endl;
        return false;
      }else if(armorpoint>armorpt){
        cout<<"You try to sell more armors than you have in possession."<<endl;
        return false;
      }
    }
    else if(faction==second_faction->GetName()){
      if(second_faction->IsAlive()==1 && armorpoint<=armorpt){
      revenue = revenue + second_faction->PurchaseArmors(armorpoint);
      cout<<"Armors sold!"<<endl;
      armorpt=armorpt-armorpoint;
      return true;
      }else if(second_faction->IsAlive()==0){
        cout<<"The faction you want to sell armors is dead!"<<endl;
        return false;
      }else if(armorpoint>armorpt){
        cout<<"You try to sell more armors than you have in possession."<<endl;
        return false;
      }
    }
      else if(faction==third_faction->GetName()){
      if(third_faction->IsAlive()==1 && armorpoint<=armorpt){
      revenue = revenue + third_faction->PurchaseArmors(armorpoint);
      cout<<"Armors sold!"<<endl;
      armorpt=armorpt-armorpoint;
      return true;
      }else if(third_faction->IsAlive()==0){
        cout<<"The faction you want to sell armors is dead!"<<endl;
        return false;
      }else if(armorpoint>armorpt){
        cout<<"You try to sell more armors than you have in possession."<<endl;
        return false;
      }
    }
  }
  void Merchant::EndTurn(){
    weaponpt=startweaponpt;
    armorpt=startarmorpt;
  }