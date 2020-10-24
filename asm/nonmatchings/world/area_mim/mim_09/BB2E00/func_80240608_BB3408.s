.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240608_BB3408
/* BB3408 80240608 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* BB340C 8024060C AFB3001C */  sw        $s3, 0x1c($sp)
/* BB3410 80240610 0080982D */  daddu     $s3, $a0, $zero
/* BB3414 80240614 AFBF0020 */  sw        $ra, 0x20($sp)
/* BB3418 80240618 AFB20018 */  sw        $s2, 0x18($sp)
/* BB341C 8024061C AFB10014 */  sw        $s1, 0x14($sp)
/* BB3420 80240620 AFB00010 */  sw        $s0, 0x10($sp)
/* BB3424 80240624 8E720148 */  lw        $s2, 0x148($s3)
/* BB3428 80240628 86440008 */  lh        $a0, 8($s2)
/* BB342C 8024062C 0C00EABB */  jal       get_npc_unsafe
/* BB3430 80240630 00A0882D */   daddu    $s1, $a1, $zero
/* BB3434 80240634 8E240008 */  lw        $a0, 8($s1)
/* BB3438 80240638 0040802D */  daddu     $s0, $v0, $zero
/* BB343C 8024063C 00041FC2 */  srl       $v1, $a0, 0x1f
/* BB3440 80240640 00832021 */  addu      $a0, $a0, $v1
/* BB3444 80240644 00042043 */  sra       $a0, $a0, 1
/* BB3448 80240648 0C00A67F */  jal       rand_int
/* BB344C 8024064C 24840001 */   addiu    $a0, $a0, 1
/* BB3450 80240650 8E230008 */  lw        $v1, 8($s1)
/* BB3454 80240654 240400B4 */  addiu     $a0, $zero, 0xb4
/* BB3458 80240658 00032FC2 */  srl       $a1, $v1, 0x1f
/* BB345C 8024065C 00651821 */  addu      $v1, $v1, $a1
/* BB3460 80240660 00031843 */  sra       $v1, $v1, 1
/* BB3464 80240664 00621821 */  addu      $v1, $v1, $v0
/* BB3468 80240668 0C00A67F */  jal       rand_int
/* BB346C 8024066C A603008E */   sh       $v1, 0x8e($s0)
/* BB3470 80240670 C60C000C */  lwc1      $f12, 0xc($s0)
/* BB3474 80240674 44820000 */  mtc1      $v0, $f0
/* BB3478 80240678 00000000 */  nop       
/* BB347C 8024067C 46800020 */  cvt.s.w   $f0, $f0
/* BB3480 80240680 46006300 */  add.s     $f12, $f12, $f0
/* BB3484 80240684 3C0142B4 */  lui       $at, 0x42b4
/* BB3488 80240688 44810000 */  mtc1      $at, $f0
/* BB348C 8024068C 0C00A6C9 */  jal       clamp_angle
/* BB3490 80240690 46006301 */   sub.s    $f12, $f12, $f0
/* BB3494 80240694 E600000C */  swc1      $f0, 0xc($s0)
/* BB3498 80240698 8E4200CC */  lw        $v0, 0xcc($s2)
/* BB349C 8024069C 8C420000 */  lw        $v0, ($v0)
/* BB34A0 802406A0 AE020028 */  sw        $v0, 0x28($s0)
/* BB34A4 802406A4 24020003 */  addiu     $v0, $zero, 3
/* BB34A8 802406A8 AE620070 */  sw        $v0, 0x70($s3)
/* BB34AC 802406AC 8FBF0020 */  lw        $ra, 0x20($sp)
/* BB34B0 802406B0 8FB3001C */  lw        $s3, 0x1c($sp)
/* BB34B4 802406B4 8FB20018 */  lw        $s2, 0x18($sp)
/* BB34B8 802406B8 8FB10014 */  lw        $s1, 0x14($sp)
/* BB34BC 802406BC 8FB00010 */  lw        $s0, 0x10($sp)
/* BB34C0 802406C0 03E00008 */  jr        $ra
/* BB34C4 802406C4 27BD0028 */   addiu    $sp, $sp, 0x28
