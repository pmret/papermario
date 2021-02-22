.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240330_8EC150
/* 8EC150 80240330 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8EC154 80240334 0000202D */  daddu     $a0, $zero, $zero
/* 8EC158 80240338 240503E8 */  addiu     $a1, $zero, 0x3e8
/* 8EC15C 8024033C AFBF0010 */  sw        $ra, 0x10($sp)
/* 8EC160 80240340 0C01559B */  jal       func_8005566C
/* 8EC164 80240344 2406003F */   addiu    $a2, $zero, 0x3f
/* 8EC168 80240348 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8EC16C 8024034C 24020002 */  addiu     $v0, $zero, 2
/* 8EC170 80240350 03E00008 */  jr        $ra
/* 8EC174 80240354 27BD0018 */   addiu    $sp, $sp, 0x18
