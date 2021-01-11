.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E007A88C
/* 37CDCC E007A88C 27BDFF30 */  addiu     $sp, $sp, -0xd0
/* 37CDD0 E007A890 AFBE00B8 */  sw        $fp, 0xb8($sp)
/* 37CDD4 E007A894 0080F02D */  daddu     $fp, $a0, $zero
/* 37CDD8 E007A898 3C06DB06 */  lui       $a2, 0xdb06
/* 37CDDC E007A89C 34C60024 */  ori       $a2, $a2, 0x24
/* 37CDE0 E007A8A0 27A40018 */  addiu     $a0, $sp, 0x18
/* 37CDE4 E007A8A4 AFB00098 */  sw        $s0, 0x98($sp)
/* 37CDE8 E007A8A8 3C100001 */  lui       $s0, 1
/* 37CDEC E007A8AC 36101630 */  ori       $s0, $s0, 0x1630
/* 37CDF0 E007A8B0 AFB500AC */  sw        $s5, 0xac($sp)
/* 37CDF4 E007A8B4 24150001 */  addiu     $s5, $zero, 1
/* 37CDF8 E007A8B8 AFB1009C */  sw        $s1, 0x9c($sp)
/* 37CDFC E007A8BC 3C11800A */  lui       $s1, %hi(gMasterGfxPos)
/* 37CE00 E007A8C0 2631A66C */  addiu     $s1, $s1, %lo(gMasterGfxPos)
/* 37CE04 E007A8C4 3C02E700 */  lui       $v0, 0xe700
/* 37CE08 E007A8C8 AFBF00BC */  sw        $ra, 0xbc($sp)
/* 37CE0C E007A8CC AFB700B4 */  sw        $s7, 0xb4($sp)
/* 37CE10 E007A8D0 AFB600B0 */  sw        $s6, 0xb0($sp)
/* 37CE14 E007A8D4 AFB400A8 */  sw        $s4, 0xa8($sp)
/* 37CE18 E007A8D8 AFB300A4 */  sw        $s3, 0xa4($sp)
/* 37CE1C E007A8DC AFB200A0 */  sw        $s2, 0xa0($sp)
/* 37CE20 E007A8E0 F7B600C8 */  sdc1      $f22, 0xc8($sp)
/* 37CE24 E007A8E4 F7B400C0 */  sdc1      $f20, 0xc0($sp)
/* 37CE28 E007A8E8 8E230000 */  lw        $v1, ($s1)
/* 37CE2C E007A8EC 8FD2000C */  lw        $s2, 0xc($fp)
/* 37CE30 E007A8F0 0060282D */  daddu     $a1, $v1, $zero
/* 37CE34 E007A8F4 24630008 */  addiu     $v1, $v1, 8
/* 37CE38 E007A8F8 AE230000 */  sw        $v1, ($s1)
/* 37CE3C E007A8FC ACA20000 */  sw        $v0, ($a1)
/* 37CE40 E007A900 24620008 */  addiu     $v0, $v1, 8
/* 37CE44 E007A904 ACA00004 */  sw        $zero, 4($a1)
/* 37CE48 E007A908 AE220000 */  sw        $v0, ($s1)
/* 37CE4C E007A90C AC660000 */  sw        $a2, ($v1)
/* 37CE50 E007A910 8FC50010 */  lw        $a1, 0x10($fp)
/* 37CE54 E007A914 24620010 */  addiu     $v0, $v1, 0x10
/* 37CE58 E007A918 AE220000 */  sw        $v0, ($s1)
/* 37CE5C E007A91C 8CA5001C */  lw        $a1, 0x1c($a1)
/* 37CE60 E007A920 3C02DE00 */  lui       $v0, 0xde00
/* 37CE64 E007A924 AC620008 */  sw        $v0, 8($v1)
/* 37CE68 E007A928 3C020900 */  lui       $v0, 0x900
/* 37CE6C E007A92C 24420240 */  addiu     $v0, $v0, 0x240
/* 37CE70 E007A930 AC62000C */  sw        $v0, 0xc($v1)
/* 37CE74 E007A934 3C028000 */  lui       $v0, 0x8000
/* 37CE78 E007A938 00A22821 */  addu      $a1, $a1, $v0
/* 37CE7C E007A93C AC650004 */  sw        $a1, 4($v1)
/* 37CE80 E007A940 8E450008 */  lw        $a1, 8($s2)
/* 37CE84 E007A944 8E46000C */  lw        $a2, 0xc($s2)
/* 37CE88 E007A948 8E470010 */  lw        $a3, 0x10($s2)
/* 37CE8C E007A94C 0C080108 */  jal       func_E0200420
/* 37CE90 E007A950 26520068 */   addiu    $s2, $s2, 0x68
/* 37CE94 E007A954 27A40018 */  addiu     $a0, $sp, 0x18
/* 37CE98 E007A958 3C148007 */  lui       $s4, %hi(gMatrixListPos)
/* 37CE9C E007A95C 269441F0 */  addiu     $s4, $s4, %lo(gMatrixListPos)
/* 37CEA0 E007A960 3C16800A */  lui       $s6, %hi(gDisplayContext)
/* 37CEA4 E007A964 26D6A674 */  addiu     $s6, $s6, %lo(gDisplayContext)
/* 37CEA8 E007A968 96850000 */  lhu       $a1, ($s4)
/* 37CEAC E007A96C 8EC20000 */  lw        $v0, ($s6)
/* 37CEB0 E007A970 00052980 */  sll       $a1, $a1, 6
/* 37CEB4 E007A974 00B02821 */  addu      $a1, $a1, $s0
/* 37CEB8 E007A978 0C080118 */  jal       func_E0200460
/* 37CEBC E007A97C 00452821 */   addu     $a1, $v0, $a1
/* 37CEC0 E007A980 3C03DA38 */  lui       $v1, 0xda38
/* 37CEC4 E007A984 34630002 */  ori       $v1, $v1, 2
/* 37CEC8 E007A988 8E220000 */  lw        $v0, ($s1)
/* 37CECC E007A98C 96840000 */  lhu       $a0, ($s4)
/* 37CED0 E007A990 0040282D */  daddu     $a1, $v0, $zero
/* 37CED4 E007A994 24420008 */  addiu     $v0, $v0, 8
/* 37CED8 E007A998 AE220000 */  sw        $v0, ($s1)
/* 37CEDC E007A99C 3082FFFF */  andi      $v0, $a0, 0xffff
/* 37CEE0 E007A9A0 00021180 */  sll       $v0, $v0, 6
/* 37CEE4 E007A9A4 ACA30000 */  sw        $v1, ($a1)
/* 37CEE8 E007A9A8 8EC30000 */  lw        $v1, ($s6)
/* 37CEEC E007A9AC 00501021 */  addu      $v0, $v0, $s0
/* 37CEF0 E007A9B0 00621821 */  addu      $v1, $v1, $v0
/* 37CEF4 E007A9B4 ACA30004 */  sw        $v1, 4($a1)
/* 37CEF8 E007A9B8 8FC20008 */  lw        $v0, 8($fp)
/* 37CEFC E007A9BC 00952021 */  addu      $a0, $a0, $s5
/* 37CF00 E007A9C0 02A2102A */  slt       $v0, $s5, $v0
/* 37CF04 E007A9C4 1040006F */  beqz      $v0, .LE007AB84
/* 37CF08 E007A9C8 A6840000 */   sh       $a0, ($s4)
/* 37CF0C E007A9CC 0220982D */  daddu     $s3, $s1, $zero
/* 37CF10 E007A9D0 27B10058 */  addiu     $s1, $sp, 0x58
/* 37CF14 E007A9D4 02C0B82D */  daddu     $s7, $s6, $zero
/* 37CF18 E007A9D8 0280B02D */  daddu     $s6, $s4, $zero
/* 37CF1C E007A9DC 3C140001 */  lui       $s4, 1
/* 37CF20 E007A9E0 36941630 */  ori       $s4, $s4, 0x1630
/* 37CF24 E007A9E4 2650004C */  addiu     $s0, $s2, 0x4c
/* 37CF28 E007A9E8 4480A000 */  mtc1      $zero, $f20
/* 37CF2C E007A9EC 3C013F80 */  lui       $at, 0x3f80
/* 37CF30 E007A9F0 4481B000 */  mtc1      $at, $f22
.LE007A9F4:
/* 37CF34 E007A9F4 3C05C8FF */  lui       $a1, 0xc8ff
/* 37CF38 E007A9F8 8E620000 */  lw        $v0, ($s3)
/* 37CF3C E007A9FC 34A5FF00 */  ori       $a1, $a1, 0xff00
/* 37CF40 E007AA00 0040182D */  daddu     $v1, $v0, $zero
/* 37CF44 E007AA04 24420008 */  addiu     $v0, $v0, 8
/* 37CF48 E007AA08 AE620000 */  sw        $v0, ($s3)
/* 37CF4C E007AA0C 3C02FA00 */  lui       $v0, 0xfa00
/* 37CF50 E007AA10 AC620000 */  sw        $v0, ($v1)
/* 37CF54 E007AA14 9202000F */  lbu       $v0, 0xf($s0)
/* 37CF58 E007AA18 27A40018 */  addiu     $a0, $sp, 0x18
/* 37CF5C E007AA1C 00451025 */  or        $v0, $v0, $a1
/* 37CF60 E007AA20 AC620004 */  sw        $v0, 4($v1)
/* 37CF64 E007AA24 8E05FFBC */  lw        $a1, -0x44($s0)
/* 37CF68 E007AA28 8E06FFC0 */  lw        $a2, -0x40($s0)
/* 37CF6C E007AA2C 8E07FFC4 */  lw        $a3, -0x3c($s0)
/* 37CF70 E007AA30 0C080108 */  jal       func_E0200420
/* 37CF74 E007AA34 26B50001 */   addiu    $s5, $s5, 1
/* 37CF78 E007AA38 3C08800B */  lui       $t0, %hi(gCameras)
/* 37CF7C E007AA3C 25081D80 */  addiu     $t0, $t0, %lo(gCameras)
/* 37CF80 E007AA40 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 37CF84 E007AA44 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 37CF88 E007AA48 4406A000 */  mfc1      $a2, $f20
/* 37CF8C E007AA4C 00031080 */  sll       $v0, $v1, 2
/* 37CF90 E007AA50 00431021 */  addu      $v0, $v0, $v1
/* 37CF94 E007AA54 00021080 */  sll       $v0, $v0, 2
/* 37CF98 E007AA58 00431023 */  subu      $v0, $v0, $v1
/* 37CF9C E007AA5C 000218C0 */  sll       $v1, $v0, 3
/* 37CFA0 E007AA60 00431021 */  addu      $v0, $v0, $v1
/* 37CFA4 E007AA64 000210C0 */  sll       $v0, $v0, 3
/* 37CFA8 E007AA68 00481021 */  addu      $v0, $v0, $t0
/* 37CFAC E007AA6C C440006C */  lwc1      $f0, 0x6c($v0)
/* 37CFB0 E007AA70 4407B000 */  mfc1      $a3, $f22
/* 37CFB4 E007AA74 46000007 */  neg.s     $f0, $f0
/* 37CFB8 E007AA78 44050000 */  mfc1      $a1, $f0
/* 37CFBC E007AA7C 0220202D */  daddu     $a0, $s1, $zero
/* 37CFC0 E007AA80 0C080104 */  jal       func_E0200410
/* 37CFC4 E007AA84 E7B40010 */   swc1     $f20, 0x10($sp)
/* 37CFC8 E007AA88 0220202D */  daddu     $a0, $s1, $zero
/* 37CFCC E007AA8C 27A50018 */  addiu     $a1, $sp, 0x18
/* 37CFD0 E007AA90 0C080114 */  jal       func_E0200450
/* 37CFD4 E007AA94 00A0302D */   daddu    $a2, $a1, $zero
/* 37CFD8 E007AA98 0220202D */  daddu     $a0, $s1, $zero
/* 37CFDC E007AA9C 8E05FFF8 */  lw        $a1, -8($s0)
/* 37CFE0 E007AAA0 8E06FFFC */  lw        $a2, -4($s0)
/* 37CFE4 E007AAA4 0C080110 */  jal       func_E0200440
/* 37CFE8 E007AAA8 00A0382D */   daddu    $a3, $a1, $zero
/* 37CFEC E007AAAC 0220202D */  daddu     $a0, $s1, $zero
/* 37CFF0 E007AAB0 27A50018 */  addiu     $a1, $sp, 0x18
/* 37CFF4 E007AAB4 0C080114 */  jal       func_E0200450
/* 37CFF8 E007AAB8 00A0302D */   daddu    $a2, $a1, $zero
/* 37CFFC E007AABC 0220202D */  daddu     $a0, $s1, $zero
/* 37D000 E007AAC0 E7B60010 */  swc1      $f22, 0x10($sp)
/* 37D004 E007AAC4 8E050000 */  lw        $a1, ($s0)
/* 37D008 E007AAC8 4406A000 */  mfc1      $a2, $f20
/* 37D00C E007AACC 4407A000 */  mfc1      $a3, $f20
/* 37D010 E007AAD0 0C080104 */  jal       func_E0200410
/* 37D014 E007AAD4 26100068 */   addiu    $s0, $s0, 0x68
/* 37D018 E007AAD8 0220202D */  daddu     $a0, $s1, $zero
/* 37D01C E007AADC 27A50018 */  addiu     $a1, $sp, 0x18
/* 37D020 E007AAE0 0C080114 */  jal       func_E0200450
/* 37D024 E007AAE4 00A0302D */   daddu    $a2, $a1, $zero
/* 37D028 E007AAE8 27A40018 */  addiu     $a0, $sp, 0x18
/* 37D02C E007AAEC 96C50000 */  lhu       $a1, ($s6)
/* 37D030 E007AAF0 8EE20000 */  lw        $v0, ($s7)
/* 37D034 E007AAF4 00052980 */  sll       $a1, $a1, 6
/* 37D038 E007AAF8 00B42821 */  addu      $a1, $a1, $s4
/* 37D03C E007AAFC 0C080118 */  jal       func_E0200460
/* 37D040 E007AB00 00452821 */   addu     $a1, $v0, $a1
/* 37D044 E007AB04 3C06D838 */  lui       $a2, 0xd838
/* 37D048 E007AB08 8E640000 */  lw        $a0, ($s3)
/* 37D04C E007AB0C 34C60002 */  ori       $a2, $a2, 2
/* 37D050 E007AB10 0080282D */  daddu     $a1, $a0, $zero
/* 37D054 E007AB14 24840008 */  addiu     $a0, $a0, 8
/* 37D058 E007AB18 AE640000 */  sw        $a0, ($s3)
/* 37D05C E007AB1C 96C20000 */  lhu       $v0, ($s6)
/* 37D060 E007AB20 3C03DA38 */  lui       $v1, 0xda38
/* 37D064 E007AB24 ACA30000 */  sw        $v1, ($a1)
/* 37D068 E007AB28 24430001 */  addiu     $v1, $v0, 1
/* 37D06C E007AB2C 3042FFFF */  andi      $v0, $v0, 0xffff
/* 37D070 E007AB30 00021180 */  sll       $v0, $v0, 6
/* 37D074 E007AB34 A6C30000 */  sh        $v1, ($s6)
/* 37D078 E007AB38 8EE30000 */  lw        $v1, ($s7)
/* 37D07C E007AB3C 00541021 */  addu      $v0, $v0, $s4
/* 37D080 E007AB40 00621821 */  addu      $v1, $v1, $v0
/* 37D084 E007AB44 24820008 */  addiu     $v0, $a0, 8
/* 37D088 E007AB48 ACA30004 */  sw        $v1, 4($a1)
/* 37D08C E007AB4C AE620000 */  sw        $v0, ($s3)
/* 37D090 E007AB50 3C02DE00 */  lui       $v0, 0xde00
/* 37D094 E007AB54 AC820000 */  sw        $v0, ($a0)
/* 37D098 E007AB58 3C020900 */  lui       $v0, 0x900
/* 37D09C E007AB5C 244202E8 */  addiu     $v0, $v0, 0x2e8
/* 37D0A0 E007AB60 AC820004 */  sw        $v0, 4($a0)
/* 37D0A4 E007AB64 24020040 */  addiu     $v0, $zero, 0x40
/* 37D0A8 E007AB68 AC860008 */  sw        $a2, 8($a0)
/* 37D0AC E007AB6C AC82000C */  sw        $v0, 0xc($a0)
/* 37D0B0 E007AB70 8FC20008 */  lw        $v0, 8($fp)
/* 37D0B4 E007AB74 24840010 */  addiu     $a0, $a0, 0x10
/* 37D0B8 E007AB78 02A2102A */  slt       $v0, $s5, $v0
/* 37D0BC E007AB7C 1440FF9D */  bnez      $v0, .LE007A9F4
/* 37D0C0 E007AB80 AE640000 */   sw       $a0, ($s3)
.LE007AB84:
/* 37D0C4 E007AB84 3C03D838 */  lui       $v1, 0xd838
/* 37D0C8 E007AB88 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* 37D0CC E007AB8C 2484A66C */  addiu     $a0, $a0, %lo(gMasterGfxPos)
/* 37D0D0 E007AB90 8C820000 */  lw        $v0, ($a0)
/* 37D0D4 E007AB94 34630002 */  ori       $v1, $v1, 2
/* 37D0D8 E007AB98 0040282D */  daddu     $a1, $v0, $zero
/* 37D0DC E007AB9C 24420008 */  addiu     $v0, $v0, 8
/* 37D0E0 E007ABA0 AC820000 */  sw        $v0, ($a0)
/* 37D0E4 E007ABA4 ACA30000 */  sw        $v1, ($a1)
/* 37D0E8 E007ABA8 24030040 */  addiu     $v1, $zero, 0x40
/* 37D0EC E007ABAC ACA30004 */  sw        $v1, 4($a1)
/* 37D0F0 E007ABB0 24430008 */  addiu     $v1, $v0, 8
/* 37D0F4 E007ABB4 AC830000 */  sw        $v1, ($a0)
/* 37D0F8 E007ABB8 3C03E700 */  lui       $v1, 0xe700
/* 37D0FC E007ABBC AC430000 */  sw        $v1, ($v0)
/* 37D100 E007ABC0 AC400004 */  sw        $zero, 4($v0)
/* 37D104 E007ABC4 8FBF00BC */  lw        $ra, 0xbc($sp)
/* 37D108 E007ABC8 8FBE00B8 */  lw        $fp, 0xb8($sp)
/* 37D10C E007ABCC 8FB700B4 */  lw        $s7, 0xb4($sp)
/* 37D110 E007ABD0 8FB600B0 */  lw        $s6, 0xb0($sp)
/* 37D114 E007ABD4 8FB500AC */  lw        $s5, 0xac($sp)
/* 37D118 E007ABD8 8FB400A8 */  lw        $s4, 0xa8($sp)
/* 37D11C E007ABDC 8FB300A4 */  lw        $s3, 0xa4($sp)
/* 37D120 E007ABE0 8FB200A0 */  lw        $s2, 0xa0($sp)
/* 37D124 E007ABE4 8FB1009C */  lw        $s1, 0x9c($sp)
/* 37D128 E007ABE8 8FB00098 */  lw        $s0, 0x98($sp)
/* 37D12C E007ABEC D7B600C8 */  ldc1      $f22, 0xc8($sp)
/* 37D130 E007ABF0 D7B400C0 */  ldc1      $f20, 0xc0($sp)
/* 37D134 E007ABF4 03E00008 */  jr        $ra
/* 37D138 E007ABF8 27BD00D0 */   addiu    $sp, $sp, 0xd0
/* 37D13C E007ABFC 00000000 */  nop
