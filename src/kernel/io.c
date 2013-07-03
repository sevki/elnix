#include "../include/io.h"


void out_8(uint16_t port, uint8_t val)
{
    asm volatile( "outb %0, %1" : : "a"(val), "Nd"(port) );
}

void out_16(uint16_t port,uint16_t  val)
{
    asm volatile( "outw %0, %1" : : "a"(val), "Nd"(port) );
}

void out_32(uint16_t port, uint32_t val)
{
    asm volatile( "outl %0, %1" : : "a"(val), "Nd"(port) );
}

uint8_t in_8(uint16_t port)
{
    uint8_t ret;
    asm volatile( "inb %1, %0" : "=a"(ret) : "Nd"(port) );
    return ret;
}

uint16_t in_16(uint16_t port)
{
    uint16_t ret;
    asm volatile( "inw %1, %0" : "=a"(ret) : "Nd"(port) );
    return ret;

}

uint32_t in_32(uint16_t port)
{
    uint32_t ret;
    asm volatile( "inl %1, %0" : "=a"(ret) : "Nd"(port) );
    return ret;
}
