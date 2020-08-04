.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80249E0C
/* 13D14C 80249E0C 0C04993B */  jal   draw_string
/* 13D150 80249E10 00000000 */   nop   
.L80249E14:
/* 13D154 80249E14 8FAA0050 */  lw    $t2, 0x50($sp)
/* 13D158 80249E18 240B0001 */  addiu $t3, $zero, 1
/* 13D15C 80249E1C 154B0050 */  bne   $t2, $t3, .L80249F60
/* 13D160 80249E20 3C052000 */   lui   $a1, 0x2000
/* 13D164 80249E24 8FAA0078 */  lw    $t2, 0x78($sp)
/* 13D168 80249E28 8D510000 */  lw    $s1, ($t2)
/* 13D16C 80249E2C 0C05128B */  jal   clear_icon_flags
/* 13D170 80249E30 0220202D */   daddu $a0, $s1, $zero
/* 13D174 80249E34 0220202D */  daddu $a0, $s1, $zero
/* 13D178 80249E38 0C051280 */  jal   set_icon_flags
/* 13D17C 80249E3C 34058000 */   ori   $a1, $zero, 0x8000
/* 13D180 80249E40 8FAB0074 */  lw    $t3, 0x74($sp)
/* 13D184 80249E44 11600005 */  beqz  $t3, .L80249E5C
/* 13D188 80249E48 00000000 */   nop   
/* 13D18C 80249E4C 3C118027 */  lui   $s1, 0x8027
/* 13D190 80249E50 8E310634 */  lw    $s1, 0x634($s1)
/* 13D194 80249E54 080927B9 */  j     func_80249EE4
/* 13D198 80249E58 00000000 */   nop   

.L80249E5C:
/* 13D19C 80249E5C 12600010 */  beqz  $s3, .L80249EA0
/* 13D1A0 80249E60 0220202D */   daddu $a0, $s1, $zero
/* 13D1A4 80249E64 0C051280 */  jal   set_icon_flags
/* 13D1A8 80249E68 3C052000 */   lui   $a1, 0x2000
/* 13D1AC 80249E6C 00161400 */  sll   $v0, $s6, 0x10
/* 13D1B0 80249E70 000212C3 */  sra   $v0, $v0, 0xb
/* 13D1B4 80249E74 3C0A8008 */  lui   $t2, 0x8008
/* 13D1B8 80249E78 254A78E0 */  addiu $t2, $t2, 0x78e0
/* 13D1BC 80249E7C 004A1021 */  addu  $v0, $v0, $t2
/* 13D1C0 80249E80 84420004 */  lh    $v0, 4($v0)
/* 13D1C4 80249E84 3C0B8009 */  lui   $t3, 0x8009
/* 13D1C8 80249E88 256BA680 */  addiu $t3, $t3, -0x5980
/* 13D1CC 80249E8C 000210C0 */  sll   $v0, $v0, 3
/* 13D1D0 80249E90 004B1021 */  addu  $v0, $v0, $t3
/* 13D1D4 80249E94 8C420000 */  lw    $v0, ($v0)
/* 13D1D8 80249E98 3C018027 */  lui   $at, 0x8027
/* 13D1DC 80249E9C AC2200CC */  sw    $v0, 0xcc($at)
.L80249EA0:
/* 13D1E0 80249EA0 00161400 */  sll   $v0, $s6, 0x10
/* 13D1E4 80249EA4 000212C3 */  sra   $v0, $v0, 0xb
/* 13D1E8 80249EA8 3C0A8008 */  lui   $t2, 0x8008
/* 13D1EC 80249EAC 254A78E0 */  addiu $t2, $t2, 0x78e0
/* 13D1F0 80249EB0 004A1021 */  addu  $v0, $v0, $t2
/* 13D1F4 80249EB4 84420004 */  lh    $v0, 4($v0)
/* 13D1F8 80249EB8 3C0B8009 */  lui   $t3, 0x8009
/* 13D1FC 80249EBC 256BA680 */  addiu $t3, $t3, -0x5980
/* 13D200 80249EC0 000210C0 */  sll   $v0, $v0, 3
/* 13D204 80249EC4 004B1021 */  addu  $v0, $v0, $t3
/* 13D208 80249EC8 8C450000 */  lw    $a1, ($v0)
/* 13D20C 80249ECC 0C0511FF */  jal   set_menu_icon_script
/* 13D210 80249ED0 0220202D */   daddu $a0, $s1, $zero
/* 13D214 80249ED4 3C053F2B */  lui   $a1, 0x3f2b
/* 13D218 80249ED8 34A5BA99 */  ori   $a1, $a1, 0xba99
/* 13D21C 80249EDC 0C051308 */  jal   func_80144C20
/* 13D220 80249EE0 0220202D */   daddu $a0, $s1, $zero
