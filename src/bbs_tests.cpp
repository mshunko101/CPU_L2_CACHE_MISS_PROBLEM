// bbs_tests.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "tree.h"
#include "bbc.h"
#include "vechline.h"
#include "car.h"

int main()
{
    std::cout << "Hello World!\n";

    bbs b1;
    bbs b2;
    bbs b3;
    bbs b4;
    bbs b5;
    bbs b6;
    bbs b7;
    bbs b8;
    bbs b9;
    bbs b10;
    bbs b11;
    bbs b12;
 
    b1 += b2;
    b2 += b3;
    b3 += b4;
    b3 += b5;
    b5 += b6;
    b1 += b7;
    b1 += b8;
    b1 += b9;

    tree v_tree;

    v_tree >> b1;
    v_tree >> b2;
    v_tree >> b8;
    v_tree >> b3;
    v_tree >> b4;
    v_tree >> b7;
    v_tree >> b9;
    v_tree >> b5;
    v_tree >> b6;

    v_tree.commit();
    std::cout << v_tree;

    int* ptr = new int[200 * 1024 * 1024];
    
    
}
