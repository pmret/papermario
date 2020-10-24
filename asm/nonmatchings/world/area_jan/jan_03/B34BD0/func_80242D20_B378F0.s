.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242D20_B378F0
/* B378F0 80242D20 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* B378F4 80242D24 AFB1001C */  sw        $s1, 0x1c($sp)
/* B378F8 80242D28 0080882D */  daddu     $s1, $a0, $zero
/* B378FC 80242D2C AFBF0034 */  sw        $ra, 0x34($sp)
/* B37900 80242D30 AFB60030 */  sw        $s6, 0x30($sp)
/* B37904 80242D34 AFB5002C */  sw        $s5, 0x2c($sp)
/* B37908 80242D38 AFB40028 */  sw        $s4, 0x28($sp)
/* B3790C 80242D3C AFB30024 */  sw        $s3, 0x24($sp)
/* B37910 80242D40 AFB20020 */  sw        $s2, 0x20($sp)
/* B37914 80242D44 AFB00018 */  sw        $s0, 0x18($sp)
/* B37918 80242D48 F7B60040 */  sdc1      $f22, 0x40($sp)
/* B3791C 80242D4C F7B40038 */  sdc1      $f20, 0x38($sp)
/* B37920 80242D50 8E30000C */  lw        $s0, 0xc($s1)
/* B37924 80242D54 8E160000 */  lw        $s6, ($s0)
/* B37928 80242D58 26100004 */  addiu     $s0, $s0, 4
/* B3792C 80242D5C 0C0B1EAF */  jal       get_variable
/* B37930 80242D60 02C0282D */   daddu    $a1, $s6, $zero
/* B37934 80242D64 44820000 */  mtc1      $v0, $f0
/* B37938 80242D68 00000000 */  nop       
/* B3793C 80242D6C 46800020 */  cvt.s.w   $f0, $f0
/* B37940 80242D70 E7A00010 */  swc1      $f0, 0x10($sp)
/* B37944 80242D74 8E140000 */  lw        $s4, ($s0)
/* B37948 80242D78 26100004 */  addiu     $s0, $s0, 4
/* B3794C 80242D7C 0220202D */  daddu     $a0, $s1, $zero
/* B37950 80242D80 0C0B1EAF */  jal       get_variable
/* B37954 80242D84 0280282D */   daddu    $a1, $s4, $zero
/* B37958 80242D88 0220202D */  daddu     $a0, $s1, $zero
/* B3795C 80242D8C 8E150000 */  lw        $s5, ($s0)
/* B37960 80242D90 4482B000 */  mtc1      $v0, $f22
/* B37964 80242D94 00000000 */  nop       
/* B37968 80242D98 4680B5A0 */  cvt.s.w   $f22, $f22
/* B3796C 80242D9C 0C0B1EAF */  jal       get_variable
/* B37970 80242DA0 02A0282D */   daddu    $a1, $s5, $zero
/* B37974 80242DA4 2404FFFC */  addiu     $a0, $zero, -4
/* B37978 80242DA8 44820000 */  mtc1      $v0, $f0
/* B3797C 80242DAC 00000000 */  nop       
/* B37980 80242DB0 46800020 */  cvt.s.w   $f0, $f0
/* B37984 80242DB4 0C00EABB */  jal       get_npc_unsafe
/* B37988 80242DB8 E7A00014 */   swc1     $f0, 0x14($sp)
/* B3798C 80242DBC 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* B37990 80242DC0 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* B37994 80242DC4 3C014334 */  lui       $at, 0x4334
/* B37998 80242DC8 44816000 */  mtc1      $at, $f12
/* B3799C 80242DCC 00041880 */  sll       $v1, $a0, 2
/* B379A0 80242DD0 00641821 */  addu      $v1, $v1, $a0
/* B379A4 80242DD4 00031880 */  sll       $v1, $v1, 2
/* B379A8 80242DD8 00641823 */  subu      $v1, $v1, $a0
/* B379AC 80242DDC 000320C0 */  sll       $a0, $v1, 3
/* B379B0 80242DE0 00641821 */  addu      $v1, $v1, $a0
/* B379B4 80242DE4 000318C0 */  sll       $v1, $v1, 3
/* B379B8 80242DE8 3C01800B */  lui       $at, 0x800b
/* B379BC 80242DEC 00230821 */  addu      $at, $at, $v1
/* B379C0 80242DF0 C4201DEC */  lwc1      $f0, 0x1dec($at)
/* B379C4 80242DF4 460C0300 */  add.s     $f12, $f0, $f12
/* B379C8 80242DF8 0C00A6C9 */  jal       clamp_angle
/* B379CC 80242DFC 0040982D */   daddu    $s3, $v0, $zero
/* B379D0 80242E00 27B00010 */  addiu     $s0, $sp, 0x10
/* B379D4 80242E04 0200202D */  daddu     $a0, $s0, $zero
/* B379D8 80242E08 27B20014 */  addiu     $s2, $sp, 0x14
/* B379DC 80242E0C 0240282D */  daddu     $a1, $s2, $zero
/* B379E0 80242E10 3C064170 */  lui       $a2, 0x4170
/* B379E4 80242E14 8E67000C */  lw        $a3, 0xc($s3)
/* B379E8 80242E18 0C00A7E7 */  jal       add_vec2D_polar
/* B379EC 80242E1C 46000506 */   mov.s    $f20, $f0
/* B379F0 80242E20 0200202D */  daddu     $a0, $s0, $zero
/* B379F4 80242E24 3C064120 */  lui       $a2, 0x4120
/* B379F8 80242E28 4407A000 */  mfc1      $a3, $f20
/* B379FC 80242E2C 0C00A7E7 */  jal       add_vec2D_polar
/* B37A00 80242E30 0240282D */   daddu    $a1, $s2, $zero
/* B37A04 80242E34 0220202D */  daddu     $a0, $s1, $zero
/* B37A08 80242E38 C7A00010 */  lwc1      $f0, 0x10($sp)
/* B37A0C 80242E3C 4600008D */  trunc.w.s $f2, $f0
/* B37A10 80242E40 44061000 */  mfc1      $a2, $f2
/* B37A14 80242E44 0C0B2026 */  jal       set_variable
/* B37A18 80242E48 02C0282D */   daddu    $a1, $s6, $zero
/* B37A1C 80242E4C 0220202D */  daddu     $a0, $s1, $zero
/* B37A20 80242E50 4600B08D */  trunc.w.s $f2, $f22
/* B37A24 80242E54 44061000 */  mfc1      $a2, $f2
/* B37A28 80242E58 0C0B2026 */  jal       set_variable
/* B37A2C 80242E5C 0280282D */   daddu    $a1, $s4, $zero
/* B37A30 80242E60 0220202D */  daddu     $a0, $s1, $zero
/* B37A34 80242E64 C7A00014 */  lwc1      $f0, 0x14($sp)
/* B37A38 80242E68 4600008D */  trunc.w.s $f2, $f0
/* B37A3C 80242E6C 44061000 */  mfc1      $a2, $f2
/* B37A40 80242E70 0C0B2026 */  jal       set_variable
/* B37A44 80242E74 02A0282D */   daddu    $a1, $s5, $zero
/* B37A48 80242E78 8FBF0034 */  lw        $ra, 0x34($sp)
/* B37A4C 80242E7C 8FB60030 */  lw        $s6, 0x30($sp)
/* B37A50 80242E80 8FB5002C */  lw        $s5, 0x2c($sp)
/* B37A54 80242E84 8FB40028 */  lw        $s4, 0x28($sp)
/* B37A58 80242E88 8FB30024 */  lw        $s3, 0x24($sp)
/* B37A5C 80242E8C 8FB20020 */  lw        $s2, 0x20($sp)
/* B37A60 80242E90 8FB1001C */  lw        $s1, 0x1c($sp)
/* B37A64 80242E94 8FB00018 */  lw        $s0, 0x18($sp)
/* B37A68 80242E98 D7B60040 */  ldc1      $f22, 0x40($sp)
/* B37A6C 80242E9C D7B40038 */  ldc1      $f20, 0x38($sp)
/* B37A70 80242EA0 24020002 */  addiu     $v0, $zero, 2
/* B37A74 80242EA4 03E00008 */  jr        $ra
/* B37A78 80242EA8 27BD0048 */   addiu    $sp, $sp, 0x48
