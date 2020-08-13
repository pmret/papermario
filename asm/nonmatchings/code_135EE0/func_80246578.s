.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80246578
/* 1398B8 80246578 0276102A */  slt   $v0, $s3, $s6
/* 1398BC 8024657C 10400056 */  beqz  $v0, .L802466D8
/* 1398C0 80246580 26520001 */   addiu $s2, $s2, 1
/* 1398C4 80246584 26730001 */  addiu $s3, $s3, 1
/* 1398C8 80246588 00158080 */  sll   $s0, $s5, 2
/* 1398CC 8024658C 3C058025 */  lui   $a1, 0x8025
/* 1398D0 80246590 00B02821 */  addu  $a1, $a1, $s0
/* 1398D4 80246594 8CA5F434 */  lw    $a1, -0xbcc($a1)
/* 1398D8 80246598 0C0511FF */  jal   set_menu_icon_script
/* 1398DC 8024659C 0220202D */   daddu $a0, $s1, $zero
/* 1398E0 802465A0 0220202D */  daddu $a0, $s1, $zero
/* 1398E4 802465A4 27C6004B */  addiu $a2, $fp, 0x4b
/* 1398E8 802465A8 02158021 */  addu  $s0, $s0, $s5
/* 1398EC 802465AC 00108080 */  sll   $s0, $s0, 2
/* 1398F0 802465B0 2610008C */  addiu $s0, $s0, 0x8c
/* 1398F4 802465B4 8FA80084 */  lw    $t0, 0x84($sp)
/* 1398F8 802465B8 3C058025 */  lui   $a1, 0x8025
/* 1398FC 802465BC 8CA5F480 */  lw    $a1, -0xb80($a1)
/* 139900 802465C0 01108021 */  addu  $s0, $t0, $s0
/* 139904 802465C4 0C051261 */  jal   set_icon_render_pos
/* 139908 802465C8 02052821 */   addu  $a1, $s0, $a1
/* 13990C 802465CC 12800005 */  beqz  $s4, .L802465E4
/* 139910 802465D0 00000000 */   nop   
/* 139914 802465D4 0C0511F8 */  jal   func_801447E0
/* 139918 802465D8 0220202D */   daddu $a0, $s1, $zero
/* 13991C 802465DC 0809197B */  j     func_802465EC
/* 139920 802465E0 0000A02D */   daddu $s4, $zero, $zero

.L802465E4:
/* 139924 802465E4 0C0511F1 */  jal   draw_icon_1
/* 139928 802465E8 0220202D */   daddu $a0, $s1, $zero
