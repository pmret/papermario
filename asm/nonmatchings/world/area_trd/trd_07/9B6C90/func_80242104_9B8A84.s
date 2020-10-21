.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242104_9B8A84
/* 9B8A84 80242104 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9B8A88 80242108 AFB20018 */  sw        $s2, 0x18($sp)
/* 9B8A8C 8024210C 0080902D */  daddu     $s2, $a0, $zero
/* 9B8A90 80242110 AFBF001C */  sw        $ra, 0x1c($sp)
/* 9B8A94 80242114 AFB10014 */  sw        $s1, 0x14($sp)
/* 9B8A98 80242118 AFB00010 */  sw        $s0, 0x10($sp)
/* 9B8A9C 8024211C 8E510148 */  lw        $s1, 0x148($s2)
/* 9B8AA0 80242120 0C00EABB */  jal       get_npc_unsafe
/* 9B8AA4 80242124 86240008 */   lh       $a0, 8($s1)
/* 9B8AA8 80242128 0040802D */  daddu     $s0, $v0, $zero
/* 9B8AAC 8024212C C602001C */  lwc1      $f2, 0x1c($s0)
/* 9B8AB0 80242130 C6000014 */  lwc1      $f0, 0x14($s0)
/* 9B8AB4 80242134 8E050018 */  lw        $a1, 0x18($s0)
/* 9B8AB8 80242138 46001080 */  add.s     $f2, $f2, $f0
/* 9B8ABC 8024213C C600003C */  lwc1      $f0, 0x3c($s0)
/* 9B8AC0 80242140 8E06000C */  lw        $a2, 0xc($s0)
/* 9B8AC4 80242144 46020000 */  add.s     $f0, $f0, $f2
/* 9B8AC8 80242148 0200202D */  daddu     $a0, $s0, $zero
/* 9B8ACC 8024214C E602001C */  swc1      $f2, 0x1c($s0)
/* 9B8AD0 80242150 0C00EA95 */  jal       npc_move_heading
/* 9B8AD4 80242154 E600003C */   swc1     $f0, 0x3c($s0)
/* 9B8AD8 80242158 9602008E */  lhu       $v0, 0x8e($s0)
/* 9B8ADC 8024215C 2442FFFF */  addiu     $v0, $v0, -1
/* 9B8AE0 80242160 A602008E */  sh        $v0, 0x8e($s0)
/* 9B8AE4 80242164 00021400 */  sll       $v0, $v0, 0x10
/* 9B8AE8 80242168 1C40000F */  bgtz      $v0, .L802421A8
/* 9B8AEC 8024216C 00000000 */   nop      
/* 9B8AF0 80242170 3C013E99 */  lui       $at, 0x3e99
/* 9B8AF4 80242174 3421999A */  ori       $at, $at, 0x999a
/* 9B8AF8 80242178 44810000 */  mtc1      $at, $f0
/* 9B8AFC 8024217C 3C014040 */  lui       $at, 0x4040
/* 9B8B00 80242180 44811000 */  mtc1      $at, $f2
/* 9B8B04 80242184 A2200007 */  sb        $zero, 7($s1)
/* 9B8B08 80242188 AE00001C */  sw        $zero, 0x1c($s0)
/* 9B8B0C 8024218C E6000014 */  swc1      $f0, 0x14($s0)
/* 9B8B10 80242190 E6020018 */  swc1      $f2, 0x18($s0)
/* 9B8B14 80242194 8E2200CC */  lw        $v0, 0xcc($s1)
/* 9B8B18 80242198 8C420028 */  lw        $v0, 0x28($v0)
/* 9B8B1C 8024219C AE020028 */  sw        $v0, 0x28($s0)
/* 9B8B20 802421A0 2402000E */  addiu     $v0, $zero, 0xe
/* 9B8B24 802421A4 AE420070 */  sw        $v0, 0x70($s2)
.L802421A8:
/* 9B8B28 802421A8 8FBF001C */  lw        $ra, 0x1c($sp)
/* 9B8B2C 802421AC 8FB20018 */  lw        $s2, 0x18($sp)
/* 9B8B30 802421B0 8FB10014 */  lw        $s1, 0x14($sp)
/* 9B8B34 802421B4 8FB00010 */  lw        $s0, 0x10($sp)
/* 9B8B38 802421B8 03E00008 */  jr        $ra
/* 9B8B3C 802421BC 27BD0020 */   addiu    $sp, $sp, 0x20
