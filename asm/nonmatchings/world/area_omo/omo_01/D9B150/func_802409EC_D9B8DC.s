.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802409EC_D9B8DC
/* D9B8DC 802409EC 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* D9B8E0 802409F0 AFB40040 */  sw        $s4, 0x40($sp)
/* D9B8E4 802409F4 0080A02D */  daddu     $s4, $a0, $zero
/* D9B8E8 802409F8 AFBF0048 */  sw        $ra, 0x48($sp)
/* D9B8EC 802409FC AFB50044 */  sw        $s5, 0x44($sp)
/* D9B8F0 80240A00 AFB3003C */  sw        $s3, 0x3c($sp)
/* D9B8F4 80240A04 AFB20038 */  sw        $s2, 0x38($sp)
/* D9B8F8 80240A08 AFB10034 */  sw        $s1, 0x34($sp)
/* D9B8FC 80240A0C AFB00030 */  sw        $s0, 0x30($sp)
/* D9B900 80240A10 8E910148 */  lw        $s1, 0x148($s4)
/* D9B904 80240A14 86240008 */  lh        $a0, 8($s1)
/* D9B908 80240A18 0C00EABB */  jal       get_npc_unsafe
/* D9B90C 80240A1C 00A0802D */   daddu    $s0, $a1, $zero
/* D9B910 80240A20 8E83000C */  lw        $v1, 0xc($s4)
/* D9B914 80240A24 0280202D */  daddu     $a0, $s4, $zero
/* D9B918 80240A28 8C650000 */  lw        $a1, ($v1)
/* D9B91C 80240A2C 0C0B1EAF */  jal       get_variable
/* D9B920 80240A30 0040A82D */   daddu    $s5, $v0, $zero
/* D9B924 80240A34 AFA00010 */  sw        $zero, 0x10($sp)
/* D9B928 80240A38 8E2300D0 */  lw        $v1, 0xd0($s1)
/* D9B92C 80240A3C 8C630030 */  lw        $v1, 0x30($v1)
/* D9B930 80240A40 AFA30014 */  sw        $v1, 0x14($sp)
/* D9B934 80240A44 8E2300D0 */  lw        $v1, 0xd0($s1)
/* D9B938 80240A48 8C63001C */  lw        $v1, 0x1c($v1)
/* D9B93C 80240A4C AFA30018 */  sw        $v1, 0x18($sp)
/* D9B940 80240A50 8E2300D0 */  lw        $v1, 0xd0($s1)
/* D9B944 80240A54 8C630024 */  lw        $v1, 0x24($v1)
/* D9B948 80240A58 AFA3001C */  sw        $v1, 0x1c($sp)
/* D9B94C 80240A5C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* D9B950 80240A60 8C630028 */  lw        $v1, 0x28($v1)
/* D9B954 80240A64 27B30010 */  addiu     $s3, $sp, 0x10
/* D9B958 80240A68 AFA30020 */  sw        $v1, 0x20($sp)
/* D9B95C 80240A6C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* D9B960 80240A70 3C0142C8 */  lui       $at, 0x42c8
/* D9B964 80240A74 44810000 */  mtc1      $at, $f0
/* D9B968 80240A78 8C63002C */  lw        $v1, 0x2c($v1)
/* D9B96C 80240A7C 0040902D */  daddu     $s2, $v0, $zero
/* D9B970 80240A80 E7A00028 */  swc1      $f0, 0x28($sp)
/* D9B974 80240A84 A7A0002C */  sh        $zero, 0x2c($sp)
/* D9B978 80240A88 16000005 */  bnez      $s0, .L80240AA0
/* D9B97C 80240A8C AFA30024 */   sw       $v1, 0x24($sp)
/* D9B980 80240A90 8E2200B0 */  lw        $v0, 0xb0($s1)
/* D9B984 80240A94 30420004 */  andi      $v0, $v0, 4
/* D9B988 80240A98 1040001F */  beqz      $v0, .L80240B18
/* D9B98C 80240A9C 00000000 */   nop      
.L80240AA0:
/* D9B990 80240AA0 2404F7FF */  addiu     $a0, $zero, -0x801
/* D9B994 80240AA4 AE800070 */  sw        $zero, 0x70($s4)
/* D9B998 80240AA8 A6A0008E */  sh        $zero, 0x8e($s5)
/* D9B99C 80240AAC 8E2200CC */  lw        $v0, 0xcc($s1)
/* D9B9A0 80240AB0 8EA30000 */  lw        $v1, ($s5)
/* D9B9A4 80240AB4 8C420000 */  lw        $v0, ($v0)
/* D9B9A8 80240AB8 00641824 */  and       $v1, $v1, $a0
/* D9B9AC 80240ABC AEA30000 */  sw        $v1, ($s5)
/* D9B9B0 80240AC0 AEA20028 */  sw        $v0, 0x28($s5)
/* D9B9B4 80240AC4 8E2200D0 */  lw        $v0, 0xd0($s1)
/* D9B9B8 80240AC8 8C420034 */  lw        $v0, 0x34($v0)
/* D9B9BC 80240ACC 54400005 */  bnel      $v0, $zero, .L80240AE4
/* D9B9C0 80240AD0 2402FDFF */   addiu    $v0, $zero, -0x201
/* D9B9C4 80240AD4 34620200 */  ori       $v0, $v1, 0x200
/* D9B9C8 80240AD8 2403FFF7 */  addiu     $v1, $zero, -9
/* D9B9CC 80240ADC 080902BB */  j         .L80240AEC
/* D9B9D0 80240AE0 00431024 */   and      $v0, $v0, $v1
.L80240AE4:
/* D9B9D4 80240AE4 00621024 */  and       $v0, $v1, $v0
/* D9B9D8 80240AE8 34420008 */  ori       $v0, $v0, 8
.L80240AEC:
/* D9B9DC 80240AEC AEA20000 */  sw        $v0, ($s5)
/* D9B9E0 80240AF0 8E2200B0 */  lw        $v0, 0xb0($s1)
/* D9B9E4 80240AF4 30420004 */  andi      $v0, $v0, 4
/* D9B9E8 80240AF8 10400007 */  beqz      $v0, .L80240B18
/* D9B9EC 80240AFC 24020063 */   addiu    $v0, $zero, 0x63
/* D9B9F0 80240B00 AE820070 */  sw        $v0, 0x70($s4)
/* D9B9F4 80240B04 AE800074 */  sw        $zero, 0x74($s4)
/* D9B9F8 80240B08 8E2200B0 */  lw        $v0, 0xb0($s1)
/* D9B9FC 80240B0C 2403FFFB */  addiu     $v1, $zero, -5
/* D9BA00 80240B10 00431024 */  and       $v0, $v0, $v1
/* D9BA04 80240B14 AE2200B0 */  sw        $v0, 0xb0($s1)
.L80240B18:
/* D9BA08 80240B18 8E830070 */  lw        $v1, 0x70($s4)
/* D9BA0C 80240B1C 2C620064 */  sltiu     $v0, $v1, 0x64
/* D9BA10 80240B20 10400036 */  beqz      $v0, .L80240BFC
/* D9BA14 80240B24 00031080 */   sll      $v0, $v1, 2
/* D9BA18 80240B28 3C018024 */  lui       $at, %hi(func_80242448_CC5C58)
/* D9BA1C 80240B2C 00220821 */  addu      $at, $at, $v0
/* D9BA20 80240B30 8C222448 */  lw        $v0, %lo(func_80242448_CC5C58)($at)
/* D9BA24 80240B34 00400008 */  jr        $v0
/* D9BA28 80240B38 00000000 */   nop      
/* D9BA2C 80240B3C 0280202D */  daddu     $a0, $s4, $zero
/* D9BA30 80240B40 0240282D */  daddu     $a1, $s2, $zero
/* D9BA34 80240B44 0C012568 */  jal       func_800495A0
/* D9BA38 80240B48 0260302D */   daddu    $a2, $s3, $zero
/* D9BA3C 80240B4C 0280202D */  daddu     $a0, $s4, $zero
/* D9BA40 80240B50 0240282D */  daddu     $a1, $s2, $zero
/* D9BA44 80240B54 0C0125AE */  jal       func_800496B8
/* D9BA48 80240B58 0260302D */   daddu    $a2, $s3, $zero
/* D9BA4C 80240B5C 080902FF */  j         .L80240BFC
/* D9BA50 80240B60 00000000 */   nop      
/* D9BA54 80240B64 0280202D */  daddu     $a0, $s4, $zero
/* D9BA58 80240B68 0240282D */  daddu     $a1, $s2, $zero
/* D9BA5C 80240B6C 0C0126D1 */  jal       func_80049B44
/* D9BA60 80240B70 0260302D */   daddu    $a2, $s3, $zero
/* D9BA64 80240B74 0280202D */  daddu     $a0, $s4, $zero
/* D9BA68 80240B78 0240282D */  daddu     $a1, $s2, $zero
/* D9BA6C 80240B7C 0C012701 */  jal       func_80049C04
/* D9BA70 80240B80 0260302D */   daddu    $a2, $s3, $zero
/* D9BA74 80240B84 080902FF */  j         .L80240BFC
/* D9BA78 80240B88 00000000 */   nop      
/* D9BA7C 80240B8C 0280202D */  daddu     $a0, $s4, $zero
/* D9BA80 80240B90 0240282D */  daddu     $a1, $s2, $zero
/* D9BA84 80240B94 0C01278F */  jal       func_80049E3C
/* D9BA88 80240B98 0260302D */   daddu    $a2, $s3, $zero
/* D9BA8C 80240B9C 0280202D */  daddu     $a0, $s4, $zero
/* D9BA90 80240BA0 0240282D */  daddu     $a1, $s2, $zero
/* D9BA94 80240BA4 0C0127B3 */  jal       func_80049ECC
/* D9BA98 80240BA8 0260302D */   daddu    $a2, $s3, $zero
/* D9BA9C 80240BAC 080902FF */  j         .L80240BFC
/* D9BAA0 80240BB0 00000000 */   nop      
/* D9BAA4 80240BB4 0280202D */  daddu     $a0, $s4, $zero
/* D9BAA8 80240BB8 0240282D */  daddu     $a1, $s2, $zero
/* D9BAAC 80240BBC 0C090098 */  jal       func_80240260_D9B150
/* D9BAB0 80240BC0 0260302D */   daddu    $a2, $s3, $zero
/* D9BAB4 80240BC4 0280202D */  daddu     $a0, $s4, $zero
/* D9BAB8 80240BC8 0240282D */  daddu     $a1, $s2, $zero
/* D9BABC 80240BCC 0C090211 */  jal       func_80240844_D9B734
/* D9BAC0 80240BD0 0260302D */   daddu    $a2, $s3, $zero
/* D9BAC4 80240BD4 080902FF */  j         .L80240BFC
/* D9BAC8 80240BD8 00000000 */   nop      
/* D9BACC 80240BDC 0280202D */  daddu     $a0, $s4, $zero
/* D9BAD0 80240BE0 0240282D */  daddu     $a1, $s2, $zero
/* D9BAD4 80240BE4 0C09026A */  jal       func_802409A8_D9B898
/* D9BAD8 80240BE8 0260302D */   daddu    $a2, $s3, $zero
/* D9BADC 80240BEC 080902FF */  j         .L80240BFC
/* D9BAE0 80240BF0 00000000 */   nop      
/* D9BAE4 80240BF4 0C0129CF */  jal       func_8004A73C
/* D9BAE8 80240BF8 0280202D */   daddu    $a0, $s4, $zero
.L80240BFC:
/* D9BAEC 80240BFC 8FBF0048 */  lw        $ra, 0x48($sp)
/* D9BAF0 80240C00 8FB50044 */  lw        $s5, 0x44($sp)
/* D9BAF4 80240C04 8FB40040 */  lw        $s4, 0x40($sp)
/* D9BAF8 80240C08 8FB3003C */  lw        $s3, 0x3c($sp)
/* D9BAFC 80240C0C 8FB20038 */  lw        $s2, 0x38($sp)
/* D9BB00 80240C10 8FB10034 */  lw        $s1, 0x34($sp)
/* D9BB04 80240C14 8FB00030 */  lw        $s0, 0x30($sp)
/* D9BB08 80240C18 0000102D */  daddu     $v0, $zero, $zero
/* D9BB0C 80240C1C 03E00008 */  jr        $ra
/* D9BB10 80240C20 27BD0050 */   addiu    $sp, $sp, 0x50
/* D9BB14 80240C24 00000000 */  nop       
/* D9BB18 80240C28 00000000 */  nop       
/* D9BB1C 80240C2C 00000000 */  nop       
