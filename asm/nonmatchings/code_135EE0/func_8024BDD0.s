.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8024BDD0
.L8024BDD0:
/* 13F110 8024BDD0 0000902D */  daddu $s2, $zero, $zero
/* 13F114 8024BDD4 2417001D */  addiu $s7, $zero, 0x1d
/* 13F118 8024BDD8 24140016 */  addiu $s4, $zero, 0x16
/* 13F11C 8024BDDC 2416001C */  addiu $s6, $zero, 0x1c
/* 13F120 8024BDE0 8FA80054 */  lw    $t0, 0x54($sp)
/* 13F124 8024BDE4 24130002 */  addiu $s3, $zero, 2
/* 13F128 8024BDE8 25080015 */  addiu $t0, $t0, 0x15
/* 13F12C 8024BDEC AFA80020 */  sw    $t0, 0x20($sp)
.L8024BDF0:
/* 13F130 8024BDF0 0255102A */  slt   $v0, $s2, $s5
/* 13F134 8024BDF4 1040006D */  beqz  $v0, .L8024BFAC
/* 13F138 8024BDF8 03D43021 */   addu  $a2, $fp, $s4
/* 13F13C 8024BDFC 16400011 */  bnez  $s2, .L8024BE44
/* 13F140 8024BE00 00000000 */   nop   
/* 13F144 8024BE04 3C028027 */  lui   $v0, 0x8027
/* 13F148 8024BE08 8C4206A0 */  lw    $v0, 0x6a0($v0)
/* 13F14C 8024BE0C 3C088027 */  lui   $t0, 0x8027
/* 13F150 8024BE10 25080680 */  addiu $t0, $t0, 0x680
/* 13F154 8024BE14 00021080 */  sll   $v0, $v0, 2
/* 13F158 8024BE18 00481021 */  addu  $v0, $v0, $t0
/* 13F15C 8024BE1C 8C420000 */  lw    $v0, ($v0)
/* 13F160 8024BE20 3C088025 */  lui   $t0, 0x8025
/* 13F164 8024BE24 2508F6F0 */  addiu $t0, $t0, -0x910
/* 13F168 8024BE28 00021080 */  sll   $v0, $v0, 2
/* 13F16C 8024BE2C 00481021 */  addu  $v0, $v0, $t0
/* 13F170 8024BE30 8C430000 */  lw    $v1, ($v0)
/* 13F174 8024BE34 3C088009 */  lui   $t0, 0x8009
/* 13F178 8024BE38 2508F060 */  addiu $t0, $t0, -0xfa0
/* 13F17C 8024BE3C 08092FA1 */  j     func_8024BE84
/* 13F180 8024BE40 00031080 */   sll   $v0, $v1, 2

.L8024BE44:
/* 13F184 8024BE44 3C028027 */  lui   $v0, 0x8027
/* 13F188 8024BE48 8C4206A0 */  lw    $v0, 0x6a0($v0)
/* 13F18C 8024BE4C 3C088027 */  lui   $t0, 0x8027
/* 13F190 8024BE50 25080680 */  addiu $t0, $t0, 0x680
/* 13F194 8024BE54 00021080 */  sll   $v0, $v0, 2
/* 13F198 8024BE58 00481021 */  addu  $v0, $v0, $t0
/* 13F19C 8024BE5C 8C420000 */  lw    $v0, ($v0)
/* 13F1A0 8024BE60 3C088025 */  lui   $t0, 0x8025
/* 13F1A4 8024BE64 2508F6F0 */  addiu $t0, $t0, -0x910
/* 13F1A8 8024BE68 00021080 */  sll   $v0, $v0, 2
/* 13F1AC 8024BE6C 00481021 */  addu  $v0, $v0, $t0
/* 13F1B0 8024BE70 8C430000 */  lw    $v1, ($v0)
/* 13F1B4 8024BE74 3C088009 */  lui   $t0, 0x8009
/* 13F1B8 8024BE78 2508F060 */  addiu $t0, $t0, -0xfa0
/* 13F1BC 8024BE7C 00731821 */  addu  $v1, $v1, $s3
/* 13F1C0 8024BE80 00031080 */  sll   $v0, $v1, 2
