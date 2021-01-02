.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel area_omo_GetEntityPosition
/* 513068 80218A98 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 51306C 80218A9C AFB20018 */  sw        $s2, 0x18($sp)
/* 513070 80218AA0 0080902D */  daddu     $s2, $a0, $zero
/* 513074 80218AA4 AFBF001C */  sw        $ra, 0x1c($sp)
/* 513078 80218AA8 AFB10014 */  sw        $s1, 0x14($sp)
/* 51307C 80218AAC AFB00010 */  sw        $s0, 0x10($sp)
/* 513080 80218AB0 8E50000C */  lw        $s0, 0xc($s2)
/* 513084 80218AB4 8E050000 */  lw        $a1, ($s0)
/* 513088 80218AB8 0C0B1EAF */  jal       get_variable
/* 51308C 80218ABC 26100004 */   addiu    $s0, $s0, 4
/* 513090 80218AC0 0C04C3D6 */  jal       get_item_entity
/* 513094 80218AC4 0040202D */   daddu    $a0, $v0, $zero
/* 513098 80218AC8 8E050000 */  lw        $a1, ($s0)
/* 51309C 80218ACC 26100004 */  addiu     $s0, $s0, 4
/* 5130A0 80218AD0 0040882D */  daddu     $s1, $v0, $zero
/* 5130A4 80218AD4 C6200008 */  lwc1      $f0, 8($s1)
/* 5130A8 80218AD8 4600008D */  trunc.w.s $f2, $f0
/* 5130AC 80218ADC 44061000 */  mfc1      $a2, $f2
/* 5130B0 80218AE0 0C0B2026 */  jal       set_variable
/* 5130B4 80218AE4 0240202D */   daddu    $a0, $s2, $zero
/* 5130B8 80218AE8 8E050000 */  lw        $a1, ($s0)
/* 5130BC 80218AEC 26100004 */  addiu     $s0, $s0, 4
/* 5130C0 80218AF0 C620000C */  lwc1      $f0, 0xc($s1)
/* 5130C4 80218AF4 4600008D */  trunc.w.s $f2, $f0
/* 5130C8 80218AF8 44061000 */  mfc1      $a2, $f2
/* 5130CC 80218AFC 0C0B2026 */  jal       set_variable
/* 5130D0 80218B00 0240202D */   daddu    $a0, $s2, $zero
/* 5130D4 80218B04 C6200010 */  lwc1      $f0, 0x10($s1)
/* 5130D8 80218B08 8E050000 */  lw        $a1, ($s0)
/* 5130DC 80218B0C 4600008D */  trunc.w.s $f2, $f0
/* 5130E0 80218B10 44061000 */  mfc1      $a2, $f2
/* 5130E4 80218B14 0C0B2026 */  jal       set_variable
/* 5130E8 80218B18 0240202D */   daddu    $a0, $s2, $zero
/* 5130EC 80218B1C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 5130F0 80218B20 8FB20018 */  lw        $s2, 0x18($sp)
/* 5130F4 80218B24 8FB10014 */  lw        $s1, 0x14($sp)
/* 5130F8 80218B28 8FB00010 */  lw        $s0, 0x10($sp)
/* 5130FC 80218B2C 24020002 */  addiu     $v0, $zero, 2
/* 513100 80218B30 03E00008 */  jr        $ra
/* 513104 80218B34 27BD0020 */   addiu    $sp, $sp, 0x20
