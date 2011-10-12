#include <avr/io.h>
#include <util/delay.h>

#define FCPU 10000000UL

void delay_1min(void)
{
int i;
for (i=0; i<60 ;i++)
_delay_ms(1000);
}

void delay_1hr(void)
{
int i;
for (i=0; i<60 ;i++)
delay_1min();
}

void delay_23hr(void)
{
int i;
for (i=0; i<23 ;i++)
delay_1hr();
}

void start(void)
{
PORTB = 0b00010000;
}

void stop(void)
{
PORTB = 0b00000000;
}

int main(void)
{
DDRB = 0b00010000;
PORTB = 0b00000000;

while(1)
{
start();
delay_1hr();
stop();
delay_23hr();
}
}