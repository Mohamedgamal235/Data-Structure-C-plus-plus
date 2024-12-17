#include <iostream>
#include "SuffixArray.h"
using namespace std;

int main() {
    SuffixArray t("ACGACTACGATAAC$");
    t.ConstructUsingPrefixDoubling();
    t.Print(); // Expected output: 14 11 12  0  6  3  9 13  1  7  4  2  8 10  5
    return 0;
}

// The following is just illustration for your help only, nothing required about it. Check lecture.
///////////////////////////////////////////////////////////////////////////////////////////////////
// i
// 0  1  2  3  4  5  6  7  8  9 10 11 12 13 14
// t      
// A  C  G  A  C  T  A  C  G  A  T  A  A  C  $
// --------------------------------------------------
// k=0    1  2  3  1  2  4  1  2  3  1  4  1  1  2  0
// k=1    2  5  7  2  6  8  2  5  7  3  8  1  2  4  0
// k=2    3  7 10  4  9 13  3  8 11  5 12  1  2  6  0
// k=4    3  8 11  5 10 14  4  9 12  6 13  1  2  7  0
// sa=   14 11 12  0  6  3  9 13  1  7  4  2  8 10  5
///////////////////////////////////////////////////////////////////////////////////////////