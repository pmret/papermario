	.file	1 "src/os/guRotate.c"

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
	.data
	.align	2
	.type	 dtor.2,@object
	.size	 dtor.2,4
dtor.2:
	.word	0x3c8efa33		# 0.0174532886595 (float)
	.text
	.align	2
	.globl	guRotateF
	.type	 guRotateF,@function
	.ent	guRotateF
guRotateF:
	.frame	$sp,72,$31		# vars= 0, regs= 2/6, args= 16, extra= 0
	.mask	0x80010000,-52
	.fmask	0xfff00000,-4
	subu	$sp,$sp,72
	sw	$16,16($sp)
	move	$16,$4
	addu	$4,$sp,80
	s.d	$f20,24($sp)
	mtc1	$5,$f20
	addu	$5,$sp,84
	sw	$6,80($sp)
	addu	$6,$sp,88
	sw	$31,20($sp)
	s.d	$f30,64($sp)
	s.d	$f28,56($sp)
	s.d	$f26,48($sp)
	s.d	$f24,40($sp)
	s.d	$f22,32($sp)
	.set	noreorder
	.set	nomacro
	jal	guNormalize
	sw	$7,84($sp)
	.set	macro
	.set	reorder

	l.s	$f0,D_800958C0
	#nop
	mul.s	$f20,$f20,$f0
	.set	noreorder
	.set	nomacro
	jal	sin_rad
	mov.s	$f12,$f20
	.set	macro
	.set	reorder

	mov.s	$f12,$f20
	.set	noreorder
	.set	nomacro
	jal	cos_rad
	mov.s	$f30,$f0
	.set	macro
	.set	reorder

	l.s	$f2,80($sp)
	l.s	$f22,84($sp)
	#nop
	mul.s	$f28,$f2,$f22
	l.s	$f20,88($sp)
	#nop
	mul.s	$f22,$f22,$f20
	li.s	$f26,1.00000000000000000000e0
	mul.s	$f20,$f20,$f2
	mov.s	$f24,$f0
	sub.s	$f12,$f26,$f24
	mul.s	$f28,$f28,$f12
	mul.s	$f22,$f22,$f12
	mul.s	$f20,$f20,$f12
	.set	noreorder
	.set	nomacro
	jal	guMtxIdentF
	move	$4,$16
	.set	macro
	.set	reorder

	l.s	$f2,80($sp)
	#nop
	mul.s	$f12,$f2,$f2
	sub.s	$f0,$f26,$f12
	mul.s	$f0,$f24,$f0
	l.s	$f4,84($sp)
	l.s	$f8,88($sp)
	add.s	$f0,$f12,$f0
	mul.s	$f4,$f4,$f30
	s.s	$f0,0($16)
	l.s	$f0,84($sp)
	#nop
	mul.s	$f12,$f0,$f0
	mul.s	$f2,$f2,$f30
	sub.s	$f6,$f26,$f12
	add.s	$f0,$f20,$f4
	mul.s	$f6,$f24,$f6
	sub.s	$f10,$f22,$f2
	s.s	$f0,32($16)
	l.s	$f0,88($sp)
	add.s	$f6,$f12,$f6
	mul.s	$f12,$f0,$f0
	add.s	$f22,$f22,$f2
	sub.s	$f20,$f20,$f4
	mul.s	$f8,$f8,$f30
	sub.s	$f26,$f26,$f12
	sub.s	$f0,$f28,$f8
	mul.s	$f24,$f24,$f26
	add.s	$f28,$f28,$f8
	s.s	$f10,36($16)
	s.s	$f22,24($16)
	s.s	$f20,8($16)
	add.s	$f24,$f12,$f24
	s.s	$f28,4($16)
	s.s	$f0,16($16)
	s.s	$f6,20($16)
	s.s	$f24,40($16)
	lw	$31,20($sp)
	lw	$16,16($sp)
	l.d	$f30,64($sp)
	l.d	$f28,56($sp)
	l.d	$f26,48($sp)
	l.d	$f24,40($sp)
	l.d	$f22,32($sp)
	l.d	$f20,24($sp)
	addu	$sp,$sp,72
	j	$31
	.end	guRotateF
.Lfe1:
	.size	 guRotateF,.Lfe1-guRotateF
	.align	2
	.globl	guRotate
	.type	 guRotate,@function
	.ent	guRotate
guRotate:
	.frame	$sp,168,$31		# vars= 88, regs= 3/6, args= 16, extra= 0
	.mask	0x80030000,-56
	.fmask	0xfff00000,-4
	subu	$sp,$sp,168
	l.s	$f0,184($sp)
	sw	$17,108($sp)
	move	$17,$4
	addu	$4,$sp,88
	s.d	$f20,120($sp)
	mtc1	$5,$f20
	addu	$5,$sp,92
	sw	$6,88($sp)
	addu	$6,$sp,96
	sw	$31,112($sp)
	sw	$16,104($sp)
	s.d	$f30,160($sp)
	s.d	$f28,152($sp)
	s.d	$f26,144($sp)
	s.d	$f24,136($sp)
	s.d	$f22,128($sp)
	sw	$7,92($sp)
	.set	noreorder
	.set	nomacro
	jal	guNormalize
	s.s	$f0,96($sp)
	.set	macro
	.set	reorder

	l.s	$f0,D_800958C0
	#nop
	mul.s	$f20,$f20,$f0
	.set	noreorder
	.set	nomacro
	jal	sin_rad
	mov.s	$f12,$f20
	.set	macro
	.set	reorder

	mov.s	$f12,$f20
	.set	noreorder
	.set	nomacro
	jal	cos_rad
	mov.s	$f30,$f0
	.set	macro
	.set	reorder

	l.s	$f2,88($sp)
	l.s	$f22,92($sp)
	#nop
	mul.s	$f28,$f2,$f22
	l.s	$f20,96($sp)
	#nop
	mul.s	$f22,$f22,$f20
	li.s	$f26,1.00000000000000000000e0
	mul.s	$f20,$f20,$f2
	mov.s	$f24,$f0
	sub.s	$f12,$f26,$f24
	mul.s	$f28,$f28,$f12
	mul.s	$f22,$f22,$f12
	mul.s	$f20,$f20,$f12
	addu	$16,$sp,16
	.set	noreorder
	.set	nomacro
	jal	guMtxIdentF
	move	$4,$16
	.set	macro
	.set	reorder

	l.s	$f0,88($sp)
	#nop
	mul.s	$f12,$f0,$f0
	sub.s	$f6,$f26,$f12
	mul.s	$f6,$f24,$f6
	l.s	$f2,92($sp)
	add.s	$f6,$f12,$f6
	mul.s	$f12,$f2,$f2
	mul.s	$f0,$f0,$f30
	sub.s	$f4,$f26,$f12
	mul.s	$f4,$f24,$f4
	sub.s	$f10,$f22,$f0
	mul.s	$f2,$f2,$f30
	add.s	$f22,$f22,$f0
	l.s	$f0,96($sp)
	add.s	$f4,$f12,$f4
	mul.s	$f12,$f0,$f0
	add.s	$f8,$f20,$f2
	sub.s	$f20,$f20,$f2
	mul.s	$f0,$f0,$f30
	sub.s	$f26,$f26,$f12
	move	$4,$16
	move	$5,$17
	sub.s	$f2,$f28,$f0
	mul.s	$f24,$f24,$f26
	s.s	$f10,52($sp)
	s.s	$f22,40($sp)
	add.s	$f28,$f28,$f0
	s.s	$f6,16($sp)
	s.s	$f8,48($sp)
	s.s	$f20,24($sp)
	add.s	$f24,$f12,$f24
	s.s	$f4,36($sp)
	s.s	$f2,32($sp)
	s.s	$f28,20($sp)
	.set	noreorder
	.set	nomacro
	jal	guMtxF2L
	s.s	$f24,56($sp)
	.set	macro
	.set	reorder

	lw	$31,112($sp)
	lw	$17,108($sp)
	lw	$16,104($sp)
	l.d	$f30,160($sp)
	l.d	$f28,152($sp)
	l.d	$f26,144($sp)
	l.d	$f24,136($sp)
	l.d	$f22,128($sp)
	l.d	$f20,120($sp)
	addu	$sp,$sp,168
	j	$31
	.end	guRotate
.Lfe2:
	.size	 guRotate,.Lfe2-guRotate
	.ident	"GCC: (GNU) 2.7.2"
