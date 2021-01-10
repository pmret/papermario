.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00CA000
/* 3D0500 E00CA000 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 3D0504 E00CA004 F7B40040 */  sdc1      $f20, 0x40($sp)
/* 3D0508 E00CA008 4485A000 */  mtc1      $a1, $f20
/* 3D050C E00CA00C F7B60048 */  sdc1      $f22, 0x48($sp)
/* 3D0510 E00CA010 4486B000 */  mtc1      $a2, $f22
/* 3D0514 E00CA014 AFB1002C */  sw        $s1, 0x2c($sp)
/* 3D0518 E00CA018 0080882D */  daddu     $s1, $a0, $zero
/* 3D051C E00CA01C F7B80050 */  sdc1      $f24, 0x50($sp)
/* 3D0520 E00CA020 4487C000 */  mtc1      $a3, $f24
/* 3D0524 E00CA024 27A40010 */  addiu     $a0, $sp, 0x10
/* 3D0528 E00CA028 AFB30034 */  sw        $s3, 0x34($sp)
/* 3D052C E00CA02C 8FB3006C */  lw        $s3, 0x6c($sp)
/* 3D0530 E00CA030 3C02E00D */  lui       $v0, %hi(func_E00CA240)
/* 3D0534 E00CA034 2442A240 */  addiu     $v0, $v0, %lo(func_E00CA240)
/* 3D0538 E00CA038 AFA20018 */  sw        $v0, 0x18($sp)
/* 3D053C E00CA03C 3C02E00D */  lui       $v0, %hi(func_E00CA248)
/* 3D0540 E00CA040 2442A248 */  addiu     $v0, $v0, %lo(func_E00CA248)
/* 3D0544 E00CA044 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3D0548 E00CA048 3C02E00D */  lui       $v0, %hi(func_E00CA484)
/* 3D054C E00CA04C 2442A484 */  addiu     $v0, $v0, %lo(func_E00CA484)
/* 3D0550 E00CA050 AFA20020 */  sw        $v0, 0x20($sp)
/* 3D0554 E00CA054 24020065 */  addiu     $v0, $zero, 0x65
/* 3D0558 E00CA058 AFBF0038 */  sw        $ra, 0x38($sp)
/* 3D055C E00CA05C AFB20030 */  sw        $s2, 0x30($sp)
/* 3D0560 E00CA060 AFB00028 */  sw        $s0, 0x28($sp)
/* 3D0564 E00CA064 AFA00010 */  sw        $zero, 0x10($sp)
/* 3D0568 E00CA068 AFA00024 */  sw        $zero, 0x24($sp)
/* 3D056C E00CA06C 0C080124 */  jal       func_E0200490
/* 3D0570 E00CA070 AFA20014 */   sw       $v0, 0x14($sp)
/* 3D0574 E00CA074 24040324 */  addiu     $a0, $zero, 0x324
/* 3D0578 E00CA078 24030001 */  addiu     $v1, $zero, 1
/* 3D057C E00CA07C 0040902D */  daddu     $s2, $v0, $zero
/* 3D0580 E00CA080 0C08012C */  jal       func_E02004B0
/* 3D0584 E00CA084 AE430008 */   sw       $v1, 8($s2)
/* 3D0588 E00CA088 0040802D */  daddu     $s0, $v0, $zero
/* 3D058C E00CA08C 16000003 */  bnez      $s0, .LE00CA09C
/* 3D0590 E00CA090 AE42000C */   sw       $v0, 0xc($s2)
.LE00CA094:
/* 3D0594 E00CA094 08032825 */  j         .LE00CA094
/* 3D0598 E00CA098 00000000 */   nop      
.LE00CA09C:
/* 3D059C E00CA09C AE110000 */  sw        $s1, ($s0)
/* 3D05A0 E00CA0A0 1E600004 */  bgtz      $s3, .LE00CA0B4
/* 3D05A4 E00CA0A4 AE000014 */   sw       $zero, 0x14($s0)
/* 3D05A8 E00CA0A8 240203E8 */  addiu     $v0, $zero, 0x3e8
/* 3D05AC E00CA0AC 0803282E */  j         .LE00CA0B8
/* 3D05B0 E00CA0B0 AE020010 */   sw       $v0, 0x10($s0)
.LE00CA0B4:
/* 3D05B4 E00CA0B4 AE130010 */  sw        $s3, 0x10($s0)
.LE00CA0B8:
/* 3D05B8 E00CA0B8 E6140004 */  swc1      $f20, 4($s0)
/* 3D05BC E00CA0BC E6160008 */  swc1      $f22, 8($s0)
/* 3D05C0 E00CA0C0 E618000C */  swc1      $f24, 0xc($s0)
/* 3D05C4 E00CA0C4 C7A00068 */  lwc1      $f0, 0x68($sp)
/* 3D05C8 E00CA0C8 24020001 */  addiu     $v0, $zero, 1
/* 3D05CC E00CA0CC 12220017 */  beq       $s1, $v0, .LE00CA12C
/* 3D05D0 E00CA0D0 E6000034 */   swc1     $f0, 0x34($s0)
/* 3D05D4 E00CA0D4 2A220002 */  slti      $v0, $s1, 2
/* 3D05D8 E00CA0D8 50400005 */  beql      $v0, $zero, .LE00CA0F0
/* 3D05DC E00CA0DC 24020002 */   addiu    $v0, $zero, 2
/* 3D05E0 E00CA0E0 1220000A */  beqz      $s1, .LE00CA10C
/* 3D05E4 E00CA0E4 2403001D */   addiu    $v1, $zero, 0x1d
/* 3D05E8 E00CA0E8 0803286D */  j         .LE00CA1B4
/* 3D05EC E00CA0EC 26020074 */   addiu    $v0, $s0, 0x74
.LE00CA0F0:
/* 3D05F0 E00CA0F0 1222001C */  beq       $s1, $v0, .LE00CA164
/* 3D05F4 E00CA0F4 240200FF */   addiu    $v0, $zero, 0xff
/* 3D05F8 E00CA0F8 24020003 */  addiu     $v0, $zero, 3
/* 3D05FC E00CA0FC 12220021 */  beq       $s1, $v0, .LE00CA184
/* 3D0600 E00CA100 2403001D */   addiu    $v1, $zero, 0x1d
/* 3D0604 E00CA104 0803286D */  j         .LE00CA1B4
/* 3D0608 E00CA108 26020074 */   addiu    $v0, $s0, 0x74
.LE00CA10C:
/* 3D060C E00CA10C 240300FF */  addiu     $v1, $zero, 0xff
/* 3D0610 E00CA110 240200E1 */  addiu     $v0, $zero, 0xe1
/* 3D0614 E00CA114 AE030018 */  sw        $v1, 0x18($s0)
/* 3D0618 E00CA118 AE03001C */  sw        $v1, 0x1c($s0)
/* 3D061C E00CA11C AE030020 */  sw        $v1, 0x20($s0)
/* 3D0620 E00CA120 AE020028 */  sw        $v0, 0x28($s0)
/* 3D0624 E00CA124 08032856 */  j         .LE00CA158
/* 3D0628 E00CA128 AE02002C */   sw       $v0, 0x2c($s0)
.LE00CA12C:
/* 3D062C E00CA12C 240300FF */  addiu     $v1, $zero, 0xff
/* 3D0630 E00CA130 240200F5 */  addiu     $v0, $zero, 0xf5
/* 3D0634 E00CA134 AE02001C */  sw        $v0, 0x1c($s0)
/* 3D0638 E00CA138 240200E6 */  addiu     $v0, $zero, 0xe6
/* 3D063C E00CA13C AE020020 */  sw        $v0, 0x20($s0)
/* 3D0640 E00CA140 2402002D */  addiu     $v0, $zero, 0x2d
/* 3D0644 E00CA144 AE020028 */  sw        $v0, 0x28($s0)
/* 3D0648 E00CA148 24020023 */  addiu     $v0, $zero, 0x23
/* 3D064C E00CA14C AE02002C */  sw        $v0, 0x2c($s0)
/* 3D0650 E00CA150 2402000F */  addiu     $v0, $zero, 0xf
/* 3D0654 E00CA154 AE030018 */  sw        $v1, 0x18($s0)
.LE00CA158:
/* 3D0658 E00CA158 AE020030 */  sw        $v0, 0x30($s0)
/* 3D065C E00CA15C 0803286B */  j         .LE00CA1AC
/* 3D0660 E00CA160 AE030024 */   sw       $v1, 0x24($s0)
.LE00CA164:
/* 3D0664 E00CA164 2403009B */  addiu     $v1, $zero, 0x9b
/* 3D0668 E00CA168 AE030028 */  sw        $v1, 0x28($s0)
/* 3D066C E00CA16C 2403007D */  addiu     $v1, $zero, 0x7d
/* 3D0670 E00CA170 AE020018 */  sw        $v0, 0x18($s0)
/* 3D0674 E00CA174 AE00001C */  sw        $zero, 0x1c($s0)
/* 3D0678 E00CA178 AE000020 */  sw        $zero, 0x20($s0)
/* 3D067C E00CA17C 08032869 */  j         .LE00CA1A4
/* 3D0680 E00CA180 AE03002C */   sw       $v1, 0x2c($s0)
.LE00CA184:
/* 3D0684 E00CA184 240200FF */  addiu     $v0, $zero, 0xff
/* 3D0688 E00CA188 24030041 */  addiu     $v1, $zero, 0x41
/* 3D068C E00CA18C AE03002C */  sw        $v1, 0x2c($s0)
/* 3D0690 E00CA190 24030014 */  addiu     $v1, $zero, 0x14
/* 3D0694 E00CA194 AE020018 */  sw        $v0, 0x18($s0)
/* 3D0698 E00CA198 AE02001C */  sw        $v0, 0x1c($s0)
/* 3D069C E00CA19C AE020020 */  sw        $v0, 0x20($s0)
/* 3D06A0 E00CA1A0 AE020028 */  sw        $v0, 0x28($s0)
.LE00CA1A4:
/* 3D06A4 E00CA1A4 AE030030 */  sw        $v1, 0x30($s0)
/* 3D06A8 E00CA1A8 AE020024 */  sw        $v0, 0x24($s0)
.LE00CA1AC:
/* 3D06AC E00CA1AC 2403001D */  addiu     $v1, $zero, 0x1d
/* 3D06B0 E00CA1B0 26020074 */  addiu     $v0, $s0, 0x74
.LE00CA1B4:
/* 3D06B4 E00CA1B4 E6140038 */  swc1      $f20, 0x38($s0)
/* 3D06B8 E00CA1B8 E616003C */  swc1      $f22, 0x3c($s0)
/* 3D06BC E00CA1BC E6180040 */  swc1      $f24, 0x40($s0)
.LE00CA1C0:
/* 3D06C0 E00CA1C0 AC400230 */  sw        $zero, 0x230($v0)
/* 3D06C4 E00CA1C4 2463FFFF */  addiu     $v1, $v1, -1
/* 3D06C8 E00CA1C8 0461FFFD */  bgez      $v1, .LE00CA1C0
/* 3D06CC E00CA1CC 2442FFFC */   addiu    $v0, $v0, -4
/* 3D06D0 E00CA1D0 2404001E */  addiu     $a0, $zero, 0x1e
/* 3D06D4 E00CA1D4 24020001 */  addiu     $v0, $zero, 1
/* 3D06D8 E00CA1D8 AE0002A8 */  sw        $zero, 0x2a8($s0)
/* 3D06DC E00CA1DC E6140050 */  swc1      $f20, 0x50($s0)
/* 3D06E0 E00CA1E0 E61600C8 */  swc1      $f22, 0xc8($s0)
/* 3D06E4 E00CA1E4 E6180140 */  swc1      $f24, 0x140($s0)
/* 3D06E8 E00CA1E8 AE020230 */  sw        $v0, 0x230($s0)
/* 3D06EC E00CA1EC AE0001B8 */  sw        $zero, 0x1b8($s0)
/* 3D06F0 E00CA1F0 0C080138 */  jal       func_E02004E0
/* 3D06F4 E00CA1F4 AE0002AC */   sw       $zero, 0x2ac($s0)
/* 3D06F8 E00CA1F8 2443000A */  addiu     $v1, $v0, 0xa
/* 3D06FC E00CA1FC 0240102D */  daddu     $v0, $s2, $zero
/* 3D0700 E00CA200 44830000 */  mtc1      $v1, $f0
/* 3D0704 E00CA204 00000000 */  nop       
/* 3D0708 E00CA208 46800020 */  cvt.s.w   $f0, $f0
/* 3D070C E00CA20C E6000044 */  swc1      $f0, 0x44($s0)
/* 3D0710 E00CA210 AE000048 */  sw        $zero, 0x48($s0)
/* 3D0714 E00CA214 AE00004C */  sw        $zero, 0x4c($s0)
/* 3D0718 E00CA218 8FBF0038 */  lw        $ra, 0x38($sp)
/* 3D071C E00CA21C 8FB30034 */  lw        $s3, 0x34($sp)
/* 3D0720 E00CA220 8FB20030 */  lw        $s2, 0x30($sp)
/* 3D0724 E00CA224 8FB1002C */  lw        $s1, 0x2c($sp)
/* 3D0728 E00CA228 8FB00028 */  lw        $s0, 0x28($sp)
/* 3D072C E00CA22C D7B80050 */  ldc1      $f24, 0x50($sp)
/* 3D0730 E00CA230 D7B60048 */  ldc1      $f22, 0x48($sp)
/* 3D0734 E00CA234 D7B40040 */  ldc1      $f20, 0x40($sp)
/* 3D0738 E00CA238 03E00008 */  jr        $ra
/* 3D073C E00CA23C 27BD0058 */   addiu    $sp, $sp, 0x58
