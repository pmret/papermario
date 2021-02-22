.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404C0_BE3C70
/* BE3C70 802404C0 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* BE3C74 802404C4 AFB40040 */  sw        $s4, 0x40($sp)
/* BE3C78 802404C8 0080A02D */  daddu     $s4, $a0, $zero
/* BE3C7C 802404CC AFBF0044 */  sw        $ra, 0x44($sp)
/* BE3C80 802404D0 AFB3003C */  sw        $s3, 0x3c($sp)
/* BE3C84 802404D4 AFB20038 */  sw        $s2, 0x38($sp)
/* BE3C88 802404D8 AFB10034 */  sw        $s1, 0x34($sp)
/* BE3C8C 802404DC AFB00030 */  sw        $s0, 0x30($sp)
/* BE3C90 802404E0 8E910148 */  lw        $s1, 0x148($s4)
/* BE3C94 802404E4 00A0902D */  daddu     $s2, $a1, $zero
/* BE3C98 802404E8 86240008 */  lh        $a0, 8($s1)
/* BE3C9C 802404EC 0C00EABB */  jal       get_npc_unsafe
/* BE3CA0 802404F0 00C0982D */   daddu    $s3, $a2, $zero
/* BE3CA4 802404F4 8E430014 */  lw        $v1, 0x14($s2)
/* BE3CA8 802404F8 04600031 */  bltz      $v1, .L802405C0
/* BE3CAC 802404FC 0040802D */   daddu    $s0, $v0, $zero
/* BE3CB0 80240500 0260202D */  daddu     $a0, $s3, $zero
/* BE3CB4 80240504 AFA00010 */  sw        $zero, 0x10($sp)
/* BE3CB8 80240508 8E460024 */  lw        $a2, 0x24($s2)
/* BE3CBC 8024050C 8E470028 */  lw        $a3, 0x28($s2)
/* BE3CC0 80240510 0C01242D */  jal       func_800490B4
/* BE3CC4 80240514 0220282D */   daddu    $a1, $s1, $zero
/* BE3CC8 80240518 10400029 */  beqz      $v0, .L802405C0
/* BE3CCC 8024051C 0000202D */   daddu    $a0, $zero, $zero
/* BE3CD0 80240520 0200282D */  daddu     $a1, $s0, $zero
/* BE3CD4 80240524 0000302D */  daddu     $a2, $zero, $zero
/* BE3CD8 80240528 860300A8 */  lh        $v1, 0xa8($s0)
/* BE3CDC 8024052C 3C013F80 */  lui       $at, 0x3f80
/* BE3CE0 80240530 44810000 */  mtc1      $at, $f0
/* BE3CE4 80240534 3C014000 */  lui       $at, 0x4000
/* BE3CE8 80240538 44811000 */  mtc1      $at, $f2
/* BE3CEC 8024053C 3C01C1A0 */  lui       $at, 0xc1a0
/* BE3CF0 80240540 44812000 */  mtc1      $at, $f4
/* BE3CF4 80240544 2402000F */  addiu     $v0, $zero, 0xf
/* BE3CF8 80240548 AFA2001C */  sw        $v0, 0x1c($sp)
/* BE3CFC 8024054C 44833000 */  mtc1      $v1, $f6
/* BE3D00 80240550 00000000 */  nop
/* BE3D04 80240554 468031A0 */  cvt.s.w   $f6, $f6
/* BE3D08 80240558 44073000 */  mfc1      $a3, $f6
/* BE3D0C 8024055C 27A20028 */  addiu     $v0, $sp, 0x28
/* BE3D10 80240560 AFA20020 */  sw        $v0, 0x20($sp)
/* BE3D14 80240564 E7A00010 */  swc1      $f0, 0x10($sp)
/* BE3D18 80240568 E7A20014 */  swc1      $f2, 0x14($sp)
/* BE3D1C 8024056C 0C01BFA4 */  jal       fx_emote
/* BE3D20 80240570 E7A40018 */   swc1     $f4, 0x18($sp)
/* BE3D24 80240574 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* BE3D28 80240578 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* BE3D2C 8024057C C60C0038 */  lwc1      $f12, 0x38($s0)
/* BE3D30 80240580 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BE3D34 80240584 8C460028 */  lw        $a2, 0x28($v0)
/* BE3D38 80240588 0C00A720 */  jal       atan2
/* BE3D3C 8024058C 8C470030 */   lw       $a3, 0x30($v0)
/* BE3D40 80240590 0200202D */  daddu     $a0, $s0, $zero
/* BE3D44 80240594 240502F4 */  addiu     $a1, $zero, 0x2f4
/* BE3D48 80240598 3C060020 */  lui       $a2, 0x20
/* BE3D4C 8024059C 0C012530 */  jal       func_800494C0
/* BE3D50 802405A0 E480000C */   swc1     $f0, 0xc($a0)
/* BE3D54 802405A4 8E220018 */  lw        $v0, 0x18($s1)
/* BE3D58 802405A8 9442002A */  lhu       $v0, 0x2a($v0)
/* BE3D5C 802405AC 30420001 */  andi      $v0, $v0, 1
/* BE3D60 802405B0 14400029 */  bnez      $v0, .L80240658
/* BE3D64 802405B4 2402000A */   addiu    $v0, $zero, 0xa
/* BE3D68 802405B8 08090196 */  j         .L80240658
/* BE3D6C 802405BC 2402000C */   addiu    $v0, $zero, 0xc
.L802405C0:
/* BE3D70 802405C0 8602008C */  lh        $v0, 0x8c($s0)
/* BE3D74 802405C4 14400025 */  bnez      $v0, .L8024065C
/* BE3D78 802405C8 00000000 */   nop
/* BE3D7C 802405CC 9602008E */  lhu       $v0, 0x8e($s0)
/* BE3D80 802405D0 2442FFFF */  addiu     $v0, $v0, -1
/* BE3D84 802405D4 A602008E */  sh        $v0, 0x8e($s0)
/* BE3D88 802405D8 00021400 */  sll       $v0, $v0, 0x10
/* BE3D8C 802405DC 1440001F */  bnez      $v0, .L8024065C
/* BE3D90 802405E0 00000000 */   nop
/* BE3D94 802405E4 8E820074 */  lw        $v0, 0x74($s4)
/* BE3D98 802405E8 2442FFFF */  addiu     $v0, $v0, -1
/* BE3D9C 802405EC 10400019 */  beqz      $v0, .L80240654
/* BE3DA0 802405F0 AE820074 */   sw       $v0, 0x74($s4)
/* BE3DA4 802405F4 8E220018 */  lw        $v0, 0x18($s1)
/* BE3DA8 802405F8 9442002A */  lhu       $v0, 0x2a($v0)
/* BE3DAC 802405FC 30420010 */  andi      $v0, $v0, 0x10
/* BE3DB0 80240600 14400007 */  bnez      $v0, .L80240620
/* BE3DB4 80240604 00000000 */   nop
/* BE3DB8 80240608 C600000C */  lwc1      $f0, 0xc($s0)
/* BE3DBC 8024060C 3C014334 */  lui       $at, 0x4334
/* BE3DC0 80240610 44816000 */  mtc1      $at, $f12
/* BE3DC4 80240614 0C00A6C9 */  jal       clamp_angle
/* BE3DC8 80240618 460C0300 */   add.s    $f12, $f0, $f12
/* BE3DCC 8024061C E600000C */  swc1      $f0, 0xc($s0)
.L80240620:
/* BE3DD0 80240620 8E440008 */  lw        $a0, 8($s2)
/* BE3DD4 80240624 000417C2 */  srl       $v0, $a0, 0x1f
/* BE3DD8 80240628 00822021 */  addu      $a0, $a0, $v0
/* BE3DDC 8024062C 00042043 */  sra       $a0, $a0, 1
/* BE3DE0 80240630 0C00A67F */  jal       rand_int
/* BE3DE4 80240634 24840001 */   addiu    $a0, $a0, 1
/* BE3DE8 80240638 8E430008 */  lw        $v1, 8($s2)
/* BE3DEC 8024063C 000327C2 */  srl       $a0, $v1, 0x1f
/* BE3DF0 80240640 00641821 */  addu      $v1, $v1, $a0
/* BE3DF4 80240644 00031843 */  sra       $v1, $v1, 1
/* BE3DF8 80240648 00621821 */  addu      $v1, $v1, $v0
/* BE3DFC 8024064C 08090197 */  j         .L8024065C
/* BE3E00 80240650 A603008E */   sh       $v1, 0x8e($s0)
.L80240654:
/* BE3E04 80240654 24020004 */  addiu     $v0, $zero, 4
.L80240658:
/* BE3E08 80240658 AE820070 */  sw        $v0, 0x70($s4)
.L8024065C:
/* BE3E0C 8024065C 8FBF0044 */  lw        $ra, 0x44($sp)
/* BE3E10 80240660 8FB40040 */  lw        $s4, 0x40($sp)
/* BE3E14 80240664 8FB3003C */  lw        $s3, 0x3c($sp)
/* BE3E18 80240668 8FB20038 */  lw        $s2, 0x38($sp)
/* BE3E1C 8024066C 8FB10034 */  lw        $s1, 0x34($sp)
/* BE3E20 80240670 8FB00030 */  lw        $s0, 0x30($sp)
/* BE3E24 80240674 03E00008 */  jr        $ra
/* BE3E28 80240678 27BD0048 */   addiu    $sp, $sp, 0x48
