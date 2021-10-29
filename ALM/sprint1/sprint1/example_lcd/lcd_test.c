/*
 * Small test to draw some things on the screen using
 * the CLCD controller of the * versatilpb qemu board
 *
 * Some resources :
 * versatilpb.c : https://github.com/hackndev/qemu/blob/master/hw/versatilepb.c
 * clcd (pl110) ref manual : http://infocenter.arm.com/help/topic/com.arm.doc.ddi0161e/DDI0161.pdf
 * pl110 full manual : http://infocenter.arm.com/help/topic/com.arm.doc.ddi0161e/DDI0161.pdf
 * versatil doc : https://static.docs.arm.com/dui0225/d/DUI0225D_versatile_application_baseboard_arm926ej_s_ug.pdf
 */


static unsigned char g_current_fb = 0;
static unsigned int g_FB[2][800*600];

void print_square(int x, int y, int w, int h)
{
    int i, j;

    for(j = y ; j < h+y ; j++) {
        for(i = x ; i < w+x ; i++) {
            g_FB[1-g_current_fb][i + j*800] = 0;
        }
    }
}

void swap_buffer()
{
    g_current_fb = 1 - g_current_fb;
    *(volatile unsigned int *)(0x10120010) = (unsigned int)g_FB[g_current_fb];
}

void init_clcd()
{
    *(volatile unsigned int *)(0x1000001C) = 0x2CAC; /* timing magic for SVGA 800x600 */
    *(volatile unsigned int *)(0x10120000) = 0x1313A4C4;
    *(volatile unsigned int *)(0x10120004) = 0x0505F657;
    *(volatile unsigned int *)(0x10120008) = 0x071F1800;
    *(volatile unsigned int *)(0x10120010) = (unsigned int)g_FB[g_current_fb]; /* base addr of frame buffer */
    *(volatile unsigned int *)(0x10120018) = 0x82b; /* control bits */
}

int main(void)
{
    int i;
    int x = 1, y = 1;
    int vx = 1, vy = 2;

    init_clcd();

    while(1) {

        for(i = 0 ; i < 800*600 ; i++) {
            g_FB[1-g_current_fb][i] = 0x00FFCCDD;
        }

        print_square(x, y, 50, 50);

        swap_buffer();

        x = x+x*vx;
        y = y+y*vy;
    }

    return 0;
}

