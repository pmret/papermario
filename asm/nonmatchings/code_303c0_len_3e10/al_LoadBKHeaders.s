.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel al_LoadBKHeaders
/* 303C0 80054FC0 27BDFE98 */  addiu     $sp, $sp, -0x168
/* 303C4 80054FC4 0080102D */  daddu     $v0, $a0, $zero
/* 303C8 80054FC8 27A50018 */  addiu     $a1, $sp, 0x18
/* 303CC 80054FCC AFB1015C */  sw        $s1, 0x15c($sp)
/* 303D0 80054FD0 0000882D */  daddu     $s1, $zero, $zero
/* 303D4 80054FD4 AFB20160 */  sw        $s2, 0x160($sp)
/* 303D8 80054FD8 3412FFFF */  ori       $s2, $zero, 0xffff
/* 303DC 80054FDC AFBF0164 */  sw        $ra, 0x164($sp)
/* 303E0 80054FE0 AFB00158 */  sw        $s0, 0x158($sp)
/* 303E4 80054FE4 8C440034 */  lw        $a0, 0x34($v0)
/* 303E8 80054FE8 8C460038 */  lw        $a2, 0x38($v0)
/* 303EC 80054FEC 0C015380 */  jal       al_DmaCopy
/* 303F0 80054FF0 00A0802D */   daddu    $s0, $a1, $zero
.L80054FF4:
/* 303F4 80054FF4 96020000 */  lhu       $v0, ($s0)
/* 303F8 80054FF8 1052000E */  beq       $v0, $s2, .L80055034
/* 303FC 80054FFC 24050030 */   addiu    $a1, $zero, 0x30
/* 30400 80055000 27A60010 */  addiu     $a2, $sp, 0x10
/* 30404 80055004 0040202D */  daddu     $a0, $v0, $zero
/* 30408 80055008 0C01511F */  jal       al_CopyFileTableEntry
/* 3040C 8005500C 26310001 */   addiu    $s1, $s1, 1
/* 30410 80055010 0000282D */  daddu     $a1, $zero, $zero
/* 30414 80055014 8FA40010 */  lw        $a0, 0x10($sp)
/* 30418 80055018 92060002 */  lbu       $a2, 2($s0)
/* 3041C 8005501C 92070003 */  lbu       $a3, 3($s0)
/* 30420 80055020 0C0151F2 */  jal       al_LoadBank
/* 30424 80055024 26100004 */   addiu    $s0, $s0, 4
/* 30428 80055028 2A220050 */  slti      $v0, $s1, 0x50
/* 3042C 8005502C 1440FFF1 */  bnez      $v0, .L80054FF4
/* 30430 80055030 00000000 */   nop
.L80055034:
/* 30434 80055034 8FBF0164 */  lw        $ra, 0x164($sp)
/* 30438 80055038 8FB20160 */  lw        $s2, 0x160($sp)
/* 3043C 8005503C 8FB1015C */  lw        $s1, 0x15c($sp)
/* 30440 80055040 8FB00158 */  lw        $s0, 0x158($sp)
/* 30444 80055044 03E00008 */  jr        $ra
/* 30448 80055048 27BD0168 */   addiu    $sp, $sp, 0x168
/* 3044C 8005504C 00000000 */  nop
