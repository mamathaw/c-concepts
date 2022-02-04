#include <stdio.h>

/*
typedef
*/

void gfun1() { printf("gfun11111\n"); }
void gfun2() { printf("gfun22222\n"); }

//void* gfun();

//#define FNPTR (void(*)())

void testTypedef() {
	//void(*fp1) ();
	//void(*fp2) ();

	//typedef unsigned int UINT;
	//UINT ui1, ui2;

	//typedef void *()  FNPTR;
	
	//typedef void (*)()  FNPTR;

	typedef void(*FNPTR)();
	FNPTR fp1, fp2;

	fp1 = gfun1;
	fp2 = gfun2;

	fp1(); // call (fp1) // run-time
	printf("-------------\n");
	fp2();

	//gfun1(); // call CS::offset // compile-time

	printf("-------------\n");
	printf("gfun1= %p\n", gfun1);
	printf("gfun2= %p\n", gfun2);
	printf("-------------\n");
	printf("fp1= %p\n", fp1);
	printf("fp2= %p\n", fp2);
	printf("-------------\n");
}

void gfun4(int arg[10][20]) { printf("gfun444\n"); }
void gfun5(int arg[5][20]) { printf("gfun5555\n"); }
void gfun6(int arg[10][40]) { printf("gfun666\n"); }

void testTypedef02() {
	int arr[10][20];
	//void(*fnptr) (int[10][20]);

	typedef void(*FNPTR) (int[10][20]);
	
	FNPTR fnptr;

	//fnptr = gfun4;
	//fnptr = gfun5;
	fnptr = gfun6;
	printf("gfun4= %p\n", gfun4);
	printf("gfun5= %p\n", gfun5);
	printf("gfun6= %p\n", gfun6);
	printf("fnptr= %p\n", fnptr);

	fnptr(arr);
}

int garr[10][40];

typedef int(*GFNPTR)[10][40];

//int (* [][40]) gfun7() { 
GFNPTR gfun7() {
	printf("gfun777\n"); 
	return garr;
}

void testTypedef03() {
	//GFNPTR gfp1;
	//int(*ap)[10][40];

	typedef GFNPTR(*FNPTR) ();
	FNPTR gfp1;
	gfp1 = gfun7;

	printf("gfun7= %p\n", gfun7);
	printf("gfp1= %p\n", gfp1);
	printf("-------------------\n");
	//ap = gfp1();
	printf("-------------------\n");
	gfp1();
	printf("-------------------\n");
	printf("garr= %p\n", garr);
	//printf("ap= %p\n", ap);
}

int fun1() { return 0; }
int gi = 100;
int * fun2() { return &gi; }

int garr1[10];
//int [10] fun3() { return &garr1; }
int* fun3() { return &garr1; }

int garr2[10][20];
typedef int(*GA2)[10][20];

GA2 fun4() { return &garr2; }

void testTypedef04() {
	int(*fp1)();
	typedef int(*IFNPTR)(); //IFNPTR fp1, fp2;
	fp1 = fun1; // valid

	int* (*fp2)();
	fp2 = fun2; // valid
	typedef int* (*IFNPTR2)();
	// IFNPTR2 fp22, fp23;

	GA2 ap2 = fun4();
	printf("ap2= %p\n", ap2);
	printf("garr2= %p\n", garr2);
	printf("================\n");
	printf("sizeof(garr2)= %u\n", sizeof(garr2));
	printf("sizeof(*ap2)= %u\n", sizeof(*ap2));
}


//int *[10][20]
int (*(fun5)())[20] { return garr2; }

void testTypedef05() {
	int (*(p2d))[20];

	p2d = fun5();
	printf("p2d= %p\n", p2d);
	printf("garr2= %p\n", garr2);
}

#if 0
int main() {
	//testTypedef();
	//testTypedef02();
	//testTypedef03();
	//testTypedef04();
	testTypedef05();
}
#endif