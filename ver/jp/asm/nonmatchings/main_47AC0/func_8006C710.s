.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006C710
/* 47B10 8006C710 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 47B14 8006C714 AFB20018 */  sw        $s2, 0x18($sp)
/* 47B18 8006C718 00809021 */  addu      $s2, $a0, $zero
/* 47B1C 8006C71C AFB00010 */  sw        $s0, 0x10($sp)
/* 47B20 8006C720 00A08021 */  addu      $s0, $a1, $zero
/* 47B24 8006C724 AFB10014 */  sw        $s1, 0x14($sp)
/* 47B28 8006C728 00C08821 */  addu      $s1, $a2, $zero
/* 47B2C 8006C72C AFB3001C */  sw        $s3, 0x1c($sp)
/* 47B30 8006C730 AFBF0020 */  sw        $ra, 0x20($sp)
/* 47B34 8006C734 0C01B1A8 */  jal       func_8006C6A0
/* 47B38 8006C738 00E09821 */   addu     $s3, $a3, $zero
/* 47B3C 8006C73C 14400010 */  bnez      $v0, .L8006C780
/* 47B40 8006C740 2402FFFF */   addiu    $v0, $zero, -1
/* 47B44 8006C744 3C02A404 */  lui       $v0, 0xa404
/* 47B48 8006C748 02202021 */  addu      $a0, $s1, $zero
/* 47B4C 8006C74C 0C018798 */  jal       func_80061E60
/* 47B50 8006C750 AC500000 */   sw       $s0, ($v0)
/* 47B54 8006C754 3C03A404 */  lui       $v1, 0xa404
/* 47B58 8006C758 34630004 */  ori       $v1, $v1, 4
/* 47B5C 8006C75C AC620000 */  sw        $v0, ($v1)
/* 47B60 8006C760 16400003 */  bnez      $s2, .L8006C770
/* 47B64 8006C764 3C03A404 */   lui      $v1, 0xa404
/* 47B68 8006C768 0801B1DD */  j         .L8006C774
/* 47B6C 8006C76C 3463000C */   ori      $v1, $v1, 0xc
.L8006C770:
/* 47B70 8006C770 34630008 */  ori       $v1, $v1, 8
.L8006C774:
/* 47B74 8006C774 2662FFFF */  addiu     $v0, $s3, -1
/* 47B78 8006C778 AC620000 */  sw        $v0, ($v1)
/* 47B7C 8006C77C 00001021 */  addu      $v0, $zero, $zero
.L8006C780:
/* 47B80 8006C780 8FBF0020 */  lw        $ra, 0x20($sp)
/* 47B84 8006C784 8FB3001C */  lw        $s3, 0x1c($sp)
/* 47B88 8006C788 8FB20018 */  lw        $s2, 0x18($sp)
/* 47B8C 8006C78C 8FB10014 */  lw        $s1, 0x14($sp)
/* 47B90 8006C790 8FB00010 */  lw        $s0, 0x10($sp)
/* 47B94 8006C794 03E00008 */  jr        $ra
/* 47B98 8006C798 27BD0028 */   addiu    $sp, $sp, 0x28
/* 47B9C 8006C79C 00000000 */  nop
