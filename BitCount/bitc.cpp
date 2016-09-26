#include <iostream>
using namespace std;

int main(int arg, char** argv) {
	
	int t, num;
	
	cin >> t;
	
	for(int i = 0; i < t; i++)
	{
	    cin >> num;
	    int sbits = (num & 1);
	    
	    while(num != 0)
	    {
                num = num >> 1;
	        sbits += (num & 1);
	    }
	    
	    cout << sbits << endl;
	}
	
	return 0;
}
