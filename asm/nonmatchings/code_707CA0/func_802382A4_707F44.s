.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802382A4_707F44
/* 707F44 802382A4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 707F48 802382A8 AFB00018 */  sw        $s0, 0x18($sp)
/* 707F4C 802382AC 0080802D */  daddu     $s0, $a0, $zero
/* 707F50 802382B0 AFBF001C */  sw        $ra, 0x1c($sp)
/* 707F54 802382B4 C6040090 */  lwc1      $f4, 0x90($s0)
/* 707F58 802382B8 46802120 */  cvt.s.w   $f4, $f4
/* 707F5C 802382BC 44062000 */  mfc1      $a2, $f4
/* 707F60 802382C0 C6040094 */  lwc1      $f4, 0x94($s0)
/* 707F64 802382C4 46802120 */  cvt.s.w   $f4, $f4
/* 707F68 802382C8 44072000 */  mfc1      $a3, $f4
/* 707F6C 802382CC C60C0084 */  lwc1      $f12, 0x84($s0)
/* 707F70 802382D0 46806320 */  cvt.s.w   $f12, $f12
/* 707F74 802382D4 E7AC0010 */  swc1      $f12, 0x10($sp)
/* 707F78 802382D8 C60E0088 */  lwc1      $f14, 0x88($s0)
/* 707F7C 802382DC 468073A0 */  cvt.s.w   $f14, $f14
/* 707F80 802382E0 0C00A720 */  jal       atan2
/* 707F84 802382E4 E7AE0014 */   swc1     $f14, 0x14($sp)
/* 707F88 802382E8 27A40010 */  addiu     $a0, $sp, 0x10
/* 707F8C 802382EC 3C064396 */  lui       $a2, 0x4396
/* 707F90 802382F0 44070000 */  mfc1      $a3, $f0
/* 707F94 802382F4 0C00A7E7 */  jal       add_vec2D_polar
/* 707F98 802382F8 27A50014 */   addiu    $a1, $sp, 0x14
/* 707F9C 802382FC C7A00010 */  lwc1      $f0, 0x10($sp)
/* 707FA0 80238300 C7A20014 */  lwc1      $f2, 0x14($sp)
/* 707FA4 80238304 4600010D */  trunc.w.s $f4, $f0
/* 707FA8 80238308 E6040090 */  swc1      $f4, 0x90($s0)
/* 707FAC 8023830C 4600110D */  trunc.w.s $f4, $f2
/* 707FB0 80238310 E6040094 */  swc1      $f4, 0x94($s0)
/* 707FB4 80238314 8FBF001C */  lw        $ra, 0x1c($sp)
/* 707FB8 80238318 8FB00018 */  lw        $s0, 0x18($sp)
/* 707FBC 8023831C 24020002 */  addiu     $v0, $zero, 2
/* 707FC0 80238320 03E00008 */  jr        $ra
/* 707FC4 80238324 27BD0020 */   addiu    $sp, $sp, 0x20
