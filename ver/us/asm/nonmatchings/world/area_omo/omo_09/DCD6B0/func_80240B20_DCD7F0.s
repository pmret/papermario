.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B20_DCD7F0
/* DCD7F0 80240B20 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* DCD7F4 80240B24 AFB10024 */  sw        $s1, 0x24($sp)
/* DCD7F8 80240B28 0080882D */  daddu     $s1, $a0, $zero
/* DCD7FC 80240B2C AFBF0028 */  sw        $ra, 0x28($sp)
/* DCD800 80240B30 AFB00020 */  sw        $s0, 0x20($sp)
/* DCD804 80240B34 8E220148 */  lw        $v0, 0x148($s1)
/* DCD808 80240B38 0C00EABB */  jal       get_npc_unsafe
/* DCD80C 80240B3C 84440008 */   lh       $a0, 8($v0)
/* DCD810 80240B40 0040802D */  daddu     $s0, $v0, $zero
/* DCD814 80240B44 0200202D */  daddu     $a0, $s0, $zero
/* DCD818 80240B48 C600000C */  lwc1      $f0, 0xc($s0)
/* DCD81C 80240B4C 27A60018 */  addiu     $a2, $sp, 0x18
/* DCD820 80240B50 E7A00018 */  swc1      $f0, 0x18($sp)
/* DCD824 80240B54 AFA00010 */  sw        $zero, 0x10($sp)
/* DCD828 80240B58 AFA00014 */  sw        $zero, 0x14($sp)
/* DCD82C 80240B5C 8E050018 */  lw        $a1, 0x18($s0)
/* DCD830 80240B60 0C0129E1 */  jal       func_8004A784
/* DCD834 80240B64 0000382D */   daddu    $a3, $zero, $zero
/* DCD838 80240B68 14400005 */  bnez      $v0, .L80240B80
/* DCD83C 80240B6C 00000000 */   nop
/* DCD840 80240B70 8E050018 */  lw        $a1, 0x18($s0)
/* DCD844 80240B74 8E06000C */  lw        $a2, 0xc($s0)
/* DCD848 80240B78 0C00EA95 */  jal       npc_move_heading
/* DCD84C 80240B7C 0200202D */   daddu    $a0, $s0, $zero
.L80240B80:
/* DCD850 80240B80 9602008E */  lhu       $v0, 0x8e($s0)
/* DCD854 80240B84 2442FFFF */  addiu     $v0, $v0, -1
/* DCD858 80240B88 A602008E */  sh        $v0, 0x8e($s0)
/* DCD85C 80240B8C 00021400 */  sll       $v0, $v0, 0x10
/* DCD860 80240B90 14400004 */  bnez      $v0, .L80240BA4
/* DCD864 80240B94 2402001E */   addiu    $v0, $zero, 0x1e
/* DCD868 80240B98 A602008E */  sh        $v0, 0x8e($s0)
/* DCD86C 80240B9C 24020011 */  addiu     $v0, $zero, 0x11
/* DCD870 80240BA0 AE220070 */  sw        $v0, 0x70($s1)
.L80240BA4:
/* DCD874 80240BA4 8FBF0028 */  lw        $ra, 0x28($sp)
/* DCD878 80240BA8 8FB10024 */  lw        $s1, 0x24($sp)
/* DCD87C 80240BAC 8FB00020 */  lw        $s0, 0x20($sp)
/* DCD880 80240BB0 03E00008 */  jr        $ra
/* DCD884 80240BB4 27BD0030 */   addiu    $sp, $sp, 0x30
