.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243808_C7A4E8
/* C7A4E8 80243808 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* C7A4EC 8024380C AFB1001C */  sw        $s1, 0x1c($sp)
/* C7A4F0 80243810 0080882D */  daddu     $s1, $a0, $zero
/* C7A4F4 80243814 AFBF0034 */  sw        $ra, 0x34($sp)
/* C7A4F8 80243818 AFB60030 */  sw        $s6, 0x30($sp)
/* C7A4FC 8024381C AFB5002C */  sw        $s5, 0x2c($sp)
/* C7A500 80243820 AFB40028 */  sw        $s4, 0x28($sp)
/* C7A504 80243824 AFB30024 */  sw        $s3, 0x24($sp)
/* C7A508 80243828 AFB20020 */  sw        $s2, 0x20($sp)
/* C7A50C 8024382C AFB00018 */  sw        $s0, 0x18($sp)
/* C7A510 80243830 F7B60040 */  sdc1      $f22, 0x40($sp)
/* C7A514 80243834 F7B40038 */  sdc1      $f20, 0x38($sp)
/* C7A518 80243838 8E30000C */  lw        $s0, 0xc($s1)
/* C7A51C 8024383C 8E160000 */  lw        $s6, ($s0)
/* C7A520 80243840 26100004 */  addiu     $s0, $s0, 4
/* C7A524 80243844 0C0B1EAF */  jal       get_variable
/* C7A528 80243848 02C0282D */   daddu    $a1, $s6, $zero
/* C7A52C 8024384C 44820000 */  mtc1      $v0, $f0
/* C7A530 80243850 00000000 */  nop       
/* C7A534 80243854 46800020 */  cvt.s.w   $f0, $f0
/* C7A538 80243858 E7A00010 */  swc1      $f0, 0x10($sp)
/* C7A53C 8024385C 8E140000 */  lw        $s4, ($s0)
/* C7A540 80243860 26100004 */  addiu     $s0, $s0, 4
/* C7A544 80243864 0220202D */  daddu     $a0, $s1, $zero
/* C7A548 80243868 0C0B1EAF */  jal       get_variable
/* C7A54C 8024386C 0280282D */   daddu    $a1, $s4, $zero
/* C7A550 80243870 0220202D */  daddu     $a0, $s1, $zero
/* C7A554 80243874 8E150000 */  lw        $s5, ($s0)
/* C7A558 80243878 4482B000 */  mtc1      $v0, $f22
/* C7A55C 8024387C 00000000 */  nop       
/* C7A560 80243880 4680B5A0 */  cvt.s.w   $f22, $f22
/* C7A564 80243884 0C0B1EAF */  jal       get_variable
/* C7A568 80243888 02A0282D */   daddu    $a1, $s5, $zero
/* C7A56C 8024388C 2404FFFC */  addiu     $a0, $zero, -4
/* C7A570 80243890 44820000 */  mtc1      $v0, $f0
/* C7A574 80243894 00000000 */  nop       
/* C7A578 80243898 46800020 */  cvt.s.w   $f0, $f0
/* C7A57C 8024389C 0C00EABB */  jal       get_npc_unsafe
/* C7A580 802438A0 E7A00014 */   swc1     $f0, 0x14($sp)
/* C7A584 802438A4 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* C7A588 802438A8 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* C7A58C 802438AC 3C014334 */  lui       $at, 0x4334
/* C7A590 802438B0 44816000 */  mtc1      $at, $f12
/* C7A594 802438B4 00041880 */  sll       $v1, $a0, 2
/* C7A598 802438B8 00641821 */  addu      $v1, $v1, $a0
/* C7A59C 802438BC 00031880 */  sll       $v1, $v1, 2
/* C7A5A0 802438C0 00641823 */  subu      $v1, $v1, $a0
/* C7A5A4 802438C4 000320C0 */  sll       $a0, $v1, 3
/* C7A5A8 802438C8 00641821 */  addu      $v1, $v1, $a0
/* C7A5AC 802438CC 000318C0 */  sll       $v1, $v1, 3
/* C7A5B0 802438D0 3C01800B */  lui       $at, 0x800b
/* C7A5B4 802438D4 00230821 */  addu      $at, $at, $v1
/* C7A5B8 802438D8 C4201DEC */  lwc1      $f0, 0x1dec($at)
/* C7A5BC 802438DC 460C0300 */  add.s     $f12, $f0, $f12
/* C7A5C0 802438E0 0C00A6C9 */  jal       clamp_angle
/* C7A5C4 802438E4 0040982D */   daddu    $s3, $v0, $zero
/* C7A5C8 802438E8 27B00010 */  addiu     $s0, $sp, 0x10
/* C7A5CC 802438EC 0200202D */  daddu     $a0, $s0, $zero
/* C7A5D0 802438F0 27B20014 */  addiu     $s2, $sp, 0x14
/* C7A5D4 802438F4 0240282D */  daddu     $a1, $s2, $zero
/* C7A5D8 802438F8 3C064170 */  lui       $a2, 0x4170
/* C7A5DC 802438FC 8E67000C */  lw        $a3, 0xc($s3)
/* C7A5E0 80243900 0C00A7E7 */  jal       add_vec2D_polar
/* C7A5E4 80243904 46000506 */   mov.s    $f20, $f0
/* C7A5E8 80243908 0200202D */  daddu     $a0, $s0, $zero
/* C7A5EC 8024390C 3C064120 */  lui       $a2, 0x4120
/* C7A5F0 80243910 4407A000 */  mfc1      $a3, $f20
/* C7A5F4 80243914 0C00A7E7 */  jal       add_vec2D_polar
/* C7A5F8 80243918 0240282D */   daddu    $a1, $s2, $zero
/* C7A5FC 8024391C 0220202D */  daddu     $a0, $s1, $zero
/* C7A600 80243920 C7A00010 */  lwc1      $f0, 0x10($sp)
/* C7A604 80243924 4600008D */  trunc.w.s $f2, $f0
/* C7A608 80243928 44061000 */  mfc1      $a2, $f2
/* C7A60C 8024392C 0C0B2026 */  jal       set_variable
/* C7A610 80243930 02C0282D */   daddu    $a1, $s6, $zero
/* C7A614 80243934 0220202D */  daddu     $a0, $s1, $zero
/* C7A618 80243938 4600B08D */  trunc.w.s $f2, $f22
/* C7A61C 8024393C 44061000 */  mfc1      $a2, $f2
/* C7A620 80243940 0C0B2026 */  jal       set_variable
/* C7A624 80243944 0280282D */   daddu    $a1, $s4, $zero
/* C7A628 80243948 0220202D */  daddu     $a0, $s1, $zero
/* C7A62C 8024394C C7A00014 */  lwc1      $f0, 0x14($sp)
/* C7A630 80243950 4600008D */  trunc.w.s $f2, $f0
/* C7A634 80243954 44061000 */  mfc1      $a2, $f2
/* C7A638 80243958 0C0B2026 */  jal       set_variable
/* C7A63C 8024395C 02A0282D */   daddu    $a1, $s5, $zero
/* C7A640 80243960 8FBF0034 */  lw        $ra, 0x34($sp)
/* C7A644 80243964 8FB60030 */  lw        $s6, 0x30($sp)
/* C7A648 80243968 8FB5002C */  lw        $s5, 0x2c($sp)
/* C7A64C 8024396C 8FB40028 */  lw        $s4, 0x28($sp)
/* C7A650 80243970 8FB30024 */  lw        $s3, 0x24($sp)
/* C7A654 80243974 8FB20020 */  lw        $s2, 0x20($sp)
/* C7A658 80243978 8FB1001C */  lw        $s1, 0x1c($sp)
/* C7A65C 8024397C 8FB00018 */  lw        $s0, 0x18($sp)
/* C7A660 80243980 D7B60040 */  ldc1      $f22, 0x40($sp)
/* C7A664 80243984 D7B40038 */  ldc1      $f20, 0x38($sp)
/* C7A668 80243988 24020002 */  addiu     $v0, $zero, 2
/* C7A66C 8024398C 03E00008 */  jr        $ra
/* C7A670 80243990 27BD0048 */   addiu    $sp, $sp, 0x48
