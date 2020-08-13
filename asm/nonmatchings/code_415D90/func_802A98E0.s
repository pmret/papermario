.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_802A98E0
/* 41E670 802A98E0 10620070 */  beq   $v1, $v0, .L802A9AA4
/* 41E674 802A98E4 24020024 */   addiu $v0, $zero, 0x24
/* 41E678 802A98E8 10600070 */  beqz  $v1, .L802A9AAC
/* 41E67C 802A98EC 240200FF */   addiu $v0, $zero, 0xff
/* 41E680 802A98F0 1462000C */  bne   $v1, $v0, .L802A9924
/* 41E684 802A98F4 24020022 */   addiu $v0, $zero, 0x22
/* 41E688 802A98F8 0C0A91F8 */  jal   func_802A47E0
/* 41E68C 802A98FC 00000000 */   nop   
/* 41E690 802A9900 240200C9 */  addiu $v0, $zero, 0xc9
.L802A9904:
/* 41E694 802A9904 3C01800E */  lui   $at, 0x800e
/* 41E698 802A9908 AC22C4DC */  sw    $v0, -0x3b24($at)
/* 41E69C 802A990C 0C0AA072 */  jal   update_partner_menu
/* 41E6A0 802A9910 00000000 */   nop   
