.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8011BAE8
/* 0B21E8 8011BAE8 0000202D */  daddu $a0, $zero, $zero
/* 0B21EC 8011BAEC 3C058015 */  lui   $a1, 0x8015
/* 0B21F0 8011BAF0 8CA512CC */  lw    $a1, 0x12cc($a1)
.L8011BAF4:
/* 0B21F4 8011BAF4 8CA30000 */  lw    $v1, ($a1)
/* 0B21F8 8011BAF8 10600004 */  beqz  $v1, .L8011BB0C
/* 0B21FC 8011BAFC 24840001 */   addiu $a0, $a0, 1
/* 0B2200 8011BB00 94620000 */  lhu   $v0, ($v1)
/* 0B2204 8011BB04 3042FBFF */  andi  $v0, $v0, 0xfbff
/* 0B2208 8011BB08 A4620000 */  sh    $v0, ($v1)
.L8011BB0C:
/* 0B220C 8011BB0C 28820100 */  slti  $v0, $a0, 0x100
/* 0B2210 8011BB10 1440FFF8 */  bnez  $v0, .L8011BAF4
/* 0B2214 8011BB14 24A50004 */   addiu $a1, $a1, 4
/* 0B2218 8011BB18 0000202D */  daddu $a0, $zero, $zero
/* 0B221C 8011BB1C 3C058015 */  lui   $a1, 0x8015
/* 0B2220 8011BB20 8CA512E0 */  lw    $a1, 0x12e0($a1)
.L8011BB24:
/* 0B2224 8011BB24 8CA30000 */  lw    $v1, ($a1)
/* 0B2228 8011BB28 10600004 */  beqz  $v1, .L8011BB3C
/* 0B222C 8011BB2C 24840001 */   addiu $a0, $a0, 1
/* 0B2230 8011BB30 94620000 */  lhu   $v0, ($v1)
/* 0B2234 8011BB34 3042FBFF */  andi  $v0, $v0, 0xfbff
/* 0B2238 8011BB38 A4620000 */  sh    $v0, ($v1)
.L8011BB3C:
/* 0B223C 8011BB3C 28820004 */  slti  $v0, $a0, 4
/* 0B2240 8011BB40 1440FFF8 */  bnez  $v0, .L8011BB24
/* 0B2244 8011BB44 24A50004 */   addiu $a1, $a1, 4
/* 0B2248 8011BB48 03E00008 */  jr    $ra
/* 0B224C 8011BB4C 00000000 */   nop   

/* 0B2250 8011BB50 3C038015 */  lui   $v1, 0x8015
/* 0B2254 8011BB54 8C633264 */  lw    $v1, 0x3264($v1)
/* 0B2258 8011BB58 24020001 */  addiu $v0, $zero, 1
/* 0B225C 8011BB5C 03E00008 */  jr    $ra
/* 0B2260 8011BB60 AC620000 */   sw    $v0, ($v1)

/* 0B2264 8011BB64 3C028015 */  lui   $v0, 0x8015
/* 0B2268 8011BB68 8C423264 */  lw    $v0, 0x3264($v0)
/* 0B226C 8011BB6C 03E00008 */  jr    $ra
/* 0B2270 8011BB70 AC400000 */   sw    $zero, ($v0)

/* 0B2274 8011BB74 3C028015 */  lui   $v0, 0x8015
/* 0B2278 8011BB78 8C423264 */  lw    $v0, 0x3264($v0)
/* 0B227C 8011BB7C AC440014 */  sw    $a0, 0x14($v0)
/* 0B2280 8011BB80 03E00008 */  jr    $ra
/* 0B2284 8011BB84 AC450018 */   sw    $a1, 0x18($v0)

