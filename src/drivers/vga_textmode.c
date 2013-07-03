#include <vga_textmode.h>
#include <string.h>
#include <io.h>


#define VGA_BUFFER (uint16_t*)0xB8000

void vga_tm_clear_screen()
{
    size_t index;
    while(VGA_CURSOR.y < VGA_TM_HEIGHT)
    {
        while (VGA_CURSOR.x < VGA_TM_WIDTH)
        {
            index = VGA_CURSOR.y * VGA_TM_WIDTH + VGA_CURSOR.x;
            vga_tm_buffer[index] = *(uint16_t*)&(vga_tm_char){' ', COLOR_WHITE, 1, COLOR_BLACK, 0};
            VGA_CURSOR.x++;
        }
        VGA_CURSOR.x = 0;
        VGA_CURSOR.y++;
    }
}

void vga_tm_initialize()
{
    VGA_CURSOR.x = 0;
    VGA_CURSOR.y = 0;

    vga_tm_buffer = VGA_BUFFER;

    vga_tm_clear_screen();

    VGA_CURSOR.x = 0;
    VGA_CURSOR.y = 0;

}
void vga_tm_move_cursor()
{


    unsigned short position=(VGA_CURSOR.y*80) + VGA_CURSOR.x ;

    /* cursor LOW port to vga INDEX register */
    out_8(0x3D4, 0x0F);
    out_8(0x3D5, (uint8_t)(position&0xFF));
    /* cursor HIGH port to vga INDEX register */
    out_8(0x3D4, 0x0E);
    out_8(0x3D5, (uint8_t )((position>>8)&0xFF));
}


void vga_tm_set_cell(char c, size_t x, size_t y)
{
    const size_t index = y * VGA_TM_WIDTH + x;
    vga_tm_buffer[index] =  *(uint16_t*)&(vga_tm_char){c,
                                                       VGA_COLOR.fg,
                                                       VGA_COLOR.fg_bright,
                                                       VGA_COLOR.bg, VGA_COLOR.bg_bright};
}

void vga_tm_putchar(char c)
{
    if(c == '\n'){
        VGA_CURSOR.x = 0;
        VGA_CURSOR.y++;
    } else {

        vga_tm_set_cell(c, VGA_CURSOR.x, VGA_CURSOR.y);
        if ( ++VGA_CURSOR.x == VGA_TM_WIDTH )
        {
            VGA_CURSOR.x = 0;
            if ( ++VGA_CURSOR.y == VGA_TM_HEIGHT )
            {
                VGA_CURSOR.y = 0;
            }
        }
    }


}
void vga_tm_print(const char* data)
{
    size_t i = 0;
    size_t datalen = strlen(data);

    while(i < datalen ) vga_tm_putchar(data[i++]);

    vga_tm_move_cursor();
}
