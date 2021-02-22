.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021B60C_6A280C
/* 6A280C 8021B60C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6A2810 8021B610 AFBF0010 */  sw        $ra, 0x10($sp)
/* 6A2814 8021B614 8C82000C */  lw        $v0, 0xc($a0)
/* 6A2818 8021B618 0C0B1EAF */  jal       get_variable
/* 6A281C 8021B61C 8C450000 */   lw       $a1, ($v0)
/* 6A2820 8021B620 8C43000C */  lw        $v1, 0xc($v0)
/* 6A2824 8021B624 3C013D23 */  lui       $at, 0x3d23
/* 6A2828 8021B628 3421D70A */  ori       $at, $at, 0xd70a
/* 6A282C 8021B62C 44810000 */  mtc1      $at, $f0
/* 6A2830 8021B630 00000000 */  nop
/* 6A2834 8021B634 E4600038 */  swc1      $f0, 0x38($v1)
/* 6A2838 8021B638 E4600030 */  swc1      $f0, 0x30($v1)
/* 6A283C 8021B63C 8C43000C */  lw        $v1, 0xc($v0)
/* 6A2840 8021B640 3C013FF0 */  lui       $at, 0x3ff0
/* 6A2844 8021B644 44810000 */  mtc1      $at, $f0
/* 6A2848 8021B648 00000000 */  nop
/* 6A284C 8021B64C E4600034 */  swc1      $f0, 0x34($v1)
/* 6A2850 8021B650 8C43000C */  lw        $v1, 0xc($v0)
/* 6A2854 8021B654 3C013D4C */  lui       $at, 0x3d4c
/* 6A2858 8021B658 3421CCCD */  ori       $at, $at, 0xcccd
/* 6A285C 8021B65C 44810000 */  mtc1      $at, $f0
/* 6A2860 8021B660 00000000 */  nop
/* 6A2864 8021B664 E460003C */  swc1      $f0, 0x3c($v1)
/* 6A2868 8021B668 8FBF0010 */  lw        $ra, 0x10($sp)
/* 6A286C 8021B66C 24020002 */  addiu     $v0, $zero, 2
/* 6A2870 8021B670 03E00008 */  jr        $ra
/* 6A2874 8021B674 27BD0018 */   addiu    $sp, $sp, 0x18
