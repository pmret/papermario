.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel osSiRawWriteIo
/* 047C10 8006C810 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 047C14 8006C814 AFB00010 */  sw    $s0, 0x10($sp)
/* 047C18 8006C818 00808021 */  addu  $s0, $a0, $zero
/* 047C1C 8006C81C AFB10014 */  sw    $s1, 0x14($sp)
/* 047C20 8006C820 AFBF0018 */  sw    $ra, 0x18($sp)
/* 047C24 8006C824 0C01B5F8 */  jal   osSiDeviceBusy
/* 047C28 8006C828 00A08821 */   addu  $s1, $a1, $zero
/* 047C2C 8006C82C 54400005 */  bnel  $v0, $zero, .L8006C844
/* 047C30 8006C830 2402FFFF */   addiu $v0, $zero, -1
/* 047C34 8006C834 3C02A000 */  lui   $v0, 0xa000
/* 047C38 8006C838 02021025 */  or    $v0, $s0, $v0
/* 047C3C 8006C83C AC510000 */  sw    $s1, ($v0)
/* 047C40 8006C840 00001021 */  addu  $v0, $zero, $zero
.L8006C844:
/* 047C44 8006C844 8FBF0018 */  lw    $ra, 0x18($sp)
/* 047C48 8006C848 8FB10014 */  lw    $s1, 0x14($sp)
/* 047C4C 8006C84C 8FB00010 */  lw    $s0, 0x10($sp)
/* 047C50 8006C850 03E00008 */  jr    $ra
/* 047C54 8006C854 27BD0020 */   addiu $sp, $sp, 0x20

/* 047C58 8006C858 00000000 */  nop   
/* 047C5C 8006C85C 00000000 */  nop   


