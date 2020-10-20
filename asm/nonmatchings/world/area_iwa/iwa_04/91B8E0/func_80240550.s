.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240550
/* 91BE30 80240550 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 91BE34 80240554 AFB3003C */  sw        $s3, 0x3c($sp)
/* 91BE38 80240558 0080982D */  daddu     $s3, $a0, $zero
/* 91BE3C 8024055C AFBF0040 */  sw        $ra, 0x40($sp)
/* 91BE40 80240560 AFB20038 */  sw        $s2, 0x38($sp)
/* 91BE44 80240564 AFB10034 */  sw        $s1, 0x34($sp)
/* 91BE48 80240568 AFB00030 */  sw        $s0, 0x30($sp)
/* 91BE4C 8024056C 8E700148 */  lw        $s0, 0x148($s3)
/* 91BE50 80240570 00A0902D */  daddu     $s2, $a1, $zero
/* 91BE54 80240574 86040008 */  lh        $a0, 8($s0)
/* 91BE58 80240578 0C00EABB */  jal       get_npc_unsafe
/* 91BE5C 8024057C 00C0882D */   daddu    $s1, $a2, $zero
/* 91BE60 80240580 0220202D */  daddu     $a0, $s1, $zero
/* 91BE64 80240584 0200282D */  daddu     $a1, $s0, $zero
/* 91BE68 80240588 AFA00010 */  sw        $zero, 0x10($sp)
/* 91BE6C 8024058C 8E460024 */  lw        $a2, 0x24($s2)
/* 91BE70 80240590 8E470028 */  lw        $a3, 0x28($s2)
/* 91BE74 80240594 0C01242D */  jal       func_800490B4
/* 91BE78 80240598 0040802D */   daddu    $s0, $v0, $zero
/* 91BE7C 8024059C 1040000B */  beqz      $v0, .L802405CC
/* 91BE80 802405A0 00000000 */   nop      
/* 91BE84 802405A4 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 91BE88 802405A8 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 91BE8C 802405AC C60C0038 */  lwc1      $f12, 0x38($s0)
/* 91BE90 802405B0 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 91BE94 802405B4 8C460028 */  lw        $a2, 0x28($v0)
/* 91BE98 802405B8 0C00A720 */  jal       atan2
/* 91BE9C 802405BC 8C470030 */   lw       $a3, 0x30($v0)
/* 91BEA0 802405C0 2402000C */  addiu     $v0, $zero, 0xc
/* 91BEA4 802405C4 080901A9 */  j         .L802406A4
/* 91BEA8 802405C8 E600000C */   swc1     $f0, 0xc($s0)
.L802405CC:
/* 91BEAC 802405CC 9602008E */  lhu       $v0, 0x8e($s0)
/* 91BEB0 802405D0 2442FFFF */  addiu     $v0, $v0, -1
/* 91BEB4 802405D4 A602008E */  sh        $v0, 0x8e($s0)
/* 91BEB8 802405D8 00021400 */  sll       $v0, $v0, 0x10
/* 91BEBC 802405DC 1C400032 */  bgtz      $v0, .L802406A8
/* 91BEC0 802405E0 00000000 */   nop      
/* 91BEC4 802405E4 8E620074 */  lw        $v0, 0x74($s3)
/* 91BEC8 802405E8 2442FFFF */  addiu     $v0, $v0, -1
/* 91BECC 802405EC 18400014 */  blez      $v0, .L80240640
/* 91BED0 802405F0 AE620074 */   sw       $v0, 0x74($s3)
/* 91BED4 802405F4 C600000C */  lwc1      $f0, 0xc($s0)
/* 91BED8 802405F8 3C014334 */  lui       $at, 0x4334
/* 91BEDC 802405FC 44816000 */  mtc1      $at, $f12
/* 91BEE0 80240600 0C00A6C9 */  jal       clamp_angle
/* 91BEE4 80240604 460C0300 */   add.s    $f12, $f0, $f12
/* 91BEE8 80240608 E600000C */  swc1      $f0, 0xc($s0)
/* 91BEEC 8024060C 8E440008 */  lw        $a0, 8($s2)
/* 91BEF0 80240610 000417C2 */  srl       $v0, $a0, 0x1f
/* 91BEF4 80240614 00822021 */  addu      $a0, $a0, $v0
/* 91BEF8 80240618 00042043 */  sra       $a0, $a0, 1
/* 91BEFC 8024061C 0C00A67F */  jal       rand_int
/* 91BF00 80240620 24840001 */   addiu    $a0, $a0, 1
/* 91BF04 80240624 8E430008 */  lw        $v1, 8($s2)
/* 91BF08 80240628 000327C2 */  srl       $a0, $v1, 0x1f
/* 91BF0C 8024062C 00641821 */  addu      $v1, $v1, $a0
/* 91BF10 80240630 00031843 */  sra       $v1, $v1, 1
/* 91BF14 80240634 00621821 */  addu      $v1, $v1, $v0
/* 91BF18 80240638 080901AA */  j         .L802406A8
/* 91BF1C 8024063C A603008E */   sh       $v1, 0x8e($s0)
.L80240640:
/* 91BF20 80240640 24040002 */  addiu     $a0, $zero, 2
/* 91BF24 80240644 0200282D */  daddu     $a1, $s0, $zero
/* 91BF28 80240648 0000302D */  daddu     $a2, $zero, $zero
/* 91BF2C 8024064C 860300A8 */  lh        $v1, 0xa8($s0)
/* 91BF30 80240650 3C013F80 */  lui       $at, 0x3f80
/* 91BF34 80240654 44810000 */  mtc1      $at, $f0
/* 91BF38 80240658 3C014000 */  lui       $at, 0x4000
/* 91BF3C 8024065C 44811000 */  mtc1      $at, $f2
/* 91BF40 80240660 3C01C1A0 */  lui       $at, 0xc1a0
/* 91BF44 80240664 44812000 */  mtc1      $at, $f4
/* 91BF48 80240668 2402000C */  addiu     $v0, $zero, 0xc
/* 91BF4C 8024066C AFA2001C */  sw        $v0, 0x1c($sp)
/* 91BF50 80240670 44833000 */  mtc1      $v1, $f6
/* 91BF54 80240674 00000000 */  nop       
/* 91BF58 80240678 468031A0 */  cvt.s.w   $f6, $f6
/* 91BF5C 8024067C 44073000 */  mfc1      $a3, $f6
/* 91BF60 80240680 27A20028 */  addiu     $v0, $sp, 0x28
/* 91BF64 80240684 AFA20020 */  sw        $v0, 0x20($sp)
/* 91BF68 80240688 E7A00010 */  swc1      $f0, 0x10($sp)
/* 91BF6C 8024068C E7A20014 */  swc1      $f2, 0x14($sp)
/* 91BF70 80240690 0C01BFA4 */  jal       fx_emote
/* 91BF74 80240694 E7A40018 */   swc1     $f4, 0x18($sp)
/* 91BF78 80240698 2402000F */  addiu     $v0, $zero, 0xf
/* 91BF7C 8024069C A602008E */  sh        $v0, 0x8e($s0)
/* 91BF80 802406A0 24020028 */  addiu     $v0, $zero, 0x28
.L802406A4:
/* 91BF84 802406A4 AE620070 */  sw        $v0, 0x70($s3)
.L802406A8:
/* 91BF88 802406A8 8FBF0040 */  lw        $ra, 0x40($sp)
/* 91BF8C 802406AC 8FB3003C */  lw        $s3, 0x3c($sp)
/* 91BF90 802406B0 8FB20038 */  lw        $s2, 0x38($sp)
/* 91BF94 802406B4 8FB10034 */  lw        $s1, 0x34($sp)
/* 91BF98 802406B8 8FB00030 */  lw        $s0, 0x30($sp)
/* 91BF9C 802406BC 03E00008 */  jr        $ra
/* 91BFA0 802406C0 27BD0048 */   addiu    $sp, $sp, 0x48
