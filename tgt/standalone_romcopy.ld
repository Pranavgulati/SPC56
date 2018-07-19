
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
// Program layout for starting in ROM, copying text and data to RAM,
// and then running out of RAM.
//

//
//   If you wish to install a reset vector handler on your system,
//   uncomment the following OPTION() directive and the reference
//   to the .reset section.
//   You may not want to do this if you are relying on preinstalled
//   firmware to initialize your system.
//
//     OPTION("-u __ghs_reset_handler")

SECTIONS
{	
    .rchw						: > flash_rsvd1
    
//
// RAM SECTIONS
//
    .PPC.EMB.sdata0 	            		    ABS : > dram_memory
    .PPC.EMB.sbss0                            CLEAR ABS : > .

    .boottext : {
	  // All .text which is reachable between
	  // _start and __ghs_ind_crt1 needs to be
	  // pulled into .boottext and left
	  // uncompressed.
	  crt0.o(.text, .vletext)
	  libstartup.a(*)(.text, .vletext)
	  libsys.a(ind_crt1.o)(.text, .vletext)
	  libboardinit.a(*)(.text, .vletext)
     }                                                    > dram_memory
    .syscall						: > .
    .text 			        	        : > dram_memory
    .vletext 			        	        : > .
   
    .sdabase 		       		       ALIGN(16): > .
    .sdata 						: > .
    .sbss 						: > .
    .data 						: > .
    .bss 						: > .
    .heap                  ALIGN(16) PAD(heap_reserve)  : > .   
    .stack                 ALIGN(16) PAD(stack_reserve) : > .

//
// ROM SECTIONS
//

    .ROM.boottext  	                 ROM(.boottext)	: > flash_memory
    .ROM.syscall 	          	 ROM(.syscall)	: > .
    
    .rodata 						: > flash_memory
    .sdata2 						: > .

    .secinfo 						: > .
    .fixaddr 						: > .
    .fixtype 						: > .

    .CROM.PPC.EMB.sdata0 	  CROM(.PPC.EMB.sdata0) : > .
    .CROM.sdata  	          	   CROM(.sdata)	: > .
    .CROM.data 	          		    CROM(.data) : > .
    .CROM.text  	      		    CROM(.text)	: > .
    .CROM.vletext  	      		 CROM(.vletext)	: > flash_memory

//
// These special symbols mark the bounds of RAM and ROM images of boot code.
// They are used by the GHS startup code (_start and __ghs_ind_crt0).
//
    __ghs_rambootcodestart  = ADDR(.boottext);
    __ghs_rambootcodeend    = ENDADDR(.stack);	
    __ghs_rombootcodestart  = ADDR(.ROM.boottext);
    __ghs_rombootcodeend    = ENDADDR(.fixtype);

//
// These special symbols mark the bounds of RAM and ROM memory.
// They are used by the MULTI debugger.
//
    __ghs_ramstart  = MEMADDR(dram_rsvd1);
    __ghs_ramend    = MEMENDADDR(dram_memory);
    __ghs_romstart  = MEMADDR(flash_rsvd1);
    __ghs_romend    = MEMENDADDR(flash_rsvd2);

//
// This special symbol marks the the first address executed after the
// ROM to RAM copy is complete.  It is used by the MULTI debugger.
//
    __ghs_after_romcopy = __ghs_ind_crt1;
}
