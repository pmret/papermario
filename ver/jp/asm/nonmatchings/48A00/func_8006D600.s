.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006D600
/* 48A00 8006D600 00A6001A */  div       $zero, $a1, $a2
/* 48A04 8006D604 14C00002 */  bnez      $a2, .L8006D610
/* 48A08 8006D608 00000000 */   nop
/* 48A0C 8006D60C 0007000D */  break     7
.L8006D610:
/* 48A10 8006D610 2401FFFF */   addiu    $at, $zero, -1
/* 48A14 8006D614 14C10004 */  bne       $a2, $at, .L8006D628
/* 48A18 8006D618 3C018000 */   lui      $at, 0x8000
/* 48A1C 8006D61C 14A10002 */  bne       $a1, $at, .L8006D628
/* 48A20 8006D620 00000000 */   nop
/* 48A24 8006D624 0006000D */  break     6
.L8006D628:
/* 48A28 8006D628 00001812 */   mflo     $v1
/* 48A2C 8006D62C 00000000 */  nop
/* 48A30 8006D630 00000000 */  nop
/* 48A34 8006D634 00C30018 */  mult      $a2, $v1
/* 48A38 8006D638 00001012 */  mflo      $v0
/* 48A3C 8006D63C 27BDFFF8 */  addiu     $sp, $sp, -8
/* 48A40 8006D640 00803821 */  addu      $a3, $a0, $zero
/* 48A44 8006D644 AFA30000 */  sw        $v1, ($sp)
/* 48A48 8006D648 00A22823 */  subu      $a1, $a1, $v0
/* 48A4C 8006D64C 04610006 */  bgez      $v1, .L8006D668
/* 48A50 8006D650 AFA50004 */   sw       $a1, 4($sp)
/* 48A54 8006D654 18A00004 */  blez      $a1, .L8006D668
/* 48A58 8006D658 24620001 */   addiu    $v0, $v1, 1
/* 48A5C 8006D65C AFA20000 */  sw        $v0, ($sp)
/* 48A60 8006D660 00A61023 */  subu      $v0, $a1, $a2
/* 48A64 8006D664 AFA20004 */  sw        $v0, 4($sp)
.L8006D668:
/* 48A68 8006D668 8FA20000 */  lw        $v0, ($sp)
/* 48A6C 8006D66C 8FA30004 */  lw        $v1, 4($sp)
/* 48A70 8006D670 ACE20000 */  sw        $v0, ($a3)
/* 48A74 8006D674 ACE30004 */  sw        $v1, 4($a3)
/* 48A78 8006D678 00E01021 */  addu      $v0, $a3, $zero
/* 48A7C 8006D67C 03E00008 */  jr        $ra
/* 48A80 8006D680 27BD0008 */   addiu    $sp, $sp, 8
