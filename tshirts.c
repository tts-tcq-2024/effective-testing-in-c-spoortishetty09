#include <stdio.h>
#include <assert.h>

char size(int cms)
{
    char sizeName = '\0';
    if(cms < 38) 
    {
        sizeName = 'S';
    } else if(cms >= 38 && cms <= 42) {  // Fixed the condition to include the boundary value 38
        sizeName = 'M';
    } else if(cms > 42)
    {
        sizeName = 'L';
    }
    return sizeName;
}

int main() {
    // Testing boundaries and explicit edge cases
    assert(size(37) == 'S');  // Edge case for small size
    assert(size(38) == 'M');  // Boundary value between S and M
    assert(size(39) == 'M');  // Normal M value
    assert(size(40) == 'M');  // Normal M value
    assert(size(42) == 'M');  // Boundary value between M and L
    assert(size(43) == 'L');  // Edge case for large size

    // Additional edge cases to catch defects
    assert(size(0) == 'S');   // Extreme lower boundary case
    assert(size(38) == 'M');  // Explicit boundary test
    assert(size(42) == 'M');  // Explicit boundary test
    assert(size(100) == 'L'); // Extreme upper boundary case
    
    printf("All is well (maybe!)\n");
    return 0;
}
