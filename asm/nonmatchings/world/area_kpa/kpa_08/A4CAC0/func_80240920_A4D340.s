.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240920_A4D340
/* A4D340 80240920 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A4D344 80240924 AFB10014 */  sw        $s1, 0x14($sp)
/* A4D348 80240928 0080882D */  daddu     $s1, $a0, $zero
/* A4D34C 8024092C AFBF0018 */  sw        $ra, 0x18($sp)
/* A4D350 80240930 AFB00010 */  sw        $s0, 0x10($sp)
/* A4D354 80240934 8E220148 */  lw        $v0, 0x148($s1)
/* A4D358 80240938 0C00EABB */  jal       get_npc_unsafe
/* A4D35C 8024093C 84440008 */   lh       $a0, 8($v0)
/* A4D360 80240940 24040064 */  addiu     $a0, $zero, 0x64
/* A4D364 80240944 0C00A67F */  jal       rand_int
/* A4D368 80240948 0040802D */   daddu    $s0, $v0, $zero
/* A4D36C 8024094C 00021FC2 */  srl       $v1, $v0, 0x1f
/* A4D370 80240950 00431821 */  addu      $v1, $v0, $v1
/* A4D374 80240954 00031843 */  sra       $v1, $v1, 1
/* A4D378 80240958 00031840 */  sll       $v1, $v1, 1
/* A4D37C 8024095C 00431023 */  subu      $v0, $v0, $v1
/* A4D380 80240960 3C014334 */  lui       $at, 0x4334
/* A4D384 80240964 44811000 */  mtc1      $at, $f2
/* A4D388 80240968 44820000 */  mtc1      $v0, $f0
/* A4D38C 8024096C 00000000 */  nop       
/* A4D390 80240970 46800020 */  cvt.s.w   $f0, $f0
/* A4D394 80240974 46020002 */  mul.s     $f0, $f0, $f2
/* A4D398 80240978 00000000 */  nop       
/* A4D39C 8024097C 3C013F4C */  lui       $at, 0x3f4c
/* A4D3A0 80240980 3421CCCD */  ori       $at, $at, 0xcccd
/* A4D3A4 80240984 44812000 */  mtc1      $at, $f4
/* A4D3A8 80240988 3C0142B4 */  lui       $at, 0x42b4
/* A4D3AC 8024098C 44811000 */  mtc1      $at, $f2
/* A4D3B0 80240990 2402000F */  addiu     $v0, $zero, 0xf
/* A4D3B4 80240994 A602008E */  sh        $v0, 0x8e($s0)
/* A4D3B8 80240998 46020000 */  add.s     $f0, $f0, $f2
/* A4D3BC 8024099C 24020006 */  addiu     $v0, $zero, 6
/* A4D3C0 802409A0 E6040018 */  swc1      $f4, 0x18($s0)
/* A4D3C4 802409A4 E600000C */  swc1      $f0, 0xc($s0)
/* A4D3C8 802409A8 AE220070 */  sw        $v0, 0x70($s1)
/* A4D3CC 802409AC 8FBF0018 */  lw        $ra, 0x18($sp)
/* A4D3D0 802409B0 8FB10014 */  lw        $s1, 0x14($sp)
/* A4D3D4 802409B4 8FB00010 */  lw        $s0, 0x10($sp)
/* A4D3D8 802409B8 03E00008 */  jr        $ra
/* A4D3DC 802409BC 27BD0020 */   addiu    $sp, $sp, 0x20
