.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B65F8_E26D08
/* E26D08 802B65F8 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* E26D0C 802B65FC 3C048011 */  lui       $a0, %hi(gPlayerStatus)
/* E26D10 802B6600 2484EFC8 */  addiu     $a0, $a0, %lo(gPlayerStatus)
/* E26D14 802B6604 27A50028 */  addiu     $a1, $sp, 0x28
/* E26D18 802B6608 27A6002C */  addiu     $a2, $sp, 0x2c
/* E26D1C 802B660C 27A70030 */  addiu     $a3, $sp, 0x30
/* E26D20 802B6610 AFBF0048 */  sw        $ra, 0x48($sp)
/* E26D24 802B6614 848200B0 */  lh        $v0, 0xb0($a0)
/* E26D28 802B6618 3C013F00 */  lui       $at, 0x3f00
/* E26D2C 802B661C 44811000 */  mtc1      $at, $f2
/* E26D30 802B6620 C4800028 */  lwc1      $f0, 0x28($a0)
/* E26D34 802B6624 44823000 */  mtc1      $v0, $f6
/* E26D38 802B6628 00000000 */  nop
/* E26D3C 802B662C 468031A0 */  cvt.s.w   $f6, $f6
/* E26D40 802B6630 46023082 */  mul.s     $f2, $f6, $f2
/* E26D44 802B6634 00000000 */  nop
/* E26D48 802B6638 27A20034 */  addiu     $v0, $sp, 0x34
/* E26D4C 802B663C E7A00028 */  swc1      $f0, 0x28($sp)
/* E26D50 802B6640 C480002C */  lwc1      $f0, 0x2c($a0)
/* E26D54 802B6644 C4840030 */  lwc1      $f4, 0x30($a0)
/* E26D58 802B6648 46020000 */  add.s     $f0, $f0, $f2
/* E26D5C 802B664C E7A60034 */  swc1      $f6, 0x34($sp)
/* E26D60 802B6650 E7A40030 */  swc1      $f4, 0x30($sp)
/* E26D64 802B6654 E7A0002C */  swc1      $f0, 0x2c($sp)
/* E26D68 802B6658 AFA20010 */  sw        $v0, 0x10($sp)
/* E26D6C 802B665C 27A20038 */  addiu     $v0, $sp, 0x38
/* E26D70 802B6660 AFA20014 */  sw        $v0, 0x14($sp)
/* E26D74 802B6664 27A2003C */  addiu     $v0, $sp, 0x3c
/* E26D78 802B6668 AFA20018 */  sw        $v0, 0x18($sp)
/* E26D7C 802B666C 27A20040 */  addiu     $v0, $sp, 0x40
/* E26D80 802B6670 AFA2001C */  sw        $v0, 0x1c($sp)
/* E26D84 802B6674 27A20044 */  addiu     $v0, $sp, 0x44
/* E26D88 802B6678 0C03791B */  jal       player_raycast_below_cam_relative
/* E26D8C 802B667C AFA20020 */   sw       $v0, 0x20($sp)
/* E26D90 802B6680 8FBF0048 */  lw        $ra, 0x48($sp)
/* E26D94 802B6684 03E00008 */  jr        $ra
/* E26D98 802B6688 27BD0050 */   addiu    $sp, $sp, 0x50
/* E26D9C 802B668C 00000000 */  nop
