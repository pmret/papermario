.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel si_goto_label
/* 0ED240 802C8890 8C86000C */  lw    $a2, 0xc($a0)
/* 0ED244 802C8894 3C02EFE8 */  lui   $v0, 0xefe8
/* 0ED248 802C8898 34422080 */  ori   $v0, $v0, 0x2080
/* 0ED24C 802C889C 00A2102A */  slt   $v0, $a1, $v0
/* 0ED250 802C88A0 10400007 */  beqz  $v0, .L802C88C0
/* 0ED254 802C88A4 0000182D */   daddu $v1, $zero, $zero
/* 0ED258 802C88A8 03E00008 */  jr    $ra
/* 0ED25C 802C88AC 00A0102D */   daddu $v0, $a1, $zero

.L802C88B0:
/* 0ED260 802C88B0 00821021 */  addu  $v0, $a0, $v0
/* 0ED264 802C88B4 8C460020 */  lw    $a2, 0x20($v0)
/* 0ED268 802C88B8 080B2239 */  j     .L802C88E4
/* 0ED26C 802C88BC 28620010 */   slti  $v0, $v1, 0x10

.L802C88C0:
/* 0ED270 802C88C0 00831021 */  addu  $v0, $a0, $v1
.L802C88C4:
/* 0ED274 802C88C4 80420010 */  lb    $v0, 0x10($v0)
/* 0ED278 802C88C8 1045FFF9 */  beq   $v0, $a1, .L802C88B0
/* 0ED27C 802C88CC 00031080 */   sll   $v0, $v1, 2
/* 0ED280 802C88D0 24630001 */  addiu $v1, $v1, 1
/* 0ED284 802C88D4 28620010 */  slti  $v0, $v1, 0x10
/* 0ED288 802C88D8 1440FFFA */  bnez  $v0, .L802C88C4
/* 0ED28C 802C88DC 00831021 */   addu  $v0, $a0, $v1
/* 0ED290 802C88E0 28620010 */  slti  $v0, $v1, 0x10
.L802C88E4:
/* 0ED294 802C88E4 14400003 */  bnez  $v0, .L802C88F4
/* 0ED298 802C88E8 00000000 */   nop   
.L802C88EC:
/* 0ED29C 802C88EC 080B223B */  j     .L802C88EC
/* 0ED2A0 802C88F0 00000000 */   nop   

.L802C88F4:
/* 0ED2A4 802C88F4 03E00008 */  jr    $ra
/* 0ED2A8 802C88F8 00C0102D */   daddu $v0, $a2, $zero

