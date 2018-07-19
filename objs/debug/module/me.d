objs\debug\module\me.o: src\me.c .\src\include\common.h .\src\include\types.h \
 .\src\include\typedefs.h C:\ghs\comp_201754\ansi\stdint.h \
 .\src\include\ports.h .\src\include\spc56ELX_0101.h .\src\include\me.h

:cmdList=ccppc -c  -MD -I'.\\src\\include' -G -Odebug -DPROCESSOR=CPU_SPC56EL -DCPU_SPC560B=0 -DCPU_SPC560P=1 -DCPU_SPC56EL=2 -gnu99 --slash_comment --gnu_asm -pic -AltiVec -vle_errata_010385 -pid -vle -convert_ppc_asm_to_vle --preprocess_linker_directive_full -preprocess_assembly_files -asm3g --assembler_warnings --ee -bsp spc564,564Lx -uvfd -object_dir=objs\debug\module -filetype.c src\me.c -o objs\debug\module\me.o ; 
:cmdHash=0x8f14ca3c

:installDir=c:\ghs\comp_201754
:installDirHash=0x9d4d864f

:config=DBG
