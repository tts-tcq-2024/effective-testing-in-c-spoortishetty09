void printMsg(float temperature) {
    printf("ALERT: Temperature is %.1f celcius.\n", temperature);
}

void (*printMsg)(float message) = printMsg;
