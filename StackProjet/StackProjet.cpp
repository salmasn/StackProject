
#include <iostream>
#include "pch.h"
#include "ListeChaine.h"
#include "PileG.h"
//#include <stdexcept>

int main()
{
    PileG<int>* pile = new PileG<int>(5);


    try
    {
        pile->empiler(1);
        pile->empiler(2);
        pile->empiler(3);
        pile->empiler(4);
        pile->empiler(5);
        pile->afficher();
        pile->empiler(6);

    }
    catch (std::overflow_error e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        pile->depiler();
        pile->depiler();
        pile->depiler();
        pile->depiler();
        pile->depiler();

        pile->afficher();
        
        

    }
    catch (std::underflow_error e)
    {
        std::cerr << e.what() << std::endl;
    }
    /*
    ListeChaine<int>* liste = new ListeChaine<int>(1);

    liste = liste->insererdebut(2);
    liste = liste->insererdebut(3);
    liste = liste->insererdebut(4);
    liste = liste->insererdebut(5);


    liste->afficherliste();
    */
    /*
    std::cout << "******************** Pile des entiers ***************" << std::endl;
    Pile* P = new Pile();
    P->Empiler(10);
    P->Empiler(1);
    P->Empiler(8);
    P->Empiler(11);
    P->afficher();


    
    std::cout << std::endl << "******************** Pile des caracteres ***************" << std::endl;
    PileGen<char>* P1 = new PileGen<char>();
    
        P1->Empiler('a');
        P1->Empiler('m');
        P1->Empiler('l');
        P1->Empiler('a');
        P1->Empiler('S');
        P1->Empiler('S');
        P1->afficher();
    
    
        char c[10];
        for(int i=0;i<10;i++)
        { 
            c[i] = P1->depiler();
        }

        std:: cout << c << std::endl;
  
    */




}
