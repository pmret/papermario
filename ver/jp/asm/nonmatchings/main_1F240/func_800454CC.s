.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800454CC
/* 208CC 800454CC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 208D0 800454D0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 208D4 800454D4 8C82000C */  lw        $v0, 0xc($a0)
/* 208D8 800454D8 3C06800B */  lui       $a2, %hi(D_800B0EF6)
/* 208DC 800454DC 80C60EF6 */  lb        $a2, %lo(D_800B0EF6)($a2)
/* 208E0 800454E0 0C0B2026 */  jal       func_802C8098
/* 208E4 800454E4 8C450000 */   lw       $a1, ($v0)
/* 208E8 800454E8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 208EC 800454EC 24020002 */  addiu     $v0, $zero, 2
/* 208F0 800454F0 03E00008 */  jr        $ra
/* 208F4 800454F4 27BD0018 */   addiu    $sp, $sp, 0x18
