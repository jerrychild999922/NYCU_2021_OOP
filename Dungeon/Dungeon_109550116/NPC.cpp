#include "NPC.h"

NPC::NPC():GameCharacter(){

}

NPC::NPC(string name,string a,vector<Item> b):GameCharacter(name,"NPC",100,0,20){
    script=a;
    commodity=b;
}

void NPC::listCommodity(){
    for(int i=0;i<commodity.size();i++){
        cout<<i+1<<". "<<commodity[i].getName()<<"  "<<"("<<commodity[i].getHealth()<<"/"<<commodity[i].getAttack()<<"/"<<commodity[i].getDefense()<<")\n";
    }
}

void NPC::setScript(string a){
    script=a;
}

void NPC::setCommodity(vector <Item> a){
    commodity=a;
}

string NPC::getScript(){
    return script;
}

vector <Item> NPC::getCommodity(){
    return commodity;
}

bool NPC::triggerEvent(Object* a){

    
    Player* player = dynamic_cast<Player*>(a);
    if(this->getScript()=="zeyan"){
        if(checkIsDead()){
            cout<<"\n";
            cout<<"The resentment is gone.";
            cout<<"\n";
            return 0;
        }
        else {
            char k;
            cout<<"ZeYan: I was the greatest warrior in the world.\n";
            cout<<"       However, I lost to the strong Monster Bena.\n";
            cout<<"       I have waited for a hero to kill it for 100 years.\n";
            cout<<"       Are you the hero ?\n";
            cout<<"\n";
            cout<<"Y. Yes\n";
            cout<<"N. No\n";
            cin>>k;
            cout<<"\n";
            cout<<"\n-----------------------\n";
            if(k=='Y'){
                cout<<"ZeYan: Thanks god, the hero finally shows up.\n";
                cout<<"       Therefore, I will give you my Aromor to help you win the fight.\n";
                cout<<"\n============================\n";
                cout<<"you got a "<<getCommodity()[0].getName();
                cout<<"\nyou attain "<<getCommodity()[0].getHealth()<<" hp, "<<getCommodity()[0].getAttack()<<" attack, "<<getCommodity()[0].getDefense()<<" defense.";
                cout<<"\n============================\n";
                cout<<"\n";
                cout<<"< Spirit > Zeyan left";
                cout<<"\n";
                this->setCurrentHealth(0);
                player->addItem(getCommodity()[0]);
                player->increaseStates(getCommodity()[0].getHealth(),getCommodity()[0].getAttack(),getCommodity()[0].getDefense());
            }
            else if (k=='N'){
                cout<<"\nZeYan: That's ok, I will go other place to find the hero.\n";
                cout<<"\n";
                cout<<"< Spirit > Zeyan left in despair.";
                cout<<"\n";
                this->setCurrentHealth(0);
            }
            int jud =0;
            for(int j=0;j<player->getInventory().size();j++){
                if(player->getInventory()[j].getName()=="Old Sword"){
                    jud=1;
                }
            }
            if(jud==1){
                cout<<"\n************Special Case************\n";
                cout<<"Because your found zeyan's sword.\n";
                cout<<"zeyan let your weapon attack +20";
                cout<<"\n************************************\n";
                for(int j=0;j<player->getInventory().size();j++){
                    if(player->getInventory()[j].getName()=="Old Sword"){
                    player->setAttack(60);
                    }
                }
            }
        return 0;
        }
    return 0;
    }
    else if(this->getScript()=="billwu"){
        if(checkIsDead()){
            cout<<"Bill: Don't be greedy.";
            return 0;
        }
        else{
            int h;
            cout<<"Bill: Wellcome to my shop.\n";
            cout<<"Bill: You can take one thing from me.\n";
            cout<<"\n";
            cout<<"0. Back.\n";
            listCommodity();
            cin>>h;
            if(h==0){
                return 0;
            }
            if(h==1){
                cout<<"\n============================\n";
                cout<<"you got a "<<getCommodity()[0].getName();
                cout<<"\nyou attain "<<getCommodity()[0].getHealth()<<" hp, "<<getCommodity()[0].getAttack()<<" attack, "<<getCommodity()[0].getDefense()<<" defense.";
                cout<<"\n============================\n";
                this->setCurrentHealth(0);
                player->addItem(getCommodity()[0]);
                player->increaseStates(getCommodity()[0].getHealth(),getCommodity()[0].getAttack(),getCommodity()[0].getDefense());
                cout<<"\n************Special Case************\n";
                cout<<"Because you got Wine\n";
                cout<<"You gain unique skill < Reinforced >.";
                cout<<"\n************************************\n";
                


            }
            if(h==2){
                cout<<"\n============================\n";
                cout<<"you got a "<<getCommodity()[1].getName();
                cout<<"\nyou attain "<<getCommodity()[1].getHealth()<<" hp, "<<getCommodity()[1].getAttack()<<" attack, "<<getCommodity()[1].getDefense()<<" defense.";
                cout<<"\n============================\n";
                this->setCurrentHealth(0);
                player->addItem(getCommodity()[1]);
                player->increaseStates(getCommodity()[1].getHealth(),getCommodity()[1].getAttack(),getCommodity()[1].getDefense());
                cout<<"\n************Special Case************\n";
                cout<<"Because you got Magic book.\n";
                cout<<"You gain unique skill < Rest >.";
                cout<<"\n************************************\n";
                
            }
            if(h==3){
                cout<<"\n============================\n";
                cout<<"you got a "<<getCommodity()[2].getName();
                cout<<"\nyou attain "<<getCommodity()[2].getHealth()<<" hp, "<<getCommodity()[2].getAttack()<<" attack, "<<getCommodity()[2].getDefense()<<" defense.";
                cout<<"\n============================\n";
                this->setCurrentHealth(0);
                player->addItem(getCommodity()[2]);
                player->increaseStates(getCommodity()[2].getHealth(),getCommodity()[2].getAttack(),getCommodity()[2].getDefense());
                cout<<"\n************Special Case************\n";
                cout<<"Because you got the Magic book.\n";
                cout<<"You gain unique skill < Control >.";
                cout<<"\n************************************\n";
                

            }
        }

    }


return 0;
   










    
}