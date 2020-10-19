.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240344_9A8734
/* 9A8734 80240344 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 9A8738 80240348 AFB10014 */  sw        $s1, 0x14($sp)
/* 9A873C 8024034C 0080882D */  daddu     $s1, $a0, $zero
/* 9A8740 80240350 AFBF0020 */  sw        $ra, 0x20($sp)
/* 9A8744 80240354 AFB3001C */  sw        $s3, 0x1c($sp)
/* 9A8748 80240358 AFB20018 */  sw        $s2, 0x18($sp)
/* 9A874C 8024035C AFB00010 */  sw        $s0, 0x10($sp)
/* 9A8750 80240360 8E30000C */  lw        $s0, 0xc($s1)
/* 9A8754 80240364 8E050000 */  lw        $a1, ($s0)
/* 9A8758 80240368 0C0B1EAF */  jal       get_variable
/* 9A875C 8024036C 26100004 */   addiu    $s0, $s0, 4
/* 9A8760 80240370 8E050000 */  lw        $a1, ($s0)
/* 9A8764 80240374 26100004 */  addiu     $s0, $s0, 4
/* 9A8768 80240378 0220202D */  daddu     $a0, $s1, $zero
/* 9A876C 8024037C 0C0B1EAF */  jal       get_variable
/* 9A8770 80240380 0040982D */   daddu    $s3, $v0, $zero
/* 9A8774 80240384 8E050000 */  lw        $a1, ($s0)
/* 9A8778 80240388 26100004 */  addiu     $s0, $s0, 4
/* 9A877C 8024038C 0220202D */  daddu     $a0, $s1, $zero
/* 9A8780 80240390 0C0B1EAF */  jal       get_variable
/* 9A8784 80240394 0040902D */   daddu    $s2, $v0, $zero
/* 9A8788 80240398 0220202D */  daddu     $a0, $s1, $zero
/* 9A878C 8024039C 8E050000 */  lw        $a1, ($s0)
/* 9A8790 802403A0 0C0B1EAF */  jal       get_variable
/* 9A8794 802403A4 0040882D */   daddu    $s1, $v0, $zero
/* 9A8798 802403A8 0260202D */  daddu     $a0, $s3, $zero
/* 9A879C 802403AC 0C04417A */  jal       get_entity_by_index
/* 9A87A0 802403B0 0040802D */   daddu    $s0, $v0, $zero
/* 9A87A4 802403B4 0040182D */  daddu     $v1, $v0, $zero
/* 9A87A8 802403B8 44920000 */  mtc1      $s2, $f0
/* 9A87AC 802403BC 00000000 */  nop       
/* 9A87B0 802403C0 46800020 */  cvt.s.w   $f0, $f0
/* 9A87B4 802403C4 E4600048 */  swc1      $f0, 0x48($v1)
/* 9A87B8 802403C8 44910000 */  mtc1      $s1, $f0
/* 9A87BC 802403CC 00000000 */  nop       
/* 9A87C0 802403D0 46800020 */  cvt.s.w   $f0, $f0
/* 9A87C4 802403D4 E460004C */  swc1      $f0, 0x4c($v1)
/* 9A87C8 802403D8 44900000 */  mtc1      $s0, $f0
/* 9A87CC 802403DC 00000000 */  nop       
/* 9A87D0 802403E0 46800020 */  cvt.s.w   $f0, $f0
/* 9A87D4 802403E4 E4600050 */  swc1      $f0, 0x50($v1)
/* 9A87D8 802403E8 8FBF0020 */  lw        $ra, 0x20($sp)
/* 9A87DC 802403EC 8FB3001C */  lw        $s3, 0x1c($sp)
/* 9A87E0 802403F0 8FB20018 */  lw        $s2, 0x18($sp)
/* 9A87E4 802403F4 8FB10014 */  lw        $s1, 0x14($sp)
/* 9A87E8 802403F8 8FB00010 */  lw        $s0, 0x10($sp)
/* 9A87EC 802403FC 24020002 */  addiu     $v0, $zero, 2
/* 9A87F0 80240400 03E00008 */  jr        $ra
/* 9A87F4 80240404 27BD0028 */   addiu    $sp, $sp, 0x28
