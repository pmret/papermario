.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021CC5C_6A3E5C
/* 6A3E5C 8021CC5C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 6A3E60 8021CC60 AFB20018 */  sw        $s2, 0x18($sp)
/* 6A3E64 8021CC64 0080902D */  daddu     $s2, $a0, $zero
/* 6A3E68 8021CC68 AFBF001C */  sw        $ra, 0x1c($sp)
/* 6A3E6C 8021CC6C AFB10014 */  sw        $s1, 0x14($sp)
/* 6A3E70 8021CC70 AFB00010 */  sw        $s0, 0x10($sp)
/* 6A3E74 8021CC74 8E50000C */  lw        $s0, 0xc($s2)
/* 6A3E78 8021CC78 8E050000 */  lw        $a1, ($s0)
/* 6A3E7C 8021CC7C 0C0B1EAF */  jal       get_variable
/* 6A3E80 8021CC80 26100004 */   addiu    $s0, $s0, 4
/* 6A3E84 8021CC84 0C04C3D6 */  jal       get_item_entity
/* 6A3E88 8021CC88 0040202D */   daddu    $a0, $v0, $zero
/* 6A3E8C 8021CC8C 8E050000 */  lw        $a1, ($s0)
/* 6A3E90 8021CC90 26100004 */  addiu     $s0, $s0, 4
/* 6A3E94 8021CC94 0040882D */  daddu     $s1, $v0, $zero
/* 6A3E98 8021CC98 C6200008 */  lwc1      $f0, 8($s1)
/* 6A3E9C 8021CC9C 4600008D */  trunc.w.s $f2, $f0
/* 6A3EA0 8021CCA0 44061000 */  mfc1      $a2, $f2
/* 6A3EA4 8021CCA4 0C0B2026 */  jal       set_variable
/* 6A3EA8 8021CCA8 0240202D */   daddu    $a0, $s2, $zero
/* 6A3EAC 8021CCAC 8E050000 */  lw        $a1, ($s0)
/* 6A3EB0 8021CCB0 26100004 */  addiu     $s0, $s0, 4
/* 6A3EB4 8021CCB4 C620000C */  lwc1      $f0, 0xc($s1)
/* 6A3EB8 8021CCB8 4600008D */  trunc.w.s $f2, $f0
/* 6A3EBC 8021CCBC 44061000 */  mfc1      $a2, $f2
/* 6A3EC0 8021CCC0 0C0B2026 */  jal       set_variable
/* 6A3EC4 8021CCC4 0240202D */   daddu    $a0, $s2, $zero
/* 6A3EC8 8021CCC8 C6200010 */  lwc1      $f0, 0x10($s1)
/* 6A3ECC 8021CCCC 8E050000 */  lw        $a1, ($s0)
/* 6A3ED0 8021CCD0 4600008D */  trunc.w.s $f2, $f0
/* 6A3ED4 8021CCD4 44061000 */  mfc1      $a2, $f2
/* 6A3ED8 8021CCD8 0C0B2026 */  jal       set_variable
/* 6A3EDC 8021CCDC 0240202D */   daddu    $a0, $s2, $zero
/* 6A3EE0 8021CCE0 8FBF001C */  lw        $ra, 0x1c($sp)
/* 6A3EE4 8021CCE4 8FB20018 */  lw        $s2, 0x18($sp)
/* 6A3EE8 8021CCE8 8FB10014 */  lw        $s1, 0x14($sp)
/* 6A3EEC 8021CCEC 8FB00010 */  lw        $s0, 0x10($sp)
/* 6A3EF0 8021CCF0 24020002 */  addiu     $v0, $zero, 2
/* 6A3EF4 8021CCF4 03E00008 */  jr        $ra
/* 6A3EF8 8021CCF8 27BD0020 */   addiu    $sp, $sp, 0x20
