.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel fio_erase_game
/* 00682C 8002B42C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 006830 8002B430 AFB20018 */  sw    $s2, 0x18($sp)
/* 006834 8002B434 0080902D */  daddu $s2, $a0, $zero
/* 006838 8002B438 AFBF001C */  sw    $ra, 0x1c($sp)
/* 00683C 8002B43C AFB10014 */  sw    $s1, 0x14($sp)
/* 006840 8002B440 0C00AC55 */  jal   fio_fetch_saved_file_info
/* 006844 8002B444 AFB00010 */   sw    $s0, 0x10($sp)
/* 006848 8002B448 0000802D */  daddu $s0, $zero, $zero
/* 00684C 8002B44C 3C11800A */  lui   $s1, 0x800a
/* 006850 8002B450 2631BA50 */  addiu $s1, $s1, -0x45b0
.L8002B454:
/* 006854 8002B454 8E220000 */  lw    $v0, ($s1)
/* 006858 8002B458 54520004 */  bnel  $v0, $s2, .L8002B46C
/* 00685C 8002B45C 26100001 */   addiu $s0, $s0, 1
/* 006860 8002B460 0C00AE87 */  jal   fio_erase_flash
/* 006864 8002B464 0200202D */   daddu $a0, $s0, $zero
/* 006868 8002B468 26100001 */  addiu $s0, $s0, 1
.L8002B46C:
/* 00686C 8002B46C 2A020006 */  slti  $v0, $s0, 6
/* 006870 8002B470 1440FFF8 */  bnez  $v0, .L8002B454
/* 006874 8002B474 26310008 */   addiu $s1, $s1, 8
/* 006878 8002B478 8FBF001C */  lw    $ra, 0x1c($sp)
/* 00687C 8002B47C 8FB20018 */  lw    $s2, 0x18($sp)
/* 006880 8002B480 8FB10014 */  lw    $s1, 0x14($sp)
/* 006884 8002B484 8FB00010 */  lw    $s0, 0x10($sp)
/* 006888 8002B488 03E00008 */  jr    $ra
/* 00688C 8002B48C 27BD0020 */   addiu $sp, $sp, 0x20

