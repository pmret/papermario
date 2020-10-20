.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240DA0_A2AFE0
/* A2AFE0 80240DA0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A2AFE4 80240DA4 AFB10014 */  sw        $s1, 0x14($sp)
/* A2AFE8 80240DA8 0080882D */  daddu     $s1, $a0, $zero
/* A2AFEC 80240DAC AFBF0018 */  sw        $ra, 0x18($sp)
/* A2AFF0 80240DB0 AFB00010 */  sw        $s0, 0x10($sp)
/* A2AFF4 80240DB4 8E30000C */  lw        $s0, 0xc($s1)
/* A2AFF8 80240DB8 8E050000 */  lw        $a1, ($s0)
/* A2AFFC 80240DBC 0C0B1EAF */  jal       get_variable
/* A2B000 80240DC0 26100004 */   addiu    $s0, $s0, 4
/* A2B004 80240DC4 0220202D */  daddu     $a0, $s1, $zero
/* A2B008 80240DC8 8E050000 */  lw        $a1, ($s0)
/* A2B00C 80240DCC 0C0B210B */  jal       get_float_variable
/* A2B010 80240DD0 0040802D */   daddu    $s0, $v0, $zero
/* A2B014 80240DD4 44050000 */  mfc1      $a1, $f0
/* A2B018 80240DD8 0C090355 */  jal       func_80240D54
/* A2B01C 80240DDC 0200202D */   daddu    $a0, $s0, $zero
/* A2B020 80240DE0 8FBF0018 */  lw        $ra, 0x18($sp)
/* A2B024 80240DE4 8FB10014 */  lw        $s1, 0x14($sp)
/* A2B028 80240DE8 8FB00010 */  lw        $s0, 0x10($sp)
/* A2B02C 80240DEC 24020002 */  addiu     $v0, $zero, 2
/* A2B030 80240DF0 03E00008 */  jr        $ra
/* A2B034 80240DF4 27BD0020 */   addiu    $sp, $sp, 0x20
