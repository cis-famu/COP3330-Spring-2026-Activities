#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string encrypt(const string text, const int shift);

int main()
{
	string text = "";
	int shiftKey = 0;

	cout << "Enter your text to encode (lowercase): ";
	getline(cin, text);

	for(int i =0; i < text.length();++i)
		text[i] = tolower(text[i]);

	do{
		cout << "Enter the number for your shift (1 - 25): ";
		cin >> shiftKey;
		
		if(shiftKey < 1 ||shiftKey > 25)
			cout << "Shift must be between 1 and 25." << endl;
	}while(shiftKey < 1 || shiftKey > 25);

	string encyrptedText = encrypt(text, shiftKey);

	cout << "Encrypted text: " << encyrptedText << endl;
	return 0;
}

string encrypt(const string text, const int shift)
{
	string encryptedText = "";

	//a = 97, z = 122
	//! hello world
	//shift 3
	//! khoor zrvog

	for(int i = 0; i < text.length(); ++i)
	{
		if(!isalpha(text[i])) //is not alphabetic character
			encryptedText += text[i];
		else
		{
			int newASCIIVal = (int)text[i] + shift;
			if(newASCIIVal > 122) newASCIIVal-=26;
			encryptedText += to_string(newASCIIVal);
		}
	}
	return encryptedText;
}