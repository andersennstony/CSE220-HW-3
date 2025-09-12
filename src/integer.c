#include <stdio.h>
#include <stdlib.h>
#include <integer.h>

// FILL IN THE BODY OF THIS FUNCTION.
// Feel free to create any other functions you like; just include them in this file.

void printBits(unsigned int repr){ // Just here for reference
	for (int i = 31; i >= 0; i--)
		printf("%d", (repr & (1 << i)) >> i);
	printf("\n");
}

void asHex(unsigned int repr){
	for (int i = 7; i >= 0; i--){
		printf("%x", (repr & (0x0000000f << (i * 4))) >> (i * 4));
	}
	printf("\n");
}

void repr_convert(char source_repr, char target_repr, unsigned int repr) {
	if (((source_repr != '2') & (source_repr != 'S')) || ((target_repr != '2') & (target_repr != 'S'))){
		printf("error\n");
		return;
	}
	if (source_repr == target_repr){
		asHex(repr);
		return;
	}
	if (source_repr == 'S'){ // Convert from sign/magnitude to 2's complement
		if (repr & 0x80000000){ // Negative
			// The MSB 1 is just a sign, not magnitude. We will take care of it.
			// Flip all the bits except for the MSB. We will manually make it 1
			// And then add 1
			repr = ((~repr) | 0x80000000) + 1;
		}
		asHex(repr);
		return;
	}
	// The only other possible case is conversion from 2's comp to sign/mag
	if (repr == 0x80000000){
		printf("undefined\n");
		return;
	}
	if (repr & 0x80000000){ // Negative
		repr = ((~repr) + 1) | 0x80000000;
	}
	asHex(repr);
}


/**
 * Create all test cases inside of the main function below.
 * Run the test cases by first compiling with "make" and then 
 * running "./build/integer"
 * 
 * Before submmiting your assignment, please comment out your 
 * test cases for the TAs.
 */
int main(int argc, char* argv[]){
	(void)argc;
	(void)argv;
	/** CREATE TEST CASES HERE **/

	repr_convert('S', '2', 0x80000001); // ffffffff
	repr_convert('S', '2', 0x80000000); // 00000000
	repr_convert('S', '2', 0x0fffffff); // 0fffffff // This is my own test case
	repr_convert('2', '2', 0x59f2ca50); // 59f2ca50
	repr_convert('2', '2', 0x00394812); // error
	repr_convert('2', 'S', 0x80000000); // undefined
	repr_convert('2', 'S', 0x80000010); // fffffff0
	repr_convert('2', 'S', 0x70000010); // 70000010

	
	/** ---------------------- **/
	return 0;
}