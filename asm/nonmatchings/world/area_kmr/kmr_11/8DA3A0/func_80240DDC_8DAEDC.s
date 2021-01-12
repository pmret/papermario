.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240DDC_8DAEDC
/* 8DAEDC 80240DDC 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 8DAEE0 80240DE0 AFB10014 */  sw        $s1, 0x14($sp)
/* 8DAEE4 80240DE4 0080882D */  daddu     $s1, $a0, $zero
/* 8DAEE8 80240DE8 AFBF001C */  sw        $ra, 0x1c($sp)
/* 8DAEEC 80240DEC AFB20018 */  sw        $s2, 0x18($sp)
/* 8DAEF0 80240DF0 AFB00010 */  sw        $s0, 0x10($sp)
/* 8DAEF4 80240DF4 F7B60028 */  sdc1      $f22, 0x28($sp)
/* 8DAEF8 80240DF8 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 8DAEFC 80240DFC 0C00EABB */  jal       get_npc_unsafe
/* 8DAF00 80240E00 24040004 */   addiu    $a0, $zero, 4
/* 8DAF04 80240E04 0040802D */  daddu     $s0, $v0, $zero
/* 8DAF08 80240E08 3C12800B */  lui       $s2, %hi(gCameras)
/* 8DAF0C 80240E0C 26521D80 */  addiu     $s2, $s2, %lo(gCameras)
/* 8DAF10 80240E10 C60C000C */  lwc1      $f12, 0xc($s0)
/* 8DAF14 80240E14 C640006C */  lwc1      $f0, 0x6c($s2)
/* 8DAF18 80240E18 46006300 */  add.s     $f12, $f12, $f0
/* 8DAF1C 80240E1C 3C014334 */  lui       $at, 0x4334
/* 8DAF20 80240E20 4481A000 */  mtc1      $at, $f20
/* 8DAF24 80240E24 3C014220 */  lui       $at, 0x4220
/* 8DAF28 80240E28 4481B000 */  mtc1      $at, $f22
/* 8DAF2C 80240E2C 0C00A8BB */  jal       sin_deg
/* 8DAF30 80240E30 46146300 */   add.s    $f12, $f12, $f20
/* 8DAF34 80240E34 46160002 */  mul.s     $f0, $f0, $f22
/* 8DAF38 80240E38 00000000 */  nop
/* 8DAF3C 80240E3C C6020038 */  lwc1      $f2, 0x38($s0)
/* 8DAF40 80240E40 46001080 */  add.s     $f2, $f2, $f0
/* 8DAF44 80240E44 4600110D */  trunc.w.s $f4, $f2
/* 8DAF48 80240E48 E6240084 */  swc1      $f4, 0x84($s1)
/* 8DAF4C 80240E4C C600003C */  lwc1      $f0, 0x3c($s0)
/* 8DAF50 80240E50 3C014100 */  lui       $at, 0x4100
/* 8DAF54 80240E54 44811000 */  mtc1      $at, $f2
/* 8DAF58 80240E58 00000000 */  nop
/* 8DAF5C 80240E5C 46020000 */  add.s     $f0, $f0, $f2
/* 8DAF60 80240E60 4600010D */  trunc.w.s $f4, $f0
/* 8DAF64 80240E64 E6240088 */  swc1      $f4, 0x88($s1)
/* 8DAF68 80240E68 C60C000C */  lwc1      $f12, 0xc($s0)
/* 8DAF6C 80240E6C C640006C */  lwc1      $f0, 0x6c($s2)
/* 8DAF70 80240E70 46006300 */  add.s     $f12, $f12, $f0
/* 8DAF74 80240E74 0C00A8D4 */  jal       cos_deg
/* 8DAF78 80240E78 46146300 */   add.s    $f12, $f12, $f20
/* 8DAF7C 80240E7C 46160002 */  mul.s     $f0, $f0, $f22
/* 8DAF80 80240E80 00000000 */  nop
/* 8DAF84 80240E84 C6020040 */  lwc1      $f2, 0x40($s0)
/* 8DAF88 80240E88 46001081 */  sub.s     $f2, $f2, $f0
/* 8DAF8C 80240E8C 4600110D */  trunc.w.s $f4, $f2
/* 8DAF90 80240E90 E624008C */  swc1      $f4, 0x8c($s1)
/* 8DAF94 80240E94 8FBF001C */  lw        $ra, 0x1c($sp)
/* 8DAF98 80240E98 8FB20018 */  lw        $s2, 0x18($sp)
/* 8DAF9C 80240E9C 8FB10014 */  lw        $s1, 0x14($sp)
/* 8DAFA0 80240EA0 8FB00010 */  lw        $s0, 0x10($sp)
/* 8DAFA4 80240EA4 D7B60028 */  ldc1      $f22, 0x28($sp)
/* 8DAFA8 80240EA8 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 8DAFAC 80240EAC 24020002 */  addiu     $v0, $zero, 2
/* 8DAFB0 80240EB0 03E00008 */  jr        $ra
/* 8DAFB4 80240EB4 27BD0030 */   addiu    $sp, $sp, 0x30
/* 8DAFB8 80240EB8 00000000 */  nop
/* 8DAFBC 80240EBC 00000000 */  nop
