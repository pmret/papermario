.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218058_4FEAA8
/* 4FEAA8 80218058 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 4FEAAC 8021805C F7B60020 */  sdc1      $f22, 0x20($sp)
/* 4FEAB0 80218060 46006586 */  mov.s     $f22, $f12
/* 4FEAB4 80218064 F7B40018 */  sdc1      $f20, 0x18($sp)
/* 4FEAB8 80218068 AFBF0010 */  sw        $ra, 0x10($sp)
/* 4FEABC 8021806C 0C00A3FC */  jal       length2D
/* 4FEAC0 80218070 46007506 */   mov.s    $f20, $f14
/* 4FEAC4 80218074 4600A18D */  trunc.w.s $f6, $f20
/* 4FEAC8 80218078 44023000 */  mfc1      $v0, $f6
/* 4FEACC 8021807C 00000000 */  nop
/* 4FEAD0 80218080 04420001 */  bltzl     $v0, .L80218088
/* 4FEAD4 80218084 00021023 */   negu     $v0, $v0
.L80218088:
/* 4FEAD8 80218088 44821000 */  mtc1      $v0, $f2
/* 4FEADC 8021808C 00000000 */  nop
/* 4FEAE0 80218090 468010A0 */  cvt.s.w   $f2, $f2
/* 4FEAE4 80218094 46001103 */  div.s     $f4, $f2, $f0
/* 4FEAE8 80218098 0000202D */  daddu     $a0, $zero, $zero
/* 4FEAEC 8021809C 2406005A */  addiu     $a2, $zero, 0x5a
/* 4FEAF0 802180A0 0080282D */  daddu     $a1, $a0, $zero
/* 4FEAF4 802180A4 3C078022 */  lui       $a3, %hi(D_8021A4BC)
/* 4FEAF8 802180A8 24E7A4BC */  addiu     $a3, $a3, %lo(D_8021A4BC)
/* 4FEAFC 802180AC 30C2FFFF */  andi      $v0, $a2, 0xffff
.L802180B0:
/* 4FEB00 802180B0 3083FFFF */  andi      $v1, $a0, 0xffff
/* 4FEB04 802180B4 00431023 */  subu      $v0, $v0, $v1
/* 4FEB08 802180B8 00021FC2 */  srl       $v1, $v0, 0x1f
/* 4FEB0C 802180BC 00431021 */  addu      $v0, $v0, $v1
/* 4FEB10 802180C0 00021043 */  sra       $v0, $v0, 1
/* 4FEB14 802180C4 00821821 */  addu      $v1, $a0, $v0
/* 4FEB18 802180C8 3062FFFF */  andi      $v0, $v1, 0xffff
/* 4FEB1C 802180CC 00021080 */  sll       $v0, $v0, 2
/* 4FEB20 802180D0 00471021 */  addu      $v0, $v0, $a3
/* 4FEB24 802180D4 C4400000 */  lwc1      $f0, ($v0)
/* 4FEB28 802180D8 4604003C */  c.lt.s    $f0, $f4
/* 4FEB2C 802180DC 00000000 */  nop
/* 4FEB30 802180E0 45020002 */  bc1fl     .L802180EC
/* 4FEB34 802180E4 0060302D */   daddu    $a2, $v1, $zero
/* 4FEB38 802180E8 0060202D */  daddu     $a0, $v1, $zero
.L802180EC:
/* 4FEB3C 802180EC 24A50001 */  addiu     $a1, $a1, 1
/* 4FEB40 802180F0 30A2FFFF */  andi      $v0, $a1, 0xffff
/* 4FEB44 802180F4 2C420007 */  sltiu     $v0, $v0, 7
/* 4FEB48 802180F8 1440FFED */  bnez      $v0, .L802180B0
/* 4FEB4C 802180FC 30C2FFFF */   andi     $v0, $a2, 0xffff
/* 4FEB50 80218100 3082FFFF */  andi      $v0, $a0, 0xffff
/* 4FEB54 80218104 00021080 */  sll       $v0, $v0, 2
/* 4FEB58 80218108 30C3FFFF */  andi      $v1, $a2, 0xffff
/* 4FEB5C 8021810C 3C018022 */  lui       $at, %hi(D_8021A4BC)
/* 4FEB60 80218110 00220821 */  addu      $at, $at, $v0
/* 4FEB64 80218114 C422A4BC */  lwc1      $f2, %lo(D_8021A4BC)($at)
/* 4FEB68 80218118 00031880 */  sll       $v1, $v1, 2
/* 4FEB6C 8021811C 46041081 */  sub.s     $f2, $f2, $f4
/* 4FEB70 80218120 3C018022 */  lui       $at, %hi(D_8021A4BC)
/* 4FEB74 80218124 00230821 */  addu      $at, $at, $v1
/* 4FEB78 80218128 C420A4BC */  lwc1      $f0, %lo(D_8021A4BC)($at)
/* 4FEB7C 8021812C 46040001 */  sub.s     $f0, $f0, $f4
/* 4FEB80 80218130 46001085 */  abs.s     $f2, $f2
/* 4FEB84 80218134 46000005 */  abs.s     $f0, $f0
/* 4FEB88 80218138 4600103C */  c.lt.s    $f2, $f0
/* 4FEB8C 8021813C 00000000 */  nop
/* 4FEB90 80218140 45000002 */  bc1f      .L8021814C
/* 4FEB94 80218144 00C0182D */   daddu    $v1, $a2, $zero
/* 4FEB98 80218148 0080182D */  daddu     $v1, $a0, $zero
.L8021814C:
/* 4FEB9C 8021814C 44800000 */  mtc1      $zero, $f0
/* 4FEBA0 80218150 00000000 */  nop
/* 4FEBA4 80218154 4600B03C */  c.lt.s    $f22, $f0
/* 4FEBA8 80218158 00000000 */  nop
/* 4FEBAC 8021815C 4500000A */  bc1f      .L80218188
/* 4FEBB0 80218160 00000000 */   nop
/* 4FEBB4 80218164 4614003E */  c.le.s    $f0, $f20
/* 4FEBB8 80218168 00000000 */  nop
/* 4FEBBC 8021816C 45000004 */  bc1f      .L80218180
/* 4FEBC0 80218170 240200B4 */   addiu    $v0, $zero, 0xb4
/* 4FEBC4 80218174 00431823 */  subu      $v1, $v0, $v1
/* 4FEBC8 80218178 44800000 */  mtc1      $zero, $f0
/* 4FEBCC 8021817C 00000000 */  nop
.L80218180:
/* 4FEBD0 80218180 4600B03C */  c.lt.s    $f22, $f0
/* 4FEBD4 80218184 00000000 */  nop
.L80218188:
/* 4FEBD8 80218188 45000005 */  bc1f      .L802181A0
/* 4FEBDC 8021818C 00000000 */   nop
/* 4FEBE0 80218190 4600A03C */  c.lt.s    $f20, $f0
/* 4FEBE4 80218194 00000000 */  nop
/* 4FEBE8 80218198 45030001 */  bc1tl     .L802181A0
/* 4FEBEC 8021819C 246300B4 */   addiu    $v1, $v1, 0xb4
.L802181A0:
/* 4FEBF0 802181A0 44800000 */  mtc1      $zero, $f0
/* 4FEBF4 802181A4 00000000 */  nop
/* 4FEBF8 802181A8 4616003E */  c.le.s    $f0, $f22
/* 4FEBFC 802181AC 00000000 */  nop
/* 4FEC00 802181B0 45000006 */  bc1f      .L802181CC
/* 4FEC04 802181B4 00000000 */   nop
/* 4FEC08 802181B8 4600A03C */  c.lt.s    $f20, $f0
/* 4FEC0C 802181BC 00000000 */  nop
/* 4FEC10 802181C0 45000002 */  bc1f      .L802181CC
/* 4FEC14 802181C4 24020168 */   addiu    $v0, $zero, 0x168
/* 4FEC18 802181C8 00431823 */  subu      $v1, $v0, $v1
.L802181CC:
/* 4FEC1C 802181CC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 4FEC20 802181D0 D7B60020 */  ldc1      $f22, 0x20($sp)
/* 4FEC24 802181D4 D7B40018 */  ldc1      $f20, 0x18($sp)
/* 4FEC28 802181D8 3062FFFF */  andi      $v0, $v1, 0xffff
/* 4FEC2C 802181DC 03E00008 */  jr        $ra
/* 4FEC30 802181E0 27BD0028 */   addiu    $sp, $sp, 0x28
