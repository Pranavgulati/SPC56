
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
// Program layout for running out of RAM.
//
//

SECTIONS
{
    .PPC.EMB.sdata0 	            	    	    ABS : > dram_memory
    .PPC.EMB.sbss0                            CLEAR ABS : > .

    .text  			            		: > dram_memory
    .vletext 				    		: > .
    .syscall 				    		: > .
    .rchw				NOCHECKSUM	: > .
    .secinfo 				    		: > .
    .rodata 				    		: > .
    .sdata2 				    		: > .
    .fixaddr			 	   		: > .
    .fixtype						: > .

    .sdabase 		        	      ALIGN(16) : > dram_memory	
    .sdata 						: > .
    .sbss 						: > .
    .data 						: > .
    .bss 		  				: > .
    .heap                  ALIGN(16) PAD(heap_reserve)  : > .   
    .stack                 ALIGN(16) PAD(stack_reserve) : > .

//
// These special symbols mark the bounds of RAM and ROM memory.
// They are used by the MULTI debugger.
//
    __ghs_ramstart  = MEMADDR(dram_rsvd1);
    __ghs_ramend    = MEMENDADDR(dram_memory);
    __ghs_romstart  = MEMADDR(flash_rsvd1);
    __ghs_romend    = MEMENDADDR(flash_rsvd2);
    
}
