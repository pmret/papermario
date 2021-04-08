.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241A2C_EEEB2C
/* EEEB2C 80241A2C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EEEB30 80241A30 AFB20018 */  sw        $s2, 0x18($sp)
/* EEEB34 80241A34 0080902D */  daddu     $s2, $a0, $zero
/* EEEB38 80241A38 AFBF001C */  sw        $ra, 0x1c($sp)
/* EEEB3C 80241A3C AFB10014 */  sw        $s1, 0x14($sp)
/* EEEB40 80241A40 AFB00010 */  sw        $s0, 0x10($sp)
/* EEEB44 80241A44 8E510148 */  lw        $s1, 0x148($s2)
/* EEEB48 80241A48 0C00F92F */  jal       func_8003E4BC
/* EEEB4C 80241A4C 86240008 */   lh       $a0, 8($s1)
/* EEEB50 80241A50 0040802D */  daddu     $s0, $v0, $zero
/* EEEB54 80241A54 3C028010 */  lui       $v0, %hi(D_800FFC90)
/* EEEB58 80241A58 8C42FC90 */  lw        $v0, %lo(D_800FFC90)($v0)
/* EEEB5C 80241A5C C60C0038 */  lwc1      $f12, 0x38($s0)
/* EEEB60 80241A60 C60E0040 */  lwc1      $f14, 0x40($s0)
/* EEEB64 80241A64 A600008E */  sh        $zero, 0x8e($s0)
/* EEEB68 80241A68 8C460028 */  lw        $a2, 0x28($v0)
/* EEEB6C 80241A6C 0C00ABDC */  jal       fio_validate_header_checksums
/* EEEB70 80241A70 8C470030 */   lw       $a3, 0x30($v0)
/* EEEB74 80241A74 E600000C */  swc1      $f0, 0xc($s0)
/* EEEB78 80241A78 8E2200CC */  lw        $v0, 0xcc($s1)
/* EEEB7C 80241A7C 8C420020 */  lw        $v0, 0x20($v0)
/* EEEB80 80241A80 AE020028 */  sw        $v0, 0x28($s0)
/* EEEB84 80241A84 2402000B */  addiu     $v0, $zero, 0xb
/* EEEB88 80241A88 AE420070 */  sw        $v0, 0x70($s2)
/* EEEB8C 80241A8C 8FBF001C */  lw        $ra, 0x1c($sp)
/* EEEB90 80241A90 8FB20018 */  lw        $s2, 0x18($sp)
/* EEEB94 80241A94 8FB10014 */  lw        $s1, 0x14($sp)
/* EEEB98 80241A98 8FB00010 */  lw        $s0, 0x10($sp)
/* EEEB9C 80241A9C 03E00008 */  jr        $ra
/* EEEBA0 80241AA0 27BD0020 */   addiu    $sp, $sp, 0x20
