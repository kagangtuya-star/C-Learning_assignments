#include <iostream>
using namespace std;

int main()
{
	char a;
	cout << "Enter a letter:";
	cin >> a;
	
	if (a>64&&a<91){
		a+=32;
		cout << "result is " << a;
	}
	else if (a>96&&a<123){
		a-=32;
		cout << "result is " << a;
	} 
	else {
		cout << "You're not typing letters! Reenter!" << endl;
	}
	
	return 0;
	
}
