/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   header.h
 * Author: Minh Ngo
 * Tous les prototypes des fonctions et des procedures
 * Created on March 30, 2020, 10:16 PM
 */

#ifndef HEADER_H
#define HEADER_H
typedef struct Valeur Valeur;
struct Valeur {
    int data;
    int cou;
};

void resizeConsole(int width,int height);
void textcolor(int x);
void gotoxy(int x,int y);
void Screen(); //table du jeu
void initialVal1(Valeur Val[][10]); //initialiser les Valeurs 1 joueur
void initialVal2(Valeur Val[][10]); //initialiser les Valeurs 2 joueur
void initialVal3(Valeur Val[][10]); //initialiser les Valeurs 3 joueur
void initialVal4(Valeur Val[][10]); //initialiser les Valeurs 4 joueur

//8 directions des pions
void goUp(int x,int y,Valeur Val[][10]);
void goDown(int x,int y,Valeur Val[][10]);
void turnLeft(int x,int y,Valeur Val[][10]);
void turnRight(int x,int y,Valeur Val[][10]);
void crossRightUp(int x,int y,Valeur Val[][10]);
void crossLeftUp(int x,int y,Valeur Val[][10]);
void crossRightDown(int x,int y,Valeur Val[][10]);
void crossLeftDown(int x,int y,Valeur Val[][10]);

void affiche(Valeur Val[][10]); //afficher des Valeurs sur la table du jeu
void getKey(int x,int y,char c,Valeur Val[][10]);

//Les fonctions qui checker si le jeu se termine et le gagnant
int checkGame1(Valeur Val[][10]); //1 joueur
int checkGame2(Valeur Val[][10]); //2 joueurs
int checkGame3(Valeur Val[][10]); //3 joueurs
int checkGame4(Valeur Val[][10]); //4 joueurs

//Reprendre du jeu (resume)
void resumeGame1(Valeur Val[][10],int tour);
void resumeGame2(Valeur Val[][10],int tour);
void resumeGame3(Valeur Val[][10],int tour);
void resumeGame4(Valeur Val[][10],int tour);
//New game
void startGame1(Valeur Val[][10],int tour);
void startGame2(Valeur Val[][10],int tour);
void startGame3(Valeur Val[][10],int tour);
void startGame4(Valeur Val[][10],int tour);

void Menu(); //Interface graphique du Menu
char randDeplacer(int x,int y,Valeur Val[][10]);
void randPos(Valeur Val[][10]);
int checkTour(Valeur Val[][10],Valeur Val1[][10]);
void fileSave(Valeur Val[][10],int tour); //sauvegarde de la partie
#endif