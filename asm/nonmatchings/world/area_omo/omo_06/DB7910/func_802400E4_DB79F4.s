.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400E4_DB79F4
/* DB79F4 802400E4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* DB79F8 802400E8 AFB10014 */  sw        $s1, 0x14($sp)
/* DB79FC 802400EC 0080882D */  daddu     $s1, $a0, $zero
/* DB7A00 802400F0 AFBF0018 */  sw        $ra, 0x18($sp)
/* DB7A04 802400F4 AFB00010 */  sw        $s0, 0x10($sp)
/* DB7A08 802400F8 F7B40020 */  sdc1      $f20, 0x20($sp)
/* DB7A0C 802400FC 8E30000C */  lw        $s0, 0xc($s1)
/* DB7A10 80240100 8E050000 */  lw        $a1, ($s0)
/* DB7A14 80240104 0C0B210B */  jal       get_float_variable
/* DB7A18 80240108 26100004 */   addiu    $s0, $s0, 4
/* DB7A1C 8024010C 8E050000 */  lw        $a1, ($s0)
/* DB7A20 80240110 26100004 */  addiu     $s0, $s0, 4
/* DB7A24 80240114 0220202D */  daddu     $a0, $s1, $zero
/* DB7A28 80240118 0C0B210B */  jal       get_float_variable
/* DB7A2C 8024011C 46000506 */   mov.s    $f20, $f0
/* DB7A30 80240120 4614003C */  c.lt.s    $f0, $f20
/* DB7A34 80240124 00000000 */  nop       
/* DB7A38 80240128 45000004 */  bc1f      .L8024013C
/* DB7A3C 8024012C 0220202D */   daddu    $a0, $s1, $zero
/* DB7A40 80240130 8E050000 */  lw        $a1, ($s0)
/* DB7A44 80240134 08090051 */  j         .L80240144
/* DB7A48 80240138 24060001 */   addiu    $a2, $zero, 1
.L8024013C:
/* DB7A4C 8024013C 8E050000 */  lw        $a1, ($s0)
/* DB7A50 80240140 0000302D */  daddu     $a2, $zero, $zero
.L80240144:
/* DB7A54 80240144 0C0B2026 */  jal       set_variable
/* DB7A58 80240148 00000000 */   nop      
/* DB7A5C 8024014C 8FBF0018 */  lw        $ra, 0x18($sp)
/* DB7A60 80240150 8FB10014 */  lw        $s1, 0x14($sp)
/* DB7A64 80240154 8FB00010 */  lw        $s0, 0x10($sp)
/* DB7A68 80240158 D7B40020 */  ldc1      $f20, 0x20($sp)
/* DB7A6C 8024015C 24020002 */  addiu     $v0, $zero, 2
/* DB7A70 80240160 03E00008 */  jr        $ra
/* DB7A74 80240164 27BD0028 */   addiu    $sp, $sp, 0x28
