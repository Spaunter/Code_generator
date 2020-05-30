#include "CodeGen.h"


bool saveFile(vector<string>codes, string identifier) // save into file
{
	//---------------------------------save on desktop------------------------------
	cout << "Your path to file >> ";
	TCHAR appData[MAX_PATH];
	if (SUCCEEDED(SHGetFolderPath(NULL,
		CSIDL_DESKTOPDIRECTORY | CSIDL_FLAG_CREATE,
		NULL,
		SHGFP_TYPE_CURRENT,
		appData)))
		wcout << appData << endl;
	basic_ostringstream<TCHAR> file_path;
	string fileName = "\\Codes_" + identifier + ".csv";

	TCHAR* tFilePath = new TCHAR[fileName.size() + 1];
	tFilePath[fileName.size()] = 0;
	copy(fileName.begin(), fileName.end(), tFilePath);
	file_path << appData << tFilePath;
	//-----------------------------------------------------------------------------------------
	ofstream SaveFile;
	SaveFile.open(file_path.str().c_str());
	if (SaveFile.is_open())
	{
		for (int i = 0; i < codes.size(); i++)
		{
			SaveFile << codes[i] << endl;
		}
	}
	else {
		cout << "Error! no file!" << endl;
	}
	SaveFile.close();
	
	return true;
}


vector<string>codeGen(string identifier, int lengthCodes, int countCodes, int codeFormat) { // code generation
	srand(time(NULL));
	vector<string>codes;
	codes.reserve(countCodes);
	string tmpIdent = identifier;
	int i = 0;

	if (codeFormat == 1) // number code
	{
		for (; ;)
		{
			if (codes.size() == countCodes)
			{
				break;
			}
			else {
				identifier = tmpIdent; 
				for (int i = 1; i < lengthCodes; i++)
				{
					identifier += to_string(rand() % 9); // create code
				}
				auto resut = find(codes.begin(), codes.end(), identifier); // check for repetition
				if (resut == codes.end())
				{
					codes.push_back(identifier);// push code in vector
					i++;
				}
			}
			cout << i << endl;

		}
	}
	if (codeFormat == 2) // number and letters code
	{
		for (; ;)
		{
			if (codes.size() == countCodes)
			{
				break;
			}
			else {
				identifier = tmpIdent; 
				for (int i = 1; i < lengthCodes; i++)
				{
					if (i % 2 == 0) 
					{
						identifier += (char)('a' + rand() % 26);
					}
					else {
						identifier += to_string(rand() % 9);
					}
				}
				auto resut = find(codes.begin(), codes.end(), identifier); // check for repetition 
				if (resut == codes.end())
				{
					codes.push_back(identifier);// push code in vector
					i++;
				}
				cout << i << endl;
			}
		}


	}
	return codes;
}