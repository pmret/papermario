.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024146C_BD005C
/* BD005C 8024146C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BD0060 80241470 AFB10014 */  sw        $s1, 0x14($sp)
/* BD0064 80241474 0080882D */  daddu     $s1, $a0, $zero
/* BD0068 80241478 AFBF0018 */  sw        $ra, 0x18($sp)
/* BD006C 8024147C 0C090150 */  jal       func_80240540
/* BD0070 80241480 AFB00010 */   sw       $s0, 0x10($sp)
/* BD0074 80241484 3C05FE36 */  lui       $a1, 0xfe36
/* BD0078 80241488 34A53C82 */  ori       $a1, $a1, 0x3c82
/* BD007C 8024148C 0040802D */  daddu     $s0, $v0, $zero
/* BD0080 80241490 0C0B210B */  jal       get_float_variable
/* BD0084 80241494 0220202D */   daddu    $a0, $s1, $zero
/* BD0088 80241498 E60001D0 */  swc1      $f0, 0x1d0($s0)
/* BD008C 8024149C 8FBF0018 */  lw        $ra, 0x18($sp)
/* BD0090 802414A0 8FB10014 */  lw        $s1, 0x14($sp)
/* BD0094 802414A4 8FB00010 */  lw        $s0, 0x10($sp)
/* BD0098 802414A8 24020002 */  addiu     $v0, $zero, 2
/* BD009C 802414AC 03E00008 */  jr        $ra
/* BD00A0 802414B0 27BD0020 */   addiu    $sp, $sp, 0x20
