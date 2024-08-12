#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;

int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    if (celcius > 200) { // Simulating a failure for high temperatures
        return 500;
    }
    return 200;
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // This should increment failure count, but there's a bug
        alertFailureCount += 0; // Bug: should be 'alertFailureCount += 1;'
    }
}

void test_alertInCelcius() {
    alertFailureCount = 0;

    alertInCelcius(400.5);
    assert(alertFailureCount == 1); // Expected to fail due to the bug

    alertInCelcius(303.6);
    assert(alertFailureCount == 2); // Expected to fail due to the bug

    // New test case to explicitly check for the bug
    if (alertFailureCount != 2) {
        printf("Bug detected: alertFailureCount is %d, expected 2.\n", alertFailureCount);
    } else {
        printf("No bug detected: alertFailureCount is %d.\n", alertFailureCount);
    }
}

int main() {
    test_alertInCelcius();
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
