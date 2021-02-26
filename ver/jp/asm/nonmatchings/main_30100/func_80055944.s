.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055944
/* 30D44 80055944 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 30D48 80055948 240201F4 */  addiu     $v0, $zero, 0x1f4
/* 30D4C 8005594C AFA20014 */  sw        $v0, 0x14($sp)
/* 30D50 80055950 24027FFF */  addiu     $v0, $zero, 0x7fff
/* 30D54 80055954 AFA40010 */  sw        $a0, 0x10($sp)
/* 30D58 80055958 27A40010 */  addiu     $a0, $sp, 0x10
/* 30D5C 8005595C AFBF0030 */  sw        $ra, 0x30($sp)
/* 30D60 80055960 0C013769 */  jal       func_8004DDA4
/* 30D64 80055964 AFA2001C */   sw       $v0, 0x1c($sp)
/* 30D68 80055968 8FBF0030 */  lw        $ra, 0x30($sp)
/* 30D6C 8005596C 03E00008 */  jr        $ra
/* 30D70 80055970 27BD0038 */   addiu    $sp, $sp, 0x38
