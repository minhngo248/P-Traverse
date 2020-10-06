/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "header.h"

void resumeGame1(Valeur Val[][10],int tour) { // resume Game 1 player
    int x,y; //coordonne de valeur
    char c;
    Valeur Val1[10][10];
    int i,j;
    while(1) {
        system("cls");
        Screen();
        affiche(Val);
        gotoxy(1,60);
        if(tour%2 == 0) {
            for(i=0;i<10;i++) {
                for(j=0;j<10;j++) {
                    Val1[i][j] = Val[i][j];
                }
            } 
            randPos(Val);  
        }
        else {
            textcolor(7);
            printf("Votre tour");
            gotoxy(2,60);
            printf("Saissisez quelle pion: ");
            scanf("%d%d",&x,&y);
            gotoxy(3,60);
            printf("Comment deplacer:");
            gotoxy(8,60);
            printf("Tapez o pour sortir et sauvegarder");
            gotoxy(3,78);
            c = _getch();
            if(c=='o') {
                fileSave(Val,tour);
                break;
            }
            for(i=0;i<10;i++) {
                for(j=0;j<10;j++) {
                    Val1[i][j] = Val[i][j];
                }
            }    
            getKey(x,y,c,Val);
        }
                
        if(checkTour(Val,Val1)) {
            tour++;
        }
        if (tour==60) {
            system("cls");
            printf("Termine");
            printf("\nTapez un bouton pour retourner");
            c = _getch();
            break;
        }
        if (tour>=2 && checkGame1(Val)==1) {
            system("cls");
            printf("Vainqueur: Machine");
            printf("\nTapez un bouton pour retourner");
            c = _getch();
            break;
        }
        if(tour>=2 && checkGame1(Val)==2) {
            system("cls");
            printf("Felicitation");
            printf("\nTapez un bouton pour retourner");
            c = _getch();
            break;
        }
    }    
}

void resumeGame2(Valeur Val[][10],int tour) { //resume Game 2 players
    int x,y; //coordonne de valeur
    char c;
    Valeur Val1[10][10];
    int i,j;
    while(1) {
        system("cls");
        Screen();
        affiche(Val);
        gotoxy(1,60);
        textcolor(7);
        if(tour%2 == 0) {
            printf("Tour de joueur 1");
        }
        else {
            printf("Tour de joueur 2");
        }
        gotoxy(2,60);
        printf("Saissisez quelle pion: ");
        scanf("%d%d",&x,&y);
        gotoxy(3,60);
        printf("Comment deplacer:");
        gotoxy(8,60);
        printf("Tapez o pour sortir et sauvegarder");
        gotoxy(3,78);
        c = _getch();
        if(c=='o') { //sauvegarde de la partie
            fileSave(Val,tour);
            break;
        }
        for(i=0;i<10;i++) {
            for(j=0;j<10;j++) {
                Val1[i][j] = Val[i][j];
            }
        }    
        getKey(x,y,c,Val);
               
        if(checkTour(Val,Val1)) {
            tour++;
        }
        if (tour==60) {
            system("cls");
            printf("Termine");
            printf("\nTapez un bouton pour retourner");
            c = _getch();
            break;
        }
        if (tour>=2 && checkGame2(Val)==1) {
            system("cls");
            printf("Vainqueur: Joueur 1");
            printf("\nTapez un bouton pour retourner");
            c = _getch();
            break;
        }
        if(tour>=2 && checkGame2(Val)==2) {
            system("cls");
            printf("Vainqueur: Joueur 2");
            printf("\nTapez un bouton pour retourner");
            c = _getch();
            break;
        }
    }    
}

void resumeGame3(Valeur Val[][10],int tour) {
    int x,y; //coordonne de valeur
    char c;
    Valeur Val1[10][10];
    int i,j;
    while(1) {
        system("cls");
        Screen();
        affiche(Val);
        gotoxy(1,60);
        textcolor(7);
        if(tour%3 == 0) {
            printf("Tour de joueur 1");
        }
        else if (tour%3 == 1) {
            printf("Tour de joueur 2");
        }
        else {
            printf("Tour de joueur 3");
        }
        gotoxy(2,60);
        printf("Saissisez quelle pion: ");
        scanf("%d%d",&x,&y);
        gotoxy(3,60);
        printf("Comment deplacer:");
        gotoxy(8,60);
        printf("Tapez o pour sortir et sauvegarder");
        gotoxy(3,78);
        c = _getch();
        if(c=='o') { //sauvegarde de la partie
            fileSave(Val,tour);
            break;
        }
        for(i=0;i<10;i++) {
            for(j=0;j<10;j++) {
                Val1[i][j] = Val[i][j];
            }
        }    
        getKey(x,y,c,Val);
               
        if(checkTour(Val,Val1)) {
            tour++;
        }
        if (tour==90) {
            system("cls");
            printf("Termine");
            printf("\nTapez un bouton pour retourner");
            c = _getch();
            break;
        }
        if (tour>=3 && checkGame3(Val)==1) {
            system("cls");
            printf("Vainqueur: Joueur 1");
            printf("\nTapez un bouton pour retourner");
            c = _getch();
            break;
        }
        if(tour>=3 && checkGame3(Val)==2) {
            system("cls");
            printf("Vainqueur: Joueur 2");
            printf("\nTapez un bouton pour retourner");
            c = _getch();
            break;
        }
        if(tour>=3 && checkGame3(Val)==3) {
            system("cls");
            printf("Vainqueur: Joueur 3");
            printf("\nTapez un bouton pour retourner");
            c = _getch();
            break;
        }
    }    
}

void resumeGame4(Valeur Val[][10],int tour) {
    int x,y; //coordonne de valeur
    char c;
    Valeur Val1[10][10];
    int i,j;
    while(1) {
        system("cls");
        Screen();
        affiche(Val);
        gotoxy(1,60);
        textcolor(7);
        if(tour%4 == 0) {
            printf("Tour de joueur 1");
        }
        else if (tour%4 == 1) {
            printf("Tour de joueur 2");
        }
        else if (tour%4 == 2) {
            printf("Tour de joueur 3");
        }
        else {
            printf("Tour de joueur 4");
        }
        gotoxy(2,60);
        printf("Saissisez quelle pion: ");
        scanf("%d%d",&x,&y);
        gotoxy(3,60);
        printf("Comment deplacer:");
        gotoxy(8,60);
        printf("Tapez o pour sortir et sauvegarder");
        gotoxy(3,78);
        c = _getch();
        if(c=='o') { //sauvegarde de la partie
            fileSave(Val,tour);
            break;
        }
        for(i=0;i<10;i++) {
            for(j=0;j<10;j++) {
                Val1[i][j] = Val[i][j];
            }
        }    
        getKey(x,y,c,Val);
               
        if(checkTour(Val,Val1)) {
            tour++;
        }
        if (tour==120) {
            system("cls");
            printf("Termine");
            printf("\nTapez un bouton pour retourner");
            c = _getch();
            break;
        }
        if (tour>=4 && checkGame4(Val)==1) {
            system("cls");
            printf("Vainqueur: Joueur 1");
            printf("\nTapez un bouton pour retourner");
            c = _getch();
            break;
        }
        if(tour>=4 && checkGame4(Val)==2) {
            system("cls");
            printf("Vainqueur: Joueur 2");
            printf("\nTapez un bouton pour retourner");
            c = _getch();
            break;
        }
        if(tour>=4 && checkGame4(Val)==3) {
            system("cls");
            printf("Vainqueur: Joueur 3");
            printf("\nTapez un bouton pour retourner");
            c = _getch();
            break;
        }
        if(tour>=4 && checkGame4(Val)==4) {
            system("cls");
            printf("Vainqueur: Joueur 4");
            printf("\nTapez un bouton pour retourner");
            c = _getch();
            break;
        }       
    }    
}

void startGame1(Valeur Val[][10],int tour) { //new Game 1 player
    int x,y; //coordonne de valeur
    char c;
    Valeur Val1[10][10];
    int i,j;
    for(i=0;i<10;i++) {
        for(j=0;j<10;j++) {
            Val[i][j].data = 0;
            Val[i][j].cou = 0;
        }
    }
    initialVal1(Val);
    while(1) {
        system("cls");
        Screen();
        affiche(Val);
        gotoxy(1,60);
        if(tour%2 == 0) { //tour de machine
            for(i=0;i<10;i++) {
                for(j=0;j<10;j++) {
                    Val1[i][j] = Val[i][j];
                }
            } 
            randPos(Val);  
        }
        else { //tour de joueur
            textcolor(7);
            printf("Votre tour");
            gotoxy(2,60);
            printf("Saissisez quelle pion: ");
            scanf("%d%d",&x,&y);
            gotoxy(3,60);
            printf("Comment deplacer:");
            gotoxy(8,60);
            printf("Tapez o pour sortir et sauvegarder");
            gotoxy(3,78);
            c = _getch();
            if(c=='o') { //sauvegarde
                fileSave(Val,tour);
                break;
            }
            for(i=0;i<10;i++) {
                for(j=0;j<10;j++) {
                    Val1[i][j] = Val[i][j];
                }
            }    
            getKey(x,y,c,Val);
        }
                
        if(checkTour(Val,Val1)) {
            tour++;
        }
        if (tour==60) { //tour == 60, le jeu se termine
            system("cls");
            printf("Termine");
            printf("\nTapez un bouton pour retourner");
            c = _getch();
            break;
        }
        if (tour>=2 && checkGame1(Val)==1) {
            system("cls");
            printf("Vainqueur: Machine");
            printf("\nTapez un bouton pour retourner");
            c = _getch();
            break;
        }
        if(tour>=2 && checkGame1(Val)==2) {
            system("cls");
            printf("Felicitation");
            printf("\nTapez un bouton pour retourner");
            c = _getch();
            break;
        }
    }    
}

void startGame2(Valeur Val[][10],int tour) { //new Game 2 players
    int x,y; //coordonne de valeur
    char c;
    Valeur Val1[10][10];
    int i,j;
    for(i=0;i<10;i++) {
        for(j=0;j<10;j++) {
            Val[i][j].data = 0;
            Val[i][j].cou = 0;
        }
    }
    initialVal2(Val);
    while(1) {
        system("cls");
        Screen();
        affiche(Val);
        gotoxy(1,60);
        textcolor(7);
        if(tour%2 == 0) {
            printf("Tour de joueur 1");
        }
        else {
            printf("Tour de joueur 2");
        }
        gotoxy(2,60);
        printf("Saissisez quelle pion: ");
        scanf("%d%d",&x,&y);
        gotoxy(3,60);
        printf("Comment deplacer:");
        gotoxy(8,60);
        printf("Tapez o pour sortir et sauvegarder");
        gotoxy(3,78);
        c = _getch();
        if(c=='o') {
            fileSave(Val,tour);
            break;
        }
        for(i=0;i<10;i++) {
            for(j=0;j<10;j++) {
                Val1[i][j] = Val[i][j];
            }
        }    
        getKey(x,y,c,Val);
                
        if(checkTour(Val,Val1)) {
            tour++;
        }
        if (tour==60) {
            system("cls");
            printf("Termine");
            printf("\nTapez un bouton pour retourner");
            c = _getch();
            break;
        }
        if (tour>=2 && checkGame2(Val)==1) {
            system("cls");
            printf("Vainqueur: Joueur 1");
            printf("\nTapez un bouton pour retourner");
            c = _getch();
            break;
        }
        if(tour>=2 && checkGame2(Val)==2) {
            system("cls");
            printf("Vainqueur: Joueur 2");
            printf("\nTapez un bouton pour retourner");
            c = _getch();
            break;
        }
    }    
}

void startGame3(Valeur Val[][10],int tour) { //new Game 3 players
    int x,y; //coordonne de valeur
    char c;
    Valeur Val1[10][10];
    int i,j;
    for(i=0;i<10;i++) {
        for(j=0;j<10;j++) {
            Val[i][j].data = 0;
            Val[i][j].cou = 0;
        }
    }
    initialVal3(Val);
    while(1) {
        system("cls");
        Screen();
        affiche(Val);
        gotoxy(1,60);
        textcolor(7);
        if(tour%3 == 0) {
            printf("Tour de joueur 1");
        }
        else if (tour%3 == 1) {
            printf("Tour de joueur 2");
        }
        else {
            printf("Tour de joueur 3");
        }
        gotoxy(2,60);
        printf("Saissisez quelle pion: ");
        scanf("%d%d",&x,&y);
        gotoxy(3,60);
        printf("Comment deplacer:");
        gotoxy(8,60);
        printf("Tapez o pour sortir et sauvegarder");
        gotoxy(3,78);
        c = _getch();
        if(c=='o') {
            fileSave(Val,tour);
            break;
        }
        for(i=0;i<10;i++) {
            for(j=0;j<10;j++) {
                Val1[i][j] = Val[i][j];
            }
        }    
        getKey(x,y,c,Val);
                
        if(checkTour(Val,Val1)) {
            tour++;
        }
        if (tour==90) {
            system("cls");
            printf("Termine");
            printf("\nTapez un bouton pour retourner");
            c = _getch();
            break;
        }
        if (tour>=3 && checkGame3(Val)==1) {
            system("cls");
            printf("Vainqueur: Joueur 1");
            printf("\nTapez un bouton pour retourner");
            c = _getch();
            break;
        }
        if(tour>=3 && checkGame3(Val)==2) {
            system("cls");
            printf("Vainqueur: Joueur 2");
            printf("\nTapez un bouton pour retourner");
            c = _getch();
            break;
        }
        if(tour>=3 && checkGame3(Val)==3) {
            system("cls");
            printf("Vainqueur: Joueur 3");
            printf("\nTapez un bouton pour retourner");
            c = _getch();
            break;
        }       
    }    
}

void startGame4(Valeur Val[][10],int tour) { //new Game 4 players
    int x,y; //coordonne de valeur
    char c;
    Valeur Val1[10][10];
    int i,j;
    for(i=0;i<10;i++) {
        for(j=0;j<10;j++) {
            Val[i][j].data = 0;
            Val[i][j].cou = 0;
        }
    }
    initialVal4(Val);
    while(1) {
        system("cls");
        Screen();
        affiche(Val);
        gotoxy(1,60);
        textcolor(7);
        if(tour%4 == 0) {
            printf("Tour de joueur 1");
        }
        else if (tour%4 == 1) {
            printf("Tour de joueur 2");
        }
        else if (tour%4 == 2) {
            printf("Tour de joueur 3");
        }
        else {
            printf("Tour de joueur 4");
        }
        gotoxy(2,60);
        printf("Saissisez quelle pion: ");
        scanf("%d%d",&x,&y);
        gotoxy(3,60);
        printf("Comment deplacer:");
        gotoxy(8,60);
        printf("Tapez o pour sortir et sauvegarder");
        gotoxy(3,78);
        c = _getch();
        if(c=='o') {
            fileSave(Val,tour);
            break;
        }
        for(i=0;i<10;i++) {
            for(j=0;j<10;j++) {
                Val1[i][j] = Val[i][j];
            }
        }    
        getKey(x,y,c,Val);
                
        if(checkTour(Val,Val1)) {
            tour++;
        }
        if (tour==120) {
            system("cls");
            printf("Termine");
            printf("\nTapez un bouton pour retourner");
            c = _getch();
            break;
        }
        if (tour>=4 && checkGame4(Val)==1) {
            system("cls");
            printf("Vainqueur: Joueur 1");
            printf("\nTapez un bouton pour retourner");
            c = _getch();
            break;
        }
        if(tour>=4 && checkGame4(Val)==2) {
            system("cls");
            printf("Vainqueur: Joueur 2");
            printf("\nTapez un bouton pour retourner");
            c = _getch();
            break;
        }
        if(tour>=4 && checkGame4(Val)==3) {
            system("cls");
            printf("Vainqueur: Joueur 3");
            printf("\nTapez un bouton pour retourner");
            c = _getch();
            break;
        }
        if(tour>=4 && checkGame4(Val)==4) {
            system("cls");
            printf("Vainqueur: Joueur 4");
            printf("\nTapez un bouton pour retourner");
            c = _getch();
            break;
        }       
    }    
}