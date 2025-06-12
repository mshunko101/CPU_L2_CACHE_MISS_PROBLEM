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

    bbs b1(1);
    bbs b2(2);
    bbs b3(3);
    bbs b4(4);
    bbs b5(5);



    tree v_tree;



    v_tree >> b1;
    v_tree >> b2;
    v_tree >> b3;
    v_tree >> b4;
    v_tree >> b5;

    std::cout << v_tree;

     
    
}
