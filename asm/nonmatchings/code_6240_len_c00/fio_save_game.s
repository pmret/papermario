.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel fio_save_game
/* 006774 8002B374 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 006778 8002B378 AFB20018 */  sw    $s2, 0x18($sp)
/* 00677C 8002B37C 0080902D */  daddu $s2, $a0, $zero
/* 006780 8002B380 AFBF001C */  sw    $ra, 0x1c($sp)
/* 006784 8002B384 AFB10014 */  sw    $s1, 0x14($sp)
/* 006788 8002B388 0C00AC55 */  jal   fio_fetch_saved_file_info
/* 00678C 8002B38C AFB00010 */   sw    $s0, 0x10($sp)
/* 006790 8002B390 3C118007 */  lui   $s1, 0x8007
/* 006794 8002B394 2631419C */  addiu $s1, $s1, 0x419c
/* 006798 8002B398 8E220000 */  lw    $v0, ($s1)
/* 00679C 8002B39C 0C00AD8C */  jal   fio_serialize_state
/* 0067A0 8002B3A0 A0520166 */   sb    $s2, 0x166($v0)
/* 0067A4 8002B3A4 3C10800E */  lui   $s0, 0x800e
/* 0067A8 8002B3A8 2610ACC0 */  addiu $s0, $s0, -0x5340
/* 0067AC 8002B3AC 3C058007 */  lui   $a1, 0x8007
/* 0067B0 8002B3B0 24A545D0 */  addiu $a1, $a1, 0x45d0
/* 0067B4 8002B3B4 0C01BB50 */  jal   strcpy
/* 0067B8 8002B3B8 0200202D */   daddu $a0, $s0, $zero
/* 0067BC 8002B3BC 8E230000 */  lw    $v1, ($s1)
/* 0067C0 8002B3C0 AE120038 */  sw    $s2, 0x38($s0)
/* 0067C4 8002B3C4 8C620168 */  lw    $v0, 0x168($v1)
/* 0067C8 8002B3C8 0200202D */  daddu $a0, $s0, $zero
/* 0067CC 8002B3CC 24420001 */  addiu $v0, $v0, 1
/* 0067D0 8002B3D0 AC620168 */  sw    $v0, 0x168($v1)
/* 0067D4 8002B3D4 AE02003C */  sw    $v0, 0x3c($s0)
/* 0067D8 8002B3D8 2402FFFF */  addiu $v0, $zero, -1
/* 0067DC 8002B3DC AE000030 */  sw    $zero, 0x30($s0)
/* 0067E0 8002B3E0 0C00AC34 */  jal   fio_calc_file_checksum
/* 0067E4 8002B3E4 AE020034 */   sw    $v0, 0x34($s0)
/* 0067E8 8002B3E8 3C11800A */  lui   $s1, 0x800a
/* 0067EC 8002B3EC 2631BA80 */  addiu $s1, $s1, -0x4580
/* 0067F0 8002B3F0 8E240000 */  lw    $a0, ($s1)
/* 0067F4 8002B3F4 AE020030 */  sw    $v0, 0x30($s0)
/* 0067F8 8002B3F8 00021027 */  nor   $v0, $zero, $v0
/* 0067FC 8002B3FC 0C00AE87 */  jal   fio_erase_flash
/* 006800 8002B400 AE020034 */   sw    $v0, 0x34($s0)
/* 006804 8002B404 0200282D */  daddu $a1, $s0, $zero
/* 006808 8002B408 8E240000 */  lw    $a0, ($s1)
/* 00680C 8002B40C 0C00AE52 */  jal   fio_write_flash
/* 006810 8002B410 24061380 */   addiu $a2, $zero, 0x1380
/* 006814 8002B414 8FBF001C */  lw    $ra, 0x1c($sp)
/* 006818 8002B418 8FB20018 */  lw    $s2, 0x18($sp)
/* 00681C 8002B41C 8FB10014 */  lw    $s1, 0x14($sp)
/* 006820 8002B420 8FB00010 */  lw    $s0, 0x10($sp)
/* 006824 8002B424 03E00008 */  jr    $ra
/* 006828 8002B428 27BD0020 */   addiu $sp, $sp, 0x20

