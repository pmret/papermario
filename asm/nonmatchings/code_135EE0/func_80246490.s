.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80246490
/* 1397D0 80246490 0276102A */  slt   $v0, $s3, $s6
/* 1397D4 80246494 10400090 */  beqz  $v0, .L802466D8
/* 1397D8 80246498 26520001 */   addiu $s2, $s2, 1
/* 1397DC 8024649C 26730001 */  addiu $s3, $s3, 1
/* 1397E0 802464A0 00158080 */  sll   $s0, $s5, 2
/* 1397E4 802464A4 3C058025 */  lui   $a1, 0x8025
/* 1397E8 802464A8 00B02821 */  addu  $a1, $a1, $s0
/* 1397EC 802464AC 8CA5F434 */  lw    $a1, -0xbcc($a1)
/* 1397F0 802464B0 0C0511FF */  jal   set_menu_icon_script
/* 1397F4 802464B4 0220202D */   daddu $a0, $s1, $zero
/* 1397F8 802464B8 0220202D */  daddu $a0, $s1, $zero
/* 1397FC 802464BC 27C6004B */  addiu $a2, $fp, 0x4b
/* 139800 802464C0 02158021 */  addu  $s0, $s0, $s5
/* 139804 802464C4 00108080 */  sll   $s0, $s0, 2
/* 139808 802464C8 2610008C */  addiu $s0, $s0, 0x8c
/* 13980C 802464CC 8FA80084 */  lw    $t0, 0x84($sp)
/* 139810 802464D0 3C058025 */  lui   $a1, 0x8025
/* 139814 802464D4 8CA5F478 */  lw    $a1, -0xb88($a1)
/* 139818 802464D8 01108021 */  addu  $s0, $t0, $s0
/* 13981C 802464DC 0C051261 */  jal   set_icon_render_pos
/* 139820 802464E0 02052821 */   addu  $a1, $s0, $a1
/* 139824 802464E4 12800005 */  beqz  $s4, .L802464FC
/* 139828 802464E8 00000000 */   nop   
/* 13982C 802464EC 0C0511F8 */  jal   func_801447E0
/* 139830 802464F0 0220202D */   daddu $a0, $s1, $zero
/* 139834 802464F4 08091941 */  j     func_80246504
/* 139838 802464F8 0000A02D */   daddu $s4, $zero, $zero

.L802464FC:
/* 13983C 802464FC 0C0511F1 */  jal   draw_icon_1
/* 139840 80246500 0220202D */   daddu $a0, $s1, $zero
