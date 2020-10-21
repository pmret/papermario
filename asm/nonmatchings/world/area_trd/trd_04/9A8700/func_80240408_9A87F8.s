.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240408_9A87F8
/* 9A87F8 80240408 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9A87FC 8024040C AFB20018 */  sw        $s2, 0x18($sp)
/* 9A8800 80240410 0080902D */  daddu     $s2, $a0, $zero
/* 9A8804 80240414 AFBF001C */  sw        $ra, 0x1c($sp)
/* 9A8808 80240418 AFB10014 */  sw        $s1, 0x14($sp)
/* 9A880C 8024041C AFB00010 */  sw        $s0, 0x10($sp)
/* 9A8810 80240420 8E50000C */  lw        $s0, 0xc($s2)
/* 9A8814 80240424 8E050000 */  lw        $a1, ($s0)
/* 9A8818 80240428 0C0B1EAF */  jal       get_variable
/* 9A881C 8024042C 26100004 */   addiu    $s0, $s0, 4
/* 9A8820 80240430 0C04417A */  jal       get_entity_by_index
/* 9A8824 80240434 0040202D */   daddu    $a0, $v0, $zero
/* 9A8828 80240438 8E050000 */  lw        $a1, ($s0)
/* 9A882C 8024043C 26100004 */  addiu     $s0, $s0, 4
/* 9A8830 80240440 0040882D */  daddu     $s1, $v0, $zero
/* 9A8834 80240444 C6200048 */  lwc1      $f0, 0x48($s1)
/* 9A8838 80240448 4600008D */  trunc.w.s $f2, $f0
/* 9A883C 8024044C 44061000 */  mfc1      $a2, $f2
/* 9A8840 80240450 0C0B2026 */  jal       set_variable
/* 9A8844 80240454 0240202D */   daddu    $a0, $s2, $zero
/* 9A8848 80240458 8E050000 */  lw        $a1, ($s0)
/* 9A884C 8024045C 26100004 */  addiu     $s0, $s0, 4
/* 9A8850 80240460 C620004C */  lwc1      $f0, 0x4c($s1)
/* 9A8854 80240464 4600008D */  trunc.w.s $f2, $f0
/* 9A8858 80240468 44061000 */  mfc1      $a2, $f2
/* 9A885C 8024046C 0C0B2026 */  jal       set_variable
/* 9A8860 80240470 0240202D */   daddu    $a0, $s2, $zero
/* 9A8864 80240474 C6200050 */  lwc1      $f0, 0x50($s1)
/* 9A8868 80240478 8E050000 */  lw        $a1, ($s0)
/* 9A886C 8024047C 4600008D */  trunc.w.s $f2, $f0
/* 9A8870 80240480 44061000 */  mfc1      $a2, $f2
/* 9A8874 80240484 0C0B2026 */  jal       set_variable
/* 9A8878 80240488 0240202D */   daddu    $a0, $s2, $zero
/* 9A887C 8024048C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 9A8880 80240490 8FB20018 */  lw        $s2, 0x18($sp)
/* 9A8884 80240494 8FB10014 */  lw        $s1, 0x14($sp)
/* 9A8888 80240498 8FB00010 */  lw        $s0, 0x10($sp)
/* 9A888C 8024049C 24020002 */  addiu     $v0, $zero, 2
/* 9A8890 802404A0 03E00008 */  jr        $ra
/* 9A8894 802404A4 27BD0020 */   addiu    $sp, $sp, 0x20
/* 9A8898 802404A8 00000000 */  nop       
/* 9A889C 802404AC 00000000 */  nop       
