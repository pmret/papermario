.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel store_item
/* 080C74 800E77C4 0000182D */  daddu $v1, $zero, $zero
/* 080C78 800E77C8 3C068011 */  lui   $a2, 0x8011
/* 080C7C 800E77CC 24C6F290 */  addiu $a2, $a2, -0xd70
/* 080C80 800E77D0 00C0282D */  daddu $a1, $a2, $zero
.L800E77D4:
/* 080C84 800E77D4 84A201C8 */  lh    $v0, 0x1c8($a1)
/* 080C88 800E77D8 10400006 */  beqz  $v0, .L800E77F4
/* 080C8C 800E77DC 24020020 */   addiu $v0, $zero, 0x20
/* 080C90 800E77E0 24630001 */  addiu $v1, $v1, 1
/* 080C94 800E77E4 28620020 */  slti  $v0, $v1, 0x20
/* 080C98 800E77E8 1440FFFA */  bnez  $v0, .L800E77D4
/* 080C9C 800E77EC 24A50002 */   addiu $a1, $a1, 2
/* 080CA0 800E77F0 24020020 */  addiu $v0, $zero, 0x20
.L800E77F4:
/* 080CA4 800E77F4 10620005 */  beq   $v1, $v0, .L800E780C
/* 080CA8 800E77F8 00031040 */   sll   $v0, $v1, 1
/* 080CAC 800E77FC 00C21021 */  addu  $v0, $a2, $v0
/* 080CB0 800E7800 A44401C8 */  sh    $a0, 0x1c8($v0)
/* 080CB4 800E7804 03E00008 */  jr    $ra
/* 080CB8 800E7808 0060102D */   daddu $v0, $v1, $zero

.L800E780C:
/* 080CBC 800E780C 03E00008 */  jr    $ra
/* 080CC0 800E7810 2402FFFF */   addiu $v0, $zero, -1

