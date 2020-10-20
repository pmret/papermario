.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240034_9A1014
/* 9A1014 80240034 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9A1018 80240038 AFB20018 */  sw        $s2, 0x18($sp)
/* 9A101C 8024003C 0080902D */  daddu     $s2, $a0, $zero
/* 9A1020 80240040 AFBF001C */  sw        $ra, 0x1c($sp)
/* 9A1024 80240044 AFB10014 */  sw        $s1, 0x14($sp)
/* 9A1028 80240048 AFB00010 */  sw        $s0, 0x10($sp)
/* 9A102C 8024004C 8E50000C */  lw        $s0, 0xc($s2)
/* 9A1030 80240050 8E050000 */  lw        $a1, ($s0)
/* 9A1034 80240054 0C0B1EAF */  jal       get_variable
/* 9A1038 80240058 26100004 */   addiu    $s0, $s0, 4
/* 9A103C 8024005C 0C04417A */  jal       get_entity_by_index
/* 9A1040 80240060 0040202D */   daddu    $a0, $v0, $zero
/* 9A1044 80240064 8E050000 */  lw        $a1, ($s0)
/* 9A1048 80240068 26100004 */  addiu     $s0, $s0, 4
/* 9A104C 8024006C 0040882D */  daddu     $s1, $v0, $zero
/* 9A1050 80240070 C6200048 */  lwc1      $f0, 0x48($s1)
/* 9A1054 80240074 4600008D */  trunc.w.s $f2, $f0
/* 9A1058 80240078 44061000 */  mfc1      $a2, $f2
/* 9A105C 8024007C 0C0B2026 */  jal       set_variable
/* 9A1060 80240080 0240202D */   daddu    $a0, $s2, $zero
/* 9A1064 80240084 8E050000 */  lw        $a1, ($s0)
/* 9A1068 80240088 26100004 */  addiu     $s0, $s0, 4
/* 9A106C 8024008C C620004C */  lwc1      $f0, 0x4c($s1)
/* 9A1070 80240090 4600008D */  trunc.w.s $f2, $f0
/* 9A1074 80240094 44061000 */  mfc1      $a2, $f2
/* 9A1078 80240098 0C0B2026 */  jal       set_variable
/* 9A107C 8024009C 0240202D */   daddu    $a0, $s2, $zero
/* 9A1080 802400A0 C6200050 */  lwc1      $f0, 0x50($s1)
/* 9A1084 802400A4 8E050000 */  lw        $a1, ($s0)
/* 9A1088 802400A8 4600008D */  trunc.w.s $f2, $f0
/* 9A108C 802400AC 44061000 */  mfc1      $a2, $f2
/* 9A1090 802400B0 0C0B2026 */  jal       set_variable
/* 9A1094 802400B4 0240202D */   daddu    $a0, $s2, $zero
/* 9A1098 802400B8 8FBF001C */  lw        $ra, 0x1c($sp)
/* 9A109C 802400BC 8FB20018 */  lw        $s2, 0x18($sp)
/* 9A10A0 802400C0 8FB10014 */  lw        $s1, 0x14($sp)
/* 9A10A4 802400C4 8FB00010 */  lw        $s0, 0x10($sp)
/* 9A10A8 802400C8 24020002 */  addiu     $v0, $zero, 2
/* 9A10AC 802400CC 03E00008 */  jr        $ra
/* 9A10B0 802400D0 27BD0020 */   addiu    $sp, $sp, 0x20
/* 9A10B4 802400D4 00000000 */  nop       
/* 9A10B8 802400D8 00000000 */  nop       
/* 9A10BC 802400DC 00000000 */  nop       
