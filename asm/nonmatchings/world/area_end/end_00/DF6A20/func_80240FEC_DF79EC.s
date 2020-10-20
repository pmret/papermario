.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240FEC_DF79EC
/* DF79EC 80240FEC 27BDFF48 */  addiu     $sp, $sp, -0xb8
/* DF79F0 80240FF0 AFB00088 */  sw        $s0, 0x88($sp)
/* DF79F4 80240FF4 00A0802D */  daddu     $s0, $a1, $zero
/* DF79F8 80240FF8 0000202D */  daddu     $a0, $zero, $zero
/* DF79FC 80240FFC 0080282D */  daddu     $a1, $a0, $zero
/* DF7A00 80241000 0080302D */  daddu     $a2, $a0, $zero
/* DF7A04 80241004 0080382D */  daddu     $a3, $a0, $zero
/* DF7A08 80241008 AFBF00A0 */  sw        $ra, 0xa0($sp)
/* DF7A0C 8024100C AFB5009C */  sw        $s5, 0x9c($sp)
/* DF7A10 80241010 AFB40098 */  sw        $s4, 0x98($sp)
/* DF7A14 80241014 AFB30094 */  sw        $s3, 0x94($sp)
/* DF7A18 80241018 AFB20090 */  sw        $s2, 0x90($sp)
/* DF7A1C 8024101C AFB1008C */  sw        $s1, 0x8c($sp)
/* DF7A20 80241020 F7B600B0 */  sdc1      $f22, 0xb0($sp)
/* DF7A24 80241024 F7B400A8 */  sdc1      $f20, 0xa8($sp)
/* DF7A28 80241028 C6140010 */  lwc1      $f20, 0x10($s0)
/* DF7A2C 8024102C 4680A520 */  cvt.s.w   $f20, $f20
/* DF7A30 80241030 C6160014 */  lwc1      $f22, 0x14($s0)
/* DF7A34 80241034 4680B5A0 */  cvt.s.w   $f22, $f22
/* DF7A38 80241038 AFA00010 */  sw        $zero, 0x10($sp)
/* DF7A3C 8024103C AFA00014 */  sw        $zero, 0x14($sp)
/* DF7A40 80241040 0C04EAA7 */  jal       func_8013AA9C
/* DF7A44 80241044 AFA00018 */   sw       $zero, 0x18($sp)
/* DF7A48 80241048 27B40048 */  addiu     $s4, $sp, 0x48
/* DF7A4C 8024104C 0280202D */  daddu     $a0, $s4, $zero
/* DF7A50 80241050 0000382D */  daddu     $a3, $zero, $zero
/* DF7A54 80241054 3C150001 */  lui       $s5, 1
/* DF7A58 80241058 4600B587 */  neg.s     $f22, $f22
/* DF7A5C 8024105C 4405A000 */  mfc1      $a1, $f20
/* DF7A60 80241060 4406B000 */  mfc1      $a2, $f22
/* DF7A64 80241064 0C019E40 */  jal       guTranslateF
/* DF7A68 80241068 36B51630 */   ori      $s5, $s5, 0x1630
/* DF7A6C 8024106C 0280202D */  daddu     $a0, $s4, $zero
/* DF7A70 80241070 3C118007 */  lui       $s1, 0x8007
/* DF7A74 80241074 263141F0 */  addiu     $s1, $s1, 0x41f0
/* DF7A78 80241078 3C12800A */  lui       $s2, 0x800a
/* DF7A7C 8024107C 2652A674 */  addiu     $s2, $s2, -0x598c
/* DF7A80 80241080 96250000 */  lhu       $a1, ($s1)
/* DF7A84 80241084 8E420000 */  lw        $v0, ($s2)
/* DF7A88 80241088 00052980 */  sll       $a1, $a1, 6
/* DF7A8C 8024108C 00B52821 */  addu      $a1, $a1, $s5
/* DF7A90 80241090 0C019D40 */  jal       guMtxF2L
/* DF7A94 80241094 00452821 */   addu     $a1, $v0, $a1
/* DF7A98 80241098 3C02DA38 */  lui       $v0, 0xda38
/* DF7A9C 8024109C 34420002 */  ori       $v0, $v0, 2
/* DF7AA0 802410A0 3C13800A */  lui       $s3, 0x800a
/* DF7AA4 802410A4 2673A66C */  addiu     $s3, $s3, -0x5994
/* DF7AA8 802410A8 8E680000 */  lw        $t0, ($s3)
/* DF7AAC 802410AC 96290000 */  lhu       $t1, ($s1)
/* DF7AB0 802410B0 0100202D */  daddu     $a0, $t0, $zero
/* DF7AB4 802410B4 AC820000 */  sw        $v0, ($a0)
/* DF7AB8 802410B8 3122FFFF */  andi      $v0, $t1, 0xffff
/* DF7ABC 802410BC 00021180 */  sll       $v0, $v0, 6
/* DF7AC0 802410C0 00551021 */  addu      $v0, $v0, $s5
/* DF7AC4 802410C4 8E430000 */  lw        $v1, ($s2)
/* DF7AC8 802410C8 25080008 */  addiu     $t0, $t0, 8
/* DF7ACC 802410CC 00621821 */  addu      $v1, $v1, $v0
/* DF7AD0 802410D0 3C028000 */  lui       $v0, 0x8000
/* DF7AD4 802410D4 00621821 */  addu      $v1, $v1, $v0
/* DF7AD8 802410D8 27A20038 */  addiu     $v0, $sp, 0x38
/* DF7ADC 802410DC AC830004 */  sw        $v1, 4($a0)
/* DF7AE0 802410E0 AFA20010 */  sw        $v0, 0x10($sp)
/* DF7AE4 802410E4 8E040004 */  lw        $a0, 4($s0)
/* DF7AE8 802410E8 8E050008 */  lw        $a1, 8($s0)
/* DF7AEC 802410EC 8E060000 */  lw        $a2, ($s0)
/* DF7AF0 802410F0 8E07000C */  lw        $a3, 0xc($s0)
/* DF7AF4 802410F4 25290001 */  addiu     $t1, $t1, 1
/* DF7AF8 802410F8 AE680000 */  sw        $t0, ($s3)
/* DF7AFC 802410FC 0C04BA38 */  jal       func_8012E8E0
/* DF7B00 80241100 A6290000 */   sh       $t1, ($s1)
/* DF7B04 80241104 0000202D */  daddu     $a0, $zero, $zero
/* DF7B08 80241108 27A50020 */  addiu     $a1, $sp, 0x20
/* DF7B0C 8024110C 3C060005 */  lui       $a2, 5
/* DF7B10 80241110 34C60040 */  ori       $a2, $a2, 0x40
/* DF7B14 80241114 0280382D */  daddu     $a3, $s4, $zero
/* DF7B18 80241118 93A20042 */  lbu       $v0, 0x42($sp)
/* DF7B1C 8024111C 3C013FE0 */  lui       $at, 0x3fe0
/* DF7B20 80241120 44810800 */  mtc1      $at, $f1
/* DF7B24 80241124 44800000 */  mtc1      $zero, $f0
/* DF7B28 80241128 8FA30038 */  lw        $v1, 0x38($sp)
/* DF7B2C 8024112C 8FA8003C */  lw        $t0, 0x3c($sp)
/* DF7B30 80241130 93A90040 */  lbu       $t1, 0x40($sp)
/* DF7B34 80241134 93AA0041 */  lbu       $t2, 0x41($sp)
/* DF7B38 80241138 44821000 */  mtc1      $v0, $f2
/* DF7B3C 8024113C 00000000 */  nop       
/* DF7B40 80241140 468010A1 */  cvt.d.w   $f2, $f2
/* DF7B44 80241144 46201082 */  mul.d     $f2, $f2, $f0
/* DF7B48 80241148 00000000 */  nop       
/* DF7B4C 8024114C A7A0002E */  sh        $zero, 0x2e($sp)
/* DF7B50 80241150 240200FF */  addiu     $v0, $zero, 0xff
/* DF7B54 80241154 A3A20030 */  sb        $v0, 0x30($sp)
/* DF7B58 80241158 AFA30020 */  sw        $v1, 0x20($sp)
/* DF7B5C 8024115C AFA80024 */  sw        $t0, 0x24($sp)
/* DF7B60 80241160 A7A90028 */  sh        $t1, 0x28($sp)
/* DF7B64 80241164 A7AA002A */  sh        $t2, 0x2a($sp)
/* DF7B68 80241168 46201087 */  neg.d     $f2, $f2
/* DF7B6C 8024116C 4620110D */  trunc.w.d $f4, $f2
/* DF7B70 80241170 44022000 */  mfc1      $v0, $f4
/* DF7B74 80241174 0C04EBDC */  jal       func_8013AF70
/* DF7B78 80241178 A7A2002C */   sh       $v0, 0x2c($sp)
/* DF7B7C 8024117C 3C04D838 */  lui       $a0, 0xd838
/* DF7B80 80241180 8E620000 */  lw        $v0, ($s3)
/* DF7B84 80241184 34840002 */  ori       $a0, $a0, 2
/* DF7B88 80241188 0040182D */  daddu     $v1, $v0, $zero
/* DF7B8C 8024118C 24420008 */  addiu     $v0, $v0, 8
/* DF7B90 80241190 AE620000 */  sw        $v0, ($s3)
/* DF7B94 80241194 24020040 */  addiu     $v0, $zero, 0x40
/* DF7B98 80241198 AC640000 */  sw        $a0, ($v1)
/* DF7B9C 8024119C AC620004 */  sw        $v0, 4($v1)
/* DF7BA0 802411A0 8FBF00A0 */  lw        $ra, 0xa0($sp)
/* DF7BA4 802411A4 8FB5009C */  lw        $s5, 0x9c($sp)
/* DF7BA8 802411A8 8FB40098 */  lw        $s4, 0x98($sp)
/* DF7BAC 802411AC 8FB30094 */  lw        $s3, 0x94($sp)
/* DF7BB0 802411B0 8FB20090 */  lw        $s2, 0x90($sp)
/* DF7BB4 802411B4 8FB1008C */  lw        $s1, 0x8c($sp)
/* DF7BB8 802411B8 8FB00088 */  lw        $s0, 0x88($sp)
/* DF7BBC 802411BC D7B600B0 */  ldc1      $f22, 0xb0($sp)
/* DF7BC0 802411C0 D7B400A8 */  ldc1      $f20, 0xa8($sp)
/* DF7BC4 802411C4 03E00008 */  jr        $ra
/* DF7BC8 802411C8 27BD00B8 */   addiu    $sp, $sp, 0xb8
