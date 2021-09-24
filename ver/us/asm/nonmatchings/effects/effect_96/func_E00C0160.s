.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00C0160
/* 3BCEC0 E00C0160 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 3BCEC4 E00C0164 AFBF002C */  sw        $ra, 0x2c($sp)
/* 3BCEC8 E00C0168 AFB00028 */  sw        $s0, 0x28($sp)
/* 3BCECC E00C016C F7B40030 */  sdc1      $f20, 0x30($sp)
/* 3BCED0 E00C0170 8C830000 */  lw        $v1, ($a0)
/* 3BCED4 E00C0174 8C90000C */  lw        $s0, 0xc($a0)
/* 3BCED8 E00C0178 30620010 */  andi      $v0, $v1, 0x10
/* 3BCEDC E00C017C 10400005 */  beqz      $v0, .LE00C0194
/* 3BCEE0 E00C0180 2402FFEF */   addiu    $v0, $zero, -0x11
/* 3BCEE4 E00C0184 00621024 */  and       $v0, $v1, $v0
/* 3BCEE8 E00C0188 AC820000 */  sw        $v0, ($a0)
/* 3BCEEC E00C018C 24020010 */  addiu     $v0, $zero, 0x10
/* 3BCEF0 E00C0190 AE020010 */  sw        $v0, 0x10($s0)
.LE00C0194:
/* 3BCEF4 E00C0194 8E030010 */  lw        $v1, 0x10($s0)
/* 3BCEF8 E00C0198 286203E8 */  slti      $v0, $v1, 0x3e8
/* 3BCEFC E00C019C 10400002 */  beqz      $v0, .LE00C01A8
/* 3BCF00 E00C01A0 2462FFFF */   addiu    $v0, $v1, -1
/* 3BCF04 E00C01A4 AE020010 */  sw        $v0, 0x10($s0)
.LE00C01A8:
/* 3BCF08 E00C01A8 8E020014 */  lw        $v0, 0x14($s0)
/* 3BCF0C E00C01AC 8E050010 */  lw        $a1, 0x10($s0)
/* 3BCF10 E00C01B0 24420001 */  addiu     $v0, $v0, 1
/* 3BCF14 E00C01B4 04A10005 */  bgez      $a1, .LE00C01CC
/* 3BCF18 E00C01B8 AE020014 */   sw       $v0, 0x14($s0)
/* 3BCF1C E00C01BC 0C080128 */  jal       shim_remove_effect
/* 3BCF20 E00C01C0 00000000 */   nop
/* 3BCF24 E00C01C4 080301BF */  j         .LE00C06FC
/* 3BCF28 E00C01C8 00000000 */   nop
.LE00C01CC:
/* 3BCF2C E00C01CC 0040302D */  daddu     $a2, $v0, $zero
/* 3BCF30 E00C01D0 28A20010 */  slti      $v0, $a1, 0x10
/* 3BCF34 E00C01D4 10400002 */  beqz      $v0, .LE00C01E0
/* 3BCF38 E00C01D8 00051100 */   sll      $v0, $a1, 4
/* 3BCF3C E00C01DC AE020024 */  sw        $v0, 0x24($s0)
.LE00C01E0:
/* 3BCF40 E00C01E0 28C20010 */  slti      $v0, $a2, 0x10
/* 3BCF44 E00C01E4 10400003 */  beqz      $v0, .LE00C01F4
/* 3BCF48 E00C01E8 00061100 */   sll      $v0, $a2, 4
/* 3BCF4C E00C01EC 2442000F */  addiu     $v0, $v0, 0xf
/* 3BCF50 E00C01F0 AE020024 */  sw        $v0, 0x24($s0)
.LE00C01F4:
/* 3BCF54 E00C01F4 C604003C */  lwc1      $f4, 0x3c($s0)
/* 3BCF58 E00C01F8 44800000 */  mtc1      $zero, $f0
/* 3BCF5C E00C01FC 00000000 */  nop
/* 3BCF60 E00C0200 46002032 */  c.eq.s    $f4, $f0
/* 3BCF64 E00C0204 00000000 */  nop
/* 3BCF68 E00C0208 45010010 */  bc1t      .LE00C024C
/* 3BCF6C E00C020C 00000000 */   nop
/* 3BCF70 E00C0210 C6020040 */  lwc1      $f2, 0x40($s0)
/* 3BCF74 E00C0214 4600103C */  c.lt.s    $f2, $f0
/* 3BCF78 E00C0218 00000000 */  nop
/* 3BCF7C E00C021C 45030001 */  bc1tl     .LE00C0224
/* 3BCF80 E00C0220 46001087 */   neg.s    $f2, $f2
.LE00C0224:
/* 3BCF84 E00C0224 4600203C */  c.lt.s    $f4, $f0
/* 3BCF88 E00C0228 00000000 */  nop
/* 3BCF8C E00C022C 45000004 */  bc1f      .LE00C0240
/* 3BCF90 E00C0230 00000000 */   nop
/* 3BCF94 E00C0234 C600002C */  lwc1      $f0, 0x2c($s0)
/* 3BCF98 E00C0238 08030092 */  j         .LE00C0248
/* 3BCF9C E00C023C 46020001 */   sub.s    $f0, $f0, $f2
.LE00C0240:
/* 3BCFA0 E00C0240 C600002C */  lwc1      $f0, 0x2c($s0)
/* 3BCFA4 E00C0244 46020000 */  add.s     $f0, $f0, $f2
.LE00C0248:
/* 3BCFA8 E00C0248 E600002C */  swc1      $f0, 0x2c($s0)
.LE00C024C:
/* 3BCFAC E00C024C 8E040058 */  lw        $a0, 0x58($s0)
/* 3BCFB0 E00C0250 24020001 */  addiu     $v0, $zero, 1
/* 3BCFB4 E00C0254 10820028 */  beq       $a0, $v0, .LE00C02F8
/* 3BCFB8 E00C0258 28820002 */   slti     $v0, $a0, 2
/* 3BCFBC E00C025C 10400005 */  beqz      $v0, .LE00C0274
/* 3BCFC0 E00C0260 24050002 */   addiu    $a1, $zero, 2
/* 3BCFC4 E00C0264 10800009 */  beqz      $a0, .LE00C028C
/* 3BCFC8 E00C0268 30C30007 */   andi     $v1, $a2, 7
/* 3BCFCC E00C026C 08030175 */  j         .LE00C05D4
/* 3BCFD0 E00C0270 24020001 */   addiu    $v0, $zero, 1
.LE00C0274:
/* 3BCFD4 E00C0274 10850075 */  beq       $a0, $a1, .LE00C044C
/* 3BCFD8 E00C0278 24020003 */   addiu    $v0, $zero, 3
/* 3BCFDC E00C027C 1082003B */  beq       $a0, $v0, .LE00C036C
/* 3BCFE0 E00C0280 30C30007 */   andi     $v1, $a2, 7
/* 3BCFE4 E00C0284 08030175 */  j         .LE00C05D4
/* 3BCFE8 E00C0288 24020001 */   addiu    $v0, $zero, 1
.LE00C028C:
/* 3BCFEC E00C028C 8E030054 */  lw        $v1, 0x54($s0)
/* 3BCFF0 E00C0290 3C02E00C */  lui       $v0, %hi(D_E00C0A24)
/* 3BCFF4 E00C0294 00431021 */  addu      $v0, $v0, $v1
/* 3BCFF8 E00C0298 90420A24 */  lbu       $v0, %lo(D_E00C0A24)($v0)
/* 3BCFFC E00C029C 3C01E00C */  lui       $at, %hi(D_E00C0C00)
/* 3BD000 E00C02A0 D4220C00 */  ldc1      $f2, %lo(D_E00C0C00)($at)
/* 3BD004 E00C02A4 44820000 */  mtc1      $v0, $f0
/* 3BD008 E00C02A8 00000000 */  nop
/* 3BD00C E00C02AC 46800020 */  cvt.s.w   $f0, $f0
/* 3BD010 E00C02B0 46000021 */  cvt.d.s   $f0, $f0
/* 3BD014 E00C02B4 46220002 */  mul.d     $f0, $f0, $f2
/* 3BD018 E00C02B8 00000000 */  nop
/* 3BD01C E00C02BC 46200020 */  cvt.s.d   $f0, $f0
/* 3BD020 E00C02C0 E600004C */  swc1      $f0, 0x4c($s0)
/* 3BD024 E00C02C4 46000086 */  mov.s     $f2, $f0
/* 3BD028 E00C02C8 3C014000 */  lui       $at, 0x4000
/* 3BD02C E00C02CC 44810000 */  mtc1      $at, $f0
/* 3BD030 E00C02D0 24630001 */  addiu     $v1, $v1, 1
/* 3BD034 E00C02D4 AE030054 */  sw        $v1, 0x54($s0)
/* 3BD038 E00C02D8 46020001 */  sub.s     $f0, $f0, $f2
/* 3BD03C E00C02DC 0060102D */  daddu     $v0, $v1, $zero
/* 3BD040 E00C02E0 2842001B */  slti      $v0, $v0, 0x1b
/* 3BD044 E00C02E4 144000B9 */  bnez      $v0, .LE00C05CC
/* 3BD048 E00C02E8 E6000048 */   swc1     $f0, 0x48($s0)
/* 3BD04C E00C02EC 24020002 */  addiu     $v0, $zero, 2
/* 3BD050 E00C02F0 08030173 */  j         .LE00C05CC
/* 3BD054 E00C02F4 AE020058 */   sw       $v0, 0x58($s0)
.LE00C02F8:
/* 3BD058 E00C02F8 8E030054 */  lw        $v1, 0x54($s0)
/* 3BD05C E00C02FC 3C02E00C */  lui       $v0, %hi(D_E00C0A10)
/* 3BD060 E00C0300 00431021 */  addu      $v0, $v0, $v1
/* 3BD064 E00C0304 80420A10 */  lb        $v0, %lo(D_E00C0A10)($v0)
/* 3BD068 E00C0308 3C01E00C */  lui       $at, %hi(D_E00C0C08)
/* 3BD06C E00C030C D4220C08 */  ldc1      $f2, %lo(D_E00C0C08)($at)
/* 3BD070 E00C0310 44820000 */  mtc1      $v0, $f0
/* 3BD074 E00C0314 00000000 */  nop
/* 3BD078 E00C0318 46800020 */  cvt.s.w   $f0, $f0
/* 3BD07C E00C031C 46000021 */  cvt.d.s   $f0, $f0
/* 3BD080 E00C0320 46220002 */  mul.d     $f0, $f0, $f2
/* 3BD084 E00C0324 00000000 */  nop
/* 3BD088 E00C0328 46200020 */  cvt.s.d   $f0, $f0
/* 3BD08C E00C032C E600004C */  swc1      $f0, 0x4c($s0)
/* 3BD090 E00C0330 46000086 */  mov.s     $f2, $f0
/* 3BD094 E00C0334 3C014000 */  lui       $at, 0x4000
/* 3BD098 E00C0338 44810000 */  mtc1      $at, $f0
/* 3BD09C E00C033C 24630001 */  addiu     $v1, $v1, 1
/* 3BD0A0 E00C0340 AE030054 */  sw        $v1, 0x54($s0)
/* 3BD0A4 E00C0344 46020001 */  sub.s     $f0, $f0, $f2
/* 3BD0A8 E00C0348 0060102D */  daddu     $v0, $v1, $zero
/* 3BD0AC E00C034C 28420012 */  slti      $v0, $v0, 0x12
/* 3BD0B0 E00C0350 14400003 */  bnez      $v0, .LE00C0360
/* 3BD0B4 E00C0354 E6000048 */   swc1     $f0, 0x48($s0)
/* 3BD0B8 E00C0358 24020002 */  addiu     $v0, $zero, 2
/* 3BD0BC E00C035C AE020058 */  sw        $v0, 0x58($s0)
.LE00C0360:
/* 3BD0C0 E00C0360 8E020054 */  lw        $v0, 0x54($s0)
/* 3BD0C4 E00C0364 080300FF */  j         .LE00C03FC
/* 3BD0C8 E00C0368 28420008 */   slti     $v0, $v0, 8
.LE00C036C:
/* 3BD0CC E00C036C 8E030054 */  lw        $v1, 0x54($s0)
/* 3BD0D0 E00C0370 3C02E00C */  lui       $v0, %hi(D_E00C0A40)
/* 3BD0D4 E00C0374 00431021 */  addu      $v0, $v0, $v1
/* 3BD0D8 E00C0378 90420A40 */  lbu       $v0, %lo(D_E00C0A40)($v0)
/* 3BD0DC E00C037C 3C01E00C */  lui       $at, %hi(D_E00C0C10)
/* 3BD0E0 E00C0380 D4220C10 */  ldc1      $f2, %lo(D_E00C0C10)($at)
/* 3BD0E4 E00C0384 44820000 */  mtc1      $v0, $f0
/* 3BD0E8 E00C0388 00000000 */  nop
/* 3BD0EC E00C038C 46800020 */  cvt.s.w   $f0, $f0
/* 3BD0F0 E00C0390 46000021 */  cvt.d.s   $f0, $f0
/* 3BD0F4 E00C0394 46220002 */  mul.d     $f0, $f0, $f2
/* 3BD0F8 E00C0398 00000000 */  nop
/* 3BD0FC E00C039C 46200020 */  cvt.s.d   $f0, $f0
/* 3BD100 E00C03A0 E600004C */  swc1      $f0, 0x4c($s0)
/* 3BD104 E00C03A4 46000086 */  mov.s     $f2, $f0
/* 3BD108 E00C03A8 3C014000 */  lui       $at, 0x4000
/* 3BD10C E00C03AC 44810000 */  mtc1      $at, $f0
/* 3BD110 E00C03B0 24630001 */  addiu     $v1, $v1, 1
/* 3BD114 E00C03B4 46020001 */  sub.s     $f0, $f0, $f2
/* 3BD118 E00C03B8 AE030054 */  sw        $v1, 0x54($s0)
/* 3BD11C E00C03BC 0060102D */  daddu     $v0, $v1, $zero
/* 3BD120 E00C03C0 E6000048 */  swc1      $f0, 0x48($s0)
/* 3BD124 E00C03C4 3C03E00C */  lui       $v1, %hi(D_E00C0A8C)
/* 3BD128 E00C03C8 00621821 */  addu      $v1, $v1, $v0
/* 3BD12C E00C03CC 80630A8C */  lb        $v1, %lo(D_E00C0A8C)($v1)
/* 3BD130 E00C03D0 24420001 */  addiu     $v0, $v0, 1
/* 3BD134 E00C03D4 AE020054 */  sw        $v0, 0x54($s0)
/* 3BD138 E00C03D8 2842004A */  slti      $v0, $v0, 0x4a
/* 3BD13C E00C03DC 44830000 */  mtc1      $v1, $f0
/* 3BD140 E00C03E0 00000000 */  nop
/* 3BD144 E00C03E4 46800020 */  cvt.s.w   $f0, $f0
/* 3BD148 E00C03E8 14400002 */  bnez      $v0, .LE00C03F4
/* 3BD14C E00C03EC E600002C */   swc1     $f0, 0x2c($s0)
/* 3BD150 E00C03F0 AE050058 */  sw        $a1, 0x58($s0)
.LE00C03F4:
/* 3BD154 E00C03F4 8E020054 */  lw        $v0, 0x54($s0)
/* 3BD158 E00C03F8 28420040 */  slti      $v0, $v0, 0x40
.LE00C03FC:
/* 3BD15C E00C03FC 14400074 */  bnez      $v0, .LE00C05D0
/* 3BD160 E00C0400 30C30007 */   andi     $v1, $a2, 7
/* 3BD164 E00C0404 C6080030 */  lwc1      $f8, 0x30($s0)
/* 3BD168 E00C0408 C600003C */  lwc1      $f0, 0x3c($s0)
/* 3BD16C E00C040C C6060034 */  lwc1      $f6, 0x34($s0)
/* 3BD170 E00C0410 46004200 */  add.s     $f8, $f8, $f0
/* 3BD174 E00C0414 C6000040 */  lwc1      $f0, 0x40($s0)
/* 3BD178 E00C0418 C6020038 */  lwc1      $f2, 0x38($s0)
/* 3BD17C E00C041C 46003180 */  add.s     $f6, $f6, $f0
/* 3BD180 E00C0420 C6000044 */  lwc1      $f0, 0x44($s0)
/* 3BD184 E00C0424 3C01BF80 */  lui       $at, 0xbf80
/* 3BD188 E00C0428 44812000 */  mtc1      $at, $f4
/* 3BD18C E00C042C 46001080 */  add.s     $f2, $f2, $f0
/* 3BD190 E00C0430 C6000040 */  lwc1      $f0, 0x40($s0)
/* 3BD194 E00C0434 E6080030 */  swc1      $f8, 0x30($s0)
/* 3BD198 E00C0438 46040000 */  add.s     $f0, $f0, $f4
/* 3BD19C E00C043C E6060034 */  swc1      $f6, 0x34($s0)
/* 3BD1A0 E00C0440 E6020038 */  swc1      $f2, 0x38($s0)
/* 3BD1A4 E00C0444 08030174 */  j         .LE00C05D0
/* 3BD1A8 E00C0448 E6000040 */   swc1     $f0, 0x40($s0)
.LE00C044C:
/* 3BD1AC E00C044C 3C02E00C */  lui       $v0, %hi(D_E00C0A21)
/* 3BD1B0 E00C0450 80420A21 */  lb        $v0, %lo(D_E00C0A21)($v0)
/* 3BD1B4 E00C0454 3C01E00C */  lui       $at, %hi(D_E00C0C18)
/* 3BD1B8 E00C0458 D4220C18 */  ldc1      $f2, %lo(D_E00C0C18)($at)
/* 3BD1BC E00C045C 44820000 */  mtc1      $v0, $f0
/* 3BD1C0 E00C0460 00000000 */  nop
/* 3BD1C4 E00C0464 46800020 */  cvt.s.w   $f0, $f0
/* 3BD1C8 E00C0468 46000021 */  cvt.d.s   $f0, $f0
/* 3BD1CC E00C046C 46220002 */  mul.d     $f0, $f0, $f2
/* 3BD1D0 E00C0470 00000000 */  nop
/* 3BD1D4 E00C0474 C6060030 */  lwc1      $f6, 0x30($s0)
/* 3BD1D8 E00C0478 C602003C */  lwc1      $f2, 0x3c($s0)
/* 3BD1DC E00C047C C6040034 */  lwc1      $f4, 0x34($s0)
/* 3BD1E0 E00C0480 46023180 */  add.s     $f6, $f6, $f2
/* 3BD1E4 E00C0484 C6020040 */  lwc1      $f2, 0x40($s0)
/* 3BD1E8 E00C0488 C6080038 */  lwc1      $f8, 0x38($s0)
/* 3BD1EC E00C048C 46022100 */  add.s     $f4, $f4, $f2
/* 3BD1F0 E00C0490 C6020044 */  lwc1      $f2, 0x44($s0)
/* 3BD1F4 E00C0494 44805000 */  mtc1      $zero, $f10
/* 3BD1F8 E00C0498 46024200 */  add.s     $f8, $f8, $f2
/* 3BD1FC E00C049C C6020050 */  lwc1      $f2, 0x50($s0)
/* 3BD200 E00C04A0 E6040034 */  swc1      $f4, 0x34($s0)
/* 3BD204 E00C04A4 C6040040 */  lwc1      $f4, 0x40($s0)
/* 3BD208 E00C04A8 E6060030 */  swc1      $f6, 0x30($s0)
/* 3BD20C E00C04AC 46022100 */  add.s     $f4, $f4, $f2
/* 3BD210 E00C04B0 C6060034 */  lwc1      $f6, 0x34($s0)
/* 3BD214 E00C04B4 3C014000 */  lui       $at, 0x4000
/* 3BD218 E00C04B8 44811000 */  mtc1      $at, $f2
/* 3BD21C E00C04BC 460A303C */  c.lt.s    $f6, $f10
/* 3BD220 E00C04C0 E6080038 */  swc1      $f8, 0x38($s0)
/* 3BD224 E00C04C4 46200020 */  cvt.s.d   $f0, $f0
/* 3BD228 E00C04C8 46001081 */  sub.s     $f2, $f2, $f0
/* 3BD22C E00C04CC E6040040 */  swc1      $f4, 0x40($s0)
/* 3BD230 E00C04D0 E600004C */  swc1      $f0, 0x4c($s0)
/* 3BD234 E00C04D4 4500003D */  bc1f      .LE00C05CC
/* 3BD238 E00C04D8 E6020048 */   swc1     $f2, 0x48($s0)
/* 3BD23C E00C04DC 8E03005C */  lw        $v1, 0x5c($s0)
/* 3BD240 E00C04E0 2C620005 */  sltiu     $v0, $v1, 5
/* 3BD244 E00C04E4 1040002F */  beqz      $v0, .LE00C05A4
/* 3BD248 E00C04E8 00031080 */   sll      $v0, $v1, 2
/* 3BD24C E00C04EC 3C01E00C */  lui       $at, %hi(jtbl_E00C0C20)
/* 3BD250 E00C04F0 00220821 */  addu      $at, $at, $v0
/* 3BD254 E00C04F4 8C220C20 */  lw        $v0, %lo(jtbl_E00C0C20)($at)
/* 3BD258 E00C04F8 00400008 */  jr        $v0
/* 3BD25C E00C04FC 00000000 */   nop
glabel LE00C0500_3BD260
/* 3BD260 E00C0500 0803016E */  j         .LE00C05B8
/* 3BD264 E00C0504 AE000058 */   sw       $zero, 0x58($s0)
glabel LE00C0508_3BD268
/* 3BD268 E00C0508 3C014000 */  lui       $at, 0x4000
/* 3BD26C E00C050C 44810000 */  mtc1      $at, $f0
/* 3BD270 E00C0510 08030154 */  j         .LE00C0550
/* 3BD274 E00C0514 00000000 */   nop
glabel LE00C0518_3BD278
/* 3BD278 E00C0518 3C014000 */  lui       $at, 0x4000
/* 3BD27C E00C051C 44810000 */  mtc1      $at, $f0
/* 3BD280 E00C0520 3C01C000 */  lui       $at, 0xc000
/* 3BD284 E00C0524 44811000 */  mtc1      $at, $f2
/* 3BD288 E00C0528 3C014120 */  lui       $at, 0x4120
/* 3BD28C E00C052C 44812000 */  mtc1      $at, $f4
/* 3BD290 E00C0530 24020001 */  addiu     $v0, $zero, 1
/* 3BD294 E00C0534 AE020058 */  sw        $v0, 0x58($s0)
/* 3BD298 E00C0538 E600003C */  swc1      $f0, 0x3c($s0)
/* 3BD29C E00C053C E6020044 */  swc1      $f2, 0x44($s0)
/* 3BD2A0 E00C0540 0803016E */  j         .LE00C05B8
/* 3BD2A4 E00C0544 E6040040 */   swc1     $f4, 0x40($s0)
glabel LE00C0548_3BD2A8
/* 3BD2A8 E00C0548 3C01C000 */  lui       $at, 0xc000
/* 3BD2AC E00C054C 44810000 */  mtc1      $at, $f0
.LE00C0550:
/* 3BD2B0 E00C0550 3C014120 */  lui       $at, 0x4120
/* 3BD2B4 E00C0554 44811000 */  mtc1      $at, $f2
/* 3BD2B8 E00C0558 24020001 */  addiu     $v0, $zero, 1
/* 3BD2BC E00C055C AE020058 */  sw        $v0, 0x58($s0)
/* 3BD2C0 E00C0560 E600003C */  swc1      $f0, 0x3c($s0)
/* 3BD2C4 E00C0564 E6000044 */  swc1      $f0, 0x44($s0)
/* 3BD2C8 E00C0568 0803016E */  j         .LE00C05B8
/* 3BD2CC E00C056C E6020040 */   swc1     $f2, 0x40($s0)
glabel LE00C0570_3BD2D0
/* 3BD2D0 E00C0570 3C014120 */  lui       $at, 0x4120
/* 3BD2D4 E00C0574 44810000 */  mtc1      $at, $f0
/* 3BD2D8 E00C0578 3C014160 */  lui       $at, 0x4160
/* 3BD2DC E00C057C 44811000 */  mtc1      $at, $f2
/* 3BD2E0 E00C0580 3C01BF80 */  lui       $at, 0xbf80
/* 3BD2E4 E00C0584 44812000 */  mtc1      $at, $f4
/* 3BD2E8 E00C0588 24020001 */  addiu     $v0, $zero, 1
/* 3BD2EC E00C058C AE000044 */  sw        $zero, 0x44($s0)
/* 3BD2F0 E00C0590 AE020058 */  sw        $v0, 0x58($s0)
/* 3BD2F4 E00C0594 E600003C */  swc1      $f0, 0x3c($s0)
/* 3BD2F8 E00C0598 E6020040 */  swc1      $f2, 0x40($s0)
/* 3BD2FC E00C059C 0803016E */  j         .LE00C05B8
/* 3BD300 E00C05A0 E6040050 */   swc1     $f4, 0x50($s0)
.LE00C05A4:
/* 3BD304 E00C05A4 E60A003C */  swc1      $f10, 0x3c($s0)
/* 3BD308 E00C05A8 E60A0040 */  swc1      $f10, 0x40($s0)
/* 3BD30C E00C05AC E60A0044 */  swc1      $f10, 0x44($s0)
/* 3BD310 E00C05B0 E60A0034 */  swc1      $f10, 0x34($s0)
/* 3BD314 E00C05B4 AE040058 */  sw        $a0, 0x58($s0)
.LE00C05B8:
/* 3BD318 E00C05B8 8E02005C */  lw        $v0, 0x5c($s0)
/* 3BD31C E00C05BC AE000034 */  sw        $zero, 0x34($s0)
/* 3BD320 E00C05C0 AE000054 */  sw        $zero, 0x54($s0)
/* 3BD324 E00C05C4 24420001 */  addiu     $v0, $v0, 1
/* 3BD328 E00C05C8 AE02005C */  sw        $v0, 0x5c($s0)
.LE00C05CC:
/* 3BD32C E00C05CC 30C30007 */  andi      $v1, $a2, 7
.LE00C05D0:
/* 3BD330 E00C05D0 24020001 */  addiu     $v0, $zero, 1
.LE00C05D4:
/* 3BD334 E00C05D4 14620049 */  bne       $v1, $v0, .LE00C06FC
/* 3BD338 E00C05D8 00000000 */   nop
/* 3BD33C E00C05DC 0C080150 */  jal       shim_load_effect
/* 3BD340 E00C05E0 2404006F */   addiu    $a0, $zero, 0x6f
/* 3BD344 E00C05E4 0C080138 */  jal       shim_rand_int
/* 3BD348 E00C05E8 2404003C */   addiu    $a0, $zero, 0x3c
/* 3BD34C E00C05EC C6140004 */  lwc1      $f20, 4($s0)
/* 3BD350 E00C05F0 C6000030 */  lwc1      $f0, 0x30($s0)
/* 3BD354 E00C05F4 4600A500 */  add.s     $f20, $f20, $f0
/* 3BD358 E00C05F8 44820000 */  mtc1      $v0, $f0
/* 3BD35C E00C05FC 00000000 */  nop
/* 3BD360 E00C0600 46800020 */  cvt.s.w   $f0, $f0
/* 3BD364 E00C0604 4600A500 */  add.s     $f20, $f20, $f0
/* 3BD368 E00C0608 3C0141F0 */  lui       $at, 0x41f0
/* 3BD36C E00C060C 44810000 */  mtc1      $at, $f0
/* 3BD370 E00C0610 24040064 */  addiu     $a0, $zero, 0x64
/* 3BD374 E00C0614 0C080138 */  jal       shim_rand_int
/* 3BD378 E00C0618 4600A501 */   sub.s    $f20, $f20, $f0
/* 3BD37C E00C061C C602000C */  lwc1      $f2, 0xc($s0)
/* 3BD380 E00C0620 C6000038 */  lwc1      $f0, 0x38($s0)
/* 3BD384 E00C0624 46001080 */  add.s     $f2, $f2, $f0
/* 3BD388 E00C0628 C6000034 */  lwc1      $f0, 0x34($s0)
/* 3BD38C E00C062C 44071000 */  mfc1      $a3, $f2
/* 3BD390 E00C0630 C6020008 */  lwc1      $f2, 8($s0)
/* 3BD394 E00C0634 46001080 */  add.s     $f2, $f2, $f0
/* 3BD398 E00C0638 44820000 */  mtc1      $v0, $f0
/* 3BD39C E00C063C 00000000 */  nop
/* 3BD3A0 E00C0640 46800020 */  cvt.s.w   $f0, $f0
/* 3BD3A4 E00C0644 46001080 */  add.s     $f2, $f2, $f0
/* 3BD3A8 E00C0648 3C014248 */  lui       $at, 0x4248
/* 3BD3AC E00C064C 44810000 */  mtc1      $at, $f0
/* 3BD3B0 E00C0650 24040002 */  addiu     $a0, $zero, 2
/* 3BD3B4 E00C0654 46001080 */  add.s     $f2, $f2, $f0
/* 3BD3B8 E00C0658 4405A000 */  mfc1      $a1, $f20
/* 3BD3BC E00C065C 3C014080 */  lui       $at, 0x4080
/* 3BD3C0 E00C0660 44810000 */  mtc1      $at, $f0
/* 3BD3C4 E00C0664 44061000 */  mfc1      $a2, $f2
/* 3BD3C8 E00C0668 24020028 */  addiu     $v0, $zero, 0x28
/* 3BD3CC E00C066C AFA20014 */  sw        $v0, 0x14($sp)
/* 3BD3D0 E00C0670 0C037800 */  jal       fx_111_main
/* 3BD3D4 E00C0674 E7A00010 */   swc1     $f0, 0x10($sp)
/* 3BD3D8 E00C0678 0C080150 */  jal       shim_load_effect
/* 3BD3DC E00C067C 24040072 */   addiu    $a0, $zero, 0x72
/* 3BD3E0 E00C0680 C6020004 */  lwc1      $f2, 4($s0)
/* 3BD3E4 E00C0684 C6000030 */  lwc1      $f0, 0x30($s0)
/* 3BD3E8 E00C0688 46001080 */  add.s     $f2, $f2, $f0
/* 3BD3EC E00C068C 24040001 */  addiu     $a0, $zero, 1
/* 3BD3F0 E00C0690 C6000034 */  lwc1      $f0, 0x34($s0)
/* 3BD3F4 E00C0694 44051000 */  mfc1      $a1, $f2
/* 3BD3F8 E00C0698 C6020008 */  lwc1      $f2, 8($s0)
/* 3BD3FC E00C069C C6080038 */  lwc1      $f8, 0x38($s0)
/* 3BD400 E00C06A0 46001080 */  add.s     $f2, $f2, $f0
/* 3BD404 E00C06A4 C600000C */  lwc1      $f0, 0xc($s0)
/* 3BD408 E00C06A8 2402000A */  addiu     $v0, $zero, 0xa
/* 3BD40C E00C06AC 46080000 */  add.s     $f0, $f0, $f8
/* 3BD410 E00C06B0 3C014120 */  lui       $at, 0x4120
/* 3BD414 E00C06B4 44812000 */  mtc1      $at, $f4
/* 3BD418 E00C06B8 3C014270 */  lui       $at, 0x4270
/* 3BD41C E00C06BC 44813000 */  mtc1      $at, $f6
/* 3BD420 E00C06C0 46041080 */  add.s     $f2, $f2, $f4
/* 3BD424 E00C06C4 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3BD428 E00C06C8 3C014000 */  lui       $at, 0x4000
/* 3BD42C E00C06CC 44812000 */  mtc1      $at, $f4
/* 3BD430 E00C06D0 46060000 */  add.s     $f0, $f0, $f6
/* 3BD434 E00C06D4 44061000 */  mfc1      $a2, $f2
/* 3BD438 E00C06D8 3C0142C8 */  lui       $at, 0x42c8
/* 3BD43C E00C06DC 44811000 */  mtc1      $at, $f2
/* 3BD440 E00C06E0 44070000 */  mfc1      $a3, $f0
/* 3BD444 E00C06E4 2402001E */  addiu     $v0, $zero, 0x1e
/* 3BD448 E00C06E8 AFA20020 */  sw        $v0, 0x20($sp)
/* 3BD44C E00C06EC E7A60010 */  swc1      $f6, 0x10($sp)
/* 3BD450 E00C06F0 E7A40018 */  swc1      $f4, 0x18($sp)
/* 3BD454 E00C06F4 0C039000 */  jal       fx_114_main
/* 3BD458 E00C06F8 E7A20014 */   swc1     $f2, 0x14($sp)
.LE00C06FC:
/* 3BD45C E00C06FC 8FBF002C */  lw        $ra, 0x2c($sp)
/* 3BD460 E00C0700 8FB00028 */  lw        $s0, 0x28($sp)
/* 3BD464 E00C0704 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 3BD468 E00C0708 03E00008 */  jr        $ra
/* 3BD46C E00C070C 27BD0038 */   addiu    $sp, $sp, 0x38
