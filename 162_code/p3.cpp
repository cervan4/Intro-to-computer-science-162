#include <iostream>
#include <cstring>
#include <cctype>
#include <clocale>
#include <fstream>
using namespace std;
//Luis Cervnates
//11/8/18
//The purpose of this program is to read from a file as well add on to the file
//I have to write to the text file as well read in any old data that was in the file 
struct info
{
	char name[30];//My struct that holds all of the variables that I need as well the arrays
	int size;
	int bedrooms;
	double rent;
	char pets;
	char dishwasher;
	char distance[20];//turn to a char
	char extras[50];

};
int appartment(int &,info*);//My prototypes 
int file(int & ,info*);
int writing(int &,info*);
void df(info*);
void da(info*);
int preference(info*, info*,int &,int &);

int main()
{
	int t,i;
	const int size=10;
	info reading[size];
	info appp[size];
	df(reading);// I call the function 

	//appartment();//user enteres in apparment data
return 0;
}

int appartment(int &i,info* appp)//In this function is where the user gets to enter in data until they desire
{
	//info app[10];
	bool done = true;
	i=0;
	ofstream file_out;
	file_out.open("apts.txt",ios::app);// opens file in edit mode so that it doesnt erase previous 
	//things
	char continues;

	while(done)//runs until they are done entering appartments
	{
		writing(i,appp);//Enters appartment informatiion also calls the function

		cout<<"Are you done with entering appartments?"<<endl;
		cout<<"Y/N"<<endl;//Asks if they are done entering appartments 
		cin>>continues;
		cin.ignore(100,'\n');
		if(continues=='y' || continues == 'Y')//If done it exits them out of the loop
		{
			done = false;//return false which causes the loop to exit
		}
		i++;
		if(i==10)// if they have entered 10 appartments and them exists them out
		{
			done=false;
		}

	}

	file_out.clear();
	file_out.close();//closes the file when done 
	return i;//retuns i so i can know how many times the loop ran

}

int file(int &t,info* reading)
{
	t = 0;
	int i = 0;
	ifstream file_in("apts.txt");
	if (file_in)
	{

		file_in.get(reading[t].name,30,':');
		file_in.ignore(100,':');//Name of the appartments
		//To check if there is anything in the file
			while(!file_in.eof() && file_in)//while its not end of file and file is opened
			{

				file_in >> reading[t].size;//size of the appartment
				file_in.ignore(100,':');

				file_in >> reading[t].bedrooms;// i added the .get
				file_in.ignore(100,':');//Number of bedrooms

				file_in >> reading[t].rent;
				file_in.ignore(100,':');//amount of rent

				file_in >> reading[t].pets;
				file_in.ignore(100,':');//If they allow pets its a char

				file_in >> reading[t].dishwasher;
				file_in.ignore(100,':');//If they have dishwasher its a char

				file_in.get(reading[t].distance,20,':');
				file_in.ignore(100,':');//Distance from work/ school int

				file_in.get(reading[t].extras,50,'\n');
				file_in.ignore(100,'\n');//extras array of char


				t++;//adds one to know how many they have entered

				file_in.get(reading[t].name,30,':');//if the file still has more stuff it will run aain
				file_in.ignore(100,':');//Name of the appartments
			}
		file_in.clear();
		file_in.close();

	}
	else 
	{
		cout<<"File didnt open or there was no file "<<endl;
	}
	return t;

}
void df(info* reading)//display from file
{
	int t;
	int i;
	info appp[10];
	file(t,reading);
	da(appp);
	int w = 0;
	if(t > 0)// checks how many times the loop ran if zero it doesnt display anthing 
	{
		while(w < t)
		{
			cout<<'\n'<<endl;//Displays all of the data
			cout<<"Name of appartment"<<endl;	
			cout<<reading[w].name<<endl;
			cout<<"Size of appartment"<<endl;
			cout<<reading[w].size<<endl;
			cout<<"Number of rooms"<<endl;
			cout<<reading[w].bedrooms<<endl;
			cout<<"Price of rent"<<endl;
			cout<<reading[w].rent<<endl;
			cout<<"If pets are allowed"<<endl;
			cout<<reading[w].pets<<endl;
			cout<<"Is there a dishwasher"<<endl;
			cout<<reading[w].dishwasher<<endl;
			cout<<" Distance from School/ Work"<<endl;
			cout<<reading[w].distance<<endl;
			cout<<"Extra info"<<endl;
			cout<<reading[w].extras<<endl;
			w++;
		}
	}

	preference(appp,reading,t,i);//calls the function where all the appartments that allow pets are allowed
}

void da(info* appp)
{
	int i;
	appartment(i,appp);//calls function where they enter the appartment data
	int z=0;
	while(z < i) // displays everything that they entered and doesnt go more times than they entered
	{
		cout<<'\n'<<endl;
		cout<<"Name of appartment"<<endl;	
		cout<<appp[z].name<<endl;
		cout<<"Size of appartment"<<endl;
		cout<<appp[z].size<<endl;
		cout<<"Number of rooms"<<endl;
		cout<<appp[z].bedrooms<<endl;
		cout<<"Price of rent"<<endl;
		cout<<appp[z].rent<<endl;
		cout<<"If pets are allowed"<<endl;
		cout<<appp[z].pets<<endl;
		cout<<"Is there a dishwasher"<<endl;
		cout<<appp[z].dishwasher<<endl;
		cout<<" Distance from School/ Work"<<endl;
		cout<<appp[z].distance<<endl;
		cout<<"Extra info"<<endl;
		cout<<appp[z].extras<<endl;
		z++;//displays all of the appartment info
	}
}
int preference(info* appp, info* reading,int &t,int &i)
{
	int sum=0;
	cout<<"APPARTMENTS THAT ALLOW PETS ARE THESE BELOW"<<endl;// says that all of the appartments below allow dogs
	while(sum < t)
	{
		if(reading[sum].pets =='y' || reading[sum].pets == 'Y')//checks if they allow dogs
		{
			
			cout<<'\n'<<endl;//displays all that allow dogs
			cout<<"Name of appartment"<<endl;	
			cout<<reading[sum].name<<endl;
			cout<<"Size of appartment"<<endl;
			cout<<reading[sum].size<<endl;
			cout<<"Number of rooms"<<endl;
			cout<<reading[sum].bedrooms<<endl;
			cout<<"Price of rent"<<endl;
			cout<<reading[sum].rent<<endl;
			cout<<"If pets are allowed"<<endl;
			cout<<reading[sum].pets<<endl;
			cout<<"Is there a dishwasher"<<endl;
			cout<<reading[sum].dishwasher<<endl;
			cout<<" Distance from School/ Work"<<endl;
			cout<<reading[sum].distance<<endl;
			cout<<"Extra info"<<endl;
			cout<<reading[sum].extras<<endl;
		}
	sum++;//Adds to the score
	}
	sum=0;
	while(sum < i)// if there is data
	{

		if(appp[sum].pets =='y' || appp[sum].pets == 'Y')//checks if they allow dogs 
		{
			
			cout<<'\n'<<endl;//displays all that allow dogs in 
			cout<<"Name of appartment"<<endl;	
			cout<<appp[sum].name<<endl;
			cout<<"Size of appartment"<<endl;
			cout<<appp[sum].size<<endl;
			cout<<"Number of rooms"<<endl;
			cout<<appp[sum].bedrooms<<endl;
			cout<<"Price of rent"<<endl;
			cout<<appp[sum].rent<<endl;
			cout<<"If pets are allowed"<<endl;
			cout<<appp[sum].pets<<endl;
			cout<<"Is there a dishwasher"<<endl;
			cout<<appp[sum].dishwasher<<endl;
			cout<<" Distance from School/ Work"<<endl;
			cout<<appp[sum].distance<<endl;
			cout<<"Extra info"<<endl;
			cout<<appp[sum].extras<<endl;
		}
		sum++;
	}
}
int writing(int &i, info* appp)//This is where they enter all of the new data 
{
	ofstream file_out;
	file_out.open("apts.txt",ios::app);

		cout<<"Enter name of appartment"<<endl;
		cin.get(appp[i].name,30,'\n');
		cin.ignore(100, '\n');
		file_out<<appp[i].name<<":";//writed out back to the file

		cout<<"Enter size (square feet)"<<endl;
		cin>>appp[i].size;
		cin.ignore(100, '\n');
		file_out<<appp[i].size<<":";

		cout<<"Enter number of bedrooms"<<endl;
		cin>>appp[i].bedrooms;
		cin.ignore(100, '\n');
		file_out<<appp[i].bedrooms<<":";

		cout<<"Enter rent amount"<<endl;
		cin>>appp[i].rent;
		cin.ignore(100, '\n');
		file_out<<appp[i].rent<<":";

		cout<<"Enter if pets are allowed Y/N "<<endl;
		cin>>appp[i].pets;
		cin.ignore(100, '\n');
		file_out<<appp[i].pets<<":";

		cout<<"Is there a dishwasher? Y/N"<<endl;
		cin>>appp[i].dishwasher;
		cin.ignore(100,'\n');
		file_out<<appp[i].dishwasher<<":";

		cout<<"Enter distance from work/School "<<endl;
		cin.get(appp[i].distance,20,'\n');
		cin.ignore(100, '\n');
		file_out<<appp[i].distance<<":";

		cout<<"Enter any extra details you thought important "<<endl;
		cin.get(appp[i].extras,50,'\n');
		cin.ignore(100, '\n');
		file_out<<appp[i].extras<<'\n';
	file_out.close();//closes the file 
		return i;//return i to see at what loop its at 
}
