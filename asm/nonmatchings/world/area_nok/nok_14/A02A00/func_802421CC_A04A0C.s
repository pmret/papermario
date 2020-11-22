.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802421CC_A04A0C
/* A04A0C 802421CC 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* A04A10 802421D0 AFB3003C */  sw        $s3, 0x3c($sp)
/* A04A14 802421D4 0080982D */  daddu     $s3, $a0, $zero
/* A04A18 802421D8 AFBF0048 */  sw        $ra, 0x48($sp)
/* A04A1C 802421DC AFB50044 */  sw        $s5, 0x44($sp)
/* A04A20 802421E0 AFB40040 */  sw        $s4, 0x40($sp)
/* A04A24 802421E4 AFB20038 */  sw        $s2, 0x38($sp)
/* A04A28 802421E8 AFB10034 */  sw        $s1, 0x34($sp)
/* A04A2C 802421EC AFB00030 */  sw        $s0, 0x30($sp)
/* A04A30 802421F0 8E720148 */  lw        $s2, 0x148($s3)
/* A04A34 802421F4 86440008 */  lh        $a0, 8($s2)
/* A04A38 802421F8 8E70000C */  lw        $s0, 0xc($s3)
/* A04A3C 802421FC 0C00EABB */  jal       get_npc_unsafe
/* A04A40 80242200 00A0882D */   daddu    $s1, $a1, $zero
/* A04A44 80242204 0260202D */  daddu     $a0, $s3, $zero
/* A04A48 80242208 8E050000 */  lw        $a1, ($s0)
/* A04A4C 8024220C 0C0B1EAF */  jal       get_variable
/* A04A50 80242210 0040A82D */   daddu    $s5, $v0, $zero
/* A04A54 80242214 AFA00010 */  sw        $zero, 0x10($sp)
/* A04A58 80242218 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A04A5C 8024221C 8C630030 */  lw        $v1, 0x30($v1)
/* A04A60 80242220 AFA30014 */  sw        $v1, 0x14($sp)
/* A04A64 80242224 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A04A68 80242228 8C63001C */  lw        $v1, 0x1c($v1)
/* A04A6C 8024222C AFA30018 */  sw        $v1, 0x18($sp)
/* A04A70 80242230 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A04A74 80242234 8C630024 */  lw        $v1, 0x24($v1)
/* A04A78 80242238 AFA3001C */  sw        $v1, 0x1c($sp)
/* A04A7C 8024223C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A04A80 80242240 8C630028 */  lw        $v1, 0x28($v1)
/* A04A84 80242244 27B40010 */  addiu     $s4, $sp, 0x10
/* A04A88 80242248 AFA30020 */  sw        $v1, 0x20($sp)
/* A04A8C 8024224C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A04A90 80242250 3C0142F0 */  lui       $at, 0x42f0
/* A04A94 80242254 44810000 */  mtc1      $at, $f0
/* A04A98 80242258 8C63002C */  lw        $v1, 0x2c($v1)
/* A04A9C 8024225C 0040802D */  daddu     $s0, $v0, $zero
/* A04AA0 80242260 E7A00028 */  swc1      $f0, 0x28($sp)
/* A04AA4 80242264 A7A0002C */  sh        $zero, 0x2c($sp)
/* A04AA8 80242268 12200009 */  beqz      $s1, .L80242290
/* A04AAC 8024226C AFA30024 */   sw       $v1, 0x24($sp)
/* A04AB0 80242270 02A0202D */  daddu     $a0, $s5, $zero
/* A04AB4 80242274 0240282D */  daddu     $a1, $s2, $zero
/* A04AB8 80242278 0260302D */  daddu     $a2, $s3, $zero
/* A04ABC 8024227C 0C0906DF */  jal       func_80241B7C_A043BC
/* A04AC0 80242280 0200382D */   daddu    $a3, $s0, $zero
/* A04AC4 80242284 86A200A8 */  lh        $v0, 0xa8($s5)
/* A04AC8 80242288 AE42008C */  sw        $v0, 0x8c($s2)
/* A04ACC 8024228C AE600070 */  sw        $zero, 0x70($s3)
.L80242290:
/* A04AD0 80242290 2402FFFD */  addiu     $v0, $zero, -3
/* A04AD4 80242294 A2A200AB */  sb        $v0, 0xab($s5)
/* A04AD8 80242298 8E4300B0 */  lw        $v1, 0xb0($s2)
/* A04ADC 8024229C 30620004 */  andi      $v0, $v1, 4
/* A04AE0 802422A0 10400007 */  beqz      $v0, .L802422C0
/* A04AE4 802422A4 00000000 */   nop      
/* A04AE8 802422A8 824200B4 */  lb        $v0, 0xb4($s2)
/* A04AEC 802422AC 14400052 */  bnez      $v0, .L802423F8
/* A04AF0 802422B0 0000102D */   daddu    $v0, $zero, $zero
/* A04AF4 802422B4 2402FFFB */  addiu     $v0, $zero, -5
/* A04AF8 802422B8 00621024 */  and       $v0, $v1, $v0
/* A04AFC 802422BC AE4200B0 */  sw        $v0, 0xb0($s2)
.L802422C0:
/* A04B00 802422C0 8E630070 */  lw        $v1, 0x70($s3)
/* A04B04 802422C4 2C620010 */  sltiu     $v0, $v1, 0x10
/* A04B08 802422C8 1040004A */  beqz      $v0, .L802423F4
/* A04B0C 802422CC 00031080 */   sll      $v0, $v1, 2
/* A04B10 802422D0 3C018024 */  lui       $at, 0x8024
/* A04B14 802422D4 00220821 */  addu      $at, $at, $v0
/* A04B18 802422D8 8C224678 */  lw        $v0, 0x4678($at)
/* A04B1C 802422DC 00400008 */  jr        $v0
/* A04B20 802422E0 00000000 */   nop      
/* A04B24 802422E4 0260202D */  daddu     $a0, $s3, $zero
/* A04B28 802422E8 0200282D */  daddu     $a1, $s0, $zero
/* A04B2C 802422EC 0C090265 */  jal       func_80240994_A031D4
/* A04B30 802422F0 0280302D */   daddu    $a2, $s4, $zero
/* A04B34 802422F4 0260202D */  daddu     $a0, $s3, $zero
/* A04B38 802422F8 0200282D */  daddu     $a1, $s0, $zero
/* A04B3C 802422FC 0C0902D1 */  jal       func_80240B44_A03384
/* A04B40 80242300 0280302D */   daddu    $a2, $s4, $zero
/* A04B44 80242304 8E630070 */  lw        $v1, 0x70($s3)
/* A04B48 80242308 24020002 */  addiu     $v0, $zero, 2
/* A04B4C 8024230C 1462003A */  bne       $v1, $v0, .L802423F8
/* A04B50 80242310 0000102D */   daddu    $v0, $zero, $zero
/* A04B54 80242314 0260202D */  daddu     $a0, $s3, $zero
/* A04B58 80242318 0200282D */  daddu     $a1, $s0, $zero
/* A04B5C 8024231C 0C09045B */  jal       UnkNpcAIFunc1
/* A04B60 80242320 0280302D */   daddu    $a2, $s4, $zero
/* A04B64 80242324 0260202D */  daddu     $a0, $s3, $zero
/* A04B68 80242328 0200282D */  daddu     $a1, $s0, $zero
/* A04B6C 8024232C 0C09048B */  jal       func_8024122C_A03A6C
/* A04B70 80242330 0280302D */   daddu    $a2, $s4, $zero
/* A04B74 80242334 8E630070 */  lw        $v1, 0x70($s3)
/* A04B78 80242338 2402000A */  addiu     $v0, $zero, 0xa
/* A04B7C 8024233C 1462002E */  bne       $v1, $v0, .L802423F8
/* A04B80 80242340 0000102D */   daddu    $v0, $zero, $zero
/* A04B84 80242344 0260202D */  daddu     $a0, $s3, $zero
/* A04B88 80242348 0200282D */  daddu     $a1, $s0, $zero
/* A04B8C 8024234C 0C09055C */  jal       func_80241570_A03DB0
/* A04B90 80242350 0280302D */   daddu    $a2, $s4, $zero
/* A04B94 80242354 8E630070 */  lw        $v1, 0x70($s3)
/* A04B98 80242358 2402000B */  addiu     $v0, $zero, 0xb
/* A04B9C 8024235C 14620026 */  bne       $v1, $v0, .L802423F8
/* A04BA0 80242360 0000102D */   daddu    $v0, $zero, $zero
/* A04BA4 80242364 0260202D */  daddu     $a0, $s3, $zero
/* A04BA8 80242368 0200282D */  daddu     $a1, $s0, $zero
/* A04BAC 8024236C 0C09057A */  jal       func_802415E8_A03E28
/* A04BB0 80242370 0280302D */   daddu    $a2, $s4, $zero
/* A04BB4 80242374 8E630070 */  lw        $v1, 0x70($s3)
/* A04BB8 80242378 2402000C */  addiu     $v0, $zero, 0xc
/* A04BBC 8024237C 1462001E */  bne       $v1, $v0, .L802423F8
/* A04BC0 80242380 0000102D */   daddu    $v0, $zero, $zero
/* A04BC4 80242384 0260202D */  daddu     $a0, $s3, $zero
/* A04BC8 80242388 0200282D */  daddu     $a1, $s0, $zero
/* A04BCC 8024238C 0C0907A3 */  jal       func_80241E8C_A046CC
/* A04BD0 80242390 0280302D */   daddu    $a2, $s4, $zero
/* A04BD4 80242394 8E630070 */  lw        $v1, 0x70($s3)
/* A04BD8 80242398 2402000D */  addiu     $v0, $zero, 0xd
/* A04BDC 8024239C 14620016 */  bne       $v1, $v0, .L802423F8
/* A04BE0 802423A0 0000102D */   daddu    $v0, $zero, $zero
/* A04BE4 802423A4 0260202D */  daddu     $a0, $s3, $zero
/* A04BE8 802423A8 0200282D */  daddu     $a1, $s0, $zero
/* A04BEC 802423AC 0C0907ED */  jal       func_80241FB4_A047F4
/* A04BF0 802423B0 0280302D */   daddu    $a2, $s4, $zero
/* A04BF4 802423B4 8E630070 */  lw        $v1, 0x70($s3)
/* A04BF8 802423B8 2402000E */  addiu     $v0, $zero, 0xe
/* A04BFC 802423BC 1462000E */  bne       $v1, $v0, .L802423F8
/* A04C00 802423C0 0000102D */   daddu    $v0, $zero, $zero
/* A04C04 802423C4 0260202D */  daddu     $a0, $s3, $zero
/* A04C08 802423C8 0200282D */  daddu     $a1, $s0, $zero
/* A04C0C 802423CC 0C09081C */  jal       func_80242070_A048B0
/* A04C10 802423D0 0280302D */   daddu    $a2, $s4, $zero
/* A04C14 802423D4 8E630070 */  lw        $v1, 0x70($s3)
/* A04C18 802423D8 2402000F */  addiu     $v0, $zero, 0xf
/* A04C1C 802423DC 14620006 */  bne       $v1, $v0, .L802423F8
/* A04C20 802423E0 0000102D */   daddu    $v0, $zero, $zero
/* A04C24 802423E4 0260202D */  daddu     $a0, $s3, $zero
/* A04C28 802423E8 0200282D */  daddu     $a1, $s0, $zero
/* A04C2C 802423EC 0C090862 */  jal       UnkDurationCheck
/* A04C30 802423F0 0280302D */   daddu    $a2, $s4, $zero
.L802423F4:
/* A04C34 802423F4 0000102D */  daddu     $v0, $zero, $zero
.L802423F8:
/* A04C38 802423F8 8FBF0048 */  lw        $ra, 0x48($sp)
/* A04C3C 802423FC 8FB50044 */  lw        $s5, 0x44($sp)
/* A04C40 80242400 8FB40040 */  lw        $s4, 0x40($sp)
/* A04C44 80242404 8FB3003C */  lw        $s3, 0x3c($sp)
/* A04C48 80242408 8FB20038 */  lw        $s2, 0x38($sp)
/* A04C4C 8024240C 8FB10034 */  lw        $s1, 0x34($sp)
/* A04C50 80242410 8FB00030 */  lw        $s0, 0x30($sp)
/* A04C54 80242414 03E00008 */  jr        $ra
/* A04C58 80242418 27BD0050 */   addiu    $sp, $sp, 0x50
/* A04C5C 8024241C 00000000 */  nop       
