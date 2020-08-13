.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80037968
/* 012D68 80037968 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 012D6C 8003796C F7B40018 */  sdc1  $f20, 0x18($sp)
/* 012D70 80037970 AFBF0010 */  sw    $ra, 0x10($sp)
/* 012D74 80037974 0C00DE65 */  jal   func_80037994
/* 012D78 80037978 46007506 */   mov.s $f20, $f14
/* 012D7C 8003797C 0C00DF85 */  jal   func_80037E14
/* 012D80 80037980 4600A306 */   mov.s $f12, $f20
/* 012D84 80037984 8FBF0010 */  lw    $ra, 0x10($sp)
/* 012D88 80037988 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 012D8C 8003798C 03E00008 */  jr    $ra
/* 012D90 80037990 27BD0020 */   addiu $sp, $sp, 0x20

