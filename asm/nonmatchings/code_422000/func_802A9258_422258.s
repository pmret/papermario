.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9258_422258
/* 422258 802A9258 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 42225C 802A925C AFB20018 */  sw        $s2, 0x18($sp)
/* 422260 802A9260 0080902D */  daddu     $s2, $a0, $zero
/* 422264 802A9264 AFB10014 */  sw        $s1, 0x14($sp)
/* 422268 802A9268 3C11802A */  lui       $s1, %hi(D_8029FBE0)
/* 42226C 802A926C 2631FBE0 */  addiu     $s1, $s1, %lo(D_8029FBE0)
/* 422270 802A9270 AFB40020 */  sw        $s4, 0x20($sp)
/* 422274 802A9274 0220A02D */  daddu     $s4, $s1, $zero
/* 422278 802A9278 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 42227C 802A927C 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 422280 802A9280 AFB3001C */  sw        $s3, 0x1c($sp)
/* 422284 802A9284 AFBF0024 */  sw        $ra, 0x24($sp)
/* 422288 802A9288 AFB00010 */  sw        $s0, 0x10($sp)
/* 42228C 802A928C 80620083 */  lb        $v0, 0x83($v1)
/* 422290 802A9290 8E50000C */  lw        $s0, 0xc($s2)
/* 422294 802A9294 14400005 */  bnez      $v0, .L802A92AC
/* 422298 802A9298 0060982D */   daddu    $s3, $v1, $zero
/* 42229C 802A929C 24020002 */  addiu     $v0, $zero, 2
/* 4222A0 802A92A0 A0600081 */  sb        $zero, 0x81($v1)
/* 4222A4 802A92A4 080AA4D3 */  j         .L802A934C
/* 4222A8 802A92A8 A0600084 */   sb       $zero, 0x84($v1)
.L802A92AC:
/* 4222AC 802A92AC 0C09A216 */  jal       func_80268858
/* 4222B0 802A92B0 00000000 */   nop      
/* 4222B4 802A92B4 8E050000 */  lw        $a1, ($s0)
/* 4222B8 802A92B8 26100004 */  addiu     $s0, $s0, 4
/* 4222BC 802A92BC 0C0B1EAF */  jal       get_variable
/* 4222C0 802A92C0 0240202D */   daddu    $a0, $s2, $zero
/* 4222C4 802A92C4 A622004E */  sh        $v0, 0x4e($s1)
/* 4222C8 802A92C8 8E050000 */  lw        $a1, ($s0)
/* 4222CC 802A92CC 26100004 */  addiu     $s0, $s0, 4
/* 4222D0 802A92D0 0C0B1EAF */  jal       get_variable
/* 4222D4 802A92D4 0240202D */   daddu    $a0, $s2, $zero
/* 4222D8 802A92D8 A6220052 */  sh        $v0, 0x52($s1)
/* 4222DC 802A92DC 8E050000 */  lw        $a1, ($s0)
/* 4222E0 802A92E0 0C0B1EAF */  jal       get_variable
/* 4222E4 802A92E4 0240202D */   daddu    $a0, $s2, $zero
/* 4222E8 802A92E8 00022400 */  sll       $a0, $v0, 0x10
/* 4222EC 802A92EC 00042403 */  sra       $a0, $a0, 0x10
/* 4222F0 802A92F0 0C09A089 */  jal       func_80268224
/* 4222F4 802A92F4 A6220050 */   sh       $v0, 0x50($s1)
/* 4222F8 802A92F8 8623004E */  lh        $v1, 0x4e($s1)
/* 4222FC 802A92FC A6220050 */  sh        $v0, 0x50($s1)
/* 422300 802A9300 24020001 */  addiu     $v0, $zero, 1
/* 422304 802A9304 A2200060 */  sb        $zero, 0x60($s1)
/* 422308 802A9308 04610003 */  bgez      $v1, .L802A9318
/* 42230C 802A930C A2220062 */   sb       $v0, 0x62($s1)
/* 422310 802A9310 A620004E */  sh        $zero, 0x4e($s1)
/* 422314 802A9314 A2200062 */  sb        $zero, 0x62($s1)
.L802A9318:
/* 422318 802A9318 3C02FFFF */  lui       $v0, 0xffff
/* 42231C 802A931C 34427FFF */  ori       $v0, $v0, 0x7fff
/* 422320 802A9320 A280005F */  sb        $zero, 0x5f($s4)
/* 422324 802A9324 8E630000 */  lw        $v1, ($s3)
/* 422328 802A9328 2404000A */  addiu     $a0, $zero, 0xa
/* 42232C 802A932C A2600081 */  sb        $zero, 0x81($s3)
/* 422330 802A9330 A2600084 */  sb        $zero, 0x84($s3)
/* 422334 802A9334 A2600086 */  sb        $zero, 0x86($s3)
/* 422338 802A9338 A684004C */  sh        $a0, 0x4c($s4)
/* 42233C 802A933C 00621824 */  and       $v1, $v1, $v0
/* 422340 802A9340 0C09A446 */  jal       func_80269118
/* 422344 802A9344 AE630000 */   sw       $v1, ($s3)
/* 422348 802A9348 24020002 */  addiu     $v0, $zero, 2
.L802A934C:
/* 42234C 802A934C 8FBF0024 */  lw        $ra, 0x24($sp)
/* 422350 802A9350 8FB40020 */  lw        $s4, 0x20($sp)
/* 422354 802A9354 8FB3001C */  lw        $s3, 0x1c($sp)
/* 422358 802A9358 8FB20018 */  lw        $s2, 0x18($sp)
/* 42235C 802A935C 8FB10014 */  lw        $s1, 0x14($sp)
/* 422360 802A9360 8FB00010 */  lw        $s0, 0x10($sp)
/* 422364 802A9364 03E00008 */  jr        $ra
/* 422368 802A9368 27BD0028 */   addiu    $sp, $sp, 0x28
