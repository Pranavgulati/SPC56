
MEMORY {

//  512k Internal Flash
    flash_rsvd1  : ORIGIN = 0x00000000, LENGTH = 8
    flash_memory : ORIGIN = .,          LENGTH = 512K-8
    flash_rsvd2  : ORIGIN = .,          LENGTH = 0 


//  64KB of internal SRAM starting at 0x40000000
    dram_rsvd1   : ORIGIN = 0x40000000, LENGTH = 256
    dram_reset   : ORIGIN = .,	        LENGTH = 0
    dram_memory  : ORIGIN = ., 	 	LENGTH = 64K-256
    dram_rsvd2   : ORIGIN = ., 	        LENGTH = 0

}
DEFAULTS {
    stack_reserve = 8k
    heap_reserve = 16k
}
//
// Program layout for starting in ROM, copying data to RAM,
// and continuing to execute out of ROM.
//

//
//   If you wish to install a reset vector handler on your system,
//   uncomment the following OPTION() directive and the reference
//   to the .reset section.
//   You may not want to do this if you are relying on preinstalled
//   firmware to initialize your system.
//
//   OPTION("-u __ghs_reset_handler")

SECTIONS
{	
    .rchw						: > flash_rsvd1
    
//
// RAM SECTIONS
//
    .PPC.EMB.sdata0 	          		    ABS : > dram_memory
    .PPC.EMB.sbss0                            CLEAR ABS : > .
   
    .sdabase 		       		       ALIGN(16): > dram_memory	
    .sdata 						: > .
    .sbss 						: > .
    .data 						: > .
    .bss 						: > .
    .heap                  ALIGN(16) PAD(heap_reserve)  : > .   
    .stack                 ALIGN(16) PAD(stack_reserve) : > .

//
// ROM SECTIONS
//

    .boottext : {
	crt0.o(.text, .vletext)
	libboardinit.a(*(.text, .vletext))
	}						  > flash_memory
    .text						: > flash_memory
    .vletext						: > .
    .syscall						: > .

    .rodata		 				: > .
    .sdata2 						: > .

    .secinfo 						: > .
    .fixaddr 						: > .
    .fixtype 						: > .

    .CROM.PPC.EMB.sdata0 	  CROM(.PPC.EMB.sdata0) : > .
    .CROM.sdata  	            	   CROM(.sdata) : > .
    .CROM.data 	            		    CROM(.data) : > .

//
// These special symbols mark the bounds of RAM and ROM memory.
// They are used by the MULTI debugger.
//
    __ghs_ramstart  = MEMADDR(dram_rsvd1);
    __ghs_ramend    = MEMENDADDR(dram_memory);
    __ghs_romstart  = MEMADDR(flash_rsvd1);
    __ghs_romend    = MEMENDADDR(flash_rsvd2);

//
// These special symbols mark the bounds of RAM and ROM images of boot code.
// They are used by the GHS startup code (_start and __ghs_ind_crt0).
//
    __ghs_rambootcodestart  = 0;
    __ghs_rambootcodeend    = 0;
    __ghs_rombootcodestart  = ADDR(.boottext);
    __ghs_rombootcodeend    = ENDADDR(.fixtype);
}

