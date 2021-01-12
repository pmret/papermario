.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802408E0_DC4CB0
/* DC4CB0 802408E0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* DC4CB4 802408E4 AFB20028 */  sw        $s2, 0x28($sp)
/* DC4CB8 802408E8 0080902D */  daddu     $s2, $a0, $zero
/* DC4CBC 802408EC AFBF002C */  sw        $ra, 0x2c($sp)
/* DC4CC0 802408F0 AFB10024 */  sw        $s1, 0x24($sp)
/* DC4CC4 802408F4 AFB00020 */  sw        $s0, 0x20($sp)
/* DC4CC8 802408F8 8E510148 */  lw        $s1, 0x148($s2)
/* DC4CCC 802408FC 0C00EABB */  jal       get_npc_unsafe
/* DC4CD0 80240900 86240008 */   lh       $a0, 8($s1)
/* DC4CD4 80240904 0040802D */  daddu     $s0, $v0, $zero
/* DC4CD8 80240908 0200202D */  daddu     $a0, $s0, $zero
/* DC4CDC 8024090C C600000C */  lwc1      $f0, 0xc($s0)
/* DC4CE0 80240910 27A60018 */  addiu     $a2, $sp, 0x18
/* DC4CE4 80240914 E7A00018 */  swc1      $f0, 0x18($sp)
/* DC4CE8 80240918 AFA00010 */  sw        $zero, 0x10($sp)
/* DC4CEC 8024091C AFA00014 */  sw        $zero, 0x14($sp)
/* DC4CF0 80240920 8E050018 */  lw        $a1, 0x18($s0)
/* DC4CF4 80240924 0C0129E1 */  jal       func_8004A784
/* DC4CF8 80240928 0000382D */   daddu    $a3, $zero, $zero
/* DC4CFC 8024092C 14400005 */  bnez      $v0, .L80240944
/* DC4D00 80240930 00000000 */   nop
/* DC4D04 80240934 8E050018 */  lw        $a1, 0x18($s0)
/* DC4D08 80240938 8E06000C */  lw        $a2, 0xc($s0)
/* DC4D0C 8024093C 0C00EA95 */  jal       npc_move_heading
/* DC4D10 80240940 0200202D */   daddu    $a0, $s0, $zero
.L80240944:
/* DC4D14 80240944 9602008E */  lhu       $v0, 0x8e($s0)
/* DC4D18 80240948 2442FFFF */  addiu     $v0, $v0, -1
/* DC4D1C 8024094C A602008E */  sh        $v0, 0x8e($s0)
/* DC4D20 80240950 00021400 */  sll       $v0, $v0, 0x10
/* DC4D24 80240954 14400010 */  bnez      $v0, .L80240998
/* DC4D28 80240958 00000000 */   nop
/* DC4D2C 8024095C C6000018 */  lwc1      $f0, 0x18($s0)
/* DC4D30 80240960 3C018025 */  lui       $at, %hi(D_80248768)
/* DC4D34 80240964 D4228768 */  ldc1      $f2, %lo(D_80248768)($at)
/* DC4D38 80240968 46000021 */  cvt.d.s   $f0, $f0
/* DC4D3C 8024096C 46220002 */  mul.d     $f0, $f0, $f2
/* DC4D40 80240970 00000000 */  nop
/* DC4D44 80240974 46200020 */  cvt.s.d   $f0, $f0
/* DC4D48 80240978 E6000018 */  swc1      $f0, 0x18($s0)
/* DC4D4C 8024097C 8E2200CC */  lw        $v0, 0xcc($s1)
/* DC4D50 80240980 8C43002C */  lw        $v1, 0x2c($v0)
/* DC4D54 80240984 2402000A */  addiu     $v0, $zero, 0xa
/* DC4D58 80240988 A602008E */  sh        $v0, 0x8e($s0)
/* DC4D5C 8024098C 24020010 */  addiu     $v0, $zero, 0x10
/* DC4D60 80240990 AE030028 */  sw        $v1, 0x28($s0)
/* DC4D64 80240994 AE420070 */  sw        $v0, 0x70($s2)
.L80240998:
/* DC4D68 80240998 8FBF002C */  lw        $ra, 0x2c($sp)
/* DC4D6C 8024099C 8FB20028 */  lw        $s2, 0x28($sp)
/* DC4D70 802409A0 8FB10024 */  lw        $s1, 0x24($sp)
/* DC4D74 802409A4 8FB00020 */  lw        $s0, 0x20($sp)
/* DC4D78 802409A8 03E00008 */  jr        $ra
/* DC4D7C 802409AC 27BD0030 */   addiu    $sp, $sp, 0x30
