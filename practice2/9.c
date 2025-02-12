#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    float temperature;
    float humidity;
    enum Condition {
        Sunny, Cloudy, Rainy
    } condition;
} Weather;


enum Condition str_to_condition(const char* s) {
    if (!strcmp(s, "Sunny")) {
        return Sunny;
    }
    if (!strcmp(s, "Cloudy")) {
        return Cloudy;
    }
    if (!strcmp(s, "Rainy")) {
        return Rainy;
    }
    return -1;
}

int main() {
    Weather weather;
    char condition[64]; 
    scanf("%f%f%s", &weather.temperature, &weather.humidity, condition);
    weather.condition = str_to_condition(condition);
    printf("Temperature: %.1f°C\nHumidity: %.1f%%\nCondition: %s\n", weather.temperature, weather.humidity, condition);
}