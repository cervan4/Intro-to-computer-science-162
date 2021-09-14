#include "class.h"
appartment::appartment()
{
	t = 0;
	i=0;
	show = 0;
	list_n = 0;
	z = 0;
	new_ = 0;
	old = 0;
	r = 0;
}
appartment::~appartment()//releases memory
{
	delete [] appp;
	delete [] reading;
	delete [] rejected;
	delete [] reading2;
}
int appartment::load_apts()//loads old apt
{
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

				reading[t].distance=new char[test];
				file_in.get(reading[t].distance,20,':');
				file_in.ignore(100,':');//Distance from work/ school int

				reading[t].extras= new char[test];
				file_in.get(reading[t].extras,50,'\n');
				file_in.ignore(100,'\n');//extras array of char


				t++;//adds one to know how many they have entered

				file_in.get(reading[t].name,30,':');//if the file still has more stuff it will run aain
				file_in.ignore(100,':');//Name of the appartments
			}

		file_in.close();
		file_in.clear();

	}

	else 
	{
		cout<<"File didnt open or there was no file "<<endl;
	}
	return t;
}
int appartment::n_apts()
{
	cout<<"Enter how many appartments you are planning on "<<endl;
	cout<<"adding on to the list"<<endl;
	cin >>list_n;
	cin.ignore(100,'\n');
	return list_n;//Asks how many they are planning on entering to save the right amount of memory 
}
int appartment::enter_apts()//They enter in the appartments
{
	ofstream file_out;
	file_out.open("apts.txt",ios::app);//Opens file to be able to edit it

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

		appp[i].distance = new char [test];//Allocated memory for the distace
		cout<<"Enter distance from work/School "<<endl;
		cin.get(appp[i].distance,test,'\n');//testing
		cin.ignore(100, '\n'); 
		file_out<<appp[i].distance<<":";

		appp[i].extras = new char [test];//Allocates memory for the extras
		cout<<"Enter any extra details you thought important "<<endl;
		cin.get(appp[i].extras,test,'\n');//testing the ->
		cin.ignore(100, '\n');
		file_out<<appp[i].extras<<'\n';

		file_out.close();//closes the file 
		return i;//return i to see at what loop its at 
}
int appartment::data()//Where all 
{
	n_apts();//(list_n);// Calls function where the size of the app is defined

	rejected= new appartment1 [a_size];//Allocated memory
	reading2 = new appartment1 [a_size];//Allocates memory

	appp= new appartment1 [list_n];//Allocates memory
	reading = new appartment1 [a_size];//Allocates memory

	load_apts();//reads in the data from the txt file
	read_rejected();//reads if there is anything in the rejected file
	bool done = true;
	i=0;
	ofstream file_out;
	file_out.open("apts.txt",ios::app);// opens file in edit mode so that it doesnt erase previous 
	//things
	char continues;

	while(done)//runs until they are done entering appartments
	{
		enter_apts();///Enters appartment informatiion also calls the function
		data_rejected();//Asks if they have been rejected and if so they they enter info
		cout<<"Are you done with entering appartments?"<<endl;
		cout<<"Y/N"<<endl;//Asks if they are done entering appartments 
		cin>>continues;
		cin.ignore(100,'\n');
		if(continues=='y' || continues == 'Y')//If done it exits them out of the loop
		{
			done = false;//return false which causes the loop to exit
		}
		i++;
	/*	else
		{
		new_++;
		}*/
		if(i==10)// if they have entered 10 appartments and them exists them out
		{
			done=false;
		}

	}
	display();//Displays things from file
	display_new();// Displays what they just entered
	preference();//displays their preference
	display_file();//Displays rejected from file
	display_rejected();//Displays what they just entered of the rejected

}
int appartment::display()//(appartment* reading,int &t)
{
	
	show = 0;
	cout<<"!!LIST OF APPARTMENTS!!"<<endl;
	if(t > 0)// checks how many times the loop ran if zero it doesnt display anthing 
	{
		while(show < t)
		{
			cout<<'\n'<<endl;//Displays all of the data
			cout<<"Name of appartment"<<endl;	
			cout<<reading[show].name<<endl;
			cout<<"Size of appartment"<<endl;
			cout<<reading[show].size<<endl;
			cout<<"Number of rooms"<<endl;
			cout<<reading[show].bedrooms<<endl;
			cout<<"Price of rent"<<endl;
			cout<<reading[show].rent<<endl;
			cout<<"If pets are allowed"<<endl;
			cout<<reading[show].pets<<endl;
			cout<<"Is there a dishwasher"<<endl;
			cout<<reading[show].dishwasher<<endl;
			cout<<"Distance from School/ Work"<<endl;
			cout<<reading[show].distance<<endl;
			cout<<"Extra info"<<endl;
			cout<<reading[show].extras<<endl;
			show++;
		}
	}

}
int appartment::preference()// Displays their preferences
{

	int sum=0;
	if(t > 0||i > 0)
	{
	cout<<"APPARTMENTS THAT ALLOW PETS ARE THESE BELOW"<<endl;// says that all of the
	while(sum < t)
	{
       		//appartments below allow dogs
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
			cout<<"Distance from School/ Work"<<endl;
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

}
int appartment::display_new()//Displays all the new data
{

	z=0;
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
		z++;
	}

}
////////////////////////////////////////////////////////////////////////////////////////
int appartment::data_rejected()//enteres info about rejected apt
{

	char answer;
	cout<<"Have you gotten rejected from any appartments? Y/N"<<endl;
	cin >> answer;
	cin.ignore(100,'\n');
	if (answer == 'y'||answer =='Y')
	{
		ofstream file_out;
		file_out.open("rejected.txt",ios::app);

		cout<<"Enter the appartment you got rejected from"<<endl;

		cout<<"Enter name of appartment"<<endl;
		cin.get(rejected[new_].name,30,'\n');
		cin.ignore(100, '\n');
		file_out<<rejected[new_].name<<":";//writed out back to the file

		cout<<"Enter size (square feet)"<<endl;
		cin>>rejected[new_].size;
		cin.ignore(100, '\n');
		file_out<<rejected[new_].size<<":";

		cout<<"Enter number of bedrooms"<<endl;
		cin>>rejected[new_].bedrooms;
		cin.ignore(100, '\n');
		file_out<<rejected[new_].bedrooms<<":";

		cout<<"Enter rent amount"<<endl;
		cin>>rejected[new_].rent;
		cin.ignore(100, '\n');
		file_out<<rejected[new_].rent<<":";

		cout<<"Enter if pets are allowed Y/N "<<endl;
		cin>>rejected[new_].pets;
		cin.ignore(100, '\n');
		file_out<<rejected[new_].pets<<":";

		cout<<"Is there a dishwasher? Y/N"<<endl;
		cin>>rejected[new_].dishwasher;
		cin.ignore(100,'\n');
		file_out<<rejected[new_].dishwasher<<":";

		rejected[new_].distance = new char [a_size];
		cout<<"Enter distance from work/School "<<endl;
		cin.get(rejected[new_].distance,a_size,'\n');//testing
		cin.ignore(100, '\n'); 
		file_out<<rejected[new_].distance<<":";


		rejected[new_].extras = new char [a_size];
		cout<<"Enter any extra details you thought important "<<endl;
		cin.get(rejected[new_].extras,a_size,'\n');//testing the ->
		cin.ignore(100, '\n');
		file_out<<rejected[new_].extras<<'\n';
		new_++;

		file_out.close();//closes the file 
	}
}


int appartment::display_rejected()//displays all of the rejected
{
	if(new_ > 0)
	{
		old = 0;
		cout<<"THESE ARE THE APPARTMENTS YOU GOT REJECTED FROM"<<endl;
		while(old < new_) // displays everything that they entered and doesnt go more times than they entered
		{
			cout<<'\n'<<endl;
			cout<<"Name of appartment"<<endl;	
			cout<<rejected[old].name<<endl;
			cout<<"Size of appartment"<<endl;
			cout<<rejected[old].size<<endl;
			cout<<"Number of rooms"<<endl;
			cout<<rejected[old].bedrooms<<endl;
			cout<<"Price of rent"<<endl;
			cout<<rejected[old].rent<<endl;
			cout<<"If pets are allowed"<<endl;
			cout<<rejected[old].pets<<endl;
			cout<<"Is there a dishwasher"<<endl;
			cout<<rejected[old].dishwasher<<endl;
			cout<<"Distance from School/ Work"<<endl;
			cout<<rejected[old].distance<<endl;
			cout<<"Extra info"<<endl;
			cout<<rejected[old].extras<<endl;
			old++;
		}
	}
}
int appartment::display_file()//Displays from the file if there is anything
{

	show = 0;
	if(r > 0)// checks how many times the loop ran if zero it doesnt display anthing 
	{
		while(show < r)
		{
			cout<<'\n'<<endl;//Displays all of the data
			cout<<"Name of appartment"<<endl;	
			cout<<reading2[show].name<<endl;
			cout<<"Size of appartment"<<endl;
			cout<<reading2[show].size<<endl;
			cout<<"Number of rooms"<<endl;
			cout<<reading2[show].bedrooms<<endl;
			cout<<"Price of rent"<<endl;
			cout<<reading2[show].rent<<endl;
			cout<<"If pets are allowed"<<endl;
			cout<<reading2[show].pets<<endl;
			cout<<"Is there a dishwasher"<<endl;
			cout<<reading2[show].dishwasher<<endl;
			cout<<"Distance from School/ Work"<<endl;
			cout<<reading2[show].distance<<endl;
			cout<<"Extra info"<<endl;
			cout<<reading2[show].extras<<endl;
			show++;
		}
	}
}
int appartment::read_rejected()//reads rejected info
{

	ifstream file_in("rejected.txt");//opens file
	if (file_in)
	{

		file_in.get(reading2[r].name,30,':');
		file_in.ignore(100,':');//Name of the appartments
		//To check if there is anything in the file
			while(!file_in.eof() && file_in)//while its not end of file and file is opened
			{

				file_in >> reading2[r].size;//size of the appartment
				file_in.ignore(100,':');

				file_in >> reading2[r].bedrooms;// i added the .get
				file_in.ignore(100,':');//Number of bedrooms

				file_in >> reading2[r].rent;
				file_in.ignore(100,':');//amount of rent

				file_in >> reading2[r].pets;
				file_in.ignore(100,':');//If they allow pets its a char

				file_in >> reading2[r].dishwasher;
				file_in.ignore(100,':');//If they have dishwasher its a char

				reading2[r].distance=new char[a_size];
				file_in.get(reading2[r].distance,20,':');
				file_in.ignore(100,':');//Distance from work/ school int

				reading2[r].extras= new char[a_size];
				file_in.get(reading2[r].extras,50,'\n');
				file_in.ignore(100,'\n');//extras array of char


				t++;//adds one to know how many they have entered

				file_in.get(reading2[r].name,30,':');//if the file still has more stuff it will run aain
				file_in.ignore(100,':');//Name of the appartments
			}

		file_in.close();
		file_in.clear();

	}

	else 
	{
		cout<<"File didnt open or there was no file "<<endl;
	}
	return r;
}
