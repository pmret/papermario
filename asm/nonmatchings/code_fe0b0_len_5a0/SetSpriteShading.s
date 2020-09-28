.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetSpriteShading
/* FE0B0 802D9700 27BDFF98 */  addiu     $sp, $sp, -0x68
/* FE0B4 802D9704 AFBF0064 */  sw        $ra, 0x64($sp)
/* FE0B8 802D9708 AFBE0060 */  sw        $fp, 0x60($sp)
/* FE0BC 802D970C AFB7005C */  sw        $s7, 0x5c($sp)
/* FE0C0 802D9710 AFB60058 */  sw        $s6, 0x58($sp)
/* FE0C4 802D9714 AFB50054 */  sw        $s5, 0x54($sp)
/* FE0C8 802D9718 AFB40050 */  sw        $s4, 0x50($sp)
/* FE0CC 802D971C AFB3004C */  sw        $s3, 0x4c($sp)
/* FE0D0 802D9720 AFB20048 */  sw        $s2, 0x48($sp)
/* FE0D4 802D9724 AFB10044 */  sw        $s1, 0x44($sp)
/* FE0D8 802D9728 AFB00040 */  sw        $s0, 0x40($sp)
/* FE0DC 802D972C 8C82000C */  lw        $v0, 0xc($a0)
/* FE0E0 802D9730 0C0B1EAF */  jal       get_variable
/* FE0E4 802D9734 8C450000 */   lw       $a1, ($v0)
/* FE0E8 802D9738 00021C03 */  sra       $v1, $v0, 0x10
/* FE0EC 802D973C 000330C0 */  sll       $a2, $v1, 3
/* FE0F0 802D9740 3043FFFF */  andi      $v1, $v0, 0xffff
/* FE0F4 802D9744 00039080 */  sll       $s2, $v1, 2
/* FE0F8 802D9748 2403FFFF */  addiu     $v1, $zero, -1
/* FE0FC 802D974C 104300AF */  beq       $v0, $v1, .L802D9A0C
/* FE100 802D9750 24020002 */   addiu    $v0, $zero, 2
/* FE104 802D9754 3C100031 */  lui       $s0, 0x31
/* FE108 802D9758 26105B80 */  addiu     $s0, $s0, 0x5b80
/* FE10C 802D975C 00D02021 */  addu      $a0, $a2, $s0
/* FE110 802D9760 26050008 */  addiu     $a1, $s0, 8
/* FE114 802D9764 00C52821 */  addu      $a1, $a2, $a1
/* FE118 802D9768 3C11802E */  lui       $s1, 0x802e
/* FE11C 802D976C 2631BB60 */  addiu     $s1, $s1, -0x44a0
/* FE120 802D9770 0C00A5CF */  jal       dma_copy
/* FE124 802D9774 0220302D */   daddu    $a2, $s1, $zero
/* FE128 802D9778 0220302D */  daddu     $a2, $s1, $zero
/* FE12C 802D977C 8E240004 */  lw        $a0, 4($s1)
/* FE130 802D9780 02508021 */  addu      $s0, $s2, $s0
/* FE134 802D9784 00902021 */  addu      $a0, $a0, $s0
/* FE138 802D9788 8E300000 */  lw        $s0, ($s1)
/* FE13C 802D978C 0C00A5CF */  jal       dma_copy
/* FE140 802D9790 24850004 */   addiu    $a1, $a0, 4
/* FE144 802D9794 3C12802E */  lui       $s2, 0x802e
/* FE148 802D9798 2652BB68 */  addiu     $s2, $s2, -0x4498
/* FE14C 802D979C 0240302D */  daddu     $a2, $s2, $zero
/* FE150 802D97A0 8E220000 */  lw        $v0, ($s1)
/* FE154 802D97A4 3C030031 */  lui       $v1, 0x31
/* FE158 802D97A8 24635D50 */  addiu     $v1, $v1, 0x5d50
/* FE15C 802D97AC 00431021 */  addu      $v0, $v0, $v1
/* FE160 802D97B0 02028021 */  addu      $s0, $s0, $v0
/* FE164 802D97B4 0200202D */  daddu     $a0, $s0, $zero
/* FE168 802D97B8 0C00A5CF */  jal       dma_copy
/* FE16C 802D97BC 24850100 */   addiu    $a1, $a0, 0x100
/* FE170 802D97C0 3C058015 */  lui       $a1, %hi(D_80151328)
/* FE174 802D97C4 24A51328 */  addiu     $a1, $a1, %lo(D_80151328)
/* FE178 802D97C8 92470000 */  lbu       $a3, ($s2)
/* FE17C 802D97CC 8CA30000 */  lw        $v1, ($a1)
/* FE180 802D97D0 92420002 */  lbu       $v0, 2($s2)
/* FE184 802D97D4 AFA70014 */  sw        $a3, 0x14($sp)
/* FE188 802D97D8 A06200AC */  sb        $v0, 0xac($v1)
/* FE18C 802D97DC 92420003 */  lbu       $v0, 3($s2)
/* FE190 802D97E0 A06200AD */  sb        $v0, 0xad($v1)
/* FE194 802D97E4 92420004 */  lbu       $v0, 4($s2)
/* FE198 802D97E8 A06200AE */  sb        $v0, 0xae($v1)
/* FE19C 802D97EC 92420005 */  lbu       $v0, 5($s2)
/* FE1A0 802D97F0 0000882D */  daddu     $s1, $zero, $zero
/* FE1A4 802D97F4 10E0007F */  beqz      $a3, .L802D99F4
/* FE1A8 802D97F8 A06200AF */   sb       $v0, 0xaf($v1)
/* FE1AC 802D97FC 0240802D */  daddu     $s0, $s2, $zero
/* FE1B0 802D9800 24070014 */  addiu     $a3, $zero, 0x14
/* FE1B4 802D9804 AFA7002C */  sw        $a3, 0x2c($sp)
/* FE1B8 802D9808 24070010 */  addiu     $a3, $zero, 0x10
/* FE1BC 802D980C 240B0011 */  addiu     $t3, $zero, 0x11
/* FE1C0 802D9810 240C0012 */  addiu     $t4, $zero, 0x12
/* FE1C4 802D9814 240D0013 */  addiu     $t5, $zero, 0x13
/* FE1C8 802D9818 240E000F */  addiu     $t6, $zero, 0xf
/* FE1CC 802D981C 240F000E */  addiu     $t7, $zero, 0xe
/* FE1D0 802D9820 241E000D */  addiu     $fp, $zero, 0xd
/* FE1D4 802D9824 2417000C */  addiu     $s7, $zero, 0xc
/* FE1D8 802D9828 2416000B */  addiu     $s6, $zero, 0xb
/* FE1DC 802D982C 2415000A */  addiu     $s5, $zero, 0xa
/* FE1E0 802D9830 24140009 */  addiu     $s4, $zero, 9
/* FE1E4 802D9834 24130008 */  addiu     $s3, $zero, 8
/* FE1E8 802D9838 24190007 */  addiu     $t9, $zero, 7
/* FE1EC 802D983C 24180006 */  addiu     $t8, $zero, 6
/* FE1F0 802D9840 24120004 */  addiu     $s2, $zero, 4
/* FE1F4 802D9844 AFA70030 */  sw        $a3, 0x30($sp)
.L802D9848:
/* FE1F8 802D9848 01D05021 */  addu      $t2, $t6, $s0
/* FE1FC 802D984C 25CE0010 */  addiu     $t6, $t6, 0x10
/* FE200 802D9850 01F04821 */  addu      $t1, $t7, $s0
/* FE204 802D9854 25EF0010 */  addiu     $t7, $t7, 0x10
/* FE208 802D9858 03D04021 */  addu      $t0, $fp, $s0
/* FE20C 802D985C 27DE0010 */  addiu     $fp, $fp, 0x10
/* FE210 802D9860 02D03021 */  addu      $a2, $s6, $s0
/* FE214 802D9864 26D60010 */  addiu     $s6, $s6, 0x10
/* FE218 802D9868 02B02021 */  addu      $a0, $s5, $s0
/* FE21C 802D986C 26B50010 */  addiu     $s5, $s5, 0x10
/* FE220 802D9870 03101021 */  addu      $v0, $t8, $s0
/* FE224 802D9874 02901821 */  addu      $v1, $s4, $s0
/* FE228 802D9878 8FA7002C */  lw        $a3, 0x2c($sp)
/* FE22C 802D987C 26940010 */  addiu     $s4, $s4, 0x10
/* FE230 802D9880 00F03821 */  addu      $a3, $a3, $s0
/* FE234 802D9884 AFA70028 */  sw        $a3, 0x28($sp)
/* FE238 802D9888 8FA7002C */  lw        $a3, 0x2c($sp)
/* FE23C 802D988C 27180010 */  addiu     $t8, $t8, 0x10
/* FE240 802D9890 24E70010 */  addiu     $a3, $a3, 0x10
/* FE244 802D9894 AFA7002C */  sw        $a3, 0x2c($sp)
/* FE248 802D9898 8FA70030 */  lw        $a3, 0x30($sp)
/* FE24C 802D989C 26310001 */  addiu     $s1, $s1, 1
/* FE250 802D98A0 00F03821 */  addu      $a3, $a3, $s0
/* FE254 802D98A4 AFA70024 */  sw        $a3, 0x24($sp)
/* FE258 802D98A8 8FA70030 */  lw        $a3, 0x30($sp)
/* FE25C 802D98AC 3C058015 */  lui       $a1, %hi(D_80151328)
/* FE260 802D98B0 8CA51328 */  lw        $a1, %lo(D_80151328)($a1)
/* FE264 802D98B4 24E70010 */  addiu     $a3, $a3, 0x10
/* FE268 802D98B8 AFA70030 */  sw        $a3, 0x30($sp)
/* FE26C 802D98BC 01703821 */  addu      $a3, $t3, $s0
/* FE270 802D98C0 AFA70020 */  sw        $a3, 0x20($sp)
/* FE274 802D98C4 01903821 */  addu      $a3, $t4, $s0
/* FE278 802D98C8 AFA7001C */  sw        $a3, 0x1c($sp)
/* FE27C 802D98CC 01B03821 */  addu      $a3, $t5, $s0
/* FE280 802D98D0 AFA70018 */  sw        $a3, 0x18($sp)
/* FE284 802D98D4 90420000 */  lbu       $v0, ($v0)
/* FE288 802D98D8 00B22821 */  addu      $a1, $a1, $s2
/* FE28C 802D98DC A0A20000 */  sb        $v0, ($a1)
/* FE290 802D98E0 03301021 */  addu      $v0, $t9, $s0
/* FE294 802D98E4 90420000 */  lbu       $v0, ($v0)
/* FE298 802D98E8 26520018 */  addiu     $s2, $s2, 0x18
/* FE29C 802D98EC A0A20001 */  sb        $v0, 1($a1)
/* FE2A0 802D98F0 02701021 */  addu      $v0, $s3, $s0
/* FE2A4 802D98F4 90420000 */  lbu       $v0, ($v0)
/* FE2A8 802D98F8 256B0010 */  addiu     $t3, $t3, 0x10
/* FE2AC 802D98FC A0A20002 */  sb        $v0, 2($a1)
/* FE2B0 802D9900 90620000 */  lbu       $v0, ($v1)
/* FE2B4 802D9904 02F03821 */  addu      $a3, $s7, $s0
/* FE2B8 802D9908 A0A20003 */  sb        $v0, 3($a1)
/* FE2BC 802D990C 90830000 */  lbu       $v1, ($a0)
/* FE2C0 802D9910 90C20000 */  lbu       $v0, ($a2)
/* FE2C4 802D9914 00031A00 */  sll       $v1, $v1, 8
/* FE2C8 802D9918 00431021 */  addu      $v0, $v0, $v1
/* FE2CC 802D991C 00021400 */  sll       $v0, $v0, 0x10
/* FE2D0 802D9920 00021403 */  sra       $v0, $v0, 0x10
/* FE2D4 802D9924 44820000 */  mtc1      $v0, $f0
/* FE2D8 802D9928 00000000 */  nop       
/* FE2DC 802D992C 46800020 */  cvt.s.w   $f0, $f0
/* FE2E0 802D9930 E4A00004 */  swc1      $f0, 4($a1)
/* FE2E4 802D9934 90E30000 */  lbu       $v1, ($a3)
/* FE2E8 802D9938 91020000 */  lbu       $v0, ($t0)
/* FE2EC 802D993C 00031A00 */  sll       $v1, $v1, 8
/* FE2F0 802D9940 00431021 */  addu      $v0, $v0, $v1
/* FE2F4 802D9944 00021400 */  sll       $v0, $v0, 0x10
/* FE2F8 802D9948 00021403 */  sra       $v0, $v0, 0x10
/* FE2FC 802D994C 44820000 */  mtc1      $v0, $f0
/* FE300 802D9950 00000000 */  nop       
/* FE304 802D9954 46800020 */  cvt.s.w   $f0, $f0
/* FE308 802D9958 E4A00008 */  swc1      $f0, 8($a1)
/* FE30C 802D995C 91230000 */  lbu       $v1, ($t1)
/* FE310 802D9960 91420000 */  lbu       $v0, ($t2)
/* FE314 802D9964 00031A00 */  sll       $v1, $v1, 8
/* FE318 802D9968 00431021 */  addu      $v0, $v0, $v1
/* FE31C 802D996C 00021400 */  sll       $v0, $v0, 0x10
/* FE320 802D9970 00021403 */  sra       $v0, $v0, 0x10
/* FE324 802D9974 44820000 */  mtc1      $v0, $f0
/* FE328 802D9978 00000000 */  nop       
/* FE32C 802D997C 46800020 */  cvt.s.w   $f0, $f0
/* FE330 802D9980 E4A0000C */  swc1      $f0, 0xc($a1)
/* FE334 802D9984 8FA7001C */  lw        $a3, 0x1c($sp)
/* FE338 802D9988 258C0010 */  addiu     $t4, $t4, 0x10
/* FE33C 802D998C 90E30000 */  lbu       $v1, ($a3)
/* FE340 802D9990 8FA70018 */  lw        $a3, 0x18($sp)
/* FE344 802D9994 00031A00 */  sll       $v1, $v1, 8
/* FE348 802D9998 90E20000 */  lbu       $v0, ($a3)
/* FE34C 802D999C 8FA70020 */  lw        $a3, 0x20($sp)
/* FE350 802D99A0 00431021 */  addu      $v0, $v0, $v1
/* FE354 802D99A4 90E40000 */  lbu       $a0, ($a3)
/* FE358 802D99A8 8FA70024 */  lw        $a3, 0x24($sp)
/* FE35C 802D99AC 00042400 */  sll       $a0, $a0, 0x10
/* FE360 802D99B0 90E30000 */  lbu       $v1, ($a3)
/* FE364 802D99B4 00441021 */  addu      $v0, $v0, $a0
/* FE368 802D99B8 00031E00 */  sll       $v1, $v1, 0x18
/* FE36C 802D99BC 00431021 */  addu      $v0, $v0, $v1
/* FE370 802D99C0 AFA20010 */  sw        $v0, 0x10($sp)
/* FE374 802D99C4 C7A00010 */  lwc1      $f0, 0x10($sp)
/* FE378 802D99C8 25AD0010 */  addiu     $t5, $t5, 0x10
/* FE37C 802D99CC E4A00010 */  swc1      $f0, 0x10($a1)
/* FE380 802D99D0 8FA70028 */  lw        $a3, 0x28($sp)
/* FE384 802D99D4 26F70010 */  addiu     $s7, $s7, 0x10
/* FE388 802D99D8 90E20000 */  lbu       $v0, ($a3)
/* FE38C 802D99DC 27390010 */  addiu     $t9, $t9, 0x10
/* FE390 802D99E0 A0A20014 */  sb        $v0, 0x14($a1)
/* FE394 802D99E4 8FA70014 */  lw        $a3, 0x14($sp)
/* FE398 802D99E8 0227102A */  slt       $v0, $s1, $a3
/* FE39C 802D99EC 1440FF96 */  bnez      $v0, .L802D9848
/* FE3A0 802D99F0 26730010 */   addiu    $s3, $s3, 0x10
.L802D99F4:
/* FE3A4 802D99F4 3C048015 */  lui       $a0, %hi(D_80151328)
/* FE3A8 802D99F8 8C841328 */  lw        $a0, %lo(D_80151328)($a0)
/* FE3AC 802D99FC 94830000 */  lhu       $v1, ($a0)
/* FE3B0 802D9A00 24020002 */  addiu     $v0, $zero, 2
/* FE3B4 802D9A04 34630001 */  ori       $v1, $v1, 1
/* FE3B8 802D9A08 A4830000 */  sh        $v1, ($a0)
.L802D9A0C:
/* FE3BC 802D9A0C 8FBF0064 */  lw        $ra, 0x64($sp)
/* FE3C0 802D9A10 8FBE0060 */  lw        $fp, 0x60($sp)
/* FE3C4 802D9A14 8FB7005C */  lw        $s7, 0x5c($sp)
/* FE3C8 802D9A18 8FB60058 */  lw        $s6, 0x58($sp)
/* FE3CC 802D9A1C 8FB50054 */  lw        $s5, 0x54($sp)
/* FE3D0 802D9A20 8FB40050 */  lw        $s4, 0x50($sp)
/* FE3D4 802D9A24 8FB3004C */  lw        $s3, 0x4c($sp)
/* FE3D8 802D9A28 8FB20048 */  lw        $s2, 0x48($sp)
/* FE3DC 802D9A2C 8FB10044 */  lw        $s1, 0x44($sp)
/* FE3E0 802D9A30 8FB00040 */  lw        $s0, 0x40($sp)
/* FE3E4 802D9A34 03E00008 */  jr        $ra
/* FE3E8 802D9A38 27BD0068 */   addiu    $sp, $sp, 0x68
