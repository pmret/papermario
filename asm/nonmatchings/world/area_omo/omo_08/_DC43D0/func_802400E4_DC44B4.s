.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400E4_DC44B4
/* DC44B4 802400E4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* DC44B8 802400E8 AFB10014 */  sw        $s1, 0x14($sp)
/* DC44BC 802400EC 0080882D */  daddu     $s1, $a0, $zero
/* DC44C0 802400F0 AFBF0018 */  sw        $ra, 0x18($sp)
/* DC44C4 802400F4 AFB00010 */  sw        $s0, 0x10($sp)
/* DC44C8 802400F8 F7B40020 */  sdc1      $f20, 0x20($sp)
/* DC44CC 802400FC 8E30000C */  lw        $s0, 0xc($s1)
/* DC44D0 80240100 8E050000 */  lw        $a1, ($s0)
/* DC44D4 80240104 0C0B210B */  jal       get_float_variable
/* DC44D8 80240108 26100004 */   addiu    $s0, $s0, 4
/* DC44DC 8024010C 8E050000 */  lw        $a1, ($s0)
/* DC44E0 80240110 26100004 */  addiu     $s0, $s0, 4
/* DC44E4 80240114 0220202D */  daddu     $a0, $s1, $zero
/* DC44E8 80240118 0C0B210B */  jal       get_float_variable
/* DC44EC 8024011C 46000506 */   mov.s    $f20, $f0
/* DC44F0 80240120 4614003C */  c.lt.s    $f0, $f20
/* DC44F4 80240124 00000000 */  nop       
/* DC44F8 80240128 45000004 */  bc1f      .L8024013C
/* DC44FC 8024012C 0220202D */   daddu    $a0, $s1, $zero
/* DC4500 80240130 8E050000 */  lw        $a1, ($s0)
/* DC4504 80240134 08090051 */  j         .L80240144
/* DC4508 80240138 24060001 */   addiu    $a2, $zero, 1
.L8024013C:
/* DC450C 8024013C 8E050000 */  lw        $a1, ($s0)
/* DC4510 80240140 0000302D */  daddu     $a2, $zero, $zero
.L80240144:
/* DC4514 80240144 0C0B2026 */  jal       set_variable
/* DC4518 80240148 00000000 */   nop      
/* DC451C 8024014C 8FBF0018 */  lw        $ra, 0x18($sp)
/* DC4520 80240150 8FB10014 */  lw        $s1, 0x14($sp)
/* DC4524 80240154 8FB00010 */  lw        $s0, 0x10($sp)
/* DC4528 80240158 D7B40020 */  ldc1      $f20, 0x20($sp)
/* DC452C 8024015C 24020002 */  addiu     $v0, $zero, 2
/* DC4530 80240160 03E00008 */  jr        $ra
/* DC4534 80240164 27BD0028 */   addiu    $sp, $sp, 0x28
