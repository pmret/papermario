.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404C0_BE80A0
/* BE80A0 802404C0 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* BE80A4 802404C4 AFB40040 */  sw        $s4, 0x40($sp)
/* BE80A8 802404C8 0080A02D */  daddu     $s4, $a0, $zero
/* BE80AC 802404CC AFBF0044 */  sw        $ra, 0x44($sp)
/* BE80B0 802404D0 AFB3003C */  sw        $s3, 0x3c($sp)
/* BE80B4 802404D4 AFB20038 */  sw        $s2, 0x38($sp)
/* BE80B8 802404D8 AFB10034 */  sw        $s1, 0x34($sp)
/* BE80BC 802404DC AFB00030 */  sw        $s0, 0x30($sp)
/* BE80C0 802404E0 8E910148 */  lw        $s1, 0x148($s4)
/* BE80C4 802404E4 00A0902D */  daddu     $s2, $a1, $zero
/* BE80C8 802404E8 86240008 */  lh        $a0, 8($s1)
/* BE80CC 802404EC 0C00EABB */  jal       get_npc_unsafe
/* BE80D0 802404F0 00C0982D */   daddu    $s3, $a2, $zero
/* BE80D4 802404F4 8E430014 */  lw        $v1, 0x14($s2)
/* BE80D8 802404F8 04600031 */  bltz      $v1, .L802405C0
/* BE80DC 802404FC 0040802D */   daddu    $s0, $v0, $zero
/* BE80E0 80240500 0260202D */  daddu     $a0, $s3, $zero
/* BE80E4 80240504 AFA00010 */  sw        $zero, 0x10($sp)
/* BE80E8 80240508 8E460024 */  lw        $a2, 0x24($s2)
/* BE80EC 8024050C 8E470028 */  lw        $a3, 0x28($s2)
/* BE80F0 80240510 0C01242D */  jal       func_800490B4
/* BE80F4 80240514 0220282D */   daddu    $a1, $s1, $zero
/* BE80F8 80240518 10400029 */  beqz      $v0, .L802405C0
/* BE80FC 8024051C 0000202D */   daddu    $a0, $zero, $zero
/* BE8100 80240520 0200282D */  daddu     $a1, $s0, $zero
/* BE8104 80240524 0000302D */  daddu     $a2, $zero, $zero
/* BE8108 80240528 860300A8 */  lh        $v1, 0xa8($s0)
/* BE810C 8024052C 3C013F80 */  lui       $at, 0x3f80
/* BE8110 80240530 44810000 */  mtc1      $at, $f0
/* BE8114 80240534 3C014000 */  lui       $at, 0x4000
/* BE8118 80240538 44811000 */  mtc1      $at, $f2
/* BE811C 8024053C 3C01C1A0 */  lui       $at, 0xc1a0
/* BE8120 80240540 44812000 */  mtc1      $at, $f4
/* BE8124 80240544 2402000F */  addiu     $v0, $zero, 0xf
/* BE8128 80240548 AFA2001C */  sw        $v0, 0x1c($sp)
/* BE812C 8024054C 44833000 */  mtc1      $v1, $f6
/* BE8130 80240550 00000000 */  nop
/* BE8134 80240554 468031A0 */  cvt.s.w   $f6, $f6
/* BE8138 80240558 44073000 */  mfc1      $a3, $f6
/* BE813C 8024055C 27A20028 */  addiu     $v0, $sp, 0x28
/* BE8140 80240560 AFA20020 */  sw        $v0, 0x20($sp)
/* BE8144 80240564 E7A00010 */  swc1      $f0, 0x10($sp)
/* BE8148 80240568 E7A20014 */  swc1      $f2, 0x14($sp)
/* BE814C 8024056C 0C01BFA4 */  jal       fx_emote
/* BE8150 80240570 E7A40018 */   swc1     $f4, 0x18($sp)
/* BE8154 80240574 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* BE8158 80240578 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* BE815C 8024057C C60C0038 */  lwc1      $f12, 0x38($s0)
/* BE8160 80240580 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BE8164 80240584 8C460028 */  lw        $a2, 0x28($v0)
/* BE8168 80240588 0C00A720 */  jal       atan2
/* BE816C 8024058C 8C470030 */   lw       $a3, 0x30($v0)
/* BE8170 80240590 0200202D */  daddu     $a0, $s0, $zero
/* BE8174 80240594 240502F4 */  addiu     $a1, $zero, 0x2f4
/* BE8178 80240598 3C060020 */  lui       $a2, 0x20
/* BE817C 8024059C 0C012530 */  jal       func_800494C0
/* BE8180 802405A0 E480000C */   swc1     $f0, 0xc($a0)
/* BE8184 802405A4 8E220018 */  lw        $v0, 0x18($s1)
/* BE8188 802405A8 9442002A */  lhu       $v0, 0x2a($v0)
/* BE818C 802405AC 30420001 */  andi      $v0, $v0, 1
/* BE8190 802405B0 14400029 */  bnez      $v0, .L80240658
/* BE8194 802405B4 2402000A */   addiu    $v0, $zero, 0xa
/* BE8198 802405B8 08090196 */  j         .L80240658
/* BE819C 802405BC 2402000C */   addiu    $v0, $zero, 0xc
.L802405C0:
/* BE81A0 802405C0 8602008C */  lh        $v0, 0x8c($s0)
/* BE81A4 802405C4 14400025 */  bnez      $v0, .L8024065C
/* BE81A8 802405C8 00000000 */   nop
/* BE81AC 802405CC 9602008E */  lhu       $v0, 0x8e($s0)
/* BE81B0 802405D0 2442FFFF */  addiu     $v0, $v0, -1
/* BE81B4 802405D4 A602008E */  sh        $v0, 0x8e($s0)
/* BE81B8 802405D8 00021400 */  sll       $v0, $v0, 0x10
/* BE81BC 802405DC 1440001F */  bnez      $v0, .L8024065C
/* BE81C0 802405E0 00000000 */   nop
/* BE81C4 802405E4 8E820074 */  lw        $v0, 0x74($s4)
/* BE81C8 802405E8 2442FFFF */  addiu     $v0, $v0, -1
/* BE81CC 802405EC 10400019 */  beqz      $v0, .L80240654
/* BE81D0 802405F0 AE820074 */   sw       $v0, 0x74($s4)
/* BE81D4 802405F4 8E220018 */  lw        $v0, 0x18($s1)
/* BE81D8 802405F8 9442002A */  lhu       $v0, 0x2a($v0)
/* BE81DC 802405FC 30420010 */  andi      $v0, $v0, 0x10
/* BE81E0 80240600 14400007 */  bnez      $v0, .L80240620
/* BE81E4 80240604 00000000 */   nop
/* BE81E8 80240608 C600000C */  lwc1      $f0, 0xc($s0)
/* BE81EC 8024060C 3C014334 */  lui       $at, 0x4334
/* BE81F0 80240610 44816000 */  mtc1      $at, $f12
/* BE81F4 80240614 0C00A6C9 */  jal       clamp_angle
/* BE81F8 80240618 460C0300 */   add.s    $f12, $f0, $f12
/* BE81FC 8024061C E600000C */  swc1      $f0, 0xc($s0)
.L80240620:
/* BE8200 80240620 8E440008 */  lw        $a0, 8($s2)
/* BE8204 80240624 000417C2 */  srl       $v0, $a0, 0x1f
/* BE8208 80240628 00822021 */  addu      $a0, $a0, $v0
/* BE820C 8024062C 00042043 */  sra       $a0, $a0, 1
/* BE8210 80240630 0C00A67F */  jal       rand_int
/* BE8214 80240634 24840001 */   addiu    $a0, $a0, 1
/* BE8218 80240638 8E430008 */  lw        $v1, 8($s2)
/* BE821C 8024063C 000327C2 */  srl       $a0, $v1, 0x1f
/* BE8220 80240640 00641821 */  addu      $v1, $v1, $a0
/* BE8224 80240644 00031843 */  sra       $v1, $v1, 1
/* BE8228 80240648 00621821 */  addu      $v1, $v1, $v0
/* BE822C 8024064C 08090197 */  j         .L8024065C
/* BE8230 80240650 A603008E */   sh       $v1, 0x8e($s0)
.L80240654:
/* BE8234 80240654 24020004 */  addiu     $v0, $zero, 4
.L80240658:
/* BE8238 80240658 AE820070 */  sw        $v0, 0x70($s4)
.L8024065C:
/* BE823C 8024065C 8FBF0044 */  lw        $ra, 0x44($sp)
/* BE8240 80240660 8FB40040 */  lw        $s4, 0x40($sp)
/* BE8244 80240664 8FB3003C */  lw        $s3, 0x3c($sp)
/* BE8248 80240668 8FB20038 */  lw        $s2, 0x38($sp)
/* BE824C 8024066C 8FB10034 */  lw        $s1, 0x34($sp)
/* BE8250 80240670 8FB00030 */  lw        $s0, 0x30($sp)
/* BE8254 80240674 03E00008 */  jr        $ra
/* BE8258 80240678 27BD0048 */   addiu    $sp, $sp, 0x48
