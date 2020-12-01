.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242078_C48C58
/* C48C58 80242078 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C48C5C 8024207C AFB00010 */  sw        $s0, 0x10($sp)
/* C48C60 80242080 0080802D */  daddu     $s0, $a0, $zero
/* C48C64 80242084 AFBF0014 */  sw        $ra, 0x14($sp)
/* C48C68 80242088 8E020148 */  lw        $v0, 0x148($s0)
/* C48C6C 8024208C 0C00EABB */  jal       get_npc_unsafe
/* C48C70 80242090 84440008 */   lh       $a0, 8($v0)
/* C48C74 80242094 9443008E */  lhu       $v1, 0x8e($v0)
/* C48C78 80242098 C440003C */  lwc1      $f0, 0x3c($v0)
/* C48C7C 8024209C 24640001 */  addiu     $a0, $v1, 1
/* C48C80 802420A0 00031C00 */  sll       $v1, $v1, 0x10
/* C48C84 802420A4 00031B83 */  sra       $v1, $v1, 0xe
/* C48C88 802420A8 A444008E */  sh        $a0, 0x8e($v0)
/* C48C8C 802420AC 3C018024 */  lui       $at, %hi(D_80244358)
/* C48C90 802420B0 00230821 */  addu      $at, $at, $v1
/* C48C94 802420B4 C4224358 */  lwc1      $f2, %lo(D_80244358)($at)
/* C48C98 802420B8 8443008E */  lh        $v1, 0x8e($v0)
/* C48C9C 802420BC 46020000 */  add.s     $f0, $f0, $f2
/* C48CA0 802420C0 28630005 */  slti      $v1, $v1, 5
/* C48CA4 802420C4 14600003 */  bnez      $v1, .L802420D4
/* C48CA8 802420C8 E440003C */   swc1     $f0, 0x3c($v0)
/* C48CAC 802420CC 2402000C */  addiu     $v0, $zero, 0xc
/* C48CB0 802420D0 AE020070 */  sw        $v0, 0x70($s0)
.L802420D4:
/* C48CB4 802420D4 8FBF0014 */  lw        $ra, 0x14($sp)
/* C48CB8 802420D8 8FB00010 */  lw        $s0, 0x10($sp)
/* C48CBC 802420DC 03E00008 */  jr        $ra
/* C48CC0 802420E0 27BD0018 */   addiu    $sp, $sp, 0x18
