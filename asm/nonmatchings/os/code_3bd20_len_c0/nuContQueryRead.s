.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel nuContQueryRead
/* 03BD20 80060920 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 03BD24 80060924 24040103 */  addiu $a0, $zero, 0x103
/* 03BD28 80060928 AFBF0010 */  sw    $ra, 0x10($sp)
/* 03BD2C 8006092C 0C00B3CA */  jal   nuSiSendMesg
/* 03BD30 80060930 0000282D */   daddu $a1, $zero, $zero
/* 03BD34 80060934 8FBF0010 */  lw    $ra, 0x10($sp)
/* 03BD38 80060938 03E00008 */  jr    $ra
/* 03BD3C 8006093C 27BD0018 */   addiu $sp, $sp, 0x18

