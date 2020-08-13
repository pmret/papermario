.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel LoadBattleSection
/* 1986C4 80269DE4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 1986C8 80269DE8 AFBF0010 */  sw    $ra, 0x10($sp)
/* 1986CC 80269DEC 8C82000C */  lw    $v0, 0xc($a0)
/* 1986D0 80269DF0 0C0B1EAF */  jal   get_variable
/* 1986D4 80269DF4 8C450000 */   lw    $a1, ($v0)
/* 1986D8 80269DF8 3C038009 */  lui   $v1, 0x8009
/* 1986DC 80269DFC 24635A30 */  addiu $v1, $v1, 0x5a30
/* 1986E0 80269E00 00021140 */  sll   $v0, $v0, 5
/* 1986E4 80269E04 00431021 */  addu  $v0, $v0, $v1
/* 1986E8 80269E08 8C440004 */  lw    $a0, 4($v0)
/* 1986EC 80269E0C 8C450008 */  lw    $a1, 8($v0)
/* 1986F0 80269E10 0C00A5CF */  jal   dma_copy
/* 1986F4 80269E14 8C46000C */   lw    $a2, 0xc($v0)
/* 1986F8 80269E18 8FBF0010 */  lw    $ra, 0x10($sp)
/* 1986FC 80269E1C 24020001 */  addiu $v0, $zero, 1
/* 198700 80269E20 03E00008 */  jr    $ra
/* 198704 80269E24 27BD0018 */   addiu $sp, $sp, 0x18

