.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_80242FA0_A67030
.word L80241208_A65298, L80241228_A652B8, L80241300_A65390, L80241300_A65390, L80241300_A65390, L80241240_A652D0, L80241250_A652E0, L80241300_A65390, L80241300_A65390, L80241300_A65390, L80241268_A652F8, L80241278_A65308, L80241300_A65390, L80241300_A65390, L80241300_A65390, L80241300_A65390, L80241300_A65390, L80241300_A65390, L80241300_A65390, L80241300_A65390, L80241290_A65320, L802412A8_A65338, L802412C0_A65350, L802412D8_A65368, L802412F0_A65380, 0

.section .text

glabel func_802410BC_A6514C
/* A6514C 802410BC 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* A65150 802410C0 AFB50044 */  sw        $s5, 0x44($sp)
/* A65154 802410C4 0080A82D */  daddu     $s5, $a0, $zero
/* A65158 802410C8 AFBF0048 */  sw        $ra, 0x48($sp)
/* A6515C 802410CC AFB40040 */  sw        $s4, 0x40($sp)
/* A65160 802410D0 AFB3003C */  sw        $s3, 0x3c($sp)
/* A65164 802410D4 AFB20038 */  sw        $s2, 0x38($sp)
/* A65168 802410D8 AFB10034 */  sw        $s1, 0x34($sp)
/* A6516C 802410DC AFB00030 */  sw        $s0, 0x30($sp)
/* A65170 802410E0 8EB10148 */  lw        $s1, 0x148($s5)
/* A65174 802410E4 86240008 */  lh        $a0, 8($s1)
/* A65178 802410E8 0C00EABB */  jal       get_npc_unsafe
/* A6517C 802410EC 00A0802D */   daddu    $s0, $a1, $zero
/* A65180 802410F0 8EA3000C */  lw        $v1, 0xc($s5)
/* A65184 802410F4 02A0202D */  daddu     $a0, $s5, $zero
/* A65188 802410F8 8C650000 */  lw        $a1, ($v1)
/* A6518C 802410FC 0C0B1EAF */  jal       evt_get_variable
/* A65190 80241100 0040902D */   daddu    $s2, $v0, $zero
/* A65194 80241104 AFA00010 */  sw        $zero, 0x10($sp)
/* A65198 80241108 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A6519C 8024110C 8C630030 */  lw        $v1, 0x30($v1)
/* A651A0 80241110 AFA30014 */  sw        $v1, 0x14($sp)
/* A651A4 80241114 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A651A8 80241118 8C63001C */  lw        $v1, 0x1c($v1)
/* A651AC 8024111C AFA30018 */  sw        $v1, 0x18($sp)
/* A651B0 80241120 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A651B4 80241124 8C630024 */  lw        $v1, 0x24($v1)
/* A651B8 80241128 AFA3001C */  sw        $v1, 0x1c($sp)
/* A651BC 8024112C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A651C0 80241130 8C630028 */  lw        $v1, 0x28($v1)
/* A651C4 80241134 27B40010 */  addiu     $s4, $sp, 0x10
/* A651C8 80241138 AFA30020 */  sw        $v1, 0x20($sp)
/* A651CC 8024113C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A651D0 80241140 3C0142C8 */  lui       $at, 0x42c8
/* A651D4 80241144 44810000 */  mtc1      $at, $f0
/* A651D8 80241148 8C63002C */  lw        $v1, 0x2c($v1)
/* A651DC 8024114C 0040982D */  daddu     $s3, $v0, $zero
/* A651E0 80241150 E7A00028 */  swc1      $f0, 0x28($sp)
/* A651E4 80241154 A7A0002C */  sh        $zero, 0x2c($sp)
/* A651E8 80241158 16000005 */  bnez      $s0, .L80241170
/* A651EC 8024115C AFA30024 */   sw       $v1, 0x24($sp)
/* A651F0 80241160 8E2200B0 */  lw        $v0, 0xb0($s1)
/* A651F4 80241164 30420004 */  andi      $v0, $v0, 4
/* A651F8 80241168 1040001E */  beqz      $v0, .L802411E4
/* A651FC 8024116C 00000000 */   nop
.L80241170:
/* A65200 80241170 8E430000 */  lw        $v1, ($s2)
/* A65204 80241174 2402F7FF */  addiu     $v0, $zero, -0x801
/* A65208 80241178 00621824 */  and       $v1, $v1, $v0
/* A6520C 8024117C 8E2200CC */  lw        $v0, 0xcc($s1)
/* A65210 80241180 3C040020 */  lui       $a0, 0x20
/* A65214 80241184 8C420000 */  lw        $v0, ($v0)
/* A65218 80241188 00641825 */  or        $v1, $v1, $a0
/* A6521C 8024118C AE430000 */  sw        $v1, ($s2)
/* A65220 80241190 AE420028 */  sw        $v0, 0x28($s2)
/* A65224 80241194 8E220000 */  lw        $v0, ($s1)
/* A65228 80241198 00441025 */  or        $v0, $v0, $a0
/* A6522C 8024119C AE220000 */  sw        $v0, ($s1)
/* A65230 802411A0 A640008E */  sh        $zero, 0x8e($s2)
/* A65234 802411A4 8E2300B0 */  lw        $v1, 0xb0($s1)
/* A65238 802411A8 30620004 */  andi      $v0, $v1, 4
/* A6523C 802411AC 1040000C */  beqz      $v0, .L802411E0
/* A65240 802411B0 2402FFFB */   addiu    $v0, $zero, -5
/* A65244 802411B4 3C013F80 */  lui       $at, 0x3f80
/* A65248 802411B8 44810000 */  mtc1      $at, $f0
/* A6524C 802411BC 00621024 */  and       $v0, $v1, $v0
/* A65250 802411C0 AE2200B0 */  sw        $v0, 0xb0($s1)
/* A65254 802411C4 240200FF */  addiu     $v0, $zero, 0xff
/* A65258 802411C8 A24200AC */  sb        $v0, 0xac($s2)
/* A6525C 802411CC 24020014 */  addiu     $v0, $zero, 0x14
/* A65260 802411D0 A642008E */  sh        $v0, 0x8e($s2)
/* A65264 802411D4 E6400054 */  swc1      $f0, 0x54($s2)
/* A65268 802411D8 E6400058 */  swc1      $f0, 0x58($s2)
/* A6526C 802411DC E640005C */  swc1      $f0, 0x5c($s2)
.L802411E0:
/* A65270 802411E0 AEA00070 */  sw        $zero, 0x70($s5)
.L802411E4:
/* A65274 802411E4 8EA30070 */  lw        $v1, 0x70($s5)
/* A65278 802411E8 2C620019 */  sltiu     $v0, $v1, 0x19
/* A6527C 802411EC 10400044 */  beqz      $v0, L80241300_A65390
/* A65280 802411F0 00031080 */   sll      $v0, $v1, 2
/* A65284 802411F4 3C018024 */  lui       $at, %hi(jtbl_80242FA0_A67030)
/* A65288 802411F8 00220821 */  addu      $at, $at, $v0
/* A6528C 802411FC 8C222FA0 */  lw        $v0, %lo(jtbl_80242FA0_A67030)($at)
/* A65290 80241200 00400008 */  jr        $v0
/* A65294 80241204 00000000 */   nop
glabel L80241208_A65298
/* A65298 80241208 02A0202D */  daddu     $a0, $s5, $zero
/* A6529C 8024120C 0260282D */  daddu     $a1, $s3, $zero
/* A652A0 80241210 0C0901CC */  jal       func_80240730_A647C0
/* A652A4 80241214 0280302D */   daddu    $a2, $s4, $zero
/* A652A8 80241218 8EA30070 */  lw        $v1, 0x70($s5)
/* A652AC 8024121C 24020001 */  addiu     $v0, $zero, 1
/* A652B0 80241220 14620037 */  bne       $v1, $v0, L80241300_A65390
/* A652B4 80241224 00000000 */   nop
glabel L80241228_A652B8
/* A652B8 80241228 02A0202D */  daddu     $a0, $s5, $zero
/* A652BC 8024122C 0260282D */  daddu     $a1, $s3, $zero
/* A652C0 80241230 0C0901E9 */  jal       func_802407A4_A64834
/* A652C4 80241234 0280302D */   daddu    $a2, $s4, $zero
/* A652C8 80241238 080904C0 */  j         L80241300_A65390
/* A652CC 8024123C 00000000 */   nop
glabel L80241240_A652D0
/* A652D0 80241240 02A0202D */  daddu     $a0, $s5, $zero
/* A652D4 80241244 0260282D */  daddu     $a1, $s3, $zero
/* A652D8 80241248 0C090234 */  jal       func_802408D0_A64960
/* A652DC 8024124C 0280302D */   daddu    $a2, $s4, $zero
glabel L80241250_A652E0
/* A652E0 80241250 02A0202D */  daddu     $a0, $s5, $zero
/* A652E4 80241254 0260282D */  daddu     $a1, $s3, $zero
/* A652E8 80241258 0C09025C */  jal       func_80240970_A64A00
/* A652EC 8024125C 0280302D */   daddu    $a2, $s4, $zero
/* A652F0 80241260 080904C0 */  j         L80241300_A65390
/* A652F4 80241264 00000000 */   nop
glabel L80241268_A652F8
/* A652F8 80241268 02A0202D */  daddu     $a0, $s5, $zero
/* A652FC 8024126C 0260282D */  daddu     $a1, $s3, $zero
/* A65300 80241270 0C090275 */  jal       func_802409D4_A64A64
/* A65304 80241274 0280302D */   daddu    $a2, $s4, $zero
glabel L80241278_A65308
/* A65308 80241278 02A0202D */  daddu     $a0, $s5, $zero
/* A6530C 8024127C 0260282D */  daddu     $a1, $s3, $zero
/* A65310 80241280 0C0902C5 */  jal       func_80240B14_A64BA4
/* A65314 80241284 0280302D */   daddu    $a2, $s4, $zero
/* A65318 80241288 080904C0 */  j         L80241300_A65390
/* A6531C 8024128C 00000000 */   nop
glabel L80241290_A65320
/* A65320 80241290 02A0202D */  daddu     $a0, $s5, $zero
/* A65324 80241294 0260282D */  daddu     $a1, $s3, $zero
/* A65328 80241298 0C09032E */  jal       func_80240CB8_A64D48
/* A6532C 8024129C 0280302D */   daddu    $a2, $s4, $zero
/* A65330 802412A0 080904C0 */  j         L80241300_A65390
/* A65334 802412A4 00000000 */   nop
glabel L802412A8_A65338
/* A65338 802412A8 02A0202D */  daddu     $a0, $s5, $zero
/* A6533C 802412AC 0260282D */  daddu     $a1, $s3, $zero
/* A65340 802412B0 0C09033D */  jal       func_80240CF4_A64D84
/* A65344 802412B4 0280302D */   daddu    $a2, $s4, $zero
/* A65348 802412B8 080904C0 */  j         L80241300_A65390
/* A6534C 802412BC 00000000 */   nop
glabel L802412C0_A65350
/* A65350 802412C0 02A0202D */  daddu     $a0, $s5, $zero
/* A65354 802412C4 0260282D */  daddu     $a1, $s3, $zero
/* A65358 802412C8 0C0903AD */  jal       func_80240EB4_A64F44
/* A6535C 802412CC 0280302D */   daddu    $a2, $s4, $zero
/* A65360 802412D0 080904C0 */  j         L80241300_A65390
/* A65364 802412D4 00000000 */   nop
glabel L802412D8_A65368
/* A65368 802412D8 02A0202D */  daddu     $a0, $s5, $zero
/* A6536C 802412DC 0260282D */  daddu     $a1, $s3, $zero
/* A65370 802412E0 0C0903C8 */  jal       func_80240F20_A64FB0
/* A65374 802412E4 0280302D */   daddu    $a2, $s4, $zero
/* A65378 802412E8 080904C0 */  j         L80241300_A65390
/* A6537C 802412EC 00000000 */   nop
glabel L802412F0_A65380
/* A65380 802412F0 02A0202D */  daddu     $a0, $s5, $zero
/* A65384 802412F4 0260282D */  daddu     $a1, $s3, $zero
/* A65388 802412F8 0C090415 */  jal       func_80241054_A650E4
/* A6538C 802412FC 0280302D */   daddu    $a2, $s4, $zero
glabel L80241300_A65390
/* A65390 80241300 8FBF0048 */  lw        $ra, 0x48($sp)
/* A65394 80241304 8FB50044 */  lw        $s5, 0x44($sp)
/* A65398 80241308 8FB40040 */  lw        $s4, 0x40($sp)
/* A6539C 8024130C 8FB3003C */  lw        $s3, 0x3c($sp)
/* A653A0 80241310 8FB20038 */  lw        $s2, 0x38($sp)
/* A653A4 80241314 8FB10034 */  lw        $s1, 0x34($sp)
/* A653A8 80241318 8FB00030 */  lw        $s0, 0x30($sp)
/* A653AC 8024131C 0000102D */  daddu     $v0, $zero, $zero
/* A653B0 80241320 03E00008 */  jr        $ra
/* A653B4 80241324 27BD0050 */   addiu    $sp, $sp, 0x50
