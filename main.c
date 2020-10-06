/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Minh Ngo
 * Fichier principal pour la compilation
 * Created on March 29, 2020, 12:21 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <conio.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int tour;
    int i,j;
    int n;
    char c;
    FILE *fp;
    Valeur Val[10][10];
    resizeConsole(900,800);
    do {
        system("cls");
        Menu();
        do{
            c = _getch();
        }while(c!='x'&&c!='0'&&c!='1' && c!='2' && c!='3' && c!='4');
        
        if(c=='x') {
            break;
        }
        else if(c=='0') { //Reprendre le jeu
            fp = fopen("text.txt","r"); //extraire le fichier
            if (feof(fp)) {
                fclose(fp);
                break;
            }
            for(i=0;i<10;i++) {
                for(j=0;j<10;j++) {
                    fscanf(fp,"%d\t",&Val[i][j].data);
                }
                fscanf(fp,"\n");
            }
            for(i=0;i<10;i++) {
                for(j=0;j<10;j++) {
                    fscanf(fp,"%d\t",&Val[i][j].cou);
                }
                fscanf(fp,"\n");
            }
            fscanf(fp,"%d",&tour);
            fclose(fp); 
            for(i=0;i<10;i++) {
                for(j=0;j<10;j++) {
                    if(Val[i][j].cou == 72) { //reprendre 1 joueur
                        n = 1;
                        break;
                    }
                    else if (Val[i][j].cou == 70) { //reprendre 2 joueurs
                        n = 2;
                        break;
                    }
                    else if (Val[i][j].cou == 87) { //reprendre 3 joueurs
                        n = 3;
                        break;
                    }
                    else if (Val[i][j].cou == 97) { //reprendre 4 joueurs
                        n = 4;
                        break;
                    }                    
                }
            }
            
            if (n==1) {
                resumeGame1(Val,tour);
            }
            else if (n==2) {
                resumeGame2(Val,tour);
            }
            else if (n==3) {
                resumeGame3(Val,tour);
            }
            else if (n==4) {
                resumeGame4(Val,tour);
            }
        }
        else if(c=='1') {//jouer avec la machine, new game
            tour = 0;
            startGame1(Val,tour);
        }
        else if(c=='2') { //2 joueurs, new game
            tour = 0;
            startGame2(Val,tour);
        }
        else if (c=='3') { //3 joueurs, new game
            tour = 0;
            startGame3(Val,tour);
        }
        else if (c=='4') { //4 joueurs, new game
            tour = 0;
            startGame4(Val,tour);
        }
    }while(c != 'x');
    return (EXIT_SUCCESS);
}