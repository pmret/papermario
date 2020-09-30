.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005591C
/* 30D1C 8005591C 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 30D20 80055920 AFB00030 */  sw        $s0, 0x30($sp)
/* 30D24 80055924 3C108008 */  lui       $s0, 0x8008
/* 30D28 80055928 26108DB0 */  addiu     $s0, $s0, -0x7250
/* 30D2C 8005592C 24020001 */  addiu     $v0, $zero, 1
/* 30D30 80055930 AFBF0034 */  sw        $ra, 0x34($sp)
/* 30D34 80055934 AE020000 */  sw        $v0, ($s0)
/* 30D38 80055938 2402007F */  addiu     $v0, $zero, 0x7f
/* 30D3C 8005593C AFA40010 */  sw        $a0, 0x10($sp)
/* 30D40 80055940 27A40010 */  addiu     $a0, $sp, 0x10
/* 30D44 80055944 AFA00014 */  sw        $zero, 0x14($sp)
/* 30D48 80055948 AFA20018 */  sw        $v0, 0x18($sp)
/* 30D4C 8005594C AFA2001C */  sw        $v0, 0x1c($sp)
/* 30D50 80055950 AFA00020 */  sw        $zero, 0x20($sp)
/* 30D54 80055954 0C0135F8 */  jal       func_8004D7E0
/* 30D58 80055958 AFA00024 */   sw       $zero, 0x24($sp)
/* 30D5C 8005595C AE000000 */  sw        $zero, ($s0)
/* 30D60 80055960 8FBF0034 */  lw        $ra, 0x34($sp)
/* 30D64 80055964 8FB00030 */  lw        $s0, 0x30($sp)
/* 30D68 80055968 03E00008 */  jr        $ra
/* 30D6C 8005596C 27BD0038 */   addiu    $sp, $sp, 0x38
