.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055CA0
/* 310A0 80055CA0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 310A4 80055CA4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 310A8 80055CA8 0C015702 */  jal       func_80055C08
/* 310AC 80055CAC 2406003F */   addiu    $a2, $zero, 0x3f
/* 310B0 80055CB0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 310B4 80055CB4 03E00008 */  jr        $ra
/* 310B8 80055CB8 27BD0018 */   addiu    $sp, $sp, 0x18
