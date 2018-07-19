
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
// Program layout for starting in ROM, copying data to RAM, and continuing to
// execute out of ROM.  Some small debugging library functions are located in
// RAM to allow MULTI to set software breakpoints rather than hardware.
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

    // Allow small hook functions to execute out of RAM where
    // MULTI can set software breakpoints for debugging.
    .multibreak						: {
   	libind.a(indmultibreak.o)(.text, .vletext)
	libdbmem.a(indmultibreak.o)(.text, .vletext)
    	libind.a(indrnerr_wrap.o)(.text, .vletext)
	libdbmem.a(indrnerr_wrap.o)(.text, .vletext)
    }							  > .
    .syscall						: > .

//
// ROM SECTIONS
//

    .boottext : {
	crt0.o(.text, .vletext)
	libboardinit.a(*(.text, .vletext))
	}						  > flash_memory
    .text						: > flash_memory
    .vletext						: > .
    .ROM.syscall 		          ROM(.syscall)	: > .

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

//
// This special symbol marks the the first address executed after the
// ROM to RAM copy is complete.  It is used by the MULTI debugger.
//
    __ghs_after_romcopy = __ghs_ind_crt1;

//
// This symbol points to the ROM copy of __dotsyscall (which is in RAM).
// It overrides the weak symbol in startup code, which is called before RAM
// has been initialized.  This symbol is used by the MULTI debugger.
//
    __ghs_initial_dotsyscall = ADDR(.ROM.syscall);
}


// Redirect calls to __rnerr Runtime Error Checking function to a wrapper
// function located in RAM so we can set a software breakpoint on it. 
OPTION("-wrap __rnerr")

// Pull in alternate _multiend definitions to move into RAM for
// Command Line Procedure Calls.
OPTION("-u _multiend_ram")

