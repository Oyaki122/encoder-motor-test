asm(".global _printf_float");

#include <encoder1.h>
#include <encoder3.h>
#include <mbed.h>

DigitalOut dir(PA_7);
DigitalOut dir1(PA_3);
PwmOut pwm1(PA_1);
PwmOut pwm0(PA_6);
// DigitalOut dir(PA_6);

DigitalOut led(LED1);

DigitalIn sw(PA_10);

Encoder1 encoder1(360);
Encoder3 encoder3(360);

Thread thread(osPriorityNormal, 1024);

void encoder() {
  encoder1.start();
  encoder3.start();
  while (true) {
    encoder1.update();
    encoder3.update();

    printf("angle1: %lld, %lld\n", encoder1.getRawSumPulse(),
           encoder3.getRawSumPulse());
    // printf("%d\n", TIM1->CNT);
    ThisThread::sleep_for(10ms);
  }
}

int main() {
  thread.start(callback(encoder));

  pwm0.period_ms(1);

  while (sw) {
  }

  while (true) {
    dir = !dir;
    pwm0 = 0.5;

    led = dir.read();
    ThisThread::sleep_for(1500ms);
    pwm0 = 0;
    ThisThread::sleep_for(500ms);
  }
}