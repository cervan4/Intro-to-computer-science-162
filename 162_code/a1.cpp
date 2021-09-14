#include<iostream> 
using namespace std;
double manual(double &, double &);//z8
double assignments(double &,double &);
double programming(double &,double &);
int main()
	//Luis Cervantes 
	//Grading calculator
{
	double h1=0,h2=0;
	double z8,g4,a8,z9,g5,a9;
	assignments(a8,a9);//The programming and algorithm assignments total score and weight
	manual(z8,z9);// Lab manual total score and weight value 
	programming(g4,g5);// quizzes midterm and final so it has their total score value and their weight value
	h1=z8+a8+g4;
	h2=z9+g5+a9;
	h2=h1/h2;
	h2=h2*100;
	/*
	cout<<h1<<" Total scores"<<endl;
	cout<<a9<<" programming/algorithm weight"<<endl;
	cout<<z8<<" Manual score"<<endl;
	cout<<a8<<" Assignment score"<<endl;
	cout<<g4<<" Programming score return"<<endl;
	cout<<z9<<" manual weight value"<<endl;
	cout<<g5<<" quizzes and final and midterm weight worth"<<endl;*/
	cout<<"Your final grade is "<<h2<<"%"<<endl;
	return 0;
}	

double manual(double &z8,double &z9)
{
	double z1=0,z2=0,z3=1,z4=0,z5=0,z6=0,z7=0;
	cout<<"How many times has your lab manual been graded?"<<endl;//Asks the user how many they have done
	cin>>z1;
	if(z1>0)//if the value they entered is greater than zero then will do the math to determain the grade
{
	while(z2<z1)
{
	cout<<"Enter score manual for score (1-5)"<<z3<<endl;
	cin>>z4;
	z5=z5+z4;//The total number of score
	z2++;
	z3++;
}// Does the math to determine score also the weight
	z6=z6+z1;
	z6=z6*5;
	z7=z5/z6;
	z8=z7*0.5;
	z8=z8*10;
	z9=z1*5;
	z9=z9/z1;
}
	else// if z1 = 0 then it will set the weight and the score to zero
{
	z9=0;
	z8=0;
}
	return z9;//whats weighted
	return z8;// total score
	
}	

double programming(double &g4, double &g5)//The score for the quizzes and midterms and final also their weight value
{
	double p1=0,p2=0,p3=1,p4=0,p5=0,p6=0,p7=0,p8=0,p9=0;
	cout<<"How many quizzes have you taken?"<<endl;	
	cin>>p1;
	if(p1>0)// if what they have entered a number greater than zero then it will do the math so get the score
{
	while(p2<p1)
{
	cout<<"Enter the score of your quiz (1-25) "<<p3<<endl;
	cin>>p4;
	p5=p5+p4;//22
	p2++;
	p3++;
}
	p6=p6+p1;
	p6=p6*25;//25
	p7=p5/p6;//22/25
	p8=p7*0.5;//0.44
	p8=p8*10;//4.4
	p9=p1*5;
	p9=p9/p1;
}
	else// if p1 is zero then it will just set the score and weight value to zero then it will return that 
{
	p9=0;
}

	double t1=0,t2=0,t3=0,t4=0;
	cout<<"Enter score for the mid term (1-100) "<<endl;
	cout<<"If you have not taken the midterm enter zero"<<endl;
	cin>>t1;//90
	if(t1>0)///if its greater than zero then it will do the math
{
	t2=t1/100;//0.9
	t3=t2*0.25;//.225
	t3=t3*100;//22.5
	t4=t4+25;
}
	else// it will set it weight value to zero if they enter zero
{
	t4=0;
}
	double g1=0,g2=0,g3=0;
	cout<<"Enter Score for final (1-100)"<<endl;
	cout<<"Enter zero if you have not taken it"<<endl;
	cin>>g1;//93
	if(g1>0)//if greater than zero it will do the math
{
	g2=g1/100;//
	g3=g2*0.4;//
	g3=g3*100;//
	g5=g5+40;
}
	else //if it zero it will set the score value and weight value to zero
{	
	g5=0;
	g4=0;
}
	g5=p9 + g5 + t4;//The wighted grade 
	g4=t3+g3+p8;//Total scores
	return g5;
	return g4;//
}

double assignments(double &a8, double &a9)
{
	double v1,v2=0,v3=0,v4=0,as=1,ov=0,fa,v5=0;
	cout<<"How many algorithms have you done"<<endl;//asks how many they have done
	cin>>v1;
	while(v2 < v1)
{
	cout<<"Enter the score of the you algorithms (1-10) "<<as<<endl;
	cin>>v3;//The person enters score
	v4=v4+v3;//makes a copy of it 
	v2++;
	as++;
}
	ov=ov+v1;
	ov=ov*10;// does the math for the algorithms
	double a1=0,a2=0,a3=0,a4=0,a5=1,a6=0,a7=0;
	cout<<"How many programming assignments have you done"<<endl;
	cin>>a1;
	while(a2<a1)
{
	cout<<"Enter the score for the programming assignmets (1-100) "<<a5<<endl;
	cin>>a3;
	a4=a4+a3;//a4 is the totol number of all scores
	a2++;
	a5++;
}
	a6=a6+a1;
	a6=a6*100;//
	a7=a6+ov;//
	a8=v4+a4;//
	a8=a8/a7;//
	a8=a8*0.25;//
	a8=a8*100;//
	a9=25;// Does the math for the weigth and the total score 
 	if(v1 ==0 & a1 ==0)//if they are zero they set the score and the weight to zero
{
	a8=0;
	a9=0;
}
	else// it just outputs their value
{
	a8=a8;
	a9=a9;
}
	return a9;
	return a8;
}

