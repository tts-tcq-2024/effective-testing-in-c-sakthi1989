#include <stdio.h>
#include <assert.h>

#define NORMAL_TEMP_MIN 150.0
#define NORMAL_TEMP_MAX 200.0

int alertFailureCount = 0;

int networkAlertStub(float celcius) {

    if((celcius < NORMAL_TEMP_MIN) || celcius > (NORMAL_TEMP_MAX))
    {
        return 200;
    }
    else
    {
        printf("ALERT: Temperature is %.1f celcius.\n", celcius);
        return 500;
    }
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
       alertFailureCount += 0;
    }
}

int main() {
    alertInCelcius(400.5);
    assert(alertFailureCount == 0); //alertFailureCount is not incremented*/
    
    alertInCelcius(303.6);
    assert(alertFailureCount == 1); // Test should fail if alertFailureCount is not incremented
    
    alertInCelcius(500.5);
    assert(alertFailureCount == 2); // Test should fail if alertFailureCount is not incremented
    
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
