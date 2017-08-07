#include<iostream>
#include"Reversi.h"

using namespace std;

SystemType InputConnectionType();

int main(void)
{
	ReversiEngine reversiEngine;
	reversiEngine.SetConnectionType(InputConnectionType());

	switch (reversiEngine.GetConnectionType())
	{
	case SystemType::Server:
		cout << "Server..." << endl;
		break;

	case SystemType::Client:
		cout << "Client..." << endl;
		break;

	case SystemType::Other:
		cout << "Other..." << endl;
		break;

	default:
		break;
	}

	cout << "–¢Š®¬‚¾‚Á‚½Œ" << endl;

	return -1;
}

SystemType InputConnectionType()
{
	string input;

	cout << "1...Server" << endl;
	cout << "2...Clinet" << endl;
	cout << endl;
	cout << "Pleace Input Mode." << endl;
	cout << ">";
	getline(cin, input);

	switch (atoi(input.c_str()))
	{
	case 1:
		cout << "Selected Server Mode..." << endl;
		return SystemType::Server;
		break;

	case 2:
		cout << "Selected Clinet Mode..." << endl;
		return SystemType::Client;
		break;

	default:
		cout << "Please Input 1 or 2." << endl;
		return SystemType::Other;
		break;
	}
}