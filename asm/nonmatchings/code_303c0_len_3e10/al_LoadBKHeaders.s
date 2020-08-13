.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel al_LoadBKHeaders
/* 0303C0 80054FC0 27BDFE98 */  addiu $sp, $sp, -0x168
/* 0303C4 80054FC4 0080102D */  daddu $v0, $a0, $zero
/* 0303C8 80054FC8 27A50018 */  addiu $a1, $sp, 0x18
/* 0303CC 80054FCC AFB1015C */  sw    $s1, 0x15c($sp)
/* 0303D0 80054FD0 0000882D */  daddu $s1, $zero, $zero
/* 0303D4 80054FD4 AFB20160 */  sw    $s2, 0x160($sp)
/* 0303D8 80054FD8 3412FFFF */  ori   $s2, $zero, 0xffff
/* 0303DC 80054FDC AFBF0164 */  sw    $ra, 0x164($sp)
/* 0303E0 80054FE0 AFB00158 */  sw    $s0, 0x158($sp)
/* 0303E4 80054FE4 8C440034 */  lw    $a0, 0x34($v0)
/* 0303E8 80054FE8 8C460038 */  lw    $a2, 0x38($v0)
/* 0303EC 80054FEC 0C015380 */  jal   al_DmaCopy
/* 0303F0 80054FF0 00A0802D */   daddu $s0, $a1, $zero
.L80054FF4:
/* 0303F4 80054FF4 96020000 */  lhu   $v0, ($s0)
/* 0303F8 80054FF8 1052000E */  beq   $v0, $s2, .L80055034
/* 0303FC 80054FFC 24050030 */   addiu $a1, $zero, 0x30
/* 030400 80055000 27A60010 */  addiu $a2, $sp, 0x10
/* 030404 80055004 0040202D */  daddu $a0, $v0, $zero
/* 030408 80055008 0C01511F */  jal   al_CopyFileTableEntry
/* 03040C 8005500C 26310001 */   addiu $s1, $s1, 1
/* 030410 80055010 0000282D */  daddu $a1, $zero, $zero
/* 030414 80055014 8FA40010 */  lw    $a0, 0x10($sp)
/* 030418 80055018 92060002 */  lbu   $a2, 2($s0)
/* 03041C 8005501C 92070003 */  lbu   $a3, 3($s0)
/* 030420 80055020 0C0151F2 */  jal   al_LoadBank
/* 030424 80055024 26100004 */   addiu $s0, $s0, 4
/* 030428 80055028 2A220050 */  slti  $v0, $s1, 0x50
/* 03042C 8005502C 1440FFF1 */  bnez  $v0, .L80054FF4
/* 030430 80055030 00000000 */   nop   
.L80055034:
/* 030434 80055034 8FBF0164 */  lw    $ra, 0x164($sp)
/* 030438 80055038 8FB20160 */  lw    $s2, 0x160($sp)
/* 03043C 8005503C 8FB1015C */  lw    $s1, 0x15c($sp)
/* 030440 80055040 8FB00158 */  lw    $s0, 0x158($sp)
/* 030444 80055044 03E00008 */  jr    $ra
/* 030448 80055048 27BD0168 */   addiu $sp, $sp, 0x168

/* 03044C 8005504C 00000000 */  nop   
