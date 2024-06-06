/*
main() driver for Assignment #11
Bellevue College, CS212, May 2024
W.P. Iverson

DO NOT change code below, and be sure it works for other
string data like "APPLES AND BANANAS"
*/


#include "HuffmanTree.h"

int main() {
   // Huffman compression examples
   string data = "APPLES AND BANANAS";
   cout << "Huffman zyBook example:  " << data << endl << endl;

   // Show character frequency table
   cout << "Frequency table:" << endl;
   map<char, int> freq;
   freq = BuildFrequencyTable(data);
   for (map<char, int>::iterator i = freq.begin(); i != freq.end(); i++) {
       cout << i->first << " | " << i->second << endl;
   }
   cout << endl;

   // Show the dictionary from char to binary codes
   cout << "Dictionary:" << endl;
   map<char, string> codes;
   codes = HuffmanGetCodes(HuffmanBuildTree(data), "", codes);
   for (map<char, string>::iterator i = codes.begin(); i != codes.end(); i++) {
       cout << i->first << " | " << i->second << endl;
   }
   cout << endl;

   // Show compressed result
   cout << "Compressed result:" << endl;
   string binary = HuffmanCompress(data);
   cout << binary << endl << endl;

   // Show decompressed string (should be back to original)
   cout << "Decompress binary string example:" << endl;
   string output;
   HuffmanTreeNode* root;
   root = HuffmanBuildTree(data);
   output = Decompress(binary, root); // binary from HuffmanCompress function
   cout << output << endl;

   return 0;
}