#include <stdio.h>
#include <assert.h>

char size(int cms) {
    char sizeName = '\0';
    if(cms < 38) {
        sizeName = 'S';
    } else if(cms >= 38 && cms <= 42) { // Fixing boundary condition
        sizeName = 'M';
    } else if(cms > 42) {
        sizeName = 'L';
    }
    return sizeName;
}

int main() {
    // Test boundary values and beyond
    assert(size(37) == 'S'); // Below lower boundary
    assert(size(38) == 'M'); // Lower boundary
    assert(size(39) == 'M'); // Inside range
    assert(size(40) == 'M'); // Inside range
    assert(size(42) == 'M'); // Upper boundary
    assert(size(43) == 'L'); // Above upper boundary

    // Test values that should not fit any category (should return '\0')
    assert(size(-1) == '\0'); // Negative value
    assert(size(0) == '\0');  // Zero value

    printf("All is well (maybe!)\n");
    return 0;
}
