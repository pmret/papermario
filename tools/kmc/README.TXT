Some additional functions not shown in a manual are explained here.  

Additional option for 'mild'

	-E	If an undefined symbol is found when 'mild' calls a linker (ld) and linking is being
        	            processed,  'mild' continues the processing by default.  However,  if -E option is 
		specified, the processing stops when the undefined symbol is found.  

Shrinking function for debugging information

	If an environmental parameter GCC_CELF is set ON (set GCC_CELF=ON),  it will
           delete unnecessary debugging information (such as unused structure information in a file)
           and reduce the size of the debugging information.  Moreover,  by describing a header file
           etc a user uses in __elfcom.c file,  debugging information which is same as one defined
           in the file will not be output to each file,  and peculiar portion of each file alone will be
           output as debugging information.   By using this function,  an object size of each module
           will be reduced and therefore, time needed for compiling/linking will be considerably 
           reduced.   And,  since a memory used for linking is reduced a memory size needed for a
           host computer does not have to be large.  
   
           In ultra/gcc/mipse/debug directory,  a sample for using debugging function for
           N64 sample ultra/usr/pr/src/simple, is stored.  Please copy all the files in 
           ultra/gcc/mipse/debug to ultra/usr/pr/src/simple, and enter,

    		c:>envset
		c:>make

           and confirm the file shrinking function.

           In the event that to describe the common debugging information in __elfcom.c file is
           not necessary as it is optional,  there is no need to describe it.   However,  specifying of 
           'set GCC_CELF=ON' allows to reduce the size of debugging information considerably just      
           by re-compiling and without changing the present environment,  so be sure to specify it.  

How to use file shrinking function for debugging information
   
1.  Please specify an environmental parameter as 'set GCC_CELF=ON'.   Usually,  please add,

		set GCC_CELF=ON 
               
	      to ultra/setup.bat.  

2.  Please have all the objects depend upon __elfcom.tbl and __elfcom.elf  just like the
      last portion of 'makefile' in a game program directory.  As an example,  for N64
      sample ultra/usr/pr/src/simple,  please add the following at the end of 'makefile':

	$(CODEOBJECTS) $(DATAOBJECTS) : __elfcom.tbl __elfcom.elf

	__elfcom.tbl __elfcom.elf  : __elfcom.o
	     elftbl

3.  Please include or describe directly a header file which describes a structure etc in __elfcom.c file.  
    Debugging information like a structure information described in this
      __elfcom.c will be a common information for all the files to be compiled in the same 
      environment.  Debugging information which is same as the one defined in
      __elfcom.c will not be output to each file,  and peculiar portion of each file alone will 
      be output as debugging information.    For N64 sample ultra/usr/pr/src/simple, 
      please describe, 

	#include <ultra64.h>

      in __elfcom.c.

4.  It is not necessary for N64 sample ultra/usr/pr/src/simple,  however,  in case that 
      a  source code or an object code is stored in other place than a current directory,  it
      is necessary to specify a directory which has a common information table
      (__elfcom.tbl) file using an environmental parameter GCC_ELF_TBL,  if the file is to
      be compiled.  

set GCC_ELF_TBL=%ROOT%/usr/src/PR/simple
  
5.  The above concludes setting of an environmental parameter.   Please delete every
      object file (.o) once,  and redo the compiling.  And confirm that compiling ended
                   normally,  and the created file '.out file' has shrunk.

	Note:  When a file shrinking function is used,  Partner Ver 1.07 or newer ones should be
                       used.  Any older versions than this cannot read a file shrunk debugging
                       information correctly. 
