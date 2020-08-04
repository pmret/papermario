.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel status_menu_draw_number
/* 081154 800E7CA4 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 081158 800E7CA8 AFB1001C */  sw    $s1, 0x1c($sp)
/* 08115C 800E7CAC 00A0882D */  daddu $s1, $a1, $zero
/* 081160 800E7CB0 3C05800F */  lui   $a1, 0x800f
/* 081164 800E7CB4 8CA57FA8 */  lw    $a1, 0x7fa8($a1)
/* 081168 800E7CB8 AFB40028 */  sw    $s4, 0x28($sp)
/* 08116C 800E7CBC 0080A02D */  daddu $s4, $a0, $zero
/* 081170 800E7CC0 AFB00018 */  sw    $s0, 0x18($sp)
/* 081174 800E7CC4 00C0802D */  daddu $s0, $a2, $zero
/* 081178 800E7CC8 AFB30024 */  sw    $s3, 0x24($sp)
/* 08117C 800E7CCC 00E0982D */  daddu $s3, $a3, $zero
/* 081180 800E7CD0 AFB5002C */  sw    $s5, 0x2c($sp)
/* 081184 800E7CD4 8FB50050 */  lw    $s5, 0x50($sp)
/* 081188 800E7CD8 AFB20020 */  sw    $s2, 0x20($sp)
/* 08118C 800E7CDC 0000902D */  daddu $s2, $zero, $zero
/* 081190 800E7CE0 AFBF003C */  sw    $ra, 0x3c($sp)
/* 081194 800E7CE4 AFBE0038 */  sw    $fp, 0x38($sp)
/* 081198 800E7CE8 AFB70034 */  sw    $s7, 0x34($sp)
/* 08119C 800E7CEC 0C0511FF */  jal   set_menu_icon_script
/* 0811A0 800E7CF0 AFB60030 */   sw    $s6, 0x30($sp)
/* 0811A4 800E7CF4 26310008 */  addiu $s1, $s1, 8
/* 0811A8 800E7CF8 0280202D */  daddu $a0, $s4, $zero
/* 0811AC 800E7CFC 0220282D */  daddu $a1, $s1, $zero
/* 0811B0 800E7D00 26060007 */  addiu $a2, $s0, 7
/* 0811B4 800E7D04 0C051261 */  jal   set_icon_render_pos
/* 0811B8 800E7D08 261E0008 */   addiu $fp, $s0, 8
/* 0811BC 800E7D0C 0280202D */  daddu $a0, $s4, $zero
/* 0811C0 800E7D10 0C05128B */  jal   clear_icon_flags
/* 0811C4 800E7D14 24050002 */   addiu $a1, $zero, 2
/* 0811C8 800E7D18 0C0511F1 */  jal   draw_icon_1
/* 0811CC 800E7D1C 0280202D */   daddu $a0, $s4, $zero
/* 0811D0 800E7D20 5AA00016 */  blezl $s5, .L800E7D7C
/* 0811D4 800E7D24 2631000D */   addiu $s1, $s1, 0xd
/* 0811D8 800E7D28 3C066666 */  lui   $a2, 0x6666
/* 0811DC 800E7D2C 34C66667 */  ori   $a2, $a2, 0x6667
/* 0811E0 800E7D30 27A50010 */  addiu $a1, $sp, 0x10
.L800E7D34:
/* 0811E4 800E7D34 02660018 */  mult  $s3, $a2
/* 0811E8 800E7D38 02B22023 */  subu  $a0, $s5, $s2
/* 0811EC 800E7D3C 26520001 */  addiu $s2, $s2, 1
/* 0811F0 800E7D40 001317C3 */  sra   $v0, $s3, 0x1f
/* 0811F4 800E7D44 00852021 */  addu  $a0, $a0, $a1
/* 0811F8 800E7D48 00004010 */  mfhi  $t0
/* 0811FC 800E7D4C 00081883 */  sra   $v1, $t0, 2
/* 081200 800E7D50 00621023 */  subu  $v0, $v1, $v0
/* 081204 800E7D54 0040182D */  daddu $v1, $v0, $zero
/* 081208 800E7D58 00031080 */  sll   $v0, $v1, 2
/* 08120C 800E7D5C 00431021 */  addu  $v0, $v0, $v1
/* 081210 800E7D60 00021040 */  sll   $v0, $v0, 1
/* 081214 800E7D64 02621023 */  subu  $v0, $s3, $v0
/* 081218 800E7D68 A082FFFF */  sb    $v0, -1($a0)
/* 08121C 800E7D6C 0255102A */  slt   $v0, $s2, $s5
/* 081220 800E7D70 1440FFF0 */  bnez  $v0, .L800E7D34
/* 081224 800E7D74 0060982D */   daddu $s3, $v1, $zero
/* 081228 800E7D78 2631000D */  addiu $s1, $s1, 0xd
.L800E7D7C:
/* 08122C 800E7D7C 0000982D */  daddu $s3, $zero, $zero
/* 081230 800E7D80 1AA00020 */  blez  $s5, .L800E7E04
/* 081234 800E7D84 0260902D */   daddu $s2, $s3, $zero
/* 081238 800E7D88 27B60010 */  addiu $s6, $sp, 0x10
/* 08123C 800E7D8C 26B0FFFF */  addiu $s0, $s5, -1
/* 081240 800E7D90 3C17800F */  lui   $s7, 0x800f
/* 081244 800E7D94 26F77F80 */  addiu $s7, $s7, 0x7f80
.L800E7D98:
/* 081248 800E7D98 02D21021 */  addu  $v0, $s6, $s2
/* 08124C 800E7D9C 80420000 */  lb    $v0, ($v0)
/* 081250 800E7DA0 54400006 */  bnezl $v0, .L800E7DBC
/* 081254 800E7DA4 24130001 */   addiu $s3, $zero, 1
/* 081258 800E7DA8 56600004 */  bnezl $s3, .L800E7DBC
/* 08125C 800E7DAC 24130001 */   addiu $s3, $zero, 1
/* 081260 800E7DB0 56500011 */  bnel  $s2, $s0, .L800E7DF8
/* 081264 800E7DB4 26520001 */   addiu $s2, $s2, 1
/* 081268 800E7DB8 24130001 */  addiu $s3, $zero, 1
.L800E7DBC:
/* 08126C 800E7DBC 00021080 */  sll   $v0, $v0, 2
/* 081270 800E7DC0 00571021 */  addu  $v0, $v0, $s7
/* 081274 800E7DC4 8C450000 */  lw    $a1, ($v0)
/* 081278 800E7DC8 0C0511FF */  jal   set_menu_icon_script
/* 08127C 800E7DCC 0280202D */   daddu $a0, $s4, $zero
/* 081280 800E7DD0 0280202D */  daddu $a0, $s4, $zero
/* 081284 800E7DD4 0220282D */  daddu $a1, $s1, $zero
/* 081288 800E7DD8 0C051261 */  jal   set_icon_render_pos
/* 08128C 800E7DDC 03C0302D */   daddu $a2, $fp, $zero
/* 081290 800E7DE0 0280202D */  daddu $a0, $s4, $zero
/* 081294 800E7DE4 0C05128B */  jal   clear_icon_flags
/* 081298 800E7DE8 24050002 */   addiu $a1, $zero, 2
/* 08129C 800E7DEC 0C0511F1 */  jal   draw_icon_1
/* 0812A0 800E7DF0 0280202D */   daddu $a0, $s4, $zero
/* 0812A4 800E7DF4 26520001 */  addiu $s2, $s2, 1
.L800E7DF8:
/* 0812A8 800E7DF8 0255102A */  slt   $v0, $s2, $s5
/* 0812AC 800E7DFC 1440FFE6 */  bnez  $v0, .L800E7D98
/* 0812B0 800E7E00 26310008 */   addiu $s1, $s1, 8
.L800E7E04:
/* 0812B4 800E7E04 8FBF003C */  lw    $ra, 0x3c($sp)
/* 0812B8 800E7E08 8FBE0038 */  lw    $fp, 0x38($sp)
/* 0812BC 800E7E0C 8FB70034 */  lw    $s7, 0x34($sp)
/* 0812C0 800E7E10 8FB60030 */  lw    $s6, 0x30($sp)
/* 0812C4 800E7E14 8FB5002C */  lw    $s5, 0x2c($sp)
/* 0812C8 800E7E18 8FB40028 */  lw    $s4, 0x28($sp)
/* 0812CC 800E7E1C 8FB30024 */  lw    $s3, 0x24($sp)
/* 0812D0 800E7E20 8FB20020 */  lw    $s2, 0x20($sp)
/* 0812D4 800E7E24 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0812D8 800E7E28 8FB00018 */  lw    $s0, 0x18($sp)
/* 0812DC 800E7E2C 03E00008 */  jr    $ra
/* 0812E0 800E7E30 27BD0040 */   addiu $sp, $sp, 0x40

