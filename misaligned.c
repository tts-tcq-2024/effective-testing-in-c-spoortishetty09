#include <stdio.h>
#include <assert.h>
#include <string.h>

int printColorMap() 
{
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) 
    {
        for(j = 0; j < 5; j++)
        { 
            printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[i]);  // Note: this is intentionally buggy
        }
    }
    return i * j;
}

void testPrintColorMap() 
{
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    FILE* original_stdout = stdout;
    FILE* capture = freopen("output.txt", "w", stdout);
    
    int result = printColorMap();

    fflush(capture);
    freopen("/dev/tty", "a", stdout);
    stdout = original_stdout;
    
    FILE* file = fopen("output.txt", "r");
    fread(buffer, sizeof(char), 1024, file);
    fclose(file);

    const char* expectedOutput = 
        "0 | White | Blue\n1 | White | Orange\n2 | White | Green\n3 | White | Brown\n4 | White | Slate\n"
        "5 | Red | Blue\n6 | Red | Orange\n7 | Red | Green\n8 | Red | Brown\n9 | Red | Slate\n"
        "10 | Black | Blue\n11 | Black | Orange\n12 | Black | Green\n13 | Black | Brown\n14 | Black | Slate\n"
        "15 | Yellow | Blue\n16 | Yellow | Orange\n17 | Yellow | Green\n18 | Yellow | Brown\n19 | Yellow | Slate\n"
        "20 | Violet | Blue\n21 | Violet | Orange\n22 | Violet | Green\n23 | Violet | Brown\n24 | Violet | Slate\n";

    assert(result == 25);
    assert(strcmp(buffer, expectedOutput) == 0);

    printf("All is well (maybe!)\n");
}

int main() 
{
    testPrintColorMap();
    return 0;
}
