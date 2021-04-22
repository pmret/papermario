.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055674
/* 30A74 80055674 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 30A78 80055678 AFBF0010 */  sw        $ra, 0x10($sp)
/* 30A7C 8005567C 0C0135AF */  jal       func_8004D6BC
/* 30A80 80055680 00000000 */   nop
/* 30A84 80055684 8FBF0010 */  lw        $ra, 0x10($sp)
/* 30A88 80055688 03E00008 */  jr        $ra
/* 30A8C 8005568C 27BD0018 */   addiu    $sp, $sp, 0x18
