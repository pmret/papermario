.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241864
/* A882B4 80241864 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A882B8 80241868 AFB20018 */  sw        $s2, 0x18($sp)
/* A882BC 8024186C 0080902D */  daddu     $s2, $a0, $zero
/* A882C0 80241870 AFBF001C */  sw        $ra, 0x1c($sp)
/* A882C4 80241874 AFB10014 */  sw        $s1, 0x14($sp)
/* A882C8 80241878 AFB00010 */  sw        $s0, 0x10($sp)
/* A882CC 8024187C 8E50000C */  lw        $s0, 0xc($s2)
/* A882D0 80241880 8E050000 */  lw        $a1, ($s0)
/* A882D4 80241884 0C0B1EAF */  jal       get_variable
/* A882D8 80241888 26100004 */   addiu    $s0, $s0, 4
/* A882DC 8024188C 0C04417A */  jal       get_entity_by_index
/* A882E0 80241890 0040202D */   daddu    $a0, $v0, $zero
/* A882E4 80241894 8E050000 */  lw        $a1, ($s0)
/* A882E8 80241898 26100004 */  addiu     $s0, $s0, 4
/* A882EC 8024189C 0040882D */  daddu     $s1, $v0, $zero
/* A882F0 802418A0 C6200048 */  lwc1      $f0, 0x48($s1)
/* A882F4 802418A4 4600008D */  trunc.w.s $f2, $f0
/* A882F8 802418A8 44061000 */  mfc1      $a2, $f2
/* A882FC 802418AC 0C0B2026 */  jal       set_variable
/* A88300 802418B0 0240202D */   daddu    $a0, $s2, $zero
/* A88304 802418B4 8E050000 */  lw        $a1, ($s0)
/* A88308 802418B8 26100004 */  addiu     $s0, $s0, 4
/* A8830C 802418BC C620004C */  lwc1      $f0, 0x4c($s1)
/* A88310 802418C0 4600008D */  trunc.w.s $f2, $f0
/* A88314 802418C4 44061000 */  mfc1      $a2, $f2
/* A88318 802418C8 0C0B2026 */  jal       set_variable
/* A8831C 802418CC 0240202D */   daddu    $a0, $s2, $zero
/* A88320 802418D0 C6200050 */  lwc1      $f0, 0x50($s1)
/* A88324 802418D4 8E050000 */  lw        $a1, ($s0)
/* A88328 802418D8 4600008D */  trunc.w.s $f2, $f0
/* A8832C 802418DC 44061000 */  mfc1      $a2, $f2
/* A88330 802418E0 0C0B2026 */  jal       set_variable
/* A88334 802418E4 0240202D */   daddu    $a0, $s2, $zero
/* A88338 802418E8 8FBF001C */  lw        $ra, 0x1c($sp)
/* A8833C 802418EC 8FB20018 */  lw        $s2, 0x18($sp)
/* A88340 802418F0 8FB10014 */  lw        $s1, 0x14($sp)
/* A88344 802418F4 8FB00010 */  lw        $s0, 0x10($sp)
/* A88348 802418F8 24020002 */  addiu     $v0, $zero, 2
/* A8834C 802418FC 03E00008 */  jr        $ra
/* A88350 80241900 27BD0020 */   addiu    $sp, $sp, 0x20
/* A88354 80241904 00000000 */  nop       
/* A88358 80241908 00000000 */  nop       
/* A8835C 8024190C 00000000 */  nop       
