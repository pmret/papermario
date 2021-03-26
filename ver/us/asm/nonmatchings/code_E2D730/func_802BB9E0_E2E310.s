.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BB9E0_E2E310
/* E2E310 802BB9E0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* E2E314 802BB9E4 AFB20028 */  sw        $s2, 0x28($sp)
/* E2E318 802BB9E8 0080902D */  daddu     $s2, $a0, $zero
/* E2E31C 802BB9EC AFBF002C */  sw        $ra, 0x2c($sp)
/* E2E320 802BB9F0 AFB10024 */  sw        $s1, 0x24($sp)
/* E2E324 802BB9F4 AFB00020 */  sw        $s0, 0x20($sp)
/* E2E328 802BB9F8 8E500040 */  lw        $s0, 0x40($s2)
/* E2E32C 802BB9FC 3C048011 */  lui       $a0, %hi(D_8010EBB0)
/* E2E330 802BBA00 2484EBB0 */  addiu     $a0, $a0, %lo(D_8010EBB0)
/* E2E334 802BBA04 92030000 */  lbu       $v1, ($s0)
/* E2E338 802BBA08 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* E2E33C 802BBA0C 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* E2E340 802BBA10 2C620007 */  sltiu     $v0, $v1, 7
/* E2E344 802BBA14 104000A2 */  beqz      $v0, .L802BBCA0
/* E2E348 802BBA18 00031080 */   sll      $v0, $v1, 2
/* E2E34C 802BBA1C 3C01802C */  lui       $at, %hi(jtbl_802BCDE8_E2F718)
/* E2E350 802BBA20 00220821 */  addu      $at, $at, $v0
/* E2E354 802BBA24 8C22CDE8 */  lw        $v0, %lo(jtbl_802BCDE8_E2F718)($at)
/* E2E358 802BBA28 00400008 */  jr        $v0
/* E2E35C 802BBA2C 00000000 */   nop
glabel L802BBA30_E2E360
/* E2E360 802BBA30 92420006 */  lbu       $v0, 6($s2)
/* E2E364 802BBA34 30420001 */  andi      $v0, $v0, 1
/* E2E368 802BBA38 50400099 */  beql      $v0, $zero, .L802BBCA0
/* E2E36C 802BBA3C A2000001 */   sb       $zero, 1($s0)
/* E2E370 802BBA40 80820003 */  lb        $v0, 3($a0)
/* E2E374 802BBA44 10400004 */  beqz      $v0, .L802BBA58
/* E2E378 802BBA48 00000000 */   nop
/* E2E37C 802BBA4C 8E220004 */  lw        $v0, 4($s1)
/* E2E380 802BBA50 34420004 */  ori       $v0, $v0, 4
/* E2E384 802BBA54 AE220004 */  sw        $v0, 4($s1)
.L802BBA58:
/* E2E388 802BBA58 0C03BCC0 */  jal       func_800EF300
/* E2E38C 802BBA5C 00000000 */   nop
/* E2E390 802BBA60 8E220004 */  lw        $v0, 4($s1)
/* E2E394 802BBA64 3C030004 */  lui       $v1, 4
/* E2E398 802BBA68 00431025 */  or        $v0, $v0, $v1
/* E2E39C 802BBA6C AE220004 */  sw        $v0, 4($s1)
/* E2E3A0 802BBA70 24020004 */  addiu     $v0, $zero, 4
/* E2E3A4 802BBA74 A6020002 */  sh        $v0, 2($s0)
/* E2E3A8 802BBA78 92020001 */  lbu       $v0, 1($s0)
/* E2E3AC 802BBA7C 92030000 */  lbu       $v1, ($s0)
/* E2E3B0 802BBA80 24420001 */  addiu     $v0, $v0, 1
/* E2E3B4 802BBA84 24630001 */  addiu     $v1, $v1, 1
/* E2E3B8 802BBA88 A2020001 */  sb        $v0, 1($s0)
/* E2E3BC 802BBA8C 0C03805E */  jal       disable_player_input
/* E2E3C0 802BBA90 A2030000 */   sb       $v1, ($s0)
/* E2E3C4 802BBA94 0C039769 */  jal       set_action_state
/* E2E3C8 802BBA98 0000202D */   daddu    $a0, $zero, $zero
/* E2E3CC 802BBA9C 86440014 */  lh        $a0, 0x14($s2)
/* E2E3D0 802BBAA0 3C050000 */  lui       $a1, 0
/* E2E3D4 802BBAA4 24A50214 */  addiu     $a1, $a1, 0x214
/* E2E3D8 802BBAA8 0C048052 */  jal       play_model_animation
/* E2E3DC 802BBAAC 00000000 */   nop
/* E2E3E0 802BBAB0 0C05272D */  jal       sfx_play_sound
/* E2E3E4 802BBAB4 240400F2 */   addiu    $a0, $zero, 0xf2
/* E2E3E8 802BBAB8 0C0AEE35 */  jal       func_802BB8D4_E2E204
/* E2E3EC 802BBABC 0240202D */   daddu    $a0, $s2, $zero
/* E2E3F0 802BBAC0 080AEF28 */  j         .L802BBCA0
/* E2E3F4 802BBAC4 00000000 */   nop
glabel L802BBAC8_E2E3F8
/* E2E3F8 802BBAC8 8E220004 */  lw        $v0, 4($s1)
/* E2E3FC 802BBACC 3C030004 */  lui       $v1, 4
/* E2E400 802BBAD0 00431025 */  or        $v0, $v0, $v1
/* E2E404 802BBAD4 AE220004 */  sw        $v0, 4($s1)
/* E2E408 802BBAD8 96020002 */  lhu       $v0, 2($s0)
/* E2E40C 802BBADC 2442FFFF */  addiu     $v0, $v0, -1
/* E2E410 802BBAE0 A6020002 */  sh        $v0, 2($s0)
/* E2E414 802BBAE4 00021400 */  sll       $v0, $v0, 0x10
/* E2E418 802BBAE8 14400012 */  bnez      $v0, .L802BBB34
/* E2E41C 802BBAEC 24040080 */   addiu    $a0, $zero, 0x80
/* E2E420 802BBAF0 0C00A3C2 */  jal       start_rumble
/* E2E424 802BBAF4 2405000A */   addiu    $a1, $zero, 0xa
/* E2E428 802BBAF8 92020000 */  lbu       $v0, ($s0)
/* E2E42C 802BBAFC 3C0142A0 */  lui       $at, 0x42a0
/* E2E430 802BBB00 44810000 */  mtc1      $at, $f0
/* E2E434 802BBB04 2403001E */  addiu     $v1, $zero, 0x1e
/* E2E438 802BBB08 A6030002 */  sh        $v1, 2($s0)
/* E2E43C 802BBB0C 24420001 */  addiu     $v0, $v0, 1
/* E2E440 802BBB10 A2020000 */  sb        $v0, ($s0)
/* E2E444 802BBB14 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* E2E448 802BBB18 8E220000 */  lw        $v0, ($s1)
/* E2E44C 802BBB1C 3C030010 */  lui       $v1, 0x10
/* E2E450 802BBB20 E62000A8 */  swc1      $f0, 0xa8($s1)
/* E2E454 802BBB24 00431025 */  or        $v0, $v0, $v1
/* E2E458 802BBB28 AE220000 */  sw        $v0, ($s1)
/* E2E45C 802BBB2C 3C01802C */  lui       $at, %hi(D_802BCE20)
/* E2E460 802BBB30 E422CE20 */  swc1      $f2, %lo(D_802BCE20)($at)
.L802BBB34:
/* E2E464 802BBB34 0C0AEE63 */  jal       func_802BB98C_E2E2BC
/* E2E468 802BBB38 0240202D */   daddu    $a0, $s2, $zero
/* E2E46C 802BBB3C 080AEF28 */  j         .L802BBCA0
/* E2E470 802BBB40 00000000 */   nop
glabel L802BBB44_E2E474
/* E2E474 802BBB44 96020002 */  lhu       $v0, 2($s0)
/* E2E478 802BBB48 2442FFFF */  addiu     $v0, $v0, -1
/* E2E47C 802BBB4C A6020002 */  sh        $v0, 2($s0)
/* E2E480 802BBB50 00021400 */  sll       $v0, $v0, 0x10
/* E2E484 802BBB54 14400052 */  bnez      $v0, .L802BBCA0
/* E2E488 802BBB58 0000202D */   daddu    $a0, $zero, $zero
/* E2E48C 802BBB5C 2405FFFF */  addiu     $a1, $zero, -1
/* E2E490 802BBB60 0080302D */  daddu     $a2, $a0, $zero
/* E2E494 802BBB64 92020000 */  lbu       $v0, ($s0)
/* E2E498 802BBB68 0080382D */  daddu     $a3, $a0, $zero
/* E2E49C 802BBB6C 24420001 */  addiu     $v0, $v0, 1
/* E2E4A0 802BBB70 A2020000 */  sb        $v0, ($s0)
/* E2E4A4 802BBB74 AFA00010 */  sw        $zero, 0x10($sp)
/* E2E4A8 802BBB78 AFA00014 */  sw        $zero, 0x14($sp)
/* E2E4AC 802BBB7C AFA00018 */  sw        $zero, 0x18($sp)
/* E2E4B0 802BBB80 0C0B77B9 */  jal       func_802DDEE4
/* E2E4B4 802BBB84 AFA0001C */   sw       $zero, 0x1c($sp)
/* E2E4B8 802BBB88 3C040001 */  lui       $a0, 1
/* E2E4BC 802BBB8C 34840002 */  ori       $a0, $a0, 2
/* E2E4C0 802BBB90 24050005 */  addiu     $a1, $zero, 5
/* E2E4C4 802BBB94 24060013 */  addiu     $a2, $zero, 0x13
/* E2E4C8 802BBB98 24070001 */  addiu     $a3, $zero, 1
/* E2E4CC 802BBB9C 00E0102D */  daddu     $v0, $a3, $zero
/* E2E4D0 802BBBA0 AFA20010 */  sw        $v0, 0x10($sp)
/* E2E4D4 802BBBA4 AFA00014 */  sw        $zero, 0x14($sp)
/* E2E4D8 802BBBA8 0C0B77FE */  jal       func_802DDFF8
/* E2E4DC 802BBBAC AFA00018 */   sw       $zero, 0x18($sp)
/* E2E4E0 802BBBB0 080AEF28 */  j         .L802BBCA0
/* E2E4E4 802BBBB4 00000000 */   nop
glabel L802BBBB8_E2E4E8
/* E2E4E8 802BBBB8 92020000 */  lbu       $v0, ($s0)
/* E2E4EC 802BBBBC 080AEF02 */  j         .L802BBC08
/* E2E4F0 802BBBC0 24420001 */   addiu    $v0, $v0, 1
glabel L802BBBC4_E2E4F4
/* E2E4F4 802BBBC4 3C01802C */  lui       $at, %hi(D_802BCE20)
/* E2E4F8 802BBBC8 C420CE20 */  lwc1      $f0, %lo(D_802BCE20)($at)
/* E2E4FC 802BBBCC 44801000 */  mtc1      $zero, $f2
/* E2E500 802BBBD0 3C014387 */  lui       $at, 0x4387
/* E2E504 802BBBD4 44812000 */  mtc1      $at, $f4
/* E2E508 802BBBD8 46020032 */  c.eq.s    $f0, $f2
/* E2E50C 802BBBDC 00000000 */  nop
/* E2E510 802BBBE0 45010004 */  bc1t      .L802BBBF4
/* E2E514 802BBBE4 E62000A8 */   swc1     $f0, 0xa8($s1)
/* E2E518 802BBBE8 3C0142B4 */  lui       $at, 0x42b4
/* E2E51C 802BBBEC 44812000 */  mtc1      $at, $f4
/* E2E520 802BBBF0 00000000 */  nop
.L802BBBF4:
/* E2E524 802BBBF4 E6240080 */  swc1      $f4, 0x80($s1)
/* E2E528 802BBBF8 92020000 */  lbu       $v0, ($s0)
/* E2E52C 802BBBFC 24030050 */  addiu     $v1, $zero, 0x50
/* E2E530 802BBC00 A6030002 */  sh        $v1, 2($s0)
/* E2E534 802BBC04 24420001 */  addiu     $v0, $v0, 1
.L802BBC08:
/* E2E538 802BBC08 080AEF28 */  j         .L802BBCA0
/* E2E53C 802BBC0C A2020000 */   sb       $v0, ($s0)
glabel L802BBC10_E2E540
/* E2E540 802BBC10 96020002 */  lhu       $v0, 2($s0)
/* E2E544 802BBC14 2442FFFF */  addiu     $v0, $v0, -1
/* E2E548 802BBC18 A6020002 */  sh        $v0, 2($s0)
/* E2E54C 802BBC1C 00021400 */  sll       $v0, $v0, 0x10
/* E2E550 802BBC20 1440001F */  bnez      $v0, .L802BBCA0
/* E2E554 802BBC24 0000202D */   daddu    $a0, $zero, $zero
/* E2E558 802BBC28 2405FFFF */  addiu     $a1, $zero, -1
/* E2E55C 802BBC2C 0080302D */  daddu     $a2, $a0, $zero
/* E2E560 802BBC30 92020000 */  lbu       $v0, ($s0)
/* E2E564 802BBC34 0080382D */  daddu     $a3, $a0, $zero
/* E2E568 802BBC38 24420001 */  addiu     $v0, $v0, 1
/* E2E56C 802BBC3C A2020000 */  sb        $v0, ($s0)
/* E2E570 802BBC40 AFA00010 */  sw        $zero, 0x10($sp)
/* E2E574 802BBC44 AFA00014 */  sw        $zero, 0x14($sp)
/* E2E578 802BBC48 AFA00018 */  sw        $zero, 0x18($sp)
/* E2E57C 802BBC4C 0C0B77B9 */  jal       func_802DDEE4
/* E2E580 802BBC50 AFA0001C */   sw       $zero, 0x1c($sp)
/* E2E584 802BBC54 0C038069 */  jal       enable_player_input
/* E2E588 802BBC58 00000000 */   nop
/* E2E58C 802BBC5C 3C03FFEF */  lui       $v1, 0xffef
/* E2E590 802BBC60 8E220000 */  lw        $v0, ($s1)
/* E2E594 802BBC64 3463FFFF */  ori       $v1, $v1, 0xffff
/* E2E598 802BBC68 00431024 */  and       $v0, $v0, $v1
/* E2E59C 802BBC6C 080AEF28 */  j         .L802BBCA0
/* E2E5A0 802BBC70 AE220000 */   sw       $v0, ($s1)
glabel L802BBC74_E2E5A4
/* E2E5A4 802BBC74 92420006 */  lbu       $v0, 6($s2)
/* E2E5A8 802BBC78 30420001 */  andi      $v0, $v0, 1
/* E2E5AC 802BBC7C 14400008 */  bnez      $v0, .L802BBCA0
/* E2E5B0 802BBC80 00000000 */   nop
/* E2E5B4 802BBC84 80820000 */  lb        $v0, ($a0)
/* E2E5B8 802BBC88 14400005 */  bnez      $v0, .L802BBCA0
/* E2E5BC 802BBC8C 00000000 */   nop
/* E2E5C0 802BBC90 0C03BCCA */  jal       enable_partner_ai
/* E2E5C4 802BBC94 A2000000 */   sb       $zero, ($s0)
/* E2E5C8 802BBC98 0C03954C */  jal       func_800E5530
/* E2E5CC 802BBC9C 00000000 */   nop
.L802BBCA0:
/* E2E5D0 802BBCA0 8FBF002C */  lw        $ra, 0x2c($sp)
/* E2E5D4 802BBCA4 8FB20028 */  lw        $s2, 0x28($sp)
/* E2E5D8 802BBCA8 8FB10024 */  lw        $s1, 0x24($sp)
/* E2E5DC 802BBCAC 8FB00020 */  lw        $s0, 0x20($sp)
/* E2E5E0 802BBCB0 03E00008 */  jr        $ra
/* E2E5E4 802BBCB4 27BD0030 */   addiu    $sp, $sp, 0x30
/* E2E5E8 802BBCB8 00000000 */  nop
/* E2E5EC 802BBCBC 00000000 */  nop
