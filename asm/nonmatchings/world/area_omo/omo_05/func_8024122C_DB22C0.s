.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024122C_DB34EC
/* DB34EC 8024122C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* DB34F0 80241230 AFB3001C */  sw        $s3, 0x1c($sp)
/* DB34F4 80241234 0080982D */  daddu     $s3, $a0, $zero
/* DB34F8 80241238 AFBF0020 */  sw        $ra, 0x20($sp)
/* DB34FC 8024123C AFB20018 */  sw        $s2, 0x18($sp)
/* DB3500 80241240 AFB10014 */  sw        $s1, 0x14($sp)
/* DB3504 80241244 AFB00010 */  sw        $s0, 0x10($sp)
/* DB3508 80241248 8E720148 */  lw        $s2, 0x148($s3)
/* DB350C 8024124C 86440008 */  lh        $a0, 8($s2)
/* DB3510 80241250 0C00EABB */  jal       get_npc_unsafe
/* DB3514 80241254 00A0882D */   daddu    $s1, $a1, $zero
/* DB3518 80241258 8E240008 */  lw        $a0, 8($s1)
/* DB351C 8024125C 0040802D */  daddu     $s0, $v0, $zero
/* DB3520 80241260 00041FC2 */  srl       $v1, $a0, 0x1f
/* DB3524 80241264 00832021 */  addu      $a0, $a0, $v1
/* DB3528 80241268 00042043 */  sra       $a0, $a0, 1
/* DB352C 8024126C 0C00A67F */  jal       rand_int
/* DB3530 80241270 24840001 */   addiu    $a0, $a0, 1
/* DB3534 80241274 8E230008 */  lw        $v1, 8($s1)
/* DB3538 80241278 240400B4 */  addiu     $a0, $zero, 0xb4
/* DB353C 8024127C 00032FC2 */  srl       $a1, $v1, 0x1f
/* DB3540 80241280 00651821 */  addu      $v1, $v1, $a1
/* DB3544 80241284 00031843 */  sra       $v1, $v1, 1
/* DB3548 80241288 00621821 */  addu      $v1, $v1, $v0
/* DB354C 8024128C 0C00A67F */  jal       rand_int
/* DB3550 80241290 A603008E */   sh       $v1, 0x8e($s0)
/* DB3554 80241294 C60C000C */  lwc1      $f12, 0xc($s0)
/* DB3558 80241298 44820000 */  mtc1      $v0, $f0
/* DB355C 8024129C 00000000 */  nop       
/* DB3560 802412A0 46800020 */  cvt.s.w   $f0, $f0
/* DB3564 802412A4 46006300 */  add.s     $f12, $f12, $f0
/* DB3568 802412A8 3C0142B4 */  lui       $at, 0x42b4
/* DB356C 802412AC 44810000 */  mtc1      $at, $f0
/* DB3570 802412B0 0C00A6C9 */  jal       clamp_angle
/* DB3574 802412B4 46006301 */   sub.s    $f12, $f12, $f0
/* DB3578 802412B8 E600000C */  swc1      $f0, 0xc($s0)
/* DB357C 802412BC 8E4200CC */  lw        $v0, 0xcc($s2)
/* DB3580 802412C0 8C420000 */  lw        $v0, ($v0)
/* DB3584 802412C4 AE020028 */  sw        $v0, 0x28($s0)
/* DB3588 802412C8 24020003 */  addiu     $v0, $zero, 3
/* DB358C 802412CC AE620070 */  sw        $v0, 0x70($s3)
/* DB3590 802412D0 8FBF0020 */  lw        $ra, 0x20($sp)
/* DB3594 802412D4 8FB3001C */  lw        $s3, 0x1c($sp)
/* DB3598 802412D8 8FB20018 */  lw        $s2, 0x18($sp)
/* DB359C 802412DC 8FB10014 */  lw        $s1, 0x14($sp)
/* DB35A0 802412E0 8FB00010 */  lw        $s0, 0x10($sp)
/* DB35A4 802412E4 03E00008 */  jr        $ra
/* DB35A8 802412E8 27BD0028 */   addiu    $sp, $sp, 0x28
