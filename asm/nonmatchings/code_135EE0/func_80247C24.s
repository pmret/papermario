.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80247C24
/* 13AF64 80247C24 8FAB0054 */  lw    $t3, 0x54($sp)
/* 13AF68 80247C28 24020001 */  addiu $v0, $zero, 1
.L80247C2C:
/* 13AF6C 80247C2C 15620060 */  bne   $t3, $v0, .L80247DB0
/* 13AF70 80247C30 3C052000 */   lui   $a1, 0x2000
/* 13AF74 80247C34 8FAA0058 */  lw    $t2, 0x58($sp)
/* 13AF78 80247C38 000A1080 */  sll   $v0, $t2, 2
/* 13AF7C 80247C3C 3C0B8027 */  lui   $t3, 0x8027
/* 13AF80 80247C40 256B03A8 */  addiu $t3, $t3, 0x3a8
/* 13AF84 80247C44 004B1021 */  addu  $v0, $v0, $t3
/* 13AF88 80247C48 8C510000 */  lw    $s1, ($v0)
/* 13AF8C 80247C4C 0C05128B */  jal   clear_icon_flags
/* 13AF90 80247C50 0220202D */   daddu $a0, $s1, $zero
/* 13AF94 80247C54 0220202D */  daddu $a0, $s1, $zero
/* 13AF98 80247C58 0C051280 */  jal   set_icon_flags
/* 13AF9C 80247C5C 34058000 */   ori   $a1, $zero, 0x8000
/* 13AFA0 80247C60 8FAA0088 */  lw    $t2, 0x88($sp)
/* 13AFA4 80247C64 11400005 */  beqz  $t2, .L80247C7C
/* 13AFA8 80247C68 00000000 */   nop   
/* 13AFAC 80247C6C 3C118027 */  lui   $s1, 0x8027
/* 13AFB0 80247C70 8E3103FC */  lw    $s1, 0x3fc($s1)
/* 13AFB4 80247C74 08091F51 */  j     func_80247D44
/* 13AFB8 80247C78 00000000 */   nop   

.L80247C7C:
/* 13AFBC 80247C7C 12A00010 */  beqz  $s5, .L80247CC0
/* 13AFC0 80247C80 0220202D */   daddu $a0, $s1, $zero
/* 13AFC4 80247C84 0C051280 */  jal   set_icon_flags
/* 13AFC8 80247C88 3C052000 */   lui   $a1, 0x2000
/* 13AFCC 80247C8C 00131400 */  sll   $v0, $s3, 0x10
/* 13AFD0 80247C90 000212C3 */  sra   $v0, $v0, 0xb
/* 13AFD4 80247C94 3C0B8008 */  lui   $t3, 0x8008
/* 13AFD8 80247C98 256B78E0 */  addiu $t3, $t3, 0x78e0
/* 13AFDC 80247C9C 004B1021 */  addu  $v0, $v0, $t3
/* 13AFE0 80247CA0 84420004 */  lh    $v0, 4($v0)
/* 13AFE4 80247CA4 3C0A8009 */  lui   $t2, 0x8009
/* 13AFE8 80247CA8 254AA680 */  addiu $t2, $t2, -0x5980
/* 13AFEC 80247CAC 000210C0 */  sll   $v0, $v0, 3
/* 13AFF0 80247CB0 004A1021 */  addu  $v0, $v0, $t2
/* 13AFF4 80247CB4 8C420000 */  lw    $v0, ($v0)
/* 13AFF8 80247CB8 3C018027 */  lui   $at, 0x8027
/* 13AFFC 80247CBC AC2200CC */  sw    $v0, 0xcc($at)
.L80247CC0:
/* 13B000 80247CC0 8FAB0084 */  lw    $t3, 0x84($sp)
/* 13B004 80247CC4 1560000F */  bnez  $t3, .L80247D04
/* 13B008 80247CC8 00131400 */   sll   $v0, $s3, 0x10
/* 13B00C 80247CCC 8FAA008C */  lw    $t2, 0x8c($sp)
/* 13B010 80247CD0 1140000B */  beqz  $t2, .L80247D00
