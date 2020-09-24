.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetActorVar
/* 19A924 8026C044 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 19A928 8026C048 AFB20018 */  sw        $s2, 0x18($sp)
/* 19A92C 8026C04C 0080902D */  daddu     $s2, $a0, $zero
/* 19A930 8026C050 AFBF001C */  sw        $ra, 0x1c($sp)
/* 19A934 8026C054 AFB10014 */  sw        $s1, 0x14($sp)
/* 19A938 8026C058 AFB00010 */  sw        $s0, 0x10($sp)
/* 19A93C 8026C05C 8E50000C */  lw        $s0, 0xc($s2)
/* 19A940 8026C060 8E050000 */  lw        $a1, ($s0)
/* 19A944 8026C064 0C0B1EAF */  jal       get_variable
/* 19A948 8026C068 26100004 */   addiu    $s0, $s0, 4
/* 19A94C 8026C06C 0040882D */  daddu     $s1, $v0, $zero
/* 19A950 8026C070 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 19A954 8026C074 16220002 */  bne       $s1, $v0, .L8026C080
/* 19A958 8026C078 00000000 */   nop      
/* 19A95C 8026C07C 8E510148 */  lw        $s1, 0x148($s2)
.L8026C080:
/* 19A960 8026C080 8E050000 */  lw        $a1, ($s0)
/* 19A964 8026C084 26100004 */  addiu     $s0, $s0, 4
/* 19A968 8026C088 0C0B1EAF */  jal       get_variable
/* 19A96C 8026C08C 0240202D */   daddu    $a0, $s2, $zero
/* 19A970 8026C090 0240202D */  daddu     $a0, $s2, $zero
/* 19A974 8026C094 8E050000 */  lw        $a1, ($s0)
/* 19A978 8026C098 0C0B1EAF */  jal       get_variable
/* 19A97C 8026C09C 0040802D */   daddu    $s0, $v0, $zero
/* 19A980 8026C0A0 0220202D */  daddu     $a0, $s1, $zero
/* 19A984 8026C0A4 0C09A75B */  jal       get_actor
/* 19A988 8026C0A8 0040882D */   daddu    $s1, $v0, $zero
/* 19A98C 8026C0AC 00108080 */  sll       $s0, $s0, 2
/* 19A990 8026C0B0 00501821 */  addu      $v1, $v0, $s0
/* 19A994 8026C0B4 AC710088 */  sw        $s1, 0x88($v1)
/* 19A998 8026C0B8 8FBF001C */  lw        $ra, 0x1c($sp)
/* 19A99C 8026C0BC 8FB20018 */  lw        $s2, 0x18($sp)
/* 19A9A0 8026C0C0 8FB10014 */  lw        $s1, 0x14($sp)
/* 19A9A4 8026C0C4 8FB00010 */  lw        $s0, 0x10($sp)
/* 19A9A8 8026C0C8 24020002 */  addiu     $v0, $zero, 2
/* 19A9AC 8026C0CC 03E00008 */  jr        $ra
/* 19A9B0 8026C0D0 27BD0020 */   addiu    $sp, $sp, 0x20
