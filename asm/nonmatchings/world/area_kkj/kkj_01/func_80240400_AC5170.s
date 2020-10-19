.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240400_AC5570
/* AC5570 80240400 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* AC5574 80240404 AFB3001C */  sw        $s3, 0x1c($sp)
/* AC5578 80240408 0080982D */  daddu     $s3, $a0, $zero
/* AC557C 8024040C AFBF0020 */  sw        $ra, 0x20($sp)
/* AC5580 80240410 AFB20018 */  sw        $s2, 0x18($sp)
/* AC5584 80240414 AFB10014 */  sw        $s1, 0x14($sp)
/* AC5588 80240418 AFB00010 */  sw        $s0, 0x10($sp)
/* AC558C 8024041C 8E720148 */  lw        $s2, 0x148($s3)
/* AC5590 80240420 86440008 */  lh        $a0, 8($s2)
/* AC5594 80240424 0C00EABB */  jal       get_npc_unsafe
/* AC5598 80240428 00A0882D */   daddu    $s1, $a1, $zero
/* AC559C 8024042C 8E240008 */  lw        $a0, 8($s1)
/* AC55A0 80240430 0040802D */  daddu     $s0, $v0, $zero
/* AC55A4 80240434 00041FC2 */  srl       $v1, $a0, 0x1f
/* AC55A8 80240438 00832021 */  addu      $a0, $a0, $v1
/* AC55AC 8024043C 00042043 */  sra       $a0, $a0, 1
/* AC55B0 80240440 0C00A67F */  jal       rand_int
/* AC55B4 80240444 24840001 */   addiu    $a0, $a0, 1
/* AC55B8 80240448 8E230008 */  lw        $v1, 8($s1)
/* AC55BC 8024044C 240400B4 */  addiu     $a0, $zero, 0xb4
/* AC55C0 80240450 00032FC2 */  srl       $a1, $v1, 0x1f
/* AC55C4 80240454 00651821 */  addu      $v1, $v1, $a1
/* AC55C8 80240458 00031843 */  sra       $v1, $v1, 1
/* AC55CC 8024045C 00621821 */  addu      $v1, $v1, $v0
/* AC55D0 80240460 0C00A67F */  jal       rand_int
/* AC55D4 80240464 A603008E */   sh       $v1, 0x8e($s0)
/* AC55D8 80240468 C60C000C */  lwc1      $f12, 0xc($s0)
/* AC55DC 8024046C 44820000 */  mtc1      $v0, $f0
/* AC55E0 80240470 00000000 */  nop       
/* AC55E4 80240474 46800020 */  cvt.s.w   $f0, $f0
/* AC55E8 80240478 46006300 */  add.s     $f12, $f12, $f0
/* AC55EC 8024047C 3C0142B4 */  lui       $at, 0x42b4
/* AC55F0 80240480 44810000 */  mtc1      $at, $f0
/* AC55F4 80240484 0C00A6C9 */  jal       clamp_angle
/* AC55F8 80240488 46006301 */   sub.s    $f12, $f12, $f0
/* AC55FC 8024048C E600000C */  swc1      $f0, 0xc($s0)
/* AC5600 80240490 8E4200CC */  lw        $v0, 0xcc($s2)
/* AC5604 80240494 8C420000 */  lw        $v0, ($v0)
/* AC5608 80240498 AE020028 */  sw        $v0, 0x28($s0)
/* AC560C 8024049C 24020003 */  addiu     $v0, $zero, 3
/* AC5610 802404A0 AE620070 */  sw        $v0, 0x70($s3)
/* AC5614 802404A4 8FBF0020 */  lw        $ra, 0x20($sp)
/* AC5618 802404A8 8FB3001C */  lw        $s3, 0x1c($sp)
/* AC561C 802404AC 8FB20018 */  lw        $s2, 0x18($sp)
/* AC5620 802404B0 8FB10014 */  lw        $s1, 0x14($sp)
/* AC5624 802404B4 8FB00010 */  lw        $s0, 0x10($sp)
/* AC5628 802404B8 03E00008 */  jr        $ra
/* AC562C 802404BC 27BD0028 */   addiu    $sp, $sp, 0x28
