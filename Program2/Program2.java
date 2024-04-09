package Program2;

/**
 * Program2
 */
public class Program2 {

    public static final int TEST = 14; // #define in C or const in C++
    public static void main(String[] args) {
       int test = 14;
       System.out.println( 2 & 5 ); // 0 bitwise AND with zero bits in common
       System.out.println( 2 | 5 ); //    
       System.out.println( 256 & 128 ); // 
       System.out.println( 256 | 128 ); // 
       System.out.println( TEST ); //         
       System.out.println( TEST << 2 ); // 
       System.out.println( 14 << 2 ); // 
       System.out.println( test << 2 ); // 
       System.out.println( test ); // 
       System.out.println( 'G' >> 2 ); // 
       System.out.println( 'G' << 2 ); // 
       System.out.println( 'G' & 'H' ); // 
       System.out.println( 'G' | 'H' ); // 
       System.out.println( 'G' << 222 ); // maybe a strange one here
       System.out.println( 'G' >> 222 ); // 
       System.out.println( '\n' << 2 ); // 
       System.out.println( '\n' >> 2 ); // 
       System.out.println( 0x14 ); // 0x is ???
       System.out.println( 0x0000ff00 ); // 
       System.out.println( 0x12abcdef ); // 
    }
}