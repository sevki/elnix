#ifndef _VGA_TM_TEXTMODE_
#define _VGA_TM_TEXTMODE_

#include <stdint.h>
#include <stddef.h>

/* Hardware text mode color constants. */
enum vga_tm_color
{
    COLOR_BLACK = 0,
    COLOR_BLUE = 1,
    COLOR_GREEN = 2,
    COLOR_CYAN = 3,
    COLOR_RED = 4,
    COLOR_MAGENTA = 5,
    COLOR_YELLOW = 6,
    COLOR_WHITE = 7,
};

struct
{
    size_t x , y;
}VGA_CURSOR;

typedef struct
{
    char vchar;
    unsigned fg: 3;
    unsigned fg_bright :1;
    unsigned bg: 3;
    unsigned bg_bright: 1;
}vga_tm_char;

struct
{
    unsigned fg: 3;
    unsigned fg_bright :1;
    unsigned bg: 3;
    unsigned bg_bright: 1;
}VGA_COLOR;

static const size_t VGA_TM_WIDTH = 80;
static const size_t VGA_TM_HEIGHT = 24;

uint16_t* vga_tm_buffer;


void vga_tm_initialize();
void vga_tm_clear_screen();
void vga_tm_set_cell(char c, size_t x, size_t y);
void vga_tm_putchar(char c);
void vga_tm_move_cursor();

void vga_tm_print(const char* data); /* Print string to kernel */

#endif /* VGA textmode driver */
