.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400E4_DEBFB4
/* DEBFB4 802400E4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* DEBFB8 802400E8 AFB10014 */  sw        $s1, 0x14($sp)
/* DEBFBC 802400EC 0080882D */  daddu     $s1, $a0, $zero
/* DEBFC0 802400F0 AFBF0018 */  sw        $ra, 0x18($sp)
/* DEBFC4 802400F4 AFB00010 */  sw        $s0, 0x10($sp)
/* DEBFC8 802400F8 F7B40020 */  sdc1      $f20, 0x20($sp)
/* DEBFCC 802400FC 8E30000C */  lw        $s0, 0xc($s1)
/* DEBFD0 80240100 8E050000 */  lw        $a1, ($s0)
/* DEBFD4 80240104 0C0B210B */  jal       get_float_variable
/* DEBFD8 80240108 26100004 */   addiu    $s0, $s0, 4
/* DEBFDC 8024010C 8E050000 */  lw        $a1, ($s0)
/* DEBFE0 80240110 26100004 */  addiu     $s0, $s0, 4
/* DEBFE4 80240114 0220202D */  daddu     $a0, $s1, $zero
/* DEBFE8 80240118 0C0B210B */  jal       get_float_variable
/* DEBFEC 8024011C 46000506 */   mov.s    $f20, $f0
/* DEBFF0 80240120 4614003C */  c.lt.s    $f0, $f20
/* DEBFF4 80240124 00000000 */  nop       
/* DEBFF8 80240128 45000004 */  bc1f      .L8024013C
/* DEBFFC 8024012C 0220202D */   daddu    $a0, $s1, $zero
/* DEC000 80240130 8E050000 */  lw        $a1, ($s0)
/* DEC004 80240134 08090051 */  j         .L80240144
/* DEC008 80240138 24060001 */   addiu    $a2, $zero, 1
.L8024013C:
/* DEC00C 8024013C 8E050000 */  lw        $a1, ($s0)
/* DEC010 80240140 0000302D */  daddu     $a2, $zero, $zero
.L80240144:
/* DEC014 80240144 0C0B2026 */  jal       set_variable
/* DEC018 80240148 00000000 */   nop      
/* DEC01C 8024014C 8FBF0018 */  lw        $ra, 0x18($sp)
/* DEC020 80240150 8FB10014 */  lw        $s1, 0x14($sp)
/* DEC024 80240154 8FB00010 */  lw        $s0, 0x10($sp)
/* DEC028 80240158 D7B40020 */  ldc1      $f20, 0x20($sp)
/* DEC02C 8024015C 24020002 */  addiu     $v0, $zero, 2
/* DEC030 80240160 03E00008 */  jr        $ra
/* DEC034 80240164 27BD0028 */   addiu    $sp, $sp, 0x28
