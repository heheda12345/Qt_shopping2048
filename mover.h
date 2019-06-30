#ifndef MOVER_H
#define MOVER_H

#include<vector>
#include<ctime>
#include<cstdlib>
#include<iostream>
#include<fstream>
#include<ios>

#include"constants.h"

class Mover
{
public:
    Mover();
    Mover(int b[GS][GS],int m);
    int q(int x,int y) { return a[x][y]; }
    int qMark();
    MoveQuality newround();
    //0 full,can't put a new number
    //1 successfullly put a new number
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

private:
    int a[GS][GS];
    int mark;
    unsigned long long hash_a;
    unsigned long long get_hash();
    MoveQuality check_live();
};

#endif // MOVER_H
