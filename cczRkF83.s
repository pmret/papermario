	.file	1 "src/os/guOrtho.c"

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
	.globl	guOrthoF
	.type	 guOrthoF,@function
	.ent	guOrthoF
guOrthoF:
	.frame	$sp,80,$31		# vars= 0, regs= 3/6, args= 16, extra= 0
	.mask	0x80030000,-56
	.fmask	0xfff00000,-4
	subu	$sp,$sp,80
	s.d	$f24,48($sp)
	l.s	$f24,96($sp)
	s.d	$f30,72($sp)
	l.s	$f30,100($sp)
	s.d	$f22,40($sp)
	l.s	$f22,104($sp)
	sw	$17,20($sp)
	lw	$17,108($sp)
	s.d	$f26,56($sp)
	mtc1	$5,$f26
	s.d	$f20,32($sp)
	mtc1	$6,$f20
	sw	$16,16($sp)
	s.d	$f28,64($sp)
	mtc1	$7,$f28
	sw	$31,24($sp)
	.set	noreorder
	.set	nomacro
	jal	guMtxIdentF
	move	$16,$4
	.set	macro
	.set	reorder

	sub.s	$f0,$f20,$f26
	li.s	$f2,2.00000000000000000000e0
	#nop
	div.s	$f10,$f2,$f0
	sub.s	$f6,$f24,$f28
	div.s	$f2,$f2,$f6
	sub.s	$f8,$f22,$f30
	li.s	$f4,-2.00000000000000000000e0
	#nop
	div.s	$f4,$f4,$f8
	add.s	$f20,$f20,$f26
	neg.s	$f20,$f20
	div.s	$f20,$f20,$f0
	add.s	$f24,$f24,$f28
	neg.s	$f24,$f24
	div.s	$f24,$f24,$f6
	add.s	$f22,$f22,$f30
	neg.s	$f22,$f22
	div.s	$f22,$f22,$f8
	li.s	$f0,1.00000000000000000000e0
	move	$5,$0
	s.s	$f0,60($16)
	s.s	$f10,0($16)
	s.s	$f20,48($16)
	s.s	$f2,20($16)
	s.s	$f4,40($16)
	s.s	$f24,52($16)
	s.s	$f22,56($16)
.L16:
	move	$4,$0
	move	$3,$16
.L20:
	l.s	$f0,0($3)
	mtc1	$17,$f12
	#nop
	mul.s	$f0,$f0,$f12
	addu	$4,$4,1
	slt	$2,$4,4
	s.s	$f0,0($3)
	.set	noreorder
	.set	nomacro
	bne	$2,$0,.L20
	addu	$3,$3,4
	.set	macro
	.set	reorder

	addu	$5,$5,1
	slt	$2,$5,4
	.set	noreorder
	.set	nomacro
	bne	$2,$0,.L16
	addu	$16,$16,16
	.set	macro
	.set	reorder

	lw	$31,24($sp)
	lw	$17,20($sp)
	lw	$16,16($sp)
	l.d	$f30,72($sp)
	l.d	$f28,64($sp)
	l.d	$f26,56($sp)
	l.d	$f24,48($sp)
	l.d	$f22,40($sp)
	l.d	$f20,32($sp)
	addu	$sp,$sp,80
	j	$31
	.end	guOrthoF
.Lfe1:
	.size	 guOrthoF,.Lfe1-guOrthoF
	.align	2
	.globl	guOrtho
	.type	 guOrtho,@function
	.ent	guOrtho
guOrtho:
	.frame	$sp,144,$31		# vars= 64, regs= 4/6, args= 16, extra= 0
	.mask	0x80070000,-52
	.fmask	0xfff00000,-4
	subu	$sp,$sp,144
	s.d	$f22,104($sp)
	l.s	$f22,160($sp)
	s.d	$f28,128($sp)
	l.s	$f28,164($sp)
	s.d	$f20,96($sp)
	l.s	$f20,168($sp)
	sw	$17,84($sp)
	lw	$17,172($sp)
	s.d	$f26,120($sp)
	mtc1	$5,$f26
	s.d	$f24,112($sp)
	mtc1	$6,$f24
	sw	$18,88($sp)
	move	$18,$4
	sw	$16,80($sp)
	addu	$16,$sp,16
	s.d	$f30,136($sp)
	mtc1	$7,$f30
	sw	$31,92($sp)
	.set	noreorder
	.set	nomacro
	jal	guMtxIdentF
	move	$4,$16
	.set	macro
	.set	reorder

	sub.s	$f0,$f24,$f26
	li.s	$f2,2.00000000000000000000e0
	#nop
	div.s	$f10,$f2,$f0
	sub.s	$f6,$f22,$f30
	div.s	$f2,$f2,$f6
	sub.s	$f8,$f20,$f28
	li.s	$f4,-2.00000000000000000000e0
	#nop
	div.s	$f4,$f4,$f8
	add.s	$f24,$f24,$f26
	neg.s	$f24,$f24
	div.s	$f24,$f24,$f0
	add.s	$f22,$f22,$f30
	neg.s	$f22,$f22
	div.s	$f22,$f22,$f6
	add.s	$f20,$f20,$f28
	neg.s	$f20,$f20
	div.s	$f20,$f20,$f8
	li.s	$f0,1.00000000000000000000e0
	move	$5,$0
	s.s	$f0,76($sp)
	s.s	$f10,16($sp)
	s.s	$f24,64($sp)
	s.s	$f2,36($sp)
	s.s	$f4,56($sp)
	s.s	$f22,68($sp)
	s.s	$f20,72($sp)
.L40:
	move	$4,$0
	move	$3,$16
.L44:
	l.s	$f0,0($3)
	mtc1	$17,$f12
	#nop
	mul.s	$f0,$f0,$f12
	addu	$4,$4,1
	slt	$2,$4,4
	s.s	$f0,0($3)
	.set	noreorder
	.set	nomacro
	bne	$2,$0,.L44
	addu	$3,$3,4
	.set	macro
	.set	reorder

	addu	$5,$5,1
	slt	$2,$5,4
	.set	noreorder
	.set	nomacro
	bne	$2,$0,.L40
	addu	$16,$16,16
	.set	macro
	.set	reorder

	addu	$4,$sp,16
	.set	noreorder
	.set	nomacro
	jal	guMtxF2L
	move	$5,$18
	.set	macro
	.set	reorder

	lw	$31,92($sp)
	lw	$18,88($sp)
	lw	$17,84($sp)
	lw	$16,80($sp)
	l.d	$f30,136($sp)
	l.d	$f28,128($sp)
	l.d	$f26,120($sp)
	l.d	$f24,112($sp)
	l.d	$f22,104($sp)
	l.d	$f20,96($sp)
	addu	$sp,$sp,144
	j	$31
	.end	guOrtho
.Lfe2:
	.size	 guOrtho,.Lfe2-guOrtho
	.ident	"GCC: (GNU) 2.7.2"
