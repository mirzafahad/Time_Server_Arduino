#include "time_server.h"


// Callback functions for timer events
static void onBlinkTimerEvent(void);
void onD8TimerEvent(void);
void onD9TimerEvent(void);
void onD10TimerEvent(void);

// TimerEvent(Callback, interval_ms, repeat)
static TimerEvent BlinkTimer(onBlinkTimerEvent, 250, true);
static TimerEvent D8Timer(onD8TimerEvent, 250, true);
static TimerEvent D9Timer(onD9TimerEvent, 500, true);
static TimerEvent D10Timer(onD10TimerEvent, 1000, true);


void setup() 
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  

  BlinkTimer.Start();
  D8Timer.Start();
  D9Timer.Start();
  D10Timer.Start();
}

void loop() 
{
  delay(5000);
  Serial.println("Hi");
}

void onBlinkTimerEvent(void)
{
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
}

void onD8TimerEvent(void)
{
  digitalWrite(8, !digitalRead(8));
}

void onD9TimerEvent(void)
{
  digitalWrite(9, !digitalRead(9));
}

void onD10TimerEvent(void)
{
  digitalWrite(10, !digitalRead(10));
}
