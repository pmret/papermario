.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8024C318
/* 13F658 8024C318 8FBF0024 */  lw    $ra, 0x24($sp)
/* 13F65C 8024C31C 8FB40020 */  lw    $s4, 0x20($sp)
/* 13F660 8024C320 8FB3001C */  lw    $s3, 0x1c($sp)
/* 13F664 8024C324 8FB20018 */  lw    $s2, 0x18($sp)
/* 13F668 8024C328 8FB10014 */  lw    $s1, 0x14($sp)
/* 13F66C 8024C32C 8FB00010 */  lw    $s0, 0x10($sp)
/* 13F670 8024C330 03E00008 */  jr    $ra
/* 13F674 8024C334 27BD0028 */   addiu $sp, $sp, 0x28

/* 13F678 8024C338 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 13F67C 8024C33C AFB10014 */  sw    $s1, 0x14($sp)
/* 13F680 8024C340 3C118027 */  lui   $s1, 0x8027
/* 13F684 8024C344 263106B0 */  addiu $s1, $s1, 0x6b0
/* 13F688 8024C348 AFBF0018 */  sw    $ra, 0x18($sp)
/* 13F68C 8024C34C AFB00010 */  sw    $s0, 0x10($sp)
/* 13F690 8024C350 8E220000 */  lw    $v0, ($s1)
/* 13F694 8024C354 28420002 */  slti  $v0, $v0, 2
/* 13F698 8024C358 14400047 */  bnez  $v0, .L8024C478
/* 13F69C 8024C35C 00000000 */   nop   
/* 13F6A0 8024C360 3C028027 */  lui   $v0, 0x8027
/* 13F6A4 8024C364 8C4206AC */  lw    $v0, 0x6ac($v0)
/* 13F6A8 8024C368 10400006 */  beqz  $v0, .L8024C384
/* 13F6AC 8024C36C 00000000 */   nop   
/* 13F6B0 8024C370 3C028027 */  lui   $v0, 0x8027
/* 13F6B4 8024C374 8C4200C0 */  lw    $v0, 0xc0($v0)
/* 13F6B8 8024C378 30422010 */  andi  $v0, $v0, 0x2010
/* 13F6BC 8024C37C 1040003E */  beqz  $v0, .L8024C478
/* 13F6C0 8024C380 00000000 */   nop   
.L8024C384:
/* 13F6C4 8024C384 3C038027 */  lui   $v1, 0x8027
/* 13F6C8 8024C388 8C6300C0 */  lw    $v1, 0xc0($v1)
