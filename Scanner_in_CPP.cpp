//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$Name: scanner.cpp                                                                                    $
//$$Author: Abel Gancsos,Giorgio Rosi                                                                    $
//$$Class: Programming Languages                                                                         $
//$$Date: December 1, 2011                                                                               $
//$$Description: A scanner that pulls in a set of tokens from a file and matches them up with their lexem$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$


#include \"scanner.h\"

int main()
{

    int input;
    
    clear();
    displayHeaders();
 
    
    input=scanner();
    while (input!=EOF){   //Keeps running the scan until EOF has been reached
	display(input);
	clear();
	input=scanner();
    }



    return 0;
}

