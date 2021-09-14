#include <iostream>
#include <cctype>
#include <cstring>
#include <clocale>
#include <fstream>

using namespace std;
struct node
{
	char data;
	node* next;
};


class work
{
public:
    // create an empty String with no characters
    work();

    // create a String from a character array
    // String should have the same characters in the same order.
    work(const char*);//int data();

    // delete the String, and all of the characters
    ~work();

    // check to see if the String is empty
    bool empty();

    // get the length of the String
    int length();

    // return true if this String is equal to other.
    // two Strings are equal if they have the same characters in the same order.
    bool equals(work &);//(input& other);

    // creates a new String that with all of the characters in the opposite order
    void reverse(work &);//(input & result);

    // check to see if a String is a palindrome
    // A palindrome is a word that is the same forwards and back
    // for example: "racecar"
    bool same_backwords();

    // put a single character in front of the String
    void letter_infront(char);

    // put a single character at the end of the String
    void letter_atend(char);

    // put an entire second String at the end of the String
    // This should leave the second String empty
    //
    // example:
    // String abc("abc");
    // String def("def");
    // abc.append(def);
    //
    // at the end
    // abc == String("abcdef")
    // def == String("")
    void letter_atend(work& );

    // print out all of the characters in the String.
    void display();

private: 
    node *head;
    node *tail;
    node *head2;
    int size;
    char input[100];
    const char *copy;
    char infront;
    char start;
    char end;
 //   char *word;
    char word2[100];
};
