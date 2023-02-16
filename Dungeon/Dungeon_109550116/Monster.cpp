#include "Monster.h"

Monster::Monster():GameCharacter(){

}

Monster::Monster(string name, int m,int a,int d):GameCharacter(name,"Monster",m,a,d){
    
}

bool Monster::triggerEvent(Object* a){
    if(this->checkIsDead()){
        return 0;
    }
    
    else{

        char k;
        Player* player = dynamic_cast<Player*>(a);

        cout<<"you meet the monster "<<this->getName();
        cout<<"\nWhat do want to do?";
        cout<<"\n";
        while(this->getCurrentHealth()>0 && player->getCurrentHealth()>0){
            cout<<"\nA. save to file";
            cout<<"\nB. check status";
            cout<<"\nC. retreat";
            cout<<"\nD. attack";
            cout<<"\nE. Use Skill\n";
            cin>>k;
            if(k=='A'){
                player->re=1;
                break;
            }
            if(k=='B'){
                a->triggerEvent(a);
            }
            if(k=='C'){
                Player* player = dynamic_cast<Player*>(a);
                player->setCurrentRoom(player->getPreviousRoom());
                cout<<"\n"<<"you retreat to Room "<<player->getCurrentRoom()->getIndex();
                break;
            }
            if(k=='D'){ 
                Player* player = dynamic_cast<Player*>(a);
                int dam,dam1;
                dam=player->getAttack()-this->getDefense();
                dam1=this->getAttack()-player->getDefense();
                if (dam>0){}
                else{dam=0;}
                if (dam1>0){}
                else{dam1=0;}                
                
                cout<<"\n=====================================\n";
                cout<<"you attack "<<this->getName()<<" "<<dam<<" damage.  ";
                int re=this->takeDamage(dam);
                cout<<this->getName()<<" remain "<<re<<" hp \n";
                cout<<this->getName()<<" attack you "<<dam1<<" damage.  ";
                int re1=player->takeDamage(dam1);
                cout<<"you remain "<<re1<<" hp.";
                cout<<"\n=====================================\n";
            }
            if(k=='E'){
                int jud=0;
                for(int j=0;j<player->getInventory().size();j++){
                    if(player->getInventory()[j].getTag()!="no skill"){
                        jud=1;
                    }
                }
                if(jud==0){
                    cout<<"\nYou don't have any skill.\n";
                }
                else{

                    char jud1;
                    string l;
                    for(int j=0;j<player->getInventory().size();j++){
                        if(player->getInventory()[j].getTag()!="no skill"){
                            l=player->getInventory()[j].getTag();
                        }
                    }

                    cout<<"\nDo you want to use skill < "<<l<<" >?\n";
                    cout<<"\n";
                    cout<<"Y. Yes\n";
                    cout<<"N. No\n";
                    cin>>jud1;
                    if(jud1=='N'){

                    }
                    else if(jud1=='Y') {
                        for(int j=0;j<player->getInventory().size();j++){
                            player->getInventory()[j].setTag("no skill");
                        }
                        if(l=="Reinforced"){
                            cout<<"\n---------( Activate Skill )---------\n";
                            cout<<"You drink your wine and get power from it.\n";
                            cout<<"Therefore, your attack x2.\n";
                            player->setAttack(player->getAttack()*2);
                            cout<<"You have "<<player->getAttack()<<" attack now.";
                            cout<<"\n-------------------------------------\n";
                            
                        }
                        else if (l=="Rest"){
                            cout<<"\n---------( Activate Ｓkill )---------\n";
                            cout<<"You use Potion of recovery.\n";
                            cout<<"Therefore, you got heal completely.\n";
                            player->setCurrentHealth(player->getMaxHealth());
                            cout<<"You have "<<player->getCurrentHealth()<<" hp now.";
                            cout<<"\n-------------------------------------\n";
                            
                        }
                        else if(l=="Control"){
                            cout<<"\n---------( Activate Ｓkill )---------\n";
                            cout<<"You learned control magic.\n";
                            cout<<"Therefore, you have 50% chance to recruit the monster to your team.";
                            srand((unsigned) time(0));
                            int x=rand()%2;
                            if(x==0){
                                cout<<"\n-------------( Success )-------------\n";
                                this->setCurrentHealth(0);
                            }
                            else{
                                cout<<"\n---------------( Fail )--------------\n";
                            }
                        
                        }

                        
                    }
                }
            }
        }
        if(this->getCurrentHealth()<=0){
            cout<<"\nyou win.\n";
        }
        else if(player->getCurrentHealth()<=0){
            cout<<"\nyou lose.\n";
        }
    }
    return 0;
}