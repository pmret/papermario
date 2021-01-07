.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218804_6092B4
/* 6092B4 80218804 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6092B8 80218808 AFB00010 */  sw        $s0, 0x10($sp)
/* 6092BC 8021880C 0080802D */  daddu     $s0, $a0, $zero
/* 6092C0 80218810 10A00003 */  beqz      $a1, .L80218820
/* 6092C4 80218814 AFBF0014 */   sw       $ra, 0x14($sp)
/* 6092C8 80218818 24020014 */  addiu     $v0, $zero, 0x14
/* 6092CC 8021881C AE020070 */  sw        $v0, 0x70($s0)
.L80218820:
/* 6092D0 80218820 0000202D */  daddu     $a0, $zero, $zero
/* 6092D4 80218824 0080282D */  daddu     $a1, $a0, $zero
/* 6092D8 80218828 8E020070 */  lw        $v0, 0x70($s0)
/* 6092DC 8021882C 0080302D */  daddu     $a2, $a0, $zero
/* 6092E0 80218830 00023880 */  sll       $a3, $v0, 2
/* 6092E4 80218834 00E23821 */  addu      $a3, $a3, $v0
/* 6092E8 80218838 00073840 */  sll       $a3, $a3, 1
/* 6092EC 8021883C 0C046F97 */  jal       set_background_color_blend
/* 6092F0 80218840 30E700FE */   andi     $a3, $a3, 0xfe
/* 6092F4 80218844 8E020070 */  lw        $v0, 0x70($s0)
/* 6092F8 80218848 2442FFFF */  addiu     $v0, $v0, -1
/* 6092FC 8021884C 10400003 */  beqz      $v0, .L8021885C
/* 609300 80218850 AE020070 */   sw       $v0, 0x70($s0)
/* 609304 80218854 0808621D */  j         .L80218874
/* 609308 80218858 0000102D */   daddu    $v0, $zero, $zero
.L8021885C:
/* 60930C 8021885C 0000202D */  daddu     $a0, $zero, $zero
/* 609310 80218860 0080282D */  daddu     $a1, $a0, $zero
/* 609314 80218864 0080302D */  daddu     $a2, $a0, $zero
/* 609318 80218868 0C046F97 */  jal       set_background_color_blend
/* 60931C 8021886C 0080382D */   daddu    $a3, $a0, $zero
/* 609320 80218870 24020002 */  addiu     $v0, $zero, 2
.L80218874:
/* 609324 80218874 8FBF0014 */  lw        $ra, 0x14($sp)
/* 609328 80218878 8FB00010 */  lw        $s0, 0x10($sp)
/* 60932C 8021887C 03E00008 */  jr        $ra
/* 609330 80218880 27BD0018 */   addiu    $sp, $sp, 0x18
