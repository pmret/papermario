	.file	1 "src/os/osEPiReadIo.c"

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

 #NO_APP
	.text
	.align	2
	.globl	osEPiReadIo
	.type	 osEPiReadIo,@function
	.ent	osEPiReadIo
osEPiReadIo:
	.frame	$sp,32,$31		# vars= 0, regs= 4/0, args= 16, extra= 0
	.mask	0x80070000,-4
	.fmask	0x00000000,0
	subu	$sp,$sp,32
	sw	$16,16($sp)
	move	$16,$4
	sw	$17,20($sp)
	move	$17,$5
	sw	$18,24($sp)
	sw	$31,28($sp)
	.set	noreorder
	.set	nomacro
	jal	osPiGetAccess
	move	$18,$6
	.set	macro
	.set	reorder

	move	$4,$16
	move	$5,$17
	.set	noreorder
	.set	nomacro
	jal	osEPiRawReadIo
	move	$6,$18
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	jal	osPiRelAccess
	move	$16,$2
	.set	macro
	.set	reorder

	move	$2,$16
	lw	$31,28($sp)
	lw	$18,24($sp)
	lw	$17,20($sp)
	lw	$16,16($sp)
	addu	$sp,$sp,32
	j	$31
	.end	osEPiReadIo
.Lfe1:
	.size	 osEPiReadIo,.Lfe1-osEPiReadIo
	.ident	"GCC: (GNU) 2.7.2"
