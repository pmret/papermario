.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_37_main
/* 3584C0 E004A000 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* 3584C4 E004A004 F7B40040 */  sdc1      $f20, 0x40($sp)
/* 3584C8 E004A008 4485A000 */  mtc1      $a1, $f20
/* 3584CC E004A00C F7B60048 */  sdc1      $f22, 0x48($sp)
/* 3584D0 E004A010 4486B000 */  mtc1      $a2, $f22
/* 3584D4 E004A014 AFB20030 */  sw        $s2, 0x30($sp)
/* 3584D8 E004A018 0080902D */  daddu     $s2, $a0, $zero
/* 3584DC E004A01C F7B80050 */  sdc1      $f24, 0x50($sp)
/* 3584E0 E004A020 4487C000 */  mtc1      $a3, $f24
/* 3584E4 E004A024 27A40010 */  addiu     $a0, $sp, 0x10
/* 3584E8 E004A028 F7BA0058 */  sdc1      $f26, 0x58($sp)
/* 3584EC E004A02C 4480D000 */  mtc1      $zero, $f26
/* 3584F0 E004A030 24020001 */  addiu     $v0, $zero, 1
/* 3584F4 E004A034 AFBF0038 */  sw        $ra, 0x38($sp)
/* 3584F8 E004A038 AFB30034 */  sw        $s3, 0x34($sp)
/* 3584FC E004A03C AFB1002C */  sw        $s1, 0x2c($sp)
/* 358500 E004A040 1242000E */  beq       $s2, $v0, .LE004A07C
/* 358504 E004A044 AFB00028 */   sw       $s0, 0x28($sp)
/* 358508 E004A048 2A420002 */  slti      $v0, $s2, 2
/* 35850C E004A04C 10400005 */  beqz      $v0, .LE004A064
/* 358510 E004A050 24020002 */   addiu    $v0, $zero, 2
/* 358514 E004A054 12400007 */  beqz      $s2, .LE004A074
/* 358518 E004A058 24120005 */   addiu    $s2, $zero, 5
/* 35851C E004A05C 08012823 */  j         .LE004A08C
/* 358520 E004A060 24020001 */   addiu    $v0, $zero, 1
.LE004A064:
/* 358524 E004A064 12420007 */  beq       $s2, $v0, .LE004A084
/* 358528 E004A068 24120005 */   addiu    $s2, $zero, 5
/* 35852C E004A06C 08012823 */  j         .LE004A08C
/* 358530 E004A070 24020001 */   addiu    $v0, $zero, 1
.LE004A074:
/* 358534 E004A074 08012822 */  j         .LE004A088
/* 358538 E004A078 24120003 */   addiu    $s2, $zero, 3
.LE004A07C:
/* 35853C E004A07C 08012822 */  j         .LE004A088
/* 358540 E004A080 24120002 */   addiu    $s2, $zero, 2
.LE004A084:
/* 358544 E004A084 24120004 */  addiu     $s2, $zero, 4
.LE004A088:
/* 358548 E004A088 24020001 */  addiu     $v0, $zero, 1
.LE004A08C:
/* 35854C E004A08C 1242000D */  beq       $s2, $v0, .LE004A0C4
/* 358550 E004A090 2A420002 */   slti     $v0, $s2, 2
/* 358554 E004A094 10400005 */  beqz      $v0, .LE004A0AC
/* 358558 E004A098 24020002 */   addiu    $v0, $zero, 2
/* 35855C E004A09C 1240000B */  beqz      $s2, .LE004A0CC
/* 358560 E004A0A0 24130002 */   addiu    $s3, $zero, 2
/* 358564 E004A0A4 08012835 */  j         .LE004A0D4
/* 358568 E004A0A8 26730001 */   addiu    $s3, $s3, 1
.LE004A0AC:
/* 35856C E004A0AC 12420007 */  beq       $s2, $v0, .LE004A0CC
/* 358570 E004A0B0 24020005 */   addiu    $v0, $zero, 5
/* 358574 E004A0B4 12420005 */  beq       $s2, $v0, .LE004A0CC
/* 358578 E004A0B8 24130002 */   addiu    $s3, $zero, 2
/* 35857C E004A0BC 08012835 */  j         .LE004A0D4
/* 358580 E004A0C0 26730001 */   addiu    $s3, $s3, 1
.LE004A0C4:
/* 358584 E004A0C4 08012834 */  j         .LE004A0D0
/* 358588 E004A0C8 24130001 */   addiu    $s3, $zero, 1
.LE004A0CC:
/* 35858C E004A0CC 24130003 */  addiu     $s3, $zero, 3
.LE004A0D0:
/* 358590 E004A0D0 26730001 */  addiu     $s3, $s3, 1
.LE004A0D4:
/* 358594 E004A0D4 3C02E005 */  lui       $v0, %hi(func_E004A328)
/* 358598 E004A0D8 2442A328 */  addiu     $v0, $v0, %lo(func_E004A328)
/* 35859C E004A0DC AC820008 */  sw        $v0, 8($a0)
/* 3585A0 E004A0E0 3C02E005 */  lui       $v0, %hi(func_E004A330)
/* 3585A4 E004A0E4 2442A330 */  addiu     $v0, $v0, %lo(func_E004A330)
/* 3585A8 E004A0E8 AC82000C */  sw        $v0, 0xc($a0)
/* 3585AC E004A0EC 3C02E005 */  lui       $v0, %hi(func_E004A748)
/* 3585B0 E004A0F0 2442A748 */  addiu     $v0, $v0, %lo(func_E004A748)
/* 3585B4 E004A0F4 AC820010 */  sw        $v0, 0x10($a0)
/* 3585B8 E004A0F8 24020025 */  addiu     $v0, $zero, 0x25
/* 3585BC E004A0FC AC800000 */  sw        $zero, ($a0)
/* 3585C0 E004A100 AC800014 */  sw        $zero, 0x14($a0)
/* 3585C4 E004A104 0C080124 */  jal       func_E0200490
/* 3585C8 E004A108 AC820004 */   sw       $v0, 4($a0)
/* 3585CC E004A10C 00132040 */  sll       $a0, $s3, 1
/* 3585D0 E004A110 00932021 */  addu      $a0, $a0, $s3
/* 3585D4 E004A114 00042080 */  sll       $a0, $a0, 2
/* 3585D8 E004A118 00932023 */  subu      $a0, $a0, $s3
/* 3585DC E004A11C 000420C0 */  sll       $a0, $a0, 3
/* 3585E0 E004A120 0040802D */  daddu     $s0, $v0, $zero
/* 3585E4 E004A124 0C08012C */  jal       func_E02004B0
/* 3585E8 E004A128 AE130008 */   sw       $s3, 8($s0)
/* 3585EC E004A12C 0040882D */  daddu     $s1, $v0, $zero
/* 3585F0 E004A130 16200003 */  bnez      $s1, .LE004A140
/* 3585F4 E004A134 AE11000C */   sw       $s1, 0xc($s0)
.LE004A138:
/* 3585F8 E004A138 0801284E */  j         .LE004A138
/* 3585FC E004A13C 00000000 */   nop
.LE004A140:
/* 358600 E004A140 0220202D */  daddu     $a0, $s1, $zero
/* 358604 E004A144 00132840 */  sll       $a1, $s3, 1
/* 358608 E004A148 00B32821 */  addu      $a1, $a1, $s3
/* 35860C E004A14C 00052880 */  sll       $a1, $a1, 2
/* 358610 E004A150 00B32823 */  subu      $a1, $a1, $s3
/* 358614 E004A154 0C080130 */  jal       func_E02004C0
/* 358618 E004A158 000528C0 */   sll      $a1, $a1, 3
/* 35861C E004A15C 2A420002 */  slti      $v0, $s2, 2
/* 358620 E004A160 14400002 */  bnez      $v0, .LE004A16C
/* 358624 E004A164 2402001E */   addiu    $v0, $zero, 0x1e
/* 358628 E004A168 2402003C */  addiu     $v0, $zero, 0x3c
.LE004A16C:
/* 35862C E004A16C AE220028 */  sw        $v0, 0x28($s1)
/* 358630 E004A170 240200FF */  addiu     $v0, $zero, 0xff
/* 358634 E004A174 AE220038 */  sw        $v0, 0x38($s1)
/* 358638 E004A178 2E420006 */  sltiu     $v0, $s2, 6
/* 35863C E004A17C AE20002C */  sw        $zero, 0x2c($s1)
/* 358640 E004A180 A6320000 */  sh        $s2, ($s1)
/* 358644 E004A184 E6340004 */  swc1      $f20, 4($s1)
/* 358648 E004A188 E6360008 */  swc1      $f22, 8($s1)
/* 35864C E004A18C 10400033 */  beqz      $v0, LE004A25C_35871C
/* 358650 E004A190 E638000C */   swc1     $f24, 0xc($s1)
/* 358654 E004A194 00121080 */  sll       $v0, $s2, 2
/* 358658 E004A198 3C01E005 */  lui       $at, %hi(jtbl_E004AE80)
/* 35865C E004A19C 00220821 */  addu      $at, $at, $v0
/* 358660 E004A1A0 8C22AE80 */  lw        $v0, %lo(jtbl_E004AE80)($at)
/* 358664 E004A1A4 00400008 */  jr        $v0
/* 358668 E004A1A8 00000000 */   nop
glabel LE004A1AC_35866C
/* 35866C E004A1AC 240300FF */  addiu     $v1, $zero, 0xff
/* 358670 E004A1B0 2402007A */  addiu     $v0, $zero, 0x7a
/* 358674 E004A1B4 A2220052 */  sb        $v0, 0x52($s1)
/* 358678 E004A1B8 240200F0 */  addiu     $v0, $zero, 0xf0
/* 35867C E004A1BC A2220053 */  sb        $v0, 0x53($s1)
/* 358680 E004A1C0 240200FA */  addiu     $v0, $zero, 0xfa
/* 358684 E004A1C4 A2200050 */  sb        $zero, 0x50($s1)
/* 358688 E004A1C8 A2230051 */  sb        $v1, 0x51($s1)
/* 35868C E004A1CC 080128A4 */  j         .LE004A290
/* 358690 E004A1D0 A2230054 */   sb       $v1, 0x54($s1)
glabel LE004A1D4_358694
/* 358694 E004A1D4 2402007D */  addiu     $v0, $zero, 0x7d
/* 358698 E004A1D8 A2220050 */  sb        $v0, 0x50($s1)
/* 35869C E004A1DC 24020078 */  addiu     $v0, $zero, 0x78
/* 3586A0 E004A1E0 A2220051 */  sb        $v0, 0x51($s1)
/* 3586A4 E004A1E4 24020064 */  addiu     $v0, $zero, 0x64
/* 3586A8 E004A1E8 A2220052 */  sb        $v0, 0x52($s1)
/* 3586AC E004A1EC 240200FF */  addiu     $v0, $zero, 0xff
/* 3586B0 E004A1F0 A2220053 */  sb        $v0, 0x53($s1)
/* 3586B4 E004A1F4 A2220054 */  sb        $v0, 0x54($s1)
/* 3586B8 E004A1F8 080128A4 */  j         .LE004A290
/* 3586BC E004A1FC 240200F0 */   addiu    $v0, $zero, 0xf0
glabel LE004A200_3586C0
/* 3586C0 E004A200 240200DC */  addiu     $v0, $zero, 0xdc
/* 3586C4 E004A204 A2220050 */  sb        $v0, 0x50($s1)
/* 3586C8 E004A208 240200D2 */  addiu     $v0, $zero, 0xd2
/* 3586CC E004A20C A2220051 */  sb        $v0, 0x51($s1)
/* 3586D0 E004A210 240200C8 */  addiu     $v0, $zero, 0xc8
/* 3586D4 E004A214 A2220052 */  sb        $v0, 0x52($s1)
/* 3586D8 E004A218 240200FF */  addiu     $v0, $zero, 0xff
/* 3586DC E004A21C A2220053 */  sb        $v0, 0x53($s1)
/* 3586E0 E004A220 A2220054 */  sb        $v0, 0x54($s1)
/* 3586E4 E004A224 080128A4 */  j         .LE004A290
/* 3586E8 E004A228 240200FA */   addiu    $v0, $zero, 0xfa
glabel LE004A22C_3586EC
/* 3586EC E004A22C 240200E1 */  addiu     $v0, $zero, 0xe1
/* 3586F0 E004A230 A2220050 */  sb        $v0, 0x50($s1)
/* 3586F4 E004A234 240200CC */  addiu     $v0, $zero, 0xcc
/* 3586F8 E004A238 A2220051 */  sb        $v0, 0x51($s1)
/* 3586FC E004A23C 2402005D */  addiu     $v0, $zero, 0x5d
/* 358700 E004A240 A2220052 */  sb        $v0, 0x52($s1)
/* 358704 E004A244 240200E8 */  addiu     $v0, $zero, 0xe8
/* 358708 E004A248 A2220053 */  sb        $v0, 0x53($s1)
/* 35870C E004A24C 240200E7 */  addiu     $v0, $zero, 0xe7
/* 358710 E004A250 A2220054 */  sb        $v0, 0x54($s1)
/* 358714 E004A254 080128A4 */  j         .LE004A290
/* 358718 E004A258 240200AB */   addiu    $v0, $zero, 0xab
glabel LE004A25C_35871C
/* 35871C E004A25C 24020032 */  addiu     $v0, $zero, 0x32
/* 358720 E004A260 AE220028 */  sw        $v0, 0x28($s1)
/* 358724 E004A264 240200D0 */  addiu     $v0, $zero, 0xd0
/* 358728 E004A268 A2220050 */  sb        $v0, 0x50($s1)
/* 35872C E004A26C 24020088 */  addiu     $v0, $zero, 0x88
/* 358730 E004A270 A2220051 */  sb        $v0, 0x51($s1)
/* 358734 E004A274 24020028 */  addiu     $v0, $zero, 0x28
/* 358738 E004A278 A2220052 */  sb        $v0, 0x52($s1)
/* 35873C E004A27C 240200D8 */  addiu     $v0, $zero, 0xd8
/* 358740 E004A280 A2220053 */  sb        $v0, 0x53($s1)
/* 358744 E004A284 240200A9 */  addiu     $v0, $zero, 0xa9
/* 358748 E004A288 A2220054 */  sb        $v0, 0x54($s1)
/* 35874C E004A28C 24020041 */  addiu     $v0, $zero, 0x41
.LE004A290:
/* 358750 E004A290 A2220055 */  sb        $v0, 0x55($s1)
/* 358754 E004A294 24030001 */  addiu     $v1, $zero, 1
/* 358758 E004A298 0073102A */  slt       $v0, $v1, $s3
/* 35875C E004A29C 10400017 */  beqz      $v0, .LE004A2FC
/* 358760 E004A2A0 26310058 */   addiu    $s1, $s1, 0x58
/* 358764 E004A2A4 2A480002 */  slti      $t0, $s2, 2
/* 358768 E004A2A8 26240030 */  addiu     $a0, $s1, 0x30
/* 35876C E004A2AC 2407001E */  addiu     $a3, $zero, 0x1e
/* 358770 E004A2B0 2406FFFF */  addiu     $a2, $zero, -1
/* 358774 E004A2B4 00C0282D */  daddu     $a1, $a2, $zero
.LE004A2B8:
/* 358778 E004A2B8 51000004 */  beql      $t0, $zero, .LE004A2CC
/* 35877C E004A2BC AC86001C */   sw       $a2, 0x1c($a0)
/* 358780 E004A2C0 06420002 */  bltzl     $s2, .LE004A2CC
/* 358784 E004A2C4 AC86001C */   sw       $a2, 0x1c($a0)
/* 358788 E004A2C8 AC85001C */  sw        $a1, 0x1c($a0)
.LE004A2CC:
/* 35878C E004A2CC 44870000 */  mtc1      $a3, $f0
/* 358790 E004A2D0 00000000 */  nop
/* 358794 E004A2D4 46800020 */  cvt.s.w   $f0, $f0
/* 358798 E004A2D8 24E7001E */  addiu     $a3, $a3, 0x1e
/* 35879C E004A2DC 24C6FFFD */  addiu     $a2, $a2, -3
/* 3587A0 E004A2E0 24A5FFFE */  addiu     $a1, $a1, -2
/* 3587A4 E004A2E4 24630001 */  addiu     $v1, $v1, 1
/* 3587A8 E004A2E8 E49A0004 */  swc1      $f26, 4($a0)
/* 3587AC E004A2EC E4800000 */  swc1      $f0, ($a0)
/* 3587B0 E004A2F0 0073102A */  slt       $v0, $v1, $s3
/* 3587B4 E004A2F4 1440FFF0 */  bnez      $v0, .LE004A2B8
/* 3587B8 E004A2F8 24840058 */   addiu    $a0, $a0, 0x58
.LE004A2FC:
/* 3587BC E004A2FC 8FBF0038 */  lw        $ra, 0x38($sp)
/* 3587C0 E004A300 8FB30034 */  lw        $s3, 0x34($sp)
/* 3587C4 E004A304 8FB20030 */  lw        $s2, 0x30($sp)
/* 3587C8 E004A308 8FB1002C */  lw        $s1, 0x2c($sp)
/* 3587CC E004A30C 8FB00028 */  lw        $s0, 0x28($sp)
/* 3587D0 E004A310 D7BA0058 */  ldc1      $f26, 0x58($sp)
/* 3587D4 E004A314 D7B80050 */  ldc1      $f24, 0x50($sp)
/* 3587D8 E004A318 D7B60048 */  ldc1      $f22, 0x48($sp)
/* 3587DC E004A31C D7B40040 */  ldc1      $f20, 0x40($sp)
/* 3587E0 E004A320 03E00008 */  jr        $ra
/* 3587E4 E004A324 27BD0060 */   addiu    $sp, $sp, 0x60
