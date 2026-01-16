#include <iostream>
#include <string>
using namespace std;

int main()
{
	int scores[] = {85, 45, 67, 90, 46, 89};

	const int SIZE = 6;

	//forward
	for(int i = 0; i < SIZE; ++i)
	{
		cout << scores[i] << endl;
	}
	
	//reverse
	for(int i = SIZE - 1; i >= 0; --i )
		cout << scores[i] << endl;

	for (int i = SIZE; i > 0; --i)
		cout << scores[i - 1] << endl;
	
	string sentence = "HELLO BOB";
	char sentence2[] = {'H','E','L','L','O',' ', 'B', 'O', 'B'};

	for(int i = 0; i < sentence.length(); ++i)
		cout << sentence[i] << endl;
	return 0;
}