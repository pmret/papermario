.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetOwnerTarget
/* 19CC88 8026E3A8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 19CC8C 8026E3AC AFB10014 */  sw        $s1, 0x14($sp)
/* 19CC90 8026E3B0 0080882D */  daddu     $s1, $a0, $zero
/* 19CC94 8026E3B4 AFBF001C */  sw        $ra, 0x1c($sp)
/* 19CC98 8026E3B8 AFB20018 */  sw        $s2, 0x18($sp)
/* 19CC9C 8026E3BC AFB00010 */  sw        $s0, 0x10($sp)
/* 19CCA0 8026E3C0 8E240148 */  lw        $a0, 0x148($s1)
/* 19CCA4 8026E3C4 0C09A75B */  jal       get_actor
/* 19CCA8 8026E3C8 8E30000C */   lw       $s0, 0xc($s1)
/* 19CCAC 8026E3CC 8E050000 */  lw        $a1, ($s0)
/* 19CCB0 8026E3D0 26100004 */  addiu     $s0, $s0, 4
/* 19CCB4 8026E3D4 0220202D */  daddu     $a0, $s1, $zero
/* 19CCB8 8026E3D8 0C0B1EAF */  jal       get_variable
/* 19CCBC 8026E3DC 0040902D */   daddu    $s2, $v0, $zero
/* 19CCC0 8026E3E0 0220202D */  daddu     $a0, $s1, $zero
/* 19CCC4 8026E3E4 8E050000 */  lw        $a1, ($s0)
/* 19CCC8 8026E3E8 0C0B1EAF */  jal       get_variable
/* 19CCCC 8026E3EC 0040802D */   daddu    $s0, $v0, $zero
/* 19CCD0 8026E3F0 A2420426 */  sb        $v0, 0x426($s2)
/* 19CCD4 8026E3F4 A6500428 */  sh        $s0, 0x428($s2)
/* 19CCD8 8026E3F8 8FBF001C */  lw        $ra, 0x1c($sp)
/* 19CCDC 8026E3FC 8FB20018 */  lw        $s2, 0x18($sp)
/* 19CCE0 8026E400 8FB10014 */  lw        $s1, 0x14($sp)
/* 19CCE4 8026E404 8FB00010 */  lw        $s0, 0x10($sp)
/* 19CCE8 8026E408 24020002 */  addiu     $v0, $zero, 2
/* 19CCEC 8026E40C 03E00008 */  jr        $ra
/* 19CCF0 8026E410 27BD0020 */   addiu    $sp, $sp, 0x20
