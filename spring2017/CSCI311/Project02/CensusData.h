/**
 * @file CensusData.h   Declaration of the CensusData class.
 *
 * @author Judy Challinger
 * @date 2/22/13
 */

#ifndef CSCI_311_CENSUSDATA_H
#define CSCI_311_CENSUSDATA_H

#include <vector>
using std::ifstream;
using std::string;
using std::vector;

class CensusData {
public:
   static const int POPULATION = 0;       // type of sort
   static const int NAME = 1;
   ~CensusData();
   void initialize(ifstream&);            // reads in data
   int getSize(){return data.size();}
   void print();                          // prints out data
   void insertionSort(int searchType);    // sorts data using insertionSort
   void mergeSort(int searchType);        // sorts data using mergeSort
   void quickSort(int searchType);        // sorts data using quickSort
private:
   class Record {                         // declaration of a Record
   public:
      string* city;
      string* state;
      int population;
      Record(string&, string&, int);
      ~Record();
   };
   vector<Record*> data;                  // data storage
//
// You may add your private helper functions here!
//
   //merge sort helper here ==========>
   void merge_sort(int searchType, int p, int r);
   void merge(int searchType, int p, int q, int r);
   void quick_sort(int searchType, int p, int r);
   int partition(int searchTyep, int p, int r);
   bool isSmaller(int, Record*, Record*); // this is one I used - you may delete
};

#endif // CSCI_311_CENSUSDATA_H
