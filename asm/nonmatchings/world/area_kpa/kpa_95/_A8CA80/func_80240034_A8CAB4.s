.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240034_A8CAB4
/* A8CAB4 80240034 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A8CAB8 80240038 AFB20018 */  sw        $s2, 0x18($sp)
/* A8CABC 8024003C 0080902D */  daddu     $s2, $a0, $zero
/* A8CAC0 80240040 AFBF001C */  sw        $ra, 0x1c($sp)
/* A8CAC4 80240044 AFB10014 */  sw        $s1, 0x14($sp)
/* A8CAC8 80240048 AFB00010 */  sw        $s0, 0x10($sp)
/* A8CACC 8024004C 8E50000C */  lw        $s0, 0xc($s2)
/* A8CAD0 80240050 8E050000 */  lw        $a1, ($s0)
/* A8CAD4 80240054 0C0B1EAF */  jal       get_variable
/* A8CAD8 80240058 26100004 */   addiu    $s0, $s0, 4
/* A8CADC 8024005C 0C04417A */  jal       get_entity_by_index
/* A8CAE0 80240060 0040202D */   daddu    $a0, $v0, $zero
/* A8CAE4 80240064 8E050000 */  lw        $a1, ($s0)
/* A8CAE8 80240068 26100004 */  addiu     $s0, $s0, 4
/* A8CAEC 8024006C 0040882D */  daddu     $s1, $v0, $zero
/* A8CAF0 80240070 C6200048 */  lwc1      $f0, 0x48($s1)
/* A8CAF4 80240074 4600008D */  trunc.w.s $f2, $f0
/* A8CAF8 80240078 44061000 */  mfc1      $a2, $f2
/* A8CAFC 8024007C 0C0B2026 */  jal       set_variable
/* A8CB00 80240080 0240202D */   daddu    $a0, $s2, $zero
/* A8CB04 80240084 8E050000 */  lw        $a1, ($s0)
/* A8CB08 80240088 26100004 */  addiu     $s0, $s0, 4
/* A8CB0C 8024008C C620004C */  lwc1      $f0, 0x4c($s1)
/* A8CB10 80240090 4600008D */  trunc.w.s $f2, $f0
/* A8CB14 80240094 44061000 */  mfc1      $a2, $f2
/* A8CB18 80240098 0C0B2026 */  jal       set_variable
/* A8CB1C 8024009C 0240202D */   daddu    $a0, $s2, $zero
/* A8CB20 802400A0 C6200050 */  lwc1      $f0, 0x50($s1)
/* A8CB24 802400A4 8E050000 */  lw        $a1, ($s0)
/* A8CB28 802400A8 4600008D */  trunc.w.s $f2, $f0
/* A8CB2C 802400AC 44061000 */  mfc1      $a2, $f2
/* A8CB30 802400B0 0C0B2026 */  jal       set_variable
/* A8CB34 802400B4 0240202D */   daddu    $a0, $s2, $zero
/* A8CB38 802400B8 8FBF001C */  lw        $ra, 0x1c($sp)
/* A8CB3C 802400BC 8FB20018 */  lw        $s2, 0x18($sp)
/* A8CB40 802400C0 8FB10014 */  lw        $s1, 0x14($sp)
/* A8CB44 802400C4 8FB00010 */  lw        $s0, 0x10($sp)
/* A8CB48 802400C8 24020002 */  addiu     $v0, $zero, 2
/* A8CB4C 802400CC 03E00008 */  jr        $ra
/* A8CB50 802400D0 27BD0020 */   addiu    $sp, $sp, 0x20
/* A8CB54 802400D4 00000000 */  nop       
/* A8CB58 802400D8 00000000 */  nop       
/* A8CB5C 802400DC 00000000 */  nop       
