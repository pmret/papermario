.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240248_BDA9F8
/* BDA9F8 80240248 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BDA9FC 8024024C 0080102D */  daddu     $v0, $a0, $zero
/* BDAA00 80240250 AFBF001C */  sw        $ra, 0x1c($sp)
/* BDAA04 80240254 AFB20018 */  sw        $s2, 0x18($sp)
/* BDAA08 80240258 AFB10014 */  sw        $s1, 0x14($sp)
/* BDAA0C 8024025C AFB00010 */  sw        $s0, 0x10($sp)
/* BDAA10 80240260 8C44014C */  lw        $a0, 0x14c($v0)
/* BDAA14 80240264 0C00EAD2 */  jal       get_npc_safe
/* BDAA18 80240268 8C500060 */   lw       $s0, 0x60($v0)
/* BDAA1C 8024026C 8E040018 */  lw        $a0, 0x18($s0)
/* BDAA20 80240270 0C044181 */  jal       get_shadow_by_index
/* BDAA24 80240274 0040882D */   daddu    $s1, $v0, $zero
/* BDAA28 80240278 C6200038 */  lwc1      $f0, 0x38($s1)
/* BDAA2C 8024027C 3C014000 */  lui       $at, 0x4000
/* BDAA30 80240280 44811000 */  mtc1      $at, $f2
/* BDAA34 80240284 00000000 */  nop       
/* BDAA38 80240288 46020001 */  sub.s     $f0, $f0, $f2
/* BDAA3C 8024028C 3C014140 */  lui       $at, 0x4140
/* BDAA40 80240290 44811000 */  mtc1      $at, $f2
/* BDAA44 80240294 E6000000 */  swc1      $f0, ($s0)
/* BDAA48 80240298 C620003C */  lwc1      $f0, 0x3c($s1)
/* BDAA4C 8024029C 46020000 */  add.s     $f0, $f0, $f2
/* BDAA50 802402A0 3C0141F0 */  lui       $at, 0x41f0
/* BDAA54 802402A4 44811000 */  mtc1      $at, $f2
/* BDAA58 802402A8 E6000004 */  swc1      $f0, 4($s0)
/* BDAA5C 802402AC C6200040 */  lwc1      $f0, 0x40($s1)
/* BDAA60 802402B0 8E12001C */  lw        $s2, 0x1c($s0)
/* BDAA64 802402B4 46020001 */  sub.s     $f0, $f0, $f2
/* BDAA68 802402B8 3C0140D3 */  lui       $at, 0x40d3
/* BDAA6C 802402BC 34213333 */  ori       $at, $at, 0x3333
/* BDAA70 802402C0 44816000 */  mtc1      $at, $f12
/* BDAA74 802402C4 E6000008 */  swc1      $f0, 8($s0)
/* BDAA78 802402C8 8E43000C */  lw        $v1, 0xc($s2)
/* BDAA7C 802402CC C6000000 */  lwc1      $f0, ($s0)
/* BDAA80 802402D0 E4600004 */  swc1      $f0, 4($v1)
/* BDAA84 802402D4 8E43000C */  lw        $v1, 0xc($s2)
/* BDAA88 802402D8 C6000004 */  lwc1      $f0, 4($s0)
/* BDAA8C 802402DC E4600008 */  swc1      $f0, 8($v1)
/* BDAA90 802402E0 8E43000C */  lw        $v1, 0xc($s2)
/* BDAA94 802402E4 C6000008 */  lwc1      $f0, 8($s0)
/* BDAA98 802402E8 E460000C */  swc1      $f0, 0xc($v1)
/* BDAA9C 802402EC C6000010 */  lwc1      $f0, 0x10($s0)
/* BDAAA0 802402F0 460C0300 */  add.s     $f12, $f0, $f12
/* BDAAA4 802402F4 0C00A6C9 */  jal       clamp_angle
/* BDAAA8 802402F8 0040882D */   daddu    $s1, $v0, $zero
/* BDAAAC 802402FC E6000010 */  swc1      $f0, 0x10($s0)
/* BDAAB0 80240300 8E42000C */  lw        $v0, 0xc($s2)
/* BDAAB4 80240304 3C014220 */  lui       $at, 0x4220
/* BDAAB8 80240308 44811000 */  mtc1      $at, $f2
/* BDAABC 8024030C E4400024 */  swc1      $f0, 0x24($v0)
/* BDAAC0 80240310 C6000000 */  lwc1      $f0, ($s0)
/* BDAAC4 80240314 E6200010 */  swc1      $f0, 0x10($s1)
/* BDAAC8 80240318 C6000004 */  lwc1      $f0, 4($s0)
/* BDAACC 8024031C 46020001 */  sub.s     $f0, $f0, $f2
/* BDAAD0 80240320 E6200014 */  swc1      $f0, 0x14($s1)
/* BDAAD4 80240324 C6000008 */  lwc1      $f0, 8($s0)
/* BDAAD8 80240328 E6200018 */  swc1      $f0, 0x18($s1)
/* BDAADC 8024032C 8FBF001C */  lw        $ra, 0x1c($sp)
/* BDAAE0 80240330 8FB20018 */  lw        $s2, 0x18($sp)
/* BDAAE4 80240334 8FB10014 */  lw        $s1, 0x14($sp)
/* BDAAE8 80240338 8FB00010 */  lw        $s0, 0x10($sp)
/* BDAAEC 8024033C 0000102D */  daddu     $v0, $zero, $zero
/* BDAAF0 80240340 03E00008 */  jr        $ra
/* BDAAF4 80240344 27BD0020 */   addiu    $sp, $sp, 0x20
/* BDAAF8 80240348 00000000 */  nop       
/* BDAAFC 8024034C 00000000 */  nop       
