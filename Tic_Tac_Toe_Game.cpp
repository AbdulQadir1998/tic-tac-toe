#include<iostream>
using namespace std;
const int rows=3;
const int cols=3;
void Print_Board(char player1[50],char player2[50],char c_board[rows][cols])
{
	cout<<endl<<endl;
	cout<<"                             Tic Tac Toe Game"<<endl<<endl;
	cout <<"                             "<<player1 << " (X)   &   " << player2 << " (O)" << endl << endl;
	cout << "                                   |     |     " << endl;
	cout << "                                " << c_board[0][0] << "  |  " << c_board[0][1] << "  |  " << c_board[0][2] << endl;
	cout << "                              _____|_____|_____" << endl;
	cout << "                                   |     |     " << endl;
	cout << "                                " << c_board[1][0] << "  |  " << c_board[1][1] << "  |  " << c_board[1][2] << endl;
	cout << "                              _____|_____|_____" << endl;
	cout << "                                   |     |     " << endl;
	cout << "                                " << c_board[2][0] << "  |  " << c_board[2][1] << "  |  " << c_board[2][2] << endl;
	cout << "                                   |     |     " << endl << endl;
}
bool checkwin(char board[][cols])
{
	bool flag=true;
	if(board[0][0]==board[0][1] && board[0][1]==board[0][2])
	{
		flag=false;
	}
	if(board[1][0]==board[1][1] && board[1][1]==board[1][2])
	{
		flag=false;
	}
	if(board[2][0]==board[2][1] && board[2][1]==board[2][2])
	{
		flag=false;
	}
	if(board[0][0]==board[1][0] && board[1][0]==board[2][0])
	{
		flag=false;
	}
	if(board[0][1]==board[1][1] && board[1][1]==board[2][1])
	{
		flag=false;
	}
	if(board[0][2]==board[1][2] && board[1][2]==board[2][2])
	{
		flag=false;
	}
	if(board[0][0]==board[1][1] && board[1][1]==board[2][2])
	{
		flag=false;
	}
	if(board[0][2]==board[1][1] && board[1][1]==board[2][0])
	{
		flag=false;
	}
	return flag;
}
bool Check_Move(char number1[50],char number2[50],char o_board[][cols],char c_board[][cols],int player,char player1[50],char player2[50])
{
	char temp[rows][cols]={'1','2','3','4','5','6','7','8','9'};
	bool flag1=false,flag2=false,flag=false;
	int index1=0,index2=0,index3=0,index4=0;
	if(player==1)
	{
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<cols;j++)
			{
				if((temp[i][j]==number1[0]) && (o_board[i][j]=='X'))
				{
					index1=i;
					index2=j;
					flag1=true;
				}
			}
		}
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<cols;j++)
			{
				if((temp[i][j]==number2[0]) && (c_board[i][j]==' '))
				{
					index3=i;
					index4=j;
					flag2=true;
				}
			}
		}
		if(flag1==true && flag2==true)
		{
			if((index1==index3 && index2+1==index4) || (index1==index3 && index2-1==index4) 
				|| (index1+1==index3 && index2==index4) || (index1-1==index3 && index2==index4) 
				|| (index1+1==index3 && index2+1==index4) || (index1-1==index3 && index2-1==index4)
				|| (index1+1==index3 && index2-1==index4) || (index1-1==index3 && index2+1==index4))
			{
				flag=true;
				c_board[index1][index2]=' ';
				o_board[index1][index2]=' ';
				c_board[index3][index4]='X';
				o_board[index3][index4]='X';
			}
		}
	}
	if(player==2)
	{
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<cols;j++)
			{
				if((temp[i][j]==number1[0]) && (o_board[i][j]=='O'))
				{
					index1=i;
					index2=j;
					flag1=true;
				}
			}
		}
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<cols;j++)
			{
				if((temp[i][j]==number2[0]) && (c_board[i][j]==' '))
				{
					index3=i;
					index4=j;
					flag2=true;
				}
			}
		}
		if(flag1==true && flag2==true)
		{
			if((index1==index3 && index2+1==index4) || (index1==index3 && index2-1==index4) 
				|| (index1+1==index3 && index2==index4) || (index1-1==index3 && index2==index4) 
				|| (index1+1==index3 && index2+1==index4) || (index1-1==index3 && index2-1==index4) 
				|| (index1+1==index3 && index2-1==index4) || (index1-1==index3 && index2+1==index4))
			{
				flag=true;
				c_board[index1][index2]=' ';
				o_board[index1][index2]=' ';
				c_board[index3][index4]='O';
				o_board[index3][index4]='O';
			}
		}
	}
	return flag;
}
void Start_Game(char c_board[][cols],char o_board[][cols],char player1[50],char player2[50],int &player)
{
	int rand=0,rand1=0,rand2=0,index1=0,index2=0,count=0;
	char number[50],number1[50],number2[50];
	bool flag=true;
	while(checkwin(o_board)==true)
	{
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<cols;j++)
			{
				if(o_board[i][j]=='X' || o_board[i][j]=='O')
				{
					count++;
				}
			}
		}
		if(count<6)
		{
			if(player==1)
			{
				cout << "          " << player1 << "'s Turn, Enter Position (1-9) To Insert Your Piece: ";
			}
			if(player==2)
			{
				cout << "          " << player2 << "'s Turn, Enter Position (1-9) To Insert Your Piece: ";
			}
			cin.getline(number,50);
			for(int i=0;number[i]!='\0';i++)
			{
				rand=rand*10+(int(number[i]) - 48);
			}
			if(rand>0 && rand<10)
			{
				for(int i=0;i<rows;i++)
				{
					for(int j=0;j<cols;j++)
					{
						if(o_board[i][j]==number[0])
						{
							index1=i;
							index2=j;
							flag=false;
						}
					}
				}
				if(flag==false)
				{
					if(player==1)
					{
						o_board[index1][index2]='X';
						c_board[index1][index2]='X';
						system("cls");
						Print_Board(player1, player2,c_board);
					}
					if(player==2)
					{
						o_board[index1][index2]='O';
						c_board[index1][index2]='O';
						system("cls");
						Print_Board(player1, player2,c_board);
					}
				}
				else
				{
					cout << endl;
					cout << "          'INVALID MOVE', PRESS 'ENTER'";
					cin.get();
					system("cls");
					Print_Board(player1, player2,c_board);
				}
			}
			else
			{
				cout << endl;
				cout << "      PLEASE ENTER POSITION GREATER THAN 0 AND LESS THAN 10, PRESS 'ENTER'";
				cin.get();
				system("cls");
				Print_Board(player1, player2,c_board);
			}
		}
		else
		{
			if (player == 1)
			{
				cout << "      " << player1 << "'s Turn, Enter Position (1-9) Of The Piece, You Want To Shift: ";
			}
			if (player == 2)
			{
				cout << "      " << player2 << "'s Turn, Enter Position (1-9) Of The Piece, You Want To Shift: ";
			}
			cin.getline(number1,50);
			for(int i=0;number1[i]!='\0';i++)
			{
				rand1=rand1*10+(int(number1[i]-48));
			}
			cout << "      Enter Number (1-9), At Which Position, You Want To shift That Piece: ";
			cin.getline(number2,50);
			for (int i = 0; number1[i] != '\0'; i++)
			{
				rand2 = rand2 * 10 + (int(number2[i]) - 48);
			}
			if((rand1>0 && rand1<10) && (rand2>0 && rand2<10))
			{
				if(Check_Move(number1,number2,o_board,c_board,player,player1,player2)==true)
				{
					flag=false;
					cout<<"         OK.........";
					system("cls");
					Print_Board(player1, player2,c_board);
				}
				else
				{
					cout << endl;
					cout << "          'INVALID MOVE', PRESS 'ENTER'";
					cin.get();
					system("cls");
					Print_Board(player1, player2,c_board);
				}
			}
			else
			{
				cout << endl;
				cout << "      PLEASE ENTER POSITION GREATER THAN 0 AND LESS THAN 10, PRESS 'ENTER'";
				cin.get();
				system("cls");
				Print_Board(player1, player2,c_board);
			}
		}
		if(flag==false)
		{
			if(player==1)
			{
				player=2;
			}
			else if(player==2)
			{
				player=1;
			}
		}
		flag=true;
		index1=0;index2=0;rand=0;rand1=0;rand2=0;count=0;
	}
}
void func(char c_board[][cols],char o_board[][cols],char player1[50],char player2[50])
{
	int num,player=1;
	cout<<endl<<endl;
	cout<<"                            1) Exit"<<endl;
	cout<<"                            2) Start Game"<<endl;
	cout<<"                            Enter Choice ";
	cin>>num;
	if(num==0)
	{
		exit(0);
	}
	else if(num==1)
	{
		cin.ignore();
		cout<<endl;
		cout<<"                      Enter Player 1 Name  ";
		cin.getline(player1,50);
		cout<<endl;
		cout<<"                      Enter Player 2 Name  ";
		cin.getline(player2,50);
		system("cls");
		Print_Board(player1,player2,c_board);
		Start_Game(c_board,o_board,player1,player2,player);
		cout<<endl;
		if(--player==1)
		{
			cout<<"                    "<<player1<<" Wins The Game"<<endl;
		}
		else
		{
			cout<<"                    "<<player2<<" Wins The Game"<<endl;
		}
	}
}
int main()
{
	char choice;
	char c_board[rows][cols]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
	char o_board[rows][cols]={'1','2','3','4','5','6','7','8','9'};
	char player1[50];
	char player2[50];
	func(c_board,o_board,player1,player2);
	cin.get();
	while(1)
	{
		system("cls");
		cout<<endl<<endl;
		cout<<"                        Do You Want To Play Again (Y) OR (N) ";
		cin>>choice;
		if(choice=='Y' || choice=='y')
		{
			char c_board[rows][cols]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
			char o_board[rows][cols]={'1','2','3','4','5','6','7','8','9'};
			system("cls");
			cin.ignore();
			func(c_board,o_board,player1,player2);
		}
		else if(choice=='n' || choice=='N')
		{
			system("cls");
			cout<<endl<<endl;
			cout<<"                       Thanks For Playing "<<endl<<endl;
			break;
		}
	}
	system("pause");
	return 0;
}