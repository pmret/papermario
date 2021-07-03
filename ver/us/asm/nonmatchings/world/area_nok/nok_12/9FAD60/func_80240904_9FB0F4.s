.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_80245A78_A00268
.word L80240D10_9FB500, L80240D1C_9FB50C, L80240D1C_9FB50C, L80240D1C_9FB50C, L80240D1C_9FB50C, L80240D1C_9FB50C, L80240D1C_9FB50C, L80240D1C_9FB50C, L80240D10_9FB500, L80240D1C_9FB50C, L80240D10_9FB500, L80240D1C_9FB50C, L80240D10_9FB500, L80240D1C_9FB50C, L80240D10_9FB500, L80240D1C_9FB50C, L80240D1C_9FB50C, L80240D1C_9FB50C, L80240D10_9FB500, L80240D1C_9FB50C, L80240D10_9FB500, 0

.section .text

glabel func_80240904_9FB0F4
/* 9FB0F4 80240904 27BDFF90 */  addiu     $sp, $sp, -0x70
/* 9FB0F8 80240908 AFB3005C */  sw        $s3, 0x5c($sp)
/* 9FB0FC 8024090C 0080982D */  daddu     $s3, $a0, $zero
/* 9FB100 80240910 AFBF0068 */  sw        $ra, 0x68($sp)
/* 9FB104 80240914 AFB50064 */  sw        $s5, 0x64($sp)
/* 9FB108 80240918 AFB40060 */  sw        $s4, 0x60($sp)
/* 9FB10C 8024091C AFB20058 */  sw        $s2, 0x58($sp)
/* 9FB110 80240920 AFB10054 */  sw        $s1, 0x54($sp)
/* 9FB114 80240924 AFB00050 */  sw        $s0, 0x50($sp)
/* 9FB118 80240928 8E710148 */  lw        $s1, 0x148($s3)
/* 9FB11C 8024092C 86240008 */  lh        $a0, 8($s1)
/* 9FB120 80240930 0C00EABB */  jal       get_npc_unsafe
/* 9FB124 80240934 00A0802D */   daddu    $s0, $a1, $zero
/* 9FB128 80240938 8E63000C */  lw        $v1, 0xc($s3)
/* 9FB12C 8024093C 0260202D */  daddu     $a0, $s3, $zero
/* 9FB130 80240940 8C650000 */  lw        $a1, ($v1)
/* 9FB134 80240944 0C0B1EAF */  jal       get_variable
/* 9FB138 80240948 0040902D */   daddu    $s2, $v0, $zero
/* 9FB13C 8024094C AFA00028 */  sw        $zero, 0x28($sp)
/* 9FB140 80240950 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 9FB144 80240954 8C630030 */  lw        $v1, 0x30($v1)
/* 9FB148 80240958 AFA3002C */  sw        $v1, 0x2c($sp)
/* 9FB14C 8024095C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 9FB150 80240960 8C63001C */  lw        $v1, 0x1c($v1)
/* 9FB154 80240964 AFA30030 */  sw        $v1, 0x30($sp)
/* 9FB158 80240968 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 9FB15C 8024096C 8C630024 */  lw        $v1, 0x24($v1)
/* 9FB160 80240970 AFA30034 */  sw        $v1, 0x34($sp)
/* 9FB164 80240974 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 9FB168 80240978 8C630028 */  lw        $v1, 0x28($v1)
/* 9FB16C 8024097C 27B50028 */  addiu     $s5, $sp, 0x28
/* 9FB170 80240980 AFA30038 */  sw        $v1, 0x38($sp)
/* 9FB174 80240984 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 9FB178 80240988 3C0142C8 */  lui       $at, 0x42c8
/* 9FB17C 8024098C 44810000 */  mtc1      $at, $f0
/* 9FB180 80240990 8C63002C */  lw        $v1, 0x2c($v1)
/* 9FB184 80240994 0040A02D */  daddu     $s4, $v0, $zero
/* 9FB188 80240998 E7A00040 */  swc1      $f0, 0x40($sp)
/* 9FB18C 8024099C A7A00044 */  sh        $zero, 0x44($sp)
/* 9FB190 802409A0 12000009 */  beqz      $s0, .L802409C8
/* 9FB194 802409A4 AFA3003C */   sw       $v1, 0x3c($sp)
/* 9FB198 802409A8 864300A8 */  lh        $v1, 0xa8($s2)
/* 9FB19C 802409AC 8E2200B0 */  lw        $v0, 0xb0($s1)
/* 9FB1A0 802409B0 AE20008C */  sw        $zero, 0x8c($s1)
/* 9FB1A4 802409B4 A22000B5 */  sb        $zero, 0xb5($s1)
/* 9FB1A8 802409B8 34420008 */  ori       $v0, $v0, 8
/* 9FB1AC 802409BC AE230084 */  sw        $v1, 0x84($s1)
/* 9FB1B0 802409C0 08090276 */  j         .L802409D8
/* 9FB1B4 802409C4 AE2200B0 */   sw       $v0, 0xb0($s1)
.L802409C8:
/* 9FB1B8 802409C8 8E2200B0 */  lw        $v0, 0xb0($s1)
/* 9FB1BC 802409CC 30420004 */  andi      $v0, $v0, 4
/* 9FB1C0 802409D0 10400047 */  beqz      $v0, .L80240AF0
/* 9FB1C4 802409D4 00000000 */   nop
.L802409D8:
/* 9FB1C8 802409D8 AE600070 */  sw        $zero, 0x70($s3)
/* 9FB1CC 802409DC A640008E */  sh        $zero, 0x8e($s2)
/* 9FB1D0 802409E0 8E2300CC */  lw        $v1, 0xcc($s1)
/* 9FB1D4 802409E4 2404F7FF */  addiu     $a0, $zero, -0x801
/* 9FB1D8 802409E8 A2200007 */  sb        $zero, 7($s1)
/* 9FB1DC 802409EC 8E420000 */  lw        $v0, ($s2)
/* 9FB1E0 802409F0 8C630000 */  lw        $v1, ($v1)
/* 9FB1E4 802409F4 00441024 */  and       $v0, $v0, $a0
/* 9FB1E8 802409F8 AE420000 */  sw        $v0, ($s2)
/* 9FB1EC 802409FC AE430028 */  sw        $v1, 0x28($s2)
/* 9FB1F0 80240A00 96220086 */  lhu       $v0, 0x86($s1)
/* 9FB1F4 80240A04 A64200A8 */  sh        $v0, 0xa8($s2)
/* 9FB1F8 80240A08 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 9FB1FC 80240A0C AE200090 */  sw        $zero, 0x90($s1)
/* 9FB200 80240A10 8C420034 */  lw        $v0, 0x34($v0)
/* 9FB204 80240A14 14400006 */  bnez      $v0, .L80240A30
/* 9FB208 80240A18 2403FDFF */   addiu    $v1, $zero, -0x201
/* 9FB20C 80240A1C 8E420000 */  lw        $v0, ($s2)
/* 9FB210 80240A20 2403FFF7 */  addiu     $v1, $zero, -9
/* 9FB214 80240A24 34420200 */  ori       $v0, $v0, 0x200
/* 9FB218 80240A28 0809028F */  j         .L80240A3C
/* 9FB21C 80240A2C 00431024 */   and      $v0, $v0, $v1
.L80240A30:
/* 9FB220 80240A30 8E420000 */  lw        $v0, ($s2)
/* 9FB224 80240A34 00431024 */  and       $v0, $v0, $v1
/* 9FB228 80240A38 34420008 */  ori       $v0, $v0, 8
.L80240A3C:
/* 9FB22C 80240A3C AE420000 */  sw        $v0, ($s2)
/* 9FB230 80240A40 8E2200B0 */  lw        $v0, 0xb0($s1)
/* 9FB234 80240A44 30420004 */  andi      $v0, $v0, 4
/* 9FB238 80240A48 1040001E */  beqz      $v0, .L80240AC4
/* 9FB23C 80240A4C 24040002 */   addiu    $a0, $zero, 2
/* 9FB240 80240A50 0240282D */  daddu     $a1, $s2, $zero
/* 9FB244 80240A54 0000302D */  daddu     $a2, $zero, $zero
/* 9FB248 80240A58 24020063 */  addiu     $v0, $zero, 0x63
/* 9FB24C 80240A5C AE620070 */  sw        $v0, 0x70($s3)
/* 9FB250 80240A60 AE600074 */  sw        $zero, 0x74($s3)
/* 9FB254 80240A64 864300A8 */  lh        $v1, 0xa8($s2)
/* 9FB258 80240A68 3C013F80 */  lui       $at, 0x3f80
/* 9FB25C 80240A6C 44810000 */  mtc1      $at, $f0
/* 9FB260 80240A70 3C014000 */  lui       $at, 0x4000
/* 9FB264 80240A74 44811000 */  mtc1      $at, $f2
/* 9FB268 80240A78 3C01C1A0 */  lui       $at, 0xc1a0
/* 9FB26C 80240A7C 44812000 */  mtc1      $at, $f4
/* 9FB270 80240A80 24020028 */  addiu     $v0, $zero, 0x28
/* 9FB274 80240A84 AFA2001C */  sw        $v0, 0x1c($sp)
/* 9FB278 80240A88 44833000 */  mtc1      $v1, $f6
/* 9FB27C 80240A8C 00000000 */  nop
/* 9FB280 80240A90 468031A0 */  cvt.s.w   $f6, $f6
/* 9FB284 80240A94 44073000 */  mfc1      $a3, $f6
/* 9FB288 80240A98 27A20048 */  addiu     $v0, $sp, 0x48
/* 9FB28C 80240A9C AFA20020 */  sw        $v0, 0x20($sp)
/* 9FB290 80240AA0 E7A00010 */  swc1      $f0, 0x10($sp)
/* 9FB294 80240AA4 E7A20014 */  swc1      $f2, 0x14($sp)
/* 9FB298 80240AA8 0C01BFA4 */  jal       fx_emote
/* 9FB29C 80240AAC E7A40018 */   swc1     $f4, 0x18($sp)
/* 9FB2A0 80240AB0 8E2200B0 */  lw        $v0, 0xb0($s1)
/* 9FB2A4 80240AB4 2403FFFB */  addiu     $v1, $zero, -5
/* 9FB2A8 80240AB8 00431024 */  and       $v0, $v0, $v1
/* 9FB2AC 80240ABC 080902BC */  j         .L80240AF0
/* 9FB2B0 80240AC0 AE2200B0 */   sw       $v0, 0xb0($s1)
.L80240AC4:
/* 9FB2B4 80240AC4 8E220000 */  lw        $v0, ($s1)
/* 9FB2B8 80240AC8 3C034000 */  lui       $v1, 0x4000
/* 9FB2BC 80240ACC 00431024 */  and       $v0, $v0, $v1
/* 9FB2C0 80240AD0 10400007 */  beqz      $v0, .L80240AF0
/* 9FB2C4 80240AD4 3C03BFFF */   lui      $v1, 0xbfff
/* 9FB2C8 80240AD8 2402000C */  addiu     $v0, $zero, 0xc
/* 9FB2CC 80240ADC AE620070 */  sw        $v0, 0x70($s3)
/* 9FB2D0 80240AE0 8E220000 */  lw        $v0, ($s1)
/* 9FB2D4 80240AE4 3463FFFF */  ori       $v1, $v1, 0xffff
/* 9FB2D8 80240AE8 00431024 */  and       $v0, $v0, $v1
/* 9FB2DC 80240AEC AE220000 */  sw        $v0, ($s1)
.L80240AF0:
/* 9FB2E0 80240AF0 8E220090 */  lw        $v0, 0x90($s1)
/* 9FB2E4 80240AF4 1840000C */  blez      $v0, .L80240B28
/* 9FB2E8 80240AF8 2442FFFF */   addiu    $v0, $v0, -1
/* 9FB2EC 80240AFC 14400087 */  bnez      $v0, L80240D1C_9FB50C
/* 9FB2F0 80240B00 AE220090 */   sw       $v0, 0x90($s1)
/* 9FB2F4 80240B04 3C03FFAA */  lui       $v1, 0xffaa
/* 9FB2F8 80240B08 8E420028 */  lw        $v0, 0x28($s2)
/* 9FB2FC 80240B0C 3463FFD2 */  ori       $v1, $v1, 0xffd2
/* 9FB300 80240B10 00431021 */  addu      $v0, $v0, $v1
/* 9FB304 80240B14 2C420002 */  sltiu     $v0, $v0, 2
/* 9FB308 80240B18 10400003 */  beqz      $v0, .L80240B28
/* 9FB30C 80240B1C 3C020055 */   lui      $v0, 0x55
/* 9FB310 80240B20 3442000C */  ori       $v0, $v0, 0xc
/* 9FB314 80240B24 AE420028 */  sw        $v0, 0x28($s2)
.L80240B28:
/* 9FB318 80240B28 8E630070 */  lw        $v1, 0x70($s3)
/* 9FB31C 80240B2C 2402000C */  addiu     $v0, $zero, 0xc
/* 9FB320 80240B30 10620048 */  beq       $v1, $v0, .L80240C54
/* 9FB324 80240B34 2862000D */   slti     $v0, $v1, 0xd
/* 9FB328 80240B38 1040000F */  beqz      $v0, .L80240B78
/* 9FB32C 80240B3C 24100001 */   addiu    $s0, $zero, 1
/* 9FB330 80240B40 1070001E */  beq       $v1, $s0, .L80240BBC
/* 9FB334 80240B44 28620002 */   slti     $v0, $v1, 2
/* 9FB338 80240B48 10400005 */  beqz      $v0, .L80240B60
/* 9FB33C 80240B4C 24020002 */   addiu    $v0, $zero, 2
/* 9FB340 80240B50 10600015 */  beqz      $v1, .L80240BA8
/* 9FB344 80240B54 0260202D */   daddu    $a0, $s3, $zero
/* 9FB348 80240B58 0809032C */  j         .L80240CB0
/* 9FB34C 80240B5C 00000000 */   nop
.L80240B60:
/* 9FB350 80240B60 1062001C */  beq       $v1, $v0, .L80240BD4
/* 9FB354 80240B64 24020003 */   addiu    $v0, $zero, 3
/* 9FB358 80240B68 10620035 */  beq       $v1, $v0, .L80240C40
/* 9FB35C 80240B6C 0260202D */   daddu    $a0, $s3, $zero
/* 9FB360 80240B70 0809032C */  j         .L80240CB0
/* 9FB364 80240B74 00000000 */   nop
.L80240B78:
/* 9FB368 80240B78 2402000E */  addiu     $v0, $zero, 0xe
/* 9FB36C 80240B7C 1062003F */  beq       $v1, $v0, .L80240C7C
/* 9FB370 80240B80 0062102A */   slt      $v0, $v1, $v0
/* 9FB374 80240B84 14400038 */  bnez      $v0, .L80240C68
/* 9FB378 80240B88 0260202D */   daddu    $a0, $s3, $zero
/* 9FB37C 80240B8C 2402000F */  addiu     $v0, $zero, 0xf
/* 9FB380 80240B90 10620040 */  beq       $v1, $v0, .L80240C94
/* 9FB384 80240B94 24020063 */   addiu    $v0, $zero, 0x63
/* 9FB388 80240B98 10620043 */  beq       $v1, $v0, .L80240CA8
/* 9FB38C 80240B9C 00000000 */   nop
/* 9FB390 80240BA0 0809032C */  j         .L80240CB0
/* 9FB394 80240BA4 00000000 */   nop
.L80240BA8:
/* 9FB398 80240BA8 0280282D */  daddu     $a1, $s4, $zero
/* 9FB39C 80240BAC 0C012568 */  jal       func_800495A0
/* 9FB3A0 80240BB0 02A0302D */   daddu    $a2, $s5, $zero
/* 9FB3A4 80240BB4 96220086 */  lhu       $v0, 0x86($s1)
/* 9FB3A8 80240BB8 A64200A8 */  sh        $v0, 0xa8($s2)
.L80240BBC:
/* 9FB3AC 80240BBC 0260202D */  daddu     $a0, $s3, $zero
/* 9FB3B0 80240BC0 0280282D */  daddu     $a1, $s4, $zero
/* 9FB3B4 80240BC4 0C0125AE */  jal       func_800496B8
/* 9FB3B8 80240BC8 02A0302D */   daddu    $a2, $s5, $zero
/* 9FB3BC 80240BCC 0809032C */  j         .L80240CB0
/* 9FB3C0 80240BD0 00000000 */   nop
.L80240BD4:
/* 9FB3C4 80240BD4 0260202D */  daddu     $a0, $s3, $zero
/* 9FB3C8 80240BD8 0280282D */  daddu     $a1, $s4, $zero
/* 9FB3CC 80240BDC 0C0126D1 */  jal       base_UnkNpcAIFunc1
/* 9FB3D0 80240BE0 02A0302D */   daddu    $a2, $s5, $zero
/* 9FB3D4 80240BE4 8E230088 */  lw        $v1, 0x88($s1)
/* 9FB3D8 80240BE8 24020006 */  addiu     $v0, $zero, 6
/* 9FB3DC 80240BEC 14620014 */  bne       $v1, $v0, .L80240C40
/* 9FB3E0 80240BF0 0260202D */   daddu    $a0, $s3, $zero
/* 9FB3E4 80240BF4 0C00A67F */  jal       rand_int
/* 9FB3E8 80240BF8 24040064 */   addiu    $a0, $zero, 0x64
/* 9FB3EC 80240BFC 28420021 */  slti      $v0, $v0, 0x21
/* 9FB3F0 80240C00 5040000F */  beql      $v0, $zero, .L80240C40
/* 9FB3F4 80240C04 0260202D */   daddu    $a0, $s3, $zero
/* 9FB3F8 80240C08 8E22008C */  lw        $v0, 0x8c($s1)
/* 9FB3FC 80240C0C 10400005 */  beqz      $v0, .L80240C24
/* 9FB400 80240C10 3C020055 */   lui      $v0, 0x55
/* 9FB404 80240C14 3442002F */  ori       $v0, $v0, 0x2f
/* 9FB408 80240C18 AE20008C */  sw        $zero, 0x8c($s1)
/* 9FB40C 80240C1C 0809030C */  j         .L80240C30
/* 9FB410 80240C20 A22000B5 */   sb       $zero, 0xb5($s1)
.L80240C24:
/* 9FB414 80240C24 3442002E */  ori       $v0, $v0, 0x2e
/* 9FB418 80240C28 AE30008C */  sw        $s0, 0x8c($s1)
/* 9FB41C 80240C2C A23000B5 */  sb        $s0, 0xb5($s1)
.L80240C30:
/* 9FB420 80240C30 AE420028 */  sw        $v0, 0x28($s2)
/* 9FB424 80240C34 24020007 */  addiu     $v0, $zero, 7
/* 9FB428 80240C38 08090347 */  j         L80240D1C_9FB50C
/* 9FB42C 80240C3C AE220090 */   sw       $v0, 0x90($s1)
.L80240C40:
/* 9FB430 80240C40 0280282D */  daddu     $a1, $s4, $zero
/* 9FB434 80240C44 0C012701 */  jal       func_80049C04
/* 9FB438 80240C48 02A0302D */   daddu    $a2, $s5, $zero
/* 9FB43C 80240C4C 0809032C */  j         .L80240CB0
/* 9FB440 80240C50 00000000 */   nop
.L80240C54:
/* 9FB444 80240C54 0260202D */  daddu     $a0, $s3, $zero
/* 9FB448 80240C58 0280282D */  daddu     $a1, $s4, $zero
/* 9FB44C 80240C5C 0C09015C */  jal       nok_12_set_script_owner_npc_anim
/* 9FB450 80240C60 02A0302D */   daddu    $a2, $s5, $zero
/* 9FB454 80240C64 0260202D */  daddu     $a0, $s3, $zero
.L80240C68:
/* 9FB458 80240C68 0280282D */  daddu     $a1, $s4, $zero
/* 9FB45C 80240C6C 0C09017B */  jal       func_802405EC_9FADDC
/* 9FB460 80240C70 02A0302D */   daddu    $a2, $s5, $zero
/* 9FB464 80240C74 0809032C */  j         .L80240CB0
/* 9FB468 80240C78 00000000 */   nop
.L80240C7C:
/* 9FB46C 80240C7C 0260202D */  daddu     $a0, $s3, $zero
/* 9FB470 80240C80 0280282D */  daddu     $a1, $s4, $zero
/* 9FB474 80240C84 0C0901C8 */  jal       nok_12_UnkNpcAIFunc12
/* 9FB478 80240C88 02A0302D */   daddu    $a2, $s5, $zero
/* 9FB47C 80240C8C 0809032C */  j         .L80240CB0
/* 9FB480 80240C90 00000000 */   nop
.L80240C94:
/* 9FB484 80240C94 0280282D */  daddu     $a1, $s4, $zero
/* 9FB488 80240C98 0C090221 */  jal       nok_12_set_script_owner_npc_col_height
/* 9FB48C 80240C9C 02A0302D */   daddu    $a2, $s5, $zero
/* 9FB490 80240CA0 0809032C */  j         .L80240CB0
/* 9FB494 80240CA4 00000000 */   nop
.L80240CA8:
/* 9FB498 80240CA8 0C0129CF */  jal       func_8004A73C
/* 9FB49C 80240CAC 0260202D */   daddu    $a0, $s3, $zero
.L80240CB0:
/* 9FB4A0 80240CB0 8E230088 */  lw        $v1, 0x88($s1)
/* 9FB4A4 80240CB4 24020006 */  addiu     $v0, $zero, 6
/* 9FB4A8 80240CB8 14620019 */  bne       $v1, $v0, .L80240D20
/* 9FB4AC 80240CBC 0000102D */   daddu    $v0, $zero, $zero
/* 9FB4B0 80240CC0 8E22008C */  lw        $v0, 0x8c($s1)
/* 9FB4B4 80240CC4 10400003 */  beqz      $v0, .L80240CD4
/* 9FB4B8 80240CC8 24020001 */   addiu    $v0, $zero, 1
/* 9FB4BC 80240CCC 08090336 */  j         .L80240CD8
/* 9FB4C0 80240CD0 A22200B5 */   sb       $v0, 0xb5($s1)
.L80240CD4:
/* 9FB4C4 80240CD4 A22000B5 */  sb        $zero, 0xb5($s1)
.L80240CD8:
/* 9FB4C8 80240CD8 8E22008C */  lw        $v0, 0x8c($s1)
/* 9FB4CC 80240CDC 1040000F */  beqz      $v0, L80240D1C_9FB50C
/* 9FB4D0 80240CE0 3C03FFAA */   lui      $v1, 0xffaa
/* 9FB4D4 80240CE4 8E420028 */  lw        $v0, 0x28($s2)
/* 9FB4D8 80240CE8 3463FFFC */  ori       $v1, $v1, 0xfffc
/* 9FB4DC 80240CEC 00431821 */  addu      $v1, $v0, $v1
/* 9FB4E0 80240CF0 2C620015 */  sltiu     $v0, $v1, 0x15
/* 9FB4E4 80240CF4 10400009 */  beqz      $v0, L80240D1C_9FB50C
/* 9FB4E8 80240CF8 00031080 */   sll      $v0, $v1, 2
/* 9FB4EC 80240CFC 3C018024 */  lui       $at, %hi(jtbl_80245A78_A00268)
/* 9FB4F0 80240D00 00220821 */  addu      $at, $at, $v0
/* 9FB4F4 80240D04 8C225A78 */  lw        $v0, %lo(jtbl_80245A78_A00268)($at)
/* 9FB4F8 80240D08 00400008 */  jr        $v0
/* 9FB4FC 80240D0C 00000000 */   nop
glabel L80240D10_9FB500
/* 9FB500 80240D10 8E420028 */  lw        $v0, 0x28($s2)
/* 9FB504 80240D14 24420001 */  addiu     $v0, $v0, 1
/* 9FB508 80240D18 AE420028 */  sw        $v0, 0x28($s2)
glabel L80240D1C_9FB50C
/* 9FB50C 80240D1C 0000102D */  daddu     $v0, $zero, $zero
.L80240D20:
/* 9FB510 80240D20 8FBF0068 */  lw        $ra, 0x68($sp)
/* 9FB514 80240D24 8FB50064 */  lw        $s5, 0x64($sp)
/* 9FB518 80240D28 8FB40060 */  lw        $s4, 0x60($sp)
/* 9FB51C 80240D2C 8FB3005C */  lw        $s3, 0x5c($sp)
/* 9FB520 80240D30 8FB20058 */  lw        $s2, 0x58($sp)
/* 9FB524 80240D34 8FB10054 */  lw        $s1, 0x54($sp)
/* 9FB528 80240D38 8FB00050 */  lw        $s0, 0x50($sp)
/* 9FB52C 80240D3C 03E00008 */  jr        $ra
/* 9FB530 80240D40 27BD0070 */   addiu    $sp, $sp, 0x70
