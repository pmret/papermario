.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel fio_load_game
/* 0066D0 8002B2D0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0066D4 8002B2D4 AFB20018 */  sw    $s2, 0x18($sp)
/* 0066D8 8002B2D8 3C128007 */  lui   $s2, 0x8007
/* 0066DC 8002B2DC 2652419C */  addiu $s2, $s2, 0x419c
/* 0066E0 8002B2E0 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0066E4 8002B2E4 AFB10014 */  sw    $s1, 0x14($sp)
/* 0066E8 8002B2E8 AFB00010 */  sw    $s0, 0x10($sp)
/* 0066EC 8002B2EC 8E420000 */  lw    $v0, ($s2)
/* 0066F0 8002B2F0 0080802D */  daddu $s0, $a0, $zero
/* 0066F4 8002B2F4 0C00AC55 */  jal   fio_fetch_saved_file_info
/* 0066F8 8002B2F8 A0500166 */   sb    $s0, 0x166($v0)
/* 0066FC 8002B2FC 3C11800E */  lui   $s1, 0x800e
/* 006700 8002B300 2631ACC0 */  addiu $s1, $s1, -0x5340
/* 006704 8002B304 0220282D */  daddu $a1, $s1, $zero
/* 006708 8002B308 001080C0 */  sll   $s0, $s0, 3
/* 00670C 8002B30C 3C04800A */  lui   $a0, 0x800a
/* 006710 8002B310 00902021 */  addu  $a0, $a0, $s0
/* 006714 8002B314 8C84BA30 */  lw    $a0, -0x45d0($a0)
/* 006718 8002B318 0C00AE1A */  jal   fio_read_flash
/* 00671C 8002B31C 24061380 */   addiu $a2, $zero, 0x1380
/* 006720 8002B320 3C058007 */  lui   $a1, 0x8007
/* 006724 8002B324 24A545D0 */  addiu $a1, $a1, 0x45d0
/* 006728 8002B328 0C01BB5C */  jal   strcmp
/* 00672C 8002B32C 0220202D */   daddu $a0, $s1, $zero
/* 006730 8002B330 1440000A */  bnez  $v0, .L8002B35C
/* 006734 8002B334 0000102D */   daddu $v0, $zero, $zero
/* 006738 8002B338 8E430000 */  lw    $v1, ($s2)
/* 00673C 8002B33C 8E24003C */  lw    $a0, 0x3c($s1)
/* 006740 8002B340 8C620168 */  lw    $v0, 0x168($v1)
/* 006744 8002B344 0044102B */  sltu  $v0, $v0, $a0
/* 006748 8002B348 54400001 */  bnel  $v0, $zero, .L8002B350
/* 00674C 8002B34C AC640168 */   sw    $a0, 0x168($v1)
.L8002B350:
/* 006750 8002B350 0C00AD24 */  jal   fio_deserialize_state
/* 006754 8002B354 00000000 */   nop   
/* 006758 8002B358 24020001 */  addiu $v0, $zero, 1
.L8002B35C:
/* 00675C 8002B35C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 006760 8002B360 8FB20018 */  lw    $s2, 0x18($sp)
/* 006764 8002B364 8FB10014 */  lw    $s1, 0x14($sp)
/* 006768 8002B368 8FB00010 */  lw    $s0, 0x10($sp)
/* 00676C 8002B36C 03E00008 */  jr    $ra
/* 006770 8002B370 27BD0020 */   addiu $sp, $sp, 0x20

