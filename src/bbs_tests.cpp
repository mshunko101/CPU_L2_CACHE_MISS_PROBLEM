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

    b2 = b2 + b3;
    b1 = b1 + b2;
    b1 = b1 + b4;
    b1 = b1 + b5;

    tree v_tree;

    v_tree >> b1;
    v_tree >> b2;
    v_tree >> b3;
    v_tree >> b4;
    v_tree >> b5;

    std::cout << v_tree;

 
     
    
}
