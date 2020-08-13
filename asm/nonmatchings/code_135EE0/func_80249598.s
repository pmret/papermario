.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80249598
/* 13C8D8 80249598 3C028027 */  lui   $v0, 0x8027
/* 13C8DC 8024959C 8C4200C4 */  lw    $v0, 0xc4($v0)
/* 13C8E0 802495A0 30424000 */  andi  $v0, $v0, 0x4000
/* 13C8E4 802495A4 10400017 */  beqz  $v0, .L80249604
/* 13C8E8 802495A8 00000000 */   nop   
/* 13C8EC 802495AC 3C108027 */  lui   $s0, 0x8027
/* 13C8F0 802495B0 26100398 */  addiu $s0, $s0, 0x398
/* 13C8F4 802495B4 8E020000 */  lw    $v0, ($s0)
/* 13C8F8 802495B8 14400007 */  bnez  $v0, .L802495D8
/* 13C8FC 802495BC 00000000 */   nop   
/* 13C900 802495C0 0C05272D */  jal   play_sound
/* 13C904 802495C4 240400CA */   addiu $a0, $zero, 0xca
/* 13C908 802495C8 3C018027 */  lui   $at, 0x8027
/* 13C90C 802495CC A02000D4 */  sb    $zero, 0xd4($at)
/* 13C910 802495D0 08092581 */  j     func_80249604
/* 13C914 802495D4 00000000 */   nop   

.L802495D8:
/* 13C918 802495D8 0C05272D */  jal   play_sound
/* 13C91C 802495DC 240400CA */   addiu $a0, $zero, 0xca
/* 13C920 802495E0 0C039E1B */  jal   enforce_hpfp_limits
/* 13C924 802495E4 AE000000 */   sw    $zero, ($s0)
/* 13C928 802495E8 3C038027 */  lui   $v1, 0x8027
/* 13C92C 802495EC 8C63039C */  lw    $v1, 0x39c($v1)
/* 13C930 802495F0 24020001 */  addiu $v0, $zero, 1
/* 13C934 802495F4 14620003 */  bne   $v1, $v0, .L80249604
/* 13C938 802495F8 00000000 */   nop   
/* 13C93C 802495FC 0C092363 */  jal   func_80248D8C
/* 13C940 80249600 0040202D */   daddu $a0, $v0, $zero
