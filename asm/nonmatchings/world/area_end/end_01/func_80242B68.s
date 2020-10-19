.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242B68
/* E07EC8 80242B68 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E07ECC 80242B6C AFB10014 */  sw        $s1, 0x14($sp)
/* E07ED0 80242B70 0080882D */  daddu     $s1, $a0, $zero
/* E07ED4 80242B74 AFBF0018 */  sw        $ra, 0x18($sp)
/* E07ED8 80242B78 AFB00010 */  sw        $s0, 0x10($sp)
/* E07EDC 80242B7C 8E22000C */  lw        $v0, 0xc($s1)
/* E07EE0 80242B80 00A0802D */  daddu     $s0, $a1, $zero
/* E07EE4 80242B84 0C0B1EAF */  jal       get_variable
/* E07EE8 80242B88 8C450000 */   lw       $a1, ($v0)
/* E07EEC 80242B8C 1200000C */  beqz      $s0, .L80242BC0
/* E07EF0 80242B90 0220202D */   daddu    $a0, $s1, $zero
/* E07EF4 80242B94 0C0B36B0 */  jal       resolve_npc
/* E07EF8 80242B98 0040282D */   daddu    $a1, $v0, $zero
/* E07EFC 80242B9C AE220074 */  sw        $v0, 0x74($s1)
/* E07F00 80242BA0 C4420038 */  lwc1      $f2, 0x38($v0)
/* E07F04 80242BA4 3C014334 */  lui       $at, 0x4334
/* E07F08 80242BA8 44810000 */  mtc1      $at, $f0
/* E07F0C 80242BAC 24020048 */  addiu     $v0, $zero, 0x48
/* E07F10 80242BB0 AE220070 */  sw        $v0, 0x70($s1)
/* E07F14 80242BB4 4600110D */  trunc.w.s $f4, $f2
/* E07F18 80242BB8 E6240078 */  swc1      $f4, 0x78($s1)
/* E07F1C 80242BBC E620007C */  swc1      $f0, 0x7c($s1)
.L80242BC0:
/* E07F20 80242BC0 C620007C */  lwc1      $f0, 0x7c($s1)
/* E07F24 80242BC4 3C0140A0 */  lui       $at, 0x40a0
/* E07F28 80242BC8 44816000 */  mtc1      $at, $f12
/* E07F2C 80242BCC 8E300074 */  lw        $s0, 0x74($s1)
/* E07F30 80242BD0 0C00A6C9 */  jal       clamp_angle
/* E07F34 80242BD4 460C0300 */   add.s    $f12, $f0, $f12
/* E07F38 80242BD8 46000306 */  mov.s     $f12, $f0
/* E07F3C 80242BDC 0C00A8D4 */  jal       cos_deg
/* E07F40 80242BE0 E62C007C */   swc1     $f12, 0x7c($s1)
/* E07F44 80242BE4 3C0140C0 */  lui       $at, 0x40c0
/* E07F48 80242BE8 44811000 */  mtc1      $at, $f2
/* E07F4C 80242BEC 00000000 */  nop       
/* E07F50 80242BF0 46020002 */  mul.s     $f0, $f0, $f2
/* E07F54 80242BF4 00000000 */  nop       
/* E07F58 80242BF8 C6020038 */  lwc1      $f2, 0x38($s0)
/* E07F5C 80242BFC 46001080 */  add.s     $f2, $f2, $f0
/* E07F60 80242C00 E6020038 */  swc1      $f2, 0x38($s0)
/* E07F64 80242C04 0C00A8BB */  jal       sin_deg
/* E07F68 80242C08 C62C007C */   lwc1     $f12, 0x7c($s1)
/* E07F6C 80242C0C 3C014020 */  lui       $at, 0x4020
/* E07F70 80242C10 44811000 */  mtc1      $at, $f2
/* E07F74 80242C14 00000000 */  nop       
/* E07F78 80242C18 46020002 */  mul.s     $f0, $f0, $f2
/* E07F7C 80242C1C 00000000 */  nop       
/* E07F80 80242C20 C6020040 */  lwc1      $f2, 0x40($s0)
/* E07F84 80242C24 46001080 */  add.s     $f2, $f2, $f0
/* E07F88 80242C28 3C014334 */  lui       $at, 0x4334
/* E07F8C 80242C2C 44816000 */  mtc1      $at, $f12
/* E07F90 80242C30 E6020040 */  swc1      $f2, 0x40($s0)
/* E07F94 80242C34 C620007C */  lwc1      $f0, 0x7c($s1)
/* E07F98 80242C38 0C00A6C9 */  jal       clamp_angle
/* E07F9C 80242C3C 46006301 */   sub.s    $f12, $f12, $f0
/* E07FA0 80242C40 E6000034 */  swc1      $f0, 0x34($s0)
/* E07FA4 80242C44 8E230070 */  lw        $v1, 0x70($s1)
/* E07FA8 80242C48 2463FFFF */  addiu     $v1, $v1, -1
/* E07FAC 80242C4C AE230070 */  sw        $v1, 0x70($s1)
/* E07FB0 80242C50 8FBF0018 */  lw        $ra, 0x18($sp)
/* E07FB4 80242C54 8FB10014 */  lw        $s1, 0x14($sp)
/* E07FB8 80242C58 8FB00010 */  lw        $s0, 0x10($sp)
/* E07FBC 80242C5C 2C620001 */  sltiu     $v0, $v1, 1
/* E07FC0 80242C60 03E00008 */  jr        $ra
/* E07FC4 80242C64 27BD0020 */   addiu    $sp, $sp, 0x20
