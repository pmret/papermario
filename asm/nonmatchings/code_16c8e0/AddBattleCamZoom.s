.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel AddBattleCamZoom
/* 17D58C 8024ECAC 3C028028 */  lui   $v0, 0x8028
/* 17D590 8024ECB0 80420CE0 */  lb    $v0, 0xce0($v0)
/* 17D594 8024ECB4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 17D598 8024ECB8 AFBF0010 */  sw    $ra, 0x10($sp)
/* 17D59C 8024ECBC 8C85000C */  lw    $a1, 0xc($a0)
/* 17D5A0 8024ECC0 1440000A */  bnez  $v0, .L8024ECEC
/* 17D5A4 8024ECC4 24020002 */   addiu $v0, $zero, 2
/* 17D5A8 8024ECC8 8CA50000 */  lw    $a1, ($a1)
/* 17D5AC 8024ECCC 0C0B1EAF */  jal   get_variable
/* 17D5B0 8024ECD0 00000000 */   nop   
/* 17D5B4 8024ECD4 3C04802A */  lui   $a0, 0x802a
/* 17D5B8 8024ECD8 2484F280 */  addiu $a0, $a0, -0xd80
/* 17D5BC 8024ECDC 94830000 */  lhu   $v1, ($a0)
/* 17D5C0 8024ECE0 00621821 */  addu  $v1, $v1, $v0
/* 17D5C4 8024ECE4 24020002 */  addiu $v0, $zero, 2
/* 17D5C8 8024ECE8 A4830000 */  sh    $v1, ($a0)
.L8024ECEC:
/* 17D5CC 8024ECEC 8FBF0010 */  lw    $ra, 0x10($sp)
/* 17D5D0 8024ECF0 03E00008 */  jr    $ra
/* 17D5D4 8024ECF4 27BD0018 */   addiu $sp, $sp, 0x18

/* 17D5D8 8024ECF8 3C028028 */  lui   $v0, 0x8028
/* 17D5DC 8024ECFC 80420CE0 */  lb    $v0, 0xce0($v0)
/* 17D5E0 8024ED00 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 17D5E4 8024ED04 AFB10014 */  sw    $s1, 0x14($sp)
/* 17D5E8 8024ED08 0080882D */  daddu $s1, $a0, $zero
/* 17D5EC 8024ED0C AFBF0018 */  sw    $ra, 0x18($sp)
/* 17D5F0 8024ED10 AFB00010 */  sw    $s0, 0x10($sp)
/* 17D5F4 8024ED14 8E30000C */  lw    $s0, 0xc($s1)
/* 17D5F8 8024ED18 14400012 */  bnez  $v0, .L8024ED64
/* 17D5FC 8024ED1C 24020002 */   addiu $v0, $zero, 2
/* 17D600 8024ED20 8E050000 */  lw    $a1, ($s0)
/* 17D604 8024ED24 0C0B1EAF */  jal   get_variable
/* 17D608 8024ED28 26100004 */   addiu $s0, $s0, 4
/* 17D60C 8024ED2C 3C01802A */  lui   $at, 0x802a
/* 17D610 8024ED30 A022F2A2 */  sb    $v0, -0xd5e($at)
/* 17D614 8024ED34 8E050000 */  lw    $a1, ($s0)
/* 17D618 8024ED38 26100004 */  addiu $s0, $s0, 4
/* 17D61C 8024ED3C 0C0B1EAF */  jal   get_variable
/* 17D620 8024ED40 0220202D */   daddu $a0, $s1, $zero
/* 17D624 8024ED44 3C01802A */  lui   $at, 0x802a
/* 17D628 8024ED48 A022F2A3 */  sb    $v0, -0xd5d($at)
/* 17D62C 8024ED4C 8E050000 */  lw    $a1, ($s0)
/* 17D630 8024ED50 0C0B1EAF */  jal   get_variable
/* 17D634 8024ED54 0220202D */   daddu $a0, $s1, $zero
/* 17D638 8024ED58 3C01802A */  lui   $at, 0x802a
/* 17D63C 8024ED5C A022F2A5 */  sb    $v0, -0xd5b($at)
/* 17D640 8024ED60 24020002 */  addiu $v0, $zero, 2
.L8024ED64:
/* 17D644 8024ED64 8FBF0018 */  lw    $ra, 0x18($sp)
/* 17D648 8024ED68 8FB10014 */  lw    $s1, 0x14($sp)
/* 17D64C 8024ED6C 8FB00010 */  lw    $s0, 0x10($sp)
/* 17D650 8024ED70 03E00008 */  jr    $ra
/* 17D654 8024ED74 27BD0020 */   addiu $sp, $sp, 0x20

