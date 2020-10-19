.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240034_A6CB34
/* A6CB34 80240034 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A6CB38 80240038 AFB20018 */  sw        $s2, 0x18($sp)
/* A6CB3C 8024003C 0080902D */  daddu     $s2, $a0, $zero
/* A6CB40 80240040 AFBF001C */  sw        $ra, 0x1c($sp)
/* A6CB44 80240044 AFB10014 */  sw        $s1, 0x14($sp)
/* A6CB48 80240048 AFB00010 */  sw        $s0, 0x10($sp)
/* A6CB4C 8024004C 8E50000C */  lw        $s0, 0xc($s2)
/* A6CB50 80240050 8E050000 */  lw        $a1, ($s0)
/* A6CB54 80240054 0C0B1EAF */  jal       get_variable
/* A6CB58 80240058 26100004 */   addiu    $s0, $s0, 4
/* A6CB5C 8024005C 0C04417A */  jal       get_entity_by_index
/* A6CB60 80240060 0040202D */   daddu    $a0, $v0, $zero
/* A6CB64 80240064 8E050000 */  lw        $a1, ($s0)
/* A6CB68 80240068 26100004 */  addiu     $s0, $s0, 4
/* A6CB6C 8024006C 0040882D */  daddu     $s1, $v0, $zero
/* A6CB70 80240070 C6200048 */  lwc1      $f0, 0x48($s1)
/* A6CB74 80240074 4600008D */  trunc.w.s $f2, $f0
/* A6CB78 80240078 44061000 */  mfc1      $a2, $f2
/* A6CB7C 8024007C 0C0B2026 */  jal       set_variable
/* A6CB80 80240080 0240202D */   daddu    $a0, $s2, $zero
/* A6CB84 80240084 8E050000 */  lw        $a1, ($s0)
/* A6CB88 80240088 26100004 */  addiu     $s0, $s0, 4
/* A6CB8C 8024008C C620004C */  lwc1      $f0, 0x4c($s1)
/* A6CB90 80240090 4600008D */  trunc.w.s $f2, $f0
/* A6CB94 80240094 44061000 */  mfc1      $a2, $f2
/* A6CB98 80240098 0C0B2026 */  jal       set_variable
/* A6CB9C 8024009C 0240202D */   daddu    $a0, $s2, $zero
/* A6CBA0 802400A0 C6200050 */  lwc1      $f0, 0x50($s1)
/* A6CBA4 802400A4 8E050000 */  lw        $a1, ($s0)
/* A6CBA8 802400A8 4600008D */  trunc.w.s $f2, $f0
/* A6CBAC 802400AC 44061000 */  mfc1      $a2, $f2
/* A6CBB0 802400B0 0C0B2026 */  jal       set_variable
/* A6CBB4 802400B4 0240202D */   daddu    $a0, $s2, $zero
/* A6CBB8 802400B8 8FBF001C */  lw        $ra, 0x1c($sp)
/* A6CBBC 802400BC 8FB20018 */  lw        $s2, 0x18($sp)
/* A6CBC0 802400C0 8FB10014 */  lw        $s1, 0x14($sp)
/* A6CBC4 802400C4 8FB00010 */  lw        $s0, 0x10($sp)
/* A6CBC8 802400C8 24020002 */  addiu     $v0, $zero, 2
/* A6CBCC 802400CC 03E00008 */  jr        $ra
/* A6CBD0 802400D0 27BD0020 */   addiu    $sp, $sp, 0x20
/* A6CBD4 802400D4 00000000 */  nop       
/* A6CBD8 802400D8 00000000 */  nop       
/* A6CBDC 802400DC 00000000 */  nop       
