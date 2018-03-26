#include "Chess.h"



void Chess::Map()
{
	system("cls");
	int t=0;
	while (t<MapX)
		cout << setw(2) << t++;
	cout << endl;
	int j, i = j = 0;
	//y轴
	for (; i <= MapY; i++)
	{
		j = 0;  //x轴
		for (; j <= MapX; j++)
		{
			if (map[i][j] == 0) {
				if (i == 0 && j == 0)
					cout << "┌";
				else if (j == 0 && i == MapY)
					cout << "└";
				else if (j == MapX && i == 0)
					cout << "┐";

				else if (j == MapX && i == MapY)
					cout << "┘";

				else if (i == 0 && j != 0)
					cout << "┬";
				else if (i != 0 && j == 0)
					cout << "├";
				else if (i == MapY&&j !=0)
					cout << "┴";
				else if (i != 0 && j == MapX)
					cout << "┤";
				else
				{
					cout << "┼";
				}
			}
			else if (map[i][j] == 1)
			{
				cout<<"●";
			}
			else if (map[i][j] == 2)
			{
				cout<<"○";
			}
		}
		cout << "\n";
	}
}

int Chess::SetPoint()
{
	int  j;
	int i;
	cout << "请输入棋子的x轴和y轴（以空格隔开，输入99退出）\n";
	cout << "现在是" << (IsBlack ? _T("黑子:") : _T("白子:"));
	cin.clear();
	cin >> i;
	cin >> j;
	if (i == 99)
		return 0;
	if (i < 0 || j < 0 || i > MapX || j > MapY)
	{
		printf("输入不在棋盘范围内, 请重新输入!\n");
		//cout << unitbuf;
		while ((i = getchar()) != EOF && i != '\n');
		cin.sync();
		SetPoint();
	}
	else if (map[j][i] != 0)
	{
		printf("输入位置已有棋子, 请重新输入!\n");
		SetPoint();
	}
	else
	{//黑子 为true 1
		if (IsBlack)
		{
			map[j][i] = 1;
			Num++;
		}
		else
		{
			map[j][i] = 2;
		}
		IsBlack = !IsBlack;
	}
	return 1;
}

int Chess::Win()
{
	int p;//记录 此时 下子的是黑还是白
	p=IsBlack == true ? 2 : 1;
	int x;//10行
	int y;//20列
	int count = 0;
	//y轴  y=j 注定 了 有20列 
	for (int j = 0; j < MapY; j++)
	{//X轴  x=i 第10行
		for (int i = 0; i < MapX; i++)
		{
			if (map[j][i] != p)
			   continue;

			//竖着方向 y轴 向下
			    x = i, y = j,count = 0;
			while (--y >= 0 && map[y][x] == p)
				count++;
			y = j;
			while (++y < MapY && map[y][x] == p)
				count++;
			if (count+1 >= 5)
				return p;

			//横方向 x轴 左右
		    	x = i, y = j,count = 0;
			while (--x >= 0 && map[y][x] == p)
				count++;
			x = i;
			while (++x < MapX&&map[y][x] == p)
				count++;
			if (count + 1 >= 5)
				return p;

			//左斜右方向
		    x = i, y = j, count = 0;
			while ((--y >=0&&--x>=0) && map[y][x] == p)
				count++;
			x = i, y = j;
			while ((++y < MapY&&++x<MapX) && map[y][x] == p)
				count++;
			if (count + 1 >= 5)
				return p;

			//右斜左方向
			x = i, y = j, count = 0;
			while ((++y < MapY && --x >= 0) && map[y][x] == p)
				count++;
			x = i, y = j;
			while ((--y>=0 &&++x<MapX) && map[y][x] == p)
				count++;
			if (count + 1 >= 5)
				return p;
			count = 0;
		}
	}
	return 0;
}

int Chess::start()
{
	int i=0;
	int winer = 0;
	char T = 'y';
	while (T=='y'||T=='Y')
	{
		Map();
		i= SetPoint();
		if (i==0)
			return 0;
		winer = Win();
		if (winer == 1)
		{
			cout << "黑子获胜\n";
			cout << "请问是否需要重新开始？（y/n）" << endl;
			cin >> T;
		}
		if (winer == 2)
		{
			cout << "白子获胜";
			Sleep(1000);
			cout << "请问是否需要重新开始？（y/n）" << endl;
			cin >> T;
		}

	}
	return 0;
}
Chess::Chess()
{
	Num = 0;
}


Chess::~Chess()
{
}
