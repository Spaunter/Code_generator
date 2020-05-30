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

enum clientElement // client controls
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

const regex regNum("^[0-9]*$");//regular expression on number
const regex regLetter("^[a-z]$");//regular expression on letters

bool saveFile(vector<string>codes, string identifier); // save into file
vector<string>codeGen(string identifier, int lengthCodes, int countCodes, int codeFormat);//code generetion
