.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C54_8CECC4
/* 8CECC4 80240C54 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8CECC8 80240C58 AFB00010 */  sw        $s0, 0x10($sp)
/* 8CECCC 80240C5C 0080802D */  daddu     $s0, $a0, $zero
/* 8CECD0 80240C60 AFBF0014 */  sw        $ra, 0x14($sp)
/* 8CECD4 80240C64 8E020148 */  lw        $v0, 0x148($s0)
/* 8CECD8 80240C68 0C00EABB */  jal       get_npc_unsafe
/* 8CECDC 80240C6C 84440008 */   lh       $a0, 8($v0)
/* 8CECE0 80240C70 9443008E */  lhu       $v1, 0x8e($v0)
/* 8CECE4 80240C74 C440003C */  lwc1      $f0, 0x3c($v0)
/* 8CECE8 80240C78 24640001 */  addiu     $a0, $v1, 1
/* 8CECEC 80240C7C 00031C00 */  sll       $v1, $v1, 0x10
/* 8CECF0 80240C80 00031B83 */  sra       $v1, $v1, 0xe
/* 8CECF4 80240C84 A444008E */  sh        $a0, 0x8e($v0)
/* 8CECF8 80240C88 3C018024 */  lui       $at, 0x8024
/* 8CECFC 80240C8C 00230821 */  addu      $at, $at, $v1
/* 8CED00 80240C90 C4221B2C */  lwc1      $f2, 0x1b2c($at)
/* 8CED04 80240C94 8443008E */  lh        $v1, 0x8e($v0)
/* 8CED08 80240C98 46020000 */  add.s     $f0, $f0, $f2
/* 8CED0C 80240C9C 28630005 */  slti      $v1, $v1, 5
/* 8CED10 80240CA0 14600003 */  bnez      $v1, .L80240CB0
/* 8CED14 80240CA4 E440003C */   swc1     $f0, 0x3c($v0)
/* 8CED18 80240CA8 2402000C */  addiu     $v0, $zero, 0xc
/* 8CED1C 80240CAC AE020070 */  sw        $v0, 0x70($s0)
.L80240CB0:
/* 8CED20 80240CB0 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8CED24 80240CB4 8FB00010 */  lw        $s0, 0x10($sp)
/* 8CED28 80240CB8 03E00008 */  jr        $ra
/* 8CED2C 80240CBC 27BD0018 */   addiu    $sp, $sp, 0x18
