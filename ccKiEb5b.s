	.file	1 "src/os/osEPiStartDma.c"

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
	.globl	osEPiStartDma
	.type	 osEPiStartDma,@function
	.ent	osEPiStartDma
osEPiStartDma:
	.frame	$sp,24,$31		# vars= 0, regs= 2/0, args= 16, extra= 0
	.mask	0x80010000,-4
	.fmask	0x00000000,0
	lw	$2,__osPiDevMgr
	subu	$sp,$sp,24
	sw	$16,16($sp)
	move	$16,$5
	.set	noreorder
	.set	nomacro
	bne	$2,$0,.L8
	sw	$31,20($sp)
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	j	.L13
	li	$2,-1			# 0xffffffff
	.set	macro
	.set	reorder

.L8:
	.set	noreorder
	.set	nomacro
	bne	$6,$0,.L9
	sw	$4,20($16)
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	j	.L14
	li	$2,0x0000000f		# 15
	.set	macro
	.set	reorder

.L9:
	li	$2,0x00000010		# 16
.L14:
	sh	$2,0($16)
	lbu	$3,2($16)
	li	$2,0x00000001		# 1
	bne	$3,$2,.L11
	jal	osPiGetCmdQueue
	move	$4,$2
	move	$5,$16
	.set	noreorder
	.set	nomacro
	jal	osJamMesg
	move	$6,$0
	.set	macro
	.set	reorder

	j	.L13
.L11:
	jal	osPiGetCmdQueue
	move	$4,$2
	move	$5,$16
	.set	noreorder
	.set	nomacro
	jal	osSendMesg
	move	$6,$0
	.set	macro
	.set	reorder

.L13:
	lw	$31,20($sp)
	lw	$16,16($sp)
	addu	$sp,$sp,24
	j	$31
	.end	osEPiStartDma
.Lfe1:
	.size	 osEPiStartDma,.Lfe1-osEPiStartDma
	.ident	"GCC: (GNU) 2.7.2"
