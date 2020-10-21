.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241488_A1C588
/* A1C588 80241488 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* A1C58C 8024148C AFB3001C */  sw        $s3, 0x1c($sp)
/* A1C590 80241490 0080982D */  daddu     $s3, $a0, $zero
/* A1C594 80241494 AFBF0020 */  sw        $ra, 0x20($sp)
/* A1C598 80241498 AFB20018 */  sw        $s2, 0x18($sp)
/* A1C59C 8024149C AFB10014 */  sw        $s1, 0x14($sp)
/* A1C5A0 802414A0 AFB00010 */  sw        $s0, 0x10($sp)
/* A1C5A4 802414A4 8E720148 */  lw        $s2, 0x148($s3)
/* A1C5A8 802414A8 86440008 */  lh        $a0, 8($s2)
/* A1C5AC 802414AC 0C00EABB */  jal       get_npc_unsafe
/* A1C5B0 802414B0 00A0882D */   daddu    $s1, $a1, $zero
/* A1C5B4 802414B4 8E240008 */  lw        $a0, 8($s1)
/* A1C5B8 802414B8 0040802D */  daddu     $s0, $v0, $zero
/* A1C5BC 802414BC 00041FC2 */  srl       $v1, $a0, 0x1f
/* A1C5C0 802414C0 00832021 */  addu      $a0, $a0, $v1
/* A1C5C4 802414C4 00042043 */  sra       $a0, $a0, 1
/* A1C5C8 802414C8 0C00A67F */  jal       rand_int
/* A1C5CC 802414CC 24840001 */   addiu    $a0, $a0, 1
/* A1C5D0 802414D0 8E230008 */  lw        $v1, 8($s1)
/* A1C5D4 802414D4 240400B4 */  addiu     $a0, $zero, 0xb4
/* A1C5D8 802414D8 00032FC2 */  srl       $a1, $v1, 0x1f
/* A1C5DC 802414DC 00651821 */  addu      $v1, $v1, $a1
/* A1C5E0 802414E0 00031843 */  sra       $v1, $v1, 1
/* A1C5E4 802414E4 00621821 */  addu      $v1, $v1, $v0
/* A1C5E8 802414E8 0C00A67F */  jal       rand_int
/* A1C5EC 802414EC A603008E */   sh       $v1, 0x8e($s0)
/* A1C5F0 802414F0 C60C000C */  lwc1      $f12, 0xc($s0)
/* A1C5F4 802414F4 44820000 */  mtc1      $v0, $f0
/* A1C5F8 802414F8 00000000 */  nop       
/* A1C5FC 802414FC 46800020 */  cvt.s.w   $f0, $f0
/* A1C600 80241500 46006300 */  add.s     $f12, $f12, $f0
/* A1C604 80241504 3C0142B4 */  lui       $at, 0x42b4
/* A1C608 80241508 44810000 */  mtc1      $at, $f0
/* A1C60C 8024150C 0C00A6C9 */  jal       clamp_angle
/* A1C610 80241510 46006301 */   sub.s    $f12, $f12, $f0
/* A1C614 80241514 E600000C */  swc1      $f0, 0xc($s0)
/* A1C618 80241518 8E4200CC */  lw        $v0, 0xcc($s2)
/* A1C61C 8024151C 8C420000 */  lw        $v0, ($v0)
/* A1C620 80241520 AE020028 */  sw        $v0, 0x28($s0)
/* A1C624 80241524 24020003 */  addiu     $v0, $zero, 3
/* A1C628 80241528 AE620070 */  sw        $v0, 0x70($s3)
/* A1C62C 8024152C 8FBF0020 */  lw        $ra, 0x20($sp)
/* A1C630 80241530 8FB3001C */  lw        $s3, 0x1c($sp)
/* A1C634 80241534 8FB20018 */  lw        $s2, 0x18($sp)
/* A1C638 80241538 8FB10014 */  lw        $s1, 0x14($sp)
/* A1C63C 8024153C 8FB00010 */  lw        $s0, 0x10($sp)
/* A1C640 80241540 03E00008 */  jr        $ra
/* A1C644 80241544 27BD0028 */   addiu    $sp, $sp, 0x28
