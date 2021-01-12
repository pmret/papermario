.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241B38_BEE928
/* BEE928 80241B38 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* BEE92C 80241B3C AFB00028 */  sw        $s0, 0x28($sp)
/* BEE930 80241B40 00A0802D */  daddu     $s0, $a1, $zero
/* BEE934 80241B44 AFB1002C */  sw        $s1, 0x2c($sp)
/* BEE938 80241B48 00C0882D */  daddu     $s1, $a2, $zero
/* BEE93C 80241B4C AFBF0034 */  sw        $ra, 0x34($sp)
/* BEE940 80241B50 AFB20030 */  sw        $s2, 0x30($sp)
/* BEE944 80241B54 AE200070 */  sw        $zero, 0x70($s1)
/* BEE948 80241B58 8C830000 */  lw        $v1, ($a0)
/* BEE94C 80241B5C 2402FDFF */  addiu     $v0, $zero, -0x201
/* BEE950 80241B60 A480008E */  sh        $zero, 0x8e($a0)
/* BEE954 80241B64 00621824 */  and       $v1, $v1, $v0
/* BEE958 80241B68 34650800 */  ori       $a1, $v1, 0x800
/* BEE95C 80241B6C AC850000 */  sw        $a1, ($a0)
/* BEE960 80241B70 8E0200D0 */  lw        $v0, 0xd0($s0)
/* BEE964 80241B74 8C420034 */  lw        $v0, 0x34($v0)
/* BEE968 80241B78 10400003 */  beqz      $v0, .L80241B88
/* BEE96C 80241B7C 00E0902D */   daddu    $s2, $a3, $zero
/* BEE970 80241B80 080906E4 */  j         .L80241B90
/* BEE974 80241B84 34620808 */   ori      $v0, $v1, 0x808
.L80241B88:
/* BEE978 80241B88 2402FFF7 */  addiu     $v0, $zero, -9
/* BEE97C 80241B8C 00A21024 */  and       $v0, $a1, $v0
.L80241B90:
/* BEE980 80241B90 AC820000 */  sw        $v0, ($a0)
/* BEE984 80241B94 27A20024 */  addiu     $v0, $sp, 0x24
/* BEE988 80241B98 27A50018 */  addiu     $a1, $sp, 0x18
/* BEE98C 80241B9C C4800038 */  lwc1      $f0, 0x38($a0)
/* BEE990 80241BA0 C482003C */  lwc1      $f2, 0x3c($a0)
/* BEE994 80241BA4 C4840040 */  lwc1      $f4, 0x40($a0)
/* BEE998 80241BA8 3C01447A */  lui       $at, 0x447a
/* BEE99C 80241BAC 44813000 */  mtc1      $at, $f6
/* BEE9A0 80241BB0 27A6001C */  addiu     $a2, $sp, 0x1c
/* BEE9A4 80241BB4 E7A00018 */  swc1      $f0, 0x18($sp)
/* BEE9A8 80241BB8 E7A2001C */  swc1      $f2, 0x1c($sp)
/* BEE9AC 80241BBC E7A40020 */  swc1      $f4, 0x20($sp)
/* BEE9B0 80241BC0 E7A60024 */  swc1      $f6, 0x24($sp)
/* BEE9B4 80241BC4 AFA20010 */  sw        $v0, 0x10($sp)
/* BEE9B8 80241BC8 8C840080 */  lw        $a0, 0x80($a0)
/* BEE9BC 80241BCC 0C0372DF */  jal       func_800DCB7C
/* BEE9C0 80241BD0 27A70020 */   addiu    $a3, $sp, 0x20
/* BEE9C4 80241BD4 C7A20024 */  lwc1      $f2, 0x24($sp)
/* BEE9C8 80241BD8 3C014059 */  lui       $at, 0x4059
/* BEE9CC 80241BDC 44812800 */  mtc1      $at, $f5
/* BEE9D0 80241BE0 44802000 */  mtc1      $zero, $f4
/* BEE9D4 80241BE4 460010A1 */  cvt.d.s   $f2, $f2
/* BEE9D8 80241BE8 46241082 */  mul.d     $f2, $f2, $f4
/* BEE9DC 80241BEC 00000000 */  nop
/* BEE9E0 80241BF0 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* BEE9E4 80241BF4 46000021 */  cvt.d.s   $f0, $f0
/* BEE9E8 80241BF8 46240002 */  mul.d     $f0, $f0, $f4
/* BEE9EC 80241BFC 00000000 */  nop
/* BEE9F0 80241C00 3C013FE0 */  lui       $at, 0x3fe0
/* BEE9F4 80241C04 44812800 */  mtc1      $at, $f5
/* BEE9F8 80241C08 44802000 */  mtc1      $zero, $f4
/* BEE9FC 80241C0C 00000000 */  nop
/* BEEA00 80241C10 46241080 */  add.d     $f2, $f2, $f4
/* BEEA04 80241C14 AE000074 */  sw        $zero, 0x74($s0)
/* BEEA08 80241C18 46240000 */  add.d     $f0, $f0, $f4
/* BEEA0C 80241C1C AE000090 */  sw        $zero, 0x90($s0)
/* BEEA10 80241C20 4620120D */  trunc.w.d $f8, $f2
/* BEEA14 80241C24 E6080078 */  swc1      $f8, 0x78($s0)
/* BEEA18 80241C28 4620020D */  trunc.w.d $f8, $f0
/* BEEA1C 80241C2C E6080088 */  swc1      $f8, 0x88($s0)
/* BEEA20 80241C30 8E420014 */  lw        $v0, 0x14($s2)
/* BEEA24 80241C34 AE220074 */  sw        $v0, 0x74($s1)
/* BEEA28 80241C38 8E0200B0 */  lw        $v0, 0xb0($s0)
/* BEEA2C 80241C3C 34420010 */  ori       $v0, $v0, 0x10
/* BEEA30 80241C40 AE0200B0 */  sw        $v0, 0xb0($s0)
/* BEEA34 80241C44 8FBF0034 */  lw        $ra, 0x34($sp)
/* BEEA38 80241C48 8FB20030 */  lw        $s2, 0x30($sp)
/* BEEA3C 80241C4C 8FB1002C */  lw        $s1, 0x2c($sp)
/* BEEA40 80241C50 8FB00028 */  lw        $s0, 0x28($sp)
/* BEEA44 80241C54 03E00008 */  jr        $ra
/* BEEA48 80241C58 27BD0038 */   addiu    $sp, $sp, 0x38
