// Original code from Daniel Liang (2003)
// now animated at yongdanielliang.github.io/animation/web/LinkedList.html
// 
// Extensively modified by W.P. Iverson
// Bellevue College, April 2024
// for CS212

/*
 * Camden Harris
 * Spring 2024, CS212, William Iverson
 * 04/12/2024
 * Program 4
 * Linked List Data Structure
 */

#include <stdexcept>
#include <iostream>
using namespace std;

template<typename T> class LinkedList;

template<typename T>
class Node {
friend class LinkedList<T>;
public:
  // No-arg constructor
  Node() { next = NULL; }

  Node(T element) // Constructor
  {
    this->element = element;
    next = NULL;
  }

  // just for console testing:
  void printNodes()
  {
      Node<T>* current = this;
      while (current->next != NULL)
      {
          cout << current->element << " ";
          current = current->next;
      }
      cout << current->element << endl;
  }

  // so we can keep nodes private
  void setNext(Node<T>* change) { next = change; }

  T getData() { return element; }
  
private:
    T element;  // Element contained in the node
    Node<T>* next; // Pointer to the next node
};

// template linked list class
template<typename T>
class LinkedList
{
public:
  LinkedList();
  void addLast(T);
  void add(T);
  void printList();
  bool addAll(LinkedList<T>&);
  bool removeAll(LinkedList<T>&);
  bool retainAll(LinkedList<T>&);
  bool remove(T);
  int lastIndexOf(T);
  bool contains(T);

private:
  Node<T>* head;
	Node<T>* tail;
  int size;
};

template<typename T>
LinkedList<T>::LinkedList()
{
  head = tail = NULL;
  size = 0;
}

template<typename T>
void LinkedList<T>::printList()
{
    head->printNodes();
}

template<typename T>
void LinkedList<T>::addLast(T element)
{
  if (tail == NULL)
  {
    head = tail = new Node<T>(element);
  }
  else
  {
      Node<T>* temp = new Node<T>(element);
      tail->setNext(temp);
      tail = temp;
  }
  size++;
}

// Standard List adds data at end of list
template<typename T>
void LinkedList<T>::add(T element)
{
  addLast(element);
}

template<typename T>
bool LinkedList<T>::addAll(LinkedList<T>& otherList) {
  if (otherList.head == NULL) return false;

  Node<T>* current = otherList.head;

  for (int i = 0; i < otherList.size; i++) {
    addLast(current->getData());
    current = current->next;
  }

  return true;
}

template<typename T>
bool LinkedList<T>::removeAll(LinkedList<T>& otherList) {
  if (otherList.head == NULL) return false;

  Node<T>* currentNode = otherList.head;
  bool listChanged = false;
  
  while(currentNode != NULL) {
    if (remove(currentNode->getData())) listChanged = true;
    currentNode = currentNode->next;
  }
  return listChanged;
}

template<typename T>
bool LinkedList<T>::retainAll(LinkedList<T>& otherList) {
  if (otherList.head == NULL) return false;

  Node<T>* currentNode = head;
  bool listChanged = false;

  while(currentNode != NULL) {
    T currentNodeData = currentNode->getData();
    currentNode = currentNode->next;  
    if (!otherList.contains(currentNodeData)) {
      if (remove(currentNodeData)) listChanged = true;
    }
  }
  return listChanged;
}

template<typename T>
bool LinkedList<T>::remove(T element) {
  if (head == NULL) return false;
  if (!contains(element)) return false;

  Node<T>* currentNode = head;
  Node<T>* prevNode;
  bool listChanged = false;

  while (currentNode != NULL) {
    if (currentNode->getData() == element) {
      if (currentNode == head) head = currentNode->next; // if head needs to be deleted
      else if (currentNode == tail) { // if tail needs to be deleted
        tail = prevNode;
        if (tail != NULL) tail->setNext(NULL);
      } else prevNode->setNext(currentNode->next); // general case

      Node<T>* temp = currentNode;
      currentNode = currentNode->next;
      delete temp;
      size--;
      listChanged = true;

    } else { 
      prevNode = currentNode;
      currentNode = currentNode->next;
    }    
  }
  return listChanged;
} 

template<typename T>
int LinkedList<T>::lastIndexOf(T element) {
  int currentIndex = 1;
  int lastIndexOfT = -1;
  Node<T>* currentNode = head;

  for (int i = 0; i < size; i++) {
    if (currentNode->getData() == element) lastIndexOfT = currentIndex;
    currentIndex++;
    currentNode = currentNode->next;
  }

  return lastIndexOfT;
}

template<typename T>
bool LinkedList<T>::contains(T element) {
  return (lastIndexOf(element) != -1);
}

