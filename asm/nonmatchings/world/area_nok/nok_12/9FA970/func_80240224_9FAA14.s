.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240224_9FAA14
/* 9FAA14 80240224 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 9FAA18 80240228 AFB10014 */  sw        $s1, 0x14($sp)
/* 9FAA1C 8024022C 0080882D */  daddu     $s1, $a0, $zero
/* 9FAA20 80240230 AFBF0020 */  sw        $ra, 0x20($sp)
/* 9FAA24 80240234 AFB3001C */  sw        $s3, 0x1c($sp)
/* 9FAA28 80240238 AFB20018 */  sw        $s2, 0x18($sp)
/* 9FAA2C 8024023C AFB00010 */  sw        $s0, 0x10($sp)
/* 9FAA30 80240240 8E30000C */  lw        $s0, 0xc($s1)
/* 9FAA34 80240244 8E050000 */  lw        $a1, ($s0)
/* 9FAA38 80240248 0C0B1EAF */  jal       get_variable
/* 9FAA3C 8024024C 26100004 */   addiu    $s0, $s0, 4
/* 9FAA40 80240250 8E050000 */  lw        $a1, ($s0)
/* 9FAA44 80240254 26100004 */  addiu     $s0, $s0, 4
/* 9FAA48 80240258 0220202D */  daddu     $a0, $s1, $zero
/* 9FAA4C 8024025C 0C0B1EAF */  jal       get_variable
/* 9FAA50 80240260 0040982D */   daddu    $s3, $v0, $zero
/* 9FAA54 80240264 8E050000 */  lw        $a1, ($s0)
/* 9FAA58 80240268 26100004 */  addiu     $s0, $s0, 4
/* 9FAA5C 8024026C 0220202D */  daddu     $a0, $s1, $zero
/* 9FAA60 80240270 0C0B1EAF */  jal       get_variable
/* 9FAA64 80240274 0040902D */   daddu    $s2, $v0, $zero
/* 9FAA68 80240278 0220202D */  daddu     $a0, $s1, $zero
/* 9FAA6C 8024027C 8E050000 */  lw        $a1, ($s0)
/* 9FAA70 80240280 0C0B1EAF */  jal       get_variable
/* 9FAA74 80240284 0040882D */   daddu    $s1, $v0, $zero
/* 9FAA78 80240288 0260202D */  daddu     $a0, $s3, $zero
/* 9FAA7C 8024028C 0C04417A */  jal       get_entity_by_index
/* 9FAA80 80240290 0040802D */   daddu    $s0, $v0, $zero
/* 9FAA84 80240294 0040182D */  daddu     $v1, $v0, $zero
/* 9FAA88 80240298 44920000 */  mtc1      $s2, $f0
/* 9FAA8C 8024029C 00000000 */  nop       
/* 9FAA90 802402A0 46800020 */  cvt.s.w   $f0, $f0
/* 9FAA94 802402A4 E4600048 */  swc1      $f0, 0x48($v1)
/* 9FAA98 802402A8 44910000 */  mtc1      $s1, $f0
/* 9FAA9C 802402AC 00000000 */  nop       
/* 9FAAA0 802402B0 46800020 */  cvt.s.w   $f0, $f0
/* 9FAAA4 802402B4 E460004C */  swc1      $f0, 0x4c($v1)
/* 9FAAA8 802402B8 44900000 */  mtc1      $s0, $f0
/* 9FAAAC 802402BC 00000000 */  nop       
/* 9FAAB0 802402C0 46800020 */  cvt.s.w   $f0, $f0
/* 9FAAB4 802402C4 E4600050 */  swc1      $f0, 0x50($v1)
/* 9FAAB8 802402C8 8FBF0020 */  lw        $ra, 0x20($sp)
/* 9FAABC 802402CC 8FB3001C */  lw        $s3, 0x1c($sp)
/* 9FAAC0 802402D0 8FB20018 */  lw        $s2, 0x18($sp)
/* 9FAAC4 802402D4 8FB10014 */  lw        $s1, 0x14($sp)
/* 9FAAC8 802402D8 8FB00010 */  lw        $s0, 0x10($sp)
/* 9FAACC 802402DC 24020002 */  addiu     $v0, $zero, 2
/* 9FAAD0 802402E0 03E00008 */  jr        $ra
/* 9FAAD4 802402E4 27BD0028 */   addiu    $sp, $sp, 0x28
/* 9FAAD8 802402E8 00000000 */  nop       
/* 9FAADC 802402EC 00000000 */  nop       
