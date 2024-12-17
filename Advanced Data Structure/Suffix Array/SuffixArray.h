#ifndef SUFFIXARRAY_H
#define SUFFIXARRAY_H

class SuffixArray {
private:
    const char *str ;
    int len ;
    int *suffixArr ;
    int *rank;
    int *tempRank ;
    int *tempSuffixArr ;
    bool compare(int i , int j , int k) ;
    void mergeSort(int left , int right , int k);

public:
    SuffixArray(const char *str);
    ~SuffixArray();
    void ConstructUsingPrefixDoubling();
    void Print();

};

#endif //SUFFIXARRAY_H
