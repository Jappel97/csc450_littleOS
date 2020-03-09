#include "io.h"
#include "string.h"
#include "segments.h"
#include "interrupts.h"
#include "mem_manager.h"
#include "frame_buffer.h"
#include "etc.h"

int main() 
{
    //prepare OS for handing out mem
    unmarkAllMemory();
    segments_install_gdt();
	interrupts_install_idt();
    char* s;
    fb_clear();
    for(int i = 0; i < 25; i++)
    {
        s = getMem(5);//dataSpaceStart; //malloc 5 * sizeof(char) -> give me 5 bytes
        strcpy(s, "hello", 5);
        fb_write_string(80*2*i, s,5);
        freeMem(s, 5);
    }
    //Sleep for 1,000,000 instructions:
    for(int i = 0; i < 1000000; i++)
    {
		sleep();
	}
	fb_clear();
	
	//the OS Main Looooooooooop
	while(1){
		sleep();
	}
    return 0;
}
