.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404A8_91BD88
/* 91BD88 802404A8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 91BD8C 802404AC AFB10014 */  sw        $s1, 0x14($sp)
/* 91BD90 802404B0 0080882D */  daddu     $s1, $a0, $zero
/* 91BD94 802404B4 AFBF001C */  sw        $ra, 0x1c($sp)
/* 91BD98 802404B8 AFB20018 */  sw        $s2, 0x18($sp)
/* 91BD9C 802404BC AFB00010 */  sw        $s0, 0x10($sp)
/* 91BDA0 802404C0 8E320148 */  lw        $s2, 0x148($s1)
/* 91BDA4 802404C4 0C00EABB */  jal       get_npc_unsafe
/* 91BDA8 802404C8 86440008 */   lh       $a0, 8($s2)
/* 91BDAC 802404CC 240400B4 */  addiu     $a0, $zero, 0xb4
/* 91BDB0 802404D0 0C00A67F */  jal       rand_int
/* 91BDB4 802404D4 0040802D */   daddu    $s0, $v0, $zero
/* 91BDB8 802404D8 C60C000C */  lwc1      $f12, 0xc($s0)
/* 91BDBC 802404DC 44820000 */  mtc1      $v0, $f0
/* 91BDC0 802404E0 00000000 */  nop
/* 91BDC4 802404E4 46800020 */  cvt.s.w   $f0, $f0
/* 91BDC8 802404E8 46006300 */  add.s     $f12, $f12, $f0
/* 91BDCC 802404EC 3C0142B4 */  lui       $at, 0x42b4
/* 91BDD0 802404F0 44810000 */  mtc1      $at, $f0
/* 91BDD4 802404F4 0C00A6C9 */  jal       clamp_angle
/* 91BDD8 802404F8 46006301 */   sub.s    $f12, $f12, $f0
/* 91BDDC 802404FC E600000C */  swc1      $f0, 0xc($s0)
/* 91BDE0 80240500 8E4200CC */  lw        $v0, 0xcc($s2)
/* 91BDE4 80240504 8C420000 */  lw        $v0, ($v0)
/* 91BDE8 80240508 240403E8 */  addiu     $a0, $zero, 0x3e8
/* 91BDEC 8024050C 0C00A67F */  jal       rand_int
/* 91BDF0 80240510 AE020028 */   sw       $v0, 0x28($s0)
/* 91BDF4 80240514 00021FC2 */  srl       $v1, $v0, 0x1f
/* 91BDF8 80240518 00431821 */  addu      $v1, $v0, $v1
/* 91BDFC 8024051C 00031843 */  sra       $v1, $v1, 1
/* 91BE00 80240520 00031840 */  sll       $v1, $v1, 1
/* 91BE04 80240524 00431023 */  subu      $v0, $v0, $v1
/* 91BE08 80240528 24420002 */  addiu     $v0, $v0, 2
/* 91BE0C 8024052C AE220074 */  sw        $v0, 0x74($s1)
/* 91BE10 80240530 24020005 */  addiu     $v0, $zero, 5
/* 91BE14 80240534 AE220070 */  sw        $v0, 0x70($s1)
/* 91BE18 80240538 8FBF001C */  lw        $ra, 0x1c($sp)
/* 91BE1C 8024053C 8FB20018 */  lw        $s2, 0x18($sp)
/* 91BE20 80240540 8FB10014 */  lw        $s1, 0x14($sp)
/* 91BE24 80240544 8FB00010 */  lw        $s0, 0x10($sp)
/* 91BE28 80240548 03E00008 */  jr        $ra
/* 91BE2C 8024054C 27BD0020 */   addiu    $sp, $sp, 0x20
