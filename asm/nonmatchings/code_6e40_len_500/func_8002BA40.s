.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8002BA40
/* 006E40 8002BA40 3C014000 */  lui   $at, 0x4000
/* 006E44 8002BA44 44810000 */  mtc1  $at, $f0
/* 006E48 8002BA48 3C01800A */  lui   $at, 0x800a
/* 006E4C 8002BA4C AC20BAA0 */  sw    $zero, -0x4560($at)
/* 006E50 8002BA50 3C01800A */  lui   $at, 0x800a
/* 006E54 8002BA54 AC20BA98 */  sw    $zero, -0x4568($at)
/* 006E58 8002BA58 3C01800A */  lui   $at, 0x800a
/* 006E5C 8002BA5C AC20BA9C */  sw    $zero, -0x4564($at)
/* 006E60 8002BA60 3C01800A */  lui   $at, 0x800a
/* 006E64 8002BA64 E420BA90 */  swc1  $f0, -0x4570($at)
/* 006E68 8002BA68 3C01800A */  lui   $at, 0x800a
/* 006E6C 8002BA6C E420BA94 */  swc1  $f0, -0x456c($at)
/* 006E70 8002BA70 03E00008 */  jr    $ra
/* 006E74 8002BA74 00000000 */   nop   

