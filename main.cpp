#include <unistd.h>
#include <iostream>
using namespace std;

class MyType {
public:
	typedef enum enType {
		ZERO = 0,
		ONE,
		TWO,
		FOUR_HUNDRED = 400,
		FF_AND_42 = 0xFF42
	} T_Type;

	T_Type m_eType;
	MyType(T_Type eSetType) : m_eType(eSetType) {};
	T_Type getType() { return m_eType; };
};

void loop(int times) {
    int i;
    for (i=0; i<times; i++) {
        printf("delay %d\r\n", i);
        sleep(1);
    }
}

int main()
{	
 int i = 0xFF43;
 char c;
 
 cout << "\nKlocwork_Test!\n" << endl;
  
 // Trying to detect this
 c = i; // 0x43 ascii char -> 'C'
 cout << "c = " << c << endl; // Expected output: c = C (ASCII 0x43 is 'C')
 
 // And this
 MyType obj(MyType::FF_AND_42);
 c = obj.getType();
 cout << "c = " << c << endl; // Expected output: c = B (ASCII 0x42 is 'B')
 
 // Buffer overflow - Just to check Klocwork desktop analysis is working
 char array[3];
 array[3] = 'z';
 
 // Push this change
 cout << "Push this change" << endl;
 
 loop(5);
 
 return 0;
}