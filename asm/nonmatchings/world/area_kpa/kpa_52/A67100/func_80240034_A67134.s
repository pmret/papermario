.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240034_A67134
/* A67134 80240034 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A67138 80240038 AFB20018 */  sw        $s2, 0x18($sp)
/* A6713C 8024003C 0080902D */  daddu     $s2, $a0, $zero
/* A67140 80240040 AFBF001C */  sw        $ra, 0x1c($sp)
/* A67144 80240044 AFB10014 */  sw        $s1, 0x14($sp)
/* A67148 80240048 AFB00010 */  sw        $s0, 0x10($sp)
/* A6714C 8024004C 8E50000C */  lw        $s0, 0xc($s2)
/* A67150 80240050 8E050000 */  lw        $a1, ($s0)
/* A67154 80240054 0C0B1EAF */  jal       get_variable
/* A67158 80240058 26100004 */   addiu    $s0, $s0, 4
/* A6715C 8024005C 0C04417A */  jal       get_entity_by_index
/* A67160 80240060 0040202D */   daddu    $a0, $v0, $zero
/* A67164 80240064 8E050000 */  lw        $a1, ($s0)
/* A67168 80240068 26100004 */  addiu     $s0, $s0, 4
/* A6716C 8024006C 0040882D */  daddu     $s1, $v0, $zero
/* A67170 80240070 C6200048 */  lwc1      $f0, 0x48($s1)
/* A67174 80240074 4600008D */  trunc.w.s $f2, $f0
/* A67178 80240078 44061000 */  mfc1      $a2, $f2
/* A6717C 8024007C 0C0B2026 */  jal       set_variable
/* A67180 80240080 0240202D */   daddu    $a0, $s2, $zero
/* A67184 80240084 8E050000 */  lw        $a1, ($s0)
/* A67188 80240088 26100004 */  addiu     $s0, $s0, 4
/* A6718C 8024008C C620004C */  lwc1      $f0, 0x4c($s1)
/* A67190 80240090 4600008D */  trunc.w.s $f2, $f0
/* A67194 80240094 44061000 */  mfc1      $a2, $f2
/* A67198 80240098 0C0B2026 */  jal       set_variable
/* A6719C 8024009C 0240202D */   daddu    $a0, $s2, $zero
/* A671A0 802400A0 C6200050 */  lwc1      $f0, 0x50($s1)
/* A671A4 802400A4 8E050000 */  lw        $a1, ($s0)
/* A671A8 802400A8 4600008D */  trunc.w.s $f2, $f0
/* A671AC 802400AC 44061000 */  mfc1      $a2, $f2
/* A671B0 802400B0 0C0B2026 */  jal       set_variable
/* A671B4 802400B4 0240202D */   daddu    $a0, $s2, $zero
/* A671B8 802400B8 8FBF001C */  lw        $ra, 0x1c($sp)
/* A671BC 802400BC 8FB20018 */  lw        $s2, 0x18($sp)
/* A671C0 802400C0 8FB10014 */  lw        $s1, 0x14($sp)
/* A671C4 802400C4 8FB00010 */  lw        $s0, 0x10($sp)
/* A671C8 802400C8 24020002 */  addiu     $v0, $zero, 2
/* A671CC 802400CC 03E00008 */  jr        $ra
/* A671D0 802400D0 27BD0020 */   addiu    $sp, $sp, 0x20
/* A671D4 802400D4 00000000 */  nop       
/* A671D8 802400D8 00000000 */  nop       
/* A671DC 802400DC 00000000 */  nop       
