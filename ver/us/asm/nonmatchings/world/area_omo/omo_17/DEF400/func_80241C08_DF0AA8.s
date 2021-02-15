.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241C08_DF0AA8
/* DF0AA8 80241C08 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DF0AAC 80241C0C AFB00010 */  sw        $s0, 0x10($sp)
/* DF0AB0 80241C10 0080802D */  daddu     $s0, $a0, $zero
/* DF0AB4 80241C14 AFBF0014 */  sw        $ra, 0x14($sp)
/* DF0AB8 80241C18 8E020148 */  lw        $v0, 0x148($s0)
/* DF0ABC 80241C1C 0C00EABB */  jal       get_npc_unsafe
/* DF0AC0 80241C20 84440008 */   lh       $a0, 8($v0)
/* DF0AC4 80241C24 9443008E */  lhu       $v1, 0x8e($v0)
/* DF0AC8 80241C28 C440003C */  lwc1      $f0, 0x3c($v0)
/* DF0ACC 80241C2C 24640001 */  addiu     $a0, $v1, 1
/* DF0AD0 80241C30 00031C00 */  sll       $v1, $v1, 0x10
/* DF0AD4 80241C34 00031B83 */  sra       $v1, $v1, 0xe
/* DF0AD8 80241C38 A444008E */  sh        $a0, 0x8e($v0)
/* DF0ADC 80241C3C 3C018024 */  lui       $at, %hi(D_80246184_DF5024)
/* DF0AE0 80241C40 00230821 */  addu      $at, $at, $v1
/* DF0AE4 80241C44 C4226184 */  lwc1      $f2, %lo(D_80246184_DF5024)($at)
/* DF0AE8 80241C48 8443008E */  lh        $v1, 0x8e($v0)
/* DF0AEC 80241C4C 46020000 */  add.s     $f0, $f0, $f2
/* DF0AF0 80241C50 28630005 */  slti      $v1, $v1, 5
/* DF0AF4 80241C54 14600003 */  bnez      $v1, .L80241C64
/* DF0AF8 80241C58 E440003C */   swc1     $f0, 0x3c($v0)
/* DF0AFC 80241C5C 2402000C */  addiu     $v0, $zero, 0xc
/* DF0B00 80241C60 AE020070 */  sw        $v0, 0x70($s0)
.L80241C64:
/* DF0B04 80241C64 8FBF0014 */  lw        $ra, 0x14($sp)
/* DF0B08 80241C68 8FB00010 */  lw        $s0, 0x10($sp)
/* DF0B0C 80241C6C 03E00008 */  jr        $ra
/* DF0B10 80241C70 27BD0018 */   addiu    $sp, $sp, 0x18
