.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_BC4280
/* BC4280 80240000 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* BC4284 80240004 AFB10014 */  sw        $s1, 0x14($sp)
/* BC4288 80240008 0080882D */  daddu     $s1, $a0, $zero
/* BC428C 8024000C AFBF0020 */  sw        $ra, 0x20($sp)
/* BC4290 80240010 AFB3001C */  sw        $s3, 0x1c($sp)
/* BC4294 80240014 AFB20018 */  sw        $s2, 0x18($sp)
/* BC4298 80240018 AFB00010 */  sw        $s0, 0x10($sp)
/* BC429C 8024001C 8E30000C */  lw        $s0, 0xc($s1)
/* BC42A0 80240020 8E050000 */  lw        $a1, ($s0)
/* BC42A4 80240024 0C0B1EAF */  jal       get_variable
/* BC42A8 80240028 26100004 */   addiu    $s0, $s0, 4
/* BC42AC 8024002C 8E050000 */  lw        $a1, ($s0)
/* BC42B0 80240030 26100004 */  addiu     $s0, $s0, 4
/* BC42B4 80240034 0220202D */  daddu     $a0, $s1, $zero
/* BC42B8 80240038 0C0B1EAF */  jal       get_variable
/* BC42BC 8024003C 0040982D */   daddu    $s3, $v0, $zero
/* BC42C0 80240040 8E050000 */  lw        $a1, ($s0)
/* BC42C4 80240044 26100004 */  addiu     $s0, $s0, 4
/* BC42C8 80240048 0220202D */  daddu     $a0, $s1, $zero
/* BC42CC 8024004C 0C0B1EAF */  jal       get_variable
/* BC42D0 80240050 0040902D */   daddu    $s2, $v0, $zero
/* BC42D4 80240054 0220202D */  daddu     $a0, $s1, $zero
/* BC42D8 80240058 8E050000 */  lw        $a1, ($s0)
/* BC42DC 8024005C 0C0B1EAF */  jal       get_variable
/* BC42E0 80240060 0040882D */   daddu    $s1, $v0, $zero
/* BC42E4 80240064 0260202D */  daddu     $a0, $s3, $zero
/* BC42E8 80240068 0C04417A */  jal       get_entity_by_index
/* BC42EC 8024006C 0040802D */   daddu    $s0, $v0, $zero
/* BC42F0 80240070 0040182D */  daddu     $v1, $v0, $zero
/* BC42F4 80240074 44920000 */  mtc1      $s2, $f0
/* BC42F8 80240078 00000000 */  nop       
/* BC42FC 8024007C 46800020 */  cvt.s.w   $f0, $f0
/* BC4300 80240080 E4600048 */  swc1      $f0, 0x48($v1)
/* BC4304 80240084 44910000 */  mtc1      $s1, $f0
/* BC4308 80240088 00000000 */  nop       
/* BC430C 8024008C 46800020 */  cvt.s.w   $f0, $f0
/* BC4310 80240090 E460004C */  swc1      $f0, 0x4c($v1)
/* BC4314 80240094 44900000 */  mtc1      $s0, $f0
/* BC4318 80240098 00000000 */  nop       
/* BC431C 8024009C 46800020 */  cvt.s.w   $f0, $f0
/* BC4320 802400A0 E4600050 */  swc1      $f0, 0x50($v1)
/* BC4324 802400A4 8FBF0020 */  lw        $ra, 0x20($sp)
/* BC4328 802400A8 8FB3001C */  lw        $s3, 0x1c($sp)
/* BC432C 802400AC 8FB20018 */  lw        $s2, 0x18($sp)
/* BC4330 802400B0 8FB10014 */  lw        $s1, 0x14($sp)
/* BC4334 802400B4 8FB00010 */  lw        $s0, 0x10($sp)
/* BC4338 802400B8 24020002 */  addiu     $v0, $zero, 2
/* BC433C 802400BC 03E00008 */  jr        $ra
/* BC4340 802400C0 27BD0028 */   addiu    $sp, $sp, 0x28
