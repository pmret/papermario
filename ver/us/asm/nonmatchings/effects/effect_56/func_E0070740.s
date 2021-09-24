.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0070740
/* 3747F0 E0070740 27BDFF10 */  addiu     $sp, $sp, -0xf0
/* 3747F4 E0070744 3C06DB06 */  lui       $a2, 0xdb06
/* 3747F8 E0070748 34C60024 */  ori       $a2, $a2, 0x24
/* 3747FC E007074C AFA400F0 */  sw        $a0, 0xf0($sp)
/* 374800 E0070750 27A40020 */  addiu     $a0, $sp, 0x20
/* 374804 E0070754 AFB100B4 */  sw        $s1, 0xb4($sp)
/* 374808 E0070758 3C110001 */  lui       $s1, 1
/* 37480C E007075C 36311630 */  ori       $s1, $s1, 0x1630
/* 374810 E0070760 AFB500C4 */  sw        $s5, 0xc4($sp)
/* 374814 E0070764 3C15800A */  lui       $s5, %hi(gMasterGfxPos)
/* 374818 E0070768 26B5A66C */  addiu     $s5, $s5, %lo(gMasterGfxPos)
/* 37481C E007076C AFBF00D4 */  sw        $ra, 0xd4($sp)
/* 374820 E0070770 AFBE00D0 */  sw        $fp, 0xd0($sp)
/* 374824 E0070774 AFB700CC */  sw        $s7, 0xcc($sp)
/* 374828 E0070778 AFB600C8 */  sw        $s6, 0xc8($sp)
/* 37482C E007077C AFB400C0 */  sw        $s4, 0xc0($sp)
/* 374830 E0070780 AFB300BC */  sw        $s3, 0xbc($sp)
/* 374834 E0070784 AFB200B8 */  sw        $s2, 0xb8($sp)
/* 374838 E0070788 AFB000B0 */  sw        $s0, 0xb0($sp)
/* 37483C E007078C F7B800E8 */  sdc1      $f24, 0xe8($sp)
/* 374840 E0070790 F7B600E0 */  sdc1      $f22, 0xe0($sp)
/* 374844 E0070794 F7B400D8 */  sdc1      $f20, 0xd8($sp)
/* 374848 E0070798 8EA50000 */  lw        $a1, ($s5)
/* 37484C E007079C 8FAA00F0 */  lw        $t2, 0xf0($sp)
/* 374850 E00707A0 00A0182D */  daddu     $v1, $a1, $zero
/* 374854 E00707A4 8D52000C */  lw        $s2, 0xc($t2)
/* 374858 E00707A8 24A50008 */  addiu     $a1, $a1, 8
/* 37485C E00707AC AEA50000 */  sw        $a1, ($s5)
/* 374860 E00707B0 8E4A0050 */  lw        $t2, 0x50($s2)
/* 374864 E00707B4 C642004C */  lwc1      $f2, 0x4c($s2)
/* 374868 E00707B8 468010A0 */  cvt.s.w   $f2, $f2
/* 37486C E00707BC AFAA00A0 */  sw        $t2, 0xa0($sp)
/* 374870 E00707C0 8E4A0054 */  lw        $t2, 0x54($s2)
/* 374874 E00707C4 24130001 */  addiu     $s3, $zero, 1
/* 374878 E00707C8 AFAA00A4 */  sw        $t2, 0xa4($sp)
/* 37487C E00707CC 8E4A0058 */  lw        $t2, 0x58($s2)
/* 374880 E00707D0 3C02E700 */  lui       $v0, 0xe700
/* 374884 E00707D4 AFAA00A8 */  sw        $t2, 0xa8($sp)
/* 374888 E00707D8 AC620000 */  sw        $v0, ($v1)
/* 37488C E00707DC AC600004 */  sw        $zero, 4($v1)
/* 374890 E00707E0 ACA60000 */  sw        $a2, ($a1)
/* 374894 E00707E4 8FAA00F0 */  lw        $t2, 0xf0($sp)
/* 374898 E00707E8 3C01437F */  lui       $at, 0x437f
/* 37489C E00707EC 44810000 */  mtc1      $at, $f0
/* 3748A0 E00707F0 8D430010 */  lw        $v1, 0x10($t2)
/* 3748A4 E00707F4 24A20008 */  addiu     $v0, $a1, 8
/* 3748A8 E00707F8 AEA20000 */  sw        $v0, ($s5)
/* 3748AC E00707FC 8C62001C */  lw        $v0, 0x1c($v1)
/* 3748B0 E0070800 3C038000 */  lui       $v1, 0x8000
/* 3748B4 E0070804 00431021 */  addu      $v0, $v0, $v1
/* 3748B8 E0070808 ACA20004 */  sw        $v0, 4($a1)
/* 3748BC E007080C 8E450004 */  lw        $a1, 4($s2)
/* 3748C0 E0070810 8E460008 */  lw        $a2, 8($s2)
/* 3748C4 E0070814 8E47000C */  lw        $a3, 0xc($s2)
/* 3748C8 E0070818 0C080108 */  jal       shim_guTranslateF
/* 3748CC E007081C 46001503 */   div.s    $f20, $f2, $f0
/* 3748D0 E0070820 27B00060 */  addiu     $s0, $sp, 0x60
/* 3748D4 E0070824 8E450060 */  lw        $a1, 0x60($s2)
/* 3748D8 E0070828 0200202D */  daddu     $a0, $s0, $zero
/* 3748DC E007082C 00A0302D */  daddu     $a2, $a1, $zero
/* 3748E0 E0070830 0C080110 */  jal       shim_guScaleF
/* 3748E4 E0070834 00A0382D */   daddu    $a3, $a1, $zero
/* 3748E8 E0070838 0200202D */  daddu     $a0, $s0, $zero
/* 3748EC E007083C 27A50020 */  addiu     $a1, $sp, 0x20
/* 3748F0 E0070840 0C080114 */  jal       shim_guMtxCatF
/* 3748F4 E0070844 00A0302D */   daddu    $a2, $a1, $zero
/* 3748F8 E0070848 27A40020 */  addiu     $a0, $sp, 0x20
/* 3748FC E007084C 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 374900 E0070850 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 374904 E0070854 3C16800A */  lui       $s6, %hi(gDisplayContext)
/* 374908 E0070858 26D6A674 */  addiu     $s6, $s6, %lo(gDisplayContext)
/* 37490C E007085C 96050000 */  lhu       $a1, ($s0)
/* 374910 E0070860 8EC20000 */  lw        $v0, ($s6)
/* 374914 E0070864 00052980 */  sll       $a1, $a1, 6
/* 374918 E0070868 00B12821 */  addu      $a1, $a1, $s1
/* 37491C E007086C 0C080118 */  jal       shim_guMtxF2L
/* 374920 E0070870 00452821 */   addu     $a1, $v0, $a1
/* 374924 E0070874 3C03DA38 */  lui       $v1, 0xda38
/* 374928 E0070878 34630002 */  ori       $v1, $v1, 2
/* 37492C E007087C 8EA40000 */  lw        $a0, ($s5)
/* 374930 E0070880 96020000 */  lhu       $v0, ($s0)
/* 374934 E0070884 0080282D */  daddu     $a1, $a0, $zero
/* 374938 E0070888 24840008 */  addiu     $a0, $a0, 8
/* 37493C E007088C AEA40000 */  sw        $a0, ($s5)
/* 374940 E0070890 ACA30000 */  sw        $v1, ($a1)
/* 374944 E0070894 00531821 */  addu      $v1, $v0, $s3
/* 374948 E0070898 3042FFFF */  andi      $v0, $v0, 0xffff
/* 37494C E007089C 00021180 */  sll       $v0, $v0, 6
/* 374950 E00708A0 00511021 */  addu      $v0, $v0, $s1
/* 374954 E00708A4 A6030000 */  sh        $v1, ($s0)
/* 374958 E00708A8 8EC30000 */  lw        $v1, ($s6)
/* 37495C E00708AC 24870010 */  addiu     $a3, $a0, 0x10
/* 374960 E00708B0 00621821 */  addu      $v1, $v1, $v0
/* 374964 E00708B4 24820008 */  addiu     $v0, $a0, 8
/* 374968 E00708B8 ACA30004 */  sw        $v1, 4($a1)
/* 37496C E00708BC AEA20000 */  sw        $v0, ($s5)
/* 374970 E00708C0 3C02FB00 */  lui       $v0, 0xfb00
/* 374974 E00708C4 AC820000 */  sw        $v0, ($a0)
/* 374978 E00708C8 92430043 */  lbu       $v1, 0x43($s2)
/* 37497C E00708CC 92450047 */  lbu       $a1, 0x47($s2)
/* 374980 E00708D0 9246004B */  lbu       $a2, 0x4b($s2)
/* 374984 E00708D4 9248005F */  lbu       $t0, 0x5f($s2)
/* 374988 E00708D8 3C02DE00 */  lui       $v0, 0xde00
/* 37498C E00708DC AEA70000 */  sw        $a3, ($s5)
/* 374990 E00708E0 AC820008 */  sw        $v0, 8($a0)
/* 374994 E00708E4 3C020900 */  lui       $v0, 0x900
/* 374998 E00708E8 24420F20 */  addiu     $v0, $v0, 0xf20
/* 37499C E00708EC AC82000C */  sw        $v0, 0xc($a0)
/* 3749A0 E00708F0 24820018 */  addiu     $v0, $a0, 0x18
/* 3749A4 E00708F4 AEA20000 */  sw        $v0, ($s5)
/* 3749A8 E00708F8 00031E00 */  sll       $v1, $v1, 0x18
/* 3749AC E00708FC 00052C00 */  sll       $a1, $a1, 0x10
/* 3749B0 E0070900 00651825 */  or        $v1, $v1, $a1
/* 3749B4 E0070904 00063200 */  sll       $a2, $a2, 8
/* 3749B8 E0070908 00661825 */  or        $v1, $v1, $a2
/* 3749BC E007090C 00681825 */  or        $v1, $v1, $t0
/* 3749C0 E0070910 AC830004 */  sw        $v1, 4($a0)
/* 3749C4 E0070914 8FAA00F0 */  lw        $t2, 0xf0($sp)
/* 3749C8 E0070918 00E0A02D */  daddu     $s4, $a3, $zero
/* 3749CC E007091C 8D420008 */  lw        $v0, 8($t2)
/* 3749D0 E0070920 0262102A */  slt       $v0, $s3, $v0
/* 3749D4 E0070924 1040006E */  beqz      $v0, .LE0070AE0
/* 3749D8 E0070928 2652006C */   addiu    $s2, $s2, 0x6c
/* 3749DC E007092C 02C0F02D */  daddu     $fp, $s6, $zero
/* 3749E0 E0070930 0200B82D */  daddu     $s7, $s0, $zero
/* 3749E4 E0070934 3C160001 */  lui       $s6, 1
/* 3749E8 E0070938 36D61630 */  ori       $s6, $s6, 0x1630
/* 3749EC E007093C 02A0882D */  daddu     $s1, $s5, $zero
/* 3749F0 E0070940 2650004C */  addiu     $s0, $s2, 0x4c
/* 3749F4 E0070944 8FAA00A0 */  lw        $t2, 0xa0($sp)
/* 3749F8 E0070948 4480C000 */  mtc1      $zero, $f24
/* 3749FC E007094C 000A1600 */  sll       $v0, $t2, 0x18
/* 374A00 E0070950 8FAA00A4 */  lw        $t2, 0xa4($sp)
/* 374A04 E0070954 3C014F00 */  lui       $at, 0x4f00
/* 374A08 E0070958 4481B000 */  mtc1      $at, $f22
/* 374A0C E007095C 314300FF */  andi      $v1, $t2, 0xff
/* 374A10 E0070960 00031C00 */  sll       $v1, $v1, 0x10
/* 374A14 E0070964 8FAA00A8 */  lw        $t2, 0xa8($sp)
/* 374A18 E0070968 00431025 */  or        $v0, $v0, $v1
/* 374A1C E007096C 314300FF */  andi      $v1, $t2, 0xff
/* 374A20 E0070970 00031A00 */  sll       $v1, $v1, 8
/* 374A24 E0070974 0043A825 */  or        $s5, $v0, $v1
.LE0070978:
/* 374A28 E0070978 8E02FFE4 */  lw        $v0, -0x1c($s0)
/* 374A2C E007097C 04400052 */  bltz      $v0, .LE0070AC8
/* 374A30 E0070980 00000000 */   nop
/* 374A34 E0070984 C6000014 */  lwc1      $f0, 0x14($s0)
/* 374A38 E0070988 46140002 */  mul.s     $f0, $f0, $f20
/* 374A3C E007098C 00000000 */  nop
/* 374A40 E0070990 4405C000 */  mfc1      $a1, $f24
/* 374A44 E0070994 4406C000 */  mfc1      $a2, $f24
/* 374A48 E0070998 E7A00010 */  swc1      $f0, 0x10($sp)
/* 374A4C E007099C C600FFB8 */  lwc1      $f0, -0x48($s0)
/* 374A50 E00709A0 E7A00014 */  swc1      $f0, 0x14($sp)
/* 374A54 E00709A4 C600FFBC */  lwc1      $f0, -0x44($s0)
/* 374A58 E00709A8 E7A00018 */  swc1      $f0, 0x18($sp)
/* 374A5C E00709AC C600FFC0 */  lwc1      $f0, -0x40($s0)
/* 374A60 E00709B0 E7A0001C */  swc1      $f0, 0x1c($sp)
/* 374A64 E00709B4 8E07FFE8 */  lw        $a3, -0x18($s0)
/* 374A68 E00709B8 0C080180 */  jal       shim_guPositionF
/* 374A6C E00709BC 27A40020 */   addiu    $a0, $sp, 0x20
/* 374A70 E00709C0 27A40020 */  addiu     $a0, $sp, 0x20
/* 374A74 E00709C4 96E50000 */  lhu       $a1, ($s7)
/* 374A78 E00709C8 8FC20000 */  lw        $v0, ($fp)
/* 374A7C E00709CC 00052980 */  sll       $a1, $a1, 6
/* 374A80 E00709D0 00B62821 */  addu      $a1, $a1, $s6
/* 374A84 E00709D4 0C080118 */  jal       shim_guMtxF2L
/* 374A88 E00709D8 00452821 */   addu     $a1, $v0, $a1
/* 374A8C E00709DC 8E240000 */  lw        $a0, ($s1)
/* 374A90 E00709E0 0080302D */  daddu     $a2, $a0, $zero
/* 374A94 E00709E4 24840008 */  addiu     $a0, $a0, 8
/* 374A98 E00709E8 AE240000 */  sw        $a0, ($s1)
/* 374A9C E00709EC 96E50000 */  lhu       $a1, ($s7)
/* 374AA0 E00709F0 3C02DA38 */  lui       $v0, 0xda38
/* 374AA4 E00709F4 ACC20000 */  sw        $v0, ($a2)
/* 374AA8 E00709F8 8FC30000 */  lw        $v1, ($fp)
/* 374AAC E00709FC 30A2FFFF */  andi      $v0, $a1, 0xffff
/* 374AB0 E0070A00 00021180 */  sll       $v0, $v0, 6
/* 374AB4 E0070A04 00561021 */  addu      $v0, $v0, $s6
/* 374AB8 E0070A08 00621821 */  addu      $v1, $v1, $v0
/* 374ABC E0070A0C 3C02FA00 */  lui       $v0, 0xfa00
/* 374AC0 E0070A10 24A50001 */  addiu     $a1, $a1, 1
/* 374AC4 E0070A14 ACC30004 */  sw        $v1, 4($a2)
/* 374AC8 E0070A18 AC820000 */  sw        $v0, ($a0)
/* 374ACC E0070A1C C6000000 */  lwc1      $f0, ($s0)
/* 374AD0 E0070A20 46800020 */  cvt.s.w   $f0, $f0
/* 374AD4 E0070A24 46140002 */  mul.s     $f0, $f0, $f20
/* 374AD8 E0070A28 00000000 */  nop
/* 374ADC E0070A2C 24820008 */  addiu     $v0, $a0, 8
/* 374AE0 E0070A30 24840004 */  addiu     $a0, $a0, 4
/* 374AE4 E0070A34 A6E50000 */  sh        $a1, ($s7)
/* 374AE8 E0070A38 4600B03E */  c.le.s    $f22, $f0
/* 374AEC E0070A3C 00000000 */  nop
/* 374AF0 E0070A40 45010005 */  bc1t      .LE0070A58
/* 374AF4 E0070A44 AE220000 */   sw       $v0, ($s1)
/* 374AF8 E0070A48 4600010D */  trunc.w.s $f4, $f0
/* 374AFC E0070A4C 44052000 */  mfc1      $a1, $f4
/* 374B00 E0070A50 0801C29D */  j         .LE0070A74
/* 374B04 E0070A54 3C06D838 */   lui      $a2, 0xd838
.LE0070A58:
/* 374B08 E0070A58 46160001 */  sub.s     $f0, $f0, $f22
/* 374B0C E0070A5C 3C028000 */  lui       $v0, 0x8000
/* 374B10 E0070A60 4600010D */  trunc.w.s $f4, $f0
/* 374B14 E0070A64 44052000 */  mfc1      $a1, $f4
/* 374B18 E0070A68 00000000 */  nop
/* 374B1C E0070A6C 00A22825 */  or        $a1, $a1, $v0
/* 374B20 E0070A70 3C06D838 */  lui       $a2, 0xd838
.LE0070A74:
/* 374B24 E0070A74 34C60002 */  ori       $a2, $a2, 2
/* 374B28 E0070A78 30A200FF */  andi      $v0, $a1, 0xff
/* 374B2C E0070A7C 8E230000 */  lw        $v1, ($s1)
/* 374B30 E0070A80 02A21025 */  or        $v0, $s5, $v0
/* 374B34 E0070A84 AC820000 */  sw        $v0, ($a0)
/* 374B38 E0070A88 3C02DE00 */  lui       $v0, 0xde00
/* 374B3C E0070A8C 0060282D */  daddu     $a1, $v1, $zero
/* 374B40 E0070A90 24630008 */  addiu     $v1, $v1, 8
/* 374B44 E0070A94 AE230000 */  sw        $v1, ($s1)
/* 374B48 E0070A98 ACA20000 */  sw        $v0, ($a1)
/* 374B4C E0070A9C 32620007 */  andi      $v0, $s3, 7
/* 374B50 E0070AA0 00021080 */  sll       $v0, $v0, 2
/* 374B54 E0070AA4 3C04E007 */  lui       $a0, %hi(D_E0070CD0)
/* 374B58 E0070AA8 00822021 */  addu      $a0, $a0, $v0
/* 374B5C E0070AAC 8C840CD0 */  lw        $a0, %lo(D_E0070CD0)($a0)
/* 374B60 E0070AB0 24620008 */  addiu     $v0, $v1, 8
/* 374B64 E0070AB4 AE220000 */  sw        $v0, ($s1)
/* 374B68 E0070AB8 24020040 */  addiu     $v0, $zero, 0x40
/* 374B6C E0070ABC ACA40004 */  sw        $a0, 4($a1)
/* 374B70 E0070AC0 AC660000 */  sw        $a2, ($v1)
/* 374B74 E0070AC4 AC620004 */  sw        $v0, 4($v1)
.LE0070AC8:
/* 374B78 E0070AC8 8FAA00F0 */  lw        $t2, 0xf0($sp)
/* 374B7C E0070ACC 26730001 */  addiu     $s3, $s3, 1
/* 374B80 E0070AD0 8D420008 */  lw        $v0, 8($t2)
/* 374B84 E0070AD4 0262102A */  slt       $v0, $s3, $v0
/* 374B88 E0070AD8 1440FFA7 */  bnez      $v0, .LE0070978
/* 374B8C E0070ADC 2610006C */   addiu    $s0, $s0, 0x6c
.LE0070AE0:
/* 374B90 E0070AE0 27A40020 */  addiu     $a0, $sp, 0x20
/* 374B94 E0070AE4 3C150001 */  lui       $s5, 1
/* 374B98 E0070AE8 36B51630 */  ori       $s5, $s5, 0x1630
/* 374B9C E0070AEC 3C1ED838 */  lui       $fp, 0xd838
/* 374BA0 E0070AF0 37DE0002 */  ori       $fp, $fp, 2
/* 374BA4 E0070AF4 3C10800A */  lui       $s0, %hi(gMasterGfxPos)
/* 374BA8 E0070AF8 2610A66C */  addiu     $s0, $s0, %lo(gMasterGfxPos)
/* 374BAC E0070AFC 3C02DF00 */  lui       $v0, 0xdf00
/* 374BB0 E0070B00 3C16DE00 */  lui       $s6, 0xde00
/* 374BB4 E0070B04 8E030000 */  lw        $v1, ($s0)
/* 374BB8 E0070B08 3C0542F0 */  lui       $a1, 0x42f0
/* 374BBC E0070B0C 3C013ECC */  lui       $at, 0x3ecc
/* 374BC0 E0070B10 3421CCCD */  ori       $at, $at, 0xcccd
/* 374BC4 E0070B14 4481A000 */  mtc1      $at, $f20
/* 374BC8 E0070B18 4480B000 */  mtc1      $zero, $f22
/* 374BCC E0070B1C 3C013F4C */  lui       $at, 0x3f4c
/* 374BD0 E0070B20 3421CCCD */  ori       $at, $at, 0xcccd
/* 374BD4 E0070B24 4481C000 */  mtc1      $at, $f24
/* 374BD8 E0070B28 0060402D */  daddu     $t0, $v1, $zero
/* 374BDC E0070B2C 4406A000 */  mfc1      $a2, $f20
/* 374BE0 E0070B30 4407B000 */  mfc1      $a3, $f22
/* 374BE4 E0070B34 24630008 */  addiu     $v1, $v1, 8
/* 374BE8 E0070B38 AE030000 */  sw        $v1, ($s0)
/* 374BEC E0070B3C AD020000 */  sw        $v0, ($t0)
/* 374BF0 E0070B40 3C02DE01 */  lui       $v0, 0xde01
/* 374BF4 E0070B44 AD000004 */  sw        $zero, 4($t0)
/* 374BF8 E0070B48 AE820000 */  sw        $v0, ($s4)
/* 374BFC E0070B4C 24620008 */  addiu     $v0, $v1, 8
/* 374C00 E0070B50 AE830004 */  sw        $v1, 4($s4)
/* 374C04 E0070B54 26940008 */  addiu     $s4, $s4, 8
/* 374C08 E0070B58 AE020000 */  sw        $v0, ($s0)
/* 374C0C E0070B5C AC760000 */  sw        $s6, ($v1)
/* 374C10 E0070B60 AC740004 */  sw        $s4, 4($v1)
/* 374C14 E0070B64 0C080104 */  jal       shim_guRotateF
/* 374C18 E0070B68 E7B80010 */   swc1     $f24, 0x10($sp)
/* 374C1C E0070B6C 27A40020 */  addiu     $a0, $sp, 0x20
/* 374C20 E0070B70 3C118007 */  lui       $s1, %hi(gMatrixListPos)
/* 374C24 E0070B74 263141F0 */  addiu     $s1, $s1, %lo(gMatrixListPos)
/* 374C28 E0070B78 3C13800A */  lui       $s3, %hi(gDisplayContext)
/* 374C2C E0070B7C 2673A674 */  addiu     $s3, $s3, %lo(gDisplayContext)
/* 374C30 E0070B80 96250000 */  lhu       $a1, ($s1)
/* 374C34 E0070B84 8E620000 */  lw        $v0, ($s3)
/* 374C38 E0070B88 00052980 */  sll       $a1, $a1, 6
/* 374C3C E0070B8C 00B52821 */  addu      $a1, $a1, $s5
/* 374C40 E0070B90 0C080118 */  jal       shim_guMtxF2L
/* 374C44 E0070B94 00452821 */   addu     $a1, $v0, $a1
/* 374C48 E0070B98 27A40020 */  addiu     $a0, $sp, 0x20
/* 374C4C E0070B9C 3C17DA38 */  lui       $s7, 0xda38
/* 374C50 E0070BA0 8E080000 */  lw        $t0, ($s0)
/* 374C54 E0070BA4 3C05C2F0 */  lui       $a1, 0xc2f0
/* 374C58 E0070BA8 4406A000 */  mfc1      $a2, $f20
/* 374C5C E0070BAC 4407B000 */  mfc1      $a3, $f22
/* 374C60 E0070BB0 0100482D */  daddu     $t1, $t0, $zero
/* 374C64 E0070BB4 25080008 */  addiu     $t0, $t0, 8
/* 374C68 E0070BB8 AE080000 */  sw        $t0, ($s0)
/* 374C6C E0070BBC 96220000 */  lhu       $v0, ($s1)
/* 374C70 E0070BC0 24120040 */  addiu     $s2, $zero, 0x40
/* 374C74 E0070BC4 AD370000 */  sw        $s7, ($t1)
/* 374C78 E0070BC8 24430001 */  addiu     $v1, $v0, 1
/* 374C7C E0070BCC 3042FFFF */  andi      $v0, $v0, 0xffff
/* 374C80 E0070BD0 00021180 */  sll       $v0, $v0, 6
/* 374C84 E0070BD4 A6230000 */  sh        $v1, ($s1)
/* 374C88 E0070BD8 8E630000 */  lw        $v1, ($s3)
/* 374C8C E0070BDC 00551021 */  addu      $v0, $v0, $s5
/* 374C90 E0070BE0 00621821 */  addu      $v1, $v1, $v0
/* 374C94 E0070BE4 25020008 */  addiu     $v0, $t0, 8
/* 374C98 E0070BE8 AD230004 */  sw        $v1, 4($t1)
/* 374C9C E0070BEC AE020000 */  sw        $v0, ($s0)
/* 374CA0 E0070BF0 25020010 */  addiu     $v0, $t0, 0x10
/* 374CA4 E0070BF4 AD160000 */  sw        $s6, ($t0)
/* 374CA8 E0070BF8 AD140004 */  sw        $s4, 4($t0)
/* 374CAC E0070BFC AE020000 */  sw        $v0, ($s0)
/* 374CB0 E0070C00 AD1E0008 */  sw        $fp, 8($t0)
/* 374CB4 E0070C04 AD12000C */  sw        $s2, 0xc($t0)
/* 374CB8 E0070C08 0C080104 */  jal       shim_guRotateF
/* 374CBC E0070C0C E7B80010 */   swc1     $f24, 0x10($sp)
/* 374CC0 E0070C10 27A40020 */  addiu     $a0, $sp, 0x20
/* 374CC4 E0070C14 96250000 */  lhu       $a1, ($s1)
/* 374CC8 E0070C18 8E620000 */  lw        $v0, ($s3)
/* 374CCC E0070C1C 00052980 */  sll       $a1, $a1, 6
/* 374CD0 E0070C20 00B52821 */  addu      $a1, $a1, $s5
/* 374CD4 E0070C24 0C080118 */  jal       shim_guMtxF2L
/* 374CD8 E0070C28 00452821 */   addu     $a1, $v0, $a1
/* 374CDC E0070C2C 8E040000 */  lw        $a0, ($s0)
/* 374CE0 E0070C30 96220000 */  lhu       $v0, ($s1)
/* 374CE4 E0070C34 0080282D */  daddu     $a1, $a0, $zero
/* 374CE8 E0070C38 24840008 */  addiu     $a0, $a0, 8
/* 374CEC E0070C3C 24430001 */  addiu     $v1, $v0, 1
/* 374CF0 E0070C40 3042FFFF */  andi      $v0, $v0, 0xffff
/* 374CF4 E0070C44 00021180 */  sll       $v0, $v0, 6
/* 374CF8 E0070C48 AE040000 */  sw        $a0, ($s0)
/* 374CFC E0070C4C ACB70000 */  sw        $s7, ($a1)
/* 374D00 E0070C50 A6230000 */  sh        $v1, ($s1)
/* 374D04 E0070C54 8E630000 */  lw        $v1, ($s3)
/* 374D08 E0070C58 00551021 */  addu      $v0, $v0, $s5
/* 374D0C E0070C5C 00621821 */  addu      $v1, $v1, $v0
/* 374D10 E0070C60 24820008 */  addiu     $v0, $a0, 8
/* 374D14 E0070C64 ACA30004 */  sw        $v1, 4($a1)
/* 374D18 E0070C68 AE020000 */  sw        $v0, ($s0)
/* 374D1C E0070C6C 24820010 */  addiu     $v0, $a0, 0x10
/* 374D20 E0070C70 AC960000 */  sw        $s6, ($a0)
/* 374D24 E0070C74 AC940004 */  sw        $s4, 4($a0)
/* 374D28 E0070C78 AE020000 */  sw        $v0, ($s0)
/* 374D2C E0070C7C 24820018 */  addiu     $v0, $a0, 0x18
/* 374D30 E0070C80 AC9E0008 */  sw        $fp, 8($a0)
/* 374D34 E0070C84 AC92000C */  sw        $s2, 0xc($a0)
/* 374D38 E0070C88 AE020000 */  sw        $v0, ($s0)
/* 374D3C E0070C8C AC9E0010 */  sw        $fp, 0x10($a0)
/* 374D40 E0070C90 AC920014 */  sw        $s2, 0x14($a0)
/* 374D44 E0070C94 8FBF00D4 */  lw        $ra, 0xd4($sp)
/* 374D48 E0070C98 8FBE00D0 */  lw        $fp, 0xd0($sp)
/* 374D4C E0070C9C 8FB700CC */  lw        $s7, 0xcc($sp)
/* 374D50 E0070CA0 8FB600C8 */  lw        $s6, 0xc8($sp)
/* 374D54 E0070CA4 8FB500C4 */  lw        $s5, 0xc4($sp)
/* 374D58 E0070CA8 8FB400C0 */  lw        $s4, 0xc0($sp)
/* 374D5C E0070CAC 8FB300BC */  lw        $s3, 0xbc($sp)
/* 374D60 E0070CB0 8FB200B8 */  lw        $s2, 0xb8($sp)
/* 374D64 E0070CB4 8FB100B4 */  lw        $s1, 0xb4($sp)
/* 374D68 E0070CB8 8FB000B0 */  lw        $s0, 0xb0($sp)
/* 374D6C E0070CBC D7B800E8 */  ldc1      $f24, 0xe8($sp)
/* 374D70 E0070CC0 D7B600E0 */  ldc1      $f22, 0xe0($sp)
/* 374D74 E0070CC4 D7B400D8 */  ldc1      $f20, 0xd8($sp)
/* 374D78 E0070CC8 03E00008 */  jr        $ra
/* 374D7C E0070CCC 27BD00F0 */   addiu    $sp, $sp, 0xf0
