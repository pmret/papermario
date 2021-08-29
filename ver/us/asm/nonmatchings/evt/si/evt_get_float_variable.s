.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel evt_get_float_variable
/* ECDDC 802C842C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* ECDE0 802C8430 3C02EFE8 */  lui       $v0, 0xefe8
/* ECDE4 802C8434 34422080 */  ori       $v0, $v0, 0x2080
/* ECDE8 802C8438 0045102A */  slt       $v0, $v0, $a1
/* ECDEC 802C843C 10400006 */  beqz      $v0, .L802C8458
/* ECDF0 802C8440 AFBF0010 */   sw       $ra, 0x10($sp)
/* ECDF4 802C8444 3C02F119 */  lui       $v0, 0xf119
/* ECDF8 802C8448 34424D80 */  ori       $v0, $v0, 0x4d80
/* ECDFC 802C844C 0045102A */  slt       $v0, $v0, $a1
/* ECE00 802C8450 14400005 */  bnez      $v0, .L802C8468
/* ECE04 802C8454 3C02F2E3 */   lui      $v0, 0xf2e3
.L802C8458:
/* ECE08 802C8458 44850000 */  mtc1      $a1, $f0
/* ECE0C 802C845C 00000000 */  nop
/* ECE10 802C8460 080B218D */  j         .L802C8634
/* ECE14 802C8464 46800020 */   cvt.s.w  $f0, $f0
.L802C8468:
/* ECE18 802C8468 34421100 */  ori       $v0, $v0, 0x1100
/* ECE1C 802C846C 0045102A */  slt       $v0, $v0, $a1
/* ECE20 802C8470 14400003 */  bnez      $v0, .L802C8480
/* ECE24 802C8474 3C02F545 */   lui      $v0, 0xf545
/* ECE28 802C8478 080B218B */  j         .L802C862C
/* ECE2C 802C847C 00A0202D */   daddu    $a0, $a1, $zero
.L802C8480:
/* ECE30 802C8480 34426B00 */  ori       $v0, $v0, 0x6b00
/* ECE34 802C8484 0045102A */  slt       $v0, $v0, $a1
/* ECE38 802C8488 14400009 */  bnez      $v0, .L802C84B0
/* ECE3C 802C848C 3C02F676 */   lui      $v0, 0xf676
/* ECE40 802C8490 3C020B53 */  lui       $v0, 0xb53
/* ECE44 802C8494 34422B80 */  ori       $v0, $v0, 0x2b80
/* ECE48 802C8498 00A22821 */  addu      $a1, $a1, $v0
/* ECE4C 802C849C 8C83013C */  lw        $v1, 0x13c($a0)
/* ECE50 802C84A0 00051080 */  sll       $v0, $a1, 2
/* ECE54 802C84A4 00431021 */  addu      $v0, $v0, $v1
/* ECE58 802C84A8 080B218B */  j         .L802C862C
/* ECE5C 802C84AC 8C440000 */   lw       $a0, ($v0)
.L802C84B0:
/* ECE60 802C84B0 34429800 */  ori       $v0, $v0, 0x9800
/* ECE64 802C84B4 0045102A */  slt       $v0, $v0, $a1
/* ECE68 802C84B8 14400007 */  bnez      $v0, .L802C84D8
/* ECE6C 802C84BC 3C02F7A7 */   lui      $v0, 0xf7a7
/* ECE70 802C84C0 3C040A21 */  lui       $a0, 0xa21
/* ECE74 802C84C4 3484FE80 */  ori       $a0, $a0, 0xfe80
/* ECE78 802C84C8 0C05154E */  jal       get_global_byte
/* ECE7C 802C84CC 00A42021 */   addu     $a0, $a1, $a0
/* ECE80 802C84D0 080B218B */  j         .L802C862C
/* ECE84 802C84D4 0040202D */   daddu    $a0, $v0, $zero
.L802C84D8:
/* ECE88 802C84D8 3442C500 */  ori       $v0, $v0, 0xc500
/* ECE8C 802C84DC 0045102A */  slt       $v0, $v0, $a1
/* ECE90 802C84E0 14400007 */  bnez      $v0, .L802C8500
/* ECE94 802C84E4 3C02FB3B */   lui      $v0, 0xfb3b
/* ECE98 802C84E8 3C0408F0 */  lui       $a0, 0x8f0
/* ECE9C 802C84EC 3484D180 */  ori       $a0, $a0, 0xd180
/* ECEA0 802C84F0 0C051594 */  jal       get_area_byte
/* ECEA4 802C84F4 00A42021 */   addu     $a0, $a1, $a0
/* ECEA8 802C84F8 080B218B */  j         .L802C862C
/* ECEAC 802C84FC 0040202D */   daddu    $a0, $v0, $zero
.L802C8500:
/* ECEB0 802C8500 34424C00 */  ori       $v0, $v0, 0x4c00
/* ECEB4 802C8504 0045102A */  slt       $v0, $v0, $a1
/* ECEB8 802C8508 14400015 */  bnez      $v0, .L802C8560
/* ECEBC 802C850C 3C02FC6C */   lui      $v0, 0xfc6c
/* ECEC0 802C8510 3C02055D */  lui       $v0, 0x55d
/* ECEC4 802C8514 34424A80 */  ori       $v0, $v0, 0x4a80
/* ECEC8 802C8518 00A22821 */  addu      $a1, $a1, $v0
/* ECECC 802C851C 04A10002 */  bgez      $a1, .L802C8528
/* ECED0 802C8520 00A0182D */   daddu    $v1, $a1, $zero
/* ECED4 802C8524 24A3001F */  addiu     $v1, $a1, 0x1f
.L802C8528:
/* ECED8 802C8528 00033143 */  sra       $a2, $v1, 5
/* ECEDC 802C852C 00C0182D */  daddu     $v1, $a2, $zero
/* ECEE0 802C8530 00031140 */  sll       $v0, $v1, 5
/* ECEE4 802C8534 00A23023 */  subu      $a2, $a1, $v0
/* ECEE8 802C8538 00031880 */  sll       $v1, $v1, 2
/* ECEEC 802C853C 3C02802E */  lui       $v0, %hi(gMapFlags)
/* ECEF0 802C8540 8C42A480 */  lw        $v0, %lo(gMapFlags)($v0)
/* ECEF4 802C8544 3C013F80 */  lui       $at, 0x3f80
/* ECEF8 802C8548 44810000 */  mtc1      $at, $f0
/* ECEFC 802C854C 00621821 */  addu      $v1, $v1, $v0
/* ECF00 802C8550 24020001 */  addiu     $v0, $zero, 1
/* ECF04 802C8554 8C630000 */  lw        $v1, ($v1)
/* ECF08 802C8558 080B216D */  j         .L802C85B4
/* ECF0C 802C855C 00C21004 */   sllv     $v0, $v0, $a2
.L802C8560:
/* ECF10 802C8560 34427900 */  ori       $v0, $v0, 0x7900
/* ECF14 802C8564 0045102A */  slt       $v0, $v0, $a1
/* ECF18 802C8568 14400018 */  bnez      $v0, .L802C85CC
/* ECF1C 802C856C 3C02FD9D */   lui      $v0, 0xfd9d
/* ECF20 802C8570 3C02042C */  lui       $v0, 0x42c
/* ECF24 802C8574 34421D80 */  ori       $v0, $v0, 0x1d80
/* ECF28 802C8578 00A22821 */  addu      $a1, $a1, $v0
/* ECF2C 802C857C 04A10002 */  bgez      $a1, .L802C8588
/* ECF30 802C8580 00A0182D */   daddu    $v1, $a1, $zero
/* ECF34 802C8584 24A3001F */  addiu     $v1, $a1, 0x1f
.L802C8588:
/* ECF38 802C8588 00033143 */  sra       $a2, $v1, 5
/* ECF3C 802C858C 00C0182D */  daddu     $v1, $a2, $zero
/* ECF40 802C8590 00031140 */  sll       $v0, $v1, 5
/* ECF44 802C8594 00A23023 */  subu      $a2, $a1, $v0
/* ECF48 802C8598 00031880 */  sll       $v1, $v1, 2
/* ECF4C 802C859C 00831821 */  addu      $v1, $a0, $v1
/* ECF50 802C85A0 24020001 */  addiu     $v0, $zero, 1
/* ECF54 802C85A4 00C21004 */  sllv      $v0, $v0, $a2
/* ECF58 802C85A8 8C6300C4 */  lw        $v1, 0xc4($v1)
/* ECF5C 802C85AC 3C013F80 */  lui       $at, 0x3f80
/* ECF60 802C85B0 44810000 */  mtc1      $at, $f0
.L802C85B4:
/* ECF64 802C85B4 00622824 */  and       $a1, $v1, $v0
/* ECF68 802C85B8 14A0001E */  bnez      $a1, .L802C8634
/* ECF6C 802C85BC 00000000 */   nop
/* ECF70 802C85C0 44800000 */  mtc1      $zero, $f0
/* ECF74 802C85C4 080B218D */  j         .L802C8634
/* ECF78 802C85C8 00000000 */   nop
.L802C85CC:
/* ECF7C 802C85CC 3442A600 */  ori       $v0, $v0, 0xa600
/* ECF80 802C85D0 0045102A */  slt       $v0, $v0, $a1
/* ECF84 802C85D4 1440000A */  bnez      $v0, .L802C8600
/* ECF88 802C85D8 3C02FECE */   lui      $v0, 0xfece
/* ECF8C 802C85DC 3C0202FA */  lui       $v0, 0x2fa
/* ECF90 802C85E0 3442F080 */  ori       $v0, $v0, 0xf080
/* ECF94 802C85E4 00A22821 */  addu      $a1, $a1, $v0
/* ECF98 802C85E8 3C03802E */  lui       $v1, %hi(gMapVars)
/* ECF9C 802C85EC 8C63A484 */  lw        $v1, %lo(gMapVars)($v1)
/* ECFA0 802C85F0 00051080 */  sll       $v0, $a1, 2
/* ECFA4 802C85F4 00431021 */  addu      $v0, $v0, $v1
/* ECFA8 802C85F8 080B218B */  j         .L802C862C
/* ECFAC 802C85FC 8C440000 */   lw       $a0, ($v0)
.L802C8600:
/* ECFB0 802C8600 3442D300 */  ori       $v0, $v0, 0xd300
/* ECFB4 802C8604 0045102A */  slt       $v0, $v0, $a1
/* ECFB8 802C8608 10400003 */  beqz      $v0, .L802C8618
/* ECFBC 802C860C 3C0201C9 */   lui      $v0, 0x1c9
/* ECFC0 802C8610 080B218B */  j         .L802C862C
/* ECFC4 802C8614 00A0202D */   daddu    $a0, $a1, $zero
.L802C8618:
/* ECFC8 802C8618 3442C380 */  ori       $v0, $v0, 0xc380
/* ECFCC 802C861C 00A22821 */  addu      $a1, $a1, $v0
/* ECFD0 802C8620 00051080 */  sll       $v0, $a1, 2
/* ECFD4 802C8624 00821021 */  addu      $v0, $a0, $v0
/* ECFD8 802C8628 8C440084 */  lw        $a0, 0x84($v0)
.L802C862C:
/* ECFDC 802C862C 0C0B1248 */  jal       evt_fixed_var_to_float
/* ECFE0 802C8630 00000000 */   nop
.L802C8634:
/* ECFE4 802C8634 8FBF0010 */  lw        $ra, 0x10($sp)
/* ECFE8 802C8638 03E00008 */  jr        $ra
/* ECFEC 802C863C 27BD0018 */   addiu    $sp, $sp, 0x18
