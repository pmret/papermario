	.file	1 "src/os/osEPiLinkHandle.c"

 # GNU C 2.7.2 [AL 1.1, MM 40] GNU MIPS/ELF compiled by GNU C

 # Cc1 defaults:
 # -mgas

 # Cc1 arguments (-G value = 0, Cpu = 4000, ISA = 3):
 # -mfp64 -mgp64 -G0 -quiet -dumpbase -mgp32 -mfp32 -mips3 -O3 -Wuninitialized
 # -Wmissing-braces -Wimplicit -Wredundant-decls -Wstrict-prototypes -o

	.version	"01.01"
gcc2_compiled.:
 #APP
	.include "include/macro.inc"

	.include "include/macro.inc"

 #NO_APP
	.text
	.align	2
	.globl	osEPiLinkHandle
	.type	 osEPiLinkHandle,@function
	.ent	osEPiLinkHandle
osEPiLinkHandle:
	.frame	$sp,24,$31		# vars= 0, regs= 2/0, args= 16, extra= 0
	.mask	0x80010000,-4
	.fmask	0x00000000,0
	subu	$sp,$sp,24
	sw	$16,16($sp)
	sw	$31,20($sp)
	.set	noreorder
	.set	nomacro
	jal	__osDisableInt
	move	$16,$4
	.set	macro
	.set	reorder

	lw	$3,__osPiTable
	move	$4,$2
	sw	$16,__osPiTable
	.set	noreorder
	.set	nomacro
	jal	__osRestoreInt
	sw	$3,0($16)
	.set	macro
	.set	reorder

	move	$2,$0
	lw	$31,20($sp)
	lw	$16,16($sp)
	addu	$sp,$sp,24
	j	$31
	.end	osEPiLinkHandle
.Lfe1:
	.size	 osEPiLinkHandle,.Lfe1-osEPiLinkHandle
	.ident	"GCC: (GNU) 2.7.2"
