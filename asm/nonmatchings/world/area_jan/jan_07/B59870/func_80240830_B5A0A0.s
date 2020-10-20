.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240830_B5A0A0
/* B5A0A0 80240830 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* B5A0A4 80240834 AFB20038 */  sw        $s2, 0x38($sp)
/* B5A0A8 80240838 0080902D */  daddu     $s2, $a0, $zero
/* B5A0AC 8024083C AFBF0048 */  sw        $ra, 0x48($sp)
/* B5A0B0 80240840 AFB50044 */  sw        $s5, 0x44($sp)
/* B5A0B4 80240844 AFB40040 */  sw        $s4, 0x40($sp)
/* B5A0B8 80240848 AFB3003C */  sw        $s3, 0x3c($sp)
/* B5A0BC 8024084C AFB10034 */  sw        $s1, 0x34($sp)
/* B5A0C0 80240850 AFB00030 */  sw        $s0, 0x30($sp)
/* B5A0C4 80240854 8E510148 */  lw        $s1, 0x148($s2)
/* B5A0C8 80240858 86240008 */  lh        $a0, 8($s1)
/* B5A0CC 8024085C 0C00EABB */  jal       get_npc_unsafe
/* B5A0D0 80240860 00A0802D */   daddu    $s0, $a1, $zero
/* B5A0D4 80240864 8E43000C */  lw        $v1, 0xc($s2)
/* B5A0D8 80240868 0240202D */  daddu     $a0, $s2, $zero
/* B5A0DC 8024086C 8C650000 */  lw        $a1, ($v1)
/* B5A0E0 80240870 0C0B1EAF */  jal       get_variable
/* B5A0E4 80240874 0040A82D */   daddu    $s5, $v0, $zero
/* B5A0E8 80240878 AFA00010 */  sw        $zero, 0x10($sp)
/* B5A0EC 8024087C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B5A0F0 80240880 8C630030 */  lw        $v1, 0x30($v1)
/* B5A0F4 80240884 AFA30014 */  sw        $v1, 0x14($sp)
/* B5A0F8 80240888 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B5A0FC 8024088C 8C63001C */  lw        $v1, 0x1c($v1)
/* B5A100 80240890 AFA30018 */  sw        $v1, 0x18($sp)
/* B5A104 80240894 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B5A108 80240898 8C630024 */  lw        $v1, 0x24($v1)
/* B5A10C 8024089C AFA3001C */  sw        $v1, 0x1c($sp)
/* B5A110 802408A0 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B5A114 802408A4 8C630028 */  lw        $v1, 0x28($v1)
/* B5A118 802408A8 27B40010 */  addiu     $s4, $sp, 0x10
/* B5A11C 802408AC AFA30020 */  sw        $v1, 0x20($sp)
/* B5A120 802408B0 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B5A124 802408B4 3C014282 */  lui       $at, 0x4282
/* B5A128 802408B8 44810000 */  mtc1      $at, $f0
/* B5A12C 802408BC 8C63002C */  lw        $v1, 0x2c($v1)
/* B5A130 802408C0 0040982D */  daddu     $s3, $v0, $zero
/* B5A134 802408C4 E7A00028 */  swc1      $f0, 0x28($sp)
/* B5A138 802408C8 A7A0002C */  sh        $zero, 0x2c($sp)
/* B5A13C 802408CC 16000005 */  bnez      $s0, .L802408E4
/* B5A140 802408D0 AFA30024 */   sw       $v1, 0x24($sp)
/* B5A144 802408D4 8E2200B0 */  lw        $v0, 0xb0($s1)
/* B5A148 802408D8 30420004 */  andi      $v0, $v0, 4
/* B5A14C 802408DC 10400020 */  beqz      $v0, .L80240960
/* B5A150 802408E0 00000000 */   nop      
.L802408E4:
/* B5A154 802408E4 2404F7FF */  addiu     $a0, $zero, -0x801
/* B5A158 802408E8 AE400070 */  sw        $zero, 0x70($s2)
/* B5A15C 802408EC A6A0008E */  sh        $zero, 0x8e($s5)
/* B5A160 802408F0 8E2200CC */  lw        $v0, 0xcc($s1)
/* B5A164 802408F4 8EA30000 */  lw        $v1, ($s5)
/* B5A168 802408F8 8C420000 */  lw        $v0, ($v0)
/* B5A16C 802408FC 00641824 */  and       $v1, $v1, $a0
/* B5A170 80240900 AEA30000 */  sw        $v1, ($s5)
/* B5A174 80240904 AEA20028 */  sw        $v0, 0x28($s5)
/* B5A178 80240908 8E2200D0 */  lw        $v0, 0xd0($s1)
/* B5A17C 8024090C 8C420034 */  lw        $v0, 0x34($v0)
/* B5A180 80240910 54400005 */  bnel      $v0, $zero, .L80240928
/* B5A184 80240914 2402FDFF */   addiu    $v0, $zero, -0x201
/* B5A188 80240918 34620200 */  ori       $v0, $v1, 0x200
/* B5A18C 8024091C 2403FFF7 */  addiu     $v1, $zero, -9
/* B5A190 80240920 0809024C */  j         .L80240930
/* B5A194 80240924 00431024 */   and      $v0, $v0, $v1
.L80240928:
/* B5A198 80240928 00621024 */  and       $v0, $v1, $v0
/* B5A19C 8024092C 34420008 */  ori       $v0, $v0, 8
.L80240930:
/* B5A1A0 80240930 AEA20000 */  sw        $v0, ($s5)
/* B5A1A4 80240934 8E2200B0 */  lw        $v0, 0xb0($s1)
/* B5A1A8 80240938 30420004 */  andi      $v0, $v0, 4
/* B5A1AC 8024093C 10400007 */  beqz      $v0, .L8024095C
/* B5A1B0 80240940 24020063 */   addiu    $v0, $zero, 0x63
/* B5A1B4 80240944 AE420070 */  sw        $v0, 0x70($s2)
/* B5A1B8 80240948 AE400074 */  sw        $zero, 0x74($s2)
/* B5A1BC 8024094C 8E2200B0 */  lw        $v0, 0xb0($s1)
/* B5A1C0 80240950 2403FFFB */  addiu     $v1, $zero, -5
/* B5A1C4 80240954 00431024 */  and       $v0, $v0, $v1
/* B5A1C8 80240958 AE2200B0 */  sw        $v0, 0xb0($s1)
.L8024095C:
/* B5A1CC 8024095C AE20006C */  sw        $zero, 0x6c($s1)
.L80240960:
/* B5A1D0 80240960 8E420070 */  lw        $v0, 0x70($s2)
/* B5A1D4 80240964 2842001E */  slti      $v0, $v0, 0x1e
/* B5A1D8 80240968 10400009 */  beqz      $v0, .L80240990
/* B5A1DC 8024096C 00000000 */   nop      
/* B5A1E0 80240970 8E22006C */  lw        $v0, 0x6c($s1)
/* B5A1E4 80240974 14400006 */  bnez      $v0, .L80240990
/* B5A1E8 80240978 00000000 */   nop      
/* B5A1EC 8024097C 0C090107 */  jal       func_8024041C
/* B5A1F0 80240980 0240202D */   daddu    $a0, $s2, $zero
/* B5A1F4 80240984 10400002 */  beqz      $v0, .L80240990
/* B5A1F8 80240988 2402001E */   addiu    $v0, $zero, 0x1e
/* B5A1FC 8024098C AE420070 */  sw        $v0, 0x70($s2)
.L80240990:
/* B5A200 80240990 8E430070 */  lw        $v1, 0x70($s2)
/* B5A204 80240994 2C620064 */  sltiu     $v0, $v1, 0x64
/* B5A208 80240998 10400048 */  beqz      $v0, .L80240ABC
/* B5A20C 8024099C 00031080 */   sll      $v0, $v1, 2
/* B5A210 802409A0 3C018024 */  lui       $at, 0x8024
/* B5A214 802409A4 00220821 */  addu      $at, $at, $v0
/* B5A218 802409A8 8C224720 */  lw        $v0, 0x4720($at)
/* B5A21C 802409AC 00400008 */  jr        $v0
/* B5A220 802409B0 00000000 */   nop      
/* B5A224 802409B4 0240202D */  daddu     $a0, $s2, $zero
/* B5A228 802409B8 0260282D */  daddu     $a1, $s3, $zero
/* B5A22C 802409BC 0C012568 */  jal       func_800495A0
/* B5A230 802409C0 0280302D */   daddu    $a2, $s4, $zero
/* B5A234 802409C4 0240202D */  daddu     $a0, $s2, $zero
/* B5A238 802409C8 0260282D */  daddu     $a1, $s3, $zero
/* B5A23C 802409CC 0C0125AE */  jal       func_800496B8
/* B5A240 802409D0 0280302D */   daddu    $a2, $s4, $zero
/* B5A244 802409D4 080902AF */  j         .L80240ABC
/* B5A248 802409D8 00000000 */   nop      
/* B5A24C 802409DC 0240202D */  daddu     $a0, $s2, $zero
/* B5A250 802409E0 0260282D */  daddu     $a1, $s3, $zero
/* B5A254 802409E4 0C0126D1 */  jal       func_80049B44
/* B5A258 802409E8 0280302D */   daddu    $a2, $s4, $zero
/* B5A25C 802409EC 0240202D */  daddu     $a0, $s2, $zero
/* B5A260 802409F0 0260282D */  daddu     $a1, $s3, $zero
/* B5A264 802409F4 0C012701 */  jal       func_80049C04
/* B5A268 802409F8 0280302D */   daddu    $a2, $s4, $zero
/* B5A26C 802409FC 080902AF */  j         .L80240ABC
/* B5A270 80240A00 00000000 */   nop      
/* B5A274 80240A04 0240202D */  daddu     $a0, $s2, $zero
/* B5A278 80240A08 0260282D */  daddu     $a1, $s3, $zero
/* B5A27C 80240A0C 0C01278F */  jal       func_80049E3C
/* B5A280 80240A10 0280302D */   daddu    $a2, $s4, $zero
/* B5A284 80240A14 0240202D */  daddu     $a0, $s2, $zero
/* B5A288 80240A18 0260282D */  daddu     $a1, $s3, $zero
/* B5A28C 80240A1C 0C0127B3 */  jal       func_80049ECC
/* B5A290 80240A20 0280302D */   daddu    $a2, $s4, $zero
/* B5A294 80240A24 080902AF */  j         .L80240ABC
/* B5A298 80240A28 00000000 */   nop      
/* B5A29C 80240A2C 0240202D */  daddu     $a0, $s2, $zero
/* B5A2A0 80240A30 0260282D */  daddu     $a1, $s3, $zero
/* B5A2A4 80240A34 0C0127DF */  jal       func_80049F7C
/* B5A2A8 80240A38 0280302D */   daddu    $a2, $s4, $zero
/* B5A2AC 80240A3C 0240202D */  daddu     $a0, $s2, $zero
/* B5A2B0 80240A40 0260282D */  daddu     $a1, $s3, $zero
/* B5A2B4 80240A44 0C012849 */  jal       func_8004A124
/* B5A2B8 80240A48 0280302D */   daddu    $a2, $s4, $zero
/* B5A2BC 80240A4C 080902AF */  j         .L80240ABC
/* B5A2C0 80240A50 00000000 */   nop      
/* B5A2C4 80240A54 0240202D */  daddu     $a0, $s2, $zero
/* B5A2C8 80240A58 0260282D */  daddu     $a1, $s3, $zero
/* B5A2CC 80240A5C 0C0128FA */  jal       func_8004A3E8
/* B5A2D0 80240A60 0280302D */   daddu    $a2, $s4, $zero
/* B5A2D4 80240A64 080902AF */  j         .L80240ABC
/* B5A2D8 80240A68 00000000 */   nop      
/* B5A2DC 80240A6C 0C090085 */  jal       func_80240214
/* B5A2E0 80240A70 0240202D */   daddu    $a0, $s2, $zero
/* B5A2E4 80240A74 0C0900A0 */  jal       func_80240280
/* B5A2E8 80240A78 0240202D */   daddu    $a0, $s2, $zero
/* B5A2EC 80240A7C 8E430070 */  lw        $v1, 0x70($s2)
/* B5A2F0 80240A80 24020020 */  addiu     $v0, $zero, 0x20
/* B5A2F4 80240A84 1462000D */  bne       $v1, $v0, .L80240ABC
/* B5A2F8 80240A88 00000000 */   nop      
/* B5A2FC 80240A8C 0C0900BC */  jal       func_802402F0
/* B5A300 80240A90 0240202D */   daddu    $a0, $s2, $zero
/* B5A304 80240A94 8E430070 */  lw        $v1, 0x70($s2)
/* B5A308 80240A98 24020021 */  addiu     $v0, $zero, 0x21
/* B5A30C 80240A9C 14620007 */  bne       $v1, $v0, .L80240ABC
/* B5A310 80240AA0 00000000 */   nop      
/* B5A314 80240AA4 0C0900F2 */  jal       func_802403C8
/* B5A318 80240AA8 0240202D */   daddu    $a0, $s2, $zero
/* B5A31C 80240AAC 080902AF */  j         .L80240ABC
/* B5A320 80240AB0 00000000 */   nop      
/* B5A324 80240AB4 0C0129CF */  jal       func_8004A73C
/* B5A328 80240AB8 0240202D */   daddu    $a0, $s2, $zero
.L80240ABC:
/* B5A32C 80240ABC 8FBF0048 */  lw        $ra, 0x48($sp)
/* B5A330 80240AC0 8FB50044 */  lw        $s5, 0x44($sp)
/* B5A334 80240AC4 8FB40040 */  lw        $s4, 0x40($sp)
/* B5A338 80240AC8 8FB3003C */  lw        $s3, 0x3c($sp)
/* B5A33C 80240ACC 8FB20038 */  lw        $s2, 0x38($sp)
/* B5A340 80240AD0 8FB10034 */  lw        $s1, 0x34($sp)
/* B5A344 80240AD4 8FB00030 */  lw        $s0, 0x30($sp)
/* B5A348 80240AD8 0000102D */  daddu     $v0, $zero, $zero
/* B5A34C 80240ADC 03E00008 */  jr        $ra
/* B5A350 80240AE0 27BD0050 */   addiu    $sp, $sp, 0x50
