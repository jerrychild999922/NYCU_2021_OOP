#include "Item.h"

Item::Item():Object(){

}

Item::Item(string name,string tag,int health,int attack,int defense):Object(name,tag){
    this->health=health;
    this->attack=attack;
    this->defense=defense;
    exist=1;
}

int Item::getAttack(){
    return this->attack;
}

int Item::getHealth(){
    return this->health;
}

int Item::getDefense(){
    return this->defense;
}

bool Item::getexist(){
    return exist;
}

void Item::setHealth(int health){
    this->health=health;
}

void Item::setAttack(int attack){
    this->attack=attack;
}

void Item::setDefense(int defense){
    this->defense=defense;
}

void Item::setexist(bool a){
    exist=a;
}

bool Item::triggerEvent(Object* a){
    
    Item temp = Item(this->getName(),this->getTag(),this->getHealth(),this->getAttack(),this->getDefense());
    if(this->getexist()==0){
        return 0;
    }
    else{
        char k;
        Player* player = dynamic_cast<Player*>(a);
        cout<<"oh you find a chest. Do you want to open it?\n";
        cout<<"\nA. Yes\n";
        cout<<"B. No\n";
        cin>>k;
        if(k=='A'){
            cout<<"\n============================\n";
            cout<<"you got a "<<this->getName();
            cout<<"\nyou attain "<<this->getHealth()<<" hp, "<<this->getAttack()<<" attack, "<<this->getDefense()<<" defense.";
            cout<<"\n============================\n";
            player->increaseStates(this->getHealth(),this->getAttack(),this->getDefense());
            this->setexist(0); 
            player->addItem(temp);
        }
        if(k=='B'){
         
        }
    }
    return 0;
   
}


