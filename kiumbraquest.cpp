 #include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>

using namespace std;



void checkStats(int atk, float intel, int hp, int luk, int dex){
	cout << "atk: " <<atk<<endl;
    cout << "intel: " <<intel<<endl;
    cout << "luk: "<<luk<<endl;
    cout << "dex: "<<dex<<endl;
    cout << "hp: "<<hp<<endl;
    cout << endl;
    
    cout << "======================================================================================================================="<<endl <<endl;
}


int battle(int atk, float intel, int hp, int luk, int dex, int enemy_hp, int enemy_atk){
	int roll, win;
	string option;
	
	srand (time(NULL));
	
	checkStats(atk, intel , hp , luk, dex);
	
        cout << "An enemy has appeared!"<<endl;
        cout << endl;

        while (enemy_hp > 0 && hp > 0){                           //battle stage
        cout<< "current hp: " << hp << endl;
        cout << endl;
        cout << "enemy hp: " << enemy_hp <<endl;
        cout << endl;
        cout << "attack or fireball?"<<endl;
        cin >> option;

        if (option == "attack"){                          //attack
            roll = rand() % 100 + 1;
            if (roll > luk){
                enemy_hp = enemy_hp - atk;
                cout << atk << " damage!" << endl;
                cout<< endl;
            }
            else {                                      //crit
                cout << "CRITICAL HIT !!" << endl;
                enemy_hp = enemy_hp - (atk*2);
                cout << atk*2 << " damage!" << endl;
                cout<< endl;
            }

            }

            else if (option == "fireball" || option == "fire") {
                    enemy_hp = enemy_hp - floor(intel);         //fireball
                    cout << "enemy burned for " << floor(intel) << " damage!"<<endl;
                    cout<<endl;
                    intel = intel + 0.5;                   //intel stack
                    cout << "Your spellcasting skills increase." << endl;
                    }

            else {
                cout << "You mumble your incantation. Spellcast failed!" << endl;
                cout << endl;
            }


            if (enemy_hp >0){
            cout << "Enemy attacks!" << endl;
            cout << endl;

            roll = rand() % 100 + 1;

            if (roll > dex){
                cout << "Enemy hits you for " << enemy_atk << " damage!" << endl;
                cout << endl;
                hp = hp - enemy_atk;


            }

            else {

                cout << "Enemy miss " << enemy_atk << " damage avoided!" << endl;
                cout << endl;
            }
            }
            cout << "======================================================================================================================="<<endl;




        }

        cout << endl;

        if (enemy_hp <= 0){
        cout << "Enemy defeated." << endl << endl;
        cout << "VICTORY" << endl;
        win = ((floor(intel))*10)+1;
        }

        else if (hp <= 0) {
        cout << "You've met with a terrible fate, haven't you?" <<endl<<endl;
        cout << "DEFEAT" << endl;

		win= 0;
        }
        cout << "======================================================================================================================="<<endl <<endl;
        return win;
}


int shop(int gold){
	int cost, option=0;
	
	cout << "You enter the shady looking tent.\n";
	cout << "The interior is dimly lit and the shelves are littered with all sorts of adventuring paraphernalia.\nThe faint smell of soup hangs in the air.\n";
	cout << "The shopkeep stands behind the counter muttering to himself.\n";
	cout << "Suddenly he looks up and begins to mutter even faster. " << endl;
	cout << "From behind the counter a small lemur appears and introduces itself as Zacaen. " << endl;
	cout << "Zacaen: Would you like to browse my wares?" <<endl <<endl;
	cout << "1 sword\t\t\t\t\t15G\n2 bigger sword\t\t\t\t30G\n3 unnecesssarily large sword\t\t100G" << endl <<endl;
	cout << "Zacaen: Which will you buy 1, 2 or 3?" << endl;
	cin >> option;
			// FINISH AND FIX THE SHOP YOU FUCK
	return 0;
}





int main(){

int atk, intel, constitution, hp, luk, dex, enemyHp, enemyAtk, roll, wincheck, weaponMod=1, gold=0, enemyAtkMAX=5, enemyHpMAX=10, enemyAtkMIN=3, enemyHpMIN=90;
string option;

    
	
	srand (time(NULL));                                //stat roll
    atk = rand() % 10 + 1;
    luk = rand() % 100 + 1;
    dex = rand() % 15 + 1;
    intel = rand() % 10 + 1;
    constitution = rand() % 5 + 5;
    hp = constitution*10;
	
	
	
	while (option != "exit"){
		
	cout << "| battle | stats | shop | exit |" << endl;
	cout << "select an option: ";
	cin >> option;
    
    if (option == "battle"){
    enemyHp = rand() % enemyHpMAX + enemyHpMIN;
    enemyAtk = rand() % enemyAtkMAX + enemyAtkMIN;

	
	wincheck = battle(atk*weaponMod, intel, hp, luk, dex, enemyHp, enemyAtk);
    
    intel = (wincheck/10);
    
    wincheck = wincheck%10;
    
    if (wincheck == 1){
	
    gold = gold+(enemyHp/10)+enemyAtk;
        cout << endl << "You find " << gold << "G in the enemy's coinpurse."<< endl << endl;
        enemyHpMAX = enemyHpMAX + 20;
        enemyHpMIN = enemyHpMIN + 20;
        enemyAtkMAX = enemyAtkMAX + 3;
        enemyAtkMIN = enemyAtkMIN + 3;
		}
	}
	
	
	else if (option == "stats"){
		checkStats(atk, intel , hp , luk, dex);
	}
	
	
	else if (option == "shop"){
		shop(gold);
		
	}
	
	
	
	
	
	        
}

    return 0;
}
