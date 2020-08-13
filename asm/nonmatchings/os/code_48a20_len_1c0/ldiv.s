.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel ldiv
/* 048A20 8006D620 00A6001A */  div   $zero, $a1, $a2
/* 048A24 8006D624 14C00002 */  bnez  $a2, .L8006D630
/* 048A28 8006D628 00000000 */   nop   
/* 048A2C 8006D62C 0007000D */  break 7
.L8006D630:
/* 048A30 8006D630 2401FFFF */  addiu $at, $zero, -1
/* 048A34 8006D634 14C10004 */  bne   $a2, $at, .L8006D648
/* 048A38 8006D638 3C018000 */   lui   $at, 0x8000
/* 048A3C 8006D63C 14A10002 */  bne   $a1, $at, .L8006D648
/* 048A40 8006D640 00000000 */   nop   
/* 048A44 8006D644 0006000D */  break 6
.L8006D648:
/* 048A48 8006D648 00001812 */  mflo  $v1
/* 048A4C 8006D64C 00000000 */  nop   
/* 048A50 8006D650 00000000 */  nop   
/* 048A54 8006D654 00C30018 */  mult  $a2, $v1
/* 048A58 8006D658 00001012 */  mflo  $v0
/* 048A5C 8006D65C 27BDFFF8 */  addiu $sp, $sp, -8
/* 048A60 8006D660 00803821 */  addu  $a3, $a0, $zero
/* 048A64 8006D664 AFA30000 */  sw    $v1, ($sp)
/* 048A68 8006D668 00A22823 */  subu  $a1, $a1, $v0
/* 048A6C 8006D66C 04610006 */  bgez  $v1, .L8006D688
/* 048A70 8006D670 AFA50004 */   sw    $a1, 4($sp)
/* 048A74 8006D674 18A00004 */  blez  $a1, .L8006D688
/* 048A78 8006D678 24620001 */   addiu $v0, $v1, 1
/* 048A7C 8006D67C AFA20000 */  sw    $v0, ($sp)
/* 048A80 8006D680 00A61023 */  subu  $v0, $a1, $a2
/* 048A84 8006D684 AFA20004 */  sw    $v0, 4($sp)
.L8006D688:
/* 048A88 8006D688 8FA20000 */  lw    $v0, ($sp)
/* 048A8C 8006D68C 8FA30004 */  lw    $v1, 4($sp)
/* 048A90 8006D690 ACE20000 */  sw    $v0, ($a3)
/* 048A94 8006D694 ACE30004 */  sw    $v1, 4($a3)
/* 048A98 8006D698 00E01021 */  addu  $v0, $a3, $zero
/* 048A9C 8006D69C 03E00008 */  jr    $ra
/* 048AA0 8006D6A0 27BD0008 */   addiu $sp, $sp, 8

