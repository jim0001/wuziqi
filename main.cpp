#include<iostream>
#include"Chess.h"
//#include <stdio.h>
//#include <tchar.h>
//#include <stdlib.h>
#include <windows.h>

#define WIN32_LEAN_AND_MEAN		// 从 Windows 头中排除极少使用的资料
using namespace std;
 
int main()
{
	system("color F0");
	HWND hwnd = GetForegroundWindow();
	SetWindowTextA(hwnd, "五子棋");
	int winer = 0;

	Chess Temp;
	Temp.start();
	return 0;
}