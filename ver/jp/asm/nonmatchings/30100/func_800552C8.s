.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800552C8
/* 306C8 800552C8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 306CC 800552CC AFB10014 */  sw        $s1, 0x14($sp)
/* 306D0 800552D0 0080882D */  daddu     $s1, $a0, $zero
/* 306D4 800552D4 AFB20018 */  sw        $s2, 0x18($sp)
/* 306D8 800552D8 00A0902D */  daddu     $s2, $a1, $zero
/* 306DC 800552DC AFBF001C */  sw        $ra, 0x1c($sp)
/* 306E0 800552E0 0C014238 */  jal       func_800508E0
/* 306E4 800552E4 AFB00010 */   sw       $s0, 0x10($sp)
/* 306E8 800552E8 0040802D */  daddu     $s0, $v0, $zero
/* 306EC 800552EC 16000005 */  bnez      $s0, .L80055304
/* 306F0 800552F0 0200102D */   daddu    $v0, $s0, $zero
/* 306F4 800552F4 0220202D */  daddu     $a0, $s1, $zero
/* 306F8 800552F8 0C014241 */  jal       func_80050904
/* 306FC 800552FC 0240282D */   daddu    $a1, $s2, $zero
/* 30700 80055300 0200102D */  daddu     $v0, $s0, $zero
.L80055304:
/* 30704 80055304 8FBF001C */  lw        $ra, 0x1c($sp)
/* 30708 80055308 8FB20018 */  lw        $s2, 0x18($sp)
/* 3070C 8005530C 8FB10014 */  lw        $s1, 0x14($sp)
/* 30710 80055310 8FB00010 */  lw        $s0, 0x10($sp)
/* 30714 80055314 03E00008 */  jr        $ra
/* 30718 80055318 27BD0020 */   addiu    $sp, $sp, 0x20
