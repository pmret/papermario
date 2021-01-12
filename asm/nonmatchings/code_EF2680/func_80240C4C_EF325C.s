.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C4C_EF325C
/* EF325C 80240C4C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EF3260 80240C50 AFB20018 */  sw        $s2, 0x18($sp)
/* EF3264 80240C54 0080902D */  daddu     $s2, $a0, $zero
/* EF3268 80240C58 AFBF001C */  sw        $ra, 0x1c($sp)
/* EF326C 80240C5C AFB10014 */  sw        $s1, 0x14($sp)
/* EF3270 80240C60 AFB00010 */  sw        $s0, 0x10($sp)
/* EF3274 80240C64 8E510148 */  lw        $s1, 0x148($s2)
/* EF3278 80240C68 0C00F92F */  jal       func_8003E4BC
/* EF327C 80240C6C 86240008 */   lh       $a0, 8($s1)
/* EF3280 80240C70 0040802D */  daddu     $s0, $v0, $zero
/* EF3284 80240C74 3C028010 */  lui       $v0, %hi(D_800FFC90)
/* EF3288 80240C78 8C42FC90 */  lw        $v0, %lo(D_800FFC90)($v0)
/* EF328C 80240C7C C60C0038 */  lwc1      $f12, 0x38($s0)
/* EF3290 80240C80 C60E0040 */  lwc1      $f14, 0x40($s0)
/* EF3294 80240C84 A600008E */  sh        $zero, 0x8e($s0)
/* EF3298 80240C88 8C460028 */  lw        $a2, 0x28($v0)
/* EF329C 80240C8C 0C00ABDC */  jal       fio_validate_header_checksums
/* EF32A0 80240C90 8C470030 */   lw       $a3, 0x30($v0)
/* EF32A4 80240C94 E600000C */  swc1      $f0, 0xc($s0)
/* EF32A8 80240C98 8E2200CC */  lw        $v0, 0xcc($s1)
/* EF32AC 80240C9C 8C420020 */  lw        $v0, 0x20($v0)
/* EF32B0 80240CA0 AE020028 */  sw        $v0, 0x28($s0)
/* EF32B4 80240CA4 2402000B */  addiu     $v0, $zero, 0xb
/* EF32B8 80240CA8 AE420070 */  sw        $v0, 0x70($s2)
/* EF32BC 80240CAC 8FBF001C */  lw        $ra, 0x1c($sp)
/* EF32C0 80240CB0 8FB20018 */  lw        $s2, 0x18($sp)
/* EF32C4 80240CB4 8FB10014 */  lw        $s1, 0x14($sp)
/* EF32C8 80240CB8 8FB00010 */  lw        $s0, 0x10($sp)
/* EF32CC 80240CBC 03E00008 */  jr        $ra
/* EF32D0 80240CC0 27BD0020 */   addiu    $sp, $sp, 0x20
