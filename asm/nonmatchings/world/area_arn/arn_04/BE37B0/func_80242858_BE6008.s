.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242858_BE6008
/* BE6008 80242858 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* BE600C 8024285C AFB3003C */  sw        $s3, 0x3c($sp)
/* BE6010 80242860 0080982D */  daddu     $s3, $a0, $zero
/* BE6014 80242864 AFBF0040 */  sw        $ra, 0x40($sp)
/* BE6018 80242868 AFB20038 */  sw        $s2, 0x38($sp)
/* BE601C 8024286C AFB10034 */  sw        $s1, 0x34($sp)
/* BE6020 80242870 AFB00030 */  sw        $s0, 0x30($sp)
/* BE6024 80242874 8E700148 */  lw        $s0, 0x148($s3)
/* BE6028 80242878 00A0902D */  daddu     $s2, $a1, $zero
/* BE602C 8024287C 86040008 */  lh        $a0, 8($s0)
/* BE6030 80242880 0C00EABB */  jal       get_npc_unsafe
/* BE6034 80242884 00C0882D */   daddu    $s1, $a2, $zero
/* BE6038 80242888 0220202D */  daddu     $a0, $s1, $zero
/* BE603C 8024288C 0200282D */  daddu     $a1, $s0, $zero
/* BE6040 80242890 AFA00010 */  sw        $zero, 0x10($sp)
/* BE6044 80242894 8E460024 */  lw        $a2, 0x24($s2)
/* BE6048 80242898 8E470028 */  lw        $a3, 0x28($s2)
/* BE604C 8024289C 0C01242D */  jal       func_800490B4
/* BE6050 802428A0 0040802D */   daddu    $s0, $v0, $zero
/* BE6054 802428A4 1040000B */  beqz      $v0, .L802428D4
/* BE6058 802428A8 00000000 */   nop      
/* BE605C 802428AC 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* BE6060 802428B0 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* BE6064 802428B4 C60C0038 */  lwc1      $f12, 0x38($s0)
/* BE6068 802428B8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BE606C 802428BC 8C460028 */  lw        $a2, 0x28($v0)
/* BE6070 802428C0 0C00A720 */  jal       atan2
/* BE6074 802428C4 8C470030 */   lw       $a3, 0x30($v0)
/* BE6078 802428C8 2402000C */  addiu     $v0, $zero, 0xc
/* BE607C 802428CC 08090A6B */  j         .L802429AC
/* BE6080 802428D0 E600000C */   swc1     $f0, 0xc($s0)
.L802428D4:
/* BE6084 802428D4 9602008E */  lhu       $v0, 0x8e($s0)
/* BE6088 802428D8 2442FFFF */  addiu     $v0, $v0, -1
/* BE608C 802428DC A602008E */  sh        $v0, 0x8e($s0)
/* BE6090 802428E0 00021400 */  sll       $v0, $v0, 0x10
/* BE6094 802428E4 1C400032 */  bgtz      $v0, .L802429B0
/* BE6098 802428E8 00000000 */   nop      
/* BE609C 802428EC 8E620074 */  lw        $v0, 0x74($s3)
/* BE60A0 802428F0 2442FFFF */  addiu     $v0, $v0, -1
/* BE60A4 802428F4 18400014 */  blez      $v0, .L80242948
/* BE60A8 802428F8 AE620074 */   sw       $v0, 0x74($s3)
/* BE60AC 802428FC C600000C */  lwc1      $f0, 0xc($s0)
/* BE60B0 80242900 3C014334 */  lui       $at, 0x4334
/* BE60B4 80242904 44816000 */  mtc1      $at, $f12
/* BE60B8 80242908 0C00A6C9 */  jal       clamp_angle
/* BE60BC 8024290C 460C0300 */   add.s    $f12, $f0, $f12
/* BE60C0 80242910 E600000C */  swc1      $f0, 0xc($s0)
/* BE60C4 80242914 8E440008 */  lw        $a0, 8($s2)
/* BE60C8 80242918 000417C2 */  srl       $v0, $a0, 0x1f
/* BE60CC 8024291C 00822021 */  addu      $a0, $a0, $v0
/* BE60D0 80242920 00042043 */  sra       $a0, $a0, 1
/* BE60D4 80242924 0C00A67F */  jal       rand_int
/* BE60D8 80242928 24840001 */   addiu    $a0, $a0, 1
/* BE60DC 8024292C 8E430008 */  lw        $v1, 8($s2)
/* BE60E0 80242930 000327C2 */  srl       $a0, $v1, 0x1f
/* BE60E4 80242934 00641821 */  addu      $v1, $v1, $a0
/* BE60E8 80242938 00031843 */  sra       $v1, $v1, 1
/* BE60EC 8024293C 00621821 */  addu      $v1, $v1, $v0
/* BE60F0 80242940 08090A6C */  j         .L802429B0
/* BE60F4 80242944 A603008E */   sh       $v1, 0x8e($s0)
.L80242948:
/* BE60F8 80242948 24040002 */  addiu     $a0, $zero, 2
/* BE60FC 8024294C 0200282D */  daddu     $a1, $s0, $zero
/* BE6100 80242950 0000302D */  daddu     $a2, $zero, $zero
/* BE6104 80242954 860300A8 */  lh        $v1, 0xa8($s0)
/* BE6108 80242958 3C013F80 */  lui       $at, 0x3f80
/* BE610C 8024295C 44810000 */  mtc1      $at, $f0
/* BE6110 80242960 3C014000 */  lui       $at, 0x4000
/* BE6114 80242964 44811000 */  mtc1      $at, $f2
/* BE6118 80242968 3C01C1A0 */  lui       $at, 0xc1a0
/* BE611C 8024296C 44812000 */  mtc1      $at, $f4
/* BE6120 80242970 2402000C */  addiu     $v0, $zero, 0xc
/* BE6124 80242974 AFA2001C */  sw        $v0, 0x1c($sp)
/* BE6128 80242978 44833000 */  mtc1      $v1, $f6
/* BE612C 8024297C 00000000 */  nop       
/* BE6130 80242980 468031A0 */  cvt.s.w   $f6, $f6
/* BE6134 80242984 44073000 */  mfc1      $a3, $f6
/* BE6138 80242988 27A20028 */  addiu     $v0, $sp, 0x28
/* BE613C 8024298C AFA20020 */  sw        $v0, 0x20($sp)
/* BE6140 80242990 E7A00010 */  swc1      $f0, 0x10($sp)
/* BE6144 80242994 E7A20014 */  swc1      $f2, 0x14($sp)
/* BE6148 80242998 0C01BFA4 */  jal       fx_emote
/* BE614C 8024299C E7A40018 */   swc1     $f4, 0x18($sp)
/* BE6150 802429A0 2402000F */  addiu     $v0, $zero, 0xf
/* BE6154 802429A4 A602008E */  sh        $v0, 0x8e($s0)
/* BE6158 802429A8 24020028 */  addiu     $v0, $zero, 0x28
.L802429AC:
/* BE615C 802429AC AE620070 */  sw        $v0, 0x70($s3)
.L802429B0:
/* BE6160 802429B0 8FBF0040 */  lw        $ra, 0x40($sp)
/* BE6164 802429B4 8FB3003C */  lw        $s3, 0x3c($sp)
/* BE6168 802429B8 8FB20038 */  lw        $s2, 0x38($sp)
/* BE616C 802429BC 8FB10034 */  lw        $s1, 0x34($sp)
/* BE6170 802429C0 8FB00030 */  lw        $s0, 0x30($sp)
/* BE6174 802429C4 03E00008 */  jr        $ra
/* BE6178 802429C8 27BD0048 */   addiu    $sp, $sp, 0x48
