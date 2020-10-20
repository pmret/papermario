.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241628_CD3458
/* CD3458 80241628 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* CD345C 8024162C AFB3001C */  sw        $s3, 0x1c($sp)
/* CD3460 80241630 0080982D */  daddu     $s3, $a0, $zero
/* CD3464 80241634 AFBF0020 */  sw        $ra, 0x20($sp)
/* CD3468 80241638 AFB20018 */  sw        $s2, 0x18($sp)
/* CD346C 8024163C AFB10014 */  sw        $s1, 0x14($sp)
/* CD3470 80241640 AFB00010 */  sw        $s0, 0x10($sp)
/* CD3474 80241644 8E720148 */  lw        $s2, 0x148($s3)
/* CD3478 80241648 86440008 */  lh        $a0, 8($s2)
/* CD347C 8024164C 0C00EABB */  jal       get_npc_unsafe
/* CD3480 80241650 00A0882D */   daddu    $s1, $a1, $zero
/* CD3484 80241654 8E240008 */  lw        $a0, 8($s1)
/* CD3488 80241658 0040802D */  daddu     $s0, $v0, $zero
/* CD348C 8024165C 00041FC2 */  srl       $v1, $a0, 0x1f
/* CD3490 80241660 00832021 */  addu      $a0, $a0, $v1
/* CD3494 80241664 00042043 */  sra       $a0, $a0, 1
/* CD3498 80241668 0C00A67F */  jal       rand_int
/* CD349C 8024166C 24840001 */   addiu    $a0, $a0, 1
/* CD34A0 80241670 8E230008 */  lw        $v1, 8($s1)
/* CD34A4 80241674 240400B4 */  addiu     $a0, $zero, 0xb4
/* CD34A8 80241678 00032FC2 */  srl       $a1, $v1, 0x1f
/* CD34AC 8024167C 00651821 */  addu      $v1, $v1, $a1
/* CD34B0 80241680 00031843 */  sra       $v1, $v1, 1
/* CD34B4 80241684 00621821 */  addu      $v1, $v1, $v0
/* CD34B8 80241688 0C00A67F */  jal       rand_int
/* CD34BC 8024168C A603008E */   sh       $v1, 0x8e($s0)
/* CD34C0 80241690 C60C000C */  lwc1      $f12, 0xc($s0)
/* CD34C4 80241694 44820000 */  mtc1      $v0, $f0
/* CD34C8 80241698 00000000 */  nop       
/* CD34CC 8024169C 46800020 */  cvt.s.w   $f0, $f0
/* CD34D0 802416A0 46006300 */  add.s     $f12, $f12, $f0
/* CD34D4 802416A4 3C0142B4 */  lui       $at, 0x42b4
/* CD34D8 802416A8 44810000 */  mtc1      $at, $f0
/* CD34DC 802416AC 0C00A6C9 */  jal       clamp_angle
/* CD34E0 802416B0 46006301 */   sub.s    $f12, $f12, $f0
/* CD34E4 802416B4 E600000C */  swc1      $f0, 0xc($s0)
/* CD34E8 802416B8 8E4200CC */  lw        $v0, 0xcc($s2)
/* CD34EC 802416BC 8C420000 */  lw        $v0, ($v0)
/* CD34F0 802416C0 AE020028 */  sw        $v0, 0x28($s0)
/* CD34F4 802416C4 24020003 */  addiu     $v0, $zero, 3
/* CD34F8 802416C8 AE620070 */  sw        $v0, 0x70($s3)
/* CD34FC 802416CC 8FBF0020 */  lw        $ra, 0x20($sp)
/* CD3500 802416D0 8FB3001C */  lw        $s3, 0x1c($sp)
/* CD3504 802416D4 8FB20018 */  lw        $s2, 0x18($sp)
/* CD3508 802416D8 8FB10014 */  lw        $s1, 0x14($sp)
/* CD350C 802416DC 8FB00010 */  lw        $s0, 0x10($sp)
/* CD3510 802416E0 03E00008 */  jr        $ra
/* CD3514 802416E4 27BD0028 */   addiu    $sp, $sp, 0x28
