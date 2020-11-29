.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024219C_BE594C
/* BE594C 8024219C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* BE5950 802421A0 AFB40040 */  sw        $s4, 0x40($sp)
/* BE5954 802421A4 0080A02D */  daddu     $s4, $a0, $zero
/* BE5958 802421A8 AFBF0048 */  sw        $ra, 0x48($sp)
/* BE595C 802421AC AFB50044 */  sw        $s5, 0x44($sp)
/* BE5960 802421B0 AFB3003C */  sw        $s3, 0x3c($sp)
/* BE5964 802421B4 AFB20038 */  sw        $s2, 0x38($sp)
/* BE5968 802421B8 AFB10034 */  sw        $s1, 0x34($sp)
/* BE596C 802421BC AFB00030 */  sw        $s0, 0x30($sp)
/* BE5970 802421C0 8E920148 */  lw        $s2, 0x148($s4)
/* BE5974 802421C4 86440008 */  lh        $a0, 8($s2)
/* BE5978 802421C8 8E90000C */  lw        $s0, 0xc($s4)
/* BE597C 802421CC 0C00EABB */  jal       get_npc_unsafe
/* BE5980 802421D0 00A0882D */   daddu    $s1, $a1, $zero
/* BE5984 802421D4 0280202D */  daddu     $a0, $s4, $zero
/* BE5988 802421D8 8E050000 */  lw        $a1, ($s0)
/* BE598C 802421DC 0C0B1EAF */  jal       get_variable
/* BE5990 802421E0 0040A82D */   daddu    $s5, $v0, $zero
/* BE5994 802421E4 AFA00010 */  sw        $zero, 0x10($sp)
/* BE5998 802421E8 8E4300D0 */  lw        $v1, 0xd0($s2)
/* BE599C 802421EC 8C630030 */  lw        $v1, 0x30($v1)
/* BE59A0 802421F0 AFA30014 */  sw        $v1, 0x14($sp)
/* BE59A4 802421F4 8E4300D0 */  lw        $v1, 0xd0($s2)
/* BE59A8 802421F8 8C63001C */  lw        $v1, 0x1c($v1)
/* BE59AC 802421FC AFA30018 */  sw        $v1, 0x18($sp)
/* BE59B0 80242200 8E4300D0 */  lw        $v1, 0xd0($s2)
/* BE59B4 80242204 8C630024 */  lw        $v1, 0x24($v1)
/* BE59B8 80242208 AFA3001C */  sw        $v1, 0x1c($sp)
/* BE59BC 8024220C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* BE59C0 80242210 8C630028 */  lw        $v1, 0x28($v1)
/* BE59C4 80242214 27B30010 */  addiu     $s3, $sp, 0x10
/* BE59C8 80242218 AFA30020 */  sw        $v1, 0x20($sp)
/* BE59CC 8024221C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* BE59D0 80242220 3C0142F0 */  lui       $at, 0x42f0
/* BE59D4 80242224 44810000 */  mtc1      $at, $f0
/* BE59D8 80242228 8C63002C */  lw        $v1, 0x2c($v1)
/* BE59DC 8024222C 0040802D */  daddu     $s0, $v0, $zero
/* BE59E0 80242230 E7A00028 */  swc1      $f0, 0x28($sp)
/* BE59E4 80242234 A7A0002C */  sh        $zero, 0x2c($sp)
/* BE59E8 80242238 12200006 */  beqz      $s1, .L80242254
/* BE59EC 8024223C AFA30024 */   sw       $v1, 0x24($sp)
/* BE59F0 80242240 02A0202D */  daddu     $a0, $s5, $zero
/* BE59F4 80242244 0240282D */  daddu     $a1, $s2, $zero
/* BE59F8 80242248 0280302D */  daddu     $a2, $s4, $zero
/* BE59FC 8024224C 0C09081E */  jal       func_80242078_BE5828
/* BE5A00 80242250 0200382D */   daddu    $a3, $s0, $zero
.L80242254:
/* BE5A04 80242254 2402FFFE */  addiu     $v0, $zero, -2
/* BE5A08 80242258 A2A200AB */  sb        $v0, 0xab($s5)
/* BE5A0C 8024225C 8E4300B0 */  lw        $v1, 0xb0($s2)
/* BE5A10 80242260 30620004 */  andi      $v0, $v1, 4
/* BE5A14 80242264 10400007 */  beqz      $v0, .L80242284
/* BE5A18 80242268 00000000 */   nop      
/* BE5A1C 8024226C 824200B4 */  lb        $v0, 0xb4($s2)
/* BE5A20 80242270 1440003C */  bnez      $v0, .L80242364
/* BE5A24 80242274 0000102D */   daddu    $v0, $zero, $zero
/* BE5A28 80242278 2402FFFB */  addiu     $v0, $zero, -5
/* BE5A2C 8024227C 00621024 */  and       $v0, $v1, $v0
/* BE5A30 80242280 AE4200B0 */  sw        $v0, 0xb0($s2)
.L80242284:
/* BE5A34 80242284 8E830070 */  lw        $v1, 0x70($s4)
/* BE5A38 80242288 2C62000F */  sltiu     $v0, $v1, 0xf
/* BE5A3C 8024228C 10400034 */  beqz      $v0, .L80242360
/* BE5A40 80242290 00031080 */   sll      $v0, $v1, 2
/* BE5A44 80242294 3C018024 */  lui       $at, %hi(D_802442E8)
/* BE5A48 80242298 00220821 */  addu      $at, $at, $v0
/* BE5A4C 8024229C 8C2242E8 */  lw        $v0, %lo(D_802442E8)($at)
/* BE5A50 802422A0 00400008 */  jr        $v0
/* BE5A54 802422A4 00000000 */   nop      
/* BE5A58 802422A8 0280202D */  daddu     $a0, $s4, $zero
/* BE5A5C 802422AC 0200282D */  daddu     $a1, $s0, $zero
/* BE5A60 802422B0 0C0903A4 */  jal       func_80240E90_BE4640
/* BE5A64 802422B4 0260302D */   daddu    $a2, $s3, $zero
/* BE5A68 802422B8 0280202D */  daddu     $a0, $s4, $zero
/* BE5A6C 802422BC 0200282D */  daddu     $a1, $s0, $zero
/* BE5A70 802422C0 0C090410 */  jal       func_80241040_BE47F0
/* BE5A74 802422C4 0260302D */   daddu    $a2, $s3, $zero
/* BE5A78 802422C8 080908D9 */  j         .L80242364
/* BE5A7C 802422CC 0000102D */   daddu    $v0, $zero, $zero
/* BE5A80 802422D0 0280202D */  daddu     $a0, $s4, $zero
/* BE5A84 802422D4 0200282D */  daddu     $a1, $s0, $zero
/* BE5A88 802422D8 0C09059A */  jal       func_80241668_BE4E18
/* BE5A8C 802422DC 0260302D */   daddu    $a2, $s3, $zero
/* BE5A90 802422E0 0280202D */  daddu     $a0, $s4, $zero
/* BE5A94 802422E4 0200282D */  daddu     $a1, $s0, $zero
/* BE5A98 802422E8 0C0905CA */  jal       func_80241728_BE4ED8
/* BE5A9C 802422EC 0260302D */   daddu    $a2, $s3, $zero
/* BE5AA0 802422F0 080908D9 */  j         .L80242364
/* BE5AA4 802422F4 0000102D */   daddu    $v0, $zero, $zero
/* BE5AA8 802422F8 0280202D */  daddu     $a0, $s4, $zero
/* BE5AAC 802422FC 0200282D */  daddu     $a1, $s0, $zero
/* BE5AB0 80242300 0C09069B */  jal       UnkNpcAIFunc2
/* BE5AB4 80242304 0260302D */   daddu    $a2, $s3, $zero
/* BE5AB8 80242308 0280202D */  daddu     $a0, $s4, $zero
/* BE5ABC 8024230C 0200282D */  daddu     $a1, $s0, $zero
/* BE5AC0 80242310 0C0906B9 */  jal       func_80241AE4_BE5294
/* BE5AC4 80242314 0260302D */   daddu    $a2, $s3, $zero
/* BE5AC8 80242318 080908D9 */  j         .L80242364
/* BE5ACC 8024231C 0000102D */   daddu    $v0, $zero, $zero
/* BE5AD0 80242320 0280202D */  daddu     $a0, $s4, $zero
/* BE5AD4 80242324 0200282D */  daddu     $a1, $s0, $zero
/* BE5AD8 80242328 0C0906D4 */  jal       func_80241B50_BE5300
/* BE5ADC 8024232C 0260302D */   daddu    $a2, $s3, $zero
/* BE5AE0 80242330 080908D9 */  j         .L80242364
/* BE5AE4 80242334 0000102D */   daddu    $v0, $zero, $zero
/* BE5AE8 80242338 0280202D */  daddu     $a0, $s4, $zero
/* BE5AEC 8024233C 0200282D */  daddu     $a1, $s0, $zero
/* BE5AF0 80242340 0C090721 */  jal       UnkNpcAIFunc3
/* BE5AF4 80242344 0260302D */   daddu    $a2, $s3, $zero
/* BE5AF8 80242348 080908D9 */  j         .L80242364
/* BE5AFC 8024234C 0000102D */   daddu    $v0, $zero, $zero
/* BE5B00 80242350 0280202D */  daddu     $a0, $s4, $zero
/* BE5B04 80242354 0200282D */  daddu     $a1, $s0, $zero
/* BE5B08 80242358 0C09073A */  jal       func_80241CE8_BE5498
/* BE5B0C 8024235C 0260302D */   daddu    $a2, $s3, $zero
.L80242360:
/* BE5B10 80242360 0000102D */  daddu     $v0, $zero, $zero
.L80242364:
/* BE5B14 80242364 8FBF0048 */  lw        $ra, 0x48($sp)
/* BE5B18 80242368 8FB50044 */  lw        $s5, 0x44($sp)
/* BE5B1C 8024236C 8FB40040 */  lw        $s4, 0x40($sp)
/* BE5B20 80242370 8FB3003C */  lw        $s3, 0x3c($sp)
/* BE5B24 80242374 8FB20038 */  lw        $s2, 0x38($sp)
/* BE5B28 80242378 8FB10034 */  lw        $s1, 0x34($sp)
/* BE5B2C 8024237C 8FB00030 */  lw        $s0, 0x30($sp)
/* BE5B30 80242380 03E00008 */  jr        $ra
/* BE5B34 80242384 27BD0050 */   addiu    $sp, $sp, 0x50
