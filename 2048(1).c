#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

int main()
{
	int num[4][4], x, y, newnum, type, contin,iftype,memory[4][4],memx,memy;
	srand(time(NULL));
start:	
	iftype = 1;//初始化变量
	type = 0;
	contin = 1;
	for (int i = 0; i <4; i++)//初始化数组
	{
		for (int j = 0; j < 4; j++)
		{
			num[i][j] = 0;
			memory[i][j] = 0;
		}
	}
	while (1)//第一次初始化随机数
	{
		x = rand() % 4;
		y = rand() % 4;
		newnum = 2 * (rand() % 2 + 1);
		if (num[x][y] == 0)
		{
			num[x][y] = newnum;
			break;
		}
	}

	while (contin)
	{	
loop:
		system("cls");
		type = 0;
		contin = 0;
		for (int i = 0; i < 4; i++)//输出数组和提示 同时检测输赢或继续
		{
			for (int j = 0; j < 4; j++)
			{
				if(num[i][j]==0) printf("·      ");
				else if(i==x&&y==j) printf("(%d)    ", num[i][j]);
				else printf("%d      ", num[i][j]);
				if (contin != 2)
				{
					if (num[i][j] == 0) contin = 1;//检测有没有空格
				}
				if (num[i][j] == 2048) contin = 2;
			}
			if (i == 0) printf("			w·····上 s·····下");
			if (i == 1) printf("			a·····左 s·····右");
			if (i == 2) printf("			b·····后退一步 (2)(4)·····新增随机数");
			if (i == 3) printf("");
			printf("\n\n\n");
		}
		if (contin ==0)//如果没有空格，检测有没有相邻的相同数字
		{
			for (int i = 1; i < 4; i++)
			{
				if (num[3][i] == num[3][i - 1] || num[i][3] == num[i - 1][3]) contin = 1;
			}
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (num[i][j] == num[i + 1][j] || num[i][j] == num[i][j + 1]) contin = 1;
				}
			}
		}
		if (contin == 0)//输
		{
			printf("YOU LOSE\n\nPRESS \"r\" TO TRY AGAIN");
			Sleep(1000);
			while (iftype)
			{
				if (_kbhit())
				{
					while (!type)
					{
						type = 0;
						Sleep(1000);
						type = _getch();
						if (type == 114) goto start;
						else break;
					}
				}
			}
		}
		if (contin == 2)//赢
		{
			printf("YOU WIN\n\nPRESS \"r\" TO TRY AGAIN");
			while (iftype)
			{
				if (_kbhit())
				{
					while (!type)
					{
						type = 0;
						Sleep(1000);
						type = _getch();
						if (type == 114) goto start;
						else break;
					}
				}
			}
		}

		//printf("\n\n-----------------------------------\n\n\n\n");
		
		/*while (iftype)
		{*/
			while (1)//检测键盘写入wasdb
			{
				if (_kbhit())
				{
					type = _getch();
					if (type == 119 || type == 115 || type == 97 || type == 100||type==98)
					{
						break;
					}
					else type = 0;
				}
			}

			if (type!=98)//记忆为上一步
			{
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						memory[i][j] = num[i][j];
					}
				}
				memx = x;
				memy = y;
			}

			if (type == 119)//w上
			{
				for (int i = 1; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						for (int k = i; k > 0; k--)
						{
							if (num[k - 1][j] == 0)
							{
								num[k - 1][j] = num[k][j];
								num[k][j] = 0;
								//printf("1a ");
							}
							else if (num[k - 1][j] == num[k][j])
							{
								num[k - 1][j] = num[k][j] + num[k][j];
								num[k][j] = 0;
								//printf("1b");
								break;
							}
							else
							{
								//printf("1c");
								break;
							}
						}
					}
				}
			}
			else if (type == 115) //s下
			{
				for (int i = 2; i >= 0; i--)
				{
					for (int j = 0; j < 4; j++)
					{
						for (int k = i; k < 3; k++)
						{
							if (num[k + 1][j] == 0)
							{
								num[k + 1][j] = num[k][j];
								num[k][j] = 0;
								//printf("2a");
							}
							else if (num[k + 1][j] == num[k][j])
							{
								num[k + 1][j] = num[k][j] + num[k][j];
								num[k][j] = 0;
								//printf("2b");
								break;
							}
							else
							{
								//printf("2c");
								break;
							}
						}
					}
				}
			}
			else if (type == 97) //a左
			{
				for (int j = 1; j < 4; j++)
				{
					for (int i = 0; i < 4; i++)
					{
						for (int k = j; k > 0; k--)
						{
							if (num[i][k - 1] == 0)
							{
								num[i][k - 1] = num[i][k];
								num[i][k] = 0;
								//printf("3a");
							}
							else if (num[i][k - 1] == num[i][k])
							{
								num[i][k - 1] = num[i][k] + num[i][k];
								num[i][k] = 0;
								//printf("3b");
								break;
							}
							else
							{
								//printf("3c");
								break;
							}
						}
					}
				}
			}
			else if (type == 100) //d右
			{
				for (int j = 2; j >= 0; j--)
				{
					for (int i = 0; i < 4; i++)
					{
						for (int k = j; k < 3; k++)
						{
							if (num[i][k + 1] == 0)
							{
								num[i][k + 1] = num[i][k];
								num[i][k] = 0;
								//printf("4a");
							}
							else if (num[i][k + 1] == num[i][k])
							{
								num[i][k + 1] = num[i][k] + num[i][k];
								num[i][k] = 0;
								//printf("4b");
								break;
							}
							else
							{
								//printf("4c");
								break;
							}
						}
					}
				}
			}
			else if (type == 98)//b后退一步
			{	
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						num[i][j] = memory[i][j];
					}
				}
				x = memx;
				y = memy;
				system("cls");
				goto loop;
			}
		/*}
		iftype = 1;*/

		while (1)//每次循环的随机数
		{
			x = rand() % 4;
			y = rand() % 4;
			newnum = 2 * (rand() % 2 + 1);
			if (num[x][y] == 0)
			{
				num[x][y] = newnum;
				break;
			}
		}


		//printf("\n\n%d-----------------------------------\n\n\n\n",type);
	}
	return 0;
}
