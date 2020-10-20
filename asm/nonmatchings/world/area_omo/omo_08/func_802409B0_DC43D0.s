.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802409B0_DC4D80
/* DC4D80 802409B0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* DC4D84 802409B4 AFB10024 */  sw        $s1, 0x24($sp)
/* DC4D88 802409B8 0080882D */  daddu     $s1, $a0, $zero
/* DC4D8C 802409BC AFBF0028 */  sw        $ra, 0x28($sp)
/* DC4D90 802409C0 AFB00020 */  sw        $s0, 0x20($sp)
/* DC4D94 802409C4 8E220148 */  lw        $v0, 0x148($s1)
/* DC4D98 802409C8 0C00EABB */  jal       get_npc_unsafe
/* DC4D9C 802409CC 84440008 */   lh       $a0, 8($v0)
/* DC4DA0 802409D0 0040802D */  daddu     $s0, $v0, $zero
/* DC4DA4 802409D4 0200202D */  daddu     $a0, $s0, $zero
/* DC4DA8 802409D8 C600000C */  lwc1      $f0, 0xc($s0)
/* DC4DAC 802409DC 27A60018 */  addiu     $a2, $sp, 0x18
/* DC4DB0 802409E0 E7A00018 */  swc1      $f0, 0x18($sp)
/* DC4DB4 802409E4 AFA00010 */  sw        $zero, 0x10($sp)
/* DC4DB8 802409E8 AFA00014 */  sw        $zero, 0x14($sp)
/* DC4DBC 802409EC 8E050018 */  lw        $a1, 0x18($s0)
/* DC4DC0 802409F0 0C0129E1 */  jal       func_8004A784
/* DC4DC4 802409F4 0000382D */   daddu    $a3, $zero, $zero
/* DC4DC8 802409F8 14400005 */  bnez      $v0, .L80240A10
/* DC4DCC 802409FC 00000000 */   nop      
/* DC4DD0 80240A00 8E050018 */  lw        $a1, 0x18($s0)
/* DC4DD4 80240A04 8E06000C */  lw        $a2, 0xc($s0)
/* DC4DD8 80240A08 0C00EA95 */  jal       npc_move_heading
/* DC4DDC 80240A0C 0200202D */   daddu    $a0, $s0, $zero
.L80240A10:
/* DC4DE0 80240A10 9602008E */  lhu       $v0, 0x8e($s0)
/* DC4DE4 80240A14 2442FFFF */  addiu     $v0, $v0, -1
/* DC4DE8 80240A18 A602008E */  sh        $v0, 0x8e($s0)
/* DC4DEC 80240A1C 00021400 */  sll       $v0, $v0, 0x10
/* DC4DF0 80240A20 14400004 */  bnez      $v0, .L80240A34
/* DC4DF4 80240A24 2402001E */   addiu    $v0, $zero, 0x1e
/* DC4DF8 80240A28 A602008E */  sh        $v0, 0x8e($s0)
/* DC4DFC 80240A2C 24020011 */  addiu     $v0, $zero, 0x11
/* DC4E00 80240A30 AE220070 */  sw        $v0, 0x70($s1)
.L80240A34:
/* DC4E04 80240A34 8FBF0028 */  lw        $ra, 0x28($sp)
/* DC4E08 80240A38 8FB10024 */  lw        $s1, 0x24($sp)
/* DC4E0C 80240A3C 8FB00020 */  lw        $s0, 0x20($sp)
/* DC4E10 80240A40 03E00008 */  jr        $ra
/* DC4E14 80240A44 27BD0030 */   addiu    $sp, $sp, 0x30
