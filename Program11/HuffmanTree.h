/*
Huffman Tree compression, for Assignment #11
Bellevue College, CS212, May 2024
W.P. Iverson

Most code from zyBooks
*/

#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;

/*
 * Camden Harris
 * Spring 2024, CS212, William Iverson
 * 06/06/2024
 * Program 11
 * Huffman Tree Compression Algorithm
 */

class HuffmanTreeNode {
private:
    HuffmanTreeNode* leftChild;
    HuffmanTreeNode* rightChild;
    char character;
    int frequency;

public:
    // Constructs an internal node with the specified children. The frequency is
    // assigned with the sum of the child frequencies. 
    HuffmanTreeNode(HuffmanTreeNode* leftChildNode, HuffmanTreeNode* rightChildNode) {
        leftChild = leftChildNode;
        rightChild = rightChildNode;
        character = '\0';

        // Determine this node's frequency by summing child frequencies
        frequency = leftChild->GetFrequency() + rightChild->GetFrequency();
    }

    // Constructs a leaf node with the specified character and frequency
    HuffmanTreeNode(char leafCharacter, int leafFrequency) {
        leftChild = nullptr;
        rightChild = nullptr;
        character = leafCharacter;
        frequency = leafFrequency;
    }

    char GetCharacter() const {
        return character;
    }

    // Returns a pointer to this node's left child, or nullptr if this node is a leaf.
    HuffmanTreeNode* GetLeftChild() const {
        return leftChild;
    }

    // Returns a pointer to this node's right child, or nullptr if this node is a leaf.
    HuffmanTreeNode* GetRightChild() const {
        return rightChild;
    }

    // Returns this node's frequency. If this node is a leaf, the frequency is
    // the leaf node's character. If this node is internal, the frequency is the
    // sum of both child frequencies.
    int GetFrequency() const {
        return frequency;
    }
};

// Operator to compare Huffman Nodes in a Priority Queue
class HuffmanNodeFrequencyComparer {
public:
    bool operator()(HuffmanTreeNode* lhs, HuffmanTreeNode* rhs) {
        return lhs->GetFrequency() > rhs->GetFrequency();
    }
};

// TODO: Complete functions below, pseudo-code from zyBooks provided here
// although you can modify as you please, just needs to work with provided 
// main() driver
// 
// Some non-member functions to build frequency table and Huffman tree 
// 11.1.9 in zyBook, HuffmanGetCodes(node, prefix, output) {
map<char,string> HuffmanGetCodes(HuffmanTreeNode* node, const string& prefix, map<char, string>& output) {
    if (node && !(node->GetLeftChild() || node->GetRightChild()))
        output[node->GetCharacter()] = prefix;
    else {
        HuffmanGetCodes(node->GetLeftChild(), prefix + "0", output);
        HuffmanGetCodes(node->GetRightChild(), prefix + "1", output);
    }

    /*
        if (node is a leaf)
            output[node⇢character] = prefix
        else {
            HuffmanGetCodes(node⇢left, prefix + "0", output)
            HuffmanGetCodes(node⇢right, prefix + "1", output)
        }
    */
    return output;
}


// 11.1.3 in zyBook, BuildCharacterFrequencyTable(inputString) {
map<char, int> BuildFrequencyTable(string inputString) {
    map<char, int> table;

    for (int i = 0; i < inputString.length(); i++) {
        char currentCharacter = inputString[i];
        if (table.count(currentCharacter) == 1)
            table[currentCharacter] = table[currentCharacter] + 1;
        else table[currentCharacter] = 1;
    }
    

    /* pseudo-code from zyBooks
            for (i = 0; i < inputString⇢length; i++) {
                currentCharacter = inputString[i]
                    if (table has key for currentCharacter) {
                        table[currentCharacter] = table[currentCharacter] + 1
                    }
                    else {
                        table[currentCharacter] = 1
                    }
            }
    */
    return table;
}

// 11.1.7 in zyBook, HuffmanBuildTree(inputString) {
HuffmanTreeNode* HuffmanBuildTree(string inputString) {
    map<char, int> table = BuildFrequencyTable(inputString);

    priority_queue<HuffmanTreeNode*, vector<HuffmanTreeNode*>, HuffmanNodeFrequencyComparer> nodes;

    for (map<char, int>::iterator iter = table.begin(); iter != table.end(); iter++)
        nodes.push(new HuffmanTreeNode(iter->first, iter->second));

    while (nodes.size() > 1) {
        HuffmanTreeNode* left = nodes.top();
        nodes.pop();

        HuffmanTreeNode* right = nodes.top();
        nodes.pop();

        nodes.push(new HuffmanTreeNode(left, right));
    }

    return nodes.top();

    /* First build the frequency table
    table = BuildCharacterFrequencyTable(inputString)

        // Make a priority queue of nodes
        nodes = new PriorityQueue()
        for ((character, frequency) in table) {
            newLeaf = new LeafNode(frequency, character)
                Enqueue newLeaf into nodes
        }
    // Make parent nodes up to the root
    while (nodes⇢length > 1) {
        // Dequeue 2 lowest-priority nodes
        left = Dequeue(nodes)
            right = Dequeue(nodes)

            // Make a parent for the two nodes
            freqSum = right⇢frequency + left⇢frequency
            parent = new InternalNode(freqSum, left, right)

            // Enqueue parent back into priority queue
            Enqueue parent into nodes
    }
    return Dequeue(nodes)
}*/
    // Make a priority queue of HuffmanTreeNodes, use vector as underlying structure, with a Compare
    // see https://cplusplus.com/reference/queue/priority_queue/priority_queue/ third example
    // priority_queue<HuffmanTreeNode*, vector<HuffmanTreeNode*>, HuffmanNodeFrequencyComparer> nodes;

    // HuffmanTreeNode* omit = new HuffmanTreeNode(' ', 0); // omit for final product
    // nodes.push(omit); // doing this just so main() will run

    // return nodes.top();
}

// 11.1.10 in zyBook, HuffmanCompress(inputString) {
string HuffmanCompress(const string& inputString) {
    // string result = "omit";
    /* Build the Huffman tree
    root = HuffmanBuildTree(inputString)

        // Get the compression codes from the tree
        codes = HuffmanGetCodes(root, "", new Dictionary())

        // Build the compressed result
        result = ""
        for c in inputString{
           result += codes[c]
        }
            return result
    */

    HuffmanTreeNode* root = HuffmanBuildTree(inputString);

    map<char, string> dictionary;
    map<char, string> codes = HuffmanGetCodes(root, "", dictionary);

    string result = "";

    for(char c : inputString) result += codes[c];

    return result;
}

// 11.1.12 in zyBook, HuffmanDecompress(compressedString, treeRoot) {
string Decompress(const string& compressedString, HuffmanTreeNode* treeRoot) {
    // string result = "omit";
    /*
        node = treeRoot
            result = ""
            for (bit in compressedString) {
                // Go to left or right child based on bit value
                if (bit == 0)
                    node = node⇢left
                else
                    node = node⇢right

                    // If the node is a leaf, add the character to the
                    // decompressed result and go back to the root node
                    if (node is a leaf) {
                        result += node⇢character
                            node = treeRoot
                    }
            }
    */

    HuffmanTreeNode* node = treeRoot;
    string result = "";

    for(char c : compressedString) {
        if (c == '0') node = node->GetLeftChild();
        else node = node->GetRightChild();

        if (!(node->GetLeftChild() || node->GetRightChild())) {
            result += node->GetCharacter();
            node = treeRoot;
        }
    }

    return result;
}