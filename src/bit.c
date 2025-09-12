#include <stdio.h>
#include <stdlib.h>
#include <bit.h>

// Students should fill in bodies of the functions below.

int ToggleBit(int num, int pos)
{
	// Students should implement here!
	int x = 1 << pos; // 1 in the position of the bit we want to toggle
	if (num & x) // The current bit is a 1
		num &= ~x;
	else // The current bit is 0
		num |= x;
	return num;
}

int GetMSB(int num)
{ // We will start from the leftmost position (31) and go to position 0
	int mask;
	for (int pos = 31; pos >= 0; pos --){
		mask = 1 << pos;
		if (num & mask)
			return pos;
	}
	return -1;
}

int ClearBitRange(int num, int start, int end)
{ 	int range = end - start + 1; // There are (end - start + 1) bits to be cleared
	unsigned int mask = 0xffffffff; // Create a mask where every bit is 1. We will shift them out to the right
	mask >>= (32 - range); // Shifts the necessary 1 bits all the way on the right
	mask <<= start; // The 1 bits are now in the correct position
	return num & ~mask; // We just need to negate the mask
}

int RotateLeft(int num, int d)
{ // If integers were 8 bits, then RotateLeft(182, 3) would break up 182 into 101 10110
  // and then move the 101 to the right of 10110 to get 10110101
	unsigned int leftMask = 0xffffffff << (32 - d),
	rightMask = 0xffffffff >> d;
	printf("%d , %d\n", leftMask, rightMask);
	unsigned int left = num & leftMask, right = num & rightMask;
	// We now have the integer in 2 parts. We will now swap the parts
	printf("%d , %d\n", left, right);
	left >>= 32 - d;
	right <<= d;
	return left | right;
}

int SwapOddEvenBits(int num)
{	// The LSB is an even bit, the bit in position 1 is odd, and so on...
	unsigned int evenBits = num & 0x55555555, oddBits = num & 0xAAAAAAAA;
	// Now that we have the even and odd bits in 2 separate variables,
	// we can shift them past each other and then join them
	return (evenBits << 1) | (oddBits >> 1);
}

/**
 * Create all test cases inside of the main function below.
 * Run the test cases by first compiling with "make" and then 
 * running "./build/bit"
 * 
 * Before submmiting your assignment, please comment out your 
 * test cases for the TAs.
 */
int main(int argc, char* argv[]){
	(void)argc;
	(void)argv;
	/** CREATE TEST CASES HERE **/

	/*
	printf("ToggleBit(16, 2) should return 20. Result: %d\n", ToggleBit(16, 2));
	printf("ToggleBit(40, 4) should return 56. Result: %d\n", ToggleBit(40, 4));
	printf("ToggleBit(5, 2) should return 1. Result: %d\n", ToggleBit(5, 2));
	printf("GetMSB(297) should return 8. Result: %d\n", GetMSB(297));
	printf("GetMSB(1) should return 0. Result: %d\n", GetMSB(1));
	printf("GetMSB(0) should return -1. Result: %d\n", GetMSB(0));
	printf("ClearBitRange(46, 0, 2) should return 40. Result: %d\n", ClearBitRange(46, 0, 2));
	printf("ClearBitRange(1073741823, 5, 10) should return 1073739807. Result: %d\n", ClearBitRange(1073741823, 5, 10));
	printf("ClearBitRange(250, 0, 5) should return 192. Result: %d\n", ClearBitRange(250, 0, 5));
	printf("RotateLeft(2863311530, 1) should return 1431655765. Result: %d\n", RotateLeft(2863311530, 1));
	printf("RotateLeft(0xffff0000, 4) should return -1048561. Result: %d\n", RotateLeft(0xffff0000, 4));
	printf("RotateLeft(5, 3) should return 40. Result: %d\n", RotateLeft(5, 3));
	printf("SwapOddEvenBits(0b101100110) should return 1010011001 (665). Result: %d\n", SwapOddEvenBits(0b101100110));
	printf("SwapOddEvenBits(45) should return 011110 (30). Result: %d\n", SwapOddEvenBits(45));
	printf("SwapOddEvenBits(5) should return 10. Result: %d\n", SwapOddEvenBits(5));
	*/

	/** ---------------------- **/
	return 0;
}