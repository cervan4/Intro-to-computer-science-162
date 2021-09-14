#include <iostream>
#include <cstring>
#include <fstream>
#include <cctype>
#include <clocale>
using namespace std;

struct appartment1 // where all the apt info will be stored
{

		char name[30];//This was a pointer testing data out
		int bedrooms;
		int size;
		double rent;
		char pets;
		char dishwasher;
		char * distance;//turn to a char
		char * extras;
};
class appartment//class of all of my appartments
{
	public:
		appartment();//Stands for previous appartments
		~appartment();
		int n_apts();//
		int load_apts();
		int enter_apts();
		int data();
		int display();
		int preference();
		int display_new();

		int data_rejected();// User enteres in data of the rejected apt
		int display_rejected();//Displays the data they just entered
		int display_file();//Displays the apt in the file
		int data_compiler();//where all if the functions are at
		int read_rejected();//Reads if there is anything inside the file to store
	private:
		int t,list_n,i;
		int show;
		int z;
		int new_;
		int old;
		int r;
		appartment1 *reading;
		appartment1 *appp;
		appartment1* rejected;
		appartment1* reading2;
		int test = 100;
		const int a_size = 100;
};
/*class rejected_apt
{
	public:
		rejected_apt();
		~rejected_apt();
		int data_rejected();// User enteres in data of the rejected apt
		int display_rejected();//Displays the data they just entered
		int display_file();//Displays the apt in the file
		int data_compiler();//where all if the functions are at
		int read_rejected();//Reads if there is anything inside the file to store
		int test();//test the if statment thing

	private:
		appartment1* rejected;
		appartment1* reading2;
		int i;
		int t;
		int z;
		const int a_size = 100;
		int show;
		//char answer;


};*/

