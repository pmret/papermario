.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E1614
/* 102E94 802E1614 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 102E98 802E1618 AFBF0010 */  sw        $ra, 0x10($sp)
/* 102E9C 802E161C 90820006 */  lbu       $v0, 6($a0)
/* 102EA0 802E1620 30420001 */  andi      $v0, $v0, 1
/* 102EA4 802E1624 1040000B */  beqz      $v0, .L802E1654
/* 102EA8 802E1628 00000000 */   nop
/* 102EAC 802E162C 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* 102EB0 802E1630 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* 102EB4 802E1634 804300B4 */  lb        $v1, 0xb4($v0)
/* 102EB8 802E1638 2402000E */  addiu     $v0, $zero, 0xe
/* 102EBC 802E163C 10620003 */  beq       $v1, $v0, .L802E164C
/* 102EC0 802E1640 24020010 */   addiu    $v0, $zero, 0x10
/* 102EC4 802E1644 14620003 */  bne       $v1, $v0, .L802E1654
/* 102EC8 802E1648 00000000 */   nop
.L802E164C:
/* 102ECC 802E164C 0C043F5A */  jal       func_8010FD68
/* 102ED0 802E1650 00000000 */   nop
.L802E1654:
/* 102ED4 802E1654 8FBF0010 */  lw        $ra, 0x10($sp)
/* 102ED8 802E1658 03E00008 */  jr        $ra
/* 102EDC 802E165C 27BD0018 */   addiu    $sp, $sp, 0x18
