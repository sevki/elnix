#include <kernel.h>
#include <kprint.h>
#include <debug.h>

void kmain()
{

    vga_tm_initialize();
    kprint("%q%Q",COLOR_YELLOW, 1); /* change the color to bright yellow */
    kprint("                                     _     _          \n");
    kprint("                                 ___| |___|_|_ _      \n");
    kprint("                                | -_| |   | |_'_|     \n");
    kprint("                                |___|_|_|_|_|_,_|     \n");
    kprint("                               %Q%qElectric Lady UNIX%Q%q   \n\n",0,COLOR_YELLOW,1,COLOR_WHITE);
    kprint("In a VM not far, far away...\n\n");
    ksucc("Kernel loaded.");


}
