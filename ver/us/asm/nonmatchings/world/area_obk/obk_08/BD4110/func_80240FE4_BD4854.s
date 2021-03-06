.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240FE4_BD4854
/* BD4854 80240FE4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BD4858 80240FE8 AFB10014 */  sw        $s1, 0x14($sp)
/* BD485C 80240FEC 0080882D */  daddu     $s1, $a0, $zero
/* BD4860 80240FF0 AFBF0018 */  sw        $ra, 0x18($sp)
/* BD4864 80240FF4 AFB00010 */  sw        $s0, 0x10($sp)
/* BD4868 80240FF8 0C00EAD2 */  jal       get_npc_safe
/* BD486C 80240FFC 8E24014C */   lw       $a0, 0x14c($s1)
/* BD4870 80241000 0040802D */  daddu     $s0, $v0, $zero
/* BD4874 80241004 8E230074 */  lw        $v1, 0x74($s1)
/* BD4878 80241008 24020001 */  addiu     $v0, $zero, 1
/* BD487C 8024100C 10620036 */  beq       $v1, $v0, .L802410E8
/* BD4880 80241010 28620002 */   slti     $v0, $v1, 2
/* BD4884 80241014 10400005 */  beqz      $v0, .L8024102C
/* BD4888 80241018 24020002 */   addiu    $v0, $zero, 2
/* BD488C 8024101C 10600007 */  beqz      $v1, .L8024103C
/* BD4890 80241020 00000000 */   nop
/* BD4894 80241024 08090455 */  j         .L80241154
/* BD4898 80241028 00000000 */   nop
.L8024102C:
/* BD489C 8024102C 10620036 */  beq       $v1, $v0, .L80241108
/* BD48A0 80241030 00000000 */   nop
/* BD48A4 80241034 08090455 */  j         .L80241154
/* BD48A8 80241038 00000000 */   nop
.L8024103C:
/* BD48AC 8024103C 0C00A67F */  jal       rand_int
/* BD48B0 80241040 240400B4 */   addiu    $a0, $zero, 0xb4
/* BD48B4 80241044 24040032 */  addiu     $a0, $zero, 0x32
/* BD48B8 80241048 3C01C3D7 */  lui       $at, 0xc3d7
/* BD48BC 8024104C 44810000 */  mtc1      $at, $f0
/* BD48C0 80241050 2442001E */  addiu     $v0, $v0, 0x1e
/* BD48C4 80241054 A602008E */  sh        $v0, 0x8e($s0)
/* BD48C8 80241058 0C00A67F */  jal       rand_int
/* BD48CC 8024105C E6000040 */   swc1     $f0, 0x40($s0)
/* BD48D0 80241060 3C014220 */  lui       $at, 0x4220
/* BD48D4 80241064 44811000 */  mtc1      $at, $f2
/* BD48D8 80241068 44820000 */  mtc1      $v0, $f0
/* BD48DC 8024106C 00000000 */  nop
/* BD48E0 80241070 46800020 */  cvt.s.w   $f0, $f0
/* BD48E4 80241074 46020000 */  add.s     $f0, $f0, $f2
/* BD48E8 80241078 0C00A64D */  jal       func_80029934
/* BD48EC 8024107C E600003C */   swc1     $f0, 0x3c($s0)
/* BD48F0 80241080 46000000 */  add.s     $f0, $f0, $f0
/* BD48F4 80241084 3C014000 */  lui       $at, 0x4000
/* BD48F8 80241088 44811000 */  mtc1      $at, $f2
/* BD48FC 8024108C 00000000 */  nop
/* BD4900 80241090 46020000 */  add.s     $f0, $f0, $f2
/* BD4904 80241094 24040064 */  addiu     $a0, $zero, 0x64
/* BD4908 80241098 0C00A67F */  jal       rand_int
/* BD490C 8024109C E6000018 */   swc1     $f0, 0x18($s0)
/* BD4910 802410A0 28420032 */  slti      $v0, $v0, 0x32
/* BD4914 802410A4 10400007 */  beqz      $v0, .L802410C4
/* BD4918 802410A8 00000000 */   nop
/* BD491C 802410AC 3C014387 */  lui       $at, 0x4387
/* BD4920 802410B0 44810000 */  mtc1      $at, $f0
/* BD4924 802410B4 00000000 */  nop
/* BD4928 802410B8 E6000038 */  swc1      $f0, 0x38($s0)
/* BD492C 802410BC 08090437 */  j         .L802410DC
/* BD4930 802410C0 E600000C */   swc1     $f0, 0xc($s0)
.L802410C4:
/* BD4934 802410C4 3C01C387 */  lui       $at, 0xc387
/* BD4938 802410C8 44810000 */  mtc1      $at, $f0
/* BD493C 802410CC 3C0142B4 */  lui       $at, 0x42b4
/* BD4940 802410D0 44811000 */  mtc1      $at, $f2
/* BD4944 802410D4 E6000038 */  swc1      $f0, 0x38($s0)
/* BD4948 802410D8 E602000C */  swc1      $f2, 0xc($s0)
.L802410DC:
/* BD494C 802410DC 24020001 */  addiu     $v0, $zero, 1
/* BD4950 802410E0 08090455 */  j         .L80241154
/* BD4954 802410E4 AE220074 */   sw       $v0, 0x74($s1)
.L802410E8:
/* BD4958 802410E8 9602008E */  lhu       $v0, 0x8e($s0)
/* BD495C 802410EC 2442FFFF */  addiu     $v0, $v0, -1
/* BD4960 802410F0 A602008E */  sh        $v0, 0x8e($s0)
/* BD4964 802410F4 00021400 */  sll       $v0, $v0, 0x10
/* BD4968 802410F8 14400016 */  bnez      $v0, .L80241154
/* BD496C 802410FC 24020002 */   addiu    $v0, $zero, 2
/* BD4970 80241100 08090455 */  j         .L80241154
/* BD4974 80241104 AE220074 */   sw       $v0, 0x74($s1)
.L80241108:
/* BD4978 80241108 8E050018 */  lw        $a1, 0x18($s0)
/* BD497C 8024110C 8E06000C */  lw        $a2, 0xc($s0)
/* BD4980 80241110 0C00EA95 */  jal       npc_move_heading
/* BD4984 80241114 0200202D */   daddu    $a0, $s0, $zero
/* BD4988 80241118 C6020038 */  lwc1      $f2, 0x38($s0)
/* BD498C 8024111C 3C01C38C */  lui       $at, 0xc38c
/* BD4990 80241120 44810000 */  mtc1      $at, $f0
/* BD4994 80241124 00000000 */  nop
/* BD4998 80241128 4600103C */  c.lt.s    $f2, $f0
/* BD499C 8024112C 00000000 */  nop
/* BD49A0 80241130 45030008 */  bc1tl     .L80241154
/* BD49A4 80241134 AE200074 */   sw       $zero, 0x74($s1)
/* BD49A8 80241138 3C01438C */  lui       $at, 0x438c
/* BD49AC 8024113C 44810000 */  mtc1      $at, $f0
/* BD49B0 80241140 00000000 */  nop
/* BD49B4 80241144 4602003C */  c.lt.s    $f0, $f2
/* BD49B8 80241148 00000000 */  nop
/* BD49BC 8024114C 45030001 */  bc1tl     .L80241154
/* BD49C0 80241150 AE200074 */   sw       $zero, 0x74($s1)
.L80241154:
/* BD49C4 80241154 8FBF0018 */  lw        $ra, 0x18($sp)
/* BD49C8 80241158 8FB10014 */  lw        $s1, 0x14($sp)
/* BD49CC 8024115C 8FB00010 */  lw        $s0, 0x10($sp)
/* BD49D0 80241160 24020002 */  addiu     $v0, $zero, 2
/* BD49D4 80241164 03E00008 */  jr        $ra
/* BD49D8 80241168 27BD0020 */   addiu    $sp, $sp, 0x20
