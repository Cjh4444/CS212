
#include <iostream>

using namespace std;

/*
 * Camden Harris
 * Spring 2024, CS212, William Iverson
 * 04/08/2024
 * Program 2
 * Bitshifting program with explanations for how each line works
 */

const int TEST = 14;

int main(int argc, char const *argv[])
{
    int test = 14;
    cout << (2 & 5) << '\n'; // AND of 00000010 and 00000101, no common bits, decimal 0
    cout << (2 | 5) << '\n'; // OR of 00000010 and 00000101, at least one 1 valued bit in 3 rightmost bits, binary 00000111, decimal 7
    cout << ( 256 & 128 ) << '\n'; // AND of 1000000000 and 010000000, no bits in common, decimal 0
    cout << ( 256 | 128 ) << '\n'; // OR of 1000000000 and 010000000, at least one 1 valued bit in 9th and 8th rightmost bits, binary 110000000, decimal 384
    cout << ( TEST ) << '\n'; // prints out the constant int TEST, which is just 14
    cout << ( TEST << 2 ) << '\n'; // constant int TEST, decimal 14, binary 00001110 2 bitshifts left is 00111000, decimal 56
    cout << ( 14 << 2 ) << '\n'; // 00001110 2 bitshifts left is 00001110, decimal 56
    cout << ( test << 2 ) << '\n'; // non-constant int test, decimal 14, binary 00001110 2 bitshifts left is 00001110, decimal 56
    cout << ( test ) << '\n'; // prints out the non-constant int test, which is just 14
    cout << ( 'G' >> 2 ) << '\n'; // 01000111 2 bitshifts right is 00010001, decimal 17
    cout << ( 'G' << 2 ) << '\n'; // 01000111 2 bitshifts left is 100011100, decimal 284
    cout << ( 'G' & 'H' ) << '\n'; // AND of 01000111 and 01001000, common bit in 7th rightmost position, binary 01000000, decimal 64
    cout << ( 'G' | 'H' ) << '\n'; // AND of 01000111 and 01001000, one 1 bit in at least one of the 7th, 4th, 3rd, 2nd, and 1st rightmost bits, binary 01001111, decimal 79
    cout << ( 'G' << 222 ) << '\n'; // 01000111 222 bitshifts left is 00000000, data is shifted out of the 32-bit int space, resulting in undefined behavior (my machine it outputs 1)
    cout << ( 'G' >> 222 ) << '\n'; // 01000111 222 bitshifts right is 00010001, data is shifted out of the 32-bit int space, resulting in undefined behavior (my machine it outputs 1)
    cout << ( '\n' << 2 ) << '\n'; // 00001010 2 bitshifts left is 00101000, decimal 40 
    cout << ( '\n' >> 2 ) << '\n'; // 00001010 2 bitshifts right is 00000010, decimal 2
    cout << ( 0x14 ) << '\n'; // 0x14 is hex, decimal 20
    cout << ( 0x0000ff00 ) << '\n'; // 0x0000ff00 is hex, decimal 65280
    cout << ( 0x12abcdef ) << '\n'; // 0x12abcdef is hex, decimal 313249263

    return 0;
}
