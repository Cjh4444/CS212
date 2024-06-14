#ifndef TREE234ITERATOR_H
#define TREE234ITERATOR_H

// OPTIONAL: Include any needed header files
#include "Node234.h"

// OPTIONAL: Declare any additional classes needed for iteration

class Tree234Iterator {
private:
   // TODO: Type your code here

public:
   Tree234Iterator(Node234* root) {
      // TODO: Type your code here
      // If the root pointer is non-null, then this iterator is being
      // constructed to point to the tree's minimum key.
      // If the root pointer is null, then this iterator is being constructed
      // to represent the exclusive endpoint of iteration.
   }
   
   Tree234Iterator(const Tree234Iterator& toCopy) {
      // TODO: Type your code here
   }
   
   // Copies the other iterator's data to this iterator.
   Tree234Iterator& operator=(const Tree234Iterator& other) {
      // TODO: Type your code here. Keep the final return statement, but insert 
      // code to copy the other iterator's data to this iterator.
      
      return *this;
   }
   
   // Returns true if this iterator represents the same point of iteration as
   // the other, false otherwise.
   bool operator==(const Tree234Iterator& other) const {
      // TODO: Type your code here (remove placeholder line below)
      return true;
   }
   
   // Returns false if this iterator represents the same point of iteration as
   // the other, true otherwise.
   bool operator!=(const Tree234Iterator& other) const {
      // TODO: Type your code here (remove placeholder line below)
      return false;
   }
   
   // Returns the key that this iterator currently points to.
   int operator*() const {
      // TODO: Type your code here (remove placeholder line below)
      return -1;
   }
   
   // Advances this iterator to the tree's next key.
   Tree234Iterator& operator++() {
      // TODO: Type your code here. Keep the final return statement, but insert code to
      // advance this iterator to the next key. If this iterator currently
      // points to the tree's maximum key, then the iterator must enter a state
      // representing completion of iteration.
      
      return *this;
   }
};

#endif