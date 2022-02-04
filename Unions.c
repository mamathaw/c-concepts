#include <stdio.h>

// Unions


void testunion01() {
	// 17-bytes
	int iVal;
	float fVal;
	double dVal;
	char ch;

	// initialize, useit, forget iVal #4bytes
	//...

	// initialize, useit, forget fVal #4bytes
	//...doJob(fVal);//...

	// initialize, useit, forget dVal #8bytes


	// initialize, useit, forget ch #1bytes
}


void testunion010() {
	{
		int iVal;

		// initialize, useit, forget iVal #4bytes
		//...
	}
	{
		float fVal;
		// initialize, useit, forget fVal #4bytes
		//...doJob(fVal);//...
	}
	{
		double dVal;
		// initialize, useit, forget dVal #8bytes
	}
	{
		char ch;
		// initialize, useit, forget ch #1bytes
	}
}

void testunion02() {
	// 8-bytes
	union myDT {
		int iVal;	// #4 // offset(0) 
		float fVal; // #4 // offset(0) 
		double dVal;// #8 // offset(0) 
		char ch;	// #1 // offset(0) 
	};
	union myDT mydt1, mydt2;
	union myDT *up = NULL;

	printf("sizeof(union myDT)= %u\n", sizeof(union myDT));
	printf("sizeof(mydt1)= %u\n", sizeof(mydt1));
	printf("sizeof(mydt2)= %u\n", sizeof(mydt2));

	up = &mydt1;
	printf("&mydt1= %p\n", &mydt1);
	printf("up= %p\n", up);
	printf("=======================\n");

	// initialize, useit, forget iVal #4bytes
	mydt1.iVal = 10;
	// &mydt1 + offset(iVal)
	// &mydt1 + offset(union myDT :: iVal)
	printf("up->iVal= %d\n", up->iVal);
	// (up) + offset(iVal)
	// (up) + offset(union myDT :: iVal)

	// initialize, useit, forget fVal #4bytes


	// initialize, useit, forget dVal #8bytes


	// initialize, useit, forget ch #1bytes

}

void getBytes() {
	int i = 10; // 4-bytes info
	char *cp = (char*)&i;

	printf(" *cp= %d\n", *cp);
	cp++;
	printf(" *cp= %d\n", *cp);
	cp++;
	printf(" *cp= %d\n", *cp);
	cp++;
	printf(" *cp= %d\n", *cp);
}


void getBytes02() {
	//int i = 10; // 4-bytes info
	//int i = 65535; // 4-bytes info
	//int i = 511;
	int i = 255 + 1;
	//int i = 511+1;
	int mask = 0xff;


	printf(" i & mask= %d\n", i & mask);
	mask <<= 8;
	printf(" (i & mask)>>8 = %d\n", (i & mask)>>8);
}


void getBytes03() {
	union {
		int m_i;
		char m_arr[4];
	}i;

	i.m_i = 10;
	printf("i.m_arr[0]= %d\n", i.m_arr[0]);
	printf("i.m_arr[1]= %d\n", i.m_arr[1]);
	printf("i.m_arr[2]= %d\n", i.m_arr[2]);
	printf("i.m_arr[3]= %d\n", i.m_arr[3]);
}

#if 0
int main() {
	//testunion01();
	//testunion02();
	//getBytes();
	//getBytes02();
	getBytes03();
}
#endif