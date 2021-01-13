.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802408D0_A64960
/* A64960 802408D0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A64964 802408D4 AFB10014 */  sw        $s1, 0x14($sp)
/* A64968 802408D8 0080882D */  daddu     $s1, $a0, $zero
/* A6496C 802408DC AFBF0018 */  sw        $ra, 0x18($sp)
/* A64970 802408E0 AFB00010 */  sw        $s0, 0x10($sp)
/* A64974 802408E4 8E220148 */  lw        $v0, 0x148($s1)
/* A64978 802408E8 0C00EABB */  jal       get_npc_unsafe
/* A6497C 802408EC 84440008 */   lh       $a0, 8($v0)
/* A64980 802408F0 24040064 */  addiu     $a0, $zero, 0x64
/* A64984 802408F4 0C00A67F */  jal       rand_int
/* A64988 802408F8 0040802D */   daddu    $s0, $v0, $zero
/* A6498C 802408FC 00021FC2 */  srl       $v1, $v0, 0x1f
/* A64990 80240900 00431821 */  addu      $v1, $v0, $v1
/* A64994 80240904 00031843 */  sra       $v1, $v1, 1
/* A64998 80240908 00031840 */  sll       $v1, $v1, 1
/* A6499C 8024090C 00431023 */  subu      $v0, $v0, $v1
/* A649A0 80240910 3C014334 */  lui       $at, 0x4334
/* A649A4 80240914 44811000 */  mtc1      $at, $f2
/* A649A8 80240918 44820000 */  mtc1      $v0, $f0
/* A649AC 8024091C 00000000 */  nop
/* A649B0 80240920 46800020 */  cvt.s.w   $f0, $f0
/* A649B4 80240924 46020002 */  mul.s     $f0, $f0, $f2
/* A649B8 80240928 00000000 */  nop
/* A649BC 8024092C 3C013F4C */  lui       $at, 0x3f4c
/* A649C0 80240930 3421CCCD */  ori       $at, $at, 0xcccd
/* A649C4 80240934 44812000 */  mtc1      $at, $f4
/* A649C8 80240938 3C0142B4 */  lui       $at, 0x42b4
/* A649CC 8024093C 44811000 */  mtc1      $at, $f2
/* A649D0 80240940 2402000F */  addiu     $v0, $zero, 0xf
/* A649D4 80240944 A602008E */  sh        $v0, 0x8e($s0)
/* A649D8 80240948 46020000 */  add.s     $f0, $f0, $f2
/* A649DC 8024094C 24020006 */  addiu     $v0, $zero, 6
/* A649E0 80240950 E6040018 */  swc1      $f4, 0x18($s0)
/* A649E4 80240954 E600000C */  swc1      $f0, 0xc($s0)
/* A649E8 80240958 AE220070 */  sw        $v0, 0x70($s1)
/* A649EC 8024095C 8FBF0018 */  lw        $ra, 0x18($sp)
/* A649F0 80240960 8FB10014 */  lw        $s1, 0x14($sp)
/* A649F4 80240964 8FB00010 */  lw        $s0, 0x10($sp)
/* A649F8 80240968 03E00008 */  jr        $ra
/* A649FC 8024096C 27BD0020 */   addiu    $sp, $sp, 0x20
