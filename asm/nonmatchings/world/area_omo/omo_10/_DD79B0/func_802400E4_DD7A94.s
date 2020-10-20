.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400E4_DD7A94
/* DD7A94 802400E4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* DD7A98 802400E8 AFB10014 */  sw        $s1, 0x14($sp)
/* DD7A9C 802400EC 0080882D */  daddu     $s1, $a0, $zero
/* DD7AA0 802400F0 AFBF0018 */  sw        $ra, 0x18($sp)
/* DD7AA4 802400F4 AFB00010 */  sw        $s0, 0x10($sp)
/* DD7AA8 802400F8 F7B40020 */  sdc1      $f20, 0x20($sp)
/* DD7AAC 802400FC 8E30000C */  lw        $s0, 0xc($s1)
/* DD7AB0 80240100 8E050000 */  lw        $a1, ($s0)
/* DD7AB4 80240104 0C0B210B */  jal       get_float_variable
/* DD7AB8 80240108 26100004 */   addiu    $s0, $s0, 4
/* DD7ABC 8024010C 8E050000 */  lw        $a1, ($s0)
/* DD7AC0 80240110 26100004 */  addiu     $s0, $s0, 4
/* DD7AC4 80240114 0220202D */  daddu     $a0, $s1, $zero
/* DD7AC8 80240118 0C0B210B */  jal       get_float_variable
/* DD7ACC 8024011C 46000506 */   mov.s    $f20, $f0
/* DD7AD0 80240120 4614003C */  c.lt.s    $f0, $f20
/* DD7AD4 80240124 00000000 */  nop       
/* DD7AD8 80240128 45000004 */  bc1f      .L8024013C
/* DD7ADC 8024012C 0220202D */   daddu    $a0, $s1, $zero
/* DD7AE0 80240130 8E050000 */  lw        $a1, ($s0)
/* DD7AE4 80240134 08090051 */  j         .L80240144
/* DD7AE8 80240138 24060001 */   addiu    $a2, $zero, 1
.L8024013C:
/* DD7AEC 8024013C 8E050000 */  lw        $a1, ($s0)
/* DD7AF0 80240140 0000302D */  daddu     $a2, $zero, $zero
.L80240144:
/* DD7AF4 80240144 0C0B2026 */  jal       set_variable
/* DD7AF8 80240148 00000000 */   nop      
/* DD7AFC 8024014C 8FBF0018 */  lw        $ra, 0x18($sp)
/* DD7B00 80240150 8FB10014 */  lw        $s1, 0x14($sp)
/* DD7B04 80240154 8FB00010 */  lw        $s0, 0x10($sp)
/* DD7B08 80240158 D7B40020 */  ldc1      $f20, 0x20($sp)
/* DD7B0C 8024015C 24020002 */  addiu     $v0, $zero, 2
/* DD7B10 80240160 03E00008 */  jr        $ra
/* DD7B14 80240164 27BD0028 */   addiu    $sp, $sp, 0x28
