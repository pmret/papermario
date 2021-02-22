.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242788_8B27F8
/* 8B27F8 80242788 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8B27FC 8024278C AFBF0010 */  sw        $ra, 0x10($sp)
/* 8B2800 80242790 3C018011 */  lui       $at, %hi(gPlayerData+0x3C)
/* 8B2804 80242794 A020F2CC */  sb        $zero, %lo(gPlayerData+0x3C)($at)
/* 8B2808 80242798 0C03ACA9 */  jal       func_800EB2A4
/* 8B280C 8024279C 0000202D */   daddu    $a0, $zero, $zero
/* 8B2810 802427A0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8B2814 802427A4 24020001 */  addiu     $v0, $zero, 1
/* 8B2818 802427A8 03E00008 */  jr        $ra
/* 8B281C 802427AC 27BD0018 */   addiu    $sp, $sp, 0x18
