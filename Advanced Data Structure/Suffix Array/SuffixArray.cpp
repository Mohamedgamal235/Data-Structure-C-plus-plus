#include "SuffixArray.h"
#include <iostream>
using namespace std;


//////////////////////// implement Helper Functions ///////////////////////////

bool SuffixArray::compare(int i, int j, int k) {
    if (rank[i] != rank[j])
        return rank[i] < rank[j] ;

    int rank_i = -1 , rank_j = -1;
    if (i + k < len)
        rank_i = rank[i + k] ;
    if (j + k < len)
        rank_j = rank[j + k] ;
    return rank_i < rank_j ;
}

// ----------

void SuffixArray::mergeSort(int l, int r, int k) {
    if (l >= r )
        return;

    int mid = (r + l) / 2 ;

    mergeSort(l , mid , k);
    mergeSort(mid + 1 , r , k);

    int i = l , j = mid + 1 , idx = l ;

    while (i <= mid && j <= r) {
        if (compare(suffixArr[i] , suffixArr[j] , k))
            tempSuffixArr[idx] = suffixArr[i] , i++ , idx++ ;
        else
            tempSuffixArr[idx] = suffixArr[j] , j++ , idx++ ;
    }

    while(i <= mid)
        tempSuffixArr[idx] = suffixArr[i] , i++ , idx++ ;

    while(j <= r)
        tempSuffixArr[idx] = suffixArr[j] , j++ , idx++ ;

    for (int m = l ; m <= r ; m++)
        suffixArr[m] = tempSuffixArr[m] ;
}

// ----------

SuffixArray::SuffixArray(const char *str) {
    this->str = str ;
    len = 0 ;
    while (this->str[len] != '\0')
        len++ ;
    rank = new int[len] ;
    suffixArr = new int[len] ;
    tempRank = new int[len];
    tempSuffixArr = new int[len] ;
}

// -----------

SuffixArray::~SuffixArray() {
    delete[] suffixArr ;
    delete[] rank ;
    delete[] tempRank ;
    delete[] tempSuffixArr ;
}

// -----------

void SuffixArray::ConstructUsingPrefixDoubling() {
    for (int i = 0 ; i < len ; i++) {
        suffixArr[i] = i ;
        rank[i] = str[i] ;
    }

    for (int k = 1 ; k < len ; k *= 2 ) {
        cout << "Suffix Array : " ;
        for (int i = 0 ; i < len ; i++)
            cout << suffixArr[i] << ' ' ;
        cout << '\n' ;

        cout << "Rank : " ;
        for (int i = 0 ; i < len ; i++)
            cout << rank[i] << ' ' ;
        cout << '\n' ;

        mergeSort(0 , len - 1 , k) ;


        cout << "==================\n" ;

        // update rank after sorrrtingg
        tempRank[suffixArr[0]] = 0 ; // char of $ -> 0
        for (int i = 1 ; i < len ; i++)
            tempRank[suffixArr[i]] = tempRank[suffixArr[i-1]] + compare(suffixArr[i-1] , suffixArr[i] , k);

        // update original rank arrayy
        for (int i = 0 ; i < len ; i++)
            rank[i] = tempRank[i] ;
    }
}

// -----------

void SuffixArray::Print() {
    for (int i = 0 ; i < len ; i++)
        cout << suffixArr[i] << ' ' ;
    cout << '\n' ;
}





