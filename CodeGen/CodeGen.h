#pragma once

#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <direct.h>
#include <shlobj.h>
#include <sstream>
#include <tchar.h>
#include <regex>
#include <algorithm>


const int MAX_LENGHT = 256;

enum clientElement // набор элементов управлени€
{
	button,
	editCount,
	editIdent,
	editType,
	editLenght,
	information,
	aboutApp
};



using namespace std;

const regex regNum("^[0-9]*$");//регул€рка дл€ ввода только чисел 
const regex regLetter("^[a-z]$");//регул€рка дл€ ввода только букв англ. строчные 

bool saveFile(vector<string>codes, string identifier); // сохранение в файл
vector<string>codeGen(string identifier, int lengthCodes, int countCodes, int codeFormat);//генираци€ кодов
