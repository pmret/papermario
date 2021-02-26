.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002FEA0
/* B2A0 8002FEA0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B2A4 8002FEA4 AFB00010 */  sw        $s0, 0x10($sp)
/* B2A8 8002FEA8 0080802D */  daddu     $s0, $a0, $zero
/* B2AC 8002FEAC AFBF0018 */  sw        $ra, 0x18($sp)
/* B2B0 8002FEB0 AFB10014 */  sw        $s1, 0x14($sp)
/* B2B4 8002FEB4 F7B60028 */  sdc1      $f22, 0x28($sp)
/* B2B8 8002FEB8 F7B40020 */  sdc1      $f20, 0x20($sp)
/* B2BC 8002FEBC C6000054 */  lwc1      $f0, 0x54($s0)
/* B2C0 8002FEC0 C6040048 */  lwc1      $f4, 0x48($s0)
/* B2C4 8002FEC4 46040001 */  sub.s     $f0, $f0, $f4
/* B2C8 8002FEC8 4485B000 */  mtc1      $a1, $f22
/* B2CC 8002FECC 00000000 */  nop
/* B2D0 8002FED0 46160002 */  mul.s     $f0, $f0, $f22
/* B2D4 8002FED4 00000000 */  nop
/* B2D8 8002FED8 44863000 */  mtc1      $a2, $f6
/* B2DC 8002FEDC 00000000 */  nop
/* B2E0 8002FEE0 46003087 */  neg.s     $f2, $f6
/* B2E4 8002FEE4 4602003C */  c.lt.s    $f0, $f2
/* B2E8 8002FEE8 00000000 */  nop
/* B2EC 8002FEEC 45000002 */  bc1f      .L8002FEF8
/* B2F0 8002FEF0 00E0882D */   daddu    $s1, $a3, $zero
/* B2F4 8002FEF4 46001006 */  mov.s     $f0, $f2
.L8002FEF8:
/* B2F8 8002FEF8 4600303C */  c.lt.s    $f6, $f0
/* B2FC 8002FEFC 00000000 */  nop
/* B300 8002FF00 45030001 */  bc1tl     .L8002FF08
/* B304 8002FF04 46003006 */   mov.s    $f0, $f6
.L8002FF08:
/* B308 8002FF08 C6020074 */  lwc1      $f2, 0x74($s0)
/* B30C 8002FF0C 46002100 */  add.s     $f4, $f4, $f0
/* B310 8002FF10 3C0140C9 */  lui       $at, 0x40c9
/* B314 8002FF14 34210FD0 */  ori       $at, $at, 0xfd0
/* B318 8002FF18 44810000 */  mtc1      $at, $f0
/* B31C 8002FF1C 00000000 */  nop
/* B320 8002FF20 46001082 */  mul.s     $f2, $f2, $f0
/* B324 8002FF24 00000000 */  nop
/* B328 8002FF28 3C0143B4 */  lui       $at, 0x43b4
/* B32C 8002FF2C 44810000 */  mtc1      $at, $f0
/* B330 8002FF30 E604003C */  swc1      $f4, 0x3c($s0)
/* B334 8002FF34 E6040048 */  swc1      $f4, 0x48($s0)
/* B338 8002FF38 46001503 */  div.s     $f20, $f2, $f0
/* B33C 8002FF3C 0C00A864 */  jal       func_8002A190
/* B340 8002FF40 4600A306 */   mov.s    $f12, $f20
/* B344 8002FF44 C6020078 */  lwc1      $f2, 0x78($s0)
/* B348 8002FF48 46001082 */  mul.s     $f2, $f2, $f0
/* B34C 8002FF4C 00000000 */  nop
/* B350 8002FF50 C604005C */  lwc1      $f4, 0x5c($s0)
/* B354 8002FF54 C6060050 */  lwc1      $f6, 0x50($s0)
/* B358 8002FF58 46062101 */  sub.s     $f4, $f4, $f6
/* B35C 8002FF5C 46162102 */  mul.s     $f4, $f4, $f22
/* B360 8002FF60 00000000 */  nop
/* B364 8002FF64 46043180 */  add.s     $f6, $f6, $f4
/* B368 8002FF68 46023080 */  add.s     $f2, $f6, $f2
/* B36C 8002FF6C 00111400 */  sll       $v0, $s1, 0x10
/* B370 8002FF70 E6060050 */  swc1      $f6, 0x50($s0)
/* B374 8002FF74 14400012 */  bnez      $v0, .L8002FFC0
/* B378 8002FF78 E6020044 */   swc1     $f2, 0x44($s0)
/* B37C 8002FF7C 0C00A84B */  jal       func_8002A12C
/* B380 8002FF80 4600A306 */   mov.s    $f12, $f20
/* B384 8002FF84 C6040058 */  lwc1      $f4, 0x58($s0)
/* B388 8002FF88 C606004C */  lwc1      $f6, 0x4c($s0)
/* B38C 8002FF8C 46062101 */  sub.s     $f4, $f4, $f6
/* B390 8002FF90 3C013E00 */  lui       $at, 0x3e00
/* B394 8002FF94 44811000 */  mtc1      $at, $f2
/* B398 8002FF98 00000000 */  nop
/* B39C 8002FF9C 46022102 */  mul.s     $f4, $f4, $f2
/* B3A0 8002FFA0 00000000 */  nop
/* B3A4 8002FFA4 C6020078 */  lwc1      $f2, 0x78($s0)
/* B3A8 8002FFA8 46001082 */  mul.s     $f2, $f2, $f0
/* B3AC 8002FFAC 00000000 */  nop
/* B3B0 8002FFB0 46043180 */  add.s     $f6, $f6, $f4
/* B3B4 8002FFB4 46023080 */  add.s     $f2, $f6, $f2
/* B3B8 8002FFB8 E606004C */  swc1      $f6, 0x4c($s0)
/* B3BC 8002FFBC E6020040 */  swc1      $f2, 0x40($s0)
.L8002FFC0:
/* B3C0 8002FFC0 8FBF0018 */  lw        $ra, 0x18($sp)
/* B3C4 8002FFC4 8FB10014 */  lw        $s1, 0x14($sp)
/* B3C8 8002FFC8 8FB00010 */  lw        $s0, 0x10($sp)
/* B3CC 8002FFCC D7B60028 */  ldc1      $f22, 0x28($sp)
/* B3D0 8002FFD0 D7B40020 */  ldc1      $f20, 0x20($sp)
/* B3D4 8002FFD4 03E00008 */  jr        $ra
/* B3D8 8002FFD8 27BD0030 */   addiu    $sp, $sp, 0x30
