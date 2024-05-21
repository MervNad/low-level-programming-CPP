

/////////////////////////////////////////////////////////////////////////////////////////////
//
// File name         : driver.cpp
//
// This program has an icon representing a turtle which moves about a floor measuring 
// 20 x 20.The turtle may, at the user's discretion, may leave or print its' trail, 
// thereby constructing geometric patterns
//
// Programmer        : B.J. Streller
//
// Date created      :
//
// Date last revised :
//
/////////////////////////////////////////////////////////////////////////////////////////////


#include<iostream>
using std::cout;
using std::endl;
using std::cin;

#include "turtle.h"


//  Prototype Declarations

void greeting();                              //greet the user
void menu();                                  //show the user the menu/options
void options();                               //while loop which processes the choices




//////////////////////////////////////    main    ///////////////////////////////////////////



int main()
{

    greeting();
    menu();
    options();

    return 0;
}



/////////////////////////////////////////////////////////////////////////////////////////////






/////////////////////////////////// greeting  ///////////////////////////////////////////////
//
// function name      : greeting
//
// purpose            : welcomes the user
//
// input parameters   : none
//
// output parameters  : none
//
// return value       : none
//
/////////////////////////////////////////////////////////////////////////////////////////////



void greeting()
{

    cout << "             WELCOME TO MY TURTLE" << endl;
    cout << " I can write, move forward, and turn in any direction." << endl;
    cout << " All of my capibilities are listed in the following menu: \n" << endl << endl;

}









/////////////////////////////////// menu ////////////////////////////////////////////////////
//
// function name      : menu
//
// purpose            : display the munu to the user
//
// input parameters   : none
//
// output parameters  : none
//
// return value       : none
//
/////////////////////////////////////////////////////////////////////////////////////////////



void menu()
{


    cout << "   **********************   MENU   *****************************" << endl;
    cout << "   *   command                         command                 *" << endl;
    cout << "   *   number                         description              *" << endl;
    cout << "   *---------------------------------------------------------  *" << endl;
    cout << "   *     1                            change pen position      *" << endl;
    cout << "   *     2                            turn                     *" << endl;
    cout << "   *     3                            move forward             *" << endl;
    cout << "   *     4                            print                    *" << endl;
    cout << "   *     5                            change brush             *" << endl;
    cout << "   *     6                            erase/start over         *" << endl;
    cout << "   *     7                            jump                     *" << endl;
    cout << "   *     8                            see menu again           *" << endl;
    cout << "   *     9                            end program              *" << endl;
    cout << "   *************************************************************" << endl;
    cout << endl;




}





/////////////////////////////////// options /////////////////////////////////////////////////
//
// function name      : options
//
// purpose            : calls the appropriate methods from turtle.h based on the user's choices
//
// input parameters   : none
//
// output parameters  : none
//
// return value       : none
//
/////////////////////////////////////////////////////////////////////////////////////////////



void options()
{


    Turtle me(true);                                    //declare a turtle object

    int num = 0;                                        //variable holding users choice


    while (num != 9)                                    //loop for the user
        {
            cout << " \nPlease enter a menu command number ( 8 to see menu ) : ";
            cin >> num;

            switch (num)
                {
                case 1:
                    me.changePenStatus();               //change pen from up to down and vice versa
                    break;
                case 2:
                    me.turn();                          //turn turtle direction
                    break;
                case 3:
                    me.forward();                       //move turtle forward
                    break;
                case 4:
                    me.print();                         //print the floor
                    break;
                case 5:
                    me.changeBrush();                   //change turtle's  print char
                    break;
                case 6:
                    me.erase();                         //clear floor
                    me.print();                         //print floor
                    break;
                case 7:
                    me.jump();                          //jump turtle to
                    break;
                case 8:
                    cout << endl;
                    menu();                             //display menu again
                    me.turtleStatus();                  //diplay cuurent position of
                    cout << endl;
                    break;
                case 9:
                    cout << " \nTHANK YOU FOR USING MY TURTLE \n";
                    break;
                }

        }


}


/////////////////////////////////////////////////////////////////////////////////////////////