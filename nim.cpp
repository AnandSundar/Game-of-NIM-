/*Name: Anand Sundar
  File: assign1.cpp 
  Description: The program is about a game called Game of NIM. This game is 
					played by 2 players 
*/

//Plan

/* Declare all the prototypes
	void startgame()
	{
		waits for the input to be either 1 or 2. If its 1 continue the game else exit the game
	}
	int initialinput()
	{
		asks the user to enter 1 for continuing the program or 2 for exiting the game
	}
	void startgame()
	{
		has a do... while loop which consists of all the calling functions in order with 
		repective to both the players. It also has a if block. All the calling functions are held 
		in the if else block.
	}
	void steponeinput()
	{
		asks the user to choose any heap from the total of three and returns the users input.
	}
	void errorchecking1()
	{
		checks the users value is within the desired range
	}
	void steptwo()
	{
		call the heap5, heap4 and heap3 function which are held in a if else block, and is
		executed according to the users input.
	}
	void heap5()
	{
		asks the user to choose a number from the range and stores the value. checks for any 
		undesired input and performs a small calculation and increases x by 1 every time to know 
		which player lost the game
	}
	void erreocheckingheap5obj()
	{
		checks for any unacceptable values and displays an	error message
	}
	functions void heap4, void heap3, void erreocheckingheap4obj, void erreocheckingheap3obj	 	
	does the same thing like heap 5 and errorcheckingheap5obj functions.
*/


#include<iostream>
//function prototypes
using namespace std;
void welcome();
int initiallinput();
void startgame(int &x, int &y);
void stepone();
int steponeInput();
void player1();
void player2();
void errorchecking1(int &input1);
void errorchecking2(int &input1);
void steptwo(int input1, int &heap1, int &heap2, int &heap3);
void heap5(int &heap5obj, int &heap1, int heap2, int heap3,int input1);
void errorcheckingheap5obj(int &heap5obj);
void heap4(int &heap4obj, int heap1, int &heap2, int heap3, int input1);
void errorcheckingheap4obj(int &heap4obj);
void Heap3(int &heap3obj, int heap1, int heap2, int &heap3, int input1);
void errorcheckingheap3obj(int &heap3obj);
int main()
{
	welcome();//displays welcome message
	int initialinput = initiallinput();//calls initiallinput()
	int x = 0,y = 0;	
	if(initialinput == 1)
	{
		startgame(x,y);
		//if block to check and display the loser
		if(x>y)
		{
			cout<<"Player 1, You Lose!!"<<endl;
		}else 
		{
			cout<<"Player 2, You Lose!!"<<endl;
		}
	}else{
		return 0;// ends the program
	}
	return 0;
}

//implementation of the welcome function
void welcome()
{
	cout<<"Welcome to the Game of Nim"<<endl;
	cout<<"Rules of the Game:\n"<<endl;
	cout<<"This is a two player game, the players will be referred to as"<<endl;
	cout<<"          \"Player1\"        and          \"Player2\"\n"<<endl;
	cout<<"At the start, there are three heaps of objects"<<endl;
	cout<<"Heap 1 has 5 objects, Heap 2 has 4 objects, and Heap 3 has 3 objects"<<endl;
	cout<<"The players take turns until the game ends"<<endl;
	cout<<"The last player to pick up an object Loses"<<endl;
   cout<<"Each player, on their turn must pick up at least one object from a heap"<<endl;

}
//implementation of the initiallinput function
int initiallinput()
{
	int initial;
	cout<<"\nPress 1 to start, or 2 to quit"<<endl;
	cin>>initial;//stores the value the user enteres
	while(!((initial == 1) || (initial == 2)))
	{
		cout<<"Please enter the right input"<<endl;
		cin>>initial;
	}
	return initial;//return 1 or 2
}
//implementation of the function start game
void startgame(int &x, int &y)
{
	int input1;
	int heap1 = 5, heap2 = 4, heap3 = 3;//initial values for heaps
	
	stepone();//calls stepone function
	// do while loop to call the remaining functions again and again
	do
	{
		//if block to check the condition for the result can be displayed
		if (!(heap1 ==0 && heap2 ==0 && heap3 ==0))
		{
						
			player1();//calls palayer1 function
			input1 = steponeInput();// calls stepone input function
			errorchecking1(input1);//errorchecking1 function call
			steptwo(input1, heap1, heap2, heap3);//steptwo fucntion call
			x++;//increments x by 1 
		}
		
		if (!(heap1 ==0 && heap2 ==0 && heap3 ==0))
		{
			
			player2();//calls player 2 fucntion
			input1 = steponeInput();//calls steponeinput
			errorchecking2(input1);//calls errorchecking2 function
			steptwo(input1, heap1, heap2, heap3);//steptwo function call
			y++;//imncrements y by 1.
		}
		
	}while (!(heap1 ==0 && heap2 ==0 && heap3 ==0));//while condition for the loop to execute
	
}
//function implementation of stepone
void stepone()
{
	cout<<"\nHere is the current content of heaps:"<<endl;
	cout<<"5 4 3"<<endl;
}
//function implemenation of palyer1
void player1()
{
	cout<<"Player 1, it is your turn"<<endl;
}
//function implementation of player2
void player2()
{
	cout<<"Player 2, it is yout turn"<<endl;
}
//implementation of steponeInput
int steponeInput()
{
	int x;//declaring variable x.
	cout<<"Please enter the number of the heap you wish to draw from, e.g. 2"<<endl;
	cin>>x;
	return x;//returning variable x.
}
//implementation of errorchecking1 function
void errorchecking1(int &input1)
{
	//while condition to check the input values
	while(!((input1==1)||(input1==2)||(input1==3)))
	{
		cout<<"*******Invalid heap number, try again********"<<endl;
		player1();
		input1 = steponeInput();
	}//loop keeps executing till the condition is satisfied
}
//function implementation of errorchecking2
void errorchecking2(int &input1)
{
	//while condition to check the user value
	while(!((input1==1)||(input1==2)||(input1==3)))
	{
		cout<<"*******Invalid heap number, try again********"<<endl;
		player2();
		input1 = steponeInput();
	}
}
//implementation of steptwo function
void steptwo(int input1, int &heap1, int &heap2, int &heap3)
{
	int heap5obj, heap4obj, heap3obj;
	//if else block to check the user input value and call a fucntion
	if (input1==1)
	{
		heap5(heap5obj, heap1, heap2, heap3,input1);//calls heap5 function
	}else if(input1==2)
	{
		heap4(heap4obj, heap1, heap2, heap3,input1);//calls heap4 function
	}else if (input1==3)
	{
		Heap3(heap3obj, heap1, heap2, heap3,input1);//calls heap3 function
	}
	
}

void heap5(int &heap5obj, int &heap1, int heap2, int heap3,int input1)
{
	if(heap1 == 0)//if the value is zero, asks the user to enter the value of new heap
	{
		cout<<"There are 5 objects to choose from, enter a number 0 to "<<heap1<<endl;
		cout<<"Plese choose another heap"<<endl;
		cin>>input1;
		steptwo(input1,heap1,heap2,heap3);//calling function
	}else
	{
		 cout<<"There are 5 objects to choose from, enter a number 1 to "<<heap1<<endl;
		 cin>>heap5obj;
	
		if (heap5obj == 0)//if block to check for error
		{
			cout<<"\nInvalid input, try again"<<endl;
			heap5(heap5obj,heap1, heap2, heap3,input1);//calls heap5 function
		}else
		{
			errorcheckingheap5obj(heap5obj);//calls errorchecking
			heap1 -= heap5obj;
			cout<<"Here is the current content of the heap"<<endl;
			cout<<heap1<<" "<<heap2<< " "<<heap3<<endl;//displays the current content of heaps
		}
	}
}
void errorcheckingheap5obj(int &heap5obj)
{
	while(heap5obj<1 || heap5obj>5)
	{
		cout<<"###### Invalid number of objects, try again ######"<<endl;
		cin>>heap5obj;	//stores the user entered value
   }
}
//implementation of heap4 function
void heap4(int &heap4obj, int heap1, int &heap2, int heap3,int input1)
{

	if(heap2 == 0)//checks if the heap is 0. if it is asks the user to choose anothe heap
	{
		cout<<"There are 4 objects to choose from, enter a number 0 to "<<heap2<<endl;
		cout<<"Plese choose another heap"<<endl;
		cin>>input1;
		steptwo(input1,heap1,heap2,heap3);//calling function
	}else
	{
		cout<<"There are 4 objects to choose from, enter a number 1 to "<<heap2<<endl;
		cin>>heap4obj;//stores the value
	
		errorcheckingheap4obj(heap4obj);// calls errorcheckingheap4obj function
		heap2 -=heap4obj;//decreases the user value from the acctual value
		if(heap4obj == 0)
		{
			cout<<"^^^^^ Invalid Input, please try again ^^^^^"<<endl;
			heap4(heap4obj, heap1, heap2, heap3,input1);//calls heap4 function
		}else 
		{
			cout<<"Here is the current content of the heap"<<endl;
			cout<<heap1<<" "<<heap2<<" "<<heap3<<endl;// displays the objects left
		}
	}
}
//implementation of errorchecking function
void errorcheckingheap4obj(int &heap4obj)
{
	while (heap4obj<1 || heap4obj>4)
	{
		cout<<"!!!!!!!! Invalid number of objects, try again !!!!!!!"<<endl;
		cin>>heap4obj;	
	}
}
// does all the function like heap4 function
void Heap3(int &heap3obj, int heap1, int heap2, int &heap3,int input1)
{
	if(heap3 == 0)
	{
		cout<<"There are 3 objects to choose from, enter a number 0 to "<<heap3<<endl;
		cout<<"Plese choose another heap"<<endl;
		cin>>input1;
		steptwo(input1,heap1,heap2,heap3);
	}else
	{
		cout<<"There are 3 objects to choose from, enter a number from 1 to "<<heap3<<endl;
		cin>>heap3obj;
		if(heap3obj == 0)//if else to check for error
		{
			cout<<"\n^^^^^ Invalid Input, please try again ^^^^^\n"<<endl;
			Heap3(heap3obj, heap1, heap2, heap3,input1);// recursion call to get the right input
		}else 
		{
			errorcheckingheap3obj(heap3obj);//calls errorchecking function
			heap3 -= heap3obj;// subtracts the user given value from actual value
			cout<<"Here is the current content of the heap"<<endl; 
			cout<<heap1<<" "<<heap2<<" "<<heap3<<endl;// displays the number objects in the heaps
		}
	}
}
//function implementation of errorcheckingheap3obj
void errorcheckingheap3obj(int &heap3obj)
{
	while (heap3obj<1 || heap3obj>3)
	{
		cout<<"\n@@@@@@@@ Invalid number of objects, try again @@@@@@@\n"<<endl;
		cin>>heap3obj;
	}
}
//end of program
