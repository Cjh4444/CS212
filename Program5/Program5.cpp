#include <iostream>
#include <string>
#include <vector>
#include "ChainingHashTable.h"
#include "HashTable.h"
#include "CalendarDate.h"
using namespace std;

int main() {
    CalendarDate dates[] = {
        CalendarDate(7,25,2618),
        CalendarDate(3,28,2571),
        CalendarDate(5,8,1839),
        CalendarDate(1,18,1322),
        CalendarDate(3,2,2050),
        CalendarDate(6,12,1777),
    };
        
    // Initialize hash table
    ChainingHashTable<int,CalendarDate>* table = new ChainingHashTable<int,CalendarDate>();
        
    // Add dates to table
    for (int i = 0; i < 6; i++) {
        table->Insert(dates[i].hashCode(), dates[i]);        
    }

    // print out table
    table->PrintTable(cout);
    cout << endl;

    delete table;
}