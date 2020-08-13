.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80120C58
/* 0B7358 80120C58 3C028007 */  lui   $v0, 0x8007
/* 0B735C 80120C5C 8C42419C */  lw    $v0, 0x419c($v0)
/* 0B7360 80120C60 80420070 */  lb    $v0, 0x70($v0)
/* 0B7364 80120C64 14400005 */  bnez  $v0, .L80120C7C
/* 0B7368 80120C68 00000000 */   nop   
/* 0B736C 80120C6C 3C028015 */  lui   $v0, 0x8015
/* 0B7370 80120C70 24423B70 */  addiu $v0, $v0, 0x3b70
/* 0B7374 80120C74 08048321 */  j     .L80120C84
/* 0B7378 80120C78 00000000 */   nop   

.L80120C7C:
/* 0B737C 80120C7C 3C028015 */  lui   $v0, 0x8015
/* 0B7380 80120C80 24423F70 */  addiu $v0, $v0, 0x3f70
.L80120C84:
/* 0B7384 80120C84 3C018015 */  lui   $at, 0x8015
/* 0B7388 80120C88 AC224370 */  sw    $v0, 0x4370($at)
/* 0B738C 80120C8C 2402000A */  addiu $v0, $zero, 0xa
/* 0B7390 80120C90 3C018015 */  lui   $at, 0x8015
/* 0B7394 80120C94 AC22437C */  sw    $v0, 0x437c($at)
/* 0B7398 80120C98 3C018015 */  lui   $at, 0x8015
/* 0B739C 80120C9C AC224380 */  sw    $v0, 0x4380($at)
/* 0B73A0 80120CA0 3C018015 */  lui   $at, 0x8015
/* 0B73A4 80120CA4 AC224384 */  sw    $v0, 0x4384($at)
/* 0B73A8 80120CA8 3C018015 */  lui   $at, 0x8015
/* 0B73AC 80120CAC AC224388 */  sw    $v0, 0x4388($at)
/* 0B73B0 80120CB0 24020320 */  addiu $v0, $zero, 0x320
/* 0B73B4 80120CB4 3C018015 */  lui   $at, 0x8015
/* 0B73B8 80120CB8 AC22438C */  sw    $v0, 0x438c($at)
/* 0B73BC 80120CBC 240203E8 */  addiu $v0, $zero, 0x3e8
/* 0B73C0 80120CC0 3C018015 */  lui   $at, 0x8015
/* 0B73C4 80120CC4 AC201318 */  sw    $zero, 0x1318($at)
/* 0B73C8 80120CC8 3C018015 */  lui   $at, 0x8015
/* 0B73CC 80120CCC AC204378 */  sw    $zero, 0x4378($at)
/* 0B73D0 80120CD0 3C018015 */  lui   $at, 0x8015
/* 0B73D4 80120CD4 AC224390 */  sw    $v0, 0x4390($at)
/* 0B73D8 80120CD8 03E00008 */  jr    $ra
/* 0B73DC 80120CDC 00000000 */   nop   

