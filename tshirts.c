#include <stdio.h>
#include <assert.h>

char size(int cms) {
    char sizeName = '\0';
    if(cms < 38) {
        sizeName = 'S';
    } else if(cms > 38 && cms < 42) {
        sizeName = 'M';
    } else if(cms > 42) {
        sizeName = 'L';
    }
    return sizeName;
}

int main() {
    assert(size(37) == 'S');  // S: below 38
    assert(size(38) == 'M');  // M: at the lower boundary of M
    assert(size(40) == 'M');  // M: within the range
    assert(size(42) == 'L');  // L: at the boundary of L
    assert(size(43) == 'L');  // L: above the boundary of L
    assert(size(39) == 'M');  // M: another value in the M range
    assert(size(36) == 'S');  // S: another value in the S range
    printf("All is well (maybe!)\n");
    return 0;
}
