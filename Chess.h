#pragma once
#include <iostream>
#include<tchar.h>
#include <windows.h>
#include<iomanip>
#include<stdlib.h>
#define WIN32_LEAN_AND_MEAN		// 从 Windows 头中排除极少使用的资料
using namespace std;
class Chess
{

public:
	enum {MapX=18,MapY=18};
	int map[MapY+1][MapX+1] = { 0 }; //棋子位置

	void Map(); //显示地图
	int Num;//第几手棋
	bool IsBlack = true;//黑子先
	int SetPoint();
	int start(); //起始
	int Win();
	Chess();
	~Chess();
};

