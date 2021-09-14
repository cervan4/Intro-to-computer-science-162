#include "lstring.h"
work::work()//the constructor
{
	head = NULL;
	tail = NULL;
	//size = 0;
	head2 = NULL;
}

work::~work()
{

}
work::work(const char* copy) //when the enter a word it makes two copies one with the original and the other for the backwords
{
	strcpy(input,copy);
	int i = 1;
	node *first =new node;
	first->data = input[0];//sets the first letter to head
	head = first;
	first->next =NULL;
	tail = first;

	node *first2 = new node;
	first2->data = input[0];//Sets the first letter to the head of the reverse 
	first2->next =NULL;
	head2 = first2;

	size = strlen(input);//checks the size of the array

	while (i < size)//Puts the array into the linear linked list
	{
		node *letter = new node;
		letter->data = input[i];
		letter->next = NULL;
		tail->next = letter;
		tail = tail->next;
		i++;
	}

}
bool work::empty()//checks if its empty
{

	if (head == NULL)//check if the head is empty
	{
		cout<<"This is empty"<<endl;	
	}
	else
	{
		cout<<"There is a linear linked list"<<endl;
	}
}
int work::length()
{

	cout<<size<<" is the length"<<endl;//displays the length
}
bool work::equals(work &other)//checks if the words they provided are equal
{
	if(strcmp(other.input,input) == 0)
	{
		cout<<"They are the same"<<endl;
	}
	else
	{
		cout<<"They are not the same"<<endl;
	}
}
void work::reverse(work &result)//it reverses the word and makes a completly new linear linked list
{
	int i = 1;

	while(i < result.size)
	{

		node* temp = new node;
		temp->data = result.input[i];
		temp->next = result.head2;
		result.head2 = temp;
		i++;
	}
	node *current = new node;
	current = result.head2;
	while(current != NULL)
	{
		cout<<current->data;
		current = current->next;
	}
	cout<<'\n'<<endl;

}
bool work::same_backwords()//checks if the word is the same backwords and if not it displays so 
{
	node *current = new node;
	node *current2 = new node;
	current = head;
	current2 = head2;
	bool status = true;

	while(current != NULL && current2 != NULL && status)
	{
		if(current2->data != current->data)
		{
			cout<<"The word is not the same backwords"<<endl;
			status =  false;
		}
		else
		{
			current = current->next;
			current2 = current2->next;
		}
	}
}
void work::letter_infront(char start)//adds one letter infront of the word
{
	int sizing, i = 0;
	infront = start;
	while(i < 1)
	{
		node* temp = new node;
		temp->data = infront;
		temp->next = head;
		head2 = temp;
		i++;
	}

}
void work::letter_atend(char end)//adds one letter at the end of the linear linked list
{
	
	int sizing, i = 0;
    	char atend;// used to be an array
	atend = end;
	while (i < 1)
	{
		node *letter = new node;
		letter->data = end;
		letter->next = NULL;
		tail->next = letter;
		tail = tail->next;
		i++;
	}

}
void work::letter_atend(work& other)//adds an entire word at the end of the letter
{
		
	int sizing, i = 0;
	while (i < size)
	{
		node *letter = new node;
		letter->data =other.input[i];
		letter->next = NULL;
		tail->next = letter;
		tail = tail->next;
		i++;
	}
}
void work::display()//displays the entire linear linked list
{
	cout<<"This is the word you entered"<<endl;
	node *current = new node;
	current = head;
	while(current != NULL)
	{
		cout<<current->data;
		current = current->next;
	}
	cout<<'\n'<<endl;
}
