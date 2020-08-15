.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_802D585C
/* 0FA20C 802D585C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0FA210 802D5860 AFB10014 */  sw    $s1, 0x14($sp)
/* 0FA214 802D5864 0080882D */  daddu $s1, $a0, $zero
/* 0FA218 802D5868 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0FA21C 802D586C AFB00010 */  sw    $s0, 0x10($sp)
/* 0FA220 802D5870 8E30000C */  lw    $s0, 0xc($s1)
/* 0FA224 802D5874 8E050000 */  lw    $a1, ($s0)
/* 0FA228 802D5878 0C0B1EAF */  jal   get_variable
/* 0FA22C 802D587C 26100004 */   addiu $s0, $s0, 4
/* 0FA230 802D5880 0220202D */  daddu $a0, $s1, $zero
/* 0FA234 802D5884 8E050000 */  lw    $a1, ($s0)
/* 0FA238 802D5888 0C0B1EAF */  jal   get_variable
/* 0FA23C 802D588C 0040802D */   daddu $s0, $v0, $zero
/* 0FA240 802D5890 12000007 */  beqz  $s0, .L802D58B0
/* 0FA244 802D5894 0040202D */   daddu $a0, $v0, $zero
/* 0FA248 802D5898 3C03800A */  lui   $v1, 0x800a
/* 0FA24C 802D589C 2463A650 */  addiu $v1, $v1, -0x59b0
/* 0FA250 802D58A0 8C620000 */  lw    $v0, ($v1)
/* 0FA254 802D58A4 00441025 */  or    $v0, $v0, $a0
/* 0FA258 802D58A8 080B5632 */  j     .L802D58C8
/* 0FA25C 802D58AC AC620000 */   sw    $v0, ($v1)

.L802D58B0:
/* 0FA260 802D58B0 3C02800A */  lui   $v0, 0x800a
/* 0FA264 802D58B4 2442A650 */  addiu $v0, $v0, -0x59b0
/* 0FA268 802D58B8 8C430000 */  lw    $v1, ($v0)
/* 0FA26C 802D58BC 00042027 */  nor   $a0, $zero, $a0
/* 0FA270 802D58C0 00641824 */  and   $v1, $v1, $a0
/* 0FA274 802D58C4 AC430000 */  sw    $v1, ($v0)
.L802D58C8:
/* 0FA278 802D58C8 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0FA27C 802D58CC 8FB10014 */  lw    $s1, 0x14($sp)
/* 0FA280 802D58D0 8FB00010 */  lw    $s0, 0x10($sp)
/* 0FA284 802D58D4 24020002 */  addiu $v0, $zero, 2
/* 0FA288 802D58D8 03E00008 */  jr    $ra
/* 0FA28C 802D58DC 27BD0020 */   addiu $sp, $sp, 0x20

