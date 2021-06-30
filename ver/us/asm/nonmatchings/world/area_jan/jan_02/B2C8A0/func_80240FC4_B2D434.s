.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240FC4_B2D434
/* B2D434 80240FC4 27BDFF98 */  addiu     $sp, $sp, -0x68
/* B2D438 80240FC8 AFB40058 */  sw        $s4, 0x58($sp)
/* B2D43C 80240FCC 0080A02D */  daddu     $s4, $a0, $zero
/* B2D440 80240FD0 AFBF0060 */  sw        $ra, 0x60($sp)
/* B2D444 80240FD4 AFB5005C */  sw        $s5, 0x5c($sp)
/* B2D448 80240FD8 AFB30054 */  sw        $s3, 0x54($sp)
/* B2D44C 80240FDC AFB20050 */  sw        $s2, 0x50($sp)
/* B2D450 80240FE0 AFB1004C */  sw        $s1, 0x4c($sp)
/* B2D454 80240FE4 AFB00048 */  sw        $s0, 0x48($sp)
/* B2D458 80240FE8 8E910148 */  lw        $s1, 0x148($s4)
/* B2D45C 80240FEC 86240008 */  lh        $a0, 8($s1)
/* B2D460 80240FF0 0C00EABB */  jal       get_npc_unsafe
/* B2D464 80240FF4 00A0802D */   daddu    $s0, $a1, $zero
/* B2D468 80240FF8 8E83000C */  lw        $v1, 0xc($s4)
/* B2D46C 80240FFC 0280202D */  daddu     $a0, $s4, $zero
/* B2D470 80241000 8C650000 */  lw        $a1, ($v1)
/* B2D474 80241004 0C0B1EAF */  jal       get_variable
/* B2D478 80241008 0040902D */   daddu    $s2, $v0, $zero
/* B2D47C 8024100C AFA00018 */  sw        $zero, 0x18($sp)
/* B2D480 80241010 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B2D484 80241014 8C630094 */  lw        $v1, 0x94($v1)
/* B2D488 80241018 AFA3001C */  sw        $v1, 0x1c($sp)
/* B2D48C 8024101C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B2D490 80241020 8C630080 */  lw        $v1, 0x80($v1)
/* B2D494 80241024 AFA30020 */  sw        $v1, 0x20($sp)
/* B2D498 80241028 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B2D49C 8024102C 8C630088 */  lw        $v1, 0x88($v1)
/* B2D4A0 80241030 AFA30024 */  sw        $v1, 0x24($sp)
/* B2D4A4 80241034 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B2D4A8 80241038 8C63008C */  lw        $v1, 0x8c($v1)
/* B2D4AC 8024103C 27B50018 */  addiu     $s5, $sp, 0x18
/* B2D4B0 80241040 AFA30028 */  sw        $v1, 0x28($sp)
/* B2D4B4 80241044 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B2D4B8 80241048 3C014282 */  lui       $at, 0x4282
/* B2D4BC 8024104C 44810000 */  mtc1      $at, $f0
/* B2D4C0 80241050 8C630090 */  lw        $v1, 0x90($v1)
/* B2D4C4 80241054 0040982D */  daddu     $s3, $v0, $zero
/* B2D4C8 80241058 E7A00030 */  swc1      $f0, 0x30($sp)
/* B2D4CC 8024105C A7A00034 */  sh        $zero, 0x34($sp)
/* B2D4D0 80241060 16000005 */  bnez      $s0, .L80241078
/* B2D4D4 80241064 AFA3002C */   sw       $v1, 0x2c($sp)
/* B2D4D8 80241068 8E2200B0 */  lw        $v0, 0xb0($s1)
/* B2D4DC 8024106C 30420004 */  andi      $v0, $v0, 4
/* B2D4E0 80241070 10400044 */  beqz      $v0, .L80241184
/* B2D4E4 80241074 00000000 */   nop
.L80241078:
/* B2D4E8 80241078 2404F7FF */  addiu     $a0, $zero, -0x801
/* B2D4EC 8024107C AE800070 */  sw        $zero, 0x70($s4)
/* B2D4F0 80241080 A640008E */  sh        $zero, 0x8e($s2)
/* B2D4F4 80241084 8E2200CC */  lw        $v0, 0xcc($s1)
/* B2D4F8 80241088 8E430000 */  lw        $v1, ($s2)
/* B2D4FC 8024108C 8C420000 */  lw        $v0, ($v0)
/* B2D500 80241090 00641824 */  and       $v1, $v1, $a0
/* B2D504 80241094 AE430000 */  sw        $v1, ($s2)
/* B2D508 80241098 AE420028 */  sw        $v0, 0x28($s2)
/* B2D50C 8024109C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* B2D510 802410A0 8C420098 */  lw        $v0, 0x98($v0)
/* B2D514 802410A4 54400005 */  bnel      $v0, $zero, .L802410BC
/* B2D518 802410A8 2402FDFF */   addiu    $v0, $zero, -0x201
/* B2D51C 802410AC 34620200 */  ori       $v0, $v1, 0x200
/* B2D520 802410B0 2403FFF7 */  addiu     $v1, $zero, -9
/* B2D524 802410B4 08090431 */  j         .L802410C4
/* B2D528 802410B8 00431024 */   and      $v0, $v0, $v1
.L802410BC:
/* B2D52C 802410BC 00621024 */  and       $v0, $v1, $v0
/* B2D530 802410C0 34420008 */  ori       $v0, $v0, 8
.L802410C4:
/* B2D534 802410C4 AE420000 */  sw        $v0, ($s2)
/* B2D538 802410C8 8E2200B0 */  lw        $v0, 0xb0($s1)
/* B2D53C 802410CC 30420004 */  andi      $v0, $v0, 4
/* B2D540 802410D0 10400008 */  beqz      $v0, .L802410F4
/* B2D544 802410D4 24020063 */   addiu    $v0, $zero, 0x63
/* B2D548 802410D8 AE820070 */  sw        $v0, 0x70($s4)
/* B2D54C 802410DC AE800074 */  sw        $zero, 0x74($s4)
/* B2D550 802410E0 8E2200B0 */  lw        $v0, 0xb0($s1)
/* B2D554 802410E4 2403FFFB */  addiu     $v1, $zero, -5
/* B2D558 802410E8 00431024 */  and       $v0, $v0, $v1
/* B2D55C 802410EC 08090448 */  j         .L80241120
/* B2D560 802410F0 AE2200B0 */   sw       $v0, 0xb0($s1)
.L802410F4:
/* B2D564 802410F4 8E220000 */  lw        $v0, ($s1)
/* B2D568 802410F8 3C034000 */  lui       $v1, 0x4000
/* B2D56C 802410FC 00431024 */  and       $v0, $v0, $v1
/* B2D570 80241100 10400007 */  beqz      $v0, .L80241120
/* B2D574 80241104 3C03BFFF */   lui      $v1, 0xbfff
/* B2D578 80241108 2402000C */  addiu     $v0, $zero, 0xc
/* B2D57C 8024110C AE820070 */  sw        $v0, 0x70($s4)
/* B2D580 80241110 8E220000 */  lw        $v0, ($s1)
/* B2D584 80241114 3463FFFF */  ori       $v1, $v1, 0xffff
/* B2D588 80241118 00431024 */  and       $v0, $v0, $v1
/* B2D58C 8024111C AE220000 */  sw        $v0, ($s1)
.L80241120:
/* B2D590 80241120 27A50038 */  addiu     $a1, $sp, 0x38
/* B2D594 80241124 27A6003C */  addiu     $a2, $sp, 0x3c
/* B2D598 80241128 C6400038 */  lwc1      $f0, 0x38($s2)
/* B2D59C 8024112C 864200A8 */  lh        $v0, 0xa8($s2)
/* B2D5A0 80241130 3C0142C8 */  lui       $at, 0x42c8
/* B2D5A4 80241134 44812000 */  mtc1      $at, $f4
/* B2D5A8 80241138 44823000 */  mtc1      $v0, $f6
/* B2D5AC 8024113C 00000000 */  nop
/* B2D5B0 80241140 468031A0 */  cvt.s.w   $f6, $f6
/* B2D5B4 80241144 27A20044 */  addiu     $v0, $sp, 0x44
/* B2D5B8 80241148 E7A00038 */  swc1      $f0, 0x38($sp)
/* B2D5BC 8024114C C640003C */  lwc1      $f0, 0x3c($s2)
/* B2D5C0 80241150 C6420040 */  lwc1      $f2, 0x40($s2)
/* B2D5C4 80241154 46060000 */  add.s     $f0, $f0, $f6
/* B2D5C8 80241158 E7A40044 */  swc1      $f4, 0x44($sp)
/* B2D5CC 8024115C E7A20040 */  swc1      $f2, 0x40($sp)
/* B2D5D0 80241160 E7A0003C */  swc1      $f0, 0x3c($sp)
/* B2D5D4 80241164 AFA20010 */  sw        $v0, 0x10($sp)
/* B2D5D8 80241168 8E440080 */  lw        $a0, 0x80($s2)
/* B2D5DC 8024116C 0C0372DF */  jal       npc_raycast_down_sides
/* B2D5E0 80241170 27A70040 */   addiu    $a3, $sp, 0x40
/* B2D5E4 80241174 10400003 */  beqz      $v0, .L80241184
/* B2D5E8 80241178 00000000 */   nop
/* B2D5EC 8024117C C7A0003C */  lwc1      $f0, 0x3c($sp)
/* B2D5F0 80241180 E640003C */  swc1      $f0, 0x3c($s2)
.L80241184:
/* B2D5F4 80241184 8E830070 */  lw        $v1, 0x70($s4)
/* B2D5F8 80241188 2C620064 */  sltiu     $v0, $v1, 0x64
/* B2D5FC 8024118C 10400042 */  beqz      $v0, L80241298_B2D708
/* B2D600 80241190 00031080 */   sll      $v0, $v1, 2
/* B2D604 80241194 3C018025 */  lui       $at, %hi(jtbl_802485D0_B34A40)
/* B2D608 80241198 00220821 */  addu      $at, $at, $v0
/* B2D60C 8024119C 8C2285D0 */  lw        $v0, %lo(jtbl_802485D0_B34A40)($at)
/* B2D610 802411A0 00400008 */  jr        $v0
/* B2D614 802411A4 00000000 */   nop
glabel L802411A8_B2D618
/* B2D618 802411A8 0280202D */  daddu     $a0, $s4, $zero
/* B2D61C 802411AC 0260282D */  daddu     $a1, $s3, $zero
/* B2D620 802411B0 0C09010C */  jal       func_80240430_B2C8A0
/* B2D624 802411B4 02A0302D */   daddu    $a2, $s5, $zero
glabel L802411B8_B2D628
/* B2D628 802411B8 0280202D */  daddu     $a0, $s4, $zero
/* B2D62C 802411BC 0260282D */  daddu     $a1, $s3, $zero
/* B2D630 802411C0 0C090162 */  jal       jan_02_UnkFunc13
/* B2D634 802411C4 02A0302D */   daddu    $a2, $s5, $zero
/* B2D638 802411C8 080904A6 */  j         L80241298_B2D708
/* B2D63C 802411CC 00000000 */   nop
glabel L802411D0_B2D640
/* B2D640 802411D0 0280202D */  daddu     $a0, $s4, $zero
/* B2D644 802411D4 0260282D */  daddu     $a1, $s3, $zero
/* B2D648 802411D8 0C09020C */  jal       jan_02_UnkNpcAIFunc1
/* B2D64C 802411DC 02A0302D */   daddu    $a2, $s5, $zero
glabel L802411E0_B2D650
/* B2D650 802411E0 0280202D */  daddu     $a0, $s4, $zero
/* B2D654 802411E4 0260282D */  daddu     $a1, $s3, $zero
/* B2D658 802411E8 0C09023C */  jal       jan_02_UnkFunc14
/* B2D65C 802411EC 02A0302D */   daddu    $a2, $s5, $zero
/* B2D660 802411F0 080904A6 */  j         L80241298_B2D708
/* B2D664 802411F4 00000000 */   nop
glabel L802411F8_B2D668
/* B2D668 802411F8 0280202D */  daddu     $a0, $s4, $zero
/* B2D66C 802411FC 0260282D */  daddu     $a1, $s3, $zero
/* B2D670 80241200 0C0902AB */  jal       func_80240AAC_B2CF1C
/* B2D674 80241204 02A0302D */   daddu    $a2, $s5, $zero
/* B2D678 80241208 080904A6 */  j         L80241298_B2D708
/* B2D67C 8024120C 00000000 */   nop
glabel L80241210_B2D680
/* B2D680 80241210 0280202D */  daddu     $a0, $s4, $zero
/* B2D684 80241214 0260282D */  daddu     $a1, $s3, $zero
/* B2D688 80241218 0C0902D8 */  jal       jan_02_NpcJumpFunc2
/* B2D68C 8024121C 02A0302D */   daddu    $a2, $s5, $zero
glabel L80241220_B2D690
/* B2D690 80241220 0280202D */  daddu     $a0, $s4, $zero
/* B2D694 80241224 0260282D */  daddu     $a1, $s3, $zero
/* B2D698 80241228 0C0902F5 */  jal       jan_02_NpcJumpFunc
/* B2D69C 8024122C 02A0302D */   daddu    $a2, $s5, $zero
/* B2D6A0 80241230 080904A6 */  j         L80241298_B2D708
/* B2D6A4 80241234 00000000 */   nop
glabel L80241238_B2D6A8
/* B2D6A8 80241238 0280202D */  daddu     $a0, $s4, $zero
/* B2D6AC 8024123C 0260282D */  daddu     $a1, $s3, $zero
/* B2D6B0 80241240 0C090313 */  jal       jan_02_UnkNpcAIFunc13
/* B2D6B4 80241244 02A0302D */   daddu    $a2, $s5, $zero
glabel L80241248_B2D6B8
/* B2D6B8 80241248 0280202D */  daddu     $a0, $s4, $zero
/* B2D6BC 8024124C 0260282D */  daddu     $a1, $s3, $zero
/* B2D6C0 80241250 0C09035F */  jal       jan_02_UnkFunc15
/* B2D6C4 80241254 02A0302D */   daddu    $a2, $s5, $zero
/* B2D6C8 80241258 080904A6 */  j         L80241298_B2D708
/* B2D6CC 8024125C 00000000 */   nop
glabel L80241260_B2D6D0
/* B2D6D0 80241260 0280202D */  daddu     $a0, $s4, $zero
/* B2D6D4 80241264 0260282D */  daddu     $a1, $s3, $zero
/* B2D6D8 80241268 0C0903A7 */  jal       jan_02_UnkNpcDurationFlagFunc
/* B2D6DC 8024126C 02A0302D */   daddu    $a2, $s5, $zero
/* B2D6E0 80241270 080904A6 */  j         L80241298_B2D708
/* B2D6E4 80241274 00000000 */   nop
glabel L80241278_B2D6E8
/* B2D6E8 80241278 0280202D */  daddu     $a0, $s4, $zero
/* B2D6EC 8024127C 0260282D */  daddu     $a1, $s3, $zero
/* B2D6F0 80241280 0C0903C1 */  jal       jan_02_UnkFunc16
/* B2D6F4 80241284 02A0302D */   daddu    $a2, $s5, $zero
/* B2D6F8 80241288 080904A6 */  j         L80241298_B2D708
/* B2D6FC 8024128C 00000000 */   nop
glabel L80241290_B2D700
/* B2D700 80241290 0C0129CF */  jal       func_8004A73C
/* B2D704 80241294 0280202D */   daddu    $a0, $s4, $zero
glabel L80241298_B2D708
/* B2D708 80241298 8FBF0060 */  lw        $ra, 0x60($sp)
/* B2D70C 8024129C 8FB5005C */  lw        $s5, 0x5c($sp)
/* B2D710 802412A0 8FB40058 */  lw        $s4, 0x58($sp)
/* B2D714 802412A4 8FB30054 */  lw        $s3, 0x54($sp)
/* B2D718 802412A8 8FB20050 */  lw        $s2, 0x50($sp)
/* B2D71C 802412AC 8FB1004C */  lw        $s1, 0x4c($sp)
/* B2D720 802412B0 8FB00048 */  lw        $s0, 0x48($sp)
/* B2D724 802412B4 0000102D */  daddu     $v0, $zero, $zero
/* B2D728 802412B8 03E00008 */  jr        $ra
/* B2D72C 802412BC 27BD0068 */   addiu    $sp, $sp, 0x68
