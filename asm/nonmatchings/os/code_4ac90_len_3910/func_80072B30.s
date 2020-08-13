.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80072B30
/* 04DF30 80072B30 3C028007 */  lui   $v0, 0x8007
/* 04DF34 80072B34 8C42419C */  lw    $v0, 0x419c($v0)
/* 04DF38 80072B38 A04000AA */  sb    $zero, 0xaa($v0)
/* 04DF3C 80072B3C 24020001 */  addiu $v0, $zero, 1
/* 04DF40 80072B40 3C01800E */  lui   $at, 0x800e
/* 04DF44 80072B44 AC20C068 */  sw    $zero, -0x3f98($at)
/* 04DF48 80072B48 3C01800E */  lui   $at, 0x800e
/* 04DF4C 80072B4C AC22C4E0 */  sw    $v0, -0x3b20($at)
/* 04DF50 80072B50 3C01800E */  lui   $at, 0x800e
/* 04DF54 80072B54 AC20C4DC */  sw    $zero, -0x3b24($at)
/* 04DF58 80072B58 3C01800E */  lui   $at, 0x800e
/* 04DF5C 80072B5C AC20C4D0 */  sw    $zero, -0x3b30($at)
/* 04DF60 80072B60 3C01800E */  lui   $at, 0x800e
/* 04DF64 80072B64 AC20C4F0 */  sw    $zero, -0x3b10($at)
/* 04DF68 80072B68 3C01800E */  lui   $at, 0x800e
/* 04DF6C 80072B6C AC20C4D4 */  sw    $zero, -0x3b2c($at)
/* 04DF70 80072B70 3C01800E */  lui   $at, 0x800e
/* 04DF74 80072B74 AC20C4FC */  sw    $zero, -0x3b04($at)
/* 04DF78 80072B78 3C01800E */  lui   $at, 0x800e
/* 04DF7C 80072B7C AC20C4F8 */  sw    $zero, -0x3b08($at)
/* 04DF80 80072B80 3C01800E */  lui   $at, 0x800e
/* 04DF84 80072B84 AC20C4E8 */  sw    $zero, -0x3b18($at)
/* 04DF88 80072B88 3C01800E */  lui   $at, 0x800e
/* 04DF8C 80072B8C AC20C064 */  sw    $zero, -0x3f9c($at)
/* 04DF90 80072B90 3C01800E */  lui   $at, 0x800e
/* 04DF94 80072B94 AC20C060 */  sw    $zero, -0x3fa0($at)
/* 04DF98 80072B98 3C01800E */  lui   $at, 0x800e
/* 04DF9C 80072B9C AC20C4EC */  sw    $zero, -0x3b14($at)
/* 04DFA0 80072BA0 3C01800E */  lui   $at, 0x800e
/* 04DFA4 80072BA4 AC20C4F4 */  sw    $zero, -0x3b0c($at)
/* 04DFA8 80072BA8 03E00008 */  jr    $ra
/* 04DFAC 80072BAC 00000000 */   nop   

/* 04DFB0 80072BB0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 04DFB4 80072BB4 AFBF0010 */  sw    $ra, 0x10($sp)
/* 04DFB8 80072BB8 0C01CACC */  jal   func_80072B30
/* 04DFBC 80072BBC 00000000 */   nop   
/* 04DFC0 80072BC0 8FBF0010 */  lw    $ra, 0x10($sp)
/* 04DFC4 80072BC4 03E00008 */  jr    $ra
/* 04DFC8 80072BC8 27BD0018 */   addiu $sp, $sp, 0x18

