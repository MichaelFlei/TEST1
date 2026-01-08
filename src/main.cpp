#include <Arduino.h>
#include <rtc.h>
#include <mutex>
#include <FreeRTOS.h>


std::mutex mutex;
#define LED_PIN 2
#define STRF_TIME_BUFFER_SIZE   64
#define TEST_TIME 1764515612


// put function declarations here:
int myFunction(int, int);

String getTime(int64_t &timestamp) {
    time_t now;
    char strftime_buf[STRF_TIME_BUFFER_SIZE];
    struct tm timeinfo;
    time(&now);
    timestamp = now;
    gmtime_r(&now, &timeinfo);
    strftime(strftime_buf, sizeof(strftime_buf), "%c", &timeinfo);
    return strftime_buf;
}

String getTimeLocal(int64_t &timestamp) {
    setenv("TZ", "CET-1CEST,M3.5.0/2,M10.5.0/3", 1);
    tzset();
    time_t now;
    char strftime_buf[STRF_TIME_BUFFER_SIZE];
    struct tm timeinfo;
    time(&now);
    timestamp = now;
    localtime_r(&now, &timeinfo);
    strftime(strftime_buf, sizeof(strftime_buf), "%c", &timeinfo);

    setenv("TZ", "UTC+0", 1);
    tzset();
    return strftime_buf;
}

//convert a network timestamp to unix and set the system time
void convert_network_to_unix() {
    int64_t unix_timestamp = TEST_TIME;
    struct timeval tv;
    tv.tv_sec = unix_timestamp;
    tv.tv_usec = 0;


    if(settimeofday(&tv, NULL) != 0) {
      Serial.println("Error");
    }
}

void test1(){
  setenv("TZ", "UTC+0", 1);
  tzset();
  struct tm t;
  t.tm_sec = 38;
  t.tm_min = 47;
  t.tm_hour = 15;
  t.tm_mday = 30;
  t.tm_mon = 10;
  t.tm_year = 125;
  t.tm_isdst = 0;
  int64_t timestamp = mktime(&t);
  Serial.printf("The timestamp is: %llu", timestamp);
}

void test2(){
  setenv("TZ", "CET-1CEST,M3.5.0/2,M10.5.0/3", 1);
  tzset();
  struct tm t;
  t.tm_sec = 38;
  t.tm_min = 47;
  t.tm_hour = 16;
  t.tm_mday = 30;
  t.tm_mon = 10;
  t.tm_year = 125;
  t.tm_isdst = 0;
  int64_t timestamp = mktime(&t);
  Serial.printf("The timestamp is: %llu", timestamp);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(3000);
  Serial.println("Hallo Setup");
  pinMode(LED_PIN, OUTPUT);
  int64_t timestamp;


  Serial.printf("The time at system start is: %s, %llu\n", getTime(timestamp).c_str(), timestamp);
  Serial.printf("The localtime at system start is: %s, %llu\n", getTimeLocal(timestamp).c_str(), timestamp);
  convert_network_to_unix();
    Serial.printf("The time at system start is: %s, %llu\n", getTime(timestamp).c_str(), timestamp);
  Serial.printf("The localtime at system start is: %s, %llu\n", getTimeLocal(timestamp).c_str(), timestamp);
  test1();
  test2();
}


void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  digitalWrite(LED_PIN, LOW);
  delay(500);
    Serial.println("Hallo");

}
