.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241D1C_8EDB3C
/* 8EDB3C 80241D1C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8EDB40 80241D20 0000202D */  daddu     $a0, $zero, $zero
/* 8EDB44 80241D24 240503E8 */  addiu     $a1, $zero, 0x3e8
/* 8EDB48 80241D28 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8EDB4C 80241D2C 0C01559B */  jal       func_8005566C
/* 8EDB50 80241D30 2406003F */   addiu    $a2, $zero, 0x3f
/* 8EDB54 80241D34 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8EDB58 80241D38 24020002 */  addiu     $v0, $zero, 2
/* 8EDB5C 80241D3C 03E00008 */  jr        $ra
/* 8EDB60 80241D40 27BD0018 */   addiu    $sp, $sp, 0x18
/* 8EDB64 80241D44 00000000 */  nop
/* 8EDB68 80241D48 00000000 */  nop
/* 8EDB6C 80241D4C 00000000 */  nop
