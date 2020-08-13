.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80034BFC
/* 00FFFC 80034BFC 3C02800A */  lui   $v0, 0x800a
/* 010000 80034C00 84420922 */  lh    $v0, 0x922($v0)
/* 010004 80034C04 18400005 */  blez  $v0, .L80034C1C
/* 010008 80034C08 24020004 */   addiu $v0, $zero, 4
/* 01000C 80034C0C 3C01800A */  lui   $at, 0x800a
/* 010010 80034C10 A0200921 */  sb    $zero, 0x921($at)
/* 010014 80034C14 0800D30B */  j     .L80034C2C
/* 010018 80034C18 00000000 */   nop   

.L80034C1C:
/* 01001C 80034C1C 24020001 */  addiu $v0, $zero, 1
/* 010020 80034C20 3C01800A */  lui   $at, 0x800a
/* 010024 80034C24 A0220921 */  sb    $v0, 0x921($at)
/* 010028 80034C28 24020004 */  addiu $v0, $zero, 4
.L80034C2C:
/* 01002C 80034C2C 3C01800A */  lui   $at, 0x800a
/* 010030 80034C30 A0220920 */  sb    $v0, 0x920($at)
/* 010034 80034C34 03E00008 */  jr    $ra
/* 010038 80034C38 00000000 */   nop   

