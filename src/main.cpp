asm(".global _printf_float");

#include <encoder1.h>
#include <mbed.h>

PwmOut pwm(PA_7);
DigitalOut dir(PA_6);

DigitalOut led(LED1);

DigitalIn sw(PA_10);

Encoder1 encoder1(360);

Thread thread(osPriorityNormal, 1024);

void encoder() {
  encoder1.start();
  while (true) {
    encoder1.update();

    printf("angle1: %lld, %f\n", encoder1.getRawSumPulse(),
           encoder1.getSumangle());
    ThisThread::sleep_for(10ms);
  }
}

int main() {
  printf("angle1: %lld", encoder1.getRawSumPulse());

  thread.start(callback(encoder));

  while (sw) {
  }

  while (true) {
    dir = !dir;
    pwm = 0.5;

    led = dir.read();
    ThisThread::sleep_for(1500ms);
    pwm = 0;
    ThisThread::sleep_for(500ms);
  }
}