#include "Record.h"

ofstream outStream;
ifstream inStream;


Record::Record(){

}

void Record::savePlayer(Player* a,ofstream& b ){
    b.open("player.txt");
    b<<a->getName()<<"\n";
    b<<a->getTag()<<"\n";
    b<<a->getMaxHealth()<<"\n";
    b<<a->getCurrentHealth()<<"\n";
    b<<a->getAttack()<<"\n";
    b<<a->getDefense()<<"\n";
    b<<a->getCurrentRoom()->getIndex()<<"\n";
    b<<a->getPreviousRoom()->getIndex()<<"\n";
    b<<a->getInventory().size()<<"\n";
    for(int i=0;i<a->getInventory().size();i++){
        b<<a->getInventory()[i].getName()<<"\n";
        b<<a->getInventory()[i].getTag()<<"\n";
        b<<a->getInventory()[i].getHealth()<<"\n";
        b<<a->getInventory()[i].getAttack()<<"\n";
        b<<a->getInventory()[i].getDefense()<<"\n";
        b<<a->getInventory()[i].getexist()<<"\n";
    }

    b.close();
}

void Record::loadPlayer(Player*a,ifstream& b){
    b.open("player.txt");
    string n;
    string t;
    int mh,ch,at,d;
    int c,p,times;
    
    b>>n;
    b>>t;
    b>>mh;
    b>>ch;
    b>>at;
    b>>d;
    b>>c;
    b>>p;
    b>>times;
    vector<Item> bag;

    for(int i=0;i<times;i++){
        string n;
        string t;
        string s;
        int h,at,d;
        bool e;
        getline(b,s);
        getline(b,n);
        getline(b,t);
        b>>h;
        b>>at;
        b>>d;
        b>>e;

        bag.push_back(Item());
        bag[i].setName(n);
        bag[i].setTag(t);
        bag[i].setHealth(h);
        bag[i].setAttack(at);
        bag[i].setDefense(d);
        bag[i].setexist(e);
    }

    a->setInventory(bag);


    a->setName(n);
    a->setTag(t);
    a->setMaxHealth(mh);
    a->setCurrentHealth(ch);
    a->setAttack(at);
    a->setDefense(d);
    a->re=0;
    a->pr=p;
    a->cr=c;

    b.close();
}


void Record::loadFromFile(Player*a ,vector<Room>&b){
    loadPlayer(a,inStream);
}

void Record::saveToFile(Player* a,vector<Room>& b){
    savePlayer(a,outStream);
}

