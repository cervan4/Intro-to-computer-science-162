#include <iostream>
#include <cctype>
#include <cstring>
#include <clocale>

using namespace std;
//10/25/18
//Luis Cervnates Oropeza
//In this program there will be two players one that enters the word and the one that guesses the word
//player two will have the chance to either guess the word or pass if desired 
//player two has five tries to guess the word
//After player two gets a comunitive score of 5 the they win the game
//if the word is less even it swaps the second letter and the last one
int test(char*,int,int &);
void gl(char*,int);
void passing(char*);
int main()
{
	const int size =20;
	int length;
	char word[size];///Where I define word and its size
	char guess[size];//Where I define 
	gl(word,size);
	return 0;
}


int test(char* word,int size,int &length)
{
	//this is where player one enters there word and I use a pointer so later on I can get the data from 
	//word as well after they have entered the word all of the words will be turned to lower case 
	int i=0;
	cout<<"Player one enter the word"<<endl;
	cin>>word;//Gets the word 
	cin.ignore(100,'\n');
	length = strlen(word);
	while(word[i] > size)//Makes all of the letters lower case
	{
		word[i]=tolower(word[i]);
		i++;

	}
	return length;
}


void gl(char* word,int size)
{
		///This is where I set up all of my variables and arrays that I will use later on 	
		int trys=0,score=0;
		char guess[size];
		int x = 0,g = 0,t = 0;
		int i=0;// Original counters 
		int fl = 0;// Swaping the first and last letter of the word
		int m = 0;
		int length;
		char greater[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q',
		     'r','s','t','u','v','w','x','y','z'};///An array of all of the alphabet

		char vowls[5] = {'a','e','i','o','u'};//An array of all of the vowls
		char copy[size];

	bool continues=true;
	while(continues)//In this loop it will continues until the player decides that they are done playing 
	{
	
		trys=0;//Sets it to zero so when it comes back for the second time it has a fresh start 
		length=0,g = 0,t = 0;//where ever i have length thats where x used to be
		i=0;// Original counters 
		fl = 0;// Swaping the first and last letter of the word
		m = 0;

		test(word,size,length);//Where I call the function when player one enteres the word 

		for(int gh = 0; gh < 100; gh++) //This clears the screen so player twp doesnt cheat
		{
			cout<<'\n'<<endl;

		}
		//cout<<length;
		strcpy(copy,word);

		if (length < 3)// If the word is less than three it will ask them to enter another word 
		{
			cout<<"Enter another word"<<endl;
		}
		else
		{
			fl = length - 1;//subracts one so I pin point all of the letter correct 
			i = 0;
			while(i < 26)// It goes thru the array of the alphabet and checks every single letter
			{	
				while(word[0] != greater[t])
				{
					t++;//Checks where in the alphabet the first word is positioned
				}
				while( word[fl] != greater[g])
				{
					g++;//Checks where the last word is positioned 
				}

				while (word[1] != vowls[m])
				{
					m++;//Checks if there is a vowl in the array of vowls
				}

	
				i++;//Adds one after everytime the loop runs
			}
			double xi;
			xi=x;
			xi=xi/2;
			xi=xi-1;
			if(xi == 0)
			{
			swap(word[1],word[fl]);//if it even it will swap the second letter and teh last one;
			}
			int q=0,w=0,e=0;	
			while(t < g && q < 1)//checks if its greater in the alphabet
			{
				swap(word[0],word[fl]);//
				q++;
			}

			while(word[1]==vowls[m] && w < 1)//checks if there is a vowl 
			{
				swap(word[1],word[2]);
				w++;
			}

			while(word[3] <= greater[10] && e < 1) //checks if its between that range and if so it swaps out 								//the letter 
			{
				swap(word[2],word[3]);
				e++;
			}

			cout<<"player two guess the word"<<endl;
			cout<<"You only have 5 tries to guess after that you lose the game"<<endl;
			cout<<"The word is "<<word<<endl;
			bool status= true;// so i can know if their guess is correct or not
			while(trys < 5)//they have five trys to guess
			{
				cout<<"would you like to skip 'y'/'n'"<<endl;
				char skip;
				cin>>skip;//asks if they want to skip the word
				if(skip=='y')
				{
					trys += 5;
					status=false;//if they check yes it exits out of the loop
				}
				else 
				{//else it checks if its correct
				passing(guess);//the function is called 
				int h=0;
				int v=0;
				int done=0;
				while (v < fl && done<1)//checks if their guess is correct
				{
					if(guess[v] == copy[v])
					{	
						status=true;
					}
					else 
					{
						status =false;
						done++;
					}
					v++;
	
				}		

				if(status)//displays if the answer was correct and if its wrong they guess again
				{
					cout<<"you got it correct"<<endl;
					trys +=5;
					score ++;
					cout<<"Player two your score is "<<score<<endl;
				}
				else
				{
					cout<<"WRONG TRY AGAIN"<<endl;
					trys++;
					//score++;
				}

				if(score ==5)//if their score is 5 they win the game
				{
					cout<<"Congrats you won the game "<<endl;
				}

				}//the else one
			}//closes trys
		
		}//The else 
		char answer;//asks if they are done playing the game and if so it exits the game 
		cout<<"Are you done playing 'y'/'n'"<<endl;
		cin>>answer;
		cin.ignore(100,'\n');
		if(answer=='y')
		{
			continues=false;
		}
	}//the true one	
}




void passing(char* guess)
{
	// They enter the guess and it turns it all lower case
		cout<<"Enter guess"<<endl;	
		cin>>guess;
		cin.ignore(100,'\n');// means it will ignore anything after the array is full
		int op=0;
		while(guess[op] > 20)
		{
			guess[op]=tolower(guess[op]);
			op++;

		}


}
