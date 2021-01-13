.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240AB0_D9DF80
/* D9DF80 80240AB0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* D9DF84 80240AB4 AFB10024 */  sw        $s1, 0x24($sp)
/* D9DF88 80240AB8 0080882D */  daddu     $s1, $a0, $zero
/* D9DF8C 80240ABC AFBF0028 */  sw        $ra, 0x28($sp)
/* D9DF90 80240AC0 AFB00020 */  sw        $s0, 0x20($sp)
/* D9DF94 80240AC4 8E220148 */  lw        $v0, 0x148($s1)
/* D9DF98 80240AC8 0C00EABB */  jal       get_npc_unsafe
/* D9DF9C 80240ACC 84440008 */   lh       $a0, 8($v0)
/* D9DFA0 80240AD0 0040802D */  daddu     $s0, $v0, $zero
/* D9DFA4 80240AD4 0200202D */  daddu     $a0, $s0, $zero
/* D9DFA8 80240AD8 C600000C */  lwc1      $f0, 0xc($s0)
/* D9DFAC 80240ADC 27A60018 */  addiu     $a2, $sp, 0x18
/* D9DFB0 80240AE0 E7A00018 */  swc1      $f0, 0x18($sp)
/* D9DFB4 80240AE4 AFA00010 */  sw        $zero, 0x10($sp)
/* D9DFB8 80240AE8 AFA00014 */  sw        $zero, 0x14($sp)
/* D9DFBC 80240AEC 8E050018 */  lw        $a1, 0x18($s0)
/* D9DFC0 80240AF0 0C0129E1 */  jal       func_8004A784
/* D9DFC4 80240AF4 0000382D */   daddu    $a3, $zero, $zero
/* D9DFC8 80240AF8 14400005 */  bnez      $v0, .L80240B10
/* D9DFCC 80240AFC 00000000 */   nop
/* D9DFD0 80240B00 8E050018 */  lw        $a1, 0x18($s0)
/* D9DFD4 80240B04 8E06000C */  lw        $a2, 0xc($s0)
/* D9DFD8 80240B08 0C00EA95 */  jal       npc_move_heading
/* D9DFDC 80240B0C 0200202D */   daddu    $a0, $s0, $zero
.L80240B10:
/* D9DFE0 80240B10 9602008E */  lhu       $v0, 0x8e($s0)
/* D9DFE4 80240B14 2442FFFF */  addiu     $v0, $v0, -1
/* D9DFE8 80240B18 A602008E */  sh        $v0, 0x8e($s0)
/* D9DFEC 80240B1C 00021400 */  sll       $v0, $v0, 0x10
/* D9DFF0 80240B20 14400004 */  bnez      $v0, .L80240B34
/* D9DFF4 80240B24 2402001E */   addiu    $v0, $zero, 0x1e
/* D9DFF8 80240B28 A602008E */  sh        $v0, 0x8e($s0)
/* D9DFFC 80240B2C 24020011 */  addiu     $v0, $zero, 0x11
/* D9E000 80240B30 AE220070 */  sw        $v0, 0x70($s1)
.L80240B34:
/* D9E004 80240B34 8FBF0028 */  lw        $ra, 0x28($sp)
/* D9E008 80240B38 8FB10024 */  lw        $s1, 0x24($sp)
/* D9E00C 80240B3C 8FB00020 */  lw        $s0, 0x20($sp)
/* D9E010 80240B40 03E00008 */  jr        $ra
/* D9E014 80240B44 27BD0030 */   addiu    $sp, $sp, 0x30
