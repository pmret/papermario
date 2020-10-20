.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406CC_BC494C
/* BC494C 802406CC 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* BC4950 802406D0 AFB1001C */  sw        $s1, 0x1c($sp)
/* BC4954 802406D4 0080882D */  daddu     $s1, $a0, $zero
/* BC4958 802406D8 AFBF0034 */  sw        $ra, 0x34($sp)
/* BC495C 802406DC AFB60030 */  sw        $s6, 0x30($sp)
/* BC4960 802406E0 AFB5002C */  sw        $s5, 0x2c($sp)
/* BC4964 802406E4 AFB40028 */  sw        $s4, 0x28($sp)
/* BC4968 802406E8 AFB30024 */  sw        $s3, 0x24($sp)
/* BC496C 802406EC AFB20020 */  sw        $s2, 0x20($sp)
/* BC4970 802406F0 AFB00018 */  sw        $s0, 0x18($sp)
/* BC4974 802406F4 F7B60040 */  sdc1      $f22, 0x40($sp)
/* BC4978 802406F8 F7B40038 */  sdc1      $f20, 0x38($sp)
/* BC497C 802406FC 8E30000C */  lw        $s0, 0xc($s1)
/* BC4980 80240700 8E160000 */  lw        $s6, ($s0)
/* BC4984 80240704 26100004 */  addiu     $s0, $s0, 4
/* BC4988 80240708 0C0B1EAF */  jal       get_variable
/* BC498C 8024070C 02C0282D */   daddu    $a1, $s6, $zero
/* BC4990 80240710 44820000 */  mtc1      $v0, $f0
/* BC4994 80240714 00000000 */  nop       
/* BC4998 80240718 46800020 */  cvt.s.w   $f0, $f0
/* BC499C 8024071C E7A00010 */  swc1      $f0, 0x10($sp)
/* BC49A0 80240720 8E140000 */  lw        $s4, ($s0)
/* BC49A4 80240724 26100004 */  addiu     $s0, $s0, 4
/* BC49A8 80240728 0220202D */  daddu     $a0, $s1, $zero
/* BC49AC 8024072C 0C0B1EAF */  jal       get_variable
/* BC49B0 80240730 0280282D */   daddu    $a1, $s4, $zero
/* BC49B4 80240734 0220202D */  daddu     $a0, $s1, $zero
/* BC49B8 80240738 8E150000 */  lw        $s5, ($s0)
/* BC49BC 8024073C 4482B000 */  mtc1      $v0, $f22
/* BC49C0 80240740 00000000 */  nop       
/* BC49C4 80240744 4680B5A0 */  cvt.s.w   $f22, $f22
/* BC49C8 80240748 0C0B1EAF */  jal       get_variable
/* BC49CC 8024074C 02A0282D */   daddu    $a1, $s5, $zero
/* BC49D0 80240750 2404FFFC */  addiu     $a0, $zero, -4
/* BC49D4 80240754 44820000 */  mtc1      $v0, $f0
/* BC49D8 80240758 00000000 */  nop       
/* BC49DC 8024075C 46800020 */  cvt.s.w   $f0, $f0
/* BC49E0 80240760 0C00EABB */  jal       get_npc_unsafe
/* BC49E4 80240764 E7A00014 */   swc1     $f0, 0x14($sp)
/* BC49E8 80240768 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* BC49EC 8024076C 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* BC49F0 80240770 3C014334 */  lui       $at, 0x4334
/* BC49F4 80240774 44816000 */  mtc1      $at, $f12
/* BC49F8 80240778 00041880 */  sll       $v1, $a0, 2
/* BC49FC 8024077C 00641821 */  addu      $v1, $v1, $a0
/* BC4A00 80240780 00031880 */  sll       $v1, $v1, 2
/* BC4A04 80240784 00641823 */  subu      $v1, $v1, $a0
/* BC4A08 80240788 000320C0 */  sll       $a0, $v1, 3
/* BC4A0C 8024078C 00641821 */  addu      $v1, $v1, $a0
/* BC4A10 80240790 000318C0 */  sll       $v1, $v1, 3
/* BC4A14 80240794 3C01800B */  lui       $at, 0x800b
/* BC4A18 80240798 00230821 */  addu      $at, $at, $v1
/* BC4A1C 8024079C C4201DEC */  lwc1      $f0, 0x1dec($at)
/* BC4A20 802407A0 460C0300 */  add.s     $f12, $f0, $f12
/* BC4A24 802407A4 0C00A6C9 */  jal       clamp_angle
/* BC4A28 802407A8 0040982D */   daddu    $s3, $v0, $zero
/* BC4A2C 802407AC 27B00010 */  addiu     $s0, $sp, 0x10
/* BC4A30 802407B0 0200202D */  daddu     $a0, $s0, $zero
/* BC4A34 802407B4 27B20014 */  addiu     $s2, $sp, 0x14
/* BC4A38 802407B8 0240282D */  daddu     $a1, $s2, $zero
/* BC4A3C 802407BC 3C064170 */  lui       $a2, 0x4170
/* BC4A40 802407C0 8E67000C */  lw        $a3, 0xc($s3)
/* BC4A44 802407C4 0C00A7E7 */  jal       add_vec2D_polar
/* BC4A48 802407C8 46000506 */   mov.s    $f20, $f0
/* BC4A4C 802407CC 0200202D */  daddu     $a0, $s0, $zero
/* BC4A50 802407D0 3C064120 */  lui       $a2, 0x4120
/* BC4A54 802407D4 4407A000 */  mfc1      $a3, $f20
/* BC4A58 802407D8 0C00A7E7 */  jal       add_vec2D_polar
/* BC4A5C 802407DC 0240282D */   daddu    $a1, $s2, $zero
/* BC4A60 802407E0 0220202D */  daddu     $a0, $s1, $zero
/* BC4A64 802407E4 C7A00010 */  lwc1      $f0, 0x10($sp)
/* BC4A68 802407E8 4600008D */  trunc.w.s $f2, $f0
/* BC4A6C 802407EC 44061000 */  mfc1      $a2, $f2
/* BC4A70 802407F0 0C0B2026 */  jal       set_variable
/* BC4A74 802407F4 02C0282D */   daddu    $a1, $s6, $zero
/* BC4A78 802407F8 0220202D */  daddu     $a0, $s1, $zero
/* BC4A7C 802407FC 4600B08D */  trunc.w.s $f2, $f22
/* BC4A80 80240800 44061000 */  mfc1      $a2, $f2
/* BC4A84 80240804 0C0B2026 */  jal       set_variable
/* BC4A88 80240808 0280282D */   daddu    $a1, $s4, $zero
/* BC4A8C 8024080C 0220202D */  daddu     $a0, $s1, $zero
/* BC4A90 80240810 C7A00014 */  lwc1      $f0, 0x14($sp)
/* BC4A94 80240814 4600008D */  trunc.w.s $f2, $f0
/* BC4A98 80240818 44061000 */  mfc1      $a2, $f2
/* BC4A9C 8024081C 0C0B2026 */  jal       set_variable
/* BC4AA0 80240820 02A0282D */   daddu    $a1, $s5, $zero
/* BC4AA4 80240824 8FBF0034 */  lw        $ra, 0x34($sp)
/* BC4AA8 80240828 8FB60030 */  lw        $s6, 0x30($sp)
/* BC4AAC 8024082C 8FB5002C */  lw        $s5, 0x2c($sp)
/* BC4AB0 80240830 8FB40028 */  lw        $s4, 0x28($sp)
/* BC4AB4 80240834 8FB30024 */  lw        $s3, 0x24($sp)
/* BC4AB8 80240838 8FB20020 */  lw        $s2, 0x20($sp)
/* BC4ABC 8024083C 8FB1001C */  lw        $s1, 0x1c($sp)
/* BC4AC0 80240840 8FB00018 */  lw        $s0, 0x18($sp)
/* BC4AC4 80240844 D7B60040 */  ldc1      $f22, 0x40($sp)
/* BC4AC8 80240848 D7B40038 */  ldc1      $f20, 0x38($sp)
/* BC4ACC 8024084C 24020002 */  addiu     $v0, $zero, 2
/* BC4AD0 80240850 03E00008 */  jr        $ra
/* BC4AD4 80240854 27BD0048 */   addiu    $sp, $sp, 0x48
