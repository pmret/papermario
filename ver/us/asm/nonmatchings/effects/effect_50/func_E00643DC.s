.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00643DC
/* 3652EC E00643DC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3652F0 E00643E0 3C02E006 */  lui       $v0, %hi(func_E0064414)
/* 3652F4 E00643E4 24424414 */  addiu     $v0, $v0, %lo(func_E0064414)
/* 3652F8 E00643E8 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3652FC E00643EC 24020028 */  addiu     $v0, $zero, 0x28
/* 365300 E00643F0 AFA40018 */  sw        $a0, 0x18($sp)
/* 365304 E00643F4 27A40010 */  addiu     $a0, $sp, 0x10
/* 365308 E00643F8 AFBF0020 */  sw        $ra, 0x20($sp)
/* 36530C E00643FC AFA00014 */  sw        $zero, 0x14($sp)
/* 365310 E0064400 0C080120 */  jal       func_E0200480
/* 365314 E0064404 AFA20010 */   sw       $v0, 0x10($sp)
/* 365318 E0064408 8FBF0020 */  lw        $ra, 0x20($sp)
/* 36531C E006440C 03E00008 */  jr        $ra
/* 365320 E0064410 27BD0028 */   addiu    $sp, $sp, 0x28
