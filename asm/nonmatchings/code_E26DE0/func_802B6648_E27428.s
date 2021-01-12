.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B6648_E27428
/* E27428 802B6648 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* E2742C 802B664C 3C048011 */  lui       $a0, %hi(gPlayerStatus)
/* E27430 802B6650 2484EFC8 */  addiu     $a0, $a0, %lo(gPlayerStatus)
/* E27434 802B6654 27A50028 */  addiu     $a1, $sp, 0x28
/* E27438 802B6658 27A6002C */  addiu     $a2, $sp, 0x2c
/* E2743C 802B665C 27A70030 */  addiu     $a3, $sp, 0x30
/* E27440 802B6660 AFBF0048 */  sw        $ra, 0x48($sp)
/* E27444 802B6664 848200B0 */  lh        $v0, 0xb0($a0)
/* E27448 802B6668 3C013F00 */  lui       $at, 0x3f00
/* E2744C 802B666C 44811000 */  mtc1      $at, $f2
/* E27450 802B6670 C4800028 */  lwc1      $f0, 0x28($a0)
/* E27454 802B6674 44823000 */  mtc1      $v0, $f6
/* E27458 802B6678 00000000 */  nop
/* E2745C 802B667C 468031A0 */  cvt.s.w   $f6, $f6
/* E27460 802B6680 46023082 */  mul.s     $f2, $f6, $f2
/* E27464 802B6684 00000000 */  nop
/* E27468 802B6688 27A20034 */  addiu     $v0, $sp, 0x34
/* E2746C 802B668C E7A00028 */  swc1      $f0, 0x28($sp)
/* E27470 802B6690 C480002C */  lwc1      $f0, 0x2c($a0)
/* E27474 802B6694 C4840030 */  lwc1      $f4, 0x30($a0)
/* E27478 802B6698 46020000 */  add.s     $f0, $f0, $f2
/* E2747C 802B669C E7A60034 */  swc1      $f6, 0x34($sp)
/* E27480 802B66A0 E7A40030 */  swc1      $f4, 0x30($sp)
/* E27484 802B66A4 E7A0002C */  swc1      $f0, 0x2c($sp)
/* E27488 802B66A8 AFA20010 */  sw        $v0, 0x10($sp)
/* E2748C 802B66AC 27A20038 */  addiu     $v0, $sp, 0x38
/* E27490 802B66B0 AFA20014 */  sw        $v0, 0x14($sp)
/* E27494 802B66B4 27A2003C */  addiu     $v0, $sp, 0x3c
/* E27498 802B66B8 AFA20018 */  sw        $v0, 0x18($sp)
/* E2749C 802B66BC 27A20040 */  addiu     $v0, $sp, 0x40
/* E274A0 802B66C0 AFA2001C */  sw        $v0, 0x1c($sp)
/* E274A4 802B66C4 27A20044 */  addiu     $v0, $sp, 0x44
/* E274A8 802B66C8 0C03791B */  jal       func_800DE46C
/* E274AC 802B66CC AFA20020 */   sw       $v0, 0x20($sp)
/* E274B0 802B66D0 8FBF0048 */  lw        $ra, 0x48($sp)
/* E274B4 802B66D4 03E00008 */  jr        $ra
/* E274B8 802B66D8 27BD0050 */   addiu    $sp, $sp, 0x50
/* E274BC 802B66DC 00000000 */  nop
