.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241C44_A17E64
/* A17E64 80241C44 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A17E68 80241C48 AFB00010 */  sw        $s0, 0x10($sp)
/* A17E6C 80241C4C 0080802D */  daddu     $s0, $a0, $zero
/* A17E70 80241C50 AFBF0014 */  sw        $ra, 0x14($sp)
/* A17E74 80241C54 8E020148 */  lw        $v0, 0x148($s0)
/* A17E78 80241C58 0C00EABB */  jal       get_npc_unsafe
/* A17E7C 80241C5C 84440008 */   lh       $a0, 8($v0)
/* A17E80 80241C60 9443008E */  lhu       $v1, 0x8e($v0)
/* A17E84 80241C64 C440003C */  lwc1      $f0, 0x3c($v0)
/* A17E88 80241C68 24640001 */  addiu     $a0, $v1, 1
/* A17E8C 80241C6C 00031C00 */  sll       $v1, $v1, 0x10
/* A17E90 80241C70 00031B83 */  sra       $v1, $v1, 0xe
/* A17E94 80241C74 A444008E */  sh        $a0, 0x8e($v0)
/* A17E98 80241C78 3C018024 */  lui       $at, %hi(D_80244490_A1A6B0)
/* A17E9C 80241C7C 00230821 */  addu      $at, $at, $v1
/* A17EA0 80241C80 C4224490 */  lwc1      $f2, %lo(D_80244490_A1A6B0)($at)
/* A17EA4 80241C84 8443008E */  lh        $v1, 0x8e($v0)
/* A17EA8 80241C88 46020000 */  add.s     $f0, $f0, $f2
/* A17EAC 80241C8C 28630005 */  slti      $v1, $v1, 5
/* A17EB0 80241C90 14600003 */  bnez      $v1, .L80241CA0
/* A17EB4 80241C94 E440003C */   swc1     $f0, 0x3c($v0)
/* A17EB8 80241C98 2402000C */  addiu     $v0, $zero, 0xc
/* A17EBC 80241C9C AE020070 */  sw        $v0, 0x70($s0)
.L80241CA0:
/* A17EC0 80241CA0 8FBF0014 */  lw        $ra, 0x14($sp)
/* A17EC4 80241CA4 8FB00010 */  lw        $s0, 0x10($sp)
/* A17EC8 80241CA8 03E00008 */  jr        $ra
/* A17ECC 80241CAC 27BD0018 */   addiu    $sp, $sp, 0x18
