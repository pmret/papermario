.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055914
/* 30D14 80055914 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 30D18 80055918 240201F4 */  addiu     $v0, $zero, 0x1f4
/* 30D1C 8005591C AFA20014 */  sw        $v0, 0x14($sp)
/* 30D20 80055920 24022000 */  addiu     $v0, $zero, 0x2000
/* 30D24 80055924 AFA40010 */  sw        $a0, 0x10($sp)
/* 30D28 80055928 27A40010 */  addiu     $a0, $sp, 0x10
/* 30D2C 8005592C AFBF0030 */  sw        $ra, 0x30($sp)
/* 30D30 80055930 0C013769 */  jal       func_8004DDA4
/* 30D34 80055934 AFA2001C */   sw       $v0, 0x1c($sp)
/* 30D38 80055938 8FBF0030 */  lw        $ra, 0x30($sp)
/* 30D3C 8005593C 03E00008 */  jr        $ra
/* 30D40 80055940 27BD0038 */   addiu    $sp, $sp, 0x38
