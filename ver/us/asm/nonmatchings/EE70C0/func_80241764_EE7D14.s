.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241764_EE7D14
/* EE7D14 80241764 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EE7D18 80241768 AFB00010 */  sw        $s0, 0x10($sp)
/* EE7D1C 8024176C 0080802D */  daddu     $s0, $a0, $zero
/* EE7D20 80241770 AFBF0014 */  sw        $ra, 0x14($sp)
/* EE7D24 80241774 8E020148 */  lw        $v0, 0x148($s0)
/* EE7D28 80241778 0C00F92F */  jal       dead_get_npc_unsafe
/* EE7D2C 8024177C 84440008 */   lh       $a0, 8($v0)
/* EE7D30 80241780 9443008E */  lhu       $v1, 0x8e($v0)
/* EE7D34 80241784 C440003C */  lwc1      $f0, 0x3c($v0)
/* EE7D38 80241788 24640001 */  addiu     $a0, $v1, 1
/* EE7D3C 8024178C 00031C00 */  sll       $v1, $v1, 0x10
/* EE7D40 80241790 00031B83 */  sra       $v1, $v1, 0xe
/* EE7D44 80241794 A444008E */  sh        $a0, 0x8e($v0)
/* EE7D48 80241798 3C018024 */  lui       $at, %hi(D_802444F0_EEAAA0)
/* EE7D4C 8024179C 00230821 */  addu      $at, $at, $v1
/* EE7D50 802417A0 C42244F0 */  lwc1      $f2, %lo(D_802444F0_EEAAA0)($at)
/* EE7D54 802417A4 8443008E */  lh        $v1, 0x8e($v0)
/* EE7D58 802417A8 46020000 */  add.s     $f0, $f0, $f2
/* EE7D5C 802417AC 28630005 */  slti      $v1, $v1, 5
/* EE7D60 802417B0 14600003 */  bnez      $v1, .L802417C0
/* EE7D64 802417B4 E440003C */   swc1     $f0, 0x3c($v0)
/* EE7D68 802417B8 2402000C */  addiu     $v0, $zero, 0xc
/* EE7D6C 802417BC AE020070 */  sw        $v0, 0x70($s0)
.L802417C0:
/* EE7D70 802417C0 8FBF0014 */  lw        $ra, 0x14($sp)
/* EE7D74 802417C4 8FB00010 */  lw        $s0, 0x10($sp)
/* EE7D78 802417C8 03E00008 */  jr        $ra
/* EE7D7C 802417CC 27BD0018 */   addiu    $sp, $sp, 0x18
