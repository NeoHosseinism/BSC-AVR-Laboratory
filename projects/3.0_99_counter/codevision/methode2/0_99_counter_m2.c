#include <delay.h>
#include <mega32a.h>
#include <stdio.h>

void main() {

  int seg[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};

  int i = 0;

  DDRA = 0xFF;
  PORTA = 0x00;

  DDRB = 0xFF;
  PORTB = 0x00;

  while (1) {
    PORTA = seg[0];
    PORTB = seg[0];

    for (i = 0; i < 100; i++) {
      PORTA = seg[i / 10];
      delay_ms(50);

      PORTB = seg[i % 10];
      delay_ms(50);
    }
  };
}