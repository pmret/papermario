.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218588_6CC5F8
/* 6CC5F8 80218588 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 6CC5FC 8021858C AFB10014 */  sw        $s1, 0x14($sp)
/* 6CC600 80218590 0080882D */  daddu     $s1, $a0, $zero
/* 6CC604 80218594 AFBF0018 */  sw        $ra, 0x18($sp)
/* 6CC608 80218598 AFB00010 */  sw        $s0, 0x10($sp)
/* 6CC60C 8021859C 8E30000C */  lw        $s0, 0xc($s1)
/* 6CC610 802185A0 8E050000 */  lw        $a1, ($s0)
/* 6CC614 802185A4 0C0B1EAF */  jal       evt_get_variable
/* 6CC618 802185A8 26100004 */   addiu    $s0, $s0, 4
/* 6CC61C 802185AC 0040202D */  daddu     $a0, $v0, $zero
/* 6CC620 802185B0 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 6CC624 802185B4 14820002 */  bne       $a0, $v0, .L802185C0
/* 6CC628 802185B8 00000000 */   nop
/* 6CC62C 802185BC 8E240148 */  lw        $a0, 0x148($s1)
.L802185C0:
/* 6CC630 802185C0 0C09A75B */  jal       get_actor
/* 6CC634 802185C4 00000000 */   nop
/* 6CC638 802185C8 0040202D */  daddu     $a0, $v0, $zero
/* 6CC63C 802185CC 90830136 */  lbu       $v1, 0x136($a0)
/* 6CC640 802185D0 24020047 */  addiu     $v0, $zero, 0x47
/* 6CC644 802185D4 1062000B */  beq       $v1, $v0, .L80218604
/* 6CC648 802185D8 0062102A */   slt      $v0, $v1, $v0
/* 6CC64C 802185DC 54400011 */  bnel      $v0, $zero, .L80218624
/* 6CC650 802185E0 0220202D */   daddu    $a0, $s1, $zero
/* 6CC654 802185E4 28620065 */  slti      $v0, $v1, 0x65
/* 6CC658 802185E8 1040000D */  beqz      $v0, .L80218620
/* 6CC65C 802185EC 2862004D */   slti     $v0, $v1, 0x4d
/* 6CC660 802185F0 1440000C */  bnez      $v0, .L80218624
/* 6CC664 802185F4 0220202D */   daddu    $a0, $s1, $zero
/* 6CC668 802185F8 8E050000 */  lw        $a1, ($s0)
/* 6CC66C 802185FC 0808618B */  j         .L8021862C
/* 6CC670 80218600 2406FFFF */   addiu    $a2, $zero, -1
.L80218604:
/* 6CC674 80218604 8C8300A8 */  lw        $v1, 0xa8($a0)
/* 6CC678 80218608 24020001 */  addiu     $v0, $zero, 1
/* 6CC67C 8021860C 14620005 */  bne       $v1, $v0, .L80218624
/* 6CC680 80218610 0220202D */   daddu    $a0, $s1, $zero
/* 6CC684 80218614 8E050000 */  lw        $a1, ($s0)
/* 6CC688 80218618 0808618B */  j         .L8021862C
/* 6CC68C 8021861C 2406FFFF */   addiu    $a2, $zero, -1
.L80218620:
/* 6CC690 80218620 0220202D */  daddu     $a0, $s1, $zero
.L80218624:
/* 6CC694 80218624 8E050000 */  lw        $a1, ($s0)
/* 6CC698 80218628 0000302D */  daddu     $a2, $zero, $zero
.L8021862C:
/* 6CC69C 8021862C 0C0B2026 */  jal       evt_set_variable
/* 6CC6A0 80218630 00000000 */   nop
/* 6CC6A4 80218634 8FBF0018 */  lw        $ra, 0x18($sp)
/* 6CC6A8 80218638 8FB10014 */  lw        $s1, 0x14($sp)
/* 6CC6AC 8021863C 8FB00010 */  lw        $s0, 0x10($sp)
/* 6CC6B0 80218640 24020002 */  addiu     $v0, $zero, 2
/* 6CC6B4 80218644 03E00008 */  jr        $ra
/* 6CC6B8 80218648 27BD0020 */   addiu    $sp, $sp, 0x20
/* 6CC6BC 8021864C 00000000 */  nop
