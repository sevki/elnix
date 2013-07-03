#ifndef _KERNEL_IO
#include <stdint.h>
#define _KERNEL_IO
/*
 * Write out to the port.
 */
void out_8(uint16_t port, uint8_t val);
void out_16(uint16_t port,uint16_t  val);
void out_32(uint16_t port, uint32_t val);

/*
 * Read in from the port.
 */
uint8_t in_8(uint16_t port);
uint16_t in_16(uint16_t port);
uint32_t in_32(uint16_t port);

#endif
