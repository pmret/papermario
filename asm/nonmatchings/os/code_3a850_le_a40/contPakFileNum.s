.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel contPakFileNum
/* 03ACD0 8005F8D0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 03ACD4 8005F8D4 AFBF0010 */  sw    $ra, 0x10($sp)
/* 03ACD8 8005F8D8 8C82000C */  lw    $v0, 0xc($a0)
/* 03ACDC 8005F8DC 8C430000 */  lw    $v1, ($v0)
/* 03ACE0 8005F8E0 8C450004 */  lw    $a1, 4($v0)
/* 03ACE4 8005F8E4 8C460008 */  lw    $a2, 8($v0)
/* 03ACE8 8005F8E8 0C01A424 */  jal   osPfsNumFiles
/* 03ACEC 8005F8EC 8C640000 */   lw    $a0, ($v1)
/* 03ACF0 8005F8F0 8FBF0010 */  lw    $ra, 0x10($sp)
/* 03ACF4 8005F8F4 03E00008 */  jr    $ra
/* 03ACF8 8005F8F8 27BD0018 */   addiu $sp, $sp, 0x18

