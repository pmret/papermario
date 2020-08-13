.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel calc_item_check_hit
/* 17FEB0 802515D0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 17FEB4 802515D4 AFB30024 */  sw    $s3, 0x24($sp)
/* 17FEB8 802515D8 3C13800E */  lui   $s3, 0x800e
/* 17FEBC 802515DC 2673C070 */  addiu $s3, $s3, -0x3f90
/* 17FEC0 802515E0 AFBF0028 */  sw    $ra, 0x28($sp)
/* 17FEC4 802515E4 AFB20020 */  sw    $s2, 0x20($sp)
/* 17FEC8 802515E8 AFB1001C */  sw    $s1, 0x1c($sp)
/* 17FECC 802515EC AFB00018 */  sw    $s0, 0x18($sp)
/* 17FED0 802515F0 8E6500D8 */  lw    $a1, 0xd8($s3)
/* 17FED4 802515F4 966301A0 */  lhu   $v1, 0x1a0($s3)
/* 17FED8 802515F8 866401A0 */  lh    $a0, 0x1a0($s3)
/* 17FEDC 802515FC 926201A2 */  lbu   $v0, 0x1a2($s3)
/* 17FEE0 80251600 827201A2 */  lb    $s2, 0x1a2($s3)
/* 17FEE4 80251604 24B1000C */  addiu $s1, $a1, 0xc
/* 17FEE8 80251608 A66301A4 */  sh    $v1, 0x1a4($s3)
/* 17FEEC 8025160C 0C09A75B */  jal   get_actor
/* 17FEF0 80251610 A26201A6 */   sb    $v0, 0x1a6($s3)
/* 17FEF4 80251614 0040802D */  daddu $s0, $v0, $zero
/* 17FEF8 80251618 1200002B */  beqz  $s0, .L802516C8
/* 17FEFC 8025161C 0200202D */   daddu $a0, $s0, $zero
/* 17FF00 80251620 0C099117 */  jal   get_actor_part
/* 17FF04 80251624 0240282D */   daddu $a1, $s2, $zero
/* 17FF08 80251628 14400003 */  bnez  $v0, .L80251638
/* 17FF0C 8025162C 00000000 */   nop   
.L80251630:
/* 17FF10 80251630 0809458C */  j     .L80251630
/* 17FF14 80251634 00000000 */   nop   

.L80251638:
/* 17FF18 80251638 8C44007C */  lw    $a0, 0x7c($v0)
/* 17FF1C 8025163C 30820020 */  andi  $v0, $a0, 0x20
/* 17FF20 80251640 14400022 */  bnez  $v0, .L802516CC
/* 17FF24 80251644 24020006 */   addiu $v0, $zero, 6
/* 17FF28 80251648 82030218 */  lb    $v1, 0x218($s0)
/* 17FF2C 8025164C 2402000E */  addiu $v0, $zero, 0xe
/* 17FF30 80251650 14620003 */  bne   $v1, $v0, .L80251660
/* 17FF34 80251654 2402000C */   addiu $v0, $zero, 0xc
/* 17FF38 80251658 080945B3 */  j     .L802516CC
/* 17FF3C 8025165C 24020006 */   addiu $v0, $zero, 6

.L80251660:
/* 17FF40 80251660 82030214 */  lb    $v1, 0x214($s0)
/* 17FF44 80251664 1462000A */  bne   $v1, $v0, .L80251690
/* 17FF48 80251668 00000000 */   nop   
/* 17FF4C 8025166C C6200014 */  lwc1  $f0, 0x14($s1)
/* 17FF50 80251670 2404010C */  addiu $a0, $zero, 0x10c
/* 17FF54 80251674 E7A00010 */  swc1  $f0, 0x10($sp)
/* 17FF58 80251678 8E26000C */  lw    $a2, 0xc($s1)
/* 17FF5C 8025167C 8E270010 */  lw    $a3, 0x10($s1)
/* 17FF60 80251680 0C052757 */  jal   play_sound_at_position
/* 17FF64 80251684 0000282D */   daddu $a1, $zero, $zero
/* 17FF68 80251688 080945B3 */  j     .L802516CC
/* 17FF6C 8025168C 24020008 */   addiu $v0, $zero, 8

.L80251690:
/* 17FF70 80251690 8E620188 */  lw    $v0, 0x188($s3)
/* 17FF74 80251694 30420080 */  andi  $v0, $v0, 0x80
/* 17FF78 80251698 1040000B */  beqz  $v0, .L802516C8
/* 17FF7C 8025169C 30820010 */   andi  $v0, $a0, 0x10
/* 17FF80 802516A0 10400009 */  beqz  $v0, .L802516C8
/* 17FF84 802516A4 240400E9 */   addiu $a0, $zero, 0xe9
/* 17FF88 802516A8 C6200014 */  lwc1  $f0, 0x14($s1)
/* 17FF8C 802516AC E7A00010 */  swc1  $f0, 0x10($sp)
/* 17FF90 802516B0 8E26000C */  lw    $a2, 0xc($s1)
/* 17FF94 802516B4 8E270010 */  lw    $a3, 0x10($s1)
/* 17FF98 802516B8 0C052757 */  jal   play_sound_at_position
/* 17FF9C 802516BC 0000282D */   daddu $a1, $zero, $zero
/* 17FFA0 802516C0 080945B3 */  j     .L802516CC
/* 17FFA4 802516C4 24020004 */   addiu $v0, $zero, 4

.L802516C8:
/* 17FFA8 802516C8 0000102D */  daddu $v0, $zero, $zero
.L802516CC:
.L802516CC:
/* 17FFAC 802516CC 8FBF0028 */  lw    $ra, 0x28($sp)
/* 17FFB0 802516D0 8FB30024 */  lw    $s3, 0x24($sp)
/* 17FFB4 802516D4 8FB20020 */  lw    $s2, 0x20($sp)
/* 17FFB8 802516D8 8FB1001C */  lw    $s1, 0x1c($sp)
/* 17FFBC 802516DC 8FB00018 */  lw    $s0, 0x18($sp)
/* 17FFC0 802516E0 03E00008 */  jr    $ra
/* 17FFC4 802516E4 27BD0030 */   addiu $sp, $sp, 0x30

