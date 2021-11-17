.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel jtbl_801506F8
.word .L80126874_BCF74, .L80126884_BCF84, .L801268D8_BCFD8, .L80126900_BD000, .L8012698C_BD08C, 0

dlabel D_80150710
.double 0.2

.section .text

glabel msg_update_rewind_arrow
/* BCE90 80126790 27BDFF18 */  addiu     $sp, $sp, -0xe8
/* BCE94 80126794 F7BA00D8 */  sdc1      $f26, 0xd8($sp)
/* BCE98 80126798 4480D000 */  mtc1      $zero, $f26
/* BCE9C 8012679C F7BC00E0 */  sdc1      $f28, 0xe0($sp)
/* BCEA0 801267A0 3C013F80 */  lui       $at, 0x3f80
/* BCEA4 801267A4 4481E000 */  mtc1      $at, $f28
/* BCEA8 801267A8 3C05800A */  lui       $a1, %hi(gMasterGfxPos)
/* BCEAC 801267AC 24A5A66C */  addiu     $a1, $a1, %lo(gMasterGfxPos)
/* BCEB0 801267B0 F7B600C8 */  sdc1      $f22, 0xc8($sp)
/* BCEB4 801267B4 3C01437F */  lui       $at, 0x437f
/* BCEB8 801267B8 4481B000 */  mtc1      $at, $f22
/* BCEBC 801267BC 3C02E700 */  lui       $v0, 0xe700
/* BCEC0 801267C0 AFBF00B8 */  sw        $ra, 0xb8($sp)
/* BCEC4 801267C4 AFB700B4 */  sw        $s7, 0xb4($sp)
/* BCEC8 801267C8 AFB600B0 */  sw        $s6, 0xb0($sp)
/* BCECC 801267CC AFB500AC */  sw        $s5, 0xac($sp)
/* BCED0 801267D0 AFB400A8 */  sw        $s4, 0xa8($sp)
/* BCED4 801267D4 AFB300A4 */  sw        $s3, 0xa4($sp)
/* BCED8 801267D8 AFB200A0 */  sw        $s2, 0xa0($sp)
/* BCEDC 801267DC AFB1009C */  sw        $s1, 0x9c($sp)
/* BCEE0 801267E0 AFB00098 */  sw        $s0, 0x98($sp)
/* BCEE4 801267E4 F7B800D0 */  sdc1      $f24, 0xd0($sp)
/* BCEE8 801267E8 F7B400C0 */  sdc1      $f20, 0xc0($sp)
/* BCEEC 801267EC 8CA30000 */  lw        $v1, ($a1)
/* BCEF0 801267F0 4600B606 */  mov.s     $f24, $f22
/* BCEF4 801267F4 0060302D */  daddu     $a2, $v1, $zero
/* BCEF8 801267F8 24630008 */  addiu     $v1, $v1, 8
/* BCEFC 801267FC ACA30000 */  sw        $v1, ($a1)
/* BCF00 80126800 ACC20000 */  sw        $v0, ($a2)
/* BCF04 80126804 24620008 */  addiu     $v0, $v1, 8
/* BCF08 80126808 ACC00004 */  sw        $zero, 4($a2)
/* BCF0C 8012680C ACA20000 */  sw        $v0, ($a1)
/* BCF10 80126810 3C02DE00 */  lui       $v0, 0xde00
/* BCF14 80126814 AC620000 */  sw        $v0, ($v1)
/* BCF18 80126818 3C028015 */  lui       $v0, %hi(D_8014C2D8)
/* BCF1C 8012681C 2442C2D8 */  addiu     $v0, $v0, %lo(D_8014C2D8)
/* BCF20 80126820 3C058015 */  lui       $a1, %hi(gMessagePrinters)
/* BCF24 80126824 24A54C30 */  addiu     $a1, $a1, %lo(gMessagePrinters)
/* BCF28 80126828 AC620004 */  sw        $v0, 4($v1)
/* BCF2C 8012682C 00041080 */  sll       $v0, $a0, 2
/* BCF30 80126830 00441021 */  addu      $v0, $v0, $a0
/* BCF34 80126834 00021080 */  sll       $v0, $v0, 2
/* BCF38 80126838 00441023 */  subu      $v0, $v0, $a0
/* BCF3C 8012683C 000218C0 */  sll       $v1, $v0, 3
/* BCF40 80126840 00431021 */  addu      $v0, $v0, $v1
/* BCF44 80126844 000210C0 */  sll       $v0, $v0, 3
/* BCF48 80126848 00458821 */  addu      $s1, $v0, $a1
/* BCF4C 8012684C 9223047C */  lbu       $v1, 0x47c($s1)
/* BCF50 80126850 2C620005 */  sltiu     $v0, $v1, 5
/* BCF54 80126854 10400071 */  beqz      $v0, .L80126A1C
/* BCF58 80126858 4600B106 */   mov.s    $f4, $f22
/* BCF5C 8012685C 00031080 */  sll       $v0, $v1, 2
/* BCF60 80126860 3C018015 */  lui       $at, %hi(jtbl_801506F8)
/* BCF64 80126864 00220821 */  addu      $at, $at, $v0
/* BCF68 80126868 8C2206F8 */  lw        $v0, %lo(jtbl_801506F8)($at)
/* BCF6C 8012686C 00400008 */  jr        $v0
/* BCF70 80126870 00000000 */   nop
.L80126874_BCF74:
/* BCF74 80126874 24020001 */  addiu     $v0, $zero, 1
/* BCF78 80126878 A620047E */  sh        $zero, 0x47e($s1)
/* BCF7C 8012687C A6200480 */  sh        $zero, 0x480($s1)
/* BCF80 80126880 A222047C */  sb        $v0, 0x47c($s1)
.L80126884_BCF84:
/* BCF84 80126884 8622047E */  lh        $v0, 0x47e($s1)
/* BCF88 80126888 3C018015 */  lui       $at, %hi(D_80150710)
/* BCF8C 8012688C D4220710 */  ldc1      $f2, %lo(D_80150710)($at)
/* BCF90 80126890 44820000 */  mtc1      $v0, $f0
/* BCF94 80126894 00000000 */  nop
/* BCF98 80126898 46800020 */  cvt.s.w   $f0, $f0
/* BCF9C 8012689C 46000021 */  cvt.d.s   $f0, $f0
/* BCFA0 801268A0 46220002 */  mul.d     $f0, $f0, $f2
/* BCFA4 801268A4 00000000 */  nop
/* BCFA8 801268A8 9622047E */  lhu       $v0, 0x47e($s1)
/* BCFAC 801268AC 3C013FE0 */  lui       $at, 0x3fe0
/* BCFB0 801268B0 44811800 */  mtc1      $at, $f3
/* BCFB4 801268B4 44801000 */  mtc1      $zero, $f2
/* BCFB8 801268B8 24420001 */  addiu     $v0, $v0, 1
/* BCFBC 801268BC A622047E */  sh        $v0, 0x47e($s1)
/* BCFC0 801268C0 00021400 */  sll       $v0, $v0, 0x10
/* BCFC4 801268C4 46220000 */  add.d     $f0, $f0, $f2
/* BCFC8 801268C8 00021403 */  sra       $v0, $v0, 0x10
/* BCFCC 801268CC 28420004 */  slti      $v0, $v0, 4
/* BCFD0 801268D0 08049A83 */  j         .L80126A0C
/* BCFD4 801268D4 46200720 */   cvt.s.d  $f28, $f0
.L801268D8_BCFD8:
/* BCFD8 801268D8 9622047E */  lhu       $v0, 0x47e($s1)
/* BCFDC 801268DC 24420001 */  addiu     $v0, $v0, 1
/* BCFE0 801268E0 A622047E */  sh        $v0, 0x47e($s1)
/* BCFE4 801268E4 00021400 */  sll       $v0, $v0, 0x10
/* BCFE8 801268E8 00021403 */  sra       $v0, $v0, 0x10
/* BCFEC 801268EC 28420019 */  slti      $v0, $v0, 0x19
/* BCFF0 801268F0 1440004A */  bnez      $v0, .L80126A1C
/* BCFF4 801268F4 24020003 */   addiu    $v0, $zero, 3
/* BCFF8 801268F8 08049A86 */  j         .L80126A18
/* BCFFC 801268FC A620047E */   sh       $zero, 0x47e($s1)
.L80126900_BD000:
/* BD000 80126900 0000202D */  daddu     $a0, $zero, $zero
/* BD004 80126904 8627047E */  lh        $a3, 0x47e($s1)
/* BD008 80126908 3C01437F */  lui       $at, 0x437f
/* BD00C 8012690C 4481A000 */  mtc1      $at, $f20
/* BD010 80126910 3C014360 */  lui       $at, 0x4360
/* BD014 80126914 4481B000 */  mtc1      $at, $f22
/* BD018 80126918 4405A000 */  mfc1      $a1, $f20
/* BD01C 8012691C 4406B000 */  mfc1      $a2, $f22
/* BD020 80126920 2410000F */  addiu     $s0, $zero, 0xf
/* BD024 80126924 0C00A8ED */  jal       update_lerp
/* BD028 80126928 AFB00010 */   sw       $s0, 0x10($sp)
/* BD02C 8012692C 46000606 */  mov.s     $f24, $f0
/* BD030 80126930 4405A000 */  mfc1      $a1, $f20
/* BD034 80126934 4406B000 */  mfc1      $a2, $f22
/* BD038 80126938 8627047E */  lh        $a3, 0x47e($s1)
/* BD03C 8012693C 0000202D */  daddu     $a0, $zero, $zero
/* BD040 80126940 0C00A8ED */  jal       update_lerp
/* BD044 80126944 AFB00010 */   sw       $s0, 0x10($sp)
/* BD048 80126948 46000586 */  mov.s     $f22, $f0
/* BD04C 8012694C 4405A000 */  mfc1      $a1, $f20
/* BD050 80126950 3C064350 */  lui       $a2, 0x4350
/* BD054 80126954 8627047E */  lh        $a3, 0x47e($s1)
/* BD058 80126958 0000202D */  daddu     $a0, $zero, $zero
/* BD05C 8012695C 0C00A8ED */  jal       update_lerp
/* BD060 80126960 AFB00010 */   sw       $s0, 0x10($sp)
/* BD064 80126964 9622047E */  lhu       $v0, 0x47e($s1)
/* BD068 80126968 24420001 */  addiu     $v0, $v0, 1
/* BD06C 8012696C A622047E */  sh        $v0, 0x47e($s1)
/* BD070 80126970 00021400 */  sll       $v0, $v0, 0x10
/* BD074 80126974 00021403 */  sra       $v0, $v0, 0x10
/* BD078 80126978 0050102A */  slt       $v0, $v0, $s0
/* BD07C 8012697C 14400027 */  bnez      $v0, .L80126A1C
/* BD080 80126980 46000106 */   mov.s    $f4, $f0
/* BD084 80126984 08049A85 */  j         .L80126A14
/* BD088 80126988 24020004 */   addiu    $v0, $zero, 4
.L8012698C_BD08C:
/* BD08C 8012698C 0000202D */  daddu     $a0, $zero, $zero
/* BD090 80126990 8627047E */  lh        $a3, 0x47e($s1)
/* BD094 80126994 3C014360 */  lui       $at, 0x4360
/* BD098 80126998 4481B000 */  mtc1      $at, $f22
/* BD09C 8012699C 3C01437F */  lui       $at, 0x437f
/* BD0A0 801269A0 4481A000 */  mtc1      $at, $f20
/* BD0A4 801269A4 4405B000 */  mfc1      $a1, $f22
/* BD0A8 801269A8 4406A000 */  mfc1      $a2, $f20
/* BD0AC 801269AC 2410000F */  addiu     $s0, $zero, 0xf
/* BD0B0 801269B0 0C00A8ED */  jal       update_lerp
/* BD0B4 801269B4 AFB00010 */   sw       $s0, 0x10($sp)
/* BD0B8 801269B8 46000606 */  mov.s     $f24, $f0
/* BD0BC 801269BC 4405B000 */  mfc1      $a1, $f22
/* BD0C0 801269C0 4406A000 */  mfc1      $a2, $f20
/* BD0C4 801269C4 8627047E */  lh        $a3, 0x47e($s1)
/* BD0C8 801269C8 0000202D */  daddu     $a0, $zero, $zero
/* BD0CC 801269CC 0C00A8ED */  jal       update_lerp
/* BD0D0 801269D0 AFB00010 */   sw       $s0, 0x10($sp)
/* BD0D4 801269D4 46000586 */  mov.s     $f22, $f0
/* BD0D8 801269D8 3C054350 */  lui       $a1, 0x4350
/* BD0DC 801269DC 4406A000 */  mfc1      $a2, $f20
/* BD0E0 801269E0 8627047E */  lh        $a3, 0x47e($s1)
/* BD0E4 801269E4 0000202D */  daddu     $a0, $zero, $zero
/* BD0E8 801269E8 0C00A8ED */  jal       update_lerp
/* BD0EC 801269EC AFB00010 */   sw       $s0, 0x10($sp)
/* BD0F0 801269F0 9622047E */  lhu       $v0, 0x47e($s1)
/* BD0F4 801269F4 46000106 */  mov.s     $f4, $f0
/* BD0F8 801269F8 24420001 */  addiu     $v0, $v0, 1
/* BD0FC 801269FC A622047E */  sh        $v0, 0x47e($s1)
/* BD100 80126A00 00021400 */  sll       $v0, $v0, 0x10
/* BD104 80126A04 00021403 */  sra       $v0, $v0, 0x10
/* BD108 80126A08 0050102A */  slt       $v0, $v0, $s0
.L80126A0C:
/* BD10C 80126A0C 14400003 */  bnez      $v0, .L80126A1C
/* BD110 80126A10 24020002 */   addiu    $v0, $zero, 2
.L80126A14:
/* BD114 80126A14 A620047E */  sh        $zero, 0x47e($s1)
.L80126A18:
/* BD118 80126A18 A222047C */  sb        $v0, 0x47c($s1)
.L80126A1C:
/* BD11C 80126A1C 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* BD120 80126A20 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* BD124 80126A24 8C620000 */  lw        $v0, ($v1)
/* BD128 80126A28 3C014F00 */  lui       $at, 0x4f00
/* BD12C 80126A2C 44810000 */  mtc1      $at, $f0
/* BD130 80126A30 0040202D */  daddu     $a0, $v0, $zero
/* BD134 80126A34 24420008 */  addiu     $v0, $v0, 8
/* BD138 80126A38 AC620000 */  sw        $v0, ($v1)
/* BD13C 80126A3C 3C02FA00 */  lui       $v0, 0xfa00
/* BD140 80126A40 AC820000 */  sw        $v0, ($a0)
/* BD144 80126A44 4618003E */  c.le.s    $f0, $f24
/* BD148 80126A48 00000000 */  nop
/* BD14C 80126A4C 45010005 */  bc1t      .L80126A64
/* BD150 80126A50 24840004 */   addiu    $a0, $a0, 4
/* BD154 80126A54 4600C18D */  trunc.w.s $f6, $f24
/* BD158 80126A58 44033000 */  mfc1      $v1, $f6
/* BD15C 80126A5C 08049AA2 */  j         .L80126A88
/* BD160 80126A60 00032E00 */   sll      $a1, $v1, 0x18
.L80126A64:
/* BD164 80126A64 4600C001 */  sub.s     $f0, $f24, $f0
/* BD168 80126A68 3C028000 */  lui       $v0, 0x8000
/* BD16C 80126A6C 4600018D */  trunc.w.s $f6, $f0
/* BD170 80126A70 44033000 */  mfc1      $v1, $f6
/* BD174 80126A74 00000000 */  nop
/* BD178 80126A78 00621825 */  or        $v1, $v1, $v0
/* BD17C 80126A7C 3C014F00 */  lui       $at, 0x4f00
/* BD180 80126A80 44810000 */  mtc1      $at, $f0
/* BD184 80126A84 00032E00 */  sll       $a1, $v1, 0x18
.L80126A88:
/* BD188 80126A88 4616003E */  c.le.s    $f0, $f22
/* BD18C 80126A8C 00000000 */  nop
/* BD190 80126A90 45030005 */  bc1tl     .L80126AA8
/* BD194 80126A94 4600B001 */   sub.s    $f0, $f22, $f0
/* BD198 80126A98 4600B18D */  trunc.w.s $f6, $f22
/* BD19C 80126A9C 44033000 */  mfc1      $v1, $f6
/* BD1A0 80126AA0 08049AAF */  j         .L80126ABC
/* BD1A4 80126AA4 00000000 */   nop
.L80126AA8:
/* BD1A8 80126AA8 3C028000 */  lui       $v0, 0x8000
/* BD1AC 80126AAC 4600018D */  trunc.w.s $f6, $f0
/* BD1B0 80126AB0 44033000 */  mfc1      $v1, $f6
/* BD1B4 80126AB4 00000000 */  nop
/* BD1B8 80126AB8 00621825 */  or        $v1, $v1, $v0
.L80126ABC:
/* BD1BC 80126ABC 3C014F00 */  lui       $at, 0x4f00
/* BD1C0 80126AC0 44810000 */  mtc1      $at, $f0
/* BD1C4 80126AC4 306200FF */  andi      $v0, $v1, 0xff
/* BD1C8 80126AC8 00021400 */  sll       $v0, $v0, 0x10
/* BD1CC 80126ACC 4604003E */  c.le.s    $f0, $f4
/* BD1D0 80126AD0 00000000 */  nop
/* BD1D4 80126AD4 45010005 */  bc1t      .L80126AEC
/* BD1D8 80126AD8 00A22825 */   or       $a1, $a1, $v0
/* BD1DC 80126ADC 4600218D */  trunc.w.s $f6, $f4
/* BD1E0 80126AE0 44033000 */  mfc1      $v1, $f6
/* BD1E4 80126AE4 08049AC2 */  j         .L80126B08
/* BD1E8 80126AE8 306200FF */   andi     $v0, $v1, 0xff
.L80126AEC:
/* BD1EC 80126AEC 46002001 */  sub.s     $f0, $f4, $f0
/* BD1F0 80126AF0 3C028000 */  lui       $v0, 0x8000
/* BD1F4 80126AF4 4600018D */  trunc.w.s $f6, $f0
/* BD1F8 80126AF8 44033000 */  mfc1      $v1, $f6
/* BD1FC 80126AFC 00000000 */  nop
/* BD200 80126B00 00621825 */  or        $v1, $v1, $v0
/* BD204 80126B04 306200FF */  andi      $v0, $v1, 0xff
.L80126B08:
/* BD208 80126B08 00021200 */  sll       $v0, $v0, 8
/* BD20C 80126B0C 00A21025 */  or        $v0, $a1, $v0
/* BD210 80126B10 344200FF */  ori       $v0, $v0, 0xff
/* BD214 80126B14 AC820000 */  sw        $v0, ($a0)
/* BD218 80126B18 9222047C */  lbu       $v0, 0x47c($s1)
/* BD21C 80126B1C 2442FFFE */  addiu     $v0, $v0, -2
/* BD220 80126B20 2C420003 */  sltiu     $v0, $v0, 3
/* BD224 80126B24 10400010 */  beqz      $v0, .L80126B68
/* BD228 80126B28 00000000 */   nop
/* BD22C 80126B2C 0C00A4F5 */  jal       cosine
/* BD230 80126B30 86240480 */   lh       $a0, 0x480($s1)
/* BD234 80126B34 96230480 */  lhu       $v1, 0x480($s1)
/* BD238 80126B38 3C0141F0 */  lui       $at, 0x41f0
/* BD23C 80126B3C 44811000 */  mtc1      $at, $f2
/* BD240 80126B40 2462000F */  addiu     $v0, $v1, 0xf
/* BD244 80126B44 A6220480 */  sh        $v0, 0x480($s1)
/* BD248 80126B48 00021400 */  sll       $v0, $v0, 0x10
/* BD24C 80126B4C 00021403 */  sra       $v0, $v0, 0x10
/* BD250 80126B50 28420168 */  slti      $v0, $v0, 0x168
/* BD254 80126B54 46020682 */  mul.s     $f26, $f0, $f2
/* BD258 80126B58 00000000 */  nop
/* BD25C 80126B5C 14400002 */  bnez      $v0, .L80126B68
/* BD260 80126B60 2462FEA7 */   addiu    $v0, $v1, -0x159
/* BD264 80126B64 A6220480 */  sh        $v0, 0x480($s1)
.L80126B68:
/* BD268 80126B68 96220482 */  lhu       $v0, 0x482($s1)
/* BD26C 80126B6C 4480A000 */  mtc1      $zero, $f20
/* BD270 80126B70 2442000C */  addiu     $v0, $v0, 0xc
/* BD274 80126B74 44823000 */  mtc1      $v0, $f6
/* BD278 80126B78 00000000 */  nop
/* BD27C 80126B7C 468031A0 */  cvt.s.w   $f6, $f6
/* BD280 80126B80 44053000 */  mfc1      $a1, $f6
/* BD284 80126B84 96220484 */  lhu       $v0, 0x484($s1)
/* BD288 80126B88 4407A000 */  mfc1      $a3, $f20
/* BD28C 80126B8C 2442000C */  addiu     $v0, $v0, 0xc
/* BD290 80126B90 00021023 */  negu      $v0, $v0
/* BD294 80126B94 44823000 */  mtc1      $v0, $f6
/* BD298 80126B98 00000000 */  nop
/* BD29C 80126B9C 468031A0 */  cvt.s.w   $f6, $f6
/* BD2A0 80126BA0 44063000 */  mfc1      $a2, $f6
/* BD2A4 80126BA4 0C019E40 */  jal       guTranslateF
/* BD2A8 80126BA8 27A40018 */   addiu    $a0, $sp, 0x18
/* BD2AC 80126BAC 44801000 */  mtc1      $zero, $f2
/* BD2B0 80126BB0 44801800 */  mtc1      $zero, $f3
/* BD2B4 80126BB4 4600D021 */  cvt.d.s   $f0, $f26
/* BD2B8 80126BB8 46220032 */  c.eq.d    $f0, $f2
/* BD2BC 80126BBC 00000000 */  nop
/* BD2C0 80126BC0 4501000D */  bc1t      .L80126BF8
/* BD2C4 80126BC4 27B00058 */   addiu    $s0, $sp, 0x58
/* BD2C8 80126BC8 0200202D */  daddu     $a0, $s0, $zero
/* BD2CC 80126BCC 4405D000 */  mfc1      $a1, $f26
/* BD2D0 80126BD0 4406A000 */  mfc1      $a2, $f20
/* BD2D4 80126BD4 3C013F80 */  lui       $at, 0x3f80
/* BD2D8 80126BD8 44810000 */  mtc1      $at, $f0
/* BD2DC 80126BDC 00C0382D */  daddu     $a3, $a2, $zero
/* BD2E0 80126BE0 0C019EC8 */  jal       guRotateF
/* BD2E4 80126BE4 E7A00010 */   swc1     $f0, 0x10($sp)
/* BD2E8 80126BE8 0200202D */  daddu     $a0, $s0, $zero
/* BD2EC 80126BEC 27A50018 */  addiu     $a1, $sp, 0x18
/* BD2F0 80126BF0 0C019D80 */  jal       guMtxCatF
/* BD2F4 80126BF4 00A0302D */   daddu    $a2, $a1, $zero
.L80126BF8:
/* BD2F8 80126BF8 3C013FF0 */  lui       $at, 0x3ff0
/* BD2FC 80126BFC 44811800 */  mtc1      $at, $f3
/* BD300 80126C00 44801000 */  mtc1      $zero, $f2
/* BD304 80126C04 4600E021 */  cvt.d.s   $f0, $f28
/* BD308 80126C08 46220032 */  c.eq.d    $f0, $f2
/* BD30C 80126C0C 00000000 */  nop
/* BD310 80126C10 4501000C */  bc1t      .L80126C44
/* BD314 80126C14 3C120001 */   lui      $s2, 1
/* BD318 80126C18 27B00058 */  addiu     $s0, $sp, 0x58
/* BD31C 80126C1C 0200202D */  daddu     $a0, $s0, $zero
/* BD320 80126C20 4405E000 */  mfc1      $a1, $f28
/* BD324 80126C24 3C073F80 */  lui       $a3, 0x3f80
/* BD328 80126C28 0C019DF0 */  jal       guScaleF
/* BD32C 80126C2C 00A0302D */   daddu    $a2, $a1, $zero
/* BD330 80126C30 0200202D */  daddu     $a0, $s0, $zero
/* BD334 80126C34 27A50018 */  addiu     $a1, $sp, 0x18
/* BD338 80126C38 0C019D80 */  jal       guMtxCatF
/* BD33C 80126C3C 00A0302D */   daddu    $a2, $a1, $zero
/* BD340 80126C40 3C120001 */  lui       $s2, 1
.L80126C44:
/* BD344 80126C44 36521630 */  ori       $s2, $s2, 0x1630
/* BD348 80126C48 27A40018 */  addiu     $a0, $sp, 0x18
/* BD34C 80126C4C 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* BD350 80126C50 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* BD354 80126C54 3C11800A */  lui       $s1, %hi(gDisplayContext)
/* BD358 80126C58 2631A674 */  addiu     $s1, $s1, %lo(gDisplayContext)
/* BD35C 80126C5C 96050000 */  lhu       $a1, ($s0)
/* BD360 80126C60 8E220000 */  lw        $v0, ($s1)
/* BD364 80126C64 00052980 */  sll       $a1, $a1, 6
/* BD368 80126C68 00B22821 */  addu      $a1, $a1, $s2
/* BD36C 80126C6C 0C019D40 */  jal       guMtxF2L
/* BD370 80126C70 00452821 */   addu     $a1, $v0, $a1
/* BD374 80126C74 3C04DA38 */  lui       $a0, 0xda38
/* BD378 80126C78 34840002 */  ori       $a0, $a0, 2
/* BD37C 80126C7C 3C07FD10 */  lui       $a3, 0xfd10
/* BD380 80126C80 34E7000F */  ori       $a3, $a3, 0xf
/* BD384 80126C84 3C09F510 */  lui       $t1, 0xf510
/* BD388 80126C88 35290800 */  ori       $t1, $t1, 0x800
/* BD38C 80126C8C 3C080701 */  lui       $t0, 0x701
/* BD390 80126C90 35080140 */  ori       $t0, $t0, 0x140
/* BD394 80126C94 3C0A0703 */  lui       $t2, 0x703
/* BD398 80126C98 354AC044 */  ori       $t2, $t2, 0xc044
/* BD39C 80126C9C 3C0B0001 */  lui       $t3, 1
/* BD3A0 80126CA0 356B0140 */  ori       $t3, $t3, 0x140
/* BD3A4 80126CA4 3C0C0003 */  lui       $t4, 3
/* BD3A8 80126CA8 358CC044 */  ori       $t4, $t4, 0xc044
/* BD3AC 80126CAC 3C0DFD88 */  lui       $t5, 0xfd88
/* BD3B0 80126CB0 35AD0007 */  ori       $t5, $t5, 7
/* BD3B4 80126CB4 3C0FF588 */  lui       $t7, 0xf588
/* BD3B8 80126CB8 35EF0300 */  ori       $t7, $t7, 0x300
/* BD3BC 80126CBC 3C0E0701 */  lui       $t6, 0x701
/* BD3C0 80126CC0 35CE4140 */  ori       $t6, $t6, 0x4140
/* BD3C4 80126CC4 3C130701 */  lui       $s3, 0x701
/* BD3C8 80126CC8 3673E048 */  ori       $s3, $s3, 0xe048
/* BD3CC 80126CCC 3C15F580 */  lui       $s5, 0xf580
/* BD3D0 80126CD0 36B50300 */  ori       $s5, $s5, 0x300
/* BD3D4 80126CD4 3C140101 */  lui       $s4, 0x101
/* BD3D8 80126CD8 36944140 */  ori       $s4, $s4, 0x4140
/* BD3DC 80126CDC 3C160103 */  lui       $s6, 0x103
/* BD3E0 80126CE0 36D6C048 */  ori       $s6, $s6, 0xc048
/* BD3E4 80126CE4 3C170100 */  lui       $s7, 0x100
/* BD3E8 80126CE8 36F74008 */  ori       $s7, $s7, 0x4008
/* BD3EC 80126CEC 3C190600 */  lui       $t9, 0x600
/* BD3F0 80126CF0 37390402 */  ori       $t9, $t9, 0x402
/* BD3F4 80126CF4 3C180002 */  lui       $t8, 2
/* BD3F8 80126CF8 3C05800A */  lui       $a1, %hi(gMasterGfxPos)
/* BD3FC 80126CFC 24A5A66C */  addiu     $a1, $a1, %lo(gMasterGfxPos)
/* BD400 80126D00 37180406 */  ori       $t8, $t8, 0x406
/* BD404 80126D04 8CA20000 */  lw        $v0, ($a1)
/* BD408 80126D08 96030000 */  lhu       $v1, ($s0)
/* BD40C 80126D0C 0040302D */  daddu     $a2, $v0, $zero
/* BD410 80126D10 24420008 */  addiu     $v0, $v0, 8
/* BD414 80126D14 ACA20000 */  sw        $v0, ($a1)
/* BD418 80126D18 ACC40000 */  sw        $a0, ($a2)
/* BD41C 80126D1C 24640001 */  addiu     $a0, $v1, 1
/* BD420 80126D20 3063FFFF */  andi      $v1, $v1, 0xffff
/* BD424 80126D24 00031980 */  sll       $v1, $v1, 6
/* BD428 80126D28 A6040000 */  sh        $a0, ($s0)
/* BD42C 80126D2C 8E240000 */  lw        $a0, ($s1)
/* BD430 80126D30 00721821 */  addu      $v1, $v1, $s2
/* BD434 80126D34 00832021 */  addu      $a0, $a0, $v1
/* BD438 80126D38 3C038000 */  lui       $v1, 0x8000
/* BD43C 80126D3C 00832021 */  addu      $a0, $a0, $v1
/* BD440 80126D40 24430008 */  addiu     $v1, $v0, 8
/* BD444 80126D44 ACC40004 */  sw        $a0, 4($a2)
/* BD448 80126D48 ACA30000 */  sw        $v1, ($a1)
/* BD44C 80126D4C 3C03802F */  lui       $v1, %hi(D_802ED690)
/* BD450 80126D50 2463D690 */  addiu     $v1, $v1, %lo(D_802ED690)
/* BD454 80126D54 AC430004 */  sw        $v1, 4($v0)
/* BD458 80126D58 24430010 */  addiu     $v1, $v0, 0x10
/* BD45C 80126D5C AC470000 */  sw        $a3, ($v0)
/* BD460 80126D60 ACA30000 */  sw        $v1, ($a1)
/* BD464 80126D64 24430018 */  addiu     $v1, $v0, 0x18
/* BD468 80126D68 AC48000C */  sw        $t0, 0xc($v0)
/* BD46C 80126D6C 3C08E600 */  lui       $t0, 0xe600
/* BD470 80126D70 AC490008 */  sw        $t1, 8($v0)
/* BD474 80126D74 ACA30000 */  sw        $v1, ($a1)
/* BD478 80126D78 24430020 */  addiu     $v1, $v0, 0x20
/* BD47C 80126D7C 3C07F400 */  lui       $a3, 0xf400
/* BD480 80126D80 AC480010 */  sw        $t0, 0x10($v0)
/* BD484 80126D84 AC400014 */  sw        $zero, 0x14($v0)
/* BD488 80126D88 ACA30000 */  sw        $v1, ($a1)
/* BD48C 80126D8C 24430028 */  addiu     $v1, $v0, 0x28
/* BD490 80126D90 3C06E700 */  lui       $a2, 0xe700
/* BD494 80126D94 AC470018 */  sw        $a3, 0x18($v0)
/* BD498 80126D98 AC4A001C */  sw        $t2, 0x1c($v0)
/* BD49C 80126D9C ACA30000 */  sw        $v1, ($a1)
/* BD4A0 80126DA0 24430030 */  addiu     $v1, $v0, 0x30
/* BD4A4 80126DA4 AC460020 */  sw        $a2, 0x20($v0)
/* BD4A8 80126DA8 AC400024 */  sw        $zero, 0x24($v0)
/* BD4AC 80126DAC ACA30000 */  sw        $v1, ($a1)
/* BD4B0 80126DB0 24430038 */  addiu     $v1, $v0, 0x38
/* BD4B4 80126DB4 3C04F200 */  lui       $a0, 0xf200
/* BD4B8 80126DB8 AC490028 */  sw        $t1, 0x28($v0)
/* BD4BC 80126DBC AC4B002C */  sw        $t3, 0x2c($v0)
/* BD4C0 80126DC0 ACA30000 */  sw        $v1, ($a1)
/* BD4C4 80126DC4 24430040 */  addiu     $v1, $v0, 0x40
/* BD4C8 80126DC8 AC440030 */  sw        $a0, 0x30($v0)
/* BD4CC 80126DCC AC4C0034 */  sw        $t4, 0x34($v0)
/* BD4D0 80126DD0 ACA30000 */  sw        $v1, ($a1)
/* BD4D4 80126DD4 3C03802F */  lui       $v1, %hi(D_802ED8D0)
/* BD4D8 80126DD8 2463D8D0 */  addiu     $v1, $v1, %lo(D_802ED8D0)
/* BD4DC 80126DDC AC43003C */  sw        $v1, 0x3c($v0)
/* BD4E0 80126DE0 24430048 */  addiu     $v1, $v0, 0x48
/* BD4E4 80126DE4 AC4D0038 */  sw        $t5, 0x38($v0)
/* BD4E8 80126DE8 ACA30000 */  sw        $v1, ($a1)
/* BD4EC 80126DEC 24430050 */  addiu     $v1, $v0, 0x50
/* BD4F0 80126DF0 AC4F0040 */  sw        $t7, 0x40($v0)
/* BD4F4 80126DF4 AC4E0044 */  sw        $t6, 0x44($v0)
/* BD4F8 80126DF8 ACA30000 */  sw        $v1, ($a1)
/* BD4FC 80126DFC 24430058 */  addiu     $v1, $v0, 0x58
/* BD500 80126E00 AC480048 */  sw        $t0, 0x48($v0)
/* BD504 80126E04 AC40004C */  sw        $zero, 0x4c($v0)
/* BD508 80126E08 ACA30000 */  sw        $v1, ($a1)
/* BD50C 80126E0C 24430060 */  addiu     $v1, $v0, 0x60
/* BD510 80126E10 AC470050 */  sw        $a3, 0x50($v0)
/* BD514 80126E14 AC530054 */  sw        $s3, 0x54($v0)
/* BD518 80126E18 ACA30000 */  sw        $v1, ($a1)
/* BD51C 80126E1C 24430068 */  addiu     $v1, $v0, 0x68
/* BD520 80126E20 AC460058 */  sw        $a2, 0x58($v0)
/* BD524 80126E24 AC40005C */  sw        $zero, 0x5c($v0)
/* BD528 80126E28 ACA30000 */  sw        $v1, ($a1)
/* BD52C 80126E2C 24430070 */  addiu     $v1, $v0, 0x70
/* BD530 80126E30 AC550060 */  sw        $s5, 0x60($v0)
/* BD534 80126E34 AC540064 */  sw        $s4, 0x64($v0)
/* BD538 80126E38 ACA30000 */  sw        $v1, ($a1)
/* BD53C 80126E3C 24430078 */  addiu     $v1, $v0, 0x78
/* BD540 80126E40 AC440068 */  sw        $a0, 0x68($v0)
/* BD544 80126E44 AC56006C */  sw        $s6, 0x6c($v0)
/* BD548 80126E48 ACA30000 */  sw        $v1, ($a1)
/* BD54C 80126E4C 3C038015 */  lui       $v1, %hi(D_8014C298)
/* BD550 80126E50 2463C298 */  addiu     $v1, $v1, %lo(D_8014C298)
/* BD554 80126E54 AC430074 */  sw        $v1, 0x74($v0)
/* BD558 80126E58 24430080 */  addiu     $v1, $v0, 0x80
/* BD55C 80126E5C AC570070 */  sw        $s7, 0x70($v0)
/* BD560 80126E60 ACA30000 */  sw        $v1, ($a1)
/* BD564 80126E64 AC590078 */  sw        $t9, 0x78($v0)
/* BD568 80126E68 AC58007C */  sw        $t8, 0x7c($v0)
/* BD56C 80126E6C 8FBF00B8 */  lw        $ra, 0xb8($sp)
/* BD570 80126E70 8FB700B4 */  lw        $s7, 0xb4($sp)
/* BD574 80126E74 8FB600B0 */  lw        $s6, 0xb0($sp)
/* BD578 80126E78 8FB500AC */  lw        $s5, 0xac($sp)
/* BD57C 80126E7C 8FB400A8 */  lw        $s4, 0xa8($sp)
/* BD580 80126E80 8FB300A4 */  lw        $s3, 0xa4($sp)
/* BD584 80126E84 8FB200A0 */  lw        $s2, 0xa0($sp)
/* BD588 80126E88 8FB1009C */  lw        $s1, 0x9c($sp)
/* BD58C 80126E8C 8FB00098 */  lw        $s0, 0x98($sp)
/* BD590 80126E90 D7BC00E0 */  ldc1      $f28, 0xe0($sp)
/* BD594 80126E94 D7BA00D8 */  ldc1      $f26, 0xd8($sp)
/* BD598 80126E98 D7B800D0 */  ldc1      $f24, 0xd0($sp)
/* BD59C 80126E9C D7B600C8 */  ldc1      $f22, 0xc8($sp)
/* BD5A0 80126EA0 D7B400C0 */  ldc1      $f20, 0xc0($sp)
/* BD5A4 80126EA4 03E00008 */  jr        $ra
/* BD5A8 80126EA8 27BD00E8 */   addiu    $sp, $sp, 0xe8
