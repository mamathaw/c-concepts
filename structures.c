#include <stdio.h>

struct BIGINT {
	int lsb; // offset => #0
	int msb; // offset => #4
};

void teststruct01() {
	struct BIGINT I1;
	struct BIGINT I2;
	struct BIGINT *sp = NULL;

	I1.lsb = 10;
	// &I1 + offset(struct BIGINT :: lsb)
	I1.msb = 20;

	sp = &I1;
	printf("sp = %p\n", sp);
	printf("&I1 = %p\n", &I1);
	printf("----------------\n");
	printf("sp->lsb= %d\n", sp->lsb);
	printf("sp->msb= %d\n", sp->msb);
	printf("----------------\n");
	printf("&sp->lsb= %p\n", &sp->lsb);
	printf("&sp->msb= %p\n", &sp->msb);
	printf("----------------\n");
	printf("sizeof(struct BIGINT)= %u\n", sizeof(struct BIGINT));
}

/*
struct DAM {
	int g1; // 32-bits
	int g2;
	int g3;
	int g4;
};
*/

// bit-field structures
struct DAM {
	unsigned g1 : 1; // 1-bits
	unsigned g2 : 2; // 2-bits
	unsigned g3 : 2; // 2-bits
	unsigned g4 : 20; // 20-bits
	//unsigned g5 : 6; // 6-bits
	unsigned g5 : 8; // 8-bits
};

void bitFieldStructures() {
	struct DAM KRS;
	struct DAM *dp = &KRS;

	printf("sizeof(struct DAM)= %d\n", sizeof(struct DAM));
	KRS.g1 = 1; // 0 or 1 only // 1-bit

	KRS.g2 = 2; // 0, 1, 2, 3 // 2-bits
	//KRS.g3 = 3; // 0, 1, 2, 3 // 2-bits
	KRS.g3 = 4;
	// 100

	printf("=======================\n");
	printf("&KRS= %p\n", &KRS);
	printf("dp= %p\n", dp);
	printf("=======================\n");
	printf("dp->g1= %u\n", dp->g1);
	printf("dp->g2= %u\n", dp->g2);
	printf("KRS.g3= %u\n", KRS.g3);
	printf("=======================\n");
}

union myBit {
	unsigned m1 : 1;
	unsigned m2 : 2;
	unsigned m3 : 4;
	unsigned m4 : 5;
};

void testunionBitField() {
	union myBit ub;

	printf("sizeof(union myBit)= %u\n", sizeof(union myBit));
	ub.m1 = 1;
	printf("ub.m1= %d\n", ub.m1);

	ub.m2 = 2;
	printf("ub.m1= %d\n", ub.m1);
	printf("ub.m2= %d\n", ub.m2);
}

//#pragma pack(4)
#pragma pack(1)
//#pragma pack(8)
//#pragma pack(16)
//#pragma pack(5)

void testStuctPadding() {
	int i, k;
	char c1, c2;

	struct myUDT {
		int iVal;	// #4
		char cVal;	// #1
		double dVal;// #8
	};
	

	struct myUDT2 {
		int iVal;	// #4
		double dVal;// #8
		char cVal;	// #1
	};
	/*
	{
		mov
	}_asm
	*/
	/* gcc
	{
		mov
	}__attibute__((asm))
	*/
	printf("sizeof(struct myUDT)= %u\n", sizeof(struct myUDT));
	printf("sizeof(struct myUDT2)= %u\n", sizeof(struct myUDT2));
}

int gi2 = 10;

void testGlobal() {
	{
		int gi2 = 20;

		printf("gi2 = %d\n", gi2);
	} // add esp, sizeof(int) // remove gi2 local
	{
		printf("gi2 = %d\n", gi2);
	}
}



void testGlobal02() {
	int gi2 = 20;

	printf("gi2 = %d\n", gi2);
	
	{
		extern int gi2;
		printf("gi2 = %d\n", gi2);
	}
}

void testSelfReferentialStructures() {
	struct Node { // Self-refrencial-structures
		int data;
		struct Node * next;
	};
}

#if 0 
int main() {
	//teststruct01();
	//bitFieldStructures();
	//testunionBitField();
	//testStuctPadding();
	//testGlobal();
	//testGlobal02();
	testSelfReferentialStructures();
}
#endif
























