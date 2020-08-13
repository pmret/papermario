.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel GetDist2D
/* 0FA120 802D5770 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0FA124 802D5774 AFB10014 */  sw    $s1, 0x14($sp)
/* 0FA128 802D5778 0080882D */  daddu $s1, $a0, $zero
/* 0FA12C 802D577C AFBF001C */  sw    $ra, 0x1c($sp)
/* 0FA130 802D5780 AFB20018 */  sw    $s2, 0x18($sp)
/* 0FA134 802D5784 AFB00010 */  sw    $s0, 0x10($sp)
/* 0FA138 802D5788 F7B80030 */  sdc1  $f24, 0x30($sp)
/* 0FA13C 802D578C F7B60028 */  sdc1  $f22, 0x28($sp)
/* 0FA140 802D5790 F7B40020 */  sdc1  $f20, 0x20($sp)
/* 0FA144 802D5794 8E30000C */  lw    $s0, 0xc($s1)
/* 0FA148 802D5798 8E120000 */  lw    $s2, ($s0)
/* 0FA14C 802D579C 26100004 */  addiu $s0, $s0, 4
/* 0FA150 802D57A0 8E050000 */  lw    $a1, ($s0)
/* 0FA154 802D57A4 0C0B210B */  jal   get_float_variable
/* 0FA158 802D57A8 26100004 */   addiu $s0, $s0, 4
/* 0FA15C 802D57AC 8E050000 */  lw    $a1, ($s0)
/* 0FA160 802D57B0 26100004 */  addiu $s0, $s0, 4
/* 0FA164 802D57B4 0220202D */  daddu $a0, $s1, $zero
/* 0FA168 802D57B8 0C0B210B */  jal   get_float_variable
/* 0FA16C 802D57BC 46000606 */   mov.s $f24, $f0
/* 0FA170 802D57C0 8E050000 */  lw    $a1, ($s0)
/* 0FA174 802D57C4 26100004 */  addiu $s0, $s0, 4
/* 0FA178 802D57C8 0220202D */  daddu $a0, $s1, $zero
/* 0FA17C 802D57CC 0C0B210B */  jal   get_float_variable
/* 0FA180 802D57D0 46000586 */   mov.s $f22, $f0
/* 0FA184 802D57D4 0220202D */  daddu $a0, $s1, $zero
/* 0FA188 802D57D8 8E050000 */  lw    $a1, ($s0)
/* 0FA18C 802D57DC 0C0B210B */  jal   get_float_variable
/* 0FA190 802D57E0 46000506 */   mov.s $f20, $f0
/* 0FA194 802D57E4 4600C306 */  mov.s $f12, $f24
/* 0FA198 802D57E8 4406A000 */  mfc1  $a2, $f20
/* 0FA19C 802D57EC 44070000 */  mfc1  $a3, $f0
/* 0FA1A0 802D57F0 0C00A7B5 */  jal   dist2D
/* 0FA1A4 802D57F4 4600B386 */   mov.s $f14, $f22
/* 0FA1A8 802D57F8 0220202D */  daddu $a0, $s1, $zero
/* 0FA1AC 802D57FC 44060000 */  mfc1  $a2, $f0
/* 0FA1B0 802D5800 0C0B2190 */  jal   set_float_variable
/* 0FA1B4 802D5804 0240282D */   daddu $a1, $s2, $zero
/* 0FA1B8 802D5808 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0FA1BC 802D580C 8FB20018 */  lw    $s2, 0x18($sp)
/* 0FA1C0 802D5810 8FB10014 */  lw    $s1, 0x14($sp)
/* 0FA1C4 802D5814 8FB00010 */  lw    $s0, 0x10($sp)
/* 0FA1C8 802D5818 D7B80030 */  ldc1  $f24, 0x30($sp)
/* 0FA1CC 802D581C D7B60028 */  ldc1  $f22, 0x28($sp)
/* 0FA1D0 802D5820 D7B40020 */  ldc1  $f20, 0x20($sp)
/* 0FA1D4 802D5824 24020002 */  addiu $v0, $zero, 2
/* 0FA1D8 802D5828 03E00008 */  jr    $ra
/* 0FA1DC 802D582C 27BD0038 */   addiu $sp, $sp, 0x38

/* 0FA1E0 802D5830 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0FA1E4 802D5834 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0FA1E8 802D5838 8C82000C */  lw    $v0, 0xc($a0)
/* 0FA1EC 802D583C 0C0B1EAF */  jal   get_variable
/* 0FA1F0 802D5840 8C450000 */   lw    $a1, ($v0)
/* 0FA1F4 802D5844 0C009C22 */  jal   func_80027088
/* 0FA1F8 802D5848 0040202D */   daddu $a0, $v0, $zero
/* 0FA1FC 802D584C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0FA200 802D5850 24020002 */  addiu $v0, $zero, 2
/* 0FA204 802D5854 03E00008 */  jr    $ra
/* 0FA208 802D5858 27BD0018 */   addiu $sp, $sp, 0x18

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

