#include "lstring.h"
//Luis Cervantes
//12/3/18
//The purpose of this program in so that we can know how to use linear linked list as well creating and shortening memory
//in this program there is a word and the word gets manipulated in main 
//All of the data is stored in a linear linked list so size isnt set 
//A add a word in the end of the other word
//as well shows if its the same backwords
int main()
{
	
    work race("race");
    
    work car("car");
    car.letter_atend('a');
    car.letter_atend('r');
    car.letter_infront('c');

    race.letter_atend(car);

    cout << "car is empty: " << car.empty() << endl;

    race.display();
    cout << endl;
    cout<<'\n'<<endl;
    car.display();
    cout<<endl;
    cout<<'\n'<<endl;

    cout << "racecar is a palindrome: " << race.same_backwords() << endl;


}
