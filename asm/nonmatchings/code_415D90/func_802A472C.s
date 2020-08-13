.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_802A472C
/* 4194BC 802A472C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 4194C0 802A4730 24040006 */  addiu $a0, $zero, 6
/* 4194C4 802A4734 24050002 */  addiu $a1, $zero, 2
/* 4194C8 802A4738 AFBF0018 */  sw    $ra, 0x18($sp)
/* 4194CC 802A473C AFB10014 */  sw    $s1, 0x14($sp)
/* 4194D0 802A4740 0C051F9F */  jal   func_80147E7C
/* 4194D4 802A4744 AFB00010 */   sw    $s0, 0x10($sp)
/* 4194D8 802A4748 24040007 */  addiu $a0, $zero, 7
/* 4194DC 802A474C 0C051F9F */  jal   func_80147E7C
/* 4194E0 802A4750 24050002 */   addiu $a1, $zero, 2
/* 4194E4 802A4754 24040008 */  addiu $a0, $zero, 8
/* 4194E8 802A4758 0C051F9F */  jal   func_80147E7C
/* 4194EC 802A475C 24050002 */   addiu $a1, $zero, 2
/* 4194F0 802A4760 3C02802B */  lui   $v0, 0x802b
/* 4194F4 802A4764 8C42D66C */  lw    $v0, -0x2994($v0)
/* 4194F8 802A4768 1840000C */  blez  $v0, .L802A479C
/* 4194FC 802A476C 0000802D */   daddu $s0, $zero, $zero
/* 419500 802A4770 3C11802B */  lui   $s1, 0x802b
/* 419504 802A4774 2631D628 */  addiu $s1, $s1, -0x29d8
.L802A4778:
/* 419508 802A4778 8E240000 */  lw    $a0, ($s1)
/* 41950C 802A477C 0C05123D */  jal   free_icon
/* 419510 802A4780 26310004 */   addiu $s1, $s1, 4
/* 419514 802A4784 3C02802B */  lui   $v0, 0x802b
/* 419518 802A4788 8C42D66C */  lw    $v0, -0x2994($v0)
/* 41951C 802A478C 26100001 */  addiu $s0, $s0, 1
/* 419520 802A4790 0202102A */  slt   $v0, $s0, $v0
/* 419524 802A4794 1440FFF8 */  bnez  $v0, .L802A4778
/* 419528 802A4798 00000000 */   nop   
.L802A479C:
/* 41952C 802A479C 3C04802B */  lui   $a0, 0x802b
/* 419530 802A47A0 8C84D618 */  lw    $a0, -0x29e8($a0)
/* 419534 802A47A4 0C05123D */  jal   free_icon
/* 419538 802A47A8 00000000 */   nop   
/* 41953C 802A47AC 3C04802B */  lui   $a0, 0x802b
/* 419540 802A47B0 8C84D61C */  lw    $a0, -0x29e4($a0)
/* 419544 802A47B4 0C05123D */  jal   free_icon
/* 419548 802A47B8 00000000 */   nop   
/* 41954C 802A47BC 3C04802B */  lui   $a0, 0x802b
/* 419550 802A47C0 8C84D620 */  lw    $a0, -0x29e0($a0)
/* 419554 802A47C4 0C05123D */  jal   free_icon
/* 419558 802A47C8 00000000 */   nop   
/* 41955C 802A47CC 8FBF0018 */  lw    $ra, 0x18($sp)
/* 419560 802A47D0 8FB10014 */  lw    $s1, 0x14($sp)
/* 419564 802A47D4 8FB00010 */  lw    $s0, 0x10($sp)
/* 419568 802A47D8 03E00008 */  jr    $ra
/* 41956C 802A47DC 27BD0020 */   addiu $sp, $sp, 0x20

