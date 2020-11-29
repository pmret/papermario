.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C54_8D2164
/* 8D2164 80240C54 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8D2168 80240C58 AFB00010 */  sw        $s0, 0x10($sp)
/* 8D216C 80240C5C 0080802D */  daddu     $s0, $a0, $zero
/* 8D2170 80240C60 AFBF0014 */  sw        $ra, 0x14($sp)
/* 8D2174 80240C64 8E020148 */  lw        $v0, 0x148($s0)
/* 8D2178 80240C68 0C00EABB */  jal       get_npc_unsafe
/* 8D217C 80240C6C 84440008 */   lh       $a0, 8($v0)
/* 8D2180 80240C70 9443008E */  lhu       $v1, 0x8e($v0)
/* 8D2184 80240C74 C440003C */  lwc1      $f0, 0x3c($v0)
/* 8D2188 80240C78 24640001 */  addiu     $a0, $v1, 1
/* 8D218C 80240C7C 00031C00 */  sll       $v1, $v1, 0x10
/* 8D2190 80240C80 00031B83 */  sra       $v1, $v1, 0xe
/* 8D2194 80240C84 A444008E */  sh        $a0, 0x8e($v0)
/* 8D2198 80240C88 3C018024 */  lui       $at, %hi(D_802420BC)
/* 8D219C 80240C8C 00230821 */  addu      $at, $at, $v1
/* 8D21A0 80240C90 C42220BC */  lwc1      $f2, %lo(D_802420BC)($at)
/* 8D21A4 80240C94 8443008E */  lh        $v1, 0x8e($v0)
/* 8D21A8 80240C98 46020000 */  add.s     $f0, $f0, $f2
/* 8D21AC 80240C9C 28630005 */  slti      $v1, $v1, 5
/* 8D21B0 80240CA0 14600003 */  bnez      $v1, .L80240CB0
/* 8D21B4 80240CA4 E440003C */   swc1     $f0, 0x3c($v0)
/* 8D21B8 80240CA8 2402000C */  addiu     $v0, $zero, 0xc
/* 8D21BC 80240CAC AE020070 */  sw        $v0, 0x70($s0)
.L80240CB0:
/* 8D21C0 80240CB0 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8D21C4 80240CB4 8FB00010 */  lw        $s0, 0x10($sp)
/* 8D21C8 80240CB8 03E00008 */  jr        $ra
/* 8D21CC 80240CBC 27BD0018 */   addiu    $sp, $sp, 0x18
