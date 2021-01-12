.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404D0_BDD680
/* BDD680 802404D0 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* BDD684 802404D4 AFB3003C */  sw        $s3, 0x3c($sp)
/* BDD688 802404D8 0080982D */  daddu     $s3, $a0, $zero
/* BDD68C 802404DC AFBF0040 */  sw        $ra, 0x40($sp)
/* BDD690 802404E0 AFB20038 */  sw        $s2, 0x38($sp)
/* BDD694 802404E4 AFB10034 */  sw        $s1, 0x34($sp)
/* BDD698 802404E8 AFB00030 */  sw        $s0, 0x30($sp)
/* BDD69C 802404EC 8E700148 */  lw        $s0, 0x148($s3)
/* BDD6A0 802404F0 00A0902D */  daddu     $s2, $a1, $zero
/* BDD6A4 802404F4 86040008 */  lh        $a0, 8($s0)
/* BDD6A8 802404F8 0C00EABB */  jal       get_npc_unsafe
/* BDD6AC 802404FC 00C0882D */   daddu    $s1, $a2, $zero
/* BDD6B0 80240500 0220202D */  daddu     $a0, $s1, $zero
/* BDD6B4 80240504 0200282D */  daddu     $a1, $s0, $zero
/* BDD6B8 80240508 AFA00010 */  sw        $zero, 0x10($sp)
/* BDD6BC 8024050C 8E460024 */  lw        $a2, 0x24($s2)
/* BDD6C0 80240510 8E470028 */  lw        $a3, 0x28($s2)
/* BDD6C4 80240514 0C01242D */  jal       func_800490B4
/* BDD6C8 80240518 0040802D */   daddu    $s0, $v0, $zero
/* BDD6CC 8024051C 1040000B */  beqz      $v0, .L8024054C
/* BDD6D0 80240520 00000000 */   nop
/* BDD6D4 80240524 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* BDD6D8 80240528 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* BDD6DC 8024052C C60C0038 */  lwc1      $f12, 0x38($s0)
/* BDD6E0 80240530 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BDD6E4 80240534 8C460028 */  lw        $a2, 0x28($v0)
/* BDD6E8 80240538 0C00A720 */  jal       atan2
/* BDD6EC 8024053C 8C470030 */   lw       $a3, 0x30($v0)
/* BDD6F0 80240540 2402000C */  addiu     $v0, $zero, 0xc
/* BDD6F4 80240544 08090189 */  j         .L80240624
/* BDD6F8 80240548 E600000C */   swc1     $f0, 0xc($s0)
.L8024054C:
/* BDD6FC 8024054C 9602008E */  lhu       $v0, 0x8e($s0)
/* BDD700 80240550 2442FFFF */  addiu     $v0, $v0, -1
/* BDD704 80240554 A602008E */  sh        $v0, 0x8e($s0)
/* BDD708 80240558 00021400 */  sll       $v0, $v0, 0x10
/* BDD70C 8024055C 1C400032 */  bgtz      $v0, .L80240628
/* BDD710 80240560 00000000 */   nop
/* BDD714 80240564 8E620074 */  lw        $v0, 0x74($s3)
/* BDD718 80240568 2442FFFF */  addiu     $v0, $v0, -1
/* BDD71C 8024056C 18400014 */  blez      $v0, .L802405C0
/* BDD720 80240570 AE620074 */   sw       $v0, 0x74($s3)
/* BDD724 80240574 C600000C */  lwc1      $f0, 0xc($s0)
/* BDD728 80240578 3C014334 */  lui       $at, 0x4334
/* BDD72C 8024057C 44816000 */  mtc1      $at, $f12
/* BDD730 80240580 0C00A6C9 */  jal       clamp_angle
/* BDD734 80240584 460C0300 */   add.s    $f12, $f0, $f12
/* BDD738 80240588 E600000C */  swc1      $f0, 0xc($s0)
/* BDD73C 8024058C 8E440008 */  lw        $a0, 8($s2)
/* BDD740 80240590 000417C2 */  srl       $v0, $a0, 0x1f
/* BDD744 80240594 00822021 */  addu      $a0, $a0, $v0
/* BDD748 80240598 00042043 */  sra       $a0, $a0, 1
/* BDD74C 8024059C 0C00A67F */  jal       rand_int
/* BDD750 802405A0 24840001 */   addiu    $a0, $a0, 1
/* BDD754 802405A4 8E430008 */  lw        $v1, 8($s2)
/* BDD758 802405A8 000327C2 */  srl       $a0, $v1, 0x1f
/* BDD75C 802405AC 00641821 */  addu      $v1, $v1, $a0
/* BDD760 802405B0 00031843 */  sra       $v1, $v1, 1
/* BDD764 802405B4 00621821 */  addu      $v1, $v1, $v0
/* BDD768 802405B8 0809018A */  j         .L80240628
/* BDD76C 802405BC A603008E */   sh       $v1, 0x8e($s0)
.L802405C0:
/* BDD770 802405C0 24040002 */  addiu     $a0, $zero, 2
/* BDD774 802405C4 0200282D */  daddu     $a1, $s0, $zero
/* BDD778 802405C8 0000302D */  daddu     $a2, $zero, $zero
/* BDD77C 802405CC 860300A8 */  lh        $v1, 0xa8($s0)
/* BDD780 802405D0 3C013F80 */  lui       $at, 0x3f80
/* BDD784 802405D4 44810000 */  mtc1      $at, $f0
/* BDD788 802405D8 3C014000 */  lui       $at, 0x4000
/* BDD78C 802405DC 44811000 */  mtc1      $at, $f2
/* BDD790 802405E0 3C01C1A0 */  lui       $at, 0xc1a0
/* BDD794 802405E4 44812000 */  mtc1      $at, $f4
/* BDD798 802405E8 2402000C */  addiu     $v0, $zero, 0xc
/* BDD79C 802405EC AFA2001C */  sw        $v0, 0x1c($sp)
/* BDD7A0 802405F0 44833000 */  mtc1      $v1, $f6
/* BDD7A4 802405F4 00000000 */  nop
/* BDD7A8 802405F8 468031A0 */  cvt.s.w   $f6, $f6
/* BDD7AC 802405FC 44073000 */  mfc1      $a3, $f6
/* BDD7B0 80240600 27A20028 */  addiu     $v0, $sp, 0x28
/* BDD7B4 80240604 AFA20020 */  sw        $v0, 0x20($sp)
/* BDD7B8 80240608 E7A00010 */  swc1      $f0, 0x10($sp)
/* BDD7BC 8024060C E7A20014 */  swc1      $f2, 0x14($sp)
/* BDD7C0 80240610 0C01BFA4 */  jal       fx_emote
/* BDD7C4 80240614 E7A40018 */   swc1     $f4, 0x18($sp)
/* BDD7C8 80240618 2402000F */  addiu     $v0, $zero, 0xf
/* BDD7CC 8024061C A602008E */  sh        $v0, 0x8e($s0)
/* BDD7D0 80240620 24020028 */  addiu     $v0, $zero, 0x28
.L80240624:
/* BDD7D4 80240624 AE620070 */  sw        $v0, 0x70($s3)
.L80240628:
/* BDD7D8 80240628 8FBF0040 */  lw        $ra, 0x40($sp)
/* BDD7DC 8024062C 8FB3003C */  lw        $s3, 0x3c($sp)
/* BDD7E0 80240630 8FB20038 */  lw        $s2, 0x38($sp)
/* BDD7E4 80240634 8FB10034 */  lw        $s1, 0x34($sp)
/* BDD7E8 80240638 8FB00030 */  lw        $s0, 0x30($sp)
/* BDD7EC 8024063C 03E00008 */  jr        $ra
/* BDD7F0 80240640 27BD0048 */   addiu    $sp, $sp, 0x48
