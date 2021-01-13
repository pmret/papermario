.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240380_AACBB0
/* AACBB0 80240380 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* AACBB4 80240384 AFB10014 */  sw        $s1, 0x14($sp)
/* AACBB8 80240388 0080882D */  daddu     $s1, $a0, $zero
/* AACBBC 8024038C AFBF001C */  sw        $ra, 0x1c($sp)
/* AACBC0 80240390 AFB20018 */  sw        $s2, 0x18($sp)
/* AACBC4 80240394 AFB00010 */  sw        $s0, 0x10($sp)
/* AACBC8 80240398 8E30000C */  lw        $s0, 0xc($s1)
/* AACBCC 8024039C 8E050000 */  lw        $a1, ($s0)
/* AACBD0 802403A0 0C0B1EAF */  jal       get_variable
/* AACBD4 802403A4 26100004 */   addiu    $s0, $s0, 4
/* AACBD8 802403A8 8E050000 */  lw        $a1, ($s0)
/* AACBDC 802403AC 26100004 */  addiu     $s0, $s0, 4
/* AACBE0 802403B0 0220202D */  daddu     $a0, $s1, $zero
/* AACBE4 802403B4 0C0B1EAF */  jal       get_variable
/* AACBE8 802403B8 0040902D */   daddu    $s2, $v0, $zero
/* AACBEC 802403BC 0220202D */  daddu     $a0, $s1, $zero
/* AACBF0 802403C0 8E050000 */  lw        $a1, ($s0)
/* AACBF4 802403C4 0C0B1EAF */  jal       get_variable
/* AACBF8 802403C8 0040802D */   daddu    $s0, $v0, $zero
/* AACBFC 802403CC 0040882D */  daddu     $s1, $v0, $zero
/* AACC00 802403D0 2402FFFF */  addiu     $v0, $zero, -1
/* AACC04 802403D4 16020005 */  bne       $s0, $v0, .L802403EC
/* AACC08 802403D8 24020001 */   addiu    $v0, $zero, 1
/* AACC0C 802403DC 0C04760B */  jal       func_8011D82C
/* AACC10 802403E0 0220202D */   daddu    $a0, $s1, $zero
/* AACC14 802403E4 08090123 */  j         .L8024048C
/* AACC18 802403E8 24020002 */   addiu    $v0, $zero, 2
.L802403EC:
/* AACC1C 802403EC 12420018 */  beq       $s2, $v0, .L80240450
/* AACC20 802403F0 2A420002 */   slti     $v0, $s2, 2
/* AACC24 802403F4 10400005 */  beqz      $v0, .L8024040C
/* AACC28 802403F8 24020002 */   addiu    $v0, $zero, 2
/* AACC2C 802403FC 12400007 */  beqz      $s2, .L8024041C
/* AACC30 80240400 3412FFFF */   ori      $s2, $zero, 0xffff
/* AACC34 80240404 08090123 */  j         .L8024048C
/* AACC38 80240408 00000000 */   nop
.L8024040C:
/* AACC3C 8024040C 1242001B */  beq       $s2, $v0, .L8024047C
/* AACC40 80240410 24020002 */   addiu    $v0, $zero, 2
/* AACC44 80240414 08090123 */  j         .L8024048C
/* AACC48 80240418 00000000 */   nop
.L8024041C:
/* AACC4C 8024041C 8E040000 */  lw        $a0, ($s0)
/* AACC50 80240420 1092001A */  beq       $a0, $s2, .L8024048C
/* AACC54 80240424 24020002 */   addiu    $v0, $zero, 2
/* AACC58 80240428 0C046C04 */  jal       get_model_list_index_from_tree_index
/* AACC5C 8024042C 26100004 */   addiu    $s0, $s0, 4
/* AACC60 80240430 0C046B4C */  jal       get_model_from_list_index
/* AACC64 80240434 0040202D */   daddu    $a0, $v0, $zero
/* AACC68 80240438 0040202D */  daddu     $a0, $v0, $zero
/* AACC6C 8024043C 2405FFFF */  addiu     $a1, $zero, -1
/* AACC70 80240440 0C046F1F */  jal       func_8011BC7C
/* AACC74 80240444 0220302D */   daddu    $a2, $s1, $zero
/* AACC78 80240448 08090107 */  j         .L8024041C
/* AACC7C 8024044C 00000000 */   nop
.L80240450:
/* AACC80 80240450 3412FFFF */  ori       $s2, $zero, 0xffff
.L80240454:
/* AACC84 80240454 8E020000 */  lw        $v0, ($s0)
/* AACC88 80240458 1052000B */  beq       $v0, $s2, .L80240488
/* AACC8C 8024045C 2405FFFF */   addiu    $a1, $zero, -1
/* AACC90 80240460 96040002 */  lhu       $a0, 2($s0)
/* AACC94 80240464 0220302D */  daddu     $a2, $s1, $zero
/* AACC98 80240468 26100004 */  addiu     $s0, $s0, 4
/* AACC9C 8024046C 0C046E54 */  jal       func_8011B950
/* AACCA0 80240470 0000382D */   daddu    $a3, $zero, $zero
/* AACCA4 80240474 08090115 */  j         .L80240454
/* AACCA8 80240478 00000000 */   nop
.L8024047C:
/* AACCAC 8024047C 3C028015 */  lui       $v0, %hi(D_801512F0)
/* AACCB0 80240480 8C4212F0 */  lw        $v0, %lo(D_801512F0)($v0)
/* AACCB4 80240484 A0510000 */  sb        $s1, ($v0)
.L80240488:
/* AACCB8 80240488 24020002 */  addiu     $v0, $zero, 2
.L8024048C:
/* AACCBC 8024048C 8FBF001C */  lw        $ra, 0x1c($sp)
/* AACCC0 80240490 8FB20018 */  lw        $s2, 0x18($sp)
/* AACCC4 80240494 8FB10014 */  lw        $s1, 0x14($sp)
/* AACCC8 80240498 8FB00010 */  lw        $s0, 0x10($sp)
/* AACCCC 8024049C 03E00008 */  jr        $ra
/* AACCD0 802404A0 27BD0020 */   addiu    $sp, $sp, 0x20
