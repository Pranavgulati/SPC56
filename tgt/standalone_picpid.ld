DEFAULTS {
    stack_reserve = 8k
    heap_reserve = 16k
}
//
// Program layout for PIC and PID built programs.
//
//

SECTIONS
{

    .PPC.EMB.sdata0	                 0x1        ABS :
    .PPC.EMB.sbss0		              CLEAR ABS :

//
// The text segment
//
    .text                       	     0x00000000	:
    .vletext 						:
    .syscall 						:
    .secinfo 						:
    .rodata 						:
    .robase 						:
    .toc                                                :
    .sdata2 						:
    .opd                                                :
    .fixaddr 						:
    .fixtype 						:

//
// The data segment
//

    .sdata                       	     0x00000000 :
    .sbss 						:
    .data 						:
    .bss 						:
    .ghcovfz 					  CLEAR	:
    .ghcovcz 					  CLEAR	:
    .ghcovdz 					  CLEAR	:
    .heap                  ALIGN(16) PAD(heap_reserve)  :       
    .stack                 ALIGN(16) PAD(stack_reserve) :
}
