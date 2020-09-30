.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80110678
/* A6D78 80110678 0080282D */  daddu     $a1, $a0, $zero
/* A6D7C 8011067C 8CA20028 */  lw        $v0, 0x28($a1)
/* A6D80 80110680 14400003 */  bnez      $v0, .L80110690
/* A6D84 80110684 24020001 */   addiu    $v0, $zero, 1
/* A6D88 80110688 03E00008 */  jr        $ra
/* A6D8C 8011068C 0000102D */   daddu    $v0, $zero, $zero
.L80110690:
/* A6D90 80110690 8CA30000 */  lw        $v1, ($a1)
/* A6D94 80110694 3C040100 */  lui       $a0, 0x100
/* A6D98 80110698 00641825 */  or        $v1, $v1, $a0
/* A6D9C 8011069C 03E00008 */  jr        $ra
/* A6DA0 801106A0 ACA30000 */   sw       $v1, ($a1)
