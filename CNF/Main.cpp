#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool AllReadyIn(string a, char b)
{
	for (int i = 0; i < a.length(); i++)
	{
		if (a.at(i) == b)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	string CNFFIleText = "";
	int numbClauses = 0;
	int numbLiterals = 0;
	string Done = "";
	system("cls");
	ifstream file;
	file.open("CNF.txt", ios_base::in);
	file.seekg(0);
	int fileSize = file.tellg();

	if (!file.is_open())
	{
		file.close();
		cout << "Can't do dat fam" << endl;
		system("pause");
		return 0;
	}
	else
	{
		file >> CNFFIleText;
		// cout << CNFFIleText << endl;
		char a = ')';
		for  (int i = 0; i < CNFFIleText.length(); i++)
		{
			if (CNFFIleText.at(i) == a)
			{
				numbClauses++;
			}

			if (CNFFIleText.at(i) != '(' // Begin clause
				& CNFFIleText.at(i) != ')' // End clause
				& CNFFIleText.at(i) != 'V' // and
				& CNFFIleText.at(i) != '&' // or
				& CNFFIleText.at(i) != '?' // not
				& !AllReadyIn(Done, CNFFIleText.at(i)))
			{
				Done += CNFFIleText.at(i);
			}
		}
		
		// -----------------------------------------------------


	}
	system("pause");
	return 1;
}