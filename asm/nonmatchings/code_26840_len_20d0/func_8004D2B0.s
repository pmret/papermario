.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004D2B0
/* 286B0 8004D2B0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 286B4 8004D2B4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 286B8 8004D2B8 8C860004 */  lw        $a2, 4($a0)
/* 286BC 8004D2BC 908200BC */  lbu       $v0, 0xbc($a0)
/* 286C0 8004D2C0 90C30045 */  lbu       $v1, 0x45($a2)
/* 286C4 8004D2C4 14620004 */  bne       $v1, $v0, .L8004D2D8
/* 286C8 8004D2C8 00000000 */   nop      
/* 286CC 8004D2CC 908500BF */  lbu       $a1, 0xbf($a0)
/* 286D0 8004D2D0 0C014E31 */  jal       func_800538C4
/* 286D4 8004D2D4 00C0202D */   daddu    $a0, $a2, $zero
.L8004D2D8:
/* 286D8 8004D2D8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 286DC 8004D2DC 03E00008 */  jr        $ra
/* 286E0 8004D2E0 27BD0018 */   addiu    $sp, $sp, 0x18
