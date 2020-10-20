.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802412E8_CCC5F8
/* CCC5F8 802412E8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* CCC5FC 802412EC AFB3001C */  sw        $s3, 0x1c($sp)
/* CCC600 802412F0 0080982D */  daddu     $s3, $a0, $zero
/* CCC604 802412F4 AFBF0020 */  sw        $ra, 0x20($sp)
/* CCC608 802412F8 AFB20018 */  sw        $s2, 0x18($sp)
/* CCC60C 802412FC AFB10014 */  sw        $s1, 0x14($sp)
/* CCC610 80241300 AFB00010 */  sw        $s0, 0x10($sp)
/* CCC614 80241304 8E720148 */  lw        $s2, 0x148($s3)
/* CCC618 80241308 86440008 */  lh        $a0, 8($s2)
/* CCC61C 8024130C 0C00EABB */  jal       get_npc_unsafe
/* CCC620 80241310 00A0882D */   daddu    $s1, $a1, $zero
/* CCC624 80241314 8E240008 */  lw        $a0, 8($s1)
/* CCC628 80241318 0040802D */  daddu     $s0, $v0, $zero
/* CCC62C 8024131C 00041FC2 */  srl       $v1, $a0, 0x1f
/* CCC630 80241320 00832021 */  addu      $a0, $a0, $v1
/* CCC634 80241324 00042043 */  sra       $a0, $a0, 1
/* CCC638 80241328 0C00A67F */  jal       rand_int
/* CCC63C 8024132C 24840001 */   addiu    $a0, $a0, 1
/* CCC640 80241330 8E230008 */  lw        $v1, 8($s1)
/* CCC644 80241334 240400B4 */  addiu     $a0, $zero, 0xb4
/* CCC648 80241338 00032FC2 */  srl       $a1, $v1, 0x1f
/* CCC64C 8024133C 00651821 */  addu      $v1, $v1, $a1
/* CCC650 80241340 00031843 */  sra       $v1, $v1, 1
/* CCC654 80241344 00621821 */  addu      $v1, $v1, $v0
/* CCC658 80241348 0C00A67F */  jal       rand_int
/* CCC65C 8024134C A603008E */   sh       $v1, 0x8e($s0)
/* CCC660 80241350 C60C000C */  lwc1      $f12, 0xc($s0)
/* CCC664 80241354 44820000 */  mtc1      $v0, $f0
/* CCC668 80241358 00000000 */  nop       
/* CCC66C 8024135C 46800020 */  cvt.s.w   $f0, $f0
/* CCC670 80241360 46006300 */  add.s     $f12, $f12, $f0
/* CCC674 80241364 3C0142B4 */  lui       $at, 0x42b4
/* CCC678 80241368 44810000 */  mtc1      $at, $f0
/* CCC67C 8024136C 0C00A6C9 */  jal       clamp_angle
/* CCC680 80241370 46006301 */   sub.s    $f12, $f12, $f0
/* CCC684 80241374 E600000C */  swc1      $f0, 0xc($s0)
/* CCC688 80241378 8E4200CC */  lw        $v0, 0xcc($s2)
/* CCC68C 8024137C 8C420000 */  lw        $v0, ($v0)
/* CCC690 80241380 AE020028 */  sw        $v0, 0x28($s0)
/* CCC694 80241384 24020003 */  addiu     $v0, $zero, 3
/* CCC698 80241388 AE620070 */  sw        $v0, 0x70($s3)
/* CCC69C 8024138C 8FBF0020 */  lw        $ra, 0x20($sp)
/* CCC6A0 80241390 8FB3001C */  lw        $s3, 0x1c($sp)
/* CCC6A4 80241394 8FB20018 */  lw        $s2, 0x18($sp)
/* CCC6A8 80241398 8FB10014 */  lw        $s1, 0x14($sp)
/* CCC6AC 8024139C 8FB00010 */  lw        $s0, 0x10($sp)
/* CCC6B0 802413A0 03E00008 */  jr        $ra
/* CCC6B4 802413A4 27BD0028 */   addiu    $sp, $sp, 0x28
