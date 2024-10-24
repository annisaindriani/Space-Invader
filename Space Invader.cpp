// 2502028821 - C Project

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define MAXHP 300
#define MAXENERGY 500
#define MAXARMOR 30

int i = 0;
int index = 0;
int countPlayer = 0;

const int rLobby = 22;
const int cLobby = 35;
const int rGame = 22;
const int cGame = 50;
char mapLobby[rLobby+1][cLobby+1];
char mapGame[rGame+1][cGame+1];
char defaultSS[7][9];
char greatSS[7][10];
char littleSS[5][5];
char rocketSS[7][10];
int posX = 19; // ROW player
int posY = 17; // COLL player

struct Player{
	char name[127];
	int money;
	int xp;
	int level;
	int hp;
	int energy;
	int armor;
	int damage;
	int potion;
	int maxPotion;
	int drink;
	int maxDrink;
	int bomb;
	int score;
} newPlayer[200];

struct GamePlayer{
	char name[127];
	int score;
} activePlayer[200];

void loadPlayer(){
	FILE *player = fopen("database/player.dat", "r");
	
	while(fscanf(player, "%[^\#]#%d#%d#%d#%d#%d#%d#%d\n", newPlayer[i].name, &newPlayer[i].money, &newPlayer[i].xp, &newPlayer[i].level, &newPlayer[i].hp, &newPlayer[i].energy, &newPlayer[i].armor, &newPlayer[i].damage) != EOF){
		printf("%d\n", i);
		i++;
	}
	
	fclose(player);
	
}

void loadScore(){
	FILE *sc = fopen("database/score.dat", "r");
	
//	int count = 0;
	while(fscanf(sc, "%[^\#]#%d\n", activePlayer[countPlayer].name, &activePlayer[countPlayer].score) != EOF){ 
		countPlayer++;
	}

	fclose(sc);
	
}

void printGameLobby(){
	mapLobby[16][6] = 'U';
	mapLobby[4][26] = 'W';
	mapLobby[16][27] = 'I';
	
	for(int j=0; j<rLobby; j++){
		for(int k=0; k<cLobby; k++){
			printf("%c", mapLobby[j][k]);
		}
		puts("");
	}
}

void gameLobby(){
	FILE *lobby = fopen("assets/lobby.txt", "r");
	
	int count = 0;
	while(fscanf(lobby, "%[^\n]\n", mapLobby[count]) != EOF){
		count++;
	}
	
	fclose(lobby);
	
}

void printGameMap(){
	for(int j=0; j<rGame; j++){
		for(int k=0; k<cGame; k++){
			printf("%c", mapGame[j][k]);
		}
		puts("");
	}
}

void gameMap(){
	FILE *map = fopen("assets/game.txt", "r");
	
	int count = 0;
	while(fscanf(map, "%[^\n]\n", mapGame[count]) != EOF){
		count++;
	}
	
	fclose(map);
	
}

void printDefaultSS(){
	defaultSS[4][2] = 'v';
	defaultSS[4][0] = ' ';

	for(int j=0; j<6; j++){
		printf("\t\t");
		for(int k=0; k<8; k++){
			printf("%c", defaultSS[j][k]);
		}
		puts("");
	}
}

void defaultSpaceship(){
	FILE *def = fopen("assets/space_1.txt", "r");
	
	int count = 0;
	while(fscanf(def, "%[^\n]\n", defaultSS[count]) != EOF){
		count++;
	}
	
	fclose(def);
	
}

void printGreatSS(){
	greatSS[4][0] = ' ';
	greatSS[4][3] = 'v';
	greatSS[1][0] = ' ';
	greatSS[1][1] = '/';
	greatSS[1][4] = ' ';
	greatSS[1][5] = '\\';
	greatSS[3][0] = ' ';
	greatSS[3][1] = '\\';
	greatSS[3][2] = '_';
	greatSS[3][3] = '_';
	greatSS[3][4] = '_';
	greatSS[3][5] = '/';
	
	for(int j=0; j<6; j++){
		printf("\t\t");
		for(int k=0; k<9; k++){
			printf("%c", greatSS[j][k]);
		}
		puts("");
	}
}

void greatSpaceship(){
	FILE *great = fopen("assets/space_2.txt", "r");
	
	int count = 0;
	while(fscanf(great, "%[^\n]\n", greatSS[count]) != EOF){
		count++;
	}
	
	fclose(great);
	
}

void printLittleSS(){
	littleSS[3][0] = ' ';
	littleSS[3][1] = 'v';
	
	for(int j=0; j<4; j++){
		printf("\t\t");
		for(int k=0; k<4; k++){
			printf("%c", littleSS[j][k]);
		}
		puts("");
	}
}

void littleSpaceship(){
	
	FILE *little = fopen("assets/space_3.txt", "r");
	
	int count = 0;
	while(fscanf(little, "%[^\n]\n", littleSS[count]) != EOF){
		count++;
	}
	
	fclose(little);
}

void printRocketSS(){
	rocketSS[4][0] = ' ';
	rocketSS[4][3] = 'v';
	
	for(int j=0; j<6; j++){
		printf("\t\t");
		for(int k=0; k<9; k++){
			printf("%c", rocketSS[j][k]);
		}
		puts("");
	}
}

void rocketSpaceship(){
	FILE *rocket = fopen("assets/space_4.txt", "r");
	
	int count = 0;
	while(fscanf(rocket, "%[^\n]\n", rocketSS[count]) != EOF){
		count++;
	}
	
	fclose(rocket);
}

void upgradeShop(int choose){

	puts("");
	puts("\nHohoo! This is an upgrade shop");
	printf("Any thing i can do for you ? [y\\n]");
	
	while(true){
		if(kbhit){
			char input = getch();
			
			if((int)input == 121){	
				while(true){
					system("cls");
					puts("");
					puts("\tDo you need anything to upgrade ?");
					printf("\t1. HP %d/300 - $50\n", newPlayer[choose-1].hp);
					printf("\t2. Energy %d/500 - $50\n", newPlayer[choose-1].energy);
					printf("\t3. Armor %d/30 - $30\n", newPlayer[choose-1].armor);
					printf("\t4. Back\n");
					printf("\t>> ");
					
					int choice;
					scanf("%d", &choice);
					getchar();
					
					int flag = 0;
					
					switch(choice){
						case 1:
							if(newPlayer[choose-1].money >= 50 && newPlayer[choose-1].hp < MAXHP){
								newPlayer[choose-1].money -= 50;
								newPlayer[choose-1].hp++;
								printf("\n\tSuccesfully upgraded skills [press enter]");
								getchar();
							} else if(newPlayer[choose-1].hp == MAXHP){
								printf("\n\tYou already at the max levels [press enter]");
								getchar();
							} else if(newPlayer[choose-1].money < 50){
								printf("\n\tYou don't have enough money! [press enter]");
								getchar();
							}	
							
							break;
							
						case 2:
							if(newPlayer[choose-1].money >= 50 && newPlayer[choose-1].energy < MAXENERGY){
								newPlayer[choose-1].money -= 50;
								newPlayer[choose-1].energy++;
								printf("\n\tSuccesfully upgraded skills [press enter]");
								getchar();
							} else if(newPlayer[choose-1].energy == MAXENERGY){
								printf("\n\tYou already at the max levels [press enter]");
								getchar();
							} else if(newPlayer[choose-1].money < 50){
								printf("\n\tYou don't have enough money! [press enter]");
								getchar();
							}	
							
							break;
							
						case 3:
							if(newPlayer[choose-1].money >= 30 && newPlayer[choose-1].armor < MAXARMOR){
								newPlayer[choose-1].money -= 30;
								newPlayer[choose-1].armor++;
								printf("\n\tSuccesfully upgraded skills [press enter]");
								getchar();
							} else if(newPlayer[choose-1].armor == MAXARMOR){
								printf("\n\tYou already at the max levels [press enter]");
								getchar();
							} else if(newPlayer[choose-1].money < 30){
								printf("\n\tYou don't have enough money! [press enter]");
								getchar();
							}	
							
							break;
							
						case 4:
							puts("");
							printf("\tGood bye! Dont forget to came again [press enter]");
							flag = 1;
							break;
							
						default:
							break;
							
					}
					
					if(flag == 1)
						break;
				}
				
			} else{
				break;	
			}
			
			break;
		}		
	}	
}

void itemShop(int choose){

	puts("");
	puts("\nWelcome to item shop!");
	printf("Do you want to buy any item ? [y\\n]");
	
	while(true){
		if(kbhit){
			char input = getch();
			
			if((int)input == 121){
				while(true){
					system("cls");
					puts("");
					puts("\tWelcome to the item shop");
					printf("\t1. Potion [$5]\n");
					printf("\t2. Max Potion [$20]\n");
					printf("\t3. Energy Drink [$3]\n");
					printf("\t4. Max Energy Drink [$15]\n");
					printf("\t5. Bomb [$10]\n");
					printf("\t6. Back\n");
					printf("\t>> ");
					
					int choice;
					scanf("%d", &choice);
					getchar();
					
					int flag = 0;
					int qty = 0;
					int price = 0;
					
					switch(choice){
						case 1:
							puts("");
							puts("\n\tHow many Potion do you want to buy ?");
							printf("\t- ");
							scanf("%d", &qty);
							getchar();
							
							price = qty*5;
							
							if(newPlayer[choose-1].money >= price){
								newPlayer[choose-1].money -= price;
								newPlayer[choose-1].potion += qty;
								printf("\n\tSuccesfully Purchased %d Potion [press enter]", qty);
								getchar();
							} else{
								printf("\n\tYou don't have enough money! [press enter]");
								getchar();
							}
							
							break;
							
						case 2:
							puts("");
							puts("\n\tHow many Max Potion do you want to buy ?");
							printf("\t- ");
							scanf("%d", &qty);
							getchar();
							
							price = qty*20;
							
							if(newPlayer[choose-1].money >= price){
								newPlayer[choose-1].money -= price;
								newPlayer[choose-1].maxPotion += qty;
								printf("\n\tSuccesfully Purchased %d Max Potion [press enter]", qty);
								getchar();
							} else{
								printf("\n\tYou don't have enough money! [press enter]");
								getchar();
							}
							
							break;
							
						case 3:
							puts("");
							puts("\n\tHow many Energy Drink do you want to buy ?");
							printf("\t- ");
							scanf("%d", &qty);
							getchar();
							
							price = qty*3;
							
							if(newPlayer[choose-1].money >= price){
								newPlayer[choose-1].money -= price;
								newPlayer[choose-1].drink += qty;
								printf("\n\tSuccesfully Purchased %d Energy Drink [press enter]", qty);
								getchar();
							} else{
								printf("\n\tYou don't have enough money! [press enter]");
								getchar();
							}
							
							break;
							
						case 4:
							puts("");
							puts("\n\tHow many Max Energy Drink do you want to buy ?");
							printf("\t- ");
							scanf("%d", &qty);
							getchar();
							
							price = qty*15;
							
							if(newPlayer[choose-1].money >= price){
								newPlayer[choose-1].money -= price;
								newPlayer[choose-1].maxDrink += qty;
								printf("\n\tSuccesfully Purchased %d Max Energy Drink [press enter]", qty);
								getchar();
							} else{
								printf("\n\tYou don't have enough money! [press enter]");
								getchar();
							}
							
							break;
							
						case 5:
							puts("");
							puts("\n\tHow many Bomb do you want to buy ?");
							printf("\t- ");
							scanf("%d", &qty);
							getchar();
							
							price = qty*10;
							
							if(newPlayer[choose-1].money >= price){
								newPlayer[choose-1].money -= price;
								newPlayer[choose-1].bomb += qty;
								printf("\n\tSuccesfully Purchased %d Bomb [press enter]", qty);
								getchar();
							} else{
								printf("\n\tYou don't have enough money! [press enter]");
								getchar();
							}
							
							break;
							
						case 6:
							puts("");
							printf("\tSee you again! [press enter]");
							flag = 1;
						default:
							break;
					}
					
					if(flag == 1)
						break;
				}

			} else{
				break;	
			}
			
			break;	
		}
	}		
}

void sortScore(){
	for(int j=0; j<countPlayer-1; j++)
	{
		struct GamePlayer temp;
		for(int k=0; k<(countPlayer-1-j); k++)
		{
			if(activePlayer[k].score < activePlayer[k+1].score)
			{
				temp = activePlayer[k];
				activePlayer[k] = activePlayer[k+1];
				activePlayer[k+1] = temp;
			} else if(activePlayer[k].score == activePlayer[k+1].score){
				if(strcmp(activePlayer[k].name, activePlayer[k+1].name) > 0)
				{
					temp = activePlayer[k];
					activePlayer[k] = activePlayer[k+1];
					activePlayer[k+1] = temp;
				}
			}
		}
	}
}

void scoreboard(){	
	sortScore();
	
	system("cls");
	puts("");
	puts("\tC Space Invader Scoreboard");
	puts("\t============================");
	puts("");
	
	for(int j=0; j<countPlayer; j++){
		printf("\t%d. %s\t| %d\n", j+1, activePlayer[j].name, activePlayer[j].score);
	}
	
	puts("");
	printf("\tBack to menu ? [press enter]");
}

void spaceshipStation(int index){

	puts("");
	puts("\nWelcome to Spaceship Station");
	printf("Do you want to buy any weapon ? [y\\n]");
	
	int flag = 0;
	while(true){
		if(kbhit){
			char input = getch();
			
			if((int)input == 121){
				int index = 0;
				
				while(true){
					system("cls");
					puts("\n\tWelcome to the station!");
					puts("\t Select your spaceship!");
					
					if(index == 0){
						puts("");
						puts("\t  Default Spaceship\n");
						printDefaultSS();
					} else if(index == 1){
						puts("");
						puts("\t    Great Spaceship\n");
						printGreatSS();
					} else if(index == 2){
						puts("");
						puts("\t   Little Spaceship\n");
						printLittleSS();
					} else if(index == 3){
						puts("");
						puts("\t   Rocket Spaceship\n");
						printRocketSS();
					}
						
					printf("\n\t[press enter to choose]\n");
					puts("\t< ------------------- >");
					
					if(kbhit){
						char input = getch();
									
						if((int)input == 68 || (int)input == 100){
							if(index == 3){
								index = 0;
							} else{
								index++;
							}
							
						} else if((int) input == 65 || (int) input == 97){
							if(index == 0){
								index = 3;
							} else{
								index--;
							}
							
						} else if((int) input == 13){
							flag = 1;
						}
					}
					
					if(flag == 1)
						break;
				}	
				
			} else{
				break;
			} 
			
			break;
		}	
	}
}

void saveScore(int choose){
	int ctr = 0;
	
	sortScore();
	
	FILE *fp = fopen("database/score.dat", "w");
	
	int jejak = 0;
	for(int j=0; j<countPlayer; j++){
		if(strcmp(activePlayer[j].name, newPlayer[choose-1].name) == 0){
			if(activePlayer[j].score < newPlayer[choose-1].score){
				activePlayer[j].score = newPlayer[choose-1].score;
				jejak++;
				
				if(jejak <= 1){
					fprintf(fp, "%s#%d\n", activePlayer[j].name, activePlayer[j].score);
				}
			}
			ctr = 10; // cuma nandain aja kl dia udah ada apa blm
		} else{
			fprintf(fp, "%s#%d\n", activePlayer[j].name, activePlayer[j].score);
		}
	}
	
	if(ctr != 10){
		fprintf(fp, "%s#%d\n", newPlayer[choose-1].name, newPlayer[choose-1].score);

	}
	
	fclose(fp);
}

void gameOver(int choose, int scoreGame){
	newPlayer[choose-1].score = scoreGame;
	int xp = scoreGame * 0.75;
	
	system("cls");	
	puts("\n\tC Space Invader");
	puts("\t------------------");
	printf("\tYour score : %d\n", newPlayer[choose-1].score);
	printf("\tYou gain %d exp\n", xp);
	
	while(xp > 100){
		xp -= 100;
		newPlayer[choose-1].level++;
		
	}
	
	printf("\tYour current level is : %d\n", newPlayer[choose-1].level);
	
	saveScore(choose);
	
	printf("\n\tContinue Game [press enter]");
	
}

void gameArena(int choose, int index){
	system("cls");
	
	gameMap();
	printGameMap();
	
	puts("");
	puts("\n\t   C Space Invader");
	
	if(index == 0){
		puts("");
		puts("\t  Default Spaceship\n");		
		printDefaultSS();
	} else if(index == 1){
		puts("");
		puts("\t    Great Spaceship\n");
		printGreatSS();
	} else if(index == 2){
		puts("");
		puts("\t   Little Spaceship\n");
		printLittleSS();
	} else if(index == 3){
		puts("");
		puts("\t   Rocket Spaceship\n");
		printRocketSS();
	}
		
	int scoreGame = 200;
	printf("\nScore : %d\n", scoreGame);
	
	int bullets = 0;
	printf("Bullets %d/10\n", bullets);
		
	printf("\nHP [%d/100]\n", newPlayer[choose-1].hp);
	printf("Energy [%d/50]\n", newPlayer[choose-1].energy);
	getchar();
	
	gameOver(choose, scoreGame);
		
}

void savePlayer(Player newPlayer[], int choose){

	int ctr = 0;
			
	FILE *fp = fopen("database/player.dat", "w");
	
	for(int j=0; j<i; j++){
		if(strcmp(newPlayer[j].name, newPlayer[choose-1].name) == 0){
			newPlayer[j].money = newPlayer[choose-1].money;
			newPlayer[j].xp = newPlayer[choose-1].xp;
			newPlayer[j].level = newPlayer[choose-1].level;
			newPlayer[j].hp = newPlayer[choose-1].hp;
			newPlayer[j].energy = newPlayer[choose-1].energy;
			newPlayer[j].armor = newPlayer[choose-1].armor;
			newPlayer[j].damage = newPlayer[choose-1].damage;
			
			ctr = 10; // cuma nandain aja kl dia udah ada apa blm
		}
		
		fprintf(fp, "%s#%d#%d#%d#%d#%d#%d#%d\n", newPlayer[j].name, newPlayer[j].money, newPlayer[j].xp, 
		newPlayer[j].level, newPlayer[j].hp, newPlayer[j].energy, newPlayer[j].armor, newPlayer[j].damage);
		
	}
	
	if(ctr != 10){
		fprintf(fp, "%s#%d#%d#%d#%d#%d#%d#%d\n", newPlayer[choose-1].name, newPlayer[choose-1].money, newPlayer[choose-1].xp, 
		newPlayer[choose-1].level, newPlayer[choose-1].hp, newPlayer[choose-1].energy, newPlayer[choose-1].armor, newPlayer[choose-1].damage);

	}
	
	fclose(fp);
	
}

void showBackpack(int choose){
	system("cls");
		puts("");
		printf("\n\t%s backpack's\n", newPlayer[choose-1].name);
		puts("\t=====================");
		
		if(newPlayer[choose-1].potion != 0){
			printf("\t- Potion : %d\n", newPlayer[choose-1].potion);
		} 
		
		if(newPlayer[choose-1].maxPotion != 0){
			printf("\t- Max Potion : %d\n", newPlayer[choose-1].maxPotion);
		} 
		
		if(newPlayer[choose-1].drink != 0){
			printf("\t- Energy Drink : %d\n", newPlayer[choose-1].drink);
		} 
		
		if(newPlayer[choose-1].maxDrink != 0){
			printf("\t- Max Energy Drink : %d\n", newPlayer[choose-1].maxDrink);
		} 
		
		if (newPlayer[choose-1].bomb != 0){
			printf("\t- Bomb : %d\n", newPlayer[choose-1].bomb);
		}
		
		puts("");	
		printf("\tback to game [press enter]");	
		getchar();
		
}

int moveLobby(Player newPlayer[], int choose){
	char input = getch();
	
	if(posX == 10 && posY == 17){
		puts("");
		printf("\nPress SPACE To Interact");
		while(true){
			if(kbhit){
				char input = getch();
			
				if((int)input == 32){
					gameArena(choose, index);
				} else{
					break;		
				}
			}		
		}
	}
	
	if(input == 'w' || input == 'W'){ // ATAS
		mapLobby[posX][posY] = ' ';
		
		if(mapLobby[posX-1][posY] == 'U'){
			puts("");
			printf("\nPress SPACE To Interact");
			while(true){
				if(kbhit){
					char input = getch();
			
					if((int)input == 32){
						upgradeShop(choose);
					} else{
						break;		
					}
				}		
			}
		} else if(mapLobby[posX-1][posY] == 'I'){
			puts("");
			printf("\nPress SPACE To Interact");
			while(true){
				if(kbhit){
					char input = getch();
			
					if((int)input == 32){
						itemShop(choose);
					} else{
						break;		
					}
				}		
			}
		} else if(mapLobby[posX-1][posY] == 'W'){
			puts("");
			printf("\nPress SPACE To Interact");
			while(true){
				if(kbhit){
					char input = getch();
			
					if((int)input == 32){
						spaceshipStation(index);
					} else{
						break;		
					}
				}		
			}
		} else if(mapLobby[posX-1][posY] == '-'){
			puts("");
			puts("\nYou need level 10 to unlock spaceship");
			printf("Press enter to continue...");
			getchar();
		} else if(mapLobby[posX-1][posY] != '#' && mapLobby[posX-1][posY] != '.' && mapLobby[posX-1][posY] != '/' && 
			mapLobby[posX-1][posY] != '\\' && mapLobby[posX-1][posY] != '_' && mapLobby[posX-1][posY] != '|'){
			posX--;
		}
			
	} else if(input == 'a' || input == 'A'){ // KIRI
		mapLobby[posX][posY] = ' ';
		
		if(mapLobby[posX][posY-1] == 'U'){
			puts("");
			printf("\nPress SPACE To Interact");
			while(true){
				if(kbhit){
					char input = getch();
			
					if((int)input == 32){
						upgradeShop(choose);
					} else{
						break;		
					}
				}		
			}
		} else if(mapLobby[posX][posY-1] == 'I'){
			puts("");
			printf("\nPress SPACE To Interact");
			while(true){
				if(kbhit){
					char input = getch();
			
					if((int)input == 32){
						itemShop(choose);
					} else{
						break;		
					}
				}		
			}
		} else if(mapLobby[posX][posY-1] == '|'){
			puts("");
			printf("\nPress SPACE to see Leaderboard");
			while(true){
				if(kbhit){
					char input = getch();
			
					if((int)input == 32){
						scoreboard();
					} else{
						break;		
					}
				}		
			}
		} else if(mapLobby[posX][posY-1] == 'W'){
			puts("");
			printf("\nPress SPACE To Interact");
			while(true){
				if(kbhit){
					char input = getch();
			
					if((int)input == 32){
						spaceshipStation(index);
					} else{
						break;		
					}
				}		
			}
		} else if(mapLobby[posX][posY-1] == '-'){
			puts("");
			puts("\nYou need level 10 to unlock spaceship");
			printf("Press enter to continue...");
			getchar();
		} else if(mapLobby[posX][posY-1] != '#' && mapLobby[posX][posY-1] != '.' && mapLobby[posX][posY-1] != '/' && mapLobby[posX][posY-1] != '\\' && mapLobby[posX][posY-1] != '_'){
			posY--;
		}
		
	} else if(input == 's' || input == 'S'){ // BAWAH
		mapLobby[posX][posY] = ' ';
		
		if(mapLobby[posX+1][posY] == 'U'){
			puts("");
			printf("\nPress SPACE To Interact");
			while(true){
				if(kbhit){
					char input = getch();
			
					if((int)input == 32){
						upgradeShop(choose);
					} else{
						break;		
					}
				}		
			}
		} else if(mapLobby[posX+1][posY] == 'I'){
			puts("");
			printf("\nPress SPACE To Interact");
			while(true){
				if(kbhit){
					char input = getch();
			
					if((int)input == 32){
						itemShop(choose);
					} else{
						break;		
					}
				}		
			}
		} else if(mapLobby[posX+1][posY] == 'W'){
			puts("");
			printf("\nPress SPACE To Interact");
			while(true){
				if(kbhit){
					char input = getch();
			
					if((int)input == 32){
						spaceshipStation(index);
					} else{
						break;		
					}
				}		
			}
		} else if(mapLobby[posX+1][posY] == '='){
			puts("");
			printf("\nPress SPACE to Exit!");
			while(true){
				if(kbhit){
					char input = getch();
			
					if((int)input == 32){
						savePlayer(newPlayer, choose);
						return 1;
					} else{
						break;		
					}
				}		
			}			
		} else if(mapLobby[posX+1][posY] == '-'){
			puts("");
			puts("\nYou need level 10 to unlock spaceship");
			printf("Press enter to continue...");
			getchar();
		} else if(mapLobby[posX+1][posY] != '#' && mapLobby[posX+1][posY] != '.' && mapLobby[posX+1][posY] != '/' && 
			mapLobby[posX+1][posY] != '\\' && mapLobby[posX+1][posY] != '_' && mapLobby[posX+1][posY] != '|'){
			posX++;
		}
		
	} else if(input == 'd' || input == 'D'){ // KANAN
		mapLobby[posX][posY] = ' ';
		
		if(mapLobby[posX][posY+1] == 'U'){
			puts("");
			printf("\nPress SPACE To Interact");
			while(true){
				if(kbhit){
					char input = getch();
			
					if((int)input == 32){
						upgradeShop(choose);
					} else{
						break;		
					}
				}		
			}		
		} else if(mapLobby[posX][posY+1] == 'I'){
			puts("");
			printf("\nPress SPACE To Interact");
			while(true){
				if(kbhit){
					char input = getch();
			
					if((int)input == 32){
						itemShop(choose);
					} else{
						break;		
					}
				}		
			}	
		} else if(mapLobby[posX][posY+1] == 'W'){
			puts("");
			printf("\nPress SPACE To Interact");
			while(true){
				if(kbhit){
					char input = getch();
			
					if((int)input == 32){
						spaceshipStation(index);
					} else{
						break;		
					}
				}		
			}	
		} else if(mapLobby[posX][posY+1] == '-'){
			puts("");
			puts("\nYou need level 10 to unlock spaceship");
			printf("Press enter to continue...");
			getchar();
		} else if(mapLobby[posX][posY+1] != '#' && mapLobby[posX][posY+1] != '.' && mapLobby[posX][posY+1] != '/' && 
			mapLobby[posX][posY+1] != '\\' && mapLobby[posX][posY+1] != '_' && mapLobby[posX][posY+1] != '|'){
			posY++;
		}

	} else if(input == 'o' || input == 'O'){
		showBackpack(choose);
	}
	
}

void gamePlay(Player newPlayer[], int choose){
	gameLobby();
	defaultSpaceship();
	greatSpaceship();
	littleSpaceship();
	rocketSpaceship();
	
	while(true){
		system("cls");
		mapLobby[posX][posY] = 'P';
	
		if(newPlayer[choose-1].level < 10){
			mapLobby[6][6] = '-';
			mapLobby[6][7] = '-';
			mapLobby[6][8] = '-';
			mapLobby[6][9] = '-';
		} else{
			mapLobby[7][5] = '/';
			mapLobby[7][10] = '\\';
		}
		
		printGameLobby();
	
		puts("");
		printf("[%s]\n", newPlayer[choose-1].name);
		printf("Level : %d\n", newPlayer[choose-1].level);
		printf("Money : %d\n", newPlayer[choose-1].money);
		puts("");
		printf("Choose [w|a|s|d] to move >> ");
		
		int flag = moveLobby(newPlayer, choose);
		
		if(flag == 1)
			break;
		
	}

	
}

void gamePlayer(Player newPlayer[]){	
	char username[127];
	
	while(true){
		system("cls");
		
		printf("\n\tSelect Your Name : ");
		scanf("%[^\n]", username);
		getchar();
	
		int ctr = 0;
		for(int j=0; j<i; j++){
			if(strcmp(username, newPlayer[j].name) == 0){
				ctr = 1;
				break;
			} 
		}
		
		if(ctr == 1){
			printf("\tSorry but name already exists! [press enter] ");
			getchar();
		} else{
			break;
		}
		
	}
	
	
	strcpy(newPlayer[i].name, username);
	newPlayer[i].money = 0;
	newPlayer[i].xp = 0;
	newPlayer[i].level = 0;
	newPlayer[i].hp = 100;
	newPlayer[i].energy = 50;
	newPlayer[i].armor = 1;
	newPlayer[i].damage = 1;
	i++;
	
	gamePlay(newPlayer, i);
	
}

void gameLoad(Player newPlayer[]){
	system("cls");	
	puts("\n\tSave Data : ");
	
	for(int j=0; j<i; j++){
		printf("\t%d. %s [Level : %d]\n", j+1, newPlayer[j].name, newPlayer[j].level);
		
		if(j == i-1){
			printf("\t%d. Back\n", j+2);
		}
		
		
	}
	
	printf("\t>> ");
	
	int choose;
	scanf("\t%d", &choose);
	getchar();
	
	if(choose != i+1){
		gamePlay(newPlayer, choose);
	}
	
}

void gameTutorial(){
	system("cls");
	puts("");
	puts("\tSpace Invader");
	puts("");
	puts("");
	puts("\tThe object of the game is, basically, to shoot the invaders with your shooter");
	puts("\twhile avoiding their shots and preventing an invasion  Amassing a high score is a further");
	puts("\tobjective and one that must be prioritised against your continued survival.");
	puts("");
	puts("");
	puts("\tThere is no time limit,");
	puts("\texcept for the fact that if you do not shoot them all before they reach");
	puts("\tthe bottom of the screen the game ends.");
	puts("");
	puts("");
	puts("\tCredit : TinTin Winata");
	puts("");
	printf("\tBack to menu ? [press enter]");
	getchar();
	
}

void gameSetting(){
	system("cls");
	puts("");
	puts("\tWelcome to the game!");
	puts("");
	puts("\tBasic Movement");
	puts("\t'w' - Move Up");
	puts("\t'a' - Move Left");
	puts("\t's' - Move Down");
	puts("\t'd' - Move Right");
	puts("");
	puts("\tLobby Arena");
	puts("\t'SPACE' - Intersect");
	puts("\t'y' - Talk");
	puts("\t'o' - Open Backpack");
	puts("");
	puts("\tGame Arena");
	puts("\t'SPACE' - Shoot");
	puts("\t'r' - Reload");
	puts("\t'f' - Skill");
	puts("\t'1' - Use Potion");
	puts("\t'2' - Use Max Potion");
	puts("\t'3' - Use Energy");
	puts("\t'4' - Use Max Energy");
	puts("\t'g' - Use Bomb");
	puts("");
	printf("\tBack to menu ? [press enter]");
	getchar();
	
}

int main(){
	loadPlayer();
	loadScore();
	
	while(true){
		system("cls");
		puts("\n\tC SPACE INVADER");
		puts("\t1. NEW GAME");
		puts("\t2. LOAD GAME");
		puts("\t3. SETTING");
		puts("\t4. HOW TO PLAY");
		puts("\t5. EXIT");
		printf("\t>> ");
		
		int menu;
		scanf("%d", &menu);
		getchar();
		
		int flag = 0;
		switch(menu){
			case 1:
				gamePlayer(newPlayer);
				break;
			
			case 2:
				gameLoad(newPlayer);
				break;
				
			case 3:
				gameSetting();
				break;
				
			case 4:
				gameTutorial();
				break;
				
			case 5:
				system("cls");
				puts("\nAlongside courage and perseverance, we shape and define our future.\nJT 22-1");
				flag = 1;
				break;
			
			default:
				break;
		}
		
		if(flag == 1)
			break;
			
	}
	
}
