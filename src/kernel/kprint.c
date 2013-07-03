#include <kprint.h>
#include <itoa.h>
#include <string.h>
#include <vga_textmode.h>

void kprint(const char *temp, ...)
{
    va_list args;
    va_start(args, temp);

    do{
        if( *temp == '%'){
            switch(*++temp){
            case 'd': case 'i':
                vga_tm_print(itoa(va_arg(args, int)));
                break;
            case 's':
                vga_tm_print(va_arg(args, char*));
                break;
            case 'q':
                VGA_COLOR.fg = va_arg(args, int);
                break;
            case 'Q':
                VGA_COLOR.fg_bright = va_arg(args, int);
                break;
            case 'w':
                VGA_COLOR.bg = va_arg(args, int);
                break;
            case 'W':
                VGA_COLOR.bg_bright = va_arg(args, int);
                break;
            default: case 'c': case 'x':
                vga_tm_putchar(*temp);
                break;
            }
        } else {
            vga_tm_putchar(*temp);
        }
    } while( *++temp != '\0');


    va_end(args);

    vga_tm_move_cursor();

}
