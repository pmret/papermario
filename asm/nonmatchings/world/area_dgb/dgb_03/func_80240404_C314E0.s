.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240404_C318E4
/* C318E4 80240404 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C318E8 80240408 AFB10014 */  sw        $s1, 0x14($sp)
/* C318EC 8024040C 0080882D */  daddu     $s1, $a0, $zero
/* C318F0 80240410 AFBF0018 */  sw        $ra, 0x18($sp)
/* C318F4 80240414 AFB00010 */  sw        $s0, 0x10($sp)
/* C318F8 80240418 8E300148 */  lw        $s0, 0x148($s1)
/* C318FC 8024041C 0C00EABB */  jal       get_npc_unsafe
/* C31900 80240420 86040008 */   lh       $a0, 8($s0)
/* C31904 80240424 9443008E */  lhu       $v1, 0x8e($v0)
/* C31908 80240428 2463FFFF */  addiu     $v1, $v1, -1
/* C3190C 8024042C A443008E */  sh        $v1, 0x8e($v0)
/* C31910 80240430 00031C00 */  sll       $v1, $v1, 0x10
/* C31914 80240434 1C600003 */  bgtz      $v1, .L80240444
/* C31918 80240438 2402000C */   addiu    $v0, $zero, 0xc
/* C3191C 8024043C AE00006C */  sw        $zero, 0x6c($s0)
/* C31920 80240440 AE220070 */  sw        $v0, 0x70($s1)
.L80240444:
/* C31924 80240444 8FBF0018 */  lw        $ra, 0x18($sp)
/* C31928 80240448 8FB10014 */  lw        $s1, 0x14($sp)
/* C3192C 8024044C 8FB00010 */  lw        $s0, 0x10($sp)
/* C31930 80240450 03E00008 */  jr        $ra
/* C31934 80240454 27BD0020 */   addiu    $sp, $sp, 0x20
