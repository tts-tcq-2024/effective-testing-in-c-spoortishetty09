void printMsg(float temperature) {
    printf("ALERT: Temperature is %.1f celcius.\n", temperature);
}

void (*printMessage)(float message) = printMsg;
