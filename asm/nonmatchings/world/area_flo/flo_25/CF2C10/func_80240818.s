.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240818
/* CF33E8 80240818 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* CF33EC 8024081C AFB3001C */  sw        $s3, 0x1c($sp)
/* CF33F0 80240820 0080982D */  daddu     $s3, $a0, $zero
/* CF33F4 80240824 AFBF0020 */  sw        $ra, 0x20($sp)
/* CF33F8 80240828 AFB20018 */  sw        $s2, 0x18($sp)
/* CF33FC 8024082C AFB10014 */  sw        $s1, 0x14($sp)
/* CF3400 80240830 AFB00010 */  sw        $s0, 0x10($sp)
/* CF3404 80240834 8E720148 */  lw        $s2, 0x148($s3)
/* CF3408 80240838 86440008 */  lh        $a0, 8($s2)
/* CF340C 8024083C 0C00EABB */  jal       get_npc_unsafe
/* CF3410 80240840 00A0882D */   daddu    $s1, $a1, $zero
/* CF3414 80240844 8E240008 */  lw        $a0, 8($s1)
/* CF3418 80240848 0040802D */  daddu     $s0, $v0, $zero
/* CF341C 8024084C 00041FC2 */  srl       $v1, $a0, 0x1f
/* CF3420 80240850 00832021 */  addu      $a0, $a0, $v1
/* CF3424 80240854 00042043 */  sra       $a0, $a0, 1
/* CF3428 80240858 0C00A67F */  jal       rand_int
/* CF342C 8024085C 24840001 */   addiu    $a0, $a0, 1
/* CF3430 80240860 8E230008 */  lw        $v1, 8($s1)
/* CF3434 80240864 240400B4 */  addiu     $a0, $zero, 0xb4
/* CF3438 80240868 00032FC2 */  srl       $a1, $v1, 0x1f
/* CF343C 8024086C 00651821 */  addu      $v1, $v1, $a1
/* CF3440 80240870 00031843 */  sra       $v1, $v1, 1
/* CF3444 80240874 00621821 */  addu      $v1, $v1, $v0
/* CF3448 80240878 0C00A67F */  jal       rand_int
/* CF344C 8024087C A603008E */   sh       $v1, 0x8e($s0)
/* CF3450 80240880 C60C000C */  lwc1      $f12, 0xc($s0)
/* CF3454 80240884 44820000 */  mtc1      $v0, $f0
/* CF3458 80240888 00000000 */  nop       
/* CF345C 8024088C 46800020 */  cvt.s.w   $f0, $f0
/* CF3460 80240890 46006300 */  add.s     $f12, $f12, $f0
/* CF3464 80240894 3C0142B4 */  lui       $at, 0x42b4
/* CF3468 80240898 44810000 */  mtc1      $at, $f0
/* CF346C 8024089C 0C00A6C9 */  jal       clamp_angle
/* CF3470 802408A0 46006301 */   sub.s    $f12, $f12, $f0
/* CF3474 802408A4 E600000C */  swc1      $f0, 0xc($s0)
/* CF3478 802408A8 8E4200CC */  lw        $v0, 0xcc($s2)
/* CF347C 802408AC 8C420000 */  lw        $v0, ($v0)
/* CF3480 802408B0 AE020028 */  sw        $v0, 0x28($s0)
/* CF3484 802408B4 24020003 */  addiu     $v0, $zero, 3
/* CF3488 802408B8 AE620070 */  sw        $v0, 0x70($s3)
/* CF348C 802408BC 8FBF0020 */  lw        $ra, 0x20($sp)
/* CF3490 802408C0 8FB3001C */  lw        $s3, 0x1c($sp)
/* CF3494 802408C4 8FB20018 */  lw        $s2, 0x18($sp)
/* CF3498 802408C8 8FB10014 */  lw        $s1, 0x14($sp)
/* CF349C 802408CC 8FB00010 */  lw        $s0, 0x10($sp)
/* CF34A0 802408D0 03E00008 */  jr        $ra
/* CF34A4 802408D4 27BD0028 */   addiu    $sp, $sp, 0x28
