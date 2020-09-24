.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055FF0
/* 313F0 80055FF0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 313F4 80055FF4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 313F8 80055FF8 0C0157D6 */  jal       func_80055F58
/* 313FC 80055FFC 2406003F */   addiu    $a2, $zero, 0x3f
/* 31400 80056000 8FBF0010 */  lw        $ra, 0x10($sp)
/* 31404 80056004 03E00008 */  jr        $ra
/* 31408 80056008 27BD0018 */   addiu    $sp, $sp, 0x18
