.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404C0_BDF250
/* BDF250 802404C0 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* BDF254 802404C4 AFB40040 */  sw        $s4, 0x40($sp)
/* BDF258 802404C8 0080A02D */  daddu     $s4, $a0, $zero
/* BDF25C 802404CC AFBF0044 */  sw        $ra, 0x44($sp)
/* BDF260 802404D0 AFB3003C */  sw        $s3, 0x3c($sp)
/* BDF264 802404D4 AFB20038 */  sw        $s2, 0x38($sp)
/* BDF268 802404D8 AFB10034 */  sw        $s1, 0x34($sp)
/* BDF26C 802404DC AFB00030 */  sw        $s0, 0x30($sp)
/* BDF270 802404E0 8E910148 */  lw        $s1, 0x148($s4)
/* BDF274 802404E4 00A0902D */  daddu     $s2, $a1, $zero
/* BDF278 802404E8 86240008 */  lh        $a0, 8($s1)
/* BDF27C 802404EC 0C00EABB */  jal       get_npc_unsafe
/* BDF280 802404F0 00C0982D */   daddu    $s3, $a2, $zero
/* BDF284 802404F4 8E430014 */  lw        $v1, 0x14($s2)
/* BDF288 802404F8 04600031 */  bltz      $v1, .L802405C0
/* BDF28C 802404FC 0040802D */   daddu    $s0, $v0, $zero
/* BDF290 80240500 0260202D */  daddu     $a0, $s3, $zero
/* BDF294 80240504 AFA00010 */  sw        $zero, 0x10($sp)
/* BDF298 80240508 8E460024 */  lw        $a2, 0x24($s2)
/* BDF29C 8024050C 8E470028 */  lw        $a3, 0x28($s2)
/* BDF2A0 80240510 0C01242D */  jal       func_800490B4
/* BDF2A4 80240514 0220282D */   daddu    $a1, $s1, $zero
/* BDF2A8 80240518 10400029 */  beqz      $v0, .L802405C0
/* BDF2AC 8024051C 0000202D */   daddu    $a0, $zero, $zero
/* BDF2B0 80240520 0200282D */  daddu     $a1, $s0, $zero
/* BDF2B4 80240524 0000302D */  daddu     $a2, $zero, $zero
/* BDF2B8 80240528 860300A8 */  lh        $v1, 0xa8($s0)
/* BDF2BC 8024052C 3C013F80 */  lui       $at, 0x3f80
/* BDF2C0 80240530 44810000 */  mtc1      $at, $f0
/* BDF2C4 80240534 3C014000 */  lui       $at, 0x4000
/* BDF2C8 80240538 44811000 */  mtc1      $at, $f2
/* BDF2CC 8024053C 3C01C1A0 */  lui       $at, 0xc1a0
/* BDF2D0 80240540 44812000 */  mtc1      $at, $f4
/* BDF2D4 80240544 2402000F */  addiu     $v0, $zero, 0xf
/* BDF2D8 80240548 AFA2001C */  sw        $v0, 0x1c($sp)
/* BDF2DC 8024054C 44833000 */  mtc1      $v1, $f6
/* BDF2E0 80240550 00000000 */  nop       
/* BDF2E4 80240554 468031A0 */  cvt.s.w   $f6, $f6
/* BDF2E8 80240558 44073000 */  mfc1      $a3, $f6
/* BDF2EC 8024055C 27A20028 */  addiu     $v0, $sp, 0x28
/* BDF2F0 80240560 AFA20020 */  sw        $v0, 0x20($sp)
/* BDF2F4 80240564 E7A00010 */  swc1      $f0, 0x10($sp)
/* BDF2F8 80240568 E7A20014 */  swc1      $f2, 0x14($sp)
/* BDF2FC 8024056C 0C01BFA4 */  jal       fx_emote
/* BDF300 80240570 E7A40018 */   swc1     $f4, 0x18($sp)
/* BDF304 80240574 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* BDF308 80240578 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* BDF30C 8024057C C60C0038 */  lwc1      $f12, 0x38($s0)
/* BDF310 80240580 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BDF314 80240584 8C460028 */  lw        $a2, 0x28($v0)
/* BDF318 80240588 0C00A720 */  jal       atan2
/* BDF31C 8024058C 8C470030 */   lw       $a3, 0x30($v0)
/* BDF320 80240590 0200202D */  daddu     $a0, $s0, $zero
/* BDF324 80240594 240502F4 */  addiu     $a1, $zero, 0x2f4
/* BDF328 80240598 3C060020 */  lui       $a2, 0x20
/* BDF32C 8024059C 0C012530 */  jal       func_800494C0
/* BDF330 802405A0 E480000C */   swc1     $f0, 0xc($a0)
/* BDF334 802405A4 8E220018 */  lw        $v0, 0x18($s1)
/* BDF338 802405A8 9442002A */  lhu       $v0, 0x2a($v0)
/* BDF33C 802405AC 30420001 */  andi      $v0, $v0, 1
/* BDF340 802405B0 14400029 */  bnez      $v0, .L80240658
/* BDF344 802405B4 2402000A */   addiu    $v0, $zero, 0xa
/* BDF348 802405B8 08090196 */  j         .L80240658
/* BDF34C 802405BC 2402000C */   addiu    $v0, $zero, 0xc
.L802405C0:
/* BDF350 802405C0 8602008C */  lh        $v0, 0x8c($s0)
/* BDF354 802405C4 14400025 */  bnez      $v0, .L8024065C
/* BDF358 802405C8 00000000 */   nop      
/* BDF35C 802405CC 9602008E */  lhu       $v0, 0x8e($s0)
/* BDF360 802405D0 2442FFFF */  addiu     $v0, $v0, -1
/* BDF364 802405D4 A602008E */  sh        $v0, 0x8e($s0)
/* BDF368 802405D8 00021400 */  sll       $v0, $v0, 0x10
/* BDF36C 802405DC 1440001F */  bnez      $v0, .L8024065C
/* BDF370 802405E0 00000000 */   nop      
/* BDF374 802405E4 8E820074 */  lw        $v0, 0x74($s4)
/* BDF378 802405E8 2442FFFF */  addiu     $v0, $v0, -1
/* BDF37C 802405EC 10400019 */  beqz      $v0, .L80240654
/* BDF380 802405F0 AE820074 */   sw       $v0, 0x74($s4)
/* BDF384 802405F4 8E220018 */  lw        $v0, 0x18($s1)
/* BDF388 802405F8 9442002A */  lhu       $v0, 0x2a($v0)
/* BDF38C 802405FC 30420010 */  andi      $v0, $v0, 0x10
/* BDF390 80240600 14400007 */  bnez      $v0, .L80240620
/* BDF394 80240604 00000000 */   nop      
/* BDF398 80240608 C600000C */  lwc1      $f0, 0xc($s0)
/* BDF39C 8024060C 3C014334 */  lui       $at, 0x4334
/* BDF3A0 80240610 44816000 */  mtc1      $at, $f12
/* BDF3A4 80240614 0C00A6C9 */  jal       clamp_angle
/* BDF3A8 80240618 460C0300 */   add.s    $f12, $f0, $f12
/* BDF3AC 8024061C E600000C */  swc1      $f0, 0xc($s0)
.L80240620:
/* BDF3B0 80240620 8E440008 */  lw        $a0, 8($s2)
/* BDF3B4 80240624 000417C2 */  srl       $v0, $a0, 0x1f
/* BDF3B8 80240628 00822021 */  addu      $a0, $a0, $v0
/* BDF3BC 8024062C 00042043 */  sra       $a0, $a0, 1
/* BDF3C0 80240630 0C00A67F */  jal       rand_int
/* BDF3C4 80240634 24840001 */   addiu    $a0, $a0, 1
/* BDF3C8 80240638 8E430008 */  lw        $v1, 8($s2)
/* BDF3CC 8024063C 000327C2 */  srl       $a0, $v1, 0x1f
/* BDF3D0 80240640 00641821 */  addu      $v1, $v1, $a0
/* BDF3D4 80240644 00031843 */  sra       $v1, $v1, 1
/* BDF3D8 80240648 00621821 */  addu      $v1, $v1, $v0
/* BDF3DC 8024064C 08090197 */  j         .L8024065C
/* BDF3E0 80240650 A603008E */   sh       $v1, 0x8e($s0)
.L80240654:
/* BDF3E4 80240654 24020004 */  addiu     $v0, $zero, 4
.L80240658:
/* BDF3E8 80240658 AE820070 */  sw        $v0, 0x70($s4)
.L8024065C:
/* BDF3EC 8024065C 8FBF0044 */  lw        $ra, 0x44($sp)
/* BDF3F0 80240660 8FB40040 */  lw        $s4, 0x40($sp)
/* BDF3F4 80240664 8FB3003C */  lw        $s3, 0x3c($sp)
/* BDF3F8 80240668 8FB20038 */  lw        $s2, 0x38($sp)
/* BDF3FC 8024066C 8FB10034 */  lw        $s1, 0x34($sp)
/* BDF400 80240670 8FB00030 */  lw        $s0, 0x30($sp)
/* BDF404 80240674 03E00008 */  jr        $ra
/* BDF408 80240678 27BD0048 */   addiu    $sp, $sp, 0x48
