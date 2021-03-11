.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80150A50
.double 0.01, 0.0

.section .text

glabel func_8012FE78
/* C6578 8012FE78 27BDFF68 */  addiu     $sp, $sp, -0x98
/* C657C 8012FE7C F7B60090 */  sdc1      $f22, 0x90($sp)
/* C6580 8012FE80 C7B600C4 */  lwc1      $f22, 0xc4($sp)
/* C6584 8012FE84 3C018015 */  lui       $at, %hi(D_80150A50)
/* C6588 8012FE88 D4220A50 */  ldc1      $f2, %lo(D_80150A50)($at)
/* C658C 8012FE8C 8FA200AC */  lw        $v0, 0xac($sp)
/* C6590 8012FE90 AFA40098 */  sw        $a0, 0x98($sp)
/* C6594 8012FE94 8FA400B0 */  lw        $a0, 0xb0($sp)
/* C6598 8012FE98 F7B40088 */  sdc1      $f20, 0x88($sp)
/* C659C 8012FE9C C7B400C8 */  lwc1      $f20, 0xc8($sp)
/* C65A0 8012FEA0 AFB7007C */  sw        $s7, 0x7c($sp)
/* C65A4 8012FEA4 93B700AB */  lbu       $s7, 0xab($sp)
/* C65A8 8012FEA8 AFBE0080 */  sw        $fp, 0x80($sp)
/* C65AC 8012FEAC 97BE00B6 */  lhu       $fp, 0xb6($sp)
/* C65B0 8012FEB0 AFB60078 */  sw        $s6, 0x78($sp)
/* C65B4 8012FEB4 97B600BA */  lhu       $s6, 0xba($sp)
/* C65B8 8012FEB8 AFB50074 */  sw        $s5, 0x74($sp)
/* C65BC 8012FEBC 97B500C2 */  lhu       $s5, 0xc2($sp)
/* C65C0 8012FEC0 AFB40070 */  sw        $s4, 0x70($sp)
/* C65C4 8012FEC4 00A0A02D */  daddu     $s4, $a1, $zero
/* C65C8 8012FEC8 AFB3006C */  sw        $s3, 0x6c($sp)
/* C65CC 8012FECC 00C0982D */  daddu     $s3, $a2, $zero
/* C65D0 8012FED0 AFB20068 */  sw        $s2, 0x68($sp)
/* C65D4 8012FED4 00E0902D */  daddu     $s2, $a3, $zero
/* C65D8 8012FED8 AFBF0084 */  sw        $ra, 0x84($sp)
/* C65DC 8012FEDC AFB10064 */  sw        $s1, 0x64($sp)
/* C65E0 8012FEE0 AFB00060 */  sw        $s0, 0x60($sp)
/* C65E4 8012FEE4 4600B021 */  cvt.d.s   $f0, $f22
/* C65E8 8012FEE8 A3B70030 */  sb        $s7, 0x30($sp)
/* C65EC 8012FEEC 97B700BE */  lhu       $s7, 0xbe($sp)
/* C65F0 8012FEF0 4622003C */  c.lt.d    $f0, $f2
/* C65F4 8012FEF4 A7A2003E */  sh        $v0, 0x3e($sp)
/* C65F8 8012FEF8 A7A40046 */  sh        $a0, 0x46($sp)
/* C65FC 8012FEFC 4501008B */  bc1t      .L8013012C
/* C6600 8012FF00 A7B7005E */   sh       $s7, 0x5e($sp)
/* C6604 8012FF04 4600A021 */  cvt.d.s   $f0, $f20
/* C6608 8012FF08 4622003C */  c.lt.d    $f0, $f2
/* C660C 8012FF0C 00000000 */  nop
/* C6610 8012FF10 450302A9 */  bc1tl     .L801309B8
/* C6614 8012FF14 0000102D */   daddu    $v0, $zero, $zero
/* C6618 8012FF18 00021400 */  sll       $v0, $v0, 0x10
/* C661C 8012FF1C 00021C03 */  sra       $v1, $v0, 0x10
/* C6620 8012FF20 97B7005E */  lhu       $s7, 0x5e($sp)
/* C6624 8012FF24 33C5FFFF */  andi      $a1, $fp, 0xffff
/* C6628 8012FF28 02E51021 */  addu      $v0, $s7, $a1
/* C662C 8012FF2C 0062102A */  slt       $v0, $v1, $v0
/* C6630 8012FF30 1040007E */  beqz      $v0, .L8013012C
/* C6634 8012FF34 00041400 */   sll      $v0, $a0, 0x10
/* C6638 8012FF38 00022403 */  sra       $a0, $v0, 0x10
/* C663C 8012FF3C 32C6FFFF */  andi      $a2, $s6, 0xffff
/* C6640 8012FF40 02A61021 */  addu      $v0, $s5, $a2
/* C6644 8012FF44 0082102A */  slt       $v0, $a0, $v0
/* C6648 8012FF48 1040029B */  beqz      $v0, .L801309B8
/* C664C 8012FF4C 0000102D */   daddu    $v0, $zero, $zero
/* C6650 8012FF50 44941000 */  mtc1      $s4, $f2
/* C6654 8012FF54 00000000 */  nop
/* C6658 8012FF58 468010A1 */  cvt.d.w   $f2, $f2
/* C665C 8012FF5C 44832000 */  mtc1      $v1, $f4
/* C6660 8012FF60 00000000 */  nop
/* C6664 8012FF64 46802120 */  cvt.s.w   $f4, $f4
/* C6668 8012FF68 06830007 */  bgezl     $s4, .L8012FF88
/* C666C 8012FF6C 46201020 */   cvt.s.d  $f0, $f2
/* C6670 8012FF70 3C0141F0 */  lui       $at, 0x41f0
/* C6674 8012FF74 44810800 */  mtc1      $at, $f1
/* C6678 8012FF78 44800000 */  mtc1      $zero, $f0
/* C667C 8012FF7C 00000000 */  nop
/* C6680 8012FF80 46201080 */  add.d     $f2, $f2, $f0
/* C6684 8012FF84 46201020 */  cvt.s.d   $f0, $f2
.L8012FF88:
/* C6688 8012FF88 46160002 */  mul.s     $f0, $f0, $f22
/* C668C 8012FF8C 00000000 */  nop
/* C6690 8012FF90 46002000 */  add.s     $f0, $f4, $f0
/* C6694 8012FF94 4600020D */  trunc.w.s $f8, $f0
/* C6698 8012FF98 44024000 */  mfc1      $v0, $f8
/* C669C 8012FF9C 00000000 */  nop
/* C66A0 8012FFA0 00021400 */  sll       $v0, $v0, 0x10
/* C66A4 8012FFA4 00021403 */  sra       $v0, $v0, 0x10
/* C66A8 8012FFA8 00A2102A */  slt       $v0, $a1, $v0
/* C66AC 8012FFAC 10400282 */  beqz      $v0, .L801309B8
/* C66B0 8012FFB0 0000102D */   daddu    $v0, $zero, $zero
/* C66B4 8012FFB4 44931000 */  mtc1      $s3, $f2
/* C66B8 8012FFB8 00000000 */  nop
/* C66BC 8012FFBC 468010A1 */  cvt.d.w   $f2, $f2
/* C66C0 8012FFC0 44842000 */  mtc1      $a0, $f4
/* C66C4 8012FFC4 00000000 */  nop
/* C66C8 8012FFC8 46802120 */  cvt.s.w   $f4, $f4
/* C66CC 8012FFCC 06630007 */  bgezl     $s3, .L8012FFEC
/* C66D0 8012FFD0 46201020 */   cvt.s.d  $f0, $f2
/* C66D4 8012FFD4 3C0141F0 */  lui       $at, 0x41f0
/* C66D8 8012FFD8 44810800 */  mtc1      $at, $f1
/* C66DC 8012FFDC 44800000 */  mtc1      $zero, $f0
/* C66E0 8012FFE0 00000000 */  nop
/* C66E4 8012FFE4 46201080 */  add.d     $f2, $f2, $f0
/* C66E8 8012FFE8 46201020 */  cvt.s.d   $f0, $f2
.L8012FFEC:
/* C66EC 8012FFEC 46140002 */  mul.s     $f0, $f0, $f20
/* C66F0 8012FFF0 00000000 */  nop
/* C66F4 8012FFF4 46002000 */  add.s     $f0, $f4, $f0
/* C66F8 8012FFF8 4600020D */  trunc.w.s $f8, $f0
/* C66FC 8012FFFC 44024000 */  mfc1      $v0, $f8
/* C6700 80130000 00000000 */  nop
/* C6704 80130004 00021400 */  sll       $v0, $v0, 0x10
/* C6708 80130008 00021403 */  sra       $v0, $v0, 0x10
/* C670C 8013000C 00C2102A */  slt       $v0, $a2, $v0
/* C6710 80130010 10400269 */  beqz      $v0, .L801309B8
/* C6714 80130014 0000102D */   daddu    $v0, $zero, $zero
/* C6718 80130018 93A30030 */  lbu       $v1, 0x30($sp)
/* C671C 8013001C 1460000C */  bnez      $v1, .L80130050
/* C6720 80130020 24020001 */   addiu    $v0, $zero, 1
/* C6724 80130024 24E2FFFD */  addiu     $v0, $a3, -3
/* C6728 80130028 304200FF */  andi      $v0, $v0, 0xff
/* C672C 8013002C 2C420002 */  sltiu     $v0, $v0, 2
/* C6730 80130030 14400024 */  bnez      $v0, .L801300C4
/* C6734 80130034 24022000 */   addiu    $v0, $zero, 0x2000
/* C6738 80130038 324300FF */  andi      $v1, $s2, 0xff
/* C673C 8013003C 24020002 */  addiu     $v0, $zero, 2
/* C6740 80130040 1062000A */  beq       $v1, $v0, .L8013006C
/* C6744 80130044 0000102D */   daddu    $v0, $zero, $zero
/* C6748 80130048 0804C26E */  j         .L801309B8
/* C674C 8013004C 00000000 */   nop
.L80130050:
/* C6750 80130050 1462000D */  bne       $v1, $v0, .L80130088
/* C6754 80130054 24020002 */   addiu    $v0, $zero, 2
/* C6758 80130058 24E2FFFD */  addiu     $v0, $a3, -3
/* C675C 8013005C 304200FF */  andi      $v0, $v0, 0xff
/* C6760 80130060 2C420002 */  sltiu     $v0, $v0, 2
/* C6764 80130064 10400003 */  beqz      $v0, .L80130074
/* C6768 80130068 324300FF */   andi     $v1, $s2, 0xff
.L8013006C:
/* C676C 8013006C 0804C031 */  j         .L801300C4
/* C6770 80130070 24021000 */   addiu    $v0, $zero, 0x1000
.L80130074:
/* C6774 80130074 24020002 */  addiu     $v0, $zero, 2
/* C6778 80130078 1062000A */  beq       $v1, $v0, .L801300A4
/* C677C 8013007C 0000102D */   daddu    $v0, $zero, $zero
/* C6780 80130080 0804C26E */  j         .L801309B8
/* C6784 80130084 00000000 */   nop
.L80130088:
/* C6788 80130088 14620008 */  bne       $v1, $v0, .L801300AC
/* C678C 8013008C 24020003 */   addiu    $v0, $zero, 3
/* C6790 80130090 324300FF */  andi      $v1, $s2, 0xff
/* C6794 80130094 5060000B */  beql      $v1, $zero, .L801300C4
/* C6798 80130098 24020800 */   addiu    $v0, $zero, 0x800
/* C679C 8013009C 14620246 */  bne       $v1, $v0, .L801309B8
/* C67A0 801300A0 0000102D */   daddu    $v0, $zero, $zero
.L801300A4:
/* C67A4 801300A4 0804C031 */  j         .L801300C4
/* C67A8 801300A8 24020800 */   addiu    $v0, $zero, 0x800
.L801300AC:
/* C67AC 801300AC 14620242 */  bne       $v1, $v0, .L801309B8
/* C67B0 801300B0 0000102D */   daddu    $v0, $zero, $zero
/* C67B4 801300B4 324200FF */  andi      $v0, $s2, 0xff
/* C67B8 801300B8 1440023F */  bnez      $v0, .L801309B8
/* C67BC 801300BC 0000102D */   daddu    $v0, $zero, $zero
/* C67C0 801300C0 24020400 */  addiu     $v0, $zero, 0x400
.L801300C4:
/* C67C4 801300C4 16800002 */  bnez      $s4, .L801300D0
/* C67C8 801300C8 0054001B */   divu     $zero, $v0, $s4
/* C67CC 801300CC 0007000D */  break     7
.L801300D0:
/* C67D0 801300D0 00001012 */   mflo     $v0
/* C67D4 801300D4 3C013F80 */  lui       $at, 0x3f80
/* C67D8 801300D8 44810000 */  mtc1      $at, $f0
/* C67DC 801300DC 3C014480 */  lui       $at, 0x4480
/* C67E0 801300E0 44812000 */  mtc1      $at, $f4
/* C67E4 801300E4 46160083 */  div.s     $f2, $f0, $f22
/* C67E8 801300E8 46041082 */  mul.s     $f2, $f2, $f4
/* C67EC 801300EC 00000000 */  nop
/* C67F0 801300F0 46140003 */  div.s     $f0, $f0, $f20
/* C67F4 801300F4 46040002 */  mul.s     $f0, $f0, $f4
/* C67F8 801300F8 00000000 */  nop
/* C67FC 801300FC 4600120D */  trunc.w.s $f8, $f2
/* C6800 80130100 E7A8004C */  swc1      $f8, 0x4c($sp)
/* C6804 80130104 4600020D */  trunc.w.s $f8, $f0
/* C6808 80130108 E7A80050 */  swc1      $f8, 0x50($sp)
/* C680C 8013010C 0040882D */  daddu     $s1, $v0, $zero
/* C6810 80130110 3223FFFF */  andi      $v1, $s1, 0xffff
/* C6814 80130114 0263102B */  sltu      $v0, $s3, $v1
/* C6818 80130118 54400006 */  bnel      $v0, $zero, .L80130134
/* C681C 8013011C 0260882D */   daddu    $s1, $s3, $zero
/* C6820 80130120 2C620002 */  sltiu     $v0, $v1, 2
/* C6824 80130124 10400003 */  beqz      $v0, .L80130134
/* C6828 80130128 00000000 */   nop
.L8013012C:
/* C682C 8013012C 0804C26E */  j         .L801309B8
/* C6830 80130130 0000102D */   daddu    $v0, $zero, $zero
.L80130134:
/* C6834 80130134 3C013FF0 */  lui       $at, 0x3ff0
/* C6838 80130138 44811800 */  mtc1      $at, $f3
/* C683C 8013013C 44801000 */  mtc1      $zero, $f2
/* C6840 80130140 4600A021 */  cvt.d.s   $f0, $f20
/* C6844 80130144 4622003E */  c.le.d    $f0, $f2
/* C6848 80130148 00000000 */  nop
/* C684C 8013014C 45000003 */  bc1f      .L8013015C
/* C6850 80130150 00000000 */   nop
/* C6854 80130154 0804C068 */  j         .L801301A0
/* C6858 80130158 A7A00048 */   sh       $zero, 0x48($sp)
.L8013015C:
/* C685C 8013015C 3C014F00 */  lui       $at, 0x4f00
/* C6860 80130160 44810000 */  mtc1      $at, $f0
/* C6864 80130164 00000000 */  nop
/* C6868 80130168 4614003E */  c.le.s    $f0, $f20
/* C686C 8013016C 00000000 */  nop
/* C6870 80130170 45030005 */  bc1tl     .L80130188
/* C6874 80130174 4600A001 */   sub.s    $f0, $f20, $f0
/* C6878 80130178 4600A20D */  trunc.w.s $f8, $f20
/* C687C 8013017C 44034000 */  mfc1      $v1, $f8
/* C6880 80130180 0804C068 */  j         .L801301A0
/* C6884 80130184 A7A30048 */   sh       $v1, 0x48($sp)
.L80130188:
/* C6888 80130188 3C028000 */  lui       $v0, 0x8000
/* C688C 8013018C 4600020D */  trunc.w.s $f8, $f0
/* C6890 80130190 44034000 */  mfc1      $v1, $f8
/* C6894 80130194 00000000 */  nop
/* C6898 80130198 00621825 */  or        $v1, $v1, $v0
/* C689C 8013019C A7A30048 */  sh        $v1, 0x48($sp)
.L801301A0:
/* C68A0 801301A0 0280202D */  daddu     $a0, $s4, $zero
/* C68A4 801301A4 0C04BF84 */  jal       func_8012FE10
/* C68A8 801301A8 24050002 */   addiu    $a1, $zero, 2
/* C68AC 801301AC 0260202D */  daddu     $a0, $s3, $zero
/* C68B0 801301B0 24050002 */  addiu     $a1, $zero, 2
/* C68B4 801301B4 0C04BF84 */  jal       func_8012FE10
/* C68B8 801301B8 0040802D */   daddu    $s0, $v0, $zero
/* C68BC 801301BC 0000582D */  daddu     $t3, $zero, $zero
/* C68C0 801301C0 32CAFFFF */  andi      $t2, $s6, 0xffff
/* C68C4 801301C4 32A3FFFF */  andi      $v1, $s5, 0xffff
/* C68C8 801301C8 01437821 */  addu      $t7, $t2, $v1
/* C68CC 801301CC 33D8FFFF */  andi      $t8, $fp, 0xffff
/* C68D0 801301D0 3C07800A */  lui       $a3, %hi(gMasterGfxPos)
/* C68D4 801301D4 24E7A66C */  addiu     $a3, $a3, %lo(gMasterGfxPos)
/* C68D8 801301D8 3C1EF508 */  lui       $fp, 0xf508
/* C68DC 801301DC 3042000F */  andi      $v0, $v0, 0xf
/* C68E0 801301E0 00021380 */  sll       $v0, $v0, 0xe
/* C68E4 801301E4 3210000F */  andi      $s0, $s0, 0xf
/* C68E8 801301E8 00108100 */  sll       $s0, $s0, 4
/* C68EC 801301EC 3C190700 */  lui       $t9, 0x700
/* C68F0 801301F0 3C15E600 */  lui       $s5, 0xe600
/* C68F4 801301F4 00506025 */  or        $t4, $v0, $s0
/* C68F8 801301F8 2697FFFF */  addiu     $s7, $s4, -1
/* C68FC 801301FC 3229FFFF */  andi      $t1, $s1, 0xffff
/* C6900 80130200 44890000 */  mtc1      $t1, $f0
/* C6904 80130204 00000000 */  nop
/* C6908 80130208 46800020 */  cvt.s.w   $f0, $f0
/* C690C 8013020C 97A3005E */  lhu       $v1, 0x5e($sp)
/* C6910 80130210 93AE0030 */  lbu       $t6, 0x30($sp)
/* C6914 80130214 46140182 */  mul.s     $f6, $f0, $f20
/* C6918 80130218 00000000 */  nop
/* C691C 8013021C AFB7005C */  sw        $s7, 0x5c($sp)
/* C6920 80130220 AFA00010 */  sw        $zero, 0x10($sp)
/* C6924 80130224 AFA00014 */  sw        $zero, 0x14($sp)
/* C6928 80130228 0303B021 */  addu      $s6, $t8, $v1
/* C692C 8013022C 02191825 */  or        $v1, $s0, $t9
/* C6930 80130230 00436825 */  or        $t5, $v0, $v1
/* C6934 80130234 32420007 */  andi      $v0, $s2, 7
/* C6938 80130238 00024540 */  sll       $t0, $v0, 0x15
/* C693C 8013023C 32F20FFF */  andi      $s2, $s7, 0xfff
/* C6940 80130240 3C17FD08 */  lui       $s7, 0xfd08
/* C6944 80130244 02571025 */  or        $v0, $s2, $s7
/* C6948 80130248 97B7003E */  lhu       $s7, 0x3e($sp)
/* C694C 8013024C 01021025 */  or        $v0, $t0, $v0
/* C6950 80130250 AFA20054 */  sw        $v0, 0x54($sp)
/* C6954 80130254 00171400 */  sll       $v0, $s7, 0x10
/* C6958 80130258 97B70046 */  lhu       $s7, 0x46($sp)
/* C695C 8013025C 00021403 */  sra       $v0, $v0, 0x10
/* C6960 80130260 AFA20020 */  sw        $v0, 0x20($sp)
/* C6964 80130264 00171400 */  sll       $v0, $s7, 0x10
/* C6968 80130268 00021403 */  sra       $v0, $v0, 0x10
/* C696C 8013026C AFA20024 */  sw        $v0, 0x24($sp)
.L80130270:
/* C6970 80130270 44941000 */  mtc1      $s4, $f2
/* C6974 80130274 00000000 */  nop
/* C6978 80130278 468010A1 */  cvt.d.w   $f2, $f2
/* C697C 8013027C C7A00024 */  lwc1      $f0, 0x24($sp)
/* C6980 80130280 46800020 */  cvt.s.w   $f0, $f0
/* C6984 80130284 C7A40020 */  lwc1      $f4, 0x20($sp)
/* C6988 80130288 46802120 */  cvt.s.w   $f4, $f4
/* C698C 8013028C 46060000 */  add.s     $f0, $f0, $f6
/* C6990 80130290 8FA20014 */  lw        $v0, 0x14($sp)
/* C6994 80130294 8FB7005C */  lw        $s7, 0x5c($sp)
/* C6998 80130298 00491021 */  addu      $v0, $v0, $t1
/* C699C 8013029C 2442FFFF */  addiu     $v0, $v0, -1
/* C69A0 801302A0 AFB70018 */  sw        $s7, 0x18($sp)
/* C69A4 801302A4 AFA2001C */  sw        $v0, 0x1c($sp)
/* C69A8 801302A8 4600020D */  trunc.w.s $f8, $f0
/* C69AC 801302AC 44034000 */  mfc1      $v1, $f8
/* C69B0 801302B0 06810006 */  bgez      $s4, .L801302CC
/* C69B4 801302B4 AFA3002C */   sw       $v1, 0x2c($sp)
/* C69B8 801302B8 3C0141F0 */  lui       $at, 0x41f0
/* C69BC 801302BC 44810800 */  mtc1      $at, $f1
/* C69C0 801302C0 44800000 */  mtc1      $zero, $f0
/* C69C4 801302C4 00000000 */  nop
/* C69C8 801302C8 46201080 */  add.d     $f2, $f2, $f0
.L801302CC:
/* C69CC 801302CC 46201020 */  cvt.s.d   $f0, $f2
/* C69D0 801302D0 46160002 */  mul.s     $f0, $f0, $f22
/* C69D4 801302D4 00000000 */  nop
/* C69D8 801302D8 46002000 */  add.s     $f0, $f4, $f0
/* C69DC 801302DC 0000882D */  daddu     $s1, $zero, $zero
/* C69E0 801302E0 4600020D */  trunc.w.s $f8, $f0
/* C69E4 801302E4 44024000 */  mfc1      $v0, $f8
/* C69E8 801302E8 00000000 */  nop
/* C69EC 801302EC 00021400 */  sll       $v0, $v0, 0x10
/* C69F0 801302F0 00021403 */  sra       $v0, $v0, 0x10
/* C69F4 801302F4 AFA20028 */  sw        $v0, 0x28($sp)
/* C69F8 801302F8 0143102A */  slt       $v0, $t2, $v1
/* C69FC 801302FC 14400018 */  bnez      $v0, .L80130360
/* C6A00 80130300 0220802D */   daddu    $s0, $s1, $zero
/* C6A04 80130304 44890000 */  mtc1      $t1, $f0
/* C6A08 80130308 00000000 */  nop
/* C6A0C 8013030C 46800020 */  cvt.s.w   $f0, $f0
/* C6A10 80130310 46140082 */  mul.s     $f2, $f0, $f20
/* C6A14 80130314 00000000 */  nop
.L80130318:
/* C6A18 80130318 8FA20014 */  lw        $v0, 0x14($sp)
/* C6A1C 8013031C 8FA3002C */  lw        $v1, 0x2c($sp)
/* C6A20 80130320 00492021 */  addu      $a0, $v0, $t1
/* C6A24 80130324 44830000 */  mtc1      $v1, $f0
/* C6A28 80130328 00000000 */  nop
/* C6A2C 8013032C 46800020 */  cvt.s.w   $f0, $f0
/* C6A30 80130330 46020000 */  add.s     $f0, $f0, $f2
/* C6A34 80130334 AFA40014 */  sw        $a0, 0x14($sp)
/* C6A38 80130338 AFA30024 */  sw        $v1, 0x24($sp)
/* C6A3C 8013033C 4600020D */  trunc.w.s $f8, $f0
/* C6A40 80130340 44024000 */  mfc1      $v0, $f8
/* C6A44 80130344 00000000 */  nop
/* C6A48 80130348 AFA2002C */  sw        $v0, 0x2c($sp)
/* C6A4C 8013034C 004A102A */  slt       $v0, $v0, $t2
/* C6A50 80130350 1440FFF1 */  bnez      $v0, .L80130318
/* C6A54 80130354 00891021 */   addu     $v0, $a0, $t1
/* C6A58 80130358 2442FFFF */  addiu     $v0, $v0, -1
/* C6A5C 8013035C AFA2001C */  sw        $v0, 0x1c($sp)
.L80130360:
/* C6A60 80130360 8FA20024 */  lw        $v0, 0x24($sp)
/* C6A64 80130364 004A102A */  slt       $v0, $v0, $t2
/* C6A68 80130368 10400012 */  beqz      $v0, .L801303B4
/* C6A6C 8013036C 00000000 */   nop
/* C6A70 80130370 97B70046 */  lhu       $s7, 0x46($sp)
/* C6A74 80130374 00171400 */  sll       $v0, $s7, 0x10
/* C6A78 80130378 00021403 */  sra       $v0, $v0, 0x10
/* C6A7C 8013037C 004A1023 */  subu      $v0, $v0, $t2
/* C6A80 80130380 04420001 */  bltzl     $v0, .L80130388
/* C6A84 80130384 00021023 */   negu     $v0, $v0
.L80130388:
/* C6A88 80130388 44821000 */  mtc1      $v0, $f2
/* C6A8C 8013038C 00000000 */  nop
/* C6A90 80130390 468010A0 */  cvt.s.w   $f2, $f2
/* C6A94 80130394 3C014200 */  lui       $at, 0x4200
/* C6A98 80130398 44810000 */  mtc1      $at, $f0
/* C6A9C 8013039C 46141083 */  div.s     $f2, $f2, $f20
/* C6AA0 801303A0 46001002 */  mul.s     $f0, $f2, $f0
/* C6AA4 801303A4 00000000 */  nop
/* C6AA8 801303A8 AFAA0024 */  sw        $t2, 0x24($sp)
/* C6AAC 801303AC 4600020D */  trunc.w.s $f8, $f0
/* C6AB0 801303B0 44114000 */  mfc1      $s1, $f8
.L801303B4:
/* C6AB4 801303B4 8FA2001C */  lw        $v0, 0x1c($sp)
/* C6AB8 801303B8 24420001 */  addiu     $v0, $v0, 1
/* C6ABC 801303BC 14530003 */  bne       $v0, $s3, .L801303CC
/* C6AC0 801303C0 0262102B */   sltu     $v0, $s3, $v0
/* C6AC4 801303C4 0804C109 */  j         .L80130424
/* C6AC8 801303C8 240B0001 */   addiu    $t3, $zero, 1
.L801303CC:
/* C6ACC 801303CC 10400015 */  beqz      $v0, .L80130424
/* C6AD0 801303D0 2662FFFF */   addiu    $v0, $s3, -1
/* C6AD4 801303D4 44931000 */  mtc1      $s3, $f2
/* C6AD8 801303D8 00000000 */  nop
/* C6ADC 801303DC 468010A1 */  cvt.d.w   $f2, $f2
/* C6AE0 801303E0 06610006 */  bgez      $s3, .L801303FC
/* C6AE4 801303E4 AFA2001C */   sw       $v0, 0x1c($sp)
/* C6AE8 801303E8 3C0141F0 */  lui       $at, 0x41f0
/* C6AEC 801303EC 44810800 */  mtc1      $at, $f1
/* C6AF0 801303F0 44800000 */  mtc1      $zero, $f0
/* C6AF4 801303F4 00000000 */  nop
/* C6AF8 801303F8 46201080 */  add.d     $f2, $f2, $f0
.L801303FC:
/* C6AFC 801303FC 46201020 */  cvt.s.d   $f0, $f2
/* C6B00 80130400 46140002 */  mul.s     $f0, $f0, $f20
/* C6B04 80130404 00000000 */  nop
/* C6B08 80130408 240B0001 */  addiu     $t3, $zero, 1
/* C6B0C 8013040C 8FA20024 */  lw        $v0, 0x24($sp)
/* C6B10 80130410 4600020D */  trunc.w.s $f8, $f0
/* C6B14 80130414 44034000 */  mfc1      $v1, $f8
/* C6B18 80130418 00000000 */  nop
/* C6B1C 8013041C 00431021 */  addu      $v0, $v0, $v1
/* C6B20 80130420 AFA2002C */  sw        $v0, 0x2c($sp)
.L80130424:
/* C6B24 80130424 8FA3002C */  lw        $v1, 0x2c($sp)
/* C6B28 80130428 006F102A */  slt       $v0, $v1, $t7
/* C6B2C 8013042C 14400008 */  bnez      $v0, .L80130450
/* C6B30 80130430 316200FF */   andi     $v0, $t3, 0xff
/* C6B34 80130434 14400004 */  bnez      $v0, .L80130448
/* C6B38 80130438 01E3102A */   slt      $v0, $t7, $v1
/* C6B3C 8013043C AFAF002C */  sw        $t7, 0x2c($sp)
/* C6B40 80130440 0804C114 */  j         .L80130450
/* C6B44 80130444 240B0001 */   addiu    $t3, $zero, 1
.L80130448:
/* C6B48 80130448 54400001 */  bnel      $v0, $zero, .L80130450
/* C6B4C 8013044C AFAF002C */   sw       $t7, 0x2c($sp)
.L80130450:
/* C6B50 80130450 8FA20020 */  lw        $v0, 0x20($sp)
/* C6B54 80130454 0058102A */  slt       $v0, $v0, $t8
/* C6B58 80130458 10400012 */  beqz      $v0, .L801304A4
/* C6B5C 8013045C 00000000 */   nop
/* C6B60 80130460 97B7003E */  lhu       $s7, 0x3e($sp)
/* C6B64 80130464 00171400 */  sll       $v0, $s7, 0x10
/* C6B68 80130468 00021403 */  sra       $v0, $v0, 0x10
/* C6B6C 8013046C 00581023 */  subu      $v0, $v0, $t8
/* C6B70 80130470 04420001 */  bltzl     $v0, .L80130478
/* C6B74 80130474 00021023 */   negu     $v0, $v0
.L80130478:
/* C6B78 80130478 44821000 */  mtc1      $v0, $f2
/* C6B7C 8013047C 00000000 */  nop
/* C6B80 80130480 468010A0 */  cvt.s.w   $f2, $f2
/* C6B84 80130484 3C014200 */  lui       $at, 0x4200
/* C6B88 80130488 44810000 */  mtc1      $at, $f0
/* C6B8C 8013048C 46161083 */  div.s     $f2, $f2, $f22
/* C6B90 80130490 46001002 */  mul.s     $f0, $f2, $f0
/* C6B94 80130494 00000000 */  nop
/* C6B98 80130498 AFB80020 */  sw        $t8, 0x20($sp)
/* C6B9C 8013049C 4600020D */  trunc.w.s $f8, $f0
/* C6BA0 801304A0 44104000 */  mfc1      $s0, $f8
.L801304A4:
/* C6BA4 801304A4 8FA20028 */  lw        $v0, 0x28($sp)
/* C6BA8 801304A8 0056102A */  slt       $v0, $v0, $s6
/* C6BAC 801304AC 50400001 */  beql      $v0, $zero, .L801304B4
/* C6BB0 801304B0 AFB60028 */   sw       $s6, 0x28($sp)
.L801304B4:
/* C6BB4 801304B4 15C0004F */  bnez      $t6, .L801305F4
/* C6BB8 801304B8 24020001 */   addiu    $v0, $zero, 1
/* C6BBC 801304BC 00141042 */  srl       $v0, $s4, 1
/* C6BC0 801304C0 2442FFFF */  addiu     $v0, $v0, -1
/* C6BC4 801304C4 30420FFF */  andi      $v0, $v0, 0xfff
/* C6BC8 801304C8 3C17FD08 */  lui       $s7, 0xfd08
/* C6BCC 801304CC 00571025 */  or        $v0, $v0, $s7
/* C6BD0 801304D0 8CE50000 */  lw        $a1, ($a3)
/* C6BD4 801304D4 01021025 */  or        $v0, $t0, $v0
/* C6BD8 801304D8 00A0182D */  daddu     $v1, $a1, $zero
/* C6BDC 801304DC 24A50008 */  addiu     $a1, $a1, 8
/* C6BE0 801304E0 ACE50000 */  sw        $a1, ($a3)
/* C6BE4 801304E4 AC620000 */  sw        $v0, ($v1)
/* C6BE8 801304E8 8FB70098 */  lw        $s7, 0x98($sp)
/* C6BEC 801304EC AC770004 */  sw        $s7, 4($v1)
/* C6BF0 801304F0 8FA20018 */  lw        $v0, 0x18($sp)
/* C6BF4 801304F4 8FA40010 */  lw        $a0, 0x10($sp)
/* C6BF8 801304F8 24A30008 */  addiu     $v1, $a1, 8
/* C6BFC 801304FC ACE30000 */  sw        $v1, ($a3)
/* C6C00 80130500 24A30010 */  addiu     $v1, $a1, 0x10
/* C6C04 80130504 ACAD0004 */  sw        $t5, 4($a1)
/* C6C08 80130508 ACE30000 */  sw        $v1, ($a3)
/* C6C0C 8013050C 3C03F400 */  lui       $v1, 0xf400
/* C6C10 80130510 ACB50008 */  sw        $s5, 8($a1)
/* C6C14 80130514 ACA0000C */  sw        $zero, 0xc($a1)
/* C6C18 80130518 00441023 */  subu      $v0, $v0, $a0
/* C6C1C 8013051C 24420001 */  addiu     $v0, $v0, 1
/* C6C20 80130520 00021043 */  sra       $v0, $v0, 1
/* C6C24 80130524 24420007 */  addiu     $v0, $v0, 7
/* C6C28 80130528 000210C3 */  sra       $v0, $v0, 3
/* C6C2C 8013052C 304201FF */  andi      $v0, $v0, 0x1ff
/* C6C30 80130530 00021240 */  sll       $v0, $v0, 9
/* C6C34 80130534 005E1025 */  or        $v0, $v0, $fp
/* C6C38 80130538 01021025 */  or        $v0, $t0, $v0
/* C6C3C 8013053C ACA20000 */  sw        $v0, ($a1)
/* C6C40 80130540 8FA40010 */  lw        $a0, 0x10($sp)
/* C6C44 80130544 24A20018 */  addiu     $v0, $a1, 0x18
/* C6C48 80130548 ACE20000 */  sw        $v0, ($a3)
/* C6C4C 8013054C 8FA20014 */  lw        $v0, 0x14($sp)
/* C6C50 80130550 00042040 */  sll       $a0, $a0, 1
/* C6C54 80130554 30840FFF */  andi      $a0, $a0, 0xfff
/* C6C58 80130558 00042300 */  sll       $a0, $a0, 0xc
/* C6C5C 8013055C 00021080 */  sll       $v0, $v0, 2
/* C6C60 80130560 30420FFF */  andi      $v0, $v0, 0xfff
/* C6C64 80130564 00431025 */  or        $v0, $v0, $v1
/* C6C68 80130568 00822025 */  or        $a0, $a0, $v0
/* C6C6C 8013056C ACA40010 */  sw        $a0, 0x10($a1)
/* C6C70 80130570 8FA30018 */  lw        $v1, 0x18($sp)
/* C6C74 80130574 8FA4001C */  lw        $a0, 0x1c($sp)
/* C6C78 80130578 3C02E700 */  lui       $v0, 0xe700
/* C6C7C 8013057C ACA20018 */  sw        $v0, 0x18($a1)
/* C6C80 80130580 ACA0001C */  sw        $zero, 0x1c($a1)
/* C6C84 80130584 00031840 */  sll       $v1, $v1, 1
/* C6C88 80130588 30630FFF */  andi      $v1, $v1, 0xfff
/* C6C8C 8013058C 00031B00 */  sll       $v1, $v1, 0xc
/* C6C90 80130590 00042080 */  sll       $a0, $a0, 2
/* C6C94 80130594 30840FFF */  andi      $a0, $a0, 0xfff
/* C6C98 80130598 00992025 */  or        $a0, $a0, $t9
/* C6C9C 8013059C 00641825 */  or        $v1, $v1, $a0
/* C6CA0 801305A0 ACA30014 */  sw        $v1, 0x14($a1)
/* C6CA4 801305A4 8FA20018 */  lw        $v0, 0x18($sp)
/* C6CA8 801305A8 8FA40010 */  lw        $a0, 0x10($sp)
/* C6CAC 801305AC 24A30020 */  addiu     $v1, $a1, 0x20
/* C6CB0 801305B0 ACE30000 */  sw        $v1, ($a3)
/* C6CB4 801305B4 3C03F500 */  lui       $v1, 0xf500
/* C6CB8 801305B8 ACAC0024 */  sw        $t4, 0x24($a1)
/* C6CBC 801305BC 00441023 */  subu      $v0, $v0, $a0
/* C6CC0 801305C0 24420001 */  addiu     $v0, $v0, 1
/* C6CC4 801305C4 00021043 */  sra       $v0, $v0, 1
/* C6CC8 801305C8 24420007 */  addiu     $v0, $v0, 7
/* C6CCC 801305CC 000210C3 */  sra       $v0, $v0, 3
/* C6CD0 801305D0 304201FF */  andi      $v0, $v0, 0x1ff
/* C6CD4 801305D4 00021240 */  sll       $v0, $v0, 9
/* C6CD8 801305D8 00431025 */  or        $v0, $v0, $v1
/* C6CDC 801305DC 01021025 */  or        $v0, $t0, $v0
/* C6CE0 801305E0 ACA20020 */  sw        $v0, 0x20($a1)
/* C6CE4 801305E4 24A20028 */  addiu     $v0, $a1, 0x28
/* C6CE8 801305E8 8FA40010 */  lw        $a0, 0x10($sp)
/* C6CEC 801305EC 0804C21C */  j         .L80130870
/* C6CF0 801305F0 3C03F200 */   lui      $v1, 0xf200
.L801305F4:
/* C6CF4 801305F4 55C20041 */  bnel      $t6, $v0, .L801306FC
/* C6CF8 801305F8 24020002 */   addiu    $v0, $zero, 2
/* C6CFC 801305FC 8CE50000 */  lw        $a1, ($a3)
/* C6D00 80130600 00A0102D */  daddu     $v0, $a1, $zero
/* C6D04 80130604 24A50008 */  addiu     $a1, $a1, 8
/* C6D08 80130608 ACE50000 */  sw        $a1, ($a3)
/* C6D0C 8013060C 8FB70054 */  lw        $s7, 0x54($sp)
/* C6D10 80130610 AC570000 */  sw        $s7, ($v0)
/* C6D14 80130614 8FB70098 */  lw        $s7, 0x98($sp)
/* C6D18 80130618 AC570004 */  sw        $s7, 4($v0)
/* C6D1C 8013061C 8FA20018 */  lw        $v0, 0x18($sp)
/* C6D20 80130620 8FA40010 */  lw        $a0, 0x10($sp)
/* C6D24 80130624 24A30008 */  addiu     $v1, $a1, 8
/* C6D28 80130628 ACE30000 */  sw        $v1, ($a3)
/* C6D2C 8013062C 24A30010 */  addiu     $v1, $a1, 0x10
/* C6D30 80130630 ACAD0004 */  sw        $t5, 4($a1)
/* C6D34 80130634 ACE30000 */  sw        $v1, ($a3)
/* C6D38 80130638 3C03F400 */  lui       $v1, 0xf400
/* C6D3C 8013063C ACB50008 */  sw        $s5, 8($a1)
/* C6D40 80130640 ACA0000C */  sw        $zero, 0xc($a1)
/* C6D44 80130644 00441023 */  subu      $v0, $v0, $a0
/* C6D48 80130648 24420008 */  addiu     $v0, $v0, 8
/* C6D4C 8013064C 000210C3 */  sra       $v0, $v0, 3
/* C6D50 80130650 304201FF */  andi      $v0, $v0, 0x1ff
/* C6D54 80130654 00021240 */  sll       $v0, $v0, 9
/* C6D58 80130658 005E1025 */  or        $v0, $v0, $fp
/* C6D5C 8013065C 01021025 */  or        $v0, $t0, $v0
/* C6D60 80130660 ACA20000 */  sw        $v0, ($a1)
/* C6D64 80130664 8FA40010 */  lw        $a0, 0x10($sp)
/* C6D68 80130668 24A20018 */  addiu     $v0, $a1, 0x18
/* C6D6C 8013066C ACE20000 */  sw        $v0, ($a3)
/* C6D70 80130670 8FA20014 */  lw        $v0, 0x14($sp)
/* C6D74 80130674 00042080 */  sll       $a0, $a0, 2
/* C6D78 80130678 30840FFF */  andi      $a0, $a0, 0xfff
/* C6D7C 8013067C 00042300 */  sll       $a0, $a0, 0xc
/* C6D80 80130680 00021080 */  sll       $v0, $v0, 2
/* C6D84 80130684 30420FFF */  andi      $v0, $v0, 0xfff
/* C6D88 80130688 00431025 */  or        $v0, $v0, $v1
/* C6D8C 8013068C 00822025 */  or        $a0, $a0, $v0
/* C6D90 80130690 ACA40010 */  sw        $a0, 0x10($a1)
/* C6D94 80130694 8FA30018 */  lw        $v1, 0x18($sp)
/* C6D98 80130698 8FA4001C */  lw        $a0, 0x1c($sp)
/* C6D9C 8013069C 3C02E700 */  lui       $v0, 0xe700
/* C6DA0 801306A0 ACA20018 */  sw        $v0, 0x18($a1)
/* C6DA4 801306A4 ACA0001C */  sw        $zero, 0x1c($a1)
/* C6DA8 801306A8 00031880 */  sll       $v1, $v1, 2
/* C6DAC 801306AC 30630FFF */  andi      $v1, $v1, 0xfff
/* C6DB0 801306B0 00031B00 */  sll       $v1, $v1, 0xc
/* C6DB4 801306B4 00042080 */  sll       $a0, $a0, 2
/* C6DB8 801306B8 30840FFF */  andi      $a0, $a0, 0xfff
/* C6DBC 801306BC 00992025 */  or        $a0, $a0, $t9
/* C6DC0 801306C0 00641825 */  or        $v1, $v1, $a0
/* C6DC4 801306C4 ACA30014 */  sw        $v1, 0x14($a1)
/* C6DC8 801306C8 8FA20018 */  lw        $v0, 0x18($sp)
/* C6DCC 801306CC 8FA40010 */  lw        $a0, 0x10($sp)
/* C6DD0 801306D0 24A30020 */  addiu     $v1, $a1, 0x20
/* C6DD4 801306D4 ACE30000 */  sw        $v1, ($a3)
/* C6DD8 801306D8 3C03F200 */  lui       $v1, 0xf200
/* C6DDC 801306DC ACAC0024 */  sw        $t4, 0x24($a1)
/* C6DE0 801306E0 00441023 */  subu      $v0, $v0, $a0
/* C6DE4 801306E4 24420008 */  addiu     $v0, $v0, 8
/* C6DE8 801306E8 000210C3 */  sra       $v0, $v0, 3
/* C6DEC 801306EC 304201FF */  andi      $v0, $v0, 0x1ff
/* C6DF0 801306F0 00021240 */  sll       $v0, $v0, 9
/* C6DF4 801306F4 0804C218 */  j         .L80130860
/* C6DF8 801306F8 005E1025 */   or       $v0, $v0, $fp
.L801306FC:
/* C6DFC 801306FC 15C20012 */  bne       $t6, $v0, .L80130748
/* C6E00 80130700 24020003 */   addiu    $v0, $zero, 3
/* C6E04 80130704 3C02FD10 */  lui       $v0, 0xfd10
/* C6E08 80130708 02421025 */  or        $v0, $s2, $v0
/* C6E0C 8013070C 8CE50000 */  lw        $a1, ($a3)
/* C6E10 80130710 01021025 */  or        $v0, $t0, $v0
/* C6E14 80130714 00A0182D */  daddu     $v1, $a1, $zero
/* C6E18 80130718 24A50008 */  addiu     $a1, $a1, 8
/* C6E1C 8013071C ACE50000 */  sw        $a1, ($a3)
/* C6E20 80130720 AC620000 */  sw        $v0, ($v1)
/* C6E24 80130724 8FB70098 */  lw        $s7, 0x98($sp)
/* C6E28 80130728 AC770004 */  sw        $s7, 4($v1)
/* C6E2C 8013072C 8FA20018 */  lw        $v0, 0x18($sp)
/* C6E30 80130730 8FA40010 */  lw        $a0, 0x10($sp)
/* C6E34 80130734 24A30008 */  addiu     $v1, $a1, 8
/* C6E38 80130738 ACE30000 */  sw        $v1, ($a3)
/* C6E3C 8013073C 24A30010 */  addiu     $v1, $a1, 0x10
/* C6E40 80130740 0804C1E4 */  j         .L80130790
/* C6E44 80130744 3C17F510 */   lui      $s7, 0xf510
.L80130748:
/* C6E48 80130748 15C2005F */  bne       $t6, $v0, .L801308C8
/* C6E4C 8013074C 3C03E400 */   lui      $v1, 0xe400
/* C6E50 80130750 3C02FD18 */  lui       $v0, 0xfd18
/* C6E54 80130754 02421025 */  or        $v0, $s2, $v0
/* C6E58 80130758 8CE50000 */  lw        $a1, ($a3)
/* C6E5C 8013075C 01021025 */  or        $v0, $t0, $v0
/* C6E60 80130760 00A0182D */  daddu     $v1, $a1, $zero
/* C6E64 80130764 24A50008 */  addiu     $a1, $a1, 8
/* C6E68 80130768 ACE50000 */  sw        $a1, ($a3)
/* C6E6C 8013076C AC620000 */  sw        $v0, ($v1)
/* C6E70 80130770 8FB70098 */  lw        $s7, 0x98($sp)
/* C6E74 80130774 AC770004 */  sw        $s7, 4($v1)
/* C6E78 80130778 8FA20018 */  lw        $v0, 0x18($sp)
/* C6E7C 8013077C 8FA40010 */  lw        $a0, 0x10($sp)
/* C6E80 80130780 24A30008 */  addiu     $v1, $a1, 8
/* C6E84 80130784 ACE30000 */  sw        $v1, ($a3)
/* C6E88 80130788 24A30010 */  addiu     $v1, $a1, 0x10
/* C6E8C 8013078C 3C17F518 */  lui       $s7, 0xf518
.L80130790:
/* C6E90 80130790 ACAD0004 */  sw        $t5, 4($a1)
/* C6E94 80130794 ACE30000 */  sw        $v1, ($a3)
/* C6E98 80130798 3C03F400 */  lui       $v1, 0xf400
/* C6E9C 8013079C ACB50008 */  sw        $s5, 8($a1)
/* C6EA0 801307A0 ACA0000C */  sw        $zero, 0xc($a1)
/* C6EA4 801307A4 00441023 */  subu      $v0, $v0, $a0
/* C6EA8 801307A8 00021040 */  sll       $v0, $v0, 1
/* C6EAC 801307AC 24420009 */  addiu     $v0, $v0, 9
/* C6EB0 801307B0 000210C3 */  sra       $v0, $v0, 3
/* C6EB4 801307B4 304201FF */  andi      $v0, $v0, 0x1ff
/* C6EB8 801307B8 00021240 */  sll       $v0, $v0, 9
/* C6EBC 801307BC 00571025 */  or        $v0, $v0, $s7
/* C6EC0 801307C0 01021025 */  or        $v0, $t0, $v0
/* C6EC4 801307C4 ACA20000 */  sw        $v0, ($a1)
/* C6EC8 801307C8 8FA40010 */  lw        $a0, 0x10($sp)
/* C6ECC 801307CC 24A20018 */  addiu     $v0, $a1, 0x18
/* C6ED0 801307D0 ACE20000 */  sw        $v0, ($a3)
/* C6ED4 801307D4 8FA20014 */  lw        $v0, 0x14($sp)
/* C6ED8 801307D8 00042080 */  sll       $a0, $a0, 2
/* C6EDC 801307DC 30840FFF */  andi      $a0, $a0, 0xfff
/* C6EE0 801307E0 00042300 */  sll       $a0, $a0, 0xc
/* C6EE4 801307E4 00021080 */  sll       $v0, $v0, 2
/* C6EE8 801307E8 30420FFF */  andi      $v0, $v0, 0xfff
/* C6EEC 801307EC 00431025 */  or        $v0, $v0, $v1
/* C6EF0 801307F0 00822025 */  or        $a0, $a0, $v0
/* C6EF4 801307F4 ACA40010 */  sw        $a0, 0x10($a1)
/* C6EF8 801307F8 8FA30018 */  lw        $v1, 0x18($sp)
/* C6EFC 801307FC 8FA4001C */  lw        $a0, 0x1c($sp)
/* C6F00 80130800 3C02E700 */  lui       $v0, 0xe700
/* C6F04 80130804 ACA20018 */  sw        $v0, 0x18($a1)
/* C6F08 80130808 ACA0001C */  sw        $zero, 0x1c($a1)
/* C6F0C 8013080C 00031880 */  sll       $v1, $v1, 2
/* C6F10 80130810 30630FFF */  andi      $v1, $v1, 0xfff
/* C6F14 80130814 00031B00 */  sll       $v1, $v1, 0xc
/* C6F18 80130818 00042080 */  sll       $a0, $a0, 2
/* C6F1C 8013081C 30840FFF */  andi      $a0, $a0, 0xfff
/* C6F20 80130820 00992025 */  or        $a0, $a0, $t9
/* C6F24 80130824 00641825 */  or        $v1, $v1, $a0
/* C6F28 80130828 ACA30014 */  sw        $v1, 0x14($a1)
/* C6F2C 8013082C 8FA20018 */  lw        $v0, 0x18($sp)
/* C6F30 80130830 8FA40010 */  lw        $a0, 0x10($sp)
/* C6F34 80130834 24A30020 */  addiu     $v1, $a1, 0x20
/* C6F38 80130838 ACE30000 */  sw        $v1, ($a3)
/* C6F3C 8013083C 3C03F200 */  lui       $v1, 0xf200
/* C6F40 80130840 ACAC0024 */  sw        $t4, 0x24($a1)
/* C6F44 80130844 00441023 */  subu      $v0, $v0, $a0
/* C6F48 80130848 00021040 */  sll       $v0, $v0, 1
/* C6F4C 8013084C 24420009 */  addiu     $v0, $v0, 9
/* C6F50 80130850 000210C3 */  sra       $v0, $v0, 3
/* C6F54 80130854 304201FF */  andi      $v0, $v0, 0x1ff
/* C6F58 80130858 00021240 */  sll       $v0, $v0, 9
/* C6F5C 8013085C 00571025 */  or        $v0, $v0, $s7
.L80130860:
/* C6F60 80130860 01021025 */  or        $v0, $t0, $v0
/* C6F64 80130864 ACA20020 */  sw        $v0, 0x20($a1)
/* C6F68 80130868 8FA40010 */  lw        $a0, 0x10($sp)
/* C6F6C 8013086C 24A20028 */  addiu     $v0, $a1, 0x28
.L80130870:
/* C6F70 80130870 ACE20000 */  sw        $v0, ($a3)
/* C6F74 80130874 8FA20014 */  lw        $v0, 0x14($sp)
/* C6F78 80130878 00042080 */  sll       $a0, $a0, 2
/* C6F7C 8013087C 30840FFF */  andi      $a0, $a0, 0xfff
/* C6F80 80130880 00042300 */  sll       $a0, $a0, 0xc
/* C6F84 80130884 00021080 */  sll       $v0, $v0, 2
/* C6F88 80130888 30420FFF */  andi      $v0, $v0, 0xfff
/* C6F8C 8013088C 00431025 */  or        $v0, $v0, $v1
/* C6F90 80130890 00822025 */  or        $a0, $a0, $v0
/* C6F94 80130894 ACA40028 */  sw        $a0, 0x28($a1)
/* C6F98 80130898 8FA30018 */  lw        $v1, 0x18($sp)
/* C6F9C 8013089C 24A20030 */  addiu     $v0, $a1, 0x30
/* C6FA0 801308A0 ACE20000 */  sw        $v0, ($a3)
/* C6FA4 801308A4 8FA2001C */  lw        $v0, 0x1c($sp)
/* C6FA8 801308A8 00031880 */  sll       $v1, $v1, 2
/* C6FAC 801308AC 30630FFF */  andi      $v1, $v1, 0xfff
/* C6FB0 801308B0 00031B00 */  sll       $v1, $v1, 0xc
/* C6FB4 801308B4 00021080 */  sll       $v0, $v0, 2
/* C6FB8 801308B8 30420FFF */  andi      $v0, $v0, 0xfff
/* C6FBC 801308BC 00621825 */  or        $v1, $v1, $v0
/* C6FC0 801308C0 ACA3002C */  sw        $v1, 0x2c($a1)
/* C6FC4 801308C4 3C03E400 */  lui       $v1, 0xe400
.L801308C8:
/* C6FC8 801308C8 8CE50000 */  lw        $a1, ($a3)
/* C6FCC 801308CC 8FA40028 */  lw        $a0, 0x28($sp)
/* C6FD0 801308D0 00A0302D */  daddu     $a2, $a1, $zero
/* C6FD4 801308D4 24A50008 */  addiu     $a1, $a1, 8
/* C6FD8 801308D8 00042080 */  sll       $a0, $a0, 2
/* C6FDC 801308DC 30840FFF */  andi      $a0, $a0, 0xfff
/* C6FE0 801308E0 ACE50000 */  sw        $a1, ($a3)
/* C6FE4 801308E4 8FA2002C */  lw        $v0, 0x2c($sp)
/* C6FE8 801308E8 00042300 */  sll       $a0, $a0, 0xc
/* C6FEC 801308EC 00021080 */  sll       $v0, $v0, 2
/* C6FF0 801308F0 30420FFF */  andi      $v0, $v0, 0xfff
/* C6FF4 801308F4 00431025 */  or        $v0, $v0, $v1
/* C6FF8 801308F8 00822025 */  or        $a0, $a0, $v0
/* C6FFC 801308FC 24A20008 */  addiu     $v0, $a1, 8
/* C7000 80130900 ACC40000 */  sw        $a0, ($a2)
/* C7004 80130904 ACE20000 */  sw        $v0, ($a3)
/* C7008 80130908 8FA30020 */  lw        $v1, 0x20($sp)
/* C700C 8013090C 24A20010 */  addiu     $v0, $a1, 0x10
/* C7010 80130910 ACE20000 */  sw        $v0, ($a3)
/* C7014 80130914 8FA20024 */  lw        $v0, 0x24($sp)
/* C7018 80130918 00031880 */  sll       $v1, $v1, 2
/* C701C 8013091C 30630FFF */  andi      $v1, $v1, 0xfff
/* C7020 80130920 00031B00 */  sll       $v1, $v1, 0xc
/* C7024 80130924 00021080 */  sll       $v0, $v0, 2
/* C7028 80130928 30420FFF */  andi      $v0, $v0, 0xfff
/* C702C 8013092C 00621825 */  or        $v1, $v1, $v0
/* C7030 80130930 3C02E100 */  lui       $v0, 0xe100
/* C7034 80130934 ACC30004 */  sw        $v1, 4($a2)
/* C7038 80130938 ACA20000 */  sw        $v0, ($a1)
/* C703C 8013093C 00101400 */  sll       $v0, $s0, 0x10
/* C7040 80130940 3223FFFF */  andi      $v1, $s1, 0xffff
/* C7044 80130944 00431025 */  or        $v0, $v0, $v1
/* C7048 80130948 ACA20004 */  sw        $v0, 4($a1)
/* C704C 8013094C 3C02F100 */  lui       $v0, 0xf100
/* C7050 80130950 ACA20008 */  sw        $v0, 8($a1)
/* C7054 80130954 8FB7004C */  lw        $s7, 0x4c($sp)
/* C7058 80130958 00171400 */  sll       $v0, $s7, 0x10
/* C705C 8013095C 8FB70050 */  lw        $s7, 0x50($sp)
/* C7060 80130960 32E3FFFF */  andi      $v1, $s7, 0xffff
/* C7064 80130964 00431025 */  or        $v0, $v0, $v1
/* C7068 80130968 ACA2000C */  sw        $v0, 0xc($a1)
/* C706C 8013096C 316200FF */  andi      $v0, $t3, 0xff
/* C7070 80130970 14400011 */  bnez      $v0, .L801309B8
/* C7074 80130974 24020001 */   addiu    $v0, $zero, 1
/* C7078 80130978 97A30048 */  lhu       $v1, 0x48($sp)
/* C707C 8013097C 44830000 */  mtc1      $v1, $f0
/* C7080 80130980 00000000 */  nop
/* C7084 80130984 46800020 */  cvt.s.w   $f0, $f0
/* C7088 80130988 46140002 */  mul.s     $f0, $f0, $f20
/* C708C 8013098C 00000000 */  nop
/* C7090 80130990 C7A2002C */  lwc1      $f2, 0x2c($sp)
/* C7094 80130994 468010A0 */  cvt.s.w   $f2, $f2
/* C7098 80130998 8FA20014 */  lw        $v0, 0x14($sp)
/* C709C 8013099C 01231823 */  subu      $v1, $t1, $v1
/* C70A0 801309A0 46001081 */  sub.s     $f2, $f2, $f0
/* C70A4 801309A4 00431021 */  addu      $v0, $v0, $v1
/* C70A8 801309A8 AFA20014 */  sw        $v0, 0x14($sp)
/* C70AC 801309AC 4600120D */  trunc.w.s $f8, $f2
/* C70B0 801309B0 0804C09C */  j         .L80130270
/* C70B4 801309B4 E7A80024 */   swc1     $f8, 0x24($sp)
.L801309B8:
/* C70B8 801309B8 8FBF0084 */  lw        $ra, 0x84($sp)
/* C70BC 801309BC 8FBE0080 */  lw        $fp, 0x80($sp)
/* C70C0 801309C0 8FB7007C */  lw        $s7, 0x7c($sp)
/* C70C4 801309C4 8FB60078 */  lw        $s6, 0x78($sp)
/* C70C8 801309C8 8FB50074 */  lw        $s5, 0x74($sp)
/* C70CC 801309CC 8FB40070 */  lw        $s4, 0x70($sp)
/* C70D0 801309D0 8FB3006C */  lw        $s3, 0x6c($sp)
/* C70D4 801309D4 8FB20068 */  lw        $s2, 0x68($sp)
/* C70D8 801309D8 8FB10064 */  lw        $s1, 0x64($sp)
/* C70DC 801309DC 8FB00060 */  lw        $s0, 0x60($sp)
/* C70E0 801309E0 D7B60090 */  ldc1      $f22, 0x90($sp)
/* C70E4 801309E4 D7B40088 */  ldc1      $f20, 0x88($sp)
/* C70E8 801309E8 03E00008 */  jr        $ra
/* C70EC 801309EC 27BD0098 */   addiu    $sp, $sp, 0x98
