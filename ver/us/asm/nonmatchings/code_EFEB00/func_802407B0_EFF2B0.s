.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802407B0_EFF2B0
/* EFF2B0 802407B0 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* EFF2B4 802407B4 AFB20018 */  sw        $s2, 0x18($sp)
/* EFF2B8 802407B8 0080902D */  daddu     $s2, $a0, $zero
/* EFF2BC 802407BC AFBF0028 */  sw        $ra, 0x28($sp)
/* EFF2C0 802407C0 AFB50024 */  sw        $s5, 0x24($sp)
/* EFF2C4 802407C4 AFB40020 */  sw        $s4, 0x20($sp)
/* EFF2C8 802407C8 AFB3001C */  sw        $s3, 0x1c($sp)
/* EFF2CC 802407CC AFB10014 */  sw        $s1, 0x14($sp)
/* EFF2D0 802407D0 AFB00010 */  sw        $s0, 0x10($sp)
/* EFF2D4 802407D4 F7B80040 */  sdc1      $f24, 0x40($sp)
/* EFF2D8 802407D8 F7B60038 */  sdc1      $f22, 0x38($sp)
/* EFF2DC 802407DC F7B40030 */  sdc1      $f20, 0x30($sp)
/* EFF2E0 802407E0 8E50000C */  lw        $s0, 0xc($s2)
/* EFF2E4 802407E4 8E140000 */  lw        $s4, ($s0)
/* EFF2E8 802407E8 26100004 */  addiu     $s0, $s0, 4
/* EFF2EC 802407EC 0C0B53A3 */  jal       dead_get_variable
/* EFF2F0 802407F0 0280282D */   daddu    $a1, $s4, $zero
/* EFF2F4 802407F4 0040982D */  daddu     $s3, $v0, $zero
/* EFF2F8 802407F8 8E150000 */  lw        $s5, ($s0)
/* EFF2FC 802407FC 26100004 */  addiu     $s0, $s0, 4
/* EFF300 80240800 8E050000 */  lw        $a1, ($s0)
/* EFF304 80240804 26100004 */  addiu     $s0, $s0, 4
/* EFF308 80240808 0C0B55FF */  jal       dead_get_float_variable
/* EFF30C 8024080C 0240202D */   daddu    $a0, $s2, $zero
/* EFF310 80240810 8E050000 */  lw        $a1, ($s0)
/* EFF314 80240814 26100004 */  addiu     $s0, $s0, 4
/* EFF318 80240818 0240202D */  daddu     $a0, $s2, $zero
/* EFF31C 8024081C 0C0B55FF */  jal       dead_get_float_variable
/* EFF320 80240820 46000606 */   mov.s    $f24, $f0
/* EFF324 80240824 8E050000 */  lw        $a1, ($s0)
/* EFF328 80240828 26100004 */  addiu     $s0, $s0, 4
/* EFF32C 8024082C 0240202D */  daddu     $a0, $s2, $zero
/* EFF330 80240830 0C0B53A3 */  jal       dead_get_variable
/* EFF334 80240834 46000506 */   mov.s    $f20, $f0
/* EFF338 80240838 8E050000 */  lw        $a1, ($s0)
/* EFF33C 8024083C 26100004 */  addiu     $s0, $s0, 4
/* EFF340 80240840 0240202D */  daddu     $a0, $s2, $zero
/* EFF344 80240844 0C0B53A3 */  jal       dead_get_variable
/* EFF348 80240848 0040882D */   daddu    $s1, $v0, $zero
/* EFF34C 8024084C 0240202D */  daddu     $a0, $s2, $zero
/* EFF350 80240850 8E050000 */  lw        $a1, ($s0)
/* EFF354 80240854 0C0B55FF */  jal       dead_get_float_variable
/* EFF358 80240858 0040802D */   daddu    $s0, $v0, $zero
/* EFF35C 8024085C 3C014334 */  lui       $at, 0x4334
/* EFF360 80240860 44811000 */  mtc1      $at, $f2
/* EFF364 80240864 3C014049 */  lui       $at, 0x4049
/* EFF368 80240868 34210FD8 */  ori       $at, $at, 0xfd8
/* EFF36C 8024086C 44812000 */  mtc1      $at, $f4
/* EFF370 80240870 46020003 */  div.s     $f0, $f0, $f2
/* EFF374 80240874 46040582 */  mul.s     $f22, $f0, $f4
/* EFF378 80240878 00000000 */  nop
/* EFF37C 8024087C 4618A501 */  sub.s     $f20, $f20, $f24
/* EFF380 80240880 3C013F00 */  lui       $at, 0x3f00
/* EFF384 80240884 44810000 */  mtc1      $at, $f0
/* EFF388 80240888 00000000 */  nop
/* EFF38C 8024088C 4600A502 */  mul.s     $f20, $f20, $f0
/* EFF390 80240890 00000000 */  nop
/* EFF394 80240894 12000007 */  beqz      $s0, .L802408B4
/* EFF398 80240898 0233102A */   slt      $v0, $s1, $s3
/* EFF39C 8024089C 10400005 */  beqz      $v0, .L802408B4
/* EFF3A0 802408A0 0240202D */   daddu    $a0, $s2, $zero
/* EFF3A4 802408A4 0220982D */  daddu     $s3, $s1, $zero
/* EFF3A8 802408A8 0280282D */  daddu     $a1, $s4, $zero
/* EFF3AC 802408AC 0C0B551A */  jal       dead_set_variable
/* EFF3B0 802408B0 0220302D */   daddu    $a2, $s1, $zero
.L802408B4:
/* EFF3B4 802408B4 3C014049 */  lui       $at, 0x4049
/* EFF3B8 802408B8 34210FD8 */  ori       $at, $at, 0xfd8
/* EFF3BC 802408BC 44810000 */  mtc1      $at, $f0
/* EFF3C0 802408C0 44936000 */  mtc1      $s3, $f12
/* EFF3C4 802408C4 00000000 */  nop
/* EFF3C8 802408C8 46806320 */  cvt.s.w   $f12, $f12
/* EFF3CC 802408CC 46006302 */  mul.s     $f12, $f12, $f0
/* EFF3D0 802408D0 00000000 */  nop
/* EFF3D4 802408D4 44910000 */  mtc1      $s1, $f0
/* EFF3D8 802408D8 00000000 */  nop
/* EFF3DC 802408DC 46800020 */  cvt.s.w   $f0, $f0
/* EFF3E0 802408E0 46006303 */  div.s     $f12, $f12, $f0
/* EFF3E4 802408E4 0C00AD30 */  jal       dead_cos_rad
/* EFF3E8 802408E8 46166300 */   add.s    $f12, $f12, $f22
/* EFF3EC 802408EC 4600A002 */  mul.s     $f0, $f20, $f0
/* EFF3F0 802408F0 00000000 */  nop
/* EFF3F4 802408F4 4614C080 */  add.s     $f2, $f24, $f20
/* EFF3F8 802408F8 46001081 */  sub.s     $f2, $f2, $f0
/* EFF3FC 802408FC 0240202D */  daddu     $a0, $s2, $zero
/* EFF400 80240900 44061000 */  mfc1      $a2, $f2
/* EFF404 80240904 0C0B5684 */  jal       dead_set_float_variable
/* EFF408 80240908 02A0282D */   daddu    $a1, $s5, $zero
/* EFF40C 8024090C 8FBF0028 */  lw        $ra, 0x28($sp)
/* EFF410 80240910 8FB50024 */  lw        $s5, 0x24($sp)
/* EFF414 80240914 8FB40020 */  lw        $s4, 0x20($sp)
/* EFF418 80240918 8FB3001C */  lw        $s3, 0x1c($sp)
/* EFF41C 8024091C 8FB20018 */  lw        $s2, 0x18($sp)
/* EFF420 80240920 8FB10014 */  lw        $s1, 0x14($sp)
/* EFF424 80240924 8FB00010 */  lw        $s0, 0x10($sp)
/* EFF428 80240928 D7B80040 */  ldc1      $f24, 0x40($sp)
/* EFF42C 8024092C D7B60038 */  ldc1      $f22, 0x38($sp)
/* EFF430 80240930 D7B40030 */  ldc1      $f20, 0x30($sp)
/* EFF434 80240934 24020002 */  addiu     $v0, $zero, 2
/* EFF438 80240938 03E00008 */  jr        $ra
/* EFF43C 8024093C 27BD0048 */   addiu    $sp, $sp, 0x48
