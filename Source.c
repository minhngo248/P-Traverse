/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include "header.h"

void resizeConsole(int width, int height) {
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, width, height, TRUE);    
}

void textcolor(int x) {
    HANDLE couleur;
    couleur = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(couleur,x);
}

void gotoxy(int x, int y) { //x: colonne, y: ligne
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = {y-1,x-1};   
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);    
    SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}

void Screen() { //table du jeu
    int i,j;
    for(i=1;i<=50;i++) {
        for(j=1;j<=50;j++) {
            if((1 <= i&&i <= 5)||(11<=i && i<=15)||(21<=i && i<=25)||(31<=i&&i<=35)||(41<=i&&i<=45)) {
                if((1 <= j&&j <= 5)||(11<=j && j<=15)||(21<=j && j<=25)||(31<=j&&j<=35)||(41<=j&&j<=45)) {
                    textcolor(112); //ajout de couleur
                    printf(" ");
                }
                else {
                    textcolor(56); //ajout de couleur
                    printf(" ");
                }
            }
            else {
                if((1 <= j&&j <= 5)||(11<=j && j<=15)||(21<=j && j<=25)||(31<=j&&j<=35)||(41<=j&&j<=45)) {
                    textcolor(56);
                    printf(" ");
                }
                else {
                    textcolor(112);
                    printf(" ");
                }                
            }
        }
        printf("\n");
    }
    for(i=0;i<10;i++) {
        gotoxy(51,5*i+3);
        textcolor(1);
        printf("%d",i);
    }
    for(i=0;i<10;i++) {
        gotoxy(5*i+3,51);
        textcolor(1);
        printf("%d",i);
    }
}

void initialVal1(Valeur Val[][10]) { //initial mode 1 joueur 
    int i;
    for(i=4;i>=1;i--) {
        Val[0][i].data = 5-i;
        Val[0][9-i].data = 5-i;
        Val[0][i].cou = 62;
        Val[0][9-i].cou = 62;        
    }
    for(i=4;i>=1;i--) {
        Val[9][i].data = 5-i;
        Val[9][9-i].data = 5-i;
        Val[9][i].cou = 72;
        Val[9][9-i].cou = 72;        
    }   
}

void initialVal2(Valeur Val[][10]) { //initial mode 2 joueurs
    int i;
    for(i=4;i>=1;i--) {
        Val[0][i].data = 5-i;
        Val[0][9-i].data = 5-i;
        Val[0][i].cou = 62;
        Val[0][9-i].cou = 62;        
    }
    for(i=4;i>=1;i--) {
        Val[9][i].data = 5-i;
        Val[9][9-i].data = 5-i;
        Val[9][i].cou = 70;
        Val[9][9-i].cou = 70;        
    }   
}

void initialVal3(Valeur Val[][10]) { //initial mode 3 joueurs
    int i;
    for(i=4;i>=1;i--) { //joueur 1
        Val[0][i].data = 5-i;
        Val[0][9-i].data = 5-i;
        Val[0][i].cou = 62;
        Val[0][9-i].cou = 62;        
    }   
    for(i=4;i>=1;i--) { //joueur 2
        Val[9][i].data = 5-i;
        Val[9][9-i].data = 5-i;
        Val[9][i].cou = 71;
        Val[9][9-i].cou = 71;        
    }
    for(i=4;i>=1;i--) { //joueur 3
        Val[i][0].data = 5-i;
        Val[9-i][0].data = 5-i;
        Val[i][0].cou = 87;
        Val[9-i][0].cou = 87;
    } 
}

void initialVal4(Valeur Val[][10]) { //initial mode 3 joueurs
    int i;
    for(i=4;i>=1;i--) { //joueur 1
        Val[0][i].data = 5-i;
        Val[0][9-i].data = 5-i;
        Val[0][i].cou = 62;
        Val[0][9-i].cou = 62;        
    }   
    for(i=4;i>=1;i--) { //joueur 2
        Val[i][9].data = 5-i;
        Val[9-i][9].data = 5-i;
        Val[i][9].cou = 71;
        Val[9-i][9].cou = 71;        
    }
    for(i=4;i>=1;i--) { //joueur 3
        Val[9][i].data = 5-i;
        Val[9][9-i].data = 5-i;
        Val[9][i].cou = 47;
        Val[9][9-i].cou = 47;
    }
    for(i=4;i>=1;i--) { //joueur 4
        Val[i][0].data = 5-i;
        Val[9-i][0].data = 5-i;
        Val[i][0].cou = 97;
        Val[9-i][0].cou = 97;
    }
}

void goUp(int x,int y,Valeur Val[][10]) { //x: ligne,y : colonne
    int i;
    if ((Val[x][y].data==1) || (Val[x][y].data==4)) {
        for(i=x-1;i>0;i--) {
            if(Val[i][y].data == 0) {
                Val[i][y] = Val[x][y];
                Val[x][y].data = 0;
                break;
            }
            if(i==1) {
                Val[x][y].data = 0;
            }
        }
    }
}

void goDown(int x,int y,Valeur Val[][10]) {
    int i;
    if ((Val[x][y].data==1) || (Val[x][y].data==3)||(Val[x][y].data==4)) {
        for(i=x+1;i<9;i++) {
            if(Val[i][y].data == 0) {
                Val[i][y] = Val[x][y];
                Val[x][y].data = 0;
                break;
            }
            if(i==8) {
                Val[x][y].data = 0;
            }
        }
    }
}

void turnLeft(int x,int y,Valeur Val[][10]) {
    int i;
    if ((Val[x][y].data==1) || (Val[x][y].data==4)) {
        for(i=y-1;i>0;i--) {
            if(Val[x][i].data == 0) {
                Val[x][i] = Val[x][y];
                Val[x][y].data = 0;
                break;
            }
        }
    }    
}

void turnRight(int x,int y,Valeur Val[][10]) {
    int i;
    if ((Val[x][y].data==1) || (Val[x][y].data==4)) {
        for(i=y+1;i<9;i++) {
            if(Val[x][i].data == 0) {
                Val[x][i] = Val[x][y];
                Val[x][y].data = 0;
                break;
            }
        }
    }    
}

void crossRightUp(int x,int y,Valeur Val[][10]) {
    int i,j;
    if((Val[x][y].data==1)||(Val[x][y].data==2)||(Val[x][y].data==3)) {
        for(i=x-1,j=y+1;i>0,j<9;i--,j++) {
            if(Val[i][j].data==0) {
                Val[i][j] = Val[x][y];
                Val[x][y].data = 0;
                break;
            }
        }
        if(i>0 && j<9) {
            Val[x][y].data = 0;
        }
    }
}

void crossLeftUp(int x,int y,Valeur Val[][10]) {
    int i,j;
    if((Val[x][y].data==1)||(Val[x][y].data==2)||(Val[x][y].data==3)) {
        for(i=x-1,j=y-1;i>0,j>0;i--,j--) {
            if(Val[i][j].data==0) {
                Val[i][j] = Val[x][y];
                Val[x][y].data = 0;
                break;
            }
        }
        if(i>0 && j>0) {
            Val[x][y].data = 0;
        }
    }
}

void crossRightDown(int x,int y,Valeur Val[][10]) {
    int i,j;
    if((Val[x][y].data==1)||(Val[x][y].data==2)) {
        for(i=x+1,j=y+1;i<9,j<9;i++,j++) {
            if(Val[i][j].data==0) {
                Val[i][j] = Val[x][y];
                Val[x][y].data = 0;
                break;
            }
        }
        if(i<9 && j<9) {
            Val[x][y].data = 0;
        }
    }
}

void crossLeftDown(int x,int y,Valeur Val[][10]) {
    int i,j;
    if((Val[x][y].data==1)||(Val[x][y].data==2)) {
        for(i=x+1,j=y-1;i<9,j>0;i++,j--) {
            if(Val[i][j].data==0) {
                Val[i][j] = Val[x][y];
                Val[x][y].data = 0;
                break;
            }
        }
        if(i<9 && j>0) {
            Val[x][y].data = 0;
        }
    }    
}

void affiche(Valeur Val[][10]) {
    int i,j;
    for(i=0;i<10;i++) {
        for(j=0;j<10;j++) {
            if(Val[i][j].data != 0) {
                gotoxy(5*i+3,5*j+3);
                textcolor(Val[i][j].cou);
                printf("%d",Val[i][j].data);
            } 
        }
    }
}

void getKey(int x,int y,char c,Valeur Val[][10]) {
    switch (c) {
        case 'w': {
            goUp(x,y,Val);
            break;
        }
        case 'x': {
            goDown(x,y,Val);
            break;
        }
        case 'd': {
            turnRight(x,y,Val);
            break;
        }
        case 'a': {
            turnLeft(x,y,Val);
            break;
        }
        case 'e': {
            crossRightUp(x,y,Val);
            break;
        }
        case 'q': {
            crossLeftUp(x,y,Val);
            break;
        }
        case 'z': {
            crossLeftDown(x,y,Val);
            break;
        }
        case 'c':{
            crossRightDown(x,y,Val);
            break;
        }
    }
}

int checkGame1(Valeur Val[][10]) { //end game, 1 player
    int a1=0,a2=0;
    int i,j;
    for(i=1;i<9;i++) {
        for(j=1;j<9;j++) {
            if(Val[i][j].cou == 62) { //machine
                a1++;
            }
            if(Val[i][j].cou == 72) {
                a2++;
            }
        }
    }
    if (a1 == 0) return 1;
    else if (a2 == 0) return 2;
    else return 0;
}

int checkGame2(Valeur Val[][10]) { //end game, 2 players
    int a1=0,a2=0;
    int i,j;
    for(i=1;i<9;i++) {
        for(j=1;j<9;j++) {
            if(Val[i][j].cou == 62) {
                a1++;
            }
            if(Val[i][j].cou == 70) {
                a2++;
            }
        }
    }
    if (a1 == 0) return 1;
    else if (a2 == 0) return 2;
    else return 0;
}

int checkGame3(Valeur Val[][10]) { //end game, 3 players
    int a1=0,a2=0,a3=0;
    int i,j;
    for(i=1;i<9;i++) {
        for(j=1;j<9;j++) {
            if(Val[i][j].cou == 62) {
                a1++;
            }
            if(Val[i][j].cou == 71) {
                a2++;
            }
            if(Val[i][j].cou == 87) {
                a3++;
            }
        }
    }
    if (a1 == 0) return 1;
    else if (a2 == 0) return 2;
    else if (a3 == 0) return 3;
    else return 0;
}

int checkGame4(Valeur Val[][10]) { //end game, 4 players
    int a1=0,a2=0,a3=0,a4=0;
    int i,j;
    for(i=1;i<9;i++) {
        for(j=1;j<9;j++) {
            if(Val[i][j].cou == 62) {
                a1++;
            }
            if(Val[i][j].cou == 71) {
                a2++;
            }
            if(Val[i][j].cou == 47) {
                a3++;
            }
            if(Val[i][j].cou == 97) {
                a4++;
            }            
        }
    }
    if (a1 == 0) return 1;
    else if (a2 == 0) return 2;
    else if (a3 == 0) return 3;
    else if (a4 == 0) return 4;    
    else return 0;
}

void Menu() {
    int i,j;
    for(i=0;i<21;i++) {
	for(j=0;j<25;j++) {
            if((i==0||i==4||i==8||i==12||i==16||i==20) || (((1<=i && i<=3)||(5<=i && i<=7)||(9<=i && i<=11)||(13<=i&&i<=15)||(17<=i&&i<=19)) &&((0<=j&&j<=5)||(18<j&&j<25))))
            {
                textcolor(112);
                printf(" ");
            }
            else 
            {
                textcolor(35);
		printf(" ");
            }
	}
	printf("\n");
    }
    gotoxy(3,9);
    textcolor(32); 
    printf("Reprendre");
    gotoxy(7,9); printf("1 joueurs");
    gotoxy(11,9); printf("2 joueurs");
    gotoxy(15,9); printf("3 joueurs");
    gotoxy(19,9); printf("4 joueurs");
    gotoxy(3,30);
    textcolor(7); printf("Tapez 0 pour reprendre le jeu");
    gotoxy(7,30); printf("Tapez 1 pour 1 joueur");
    gotoxy(11,30); printf("Tapez 2 pour 2 joueurs");
    gotoxy(15,30); printf("Tapez 3 pour 3 joueurs");
    gotoxy(19,30); printf("Tapez 4 pour 4 joueurs");
    gotoxy(23,30); printf("Tapez X pour sortir");
}

void randPos(Valeur Val[][10]) { //tour de machine (1 joueurs)
    int x,y;
    char n;
    srand(time(NULL));
    do {
        x = rand()%(9);
        y = 1 + rand()%(8);
    }while(Val[x][y].cou != 62);
    n = randDeplacer(x,y,Val);
    getKey(x,y,n,Val);
}

char randDeplacer(int x,int y,Valeur Val[][10]) {
    int n;
    srand(time(NULL));
    if(Val[x][y].data == 1) {
        do{
            n = 97 + rand()%(26);
        }while(n!='q'&&n!='w'&&n!='e'&&n!='d'&&n!='c'&&n!='x'&&n!='z'&&n!='a');
        return n;
    }
    else if(Val[x][y].data == 2) {
        do{
            n = 97 + rand()%(26);
        }while(n!='q'&&n!='e'&&n!='c'&&n!='z');
        return n;
    }
    else if(Val[x][y].data == 3) {
        do{
            n = 97 + rand()%(26);
        }while(n!='q'&&n!='e'&&n!='x');
        return n;
    }
    else if(Val[x][y].data == 4) {
        do{
            n = 97 + rand()%(26);
        }while(n!='w'&&n!='d'&&n!='x'&&n!='a');
        return n;
    }
}

int checkTour(Valeur Val[][10],Valeur Val1[][10]) {
    int i,j;
    int rep = 0;
    for(i=0;i<10;i++) {
        for(j=0;j<10;j++) {
            if(Val[i][j].data != Val1[i][j].data) {
                rep = 1;
                return rep;
            }
        }
    }
    return rep;
}

void fileSave(Valeur Val[][10],int tour) { //sauvegarde de la partie
    int i,j;
    FILE *fp;
    fp = fopen("text.txt","w");
    for(i=0;i<10;i++) { //entrer des Valeurs dans le fichier
        for(j=0;j<10;j++) {
            fprintf(fp,"%d\t",Val[i][j].data);
        }
        fprintf(fp,"\n");
    }
    for(i=0;i<10;i++) { //entrer des Couleurs
        for(j=0;j<10;j++) {
            fprintf(fp,"%d\t",Val[i][j].cou);
        }
        fprintf(fp,"\n");
    }
    fprintf(fp,"%d",tour);
    fclose(fp);    
}