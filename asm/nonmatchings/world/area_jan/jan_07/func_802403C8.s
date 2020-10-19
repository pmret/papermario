.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403C8
/* B59C38 802403C8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B59C3C 802403CC AFB10014 */  sw        $s1, 0x14($sp)
/* B59C40 802403D0 0080882D */  daddu     $s1, $a0, $zero
/* B59C44 802403D4 AFBF0018 */  sw        $ra, 0x18($sp)
/* B59C48 802403D8 AFB00010 */  sw        $s0, 0x10($sp)
/* B59C4C 802403DC 8E300148 */  lw        $s0, 0x148($s1)
/* B59C50 802403E0 0C00EABB */  jal       get_npc_unsafe
/* B59C54 802403E4 86040008 */   lh       $a0, 8($s0)
/* B59C58 802403E8 9443008E */  lhu       $v1, 0x8e($v0)
/* B59C5C 802403EC 2463FFFF */  addiu     $v1, $v1, -1
/* B59C60 802403F0 A443008E */  sh        $v1, 0x8e($v0)
/* B59C64 802403F4 00031C00 */  sll       $v1, $v1, 0x10
/* B59C68 802403F8 1C600003 */  bgtz      $v1, .L80240408
/* B59C6C 802403FC 2402000C */   addiu    $v0, $zero, 0xc
/* B59C70 80240400 AE00006C */  sw        $zero, 0x6c($s0)
/* B59C74 80240404 AE220070 */  sw        $v0, 0x70($s1)
.L80240408:
/* B59C78 80240408 8FBF0018 */  lw        $ra, 0x18($sp)
/* B59C7C 8024040C 8FB10014 */  lw        $s1, 0x14($sp)
/* B59C80 80240410 8FB00010 */  lw        $s0, 0x10($sp)
/* B59C84 80240414 03E00008 */  jr        $ra
/* B59C88 80240418 27BD0020 */   addiu    $sp, $sp, 0x20
