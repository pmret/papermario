.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240DD0
/* 8ECBF0 80240DD0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8ECBF4 80240DD4 0000202D */  daddu     $a0, $zero, $zero
/* 8ECBF8 80240DD8 240503E8 */  addiu     $a1, $zero, 0x3e8
/* 8ECBFC 80240DDC AFBF0010 */  sw        $ra, 0x10($sp)
/* 8ECC00 80240DE0 0C01559B */  jal       func_8005566C
/* 8ECC04 80240DE4 2406003F */   addiu    $a2, $zero, 0x3f
/* 8ECC08 80240DE8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8ECC0C 80240DEC 24020002 */  addiu     $v0, $zero, 2
/* 8ECC10 80240DF0 03E00008 */  jr        $ra
/* 8ECC14 80240DF4 27BD0018 */   addiu    $sp, $sp, 0x18
