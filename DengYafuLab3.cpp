//Yafu Deng
//CPSC 121 Lab 3
//2/15/2018

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

/*-----------------------------------------------------------------------------------------------------------
Create a program that:																						*
1.  Prompt the user to choose between a rectangle and a triangle											*
2.  Prompt user for shape parameters																		*
      a)  Rectangle																							*
        Ask user to choose between supplying a word or a width												*
        Ask user for height																					*
      b)  Triangle																							*
        Ask user to choose between supplying a word or a width, and whether the triangle points up or down	*
        Read input																							*
3.  Ask the user whether they want to print to a file, ¡°myshape.txt¡±, or to cout							*
4.  Print the desired shape																					*
5.  Ask the user if they would like to exit, or return to step 1											*
------------------------------------------------------------------------------------------------------------*/

void DrawTriangle(string word, bool pointingUp);
void DrawTriangle(int size, bool pointingUp);
void DrawRectangle(string word, int height);
void DrawRectangle(int width, int height);

int main()
{
	char shape = 'z'; //Create a char variable to accept userss choices of shape
	int supply = 0; //Create a int variable to accept users' choices of supplying a word or a width
	int height = 0; //Create a int variable to accept users' height input
	int width = 0; // Create a int variable to accept users' width input
	string word;//Create a string variable to accept users' word input
	bool pointingUp = 0; //Create a boolean variable to determine wether the triangle is pointing up or not
	bool end = 1;

	//set up the loop that allows user to decide whether keeps drawing shaps or ends the program
	do
	{
		cout << "Please choose the shape you want. Enter \"r\" to choose rectangle or enter \"t\" to choose triangle" << endl;
		cin >> shape; //allow user to enter the choice

					  //Todo #1, the case that user choose rectangle
		if (shape == 'r')
		{
			//Ask user to select from supplying a word or a width and accept the input
			cout << "Please choose betwwen supplying a word or a width. Enter 1 to choose supplying a word"
				<< " or enter 2 to choose supplying a width." << endl;
			cin >> supply;
			//If user selectes word
			if (supply == 1)
			{
				//Ask for input and send the variable to the function
				cout << "Please enter the word:" << endl;
				cin >> word;
				cout << "Please enter the height:" << endl;
				cin >> height;
				DrawRectangle(word, height);
			}
			//if user selectes width
			else if (supply == 2)
			{

				//Ask for input and send the variable to the function
				cout << "Please enter the width:" << endl;
				cin >> width;
				cout << "Please enter the height:" << endl;
				cin >> height;
				DrawRectangle(width, height);
			}
		}
		//Todo #2, the case that user choose triangle
		else if (shape == 't')
		{
			//Ask for user's choice of supplying a word or a width
			cout << "Please choose betwwen supplying a word or a width. Enter 1 to choose supplying a word"
				<< " or enter 2 to choose supplying a width." << endl;
			cin >> supply;
			if (supply == 1)
			{
				//Accept the word and pointingup input from user and send them to the function
				cout << "Please enter the word:" << endl;
				cin >> word;
				cout << "Do you want to point the triangle up? Enter 1 for Yes, or enter 0 for false." << endl;
				cin >> pointingUp;
				DrawTriangle(word, pointingUp);
			}
			else if (supply == 2)
			{
				//Accept the width and pointingup input from user and send them to the function
				cout << "Please enter the width:" << endl;
				cin >> width;
				cout << "Do you want to point the triangle up? Enter 1 for yes, or enter 0 for false." << endl;
				cin >> pointingUp;
				DrawTriangle(width, pointingUp);
			}
		}
		//User's decision of whether ends the program
		cout << "Enter 1 if you want to have another shape." << endl;
		cout << "Or enter 0 if you want to end the program" << endl;
		cin >> end;
	} while (end);

	
	system("pause");
	return 0;
}

//DrawRectangle funtion that recieves string and int variables
void DrawRectangle(string word, int height)
{
	//Ask user to choose between supplying a word or a width, and whether the triangle points up or down Read input
	bool file = true;
	cout << "Do you want to print the shape into \"myshape.txt\" or cout" << endl;
	cout << "Enter 1 to print the shape into \"myshape.txt\", or enter 0 to cout" << endl;
	cin >> file;

	if (file)//User wants to print the shape into txt file
	{
		ofstream myfile;
		myfile.open("myshape.txt");//open myshape.txt
		for (int i = 0; i < height; i++)
		{
			myfile << word << endl;
		}
		myfile.close();//close myshape.txt
	}
	else//User wants to cout
	{
		//cout the rectangle shape
		for (int i = 0; i < height; i++)
		{
			cout << word << endl;
		}
	}
}

//DrawRectangle funtion that recieves two int variables
void DrawRectangle(int width, int height)
{
	//Ask user to choose between supplying a word or a width, and whether the triangle points up or down Read input
	bool file = true;
	cout << "Do you want to print the shape into \"myshape.txt\" or cout" << endl;
	cout << "Enter 1 to print the shape into \"myshape.txt\", or enter 0 to cout" << endl;
	cin >> file;

	//Todo#1 if user wants to print to the txt file
	if (file)
	{
		ofstream myfile;
		myfile.open("myshape.txt"); //open myshape.txt
		for (int i = 0; i < height; i++)
		{
			for (int t = 0; t < width; t++)
				myfile << "*";
			myfile << endl;
		}
		myfile.close(); //close myshape.txt
	}
	//#Todo#2 if user wants to cout
	else
	{
		//cout the rectangle shape
		for (int i = 0; i < height; i++)
		{
			for (int t = 0; t < width; t++)
				cout << "*";
			cout << endl;
		}
	}
}

//DrawingTriangle funtion that recieves string and bool variables
void DrawTriangle(string word, bool pointingUp)
{
	//Ask user to choose between supplying a word or a width, and whether the triangle points up or down Read input
	bool file = true;
	cout << "Do you want to print the shape into \"myshape.txt\" or cout" << endl;
	cout << "Enter 1 to print the shape into \"myshape.txt\", or enter 0 to cout" << endl;
	cin >> file;

	if (file) //User wants to print the shape into myshape.txt
	{
		ofstream myfile;
		myfile.open("myshape.txt"); //open file myshape.txt
		//print the pointing up triangle
		if (pointingUp)
		{
			for (int i = word.length() - 1; i >= 0; i--)
			{
				for (size_t t = i; t <= word.length() - 1; t++)
					myfile << word[t];
				myfile << endl;
			}
		}
		//print the pointing down triangle
		else
		{
			for (size_t i = 0; i < word.length(); i++)
			{
				for (size_t t = i; t <= word.length() - 1; t++)
					myfile << word[t];
				myfile << endl;
			}
		}
		myfile.close(); //close fule myshape.txt
	}
	else //user wants to cout
	{
		//cout the pointing up triangle
		if (pointingUp)
		{
			for (int i = word.length() - 1; i >= 0; i--)
			{
				for (size_t t = i; t <= word.length() - 1; t++)
					cout << word[t];
				cout << endl;
			}
		}
		// cout the pointing down triangle
		else
		{
			for (size_t i = 0; i < word.length(); i++)
			{
				for (size_t t = i; t <= word.length() - 1; t++)
					cout << word[t];
				cout << endl;
			}
		}
	}
}

void DrawTriangle(int size, bool pointingUp)
{
	//Ask user to choose between supplying a word or a width, and whether the triangle points up or down Read input
	bool file = true;
	cout << "Do you want to print the shape into \"myshape.txt\" or cout" << endl;
	cout << "Enter 1 to print the shape into \"myshape.txt\", or enter 0 to cout" << endl;
	cin >> file;

	if (file) //User wants to print the shape into myshape.txt
	{
		ofstream myfile;
		myfile.open("myshape.txt"); //open file myshape.txt
									//print the pointing up triangle
		if (pointingUp)
		{
			for (int i = size - 1; i >= 0; i--)
			{
				for (int t = i; t <= size - 1; t++)
					myfile << "*";
				myfile << endl;
			}
		}
		//print the pointing down triangle
		else
		{
			for (int i = 0; i < size; i++)
			{
				for (int t = i; t <= size - 1; t++)
					myfile << "*";
				myfile << endl;
			}
		}
		myfile.close(); //close fule myshape.txt
	}
	else //user wants to cout
	{
		//cout the pointing up triangle
		if (pointingUp)
		{
			for (int i = size - 1; i >= 0; i--)
			{
				for (int t = i; t <= size - 1; t++)
					cout << "*";
				cout << endl;
			}
		}
		// cout the pointing down triangle
		else
		{
			for (int i = 0; i < size; i++)
			{
				for (int t = i; t <= size - 1; t++)
					cout << "*";
				cout << endl;
			}
		}
	}
}