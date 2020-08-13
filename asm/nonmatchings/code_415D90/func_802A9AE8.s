.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_802A9AE8
/* 41E878 802A9AE8 3C02800E */  lui   $v0, 0x800e
/* 41E87C 802A9AEC 8C42C4DC */  lw    $v0, -0x3b24($v0)
/* 41E880 802A9AF0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 41E884 802A9AF4 2443FFFE */  addiu $v1, $v0, -2
/* 41E888 802A9AF8 2C6200CC */  sltiu $v0, $v1, 0xcc
/* 41E88C 802A9AFC 10400009 */  beqz  $v0, .L802A9B24
/* 41E890 802A9B00 AFBF0010 */   sw    $ra, 0x10($sp)
/* 41E894 802A9B04 00031080 */  sll   $v0, $v1, 2
/* 41E898 802A9B08 3C01802B */  lui   $at, 0x802b
/* 41E89C 802A9B0C 00220821 */  addu  $at, $at, $v0
/* 41E8A0 802A9B10 8C22C880 */  lw    $v0, -0x3780($at)
/* 41E8A4 802A9B14 00400008 */  jr    $v0
/* 41E8A8 802A9B18 00000000 */   nop   
/* 41E8AC 802A9B1C 0C0A8715 */  jal   func_802A1C54
/* 41E8B0 802A9B20 00000000 */   nop   
.L802A9B24:
/* 41E8B4 802A9B24 8FBF0010 */  lw    $ra, 0x10($sp)
/* 41E8B8 802A9B28 03E00008 */  jr    $ra
/* 41E8BC 802A9B2C 27BD0018 */   addiu $sp, $sp, 0x18

