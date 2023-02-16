#include "Player.h"



Player::Player():GameCharacter(){

}

Player::Player(string name, int m,int a,int d):GameCharacter(name,"Player",m,a,d){
    re=0;
}

void Player::addItem(Item a){
    inventory.push_back(a);
}

void Player::increaseStates(int h,int a,int d){
    int t_m=getMaxHealth();
    int t_c=getCurrentHealth();
    int t_a=getAttack();
    int t_d=getDefense();
    setMaxHealth(t_m+h);
    setCurrentHealth(t_c+h);
    setAttack(t_a+a);
    setDefense(t_d+d);
}

void Player::changeRoom(Room * a){
    previousRoom=currentRoom;
    currentRoom=a;
}

void Player::setCurrentRoom(Room* a){
    currentRoom=a;
}

void Player::setPreviousRoom(Room* a){
    previousRoom=a;
}

void Player::setInventory(vector<Item> a){
    inventory=a;
}

Room* Player::getCurrentRoom(){
    return currentRoom;
}

Room* Player::getPreviousRoom(){
    return previousRoom;
}

vector<Item>& Player::getInventory(){
    return inventory;
}

bool Player::triggerEvent(Object* a){
    
    cout<<"\n=======================\n";
    cout<<"status:\n";
    cout<<getName()<<" <"<<getTag()<<">\n";
    cout<<"\n";
    cout<<"hp : "<<getCurrentHealth()<<"/"<<getMaxHealth();
    cout<<"\nattack: "<<getAttack();
    cout<<"\ndefense: "<<getDefense();
    cout<<"\n";
    cout<<"\nequipment:\n";
    for(int i=0;i<inventory.size();i++){
        cout<<inventory[i].getName()<<"   "<<"("<<inventory[i].getHealth()<<"/"<<inventory[i].getAttack()<<"/"<<inventory[i].getDefense()<<")\n";
    }
    cout<<"\n=======================\n";
    return 1;
}
