#include "Dungeon.h"
using namespace std;
Dungeon::Dungeon(){
}

void Dungeon::createPlayer(){
    
    string n;
    char k;
    cout<< "Enter character name: ";
    cin>>n;
    cout<<"\n";
    cout<<"choose your career.\n";
    cout<<"A. Warrior (90,25,5)\n";
    cout<<"B. Tank    (100,20,8)\n";
    cin>>k;

    if(k=='A'){
        player = Player(n,90,25,5);
        player.setTag("Warrior");
    }
    else{
        player = Player(n,100,20,8);
        player.setTag("Tank");
    }

    vector<Item> bag;
    player.setInventory(bag);
    player.setCurrentRoom(&rooms[0]);
    player.setCurrentHealth(player.getMaxHealth());
    
}

void Dungeon::createMap(){

    for(int i=0; i<7; i++){
        rooms.push_back(Room());
        rooms[i].setIndex(i); 
        rooms[i].setIsExit(0);
        rooms[i].setDownRoom(NULL);
        rooms[i].setUpRoom(NULL);
        rooms[i].setLeftRoom(NULL);
        rooms[i].setRightRoom(NULL);
    }

    rooms[6].setIsExit(1);

    rooms[0].setUpRoom(&rooms[1]);
    rooms[1].setDownRoom(&rooms[0]);

    rooms[1].setUpRoom(&rooms[2]);
    rooms[2].setDownRoom(&rooms[1]);

    rooms[2].setLeftRoom(&rooms[3]);
    rooms[3].setRightRoom(&rooms[2]);

    rooms[2].setRightRoom(&rooms[4]);
    rooms[4].setLeftRoom(&rooms[2]);

    rooms[4].setRightRoom(&rooms[5]);
    rooms[5].setLeftRoom(&rooms[4]);

    rooms[4].setUpRoom(&rooms[6]);
    rooms[6].setDownRoom(&rooms[4]);

}

void Dungeon::handleMovement(){

    Room* cur=player.getCurrentRoom();
     
    //cout<<player.getCurrentRoom()->getIndex();

    cout<<"\n-----------------------\n";
    
    if(cur->getUpRoom()!=NULL){
        cout<<"u. Go up\n";
    }
    if(cur->getDownRoom()!=NULL){
        cout<<"d. Go down\n";
    }
    if(cur->getLeftRoom()!=NULL){
        cout<<"l. Go left\n";
    }
    if(cur->getRightRoom()!=NULL){
        cout<<"r. Go right\n";
    }       
    char k;
    cin>>k;

    if(k=='u'){
        player.changeRoom(cur->getUpRoom());
    }   
    if(k=='d'){
        player.changeRoom(cur->getDownRoom());
    }
    if(k=='l'){
        player.changeRoom(cur->getLeftRoom());
    }
    if(k=='r'){
        player.changeRoom(cur->getRightRoom());
    }
    cout<<"---------"<<"Room"<<player.getCurrentRoom()->getIndex()<<"---------\n";
}

void Dungeon::chooseAction(){
    char j;
    vector<Object*> temp =player.getCurrentRoom()->getObjects();
    if(temp.size()>0){
        for(int i=0;i<temp.size();i++){
            while(temp[i]->triggerEvent(&player)){
            }
        }
    }
    while(1){
        if(checkGameLogic()==0){
            cout<<"\nGame Over.\n";
            break;
        }
        else if(checkGameLogic()==1){
            cout<<"\nvictory!!\n";
            break;
        }

        if(player.re==0){
            cout<<"\n-----------------------\n";
            cout<<"A. save to file\n";
            cout<<"B. check status\n";
            cout<<"C. move\n";
            cout<<"D. show map\n";
            cin>>j;
            cout<<"-----------------------\n";
        }
        else if (player.re==1){
            j='A';
        }
        
        if(j=='A'){
            Record rec;
            ofstream outStream;
            outStream.open("room.txt");
            GameCharacter*ro1= dynamic_cast<GameCharacter*>(rooms[1].getObjects()[0]);
            Item*ro3= dynamic_cast<Item*>(rooms[3].getObjects()[0]);
            GameCharacter*ro4= dynamic_cast<GameCharacter*>(rooms[4].getObjects()[0]);
            GameCharacter*ro5= dynamic_cast<GameCharacter*>(rooms[5].getObjects()[0]);
            GameCharacter*ro6= dynamic_cast<GameCharacter*>(rooms[6].getObjects()[0]);

            outStream<<ro1->getCurrentHealth()<<"\n";
            outStream<<ro3->getexist()<<"\n";
            outStream<<ro4->getCurrentHealth()<<"\n";
            outStream<<ro5->getCurrentHealth()<<"\n";
            outStream<<ro6->getCurrentHealth()<<"\n";

            outStream.close();

            rec.saveToFile(&player,rooms);
            exit(1);
        }
        if(j=='B'){
            player.triggerEvent(&player);
        }
        if(j=='C'){
            break;
        }
        if(j=='D'){
            string a="0";
            string b="1";
            string c="2";
            string d="3";
            string e="4";
            string f="5";
            string g="6";

            if(player.getCurrentRoom()->getIndex()==0){
                a="*";
            }
            if(player.getCurrentRoom()->getIndex()==1){
                b="*";
            }
            if(player.getCurrentRoom()->getIndex()==2){
                c="*";
            }
            if(player.getCurrentRoom()->getIndex()==3){
                d="*";
            }
            if(player.getCurrentRoom()->getIndex()==4){
                e="*";
            }
            if(player.getCurrentRoom()->getIndex()==5){
                f="*";
            }
            if(player.getCurrentRoom()->getIndex()==6){
                g="*";
            }

            cout<<"            |---|      \n";
            cout<<"            | "<<g<<" |      \n";
            cout<<"            |---|      \n";
            cout<<"              |        \n";
            cout<<"|---| |---| |---| |---|\n";
            cout<<"| "<<d<<" |-| "<<c<<" |-| "<<e<<" |-| "<<f<<" |\n";
            cout<<"|---| |---| |---| |---|\n";
            cout<<"        |              \n";
            cout<<"      |---|            \n";
            cout<<"      | "<<b<<" |            \n";
            cout<<"      |---|            \n";
            cout<<"        |              \n";
            cout<<"      |---|            \n";
            cout<<"      | "<<a<<" |            \n";
            cout<<"      |---|            \n";            
        }
        
    }
}

int Dungeon::checkGameLogic(){
    Monster* temp= dynamic_cast<Monster*>(rooms[6].getObjects()[0]);
    if(player.checkIsDead()){
        return 0;
    }
    else if (player.getCurrentRoom()->getIsExit()&&temp->checkIsDead()){
        return 1;
    }
    else {
        return 2;
    }
}

void Dungeon::runDungeon(){

createMap();
//==============================//
vector<Object*> o0;
vector<Object*> o1;
vector<Object*> o2;
vector<Object*> o3;
vector<Object*> o4;
vector<Object*> o5;
vector<Object*> o6;

Item sword ("Old Sword","no skill",0,20,0);
o3.push_back(&sword);
rooms[3].setObjects(o3);


Item weed ("Armor","no skill",20,0,10);
Item account("Wine","Reinforced",0,10,6);
Item hotel("Potion of recovery","Rest",0,0,0);
Item leader("Magic book","Control",5,0,8);

Monster fm ("< Monster > James",30,15,4);
fm.setCurrentHealth(30);
o1.push_back(&fm);
rooms[1].setObjects(o1);

Monster sm ("< Boss > Bena",250,45,15);
sm.setCurrentHealth(250); 
o6.push_back(&sm);
rooms[6].setObjects(o6);

vector <Item> fnb;
NPC fn ("< Spirit >","zeyan",fnb);
o4.push_back(&fn);
fn.setCurrentHealth(100);
rooms[4].setObjects(o4);
fnb.push_back(weed);
fn.setCommodity(fnb);

vector<Item> snb;
NPC sn("< Merchant > Bill","billwu",snb);
o5.push_back(&sn);
sn.setCurrentHealth(100);
rooms[5].setObjects(o5);
snb.push_back(account);
snb.push_back(hotel);
snb.push_back(leader);
sn.setCommodity(snb);
//==============================//


char k;
cout<<"\n";
cout<<"Do you want to start a new game or continue?\n";
cout<<"\n";
cout<<"A. Start a new game.\n";
cout<<"B. Contiune.\n";
cin>>k;
if(k=='B'){
    Record rec1;
    ifstream inStream;

    rec1.loadFromFile(&player,rooms);
    player.setCurrentRoom(&rooms[player.cr]);
    player.setPreviousRoom(&rooms[player.pr]);
    inStream.open("room.txt");
    int r1,r4,r5,r6;
    bool r3;
    inStream>>r1;
    inStream>>r3;
    inStream>>r4;
    inStream>>r5;
    inStream>>r6;
    GameCharacter*ro1= dynamic_cast<GameCharacter*>(rooms[1].getObjects()[0]);
    Item*ro3= dynamic_cast<Item*>(rooms[3].getObjects()[0]);
    GameCharacter*ro4= dynamic_cast<GameCharacter*>(rooms[4].getObjects()[0]);
    GameCharacter*ro5= dynamic_cast<GameCharacter*>(rooms[5].getObjects()[0]);
    GameCharacter*ro6= dynamic_cast<GameCharacter*>(rooms[6].getObjects()[0]);
    ro1->setCurrentHealth(r1);
    ro3->setexist(r3);
    ro4->setCurrentHealth(r4);
    ro5->setCurrentHealth(r5);
    ro6->setCurrentHealth(r6);
    inStream.close();

}
else {
    createPlayer();
}
 
//=======================================//

   while(1){
        
        chooseAction();
        
        
        if(checkGameLogic()==0){
            break;
        }
        else if(checkGameLogic()==1){
            break;
        }

        handleMovement();

        if(checkGameLogic()==0){
            break;
        }
        else if(checkGameLogic()==1){
            break;
        }
    }
}



