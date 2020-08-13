.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8024BD78
/* 13F0B8 8024BD78 00031880 */  sll   $v1, $v1, 2
/* 13F0BC 8024BD7C 3C018027 */  lui   $at, 0x8027
/* 13F0C0 8024BD80 00230821 */  addu  $at, $at, $v1
/* 13F0C4 8024BD84 8C230680 */  lw    $v1, 0x680($at)
/* 13F0C8 8024BD88 00031880 */  sll   $v1, $v1, 2
/* 13F0CC 8024BD8C 3C018025 */  lui   $at, 0x8025
/* 13F0D0 8024BD90 00230821 */  addu  $at, $at, $v1
/* 13F0D4 8024BD94 8C23F6B0 */  lw    $v1, -0x950($at)
/* 13F0D8 8024BD98 000318C0 */  sll   $v1, $v1, 3
/* 13F0DC 8024BD9C 00431021 */  addu  $v0, $v0, $v1
/* 13F0E0 8024BDA0 80550015 */  lb    $s5, 0x15($v0)
/* 13F0E4 8024BDA4 24020002 */  addiu $v0, $zero, 2
/* 13F0E8 8024BDA8 16A20003 */  bne   $s5, $v0, .L8024BDB8
/* 13F0EC 8024BDAC 24020001 */   addiu $v0, $zero, 1
/* 13F0F0 8024BDB0 08092F74 */  j     func_8024BDD0
/* 13F0F4 8024BDB4 24150004 */   addiu $s5, $zero, 4

.L8024BDB8:
/* 13F0F8 8024BDB8 16A20003 */  bne   $s5, $v0, .L8024BDC8
/* 13F0FC 8024BDBC 00000000 */   nop   
/* 13F100 8024BDC0 08092F74 */  j     func_8024BDD0
/* 13F104 8024BDC4 24150003 */   addiu $s5, $zero, 3

.L8024BDC8:
/* 13F108 8024BDC8 52A00001 */  beql  $s5, $zero, .L8024BDD0
/* 13F10C 8024BDCC 24150002 */   addiu $s5, $zero, 2
