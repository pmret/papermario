.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel nuContQueryRead
/* 3BD20 80060920 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3BD24 80060924 24040103 */  addiu     $a0, $zero, 0x103
/* 3BD28 80060928 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3BD2C 8006092C 0C00B3CA */  jal       nuSiSendMesg
/* 3BD30 80060930 0000282D */   daddu    $a1, $zero, $zero
/* 3BD34 80060934 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3BD38 80060938 03E00008 */  jr        $ra
/* 3BD3C 8006093C 27BD0018 */   addiu    $sp, $sp, 0x18
