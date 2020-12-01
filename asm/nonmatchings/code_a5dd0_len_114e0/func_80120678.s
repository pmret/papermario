.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80120678
/* B6D78 80120678 27BDFE00 */  addiu     $sp, $sp, -0x200
/* B6D7C 8012067C AFB001F8 */  sw        $s0, 0x1f8($sp)
/* B6D80 80120680 AFBF01FC */  sw        $ra, 0x1fc($sp)
/* B6D84 80120684 0C047900 */  jal       func_8011E400
/* B6D88 80120688 0080802D */   daddu    $s0, $a0, $zero
/* B6D8C 8012068C 24040079 */  addiu     $a0, $zero, 0x79
/* B6D90 80120690 8E0202C8 */  lw        $v0, 0x2c8($s0)
/* B6D94 80120694 27A301F4 */  addiu     $v1, $sp, 0x1f4
/* B6D98 80120698 3C018015 */  lui       $at, %hi(D_80153B68)
/* B6D9C 8012069C AC223B68 */  sw        $v0, %lo(D_80153B68)($at)
.L801206A0:
/* B6DA0 801206A0 AC600000 */  sw        $zero, ($v1)
/* B6DA4 801206A4 2484FFFF */  addiu     $a0, $a0, -1
/* B6DA8 801206A8 0481FFFD */  bgez      $a0, .L801206A0
/* B6DAC 801206AC 2463FFFC */   addiu    $v1, $v1, -4
/* B6DB0 801206B0 0200282D */  daddu     $a1, $s0, $zero
/* B6DB4 801206B4 8E0202CC */  lw        $v0, 0x2cc($s0)
/* B6DB8 801206B8 0000302D */  daddu     $a2, $zero, $zero
/* B6DBC 801206BC 00021080 */  sll       $v0, $v0, 2
/* B6DC0 801206C0 02021021 */  addu      $v0, $s0, $v0
/* B6DC4 801206C4 8C4400E0 */  lw        $a0, 0xe0($v0)
/* B6DC8 801206C8 0C04814C */  jal       func_80120530
/* B6DCC 801206CC 27A70010 */   addiu    $a3, $sp, 0x10
/* B6DD0 801206D0 0200202D */  daddu     $a0, $s0, $zero
/* B6DD4 801206D4 27A50010 */  addiu     $a1, $sp, 0x10
/* B6DD8 801206D8 2406007A */  addiu     $a2, $zero, 0x7a
/* B6DDC 801206DC 2402FFFF */  addiu     $v0, $zero, -1
/* B6DE0 801206E0 0C047FED */  jal       func_8011FFB4
/* B6DE4 801206E4 AFA20010 */   sw       $v0, 0x10($sp)
/* B6DE8 801206E8 8FBF01FC */  lw        $ra, 0x1fc($sp)
/* B6DEC 801206EC 8FB001F8 */  lw        $s0, 0x1f8($sp)
/* B6DF0 801206F0 03E00008 */  jr        $ra
/* B6DF4 801206F4 27BD0200 */   addiu    $sp, $sp, 0x200
