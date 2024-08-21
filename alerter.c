#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "printMessage.h"
#include "alerter.h"


int networkAlertMock(float celcius) {
    printMessage(celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    return 200;
}



int main() {
    alertInCelcius(400.5,networkAlertMock);
    alertInCelcius(303.6,networkAlertMock);
    assert(alertFailureCount==1);
    assert(alertFailureCount==0);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
