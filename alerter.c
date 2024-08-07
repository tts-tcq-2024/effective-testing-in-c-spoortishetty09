#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;

int networkAlertStub(float celcius) 
{
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Simulate a failure for temperatures above a certain threshold
    if (celcius > 200.0) {
        return 500;
    }
    return 200;
}

void alertInCelcius(float farenheit) 
{
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200)
    {
        // Increment the failure count on a non-200 response
        alertFailureCount += 1;
    }
}

void testAlertInCelcius() 
{
    alertFailureCount = 0;  // Reset the failure count before running tests

    // Test case 1: Temperature far above threshold, should fail
    alertInCelcius(400.5);  // This should fail the alert and increment the failure count
    assert(alertFailureCount == 1);

    // Test case 2: Temperature above threshold, should fail
    alertInCelcius(303.6);  // This should fail the alert and increment the failure count
    assert(alertFailureCount == 2);

    // Test case 3: Temperature below threshold, should not fail
    alertInCelcius(100.0);  // This should not fail the alert
    assert(alertFailureCount == 2);  // Failure count should remain the same

    // Test case 4: Temperature exactly at the threshold, should not fail
    alertInCelcius(392.0);  // 392 F is exactly 200 C
    assert(alertFailureCount == 2);  // Failure count should remain the same
}

int main() 
{
    testAlertInCelcius();
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
