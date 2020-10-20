.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240034_A72254
/* A72254 80240034 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A72258 80240038 AFB20018 */  sw        $s2, 0x18($sp)
/* A7225C 8024003C 0080902D */  daddu     $s2, $a0, $zero
/* A72260 80240040 AFBF001C */  sw        $ra, 0x1c($sp)
/* A72264 80240044 AFB10014 */  sw        $s1, 0x14($sp)
/* A72268 80240048 AFB00010 */  sw        $s0, 0x10($sp)
/* A7226C 8024004C 8E50000C */  lw        $s0, 0xc($s2)
/* A72270 80240050 8E050000 */  lw        $a1, ($s0)
/* A72274 80240054 0C0B1EAF */  jal       get_variable
/* A72278 80240058 26100004 */   addiu    $s0, $s0, 4
/* A7227C 8024005C 0C04417A */  jal       get_entity_by_index
/* A72280 80240060 0040202D */   daddu    $a0, $v0, $zero
/* A72284 80240064 8E050000 */  lw        $a1, ($s0)
/* A72288 80240068 26100004 */  addiu     $s0, $s0, 4
/* A7228C 8024006C 0040882D */  daddu     $s1, $v0, $zero
/* A72290 80240070 C6200048 */  lwc1      $f0, 0x48($s1)
/* A72294 80240074 4600008D */  trunc.w.s $f2, $f0
/* A72298 80240078 44061000 */  mfc1      $a2, $f2
/* A7229C 8024007C 0C0B2026 */  jal       set_variable
/* A722A0 80240080 0240202D */   daddu    $a0, $s2, $zero
/* A722A4 80240084 8E050000 */  lw        $a1, ($s0)
/* A722A8 80240088 26100004 */  addiu     $s0, $s0, 4
/* A722AC 8024008C C620004C */  lwc1      $f0, 0x4c($s1)
/* A722B0 80240090 4600008D */  trunc.w.s $f2, $f0
/* A722B4 80240094 44061000 */  mfc1      $a2, $f2
/* A722B8 80240098 0C0B2026 */  jal       set_variable
/* A722BC 8024009C 0240202D */   daddu    $a0, $s2, $zero
/* A722C0 802400A0 C6200050 */  lwc1      $f0, 0x50($s1)
/* A722C4 802400A4 8E050000 */  lw        $a1, ($s0)
/* A722C8 802400A8 4600008D */  trunc.w.s $f2, $f0
/* A722CC 802400AC 44061000 */  mfc1      $a2, $f2
/* A722D0 802400B0 0C0B2026 */  jal       set_variable
/* A722D4 802400B4 0240202D */   daddu    $a0, $s2, $zero
/* A722D8 802400B8 8FBF001C */  lw        $ra, 0x1c($sp)
/* A722DC 802400BC 8FB20018 */  lw        $s2, 0x18($sp)
/* A722E0 802400C0 8FB10014 */  lw        $s1, 0x14($sp)
/* A722E4 802400C4 8FB00010 */  lw        $s0, 0x10($sp)
/* A722E8 802400C8 24020002 */  addiu     $v0, $zero, 2
/* A722EC 802400CC 03E00008 */  jr        $ra
/* A722F0 802400D0 27BD0020 */   addiu    $sp, $sp, 0x20
/* A722F4 802400D4 00000000 */  nop       
/* A722F8 802400D8 00000000 */  nop       
/* A722FC 802400DC 00000000 */  nop       
