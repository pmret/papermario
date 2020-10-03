.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055618
/* 30A18 80055618 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 30A1C 8005561C AFB10014 */  sw        $s1, 0x14($sp)
/* 30A20 80055620 0080882D */  daddu     $s1, $a0, $zero
/* 30A24 80055624 AFB20018 */  sw        $s2, 0x18($sp)
/* 30A28 80055628 00A0902D */  daddu     $s2, $a1, $zero
/* 30A2C 8005562C AFBF001C */  sw        $ra, 0x1c($sp)
/* 30A30 80055630 0C01430C */  jal       func_80050C30
/* 30A34 80055634 AFB00010 */   sw       $s0, 0x10($sp)
/* 30A38 80055638 0040802D */  daddu     $s0, $v0, $zero
/* 30A3C 8005563C 16000005 */  bnez      $s0, .L80055654
/* 30A40 80055640 0200102D */   daddu    $v0, $s0, $zero
/* 30A44 80055644 0220202D */  daddu     $a0, $s1, $zero
/* 30A48 80055648 0C014315 */  jal       func_80050C54
/* 30A4C 8005564C 0240282D */   daddu    $a1, $s2, $zero
/* 30A50 80055650 0200102D */  daddu     $v0, $s0, $zero
.L80055654:
/* 30A54 80055654 8FBF001C */  lw        $ra, 0x1c($sp)
/* 30A58 80055658 8FB20018 */  lw        $s2, 0x18($sp)
/* 30A5C 8005565C 8FB10014 */  lw        $s1, 0x14($sp)
/* 30A60 80055660 8FB00010 */  lw        $s0, 0x10($sp)
/* 30A64 80055664 03E00008 */  jr        $ra
/* 30A68 80055668 27BD0020 */   addiu    $sp, $sp, 0x20
