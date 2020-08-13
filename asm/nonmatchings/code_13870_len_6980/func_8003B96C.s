.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8003B96C
/* 016D6C 8003B96C 3084FFFF */  andi  $a0, $a0, 0xffff
/* 016D70 8003B970 000412C2 */  srl   $v0, $a0, 0xb
/* 016D74 8003B974 240700FF */  addiu $a3, $zero, 0xff
/* 016D78 8003B978 00E63823 */  subu  $a3, $a3, $a2
/* 016D7C 8003B97C 00470018 */  mult  $v0, $a3
/* 016D80 8003B980 00004012 */  mflo  $t0
/* 016D84 8003B984 30A3FFFF */  andi  $v1, $a1, 0xffff
/* 016D88 8003B988 000312C2 */  srl   $v0, $v1, 0xb
/* 016D8C 8003B98C 00460018 */  mult  $v0, $a2
/* 016D90 8003B990 3C098080 */  lui   $t1, 0x8080
/* 016D94 8003B994 00005012 */  mflo  $t2
/* 016D98 8003B998 35298081 */  ori   $t1, $t1, 0x8081
/* 016D9C 8003B99C 010A4021 */  addu  $t0, $t0, $t2
/* 016DA0 8003B9A0 01090018 */  mult  $t0, $t1
/* 016DA4 8003B9A4 00006010 */  mfhi  $t4
/* 016DA8 8003B9A8 00041182 */  srl   $v0, $a0, 6
/* 016DAC 8003B9AC 3042001F */  andi  $v0, $v0, 0x1f
/* 016DB0 8003B9B0 00470018 */  mult  $v0, $a3
/* 016DB4 8003B9B4 00005012 */  mflo  $t2
/* 016DB8 8003B9B8 00031182 */  srl   $v0, $v1, 6
/* 016DBC 8003B9BC 3042001F */  andi  $v0, $v0, 0x1f
/* 016DC0 8003B9C0 00460018 */  mult  $v0, $a2
/* 016DC4 8003B9C4 00001012 */  mflo  $v0
/* 016DC8 8003B9C8 00042042 */  srl   $a0, $a0, 1
/* 016DCC 8003B9CC 3084001F */  andi  $a0, $a0, 0x1f
/* 016DD0 8003B9D0 00870018 */  mult  $a0, $a3
/* 016DD4 8003B9D4 00003812 */  mflo  $a3
/* 016DD8 8003B9D8 00031842 */  srl   $v1, $v1, 1
/* 016DDC 8003B9DC 3063001F */  andi  $v1, $v1, 0x1f
/* 016DE0 8003B9E0 00660018 */  mult  $v1, $a2
/* 016DE4 8003B9E4 30A50001 */  andi  $a1, $a1, 1
/* 016DE8 8003B9E8 01882021 */  addu  $a0, $t4, $t0
/* 016DEC 8003B9EC 01421021 */  addu  $v0, $t2, $v0
/* 016DF0 8003B9F0 00006812 */  mflo  $t5
/* 016DF4 8003B9F4 000421C3 */  sra   $a0, $a0, 7
/* 016DF8 8003B9F8 000847C3 */  sra   $t0, $t0, 0x1f
/* 016DFC 8003B9FC 00490018 */  mult  $v0, $t1
/* 016E00 8003BA00 00882023 */  subu  $a0, $a0, $t0
/* 016E04 8003BA04 308400FF */  andi  $a0, $a0, 0xff
/* 016E08 8003BA08 000422C0 */  sll   $a0, $a0, 0xb
/* 016E0C 8003BA0C 00ED3021 */  addu  $a2, $a3, $t5
/* 016E10 8003BA10 00001810 */  mfhi  $v1
/* 016E14 8003BA14 00621821 */  addu  $v1, $v1, $v0
/* 016E18 8003BA18 000319C3 */  sra   $v1, $v1, 7
/* 016E1C 8003BA1C 000217C3 */  sra   $v0, $v0, 0x1f
/* 016E20 8003BA20 00C90018 */  mult  $a2, $t1
/* 016E24 8003BA24 00621823 */  subu  $v1, $v1, $v0
/* 016E28 8003BA28 306300FF */  andi  $v1, $v1, 0xff
/* 016E2C 8003BA2C 00031980 */  sll   $v1, $v1, 6
/* 016E30 8003BA30 00832025 */  or    $a0, $a0, $v1
/* 016E34 8003BA34 00003810 */  mfhi  $a3
/* 016E38 8003BA38 00E61021 */  addu  $v0, $a3, $a2
/* 016E3C 8003BA3C 000211C3 */  sra   $v0, $v0, 7
/* 016E40 8003BA40 000637C3 */  sra   $a2, $a2, 0x1f
/* 016E44 8003BA44 00461023 */  subu  $v0, $v0, $a2
/* 016E48 8003BA48 304200FF */  andi  $v0, $v0, 0xff
/* 016E4C 8003BA4C 00021040 */  sll   $v0, $v0, 1
/* 016E50 8003BA50 00822025 */  or    $a0, $a0, $v0
/* 016E54 8003BA54 00A42825 */  or    $a1, $a1, $a0
/* 016E58 8003BA58 03E00008 */  jr    $ra
/* 016E5C 8003BA5C 30A2FFFF */   andi  $v0, $a1, 0xffff

