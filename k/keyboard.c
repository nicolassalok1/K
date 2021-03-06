/* KBDUS means US Keyboard Layout. This is a scancode table
*  used to layout a standard US keyboard. I have left some
*  comments in to give you an idea of what key is what, even
*  though I set it's array index to 0. You can change that to
*  whatever you want using a macro, if you wish! */
#include "keyboard.h"
#include "irq.h"
#include "monitor.h"

static int col = 0;
static int caps = 0;

const unsigned char kbdus[128] =
{
    0,  27, '1', '2', '3', '4', '5', '6', '7', '8',	/* 9 */
  '9', '0', '-', '=', '\b',	/* Backspace */
  '\t',			/* Tab */
  'a', 'z', 'e', 'r',	/* 19 */
  't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',	/* Enter key */
    0,			/* 29   - Control */
  'q', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',	/* 39 */
 '\'', '`',   0,		/* Left shift */
 '\\', 'w', 'x', 'c', 'v', 'b', 'n',			/* 49 */
  'm', ',', '.', '/',   0,				/* Right shift */
  '*',
    0,	/* Alt */
  ' ',	/* Space bar */
    '&',	/* Caps lock */
    0,	/* 59 - F1 key ... > */
    0,   0,   0,   0,   0,   0,   0,   0,
    0,	/* < ... F10 */
    0,	/* 69 - Num lock*/
    0,	/* Scroll Lock */
    0,	/* Home key */
    0,	/* Up Arrow */
    0,	/* Page Up */
  '-',
    0,	/* Left Arrow */
    0,
    0,	/* Right Arrow */
  '+',
    0,	/* 79 - End key*/
    0,	/* Down Arrow */
    0,	/* Page Down */
    0,	/* Insert Key */
    0,	/* Delete Key */
    0,   0,   0,
    0,	/* F11 Key */
    0,	/* F12 Key */
    0,	/* All other keys are undefined */
};

const unsigned char CAPS[128] =
{
  'A', 'Z', 'E', 'R',	/* 19 */
  'T', 'Y', 'U', 'I', 'O', 'P', '[', ']', '\n',	/* Enter key */
    0,			/* 29   - Control */
  'Q', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';',	/* 39 */
 '\'', '`',   0,		/* Left shift */
 '\\', 'W', 'X', 'C', 'V', 'B', 'N'			/* 49 */
};

void handle_key (unsigned char scancode)
{

          if (kbdus[scancode] == '&')
          {
            caps = caps == 1 ? 0 : 1;
          }
          else
          {
            col++;
            if (caps == 0)
            {
              monitor_put(kbdus[scancode]);
            }
            else
            {
              monitor_put(CAPS[scancode - 16]);
            }

             if (col == 79)
            {
              monitor_put('\n');
              col = 0;
            }

            if (kbdus[scancode] == '\n')
            {
              col = 0;
            }

            if (kbdus[scancode] == '\b')
            {
              monitor_write(" \b");
              col--;
              col--;
            }
          }
}

/* Handles the keyboard interrupt */
void keyboard_handler()
{
    unsigned char scancode = inb(0x60);

    handle_key(scancode);

}

void keyboard_install()
{
    irq_install_handler(1, keyboard_handler);
}
