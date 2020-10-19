.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241A98
/* CB07D8 80241A98 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* CB07DC 80241A9C AFB10014 */  sw        $s1, 0x14($sp)
/* CB07E0 80241AA0 0080882D */  daddu     $s1, $a0, $zero
/* CB07E4 80241AA4 AFBF0020 */  sw        $ra, 0x20($sp)
/* CB07E8 80241AA8 AFB3001C */  sw        $s3, 0x1c($sp)
/* CB07EC 80241AAC AFB20018 */  sw        $s2, 0x18($sp)
/* CB07F0 80241AB0 AFB00010 */  sw        $s0, 0x10($sp)
/* CB07F4 80241AB4 8E30000C */  lw        $s0, 0xc($s1)
/* CB07F8 80241AB8 8E050000 */  lw        $a1, ($s0)
/* CB07FC 80241ABC 0C0B1EAF */  jal       get_variable
/* CB0800 80241AC0 26100004 */   addiu    $s0, $s0, 4
/* CB0804 80241AC4 8E050000 */  lw        $a1, ($s0)
/* CB0808 80241AC8 26100004 */  addiu     $s0, $s0, 4
/* CB080C 80241ACC 0220202D */  daddu     $a0, $s1, $zero
/* CB0810 80241AD0 0C0B1EAF */  jal       get_variable
/* CB0814 80241AD4 0040982D */   daddu    $s3, $v0, $zero
/* CB0818 80241AD8 8E050000 */  lw        $a1, ($s0)
/* CB081C 80241ADC 26100004 */  addiu     $s0, $s0, 4
/* CB0820 80241AE0 0220202D */  daddu     $a0, $s1, $zero
/* CB0824 80241AE4 0C0B1EAF */  jal       get_variable
/* CB0828 80241AE8 0040902D */   daddu    $s2, $v0, $zero
/* CB082C 80241AEC 0220202D */  daddu     $a0, $s1, $zero
/* CB0830 80241AF0 8E050000 */  lw        $a1, ($s0)
/* CB0834 80241AF4 0C0B1EAF */  jal       get_variable
/* CB0838 80241AF8 0040882D */   daddu    $s1, $v0, $zero
/* CB083C 80241AFC 0260202D */  daddu     $a0, $s3, $zero
/* CB0840 80241B00 0C04C3D6 */  jal       get_item_entity
/* CB0844 80241B04 0040802D */   daddu    $s0, $v0, $zero
/* CB0848 80241B08 0040182D */  daddu     $v1, $v0, $zero
/* CB084C 80241B0C 44920000 */  mtc1      $s2, $f0
/* CB0850 80241B10 00000000 */  nop       
/* CB0854 80241B14 46800020 */  cvt.s.w   $f0, $f0
/* CB0858 80241B18 E4600008 */  swc1      $f0, 8($v1)
/* CB085C 80241B1C 44910000 */  mtc1      $s1, $f0
/* CB0860 80241B20 00000000 */  nop       
/* CB0864 80241B24 46800020 */  cvt.s.w   $f0, $f0
/* CB0868 80241B28 E460000C */  swc1      $f0, 0xc($v1)
/* CB086C 80241B2C 44900000 */  mtc1      $s0, $f0
/* CB0870 80241B30 00000000 */  nop       
/* CB0874 80241B34 46800020 */  cvt.s.w   $f0, $f0
/* CB0878 80241B38 E4600010 */  swc1      $f0, 0x10($v1)
/* CB087C 80241B3C 8FBF0020 */  lw        $ra, 0x20($sp)
/* CB0880 80241B40 8FB3001C */  lw        $s3, 0x1c($sp)
/* CB0884 80241B44 8FB20018 */  lw        $s2, 0x18($sp)
/* CB0888 80241B48 8FB10014 */  lw        $s1, 0x14($sp)
/* CB088C 80241B4C 8FB00010 */  lw        $s0, 0x10($sp)
/* CB0890 80241B50 24020002 */  addiu     $v0, $zero, 2
/* CB0894 80241B54 03E00008 */  jr        $ra
/* CB0898 80241B58 27BD0028 */   addiu    $sp, $sp, 0x28
