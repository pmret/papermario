.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80147E7C
/* 0DE57C 80147E7C 3C028016 */  lui   $v0, 0x8016
/* 0DE580 80147E80 24429D50 */  addiu $v0, $v0, -0x62b0
/* 0DE584 80147E84 00042140 */  sll   $a0, $a0, 5
/* 0DE588 80147E88 00822021 */  addu  $a0, $a0, $v0
/* 0DE58C 80147E8C 90830000 */  lbu   $v1, ($a0)
/* 0DE590 80147E90 30620001 */  andi  $v0, $v1, 1
/* 0DE594 80147E94 10400009 */  beqz  $v0, .L80147EBC
/* 0DE598 80147E98 00000000 */   nop   
/* 0DE59C 80147E9C 8C820004 */  lw    $v0, 4($a0)
/* 0DE5A0 80147EA0 14A20004 */  bne   $a1, $v0, .L80147EB4
/* 0DE5A4 80147EA4 3462000A */   ori   $v0, $v1, 0xa
/* 0DE5A8 80147EA8 306200FD */  andi  $v0, $v1, 0xfd
/* 0DE5AC 80147EAC 03E00008 */  jr    $ra
/* 0DE5B0 80147EB0 A0820000 */   sb    $v0, ($a0)

.L80147EB4:
/* 0DE5B4 80147EB4 A0820000 */  sb    $v0, ($a0)
/* 0DE5B8 80147EB8 AC850008 */  sw    $a1, 8($a0)
.L80147EBC:
/* 0DE5BC 80147EBC 03E00008 */  jr    $ra
/* 0DE5C0 80147EC0 00000000 */   nop   

