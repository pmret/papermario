.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240080_B02900
/* B02900 80240080 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* B02904 80240084 AFB00018 */  sw        $s0, 0x18($sp)
/* B02908 80240088 0080802D */  daddu     $s0, $a0, $zero
/* B0290C 8024008C AFBF001C */  sw        $ra, 0x1c($sp)
/* B02910 80240090 F7B40020 */  sdc1      $f20, 0x20($sp)
/* B02914 80240094 0C00EAD2 */  jal       get_npc_safe
/* B02918 80240098 24040001 */   addiu    $a0, $zero, 1
/* B0291C 8024009C 2404023D */  addiu     $a0, $zero, 0x23d
/* B02920 802400A0 C4420038 */  lwc1      $f2, 0x38($v0)
/* B02924 802400A4 C454003C */  lwc1      $f20, 0x3c($v0)
/* B02928 802400A8 C4400040 */  lwc1      $f0, 0x40($v0)
/* B0292C 802400AC 44061000 */  mfc1      $a2, $f2
/* B02930 802400B0 4407A000 */  mfc1      $a3, $f20
/* B02934 802400B4 0000282D */  daddu     $a1, $zero, $zero
/* B02938 802400B8 0C05267B */  jal       func_801499EC
/* B0293C 802400BC E7A00010 */   swc1     $f0, 0x10($sp)
/* B02940 802400C0 4600A10D */  trunc.w.s $f4, $f20
/* B02944 802400C4 E6040084 */  swc1      $f4, 0x84($s0)
/* B02948 802400C8 8FBF001C */  lw        $ra, 0x1c($sp)
/* B0294C 802400CC 8FB00018 */  lw        $s0, 0x18($sp)
/* B02950 802400D0 D7B40020 */  ldc1      $f20, 0x20($sp)
/* B02954 802400D4 24020002 */  addiu     $v0, $zero, 2
/* B02958 802400D8 03E00008 */  jr        $ra
/* B0295C 802400DC 27BD0028 */   addiu    $sp, $sp, 0x28
