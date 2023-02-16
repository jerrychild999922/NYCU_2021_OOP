#include "Room.h"

Room::Room(){

}
Room::Room(bool isExit,int index,vector<Object*> objects){
    this->isExit=isExit;
    this->index=index;
    this->objects=objects;
}

void Room::setUpRoom(Room* a){
    this->upRoom=a;
}

void Room::setDownRoom(Room* a){
    this->downRoom=a;
}

void Room::setLeftRoom(Room* a){
    this->leftRoom=a;
}

void Room::setRightRoom(Room* a){
    this->rightRoom=a;
}

void Room::setIsExit(bool a){
    this->isExit=a;
}

void Room::setIndex(int a){
    this->index=a;
}

void Room::setObjects(vector<Object*> a){
    this->objects=a;
    
}

Room* Room::getDownRoom(){
    return this->downRoom;
}

Room* Room::getUpRoom(){
    return this->upRoom;
}

Room* Room::getRightRoom(){
    return this->rightRoom;
}

Room* Room::getLeftRoom(){
    return this->leftRoom;
}

vector <Object*> Room::getObjects(){
    return objects;
}

int Room::getIndex(){
    return index;
}

bool Room::getIsExit(){
    return isExit;
}












