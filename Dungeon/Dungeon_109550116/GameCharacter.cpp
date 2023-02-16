#include "GameCharacter.h"

GameCharacter::GameCharacter():Object(){

}
GameCharacter::GameCharacter(string name,string tag ,int maxHealth,int attack,int defense):Object(name,tag){
    this->maxHealth=maxHealth;
    this->attack=attack;
    this->defense=defense;

}
bool GameCharacter::checkIsDead(){
    if(currentHealth<=0){
        return 1 ;
    }
    else{
        return 0 ;
    }
}

int GameCharacter::takeDamage(int dam){
    currentHealth=currentHealth-dam;
    if(currentHealth>0){
        return currentHealth;
    }
    else{
        return 0;
    }
}

void GameCharacter::setMaxHealth(int a){
    maxHealth=a;
}

void GameCharacter::setCurrentHealth(int a){
    currentHealth=a;
}

void GameCharacter::setAttack(int a){
    attack=a;
}

void GameCharacter::setDefense(int a){
    defense=a;
}

int GameCharacter::getMaxHealth(){
    return maxHealth;
}

int GameCharacter::getCurrentHealth(){
    return currentHealth;
}

int GameCharacter::getAttack(){
    return attack;
}

int GameCharacter::getDefense(){
    return defense;
}