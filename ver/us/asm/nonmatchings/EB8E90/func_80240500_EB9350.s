.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240500_EB9350
/* EB9350 80240500 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* EB9354 80240504 AFB40040 */  sw        $s4, 0x40($sp)
/* EB9358 80240508 0080A02D */  daddu     $s4, $a0, $zero
/* EB935C 8024050C AFBF0044 */  sw        $ra, 0x44($sp)
/* EB9360 80240510 AFB3003C */  sw        $s3, 0x3c($sp)
/* EB9364 80240514 AFB20038 */  sw        $s2, 0x38($sp)
/* EB9368 80240518 AFB10034 */  sw        $s1, 0x34($sp)
/* EB936C 8024051C AFB00030 */  sw        $s0, 0x30($sp)
/* EB9370 80240520 8E910148 */  lw        $s1, 0x148($s4)
/* EB9374 80240524 00A0902D */  daddu     $s2, $a1, $zero
/* EB9378 80240528 86240008 */  lh        $a0, 8($s1)
/* EB937C 8024052C 0C00F92F */  jal       dead_get_npc_unsafe
/* EB9380 80240530 00C0982D */   daddu    $s3, $a2, $zero
/* EB9384 80240534 8E430014 */  lw        $v1, 0x14($s2)
/* EB9388 80240538 04600031 */  bltz      $v1, .L80240600
/* EB938C 8024053C 0040802D */   daddu    $s0, $v0, $zero
/* EB9390 80240540 0260202D */  daddu     $a0, $s3, $zero
/* EB9394 80240544 AFA00010 */  sw        $zero, 0x10($sp)
/* EB9398 80240548 8E460024 */  lw        $a2, 0x24($s2)
/* EB939C 8024054C 8E470028 */  lw        $a3, 0x28($s2)
/* EB93A0 80240550 0C013469 */  jal       func_8004D1A4
/* EB93A4 80240554 0220282D */   daddu    $a1, $s1, $zero
/* EB93A8 80240558 10400029 */  beqz      $v0, .L80240600
/* EB93AC 8024055C 0000202D */   daddu    $a0, $zero, $zero
/* EB93B0 80240560 0200282D */  daddu     $a1, $s0, $zero
/* EB93B4 80240564 0000302D */  daddu     $a2, $zero, $zero
/* EB93B8 80240568 860300A8 */  lh        $v1, 0xa8($s0)
/* EB93BC 8024056C 3C013F80 */  lui       $at, 0x3f80
/* EB93C0 80240570 44810000 */  mtc1      $at, $f0
/* EB93C4 80240574 3C014000 */  lui       $at, 0x4000
/* EB93C8 80240578 44811000 */  mtc1      $at, $f2
/* EB93CC 8024057C 3C01C1A0 */  lui       $at, 0xc1a0
/* EB93D0 80240580 44812000 */  mtc1      $at, $f4
/* EB93D4 80240584 2402000F */  addiu     $v0, $zero, 0xf
/* EB93D8 80240588 AFA2001C */  sw        $v0, 0x1c($sp)
/* EB93DC 8024058C 44833000 */  mtc1      $v1, $f6
/* EB93E0 80240590 00000000 */  nop
/* EB93E4 80240594 468031A0 */  cvt.s.w   $f6, $f6
/* EB93E8 80240598 44073000 */  mfc1      $a3, $f6
/* EB93EC 8024059C 27A20028 */  addiu     $v0, $sp, 0x28
/* EB93F0 802405A0 AFA20020 */  sw        $v0, 0x20($sp)
/* EB93F4 802405A4 E7A00010 */  swc1      $f0, 0x10($sp)
/* EB93F8 802405A8 E7A20014 */  swc1      $f2, 0x14($sp)
/* EB93FC 802405AC 0C01D444 */  jal       dead_fx_emote
/* EB9400 802405B0 E7A40018 */   swc1     $f4, 0x18($sp)
/* EB9404 802405B4 3C028010 */  lui       $v0, %hi(dead_gPlayerStatusPtr)
/* EB9408 802405B8 8C42FC90 */  lw        $v0, %lo(dead_gPlayerStatusPtr)($v0)
/* EB940C 802405BC C60C0038 */  lwc1      $f12, 0x38($s0)
/* EB9410 802405C0 C60E0040 */  lwc1      $f14, 0x40($s0)
/* EB9414 802405C4 8C460028 */  lw        $a2, 0x28($v0)
/* EB9418 802405C8 0C00ABDC */  jal       fio_validate_header_checksums
/* EB941C 802405CC 8C470030 */   lw       $a3, 0x30($v0)
/* EB9420 802405D0 0200202D */  daddu     $a0, $s0, $zero
/* EB9424 802405D4 240502F4 */  addiu     $a1, $zero, 0x2f4
/* EB9428 802405D8 3C060020 */  lui       $a2, 0x20
/* EB942C 802405DC 0C013600 */  jal       dead_ai_enemy_play_sound
/* EB9430 802405E0 E480000C */   swc1     $f0, 0xc($a0)
/* EB9434 802405E4 8E220018 */  lw        $v0, 0x18($s1)
/* EB9438 802405E8 9442002A */  lhu       $v0, 0x2a($v0)
/* EB943C 802405EC 30420001 */  andi      $v0, $v0, 1
/* EB9440 802405F0 14400029 */  bnez      $v0, .L80240698
/* EB9444 802405F4 2402000A */   addiu    $v0, $zero, 0xa
/* EB9448 802405F8 080901A6 */  j         .L80240698
/* EB944C 802405FC 2402000C */   addiu    $v0, $zero, 0xc
.L80240600:
/* EB9450 80240600 8602008C */  lh        $v0, 0x8c($s0)
/* EB9454 80240604 14400025 */  bnez      $v0, .L8024069C
/* EB9458 80240608 00000000 */   nop
/* EB945C 8024060C 9602008E */  lhu       $v0, 0x8e($s0)
/* EB9460 80240610 2442FFFF */  addiu     $v0, $v0, -1
/* EB9464 80240614 A602008E */  sh        $v0, 0x8e($s0)
/* EB9468 80240618 00021400 */  sll       $v0, $v0, 0x10
/* EB946C 8024061C 1440001F */  bnez      $v0, .L8024069C
/* EB9470 80240620 00000000 */   nop
/* EB9474 80240624 8E820074 */  lw        $v0, 0x74($s4)
/* EB9478 80240628 2442FFFF */  addiu     $v0, $v0, -1
/* EB947C 8024062C 10400019 */  beqz      $v0, .L80240694
/* EB9480 80240630 AE820074 */   sw       $v0, 0x74($s4)
/* EB9484 80240634 8E220018 */  lw        $v0, 0x18($s1)
/* EB9488 80240638 9442002A */  lhu       $v0, 0x2a($v0)
/* EB948C 8024063C 30420010 */  andi      $v0, $v0, 0x10
/* EB9490 80240640 14400007 */  bnez      $v0, .L80240660
/* EB9494 80240644 00000000 */   nop
/* EB9498 80240648 C600000C */  lwc1      $f0, 0xc($s0)
/* EB949C 8024064C 3C014334 */  lui       $at, 0x4334
/* EB94A0 80240650 44816000 */  mtc1      $at, $f12
/* EB94A4 80240654 0C00AB85 */  jal       dead_clamp_angle
/* EB94A8 80240658 460C0300 */   add.s    $f12, $f0, $f12
/* EB94AC 8024065C E600000C */  swc1      $f0, 0xc($s0)
.L80240660:
/* EB94B0 80240660 8E440008 */  lw        $a0, 8($s2)
/* EB94B4 80240664 000417C2 */  srl       $v0, $a0, 0x1f
/* EB94B8 80240668 00822021 */  addu      $a0, $a0, $v0
/* EB94BC 8024066C 00042043 */  sra       $a0, $a0, 1
/* EB94C0 80240670 0C00AB3B */  jal       dead_rand_int
/* EB94C4 80240674 24840001 */   addiu    $a0, $a0, 1
/* EB94C8 80240678 8E430008 */  lw        $v1, 8($s2)
/* EB94CC 8024067C 000327C2 */  srl       $a0, $v1, 0x1f
/* EB94D0 80240680 00641821 */  addu      $v1, $v1, $a0
/* EB94D4 80240684 00031843 */  sra       $v1, $v1, 1
/* EB94D8 80240688 00621821 */  addu      $v1, $v1, $v0
/* EB94DC 8024068C 080901A7 */  j         .L8024069C
/* EB94E0 80240690 A603008E */   sh       $v1, 0x8e($s0)
.L80240694:
/* EB94E4 80240694 24020004 */  addiu     $v0, $zero, 4
.L80240698:
/* EB94E8 80240698 AE820070 */  sw        $v0, 0x70($s4)
.L8024069C:
/* EB94EC 8024069C 8FBF0044 */  lw        $ra, 0x44($sp)
/* EB94F0 802406A0 8FB40040 */  lw        $s4, 0x40($sp)
/* EB94F4 802406A4 8FB3003C */  lw        $s3, 0x3c($sp)
/* EB94F8 802406A8 8FB20038 */  lw        $s2, 0x38($sp)
/* EB94FC 802406AC 8FB10034 */  lw        $s1, 0x34($sp)
/* EB9500 802406B0 8FB00030 */  lw        $s0, 0x30($sp)
/* EB9504 802406B4 03E00008 */  jr        $ra
/* EB9508 802406B8 27BD0048 */   addiu    $sp, $sp, 0x48
