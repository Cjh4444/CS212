/* Authors:
Roman Lysecky / Professor of Electrical and Computer Engineering / Univ.of Arizona
Frank Vahid / Professor of Computer Science and Engineering / Univ.of California, Riverside

Modified May 2024, by W.P. Iverson, for CS212 assignment, Bellevue College, WA
*/

#ifndef TREE234_H
#define TREE234_H

#include "Node234.h"
#include "Tree234Iterator.h"

class Tree234 {
private:
   Node234* root;
   
   // Recursively deletes the node's children, then deletes the node itself.
   void DeleteTree(Node234* node) {
      if (node) {
         // Delete all child subtrees first
         DeleteTree(node->left);
         DeleteTree(node->middle1);
         DeleteTree(node->middle2);
         DeleteTree(node->right);
         
         // Delete the node itself
         delete node;
      }
   }
   
   // Recursive helper function for search.
   Node234* SearchRecursive(int key, Node234* node) {
      if (node == nullptr) {
         return nullptr;
      }
            
      // Check if the node contains the key
      if (node->HasKey(key)) {
         return node;
      }
        
      // Recursively search the appropriate subtree
      return SearchRecursive(key, node->NextNode(key));
   }
   
   // Splits a full node, moving the middle key up into the parent node.
   // Precondition: nodeParent has one or two keys.
   Node234* Split(Node234* node, Node234* nodeParent) {
      Node234* splitLeft = new Node234(node->A, node->left, node->middle1);
      Node234* splitRight = new Node234(node->C, node->middle2, node->right);
      if (nodeParent) {
         nodeParent->InsertKeyWithChildren(node->B, splitLeft, splitRight);
         delete node;
      }
      else {
         // Split root
         nodeParent = new Node234(node->B, splitLeft, splitRight);
         delete root;
         root = nodeParent;
      }
        
      return nodeParent;
   }

public:
   // Initializes the tree by assigning the root node pointer with nullptr.
   Tree234() {
      root = nullptr;
   }
   
   virtual ~Tree234() {
      DeleteTree(root);
   }

   // Inserts a new key into this tree, provided the tree doesn't already
   // contain the same key.
   Node234* Insert(int key, Node234* node = nullptr, Node234* nodeParent = nullptr) {
      // Special case for empty tree
      if (root == nullptr) {
         root = new Node234(key);
         return root;
      }

      // If the node argument is null, recursively call with root
      if (node == nullptr) {
         return Insert(key, root, nullptr);
      }

      // Check for duplicate key
      if (node->HasKey(key)) {
         // Duplicate keys are not allowed
         return nullptr;
      }

      // Preemptively split full nodes
      if (node->CountKeys() == 3) {
         node = Split(node, nodeParent);
      }

      // If node is not a leaf, recursively insert into child subtree
      if (!node->IsLeaf()) {
         return Insert(key, node->NextNode(key), node);
      }
        
      // key can be inserted into leaf node
      node->InsertKey(key);
      return node;
   }

   // Searches this tree for the specified key. If found, the node containing
   // the key is returned. Otherwise null is returned.
   Node234* Search(int key) {
      return SearchRecursive(key, root);
   }

   // Added to support range-based for loops, for the iterator, 
   // used by Tree234Iterator when grading submitted code.
   Tree234Iterator begin() const {
       return Tree234Iterator(root);
   }

   Tree234Iterator end() const {
       return Tree234Iterator(nullptr);
   }
};

#endif