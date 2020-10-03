.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80056180
/* 31580 80056180 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 31584 80056184 AFBF0010 */  sw        $ra, 0x10($sp)
/* 31588 80056188 0C015B57 */  jal       func_80056D5C
/* 3158C 8005618C 0000202D */   daddu    $a0, $zero, $zero
/* 31590 80056190 0C01536A */  jal       func_80054DA8
/* 31594 80056194 24040001 */   addiu    $a0, $zero, 1
/* 31598 80056198 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3159C 8005619C 03E00008 */  jr        $ra
/* 315A0 800561A0 27BD0018 */   addiu    $sp, $sp, 0x18
