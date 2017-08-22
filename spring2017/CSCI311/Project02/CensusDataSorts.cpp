/**
 * @file CensusDataSorts.cpp   Sort functions for census population data.
 * 
 * @brief
 *    Implements several different types of sorts. Data can be sorted
 * by population or by name of town. This file contains all of the sorting
 * functions and their helpers.
 *
 * @author Judy Challinger
 * @date 2/22/13
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <chrono>
#include <random>
#include "CensusData.h"

#define MAX_INT 2147483647

void CensusData::insertionSort(int searchType) 
{
    int i =0;
    Record* key = nullptr; 
    switch(searchType)
    {
        //Population
        case POPULATION:
            key = new Record(*data[0]);
            for(int j=1; (unsigned int) j<(data.size()); j++)
            {
                *key = *data[j];
                i = j-1;
                while(i>=0 && ((data[i]->population)>=(key->population)))
                {
                    *data[i+1] = *data[i];
                    i--;
                }
                *data[i+1] = *key;
            }

        break;
        //End Case

        //Name
        case NAME:
            key = new Record(*data[0]);
            for(int j=1; (unsigned int) j<(data.size()); j++)
            {
                *key = *data[j];
                i = j-1;
                while(i>=0 && (*(data[i]->city) >= *(key->city)))
                {
                    *data[i+1] = *data[i];
                    i--;
                }
                *data[i+1] = *key;
            }


        break;
        //End Case


        default:
            return; 
        break;
        //End Case
    }
}

void CensusData::mergeSort(int searchType) 
{
    merge_sort(searchType, 1, data.size());
}

void CensusData::merge_sort(int searchType, int p, int r)
{
    if(p<r)
    {
        int q = (p+r)/2;
        merge_sort(searchType, p, q);
        merge_sort(searchType, q+1, r);
        merge(searchType, p,q,r);
    }
}

void CensusData::merge(int searchType, int p, int q, int r)
{
    int n1 = q-p+1;
    int n2 = r-q;
    string sentString = "~~~~~~~~~";
    Record sentinel(sentString,sentString, MAX_INT);
    vector<Record*> left,right;
    Record* tempRec = nullptr;
    int i,j = 0;
    for(i = 1; i <= n1; i++)
    {
        tempRec = new Record(*data[(p+i-2)]);
        left.push_back(tempRec);
        tempRec = nullptr;
    }
    left.push_back(&sentinel);
    for(j = 1; j <= n2; j++)
    {
        tempRec = new Record(*data[q+j-1]);
        right.push_back(tempRec);
        tempRec = nullptr;
    }
    right.push_back(&sentinel);
    i=1;
    j=1;
    switch(searchType)
    {
        //Population
        case POPULATION:
        for(int k = p; k <= r; k++)
        {
            if(left[i-1]->population <= right[j-1]->population)
            {
                *data[k-1] = *left[i-1];
                i++;
            }
            else
            {
                *data[k-1] = *right[j-1];
                j++;
            }
        }
        break;

        //Name
        case NAME:
        for(int k = p; k <= r; k++)
        {
            if(*left[i-1]->city <= *right[j-1]->city)
            {
                *data[k-1] = *left[i-1];
                i++;
            }
            else
            {
                *data[k-1] = *right[j-1];
                j++;
            }
        }
        return;
        break;


        //Default Case
        default:
            return;
        break;
    }//end Switch statement
}

void CensusData::quickSort(int searchType) 
{
    quick_sort(searchType,1,data.size());
}

void CensusData::quick_sort(int searchType, int p, int r)
{
    if(p<r)
    {
        int q = partition(searchType, p, r);
        quick_sort(searchType, p, q-1);
        quick_sort(searchType, q+1, r);
    }
}

int CensusData::partition(int searchType, int p, int r)
{ 
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(p,r-1);
    int i = p - 1;
    int j = 0;
    int rand = distribution(generator);
    std::swap(data[rand], data[r-1]);
    switch(searchType)
    {
        //Population
        case POPULATION:
        {
            int x = data[r-1]->population;
            for(j = p; j <= r-1; j++)
            {
                if((data[j-1]->population) <= x)
                {
                    i++;
                    std::swap(data[i-1], data[j-1]);
                }
            }
            std::swap(data[i], data[r-1]);
            return i+1;
        break;
        }

        //Name
        case NAME:
        {
            string x = *data[r-1]->city;
            for(j = p; j <= r-1; j++)
            {
                if(*(data[j-1]->city) <= x)
                {
                    i++;
                    std::swap(data[i-1], data[j-1]);
                }
            }
            std::swap(data[i], data[r-1]);
            return i+1;
            return 0; 
            break;
        }


        default:
        return 0;
        break;
        //End Case
    }
}
