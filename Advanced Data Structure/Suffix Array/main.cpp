#include <iostream>
#include "SuffixArray.h"
using namespace std;

int main() {
    SuffixArray t("ACGACTACGATAAC$");
    t.ConstructUsingPrefixDoubling();
    t.Print(); // Expected output: 14 11 12  0  6  3  9 13  1  7  4  2  8 10  5
    return 0;
}

