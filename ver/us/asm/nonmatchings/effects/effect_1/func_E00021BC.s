.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00021BC
/* 327AAC E00021BC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 327AB0 E00021C0 0000302D */  daddu     $a2, $zero, $zero
/* 327AB4 E00021C4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 327AB8 E00021C8 8C820008 */  lw        $v0, 8($a0)
/* 327ABC E00021CC 8C85000C */  lw        $a1, 0xc($a0)
/* 327AC0 E00021D0 18400033 */  blez      $v0, .LE00022A0
/* 327AC4 E00021D4 00C0382D */   daddu    $a3, $a2, $zero
/* 327AC8 E00021D8 3C013FF4 */  lui       $at, 0x3ff4
/* 327ACC E00021DC 44813800 */  mtc1      $at, $f7
/* 327AD0 E00021E0 44803000 */  mtc1      $zero, $f6
/* 327AD4 E00021E4 24A30024 */  addiu     $v1, $a1, 0x24
.LE00021E8:
/* 327AD8 E00021E8 8462FFDE */  lh        $v0, -0x22($v1)
/* 327ADC E00021EC 04420027 */  bltzl     $v0, .LE000228C
/* 327AE0 E00021F0 24C60001 */   addiu    $a2, $a2, 1
/* 327AE4 E00021F4 8C62FFE4 */  lw        $v0, -0x1c($v1)
/* 327AE8 E00021F8 2442FFFF */  addiu     $v0, $v0, -1
/* 327AEC E00021FC 04410022 */  bgez      $v0, .LE0002288
/* 327AF0 E0002200 AC62FFE4 */   sw       $v0, -0x1c($v1)
/* 327AF4 E0002204 C464FFF4 */  lwc1      $f4, -0xc($v1)
/* 327AF8 E0002208 C460FFFC */  lwc1      $f0, -4($v1)
/* 327AFC E000220C C462FFF8 */  lwc1      $f2, -8($v1)
/* 327B00 E0002210 46002100 */  add.s     $f4, $f4, $f0
/* 327B04 E0002214 C4600000 */  lwc1      $f0, ($v1)
/* 327B08 E0002218 46001080 */  add.s     $f2, $f2, $f0
/* 327B0C E000221C E464FFF4 */  swc1      $f4, -0xc($v1)
/* 327B10 E0002220 E462FFF8 */  swc1      $f2, -8($v1)
/* 327B14 E0002224 94A20000 */  lhu       $v0, ($a1)
/* 327B18 E0002228 24420001 */  addiu     $v0, $v0, 1
/* 327B1C E000222C A4A20000 */  sh        $v0, ($a1)
/* 327B20 E0002230 9462FFDE */  lhu       $v0, -0x22($v1)
/* 327B24 E0002234 2442FFFF */  addiu     $v0, $v0, -1
/* 327B28 E0002238 A462FFDE */  sh        $v0, -0x22($v1)
/* 327B2C E000223C 00021400 */  sll       $v0, $v0, 0x10
/* 327B30 E0002240 04400011 */  bltz      $v0, .LE0002288
/* 327B34 E0002244 24070001 */   addiu    $a3, $zero, 1
/* 327B38 E0002248 9462FFE2 */  lhu       $v0, -0x1e($v1)
/* 327B3C E000224C 2442FFFF */  addiu     $v0, $v0, -1
/* 327B40 E0002250 A462FFE2 */  sh        $v0, -0x1e($v1)
/* 327B44 E0002254 00021400 */  sll       $v0, $v0, 0x10
/* 327B48 E0002258 0443000C */  bgezl     $v0, .LE000228C
/* 327B4C E000225C 24C60001 */   addiu    $a2, $a2, 1
/* 327B50 E0002260 C460FFFC */  lwc1      $f0, -4($v1)
/* 327B54 E0002264 C4620000 */  lwc1      $f2, ($v1)
/* 327B58 E0002268 46000021 */  cvt.d.s   $f0, $f0
/* 327B5C E000226C 46260003 */  div.d     $f0, $f0, $f6
/* 327B60 E0002270 46200020 */  cvt.s.d   $f0, $f0
/* 327B64 E0002274 460010A1 */  cvt.d.s   $f2, $f2
/* 327B68 E0002278 46261083 */  div.d     $f2, $f2, $f6
/* 327B6C E000227C 462010A0 */  cvt.s.d   $f2, $f2
/* 327B70 E0002280 E460FFFC */  swc1      $f0, -4($v1)
/* 327B74 E0002284 E4620000 */  swc1      $f2, ($v1)
.LE0002288:
/* 327B78 E0002288 24C60001 */  addiu     $a2, $a2, 1
.LE000228C:
/* 327B7C E000228C 2463002C */  addiu     $v1, $v1, 0x2c
/* 327B80 E0002290 8C820008 */  lw        $v0, 8($a0)
/* 327B84 E0002294 00C2102A */  slt       $v0, $a2, $v0
/* 327B88 E0002298 1440FFD3 */  bnez      $v0, .LE00021E8
/* 327B8C E000229C 24A5002C */   addiu    $a1, $a1, 0x2c
.LE00022A0:
/* 327B90 E00022A0 14E00003 */  bnez      $a3, .LE00022B0
/* 327B94 E00022A4 00000000 */   nop
/* 327B98 E00022A8 0C080128 */  jal       shim_remove_effect
/* 327B9C E00022AC 00000000 */   nop
.LE00022B0:
/* 327BA0 E00022B0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 327BA4 E00022B4 03E00008 */  jr        $ra
/* 327BA8 E00022B8 27BD0018 */   addiu    $sp, $sp, 0x18
