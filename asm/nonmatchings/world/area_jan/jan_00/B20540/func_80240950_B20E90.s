.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240950_B20E90
/* B20E90 80240950 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* B20E94 80240954 AFB1001C */  sw        $s1, 0x1c($sp)
/* B20E98 80240958 0080882D */  daddu     $s1, $a0, $zero
/* B20E9C 8024095C AFBF0034 */  sw        $ra, 0x34($sp)
/* B20EA0 80240960 AFB60030 */  sw        $s6, 0x30($sp)
/* B20EA4 80240964 AFB5002C */  sw        $s5, 0x2c($sp)
/* B20EA8 80240968 AFB40028 */  sw        $s4, 0x28($sp)
/* B20EAC 8024096C AFB30024 */  sw        $s3, 0x24($sp)
/* B20EB0 80240970 AFB20020 */  sw        $s2, 0x20($sp)
/* B20EB4 80240974 AFB00018 */  sw        $s0, 0x18($sp)
/* B20EB8 80240978 F7B60040 */  sdc1      $f22, 0x40($sp)
/* B20EBC 8024097C F7B40038 */  sdc1      $f20, 0x38($sp)
/* B20EC0 80240980 8E30000C */  lw        $s0, 0xc($s1)
/* B20EC4 80240984 8E160000 */  lw        $s6, ($s0)
/* B20EC8 80240988 26100004 */  addiu     $s0, $s0, 4
/* B20ECC 8024098C 0C0B1EAF */  jal       get_variable
/* B20ED0 80240990 02C0282D */   daddu    $a1, $s6, $zero
/* B20ED4 80240994 44820000 */  mtc1      $v0, $f0
/* B20ED8 80240998 00000000 */  nop       
/* B20EDC 8024099C 46800020 */  cvt.s.w   $f0, $f0
/* B20EE0 802409A0 E7A00010 */  swc1      $f0, 0x10($sp)
/* B20EE4 802409A4 8E140000 */  lw        $s4, ($s0)
/* B20EE8 802409A8 26100004 */  addiu     $s0, $s0, 4
/* B20EEC 802409AC 0220202D */  daddu     $a0, $s1, $zero
/* B20EF0 802409B0 0C0B1EAF */  jal       get_variable
/* B20EF4 802409B4 0280282D */   daddu    $a1, $s4, $zero
/* B20EF8 802409B8 0220202D */  daddu     $a0, $s1, $zero
/* B20EFC 802409BC 8E150000 */  lw        $s5, ($s0)
/* B20F00 802409C0 4482B000 */  mtc1      $v0, $f22
/* B20F04 802409C4 00000000 */  nop       
/* B20F08 802409C8 4680B5A0 */  cvt.s.w   $f22, $f22
/* B20F0C 802409CC 0C0B1EAF */  jal       get_variable
/* B20F10 802409D0 02A0282D */   daddu    $a1, $s5, $zero
/* B20F14 802409D4 2404FFFC */  addiu     $a0, $zero, -4
/* B20F18 802409D8 44820000 */  mtc1      $v0, $f0
/* B20F1C 802409DC 00000000 */  nop       
/* B20F20 802409E0 46800020 */  cvt.s.w   $f0, $f0
/* B20F24 802409E4 0C00EABB */  jal       get_npc_unsafe
/* B20F28 802409E8 E7A00014 */   swc1     $f0, 0x14($sp)
/* B20F2C 802409EC 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* B20F30 802409F0 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* B20F34 802409F4 3C014334 */  lui       $at, 0x4334
/* B20F38 802409F8 44816000 */  mtc1      $at, $f12
/* B20F3C 802409FC 00041880 */  sll       $v1, $a0, 2
/* B20F40 80240A00 00641821 */  addu      $v1, $v1, $a0
/* B20F44 80240A04 00031880 */  sll       $v1, $v1, 2
/* B20F48 80240A08 00641823 */  subu      $v1, $v1, $a0
/* B20F4C 80240A0C 000320C0 */  sll       $a0, $v1, 3
/* B20F50 80240A10 00641821 */  addu      $v1, $v1, $a0
/* B20F54 80240A14 000318C0 */  sll       $v1, $v1, 3
/* B20F58 80240A18 3C01800B */  lui       $at, 0x800b
/* B20F5C 80240A1C 00230821 */  addu      $at, $at, $v1
/* B20F60 80240A20 C4201DEC */  lwc1      $f0, 0x1dec($at)
/* B20F64 80240A24 460C0300 */  add.s     $f12, $f0, $f12
/* B20F68 80240A28 0C00A6C9 */  jal       clamp_angle
/* B20F6C 80240A2C 0040982D */   daddu    $s3, $v0, $zero
/* B20F70 80240A30 27B00010 */  addiu     $s0, $sp, 0x10
/* B20F74 80240A34 0200202D */  daddu     $a0, $s0, $zero
/* B20F78 80240A38 27B20014 */  addiu     $s2, $sp, 0x14
/* B20F7C 80240A3C 0240282D */  daddu     $a1, $s2, $zero
/* B20F80 80240A40 3C064170 */  lui       $a2, 0x4170
/* B20F84 80240A44 8E67000C */  lw        $a3, 0xc($s3)
/* B20F88 80240A48 0C00A7E7 */  jal       add_vec2D_polar
/* B20F8C 80240A4C 46000506 */   mov.s    $f20, $f0
/* B20F90 80240A50 0200202D */  daddu     $a0, $s0, $zero
/* B20F94 80240A54 3C064120 */  lui       $a2, 0x4120
/* B20F98 80240A58 4407A000 */  mfc1      $a3, $f20
/* B20F9C 80240A5C 0C00A7E7 */  jal       add_vec2D_polar
/* B20FA0 80240A60 0240282D */   daddu    $a1, $s2, $zero
/* B20FA4 80240A64 0220202D */  daddu     $a0, $s1, $zero
/* B20FA8 80240A68 C7A00010 */  lwc1      $f0, 0x10($sp)
/* B20FAC 80240A6C 4600008D */  trunc.w.s $f2, $f0
/* B20FB0 80240A70 44061000 */  mfc1      $a2, $f2
/* B20FB4 80240A74 0C0B2026 */  jal       set_variable
/* B20FB8 80240A78 02C0282D */   daddu    $a1, $s6, $zero
/* B20FBC 80240A7C 0220202D */  daddu     $a0, $s1, $zero
/* B20FC0 80240A80 4600B08D */  trunc.w.s $f2, $f22
/* B20FC4 80240A84 44061000 */  mfc1      $a2, $f2
/* B20FC8 80240A88 0C0B2026 */  jal       set_variable
/* B20FCC 80240A8C 0280282D */   daddu    $a1, $s4, $zero
/* B20FD0 80240A90 0220202D */  daddu     $a0, $s1, $zero
/* B20FD4 80240A94 C7A00014 */  lwc1      $f0, 0x14($sp)
/* B20FD8 80240A98 4600008D */  trunc.w.s $f2, $f0
/* B20FDC 80240A9C 44061000 */  mfc1      $a2, $f2
/* B20FE0 80240AA0 0C0B2026 */  jal       set_variable
/* B20FE4 80240AA4 02A0282D */   daddu    $a1, $s5, $zero
/* B20FE8 80240AA8 8FBF0034 */  lw        $ra, 0x34($sp)
/* B20FEC 80240AAC 8FB60030 */  lw        $s6, 0x30($sp)
/* B20FF0 80240AB0 8FB5002C */  lw        $s5, 0x2c($sp)
/* B20FF4 80240AB4 8FB40028 */  lw        $s4, 0x28($sp)
/* B20FF8 80240AB8 8FB30024 */  lw        $s3, 0x24($sp)
/* B20FFC 80240ABC 8FB20020 */  lw        $s2, 0x20($sp)
/* B21000 80240AC0 8FB1001C */  lw        $s1, 0x1c($sp)
/* B21004 80240AC4 8FB00018 */  lw        $s0, 0x18($sp)
/* B21008 80240AC8 D7B60040 */  ldc1      $f22, 0x40($sp)
/* B2100C 80240ACC D7B40038 */  ldc1      $f20, 0x38($sp)
/* B21010 80240AD0 24020002 */  addiu     $v0, $zero, 2
/* B21014 80240AD4 03E00008 */  jr        $ra
/* B21018 80240AD8 27BD0048 */   addiu    $sp, $sp, 0x48
