.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fio_load_game
/* 66D0 8002B2D0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 66D4 8002B2D4 AFB20018 */  sw        $s2, 0x18($sp)
/* 66D8 8002B2D8 3C128007 */  lui       $s2, %hi(gGameStatusPtr)
/* 66DC 8002B2DC 2652419C */  addiu     $s2, $s2, %lo(gGameStatusPtr)
/* 66E0 8002B2E0 AFBF001C */  sw        $ra, 0x1c($sp)
/* 66E4 8002B2E4 AFB10014 */  sw        $s1, 0x14($sp)
/* 66E8 8002B2E8 AFB00010 */  sw        $s0, 0x10($sp)
/* 66EC 8002B2EC 8E420000 */  lw        $v0, ($s2)
/* 66F0 8002B2F0 0080802D */  daddu     $s0, $a0, $zero
/* 66F4 8002B2F4 0C00AC55 */  jal       fio_fetch_saved_file_info
/* 66F8 8002B2F8 A0500166 */   sb       $s0, 0x166($v0)
/* 66FC 8002B2FC 3C11800E */  lui       $s1, %hi(gCurrentSaveFile)
/* 6700 8002B300 2631ACC0 */  addiu     $s1, $s1, %lo(gCurrentSaveFile)
/* 6704 8002B304 0220282D */  daddu     $a1, $s1, $zero
/* 6708 8002B308 001080C0 */  sll       $s0, $s0, 3
/* 670C 8002B30C 3C04800A */  lui       $a0, %hi(D_8009BA30)
/* 6710 8002B310 00902021 */  addu      $a0, $a0, $s0
/* 6714 8002B314 8C84BA30 */  lw        $a0, %lo(D_8009BA30)($a0)
/* 6718 8002B318 0C00AE1A */  jal       fio_read_flash
/* 671C 8002B31C 24061380 */   addiu    $a2, $zero, 0x1380
/* 6720 8002B320 3C058007 */  lui       $a1, %hi(D_800745D0)
/* 6724 8002B324 24A545D0 */  addiu     $a1, $a1, %lo(D_800745D0)
/* 6728 8002B328 0C01BB5C */  jal       strcmp
/* 672C 8002B32C 0220202D */   daddu    $a0, $s1, $zero
/* 6730 8002B330 1440000A */  bnez      $v0, .L8002B35C
/* 6734 8002B334 0000102D */   daddu    $v0, $zero, $zero
/* 6738 8002B338 8E430000 */  lw        $v1, ($s2)
/* 673C 8002B33C 8E24003C */  lw        $a0, 0x3c($s1)
/* 6740 8002B340 8C620168 */  lw        $v0, 0x168($v1)
/* 6744 8002B344 0044102B */  sltu      $v0, $v0, $a0
/* 6748 8002B348 54400001 */  bnel      $v0, $zero, .L8002B350
/* 674C 8002B34C AC640168 */   sw       $a0, 0x168($v1)
.L8002B350:
/* 6750 8002B350 0C00AD24 */  jal       fio_deserialize_state
/* 6754 8002B354 00000000 */   nop
/* 6758 8002B358 24020001 */  addiu     $v0, $zero, 1
.L8002B35C:
/* 675C 8002B35C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 6760 8002B360 8FB20018 */  lw        $s2, 0x18($sp)
/* 6764 8002B364 8FB10014 */  lw        $s1, 0x14($sp)
/* 6768 8002B368 8FB00010 */  lw        $s0, 0x10($sp)
/* 676C 8002B36C 03E00008 */  jr        $ra
/* 6770 8002B370 27BD0020 */   addiu    $sp, $sp, 0x20
