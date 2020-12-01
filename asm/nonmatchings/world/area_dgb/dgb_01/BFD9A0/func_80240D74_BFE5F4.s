.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D74_BFE5F4
/* BFE5F4 80240D74 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BFE5F8 80240D78 AFB00010 */  sw        $s0, 0x10($sp)
/* BFE5FC 80240D7C 0080802D */  daddu     $s0, $a0, $zero
/* BFE600 80240D80 AFBF0014 */  sw        $ra, 0x14($sp)
/* BFE604 80240D84 8E020148 */  lw        $v0, 0x148($s0)
/* BFE608 80240D88 0C00EABB */  jal       get_npc_unsafe
/* BFE60C 80240D8C 84440008 */   lh       $a0, 8($v0)
/* BFE610 80240D90 9443008E */  lhu       $v1, 0x8e($v0)
/* BFE614 80240D94 C440003C */  lwc1      $f0, 0x3c($v0)
/* BFE618 80240D98 24640001 */  addiu     $a0, $v1, 1
/* BFE61C 80240D9C 00031C00 */  sll       $v1, $v1, 0x10
/* BFE620 80240DA0 00031B83 */  sra       $v1, $v1, 0xe
/* BFE624 80240DA4 A444008E */  sh        $a0, 0x8e($v0)
/* BFE628 80240DA8 3C018024 */  lui       $at, %hi(D_80244CD0)
/* BFE62C 80240DAC 00230821 */  addu      $at, $at, $v1
/* BFE630 80240DB0 C4224CD0 */  lwc1      $f2, %lo(D_80244CD0)($at)
/* BFE634 80240DB4 8443008E */  lh        $v1, 0x8e($v0)
/* BFE638 80240DB8 46020000 */  add.s     $f0, $f0, $f2
/* BFE63C 80240DBC 28630005 */  slti      $v1, $v1, 5
/* BFE640 80240DC0 14600003 */  bnez      $v1, .L80240DD0
/* BFE644 80240DC4 E440003C */   swc1     $f0, 0x3c($v0)
/* BFE648 80240DC8 2402000C */  addiu     $v0, $zero, 0xc
/* BFE64C 80240DCC AE020070 */  sw        $v0, 0x70($s0)
.L80240DD0:
/* BFE650 80240DD0 8FBF0014 */  lw        $ra, 0x14($sp)
/* BFE654 80240DD4 8FB00010 */  lw        $s0, 0x10($sp)
/* BFE658 80240DD8 03E00008 */  jr        $ra
/* BFE65C 80240DDC 27BD0018 */   addiu    $sp, $sp, 0x18
