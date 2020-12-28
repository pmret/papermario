.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021BC60_6A2E60
/* 6A2E60 8021BC60 27BDFF58 */  addiu     $sp, $sp, -0xa8
/* 6A2E64 8021BC64 AFB30074 */  sw        $s3, 0x74($sp)
/* 6A2E68 8021BC68 0080982D */  daddu     $s3, $a0, $zero
/* 6A2E6C 8021BC6C AFBF0088 */  sw        $ra, 0x88($sp)
/* 6A2E70 8021BC70 AFB70084 */  sw        $s7, 0x84($sp)
/* 6A2E74 8021BC74 AFB60080 */  sw        $s6, 0x80($sp)
/* 6A2E78 8021BC78 AFB5007C */  sw        $s5, 0x7c($sp)
/* 6A2E7C 8021BC7C AFB40078 */  sw        $s4, 0x78($sp)
/* 6A2E80 8021BC80 AFB20070 */  sw        $s2, 0x70($sp)
/* 6A2E84 8021BC84 AFB1006C */  sw        $s1, 0x6c($sp)
/* 6A2E88 8021BC88 AFB00068 */  sw        $s0, 0x68($sp)
/* 6A2E8C 8021BC8C F7B800A0 */  sdc1      $f24, 0xa0($sp)
/* 6A2E90 8021BC90 F7B60098 */  sdc1      $f22, 0x98($sp)
/* 6A2E94 8021BC94 F7B40090 */  sdc1      $f20, 0x90($sp)
/* 6A2E98 8021BC98 8E640148 */  lw        $a0, 0x148($s3)
/* 6A2E9C 8021BC9C 0C09A75B */  jal       get_actor
/* 6A2EA0 8021BCA0 00A0802D */   daddu    $s0, $a1, $zero
/* 6A2EA4 8021BCA4 14400003 */  bnez      $v0, .L8021BCB4
/* 6A2EA8 8021BCA8 0040202D */   daddu    $a0, $v0, $zero
/* 6A2EAC 8021BCAC 08086FF3 */  j         .L8021BFCC
/* 6A2EB0 8021BCB0 24020002 */   addiu    $v0, $zero, 2
.L8021BCB4:
/* 6A2EB4 8021BCB4 0C099117 */  jal       get_actor_part
/* 6A2EB8 8021BCB8 24050001 */   addiu    $a1, $zero, 1
/* 6A2EBC 8021BCBC 12000013 */  beqz      $s0, .L8021BD0C
/* 6A2EC0 8021BCC0 0040A82D */   daddu    $s5, $v0, $zero
/* 6A2EC4 8021BCC4 0000802D */  daddu     $s0, $zero, $zero
/* 6A2EC8 8021BCC8 241100FF */  addiu     $s1, $zero, 0xff
/* 6A2ECC 8021BCCC AE600074 */  sw        $zero, 0x74($s3)
/* 6A2ED0 8021BCD0 AE600078 */  sw        $zero, 0x78($s3)
/* 6A2ED4 8021BCD4 AE600070 */  sw        $zero, 0x70($s3)
/* 6A2ED8 8021BCD8 0200282D */  daddu     $a1, $s0, $zero
.L8021BCDC:
/* 6A2EDC 8021BCDC 24060011 */  addiu     $a2, $zero, 0x11
/* 6A2EE0 8021BCE0 24070014 */  addiu     $a3, $zero, 0x14
/* 6A2EE4 8021BCE4 AFA00010 */  sw        $zero, 0x10($sp)
/* 6A2EE8 8021BCE8 AFA00014 */  sw        $zero, 0x14($sp)
/* 6A2EEC 8021BCEC AFB10018 */  sw        $s1, 0x18($sp)
/* 6A2EF0 8021BCF0 AFA0001C */  sw        $zero, 0x1c($sp)
/* 6A2EF4 8021BCF4 8EA40084 */  lw        $a0, 0x84($s5)
/* 6A2EF8 8021BCF8 0C0B79E0 */  jal       func_802DE780
/* 6A2EFC 8021BCFC 26100001 */   addiu    $s0, $s0, 1
/* 6A2F00 8021BD00 2A02000A */  slti      $v0, $s0, 0xa
/* 6A2F04 8021BD04 1440FFF5 */  bnez      $v0, .L8021BCDC
/* 6A2F08 8021BD08 0200282D */   daddu    $a1, $s0, $zero
.L8021BD0C:
/* 6A2F0C 8021BD0C 8E620074 */  lw        $v0, 0x74($s3)
/* 6A2F10 8021BD10 2444000A */  addiu     $a0, $v0, 0xa
/* 6A2F14 8021BD14 28820168 */  slti      $v0, $a0, 0x168
/* 6A2F18 8021BD18 14400010 */  bnez      $v0, .L8021BD5C
/* 6A2F1C 8021BD1C AE640074 */   sw       $a0, 0x74($s3)
/* 6A2F20 8021BD20 3C02B60B */  lui       $v0, 0xb60b
/* 6A2F24 8021BD24 344260B7 */  ori       $v0, $v0, 0x60b7
/* 6A2F28 8021BD28 00820018 */  mult      $a0, $v0
/* 6A2F2C 8021BD2C 00041FC3 */  sra       $v1, $a0, 0x1f
/* 6A2F30 8021BD30 00004010 */  mfhi      $t0
/* 6A2F34 8021BD34 01041021 */  addu      $v0, $t0, $a0
/* 6A2F38 8021BD38 00021203 */  sra       $v0, $v0, 8
/* 6A2F3C 8021BD3C 00431023 */  subu      $v0, $v0, $v1
/* 6A2F40 8021BD40 00021840 */  sll       $v1, $v0, 1
/* 6A2F44 8021BD44 00621821 */  addu      $v1, $v1, $v0
/* 6A2F48 8021BD48 00031100 */  sll       $v0, $v1, 4
/* 6A2F4C 8021BD4C 00431023 */  subu      $v0, $v0, $v1
/* 6A2F50 8021BD50 000210C0 */  sll       $v0, $v0, 3
/* 6A2F54 8021BD54 00821023 */  subu      $v0, $a0, $v0
/* 6A2F58 8021BD58 AE620074 */  sw        $v0, 0x74($s3)
.L8021BD5C:
/* 6A2F5C 8021BD5C 0000882D */  daddu     $s1, $zero, $zero
/* 6A2F60 8021BD60 3C128000 */  lui       $s2, 0x8000
/* 6A2F64 8021BD64 0220802D */  daddu     $s0, $s1, $zero
/* 6A2F68 8021BD68 3C013FF0 */  lui       $at, 0x3ff0
/* 6A2F6C 8021BD6C 4481C800 */  mtc1      $at, $f25
/* 6A2F70 8021BD70 4480C000 */  mtc1      $zero, $f24
/* 6A2F74 8021BD74 3C01404C */  lui       $at, 0x404c
/* 6A2F78 8021BD78 4481B800 */  mtc1      $at, $f23
/* 6A2F7C 8021BD7C 4480B000 */  mtc1      $zero, $f22
/* 6A2F80 8021BD80 3C0141E0 */  lui       $at, 0x41e0
/* 6A2F84 8021BD84 4481A800 */  mtc1      $at, $f21
/* 6A2F88 8021BD88 4480A000 */  mtc1      $zero, $f20
.L8021BD8C:
/* 6A2F8C 8021BD8C 96640076 */  lhu       $a0, 0x76($s3)
/* 6A2F90 8021BD90 00902021 */  addu      $a0, $a0, $s0
/* 6A2F94 8021BD94 24840078 */  addiu     $a0, $a0, 0x78
/* 6A2F98 8021BD98 00042400 */  sll       $a0, $a0, 0x10
/* 6A2F9C 8021BD9C 0C00A4F5 */  jal       cosine
/* 6A2FA0 8021BDA0 00042403 */   sra      $a0, $a0, 0x10
/* 6A2FA4 8021BDA4 46000021 */  cvt.d.s   $f0, $f0
/* 6A2FA8 8021BDA8 46380000 */  add.d     $f0, $f0, $f24
/* 6A2FAC 8021BDAC 46360002 */  mul.d     $f0, $f0, $f22
/* 6A2FB0 8021BDB0 00000000 */  nop       
/* 6A2FB4 8021BDB4 27A20020 */  addiu     $v0, $sp, 0x20
/* 6A2FB8 8021BDB8 4620A03E */  c.le.d    $f20, $f0
/* 6A2FBC 8021BDBC 00000000 */  nop       
/* 6A2FC0 8021BDC0 45010005 */  bc1t      .L8021BDD8
/* 6A2FC4 8021BDC4 00511021 */   addu     $v0, $v0, $s1
/* 6A2FC8 8021BDC8 4620008D */  trunc.w.d $f2, $f0
/* 6A2FCC 8021BDCC 44031000 */  mfc1      $v1, $f2
/* 6A2FD0 8021BDD0 08086F7C */  j         .L8021BDF0
/* 6A2FD4 8021BDD4 A0430000 */   sb       $v1, ($v0)
.L8021BDD8:
/* 6A2FD8 8021BDD8 46340001 */  sub.d     $f0, $f0, $f20
/* 6A2FDC 8021BDDC 4620008D */  trunc.w.d $f2, $f0
/* 6A2FE0 8021BDE0 44031000 */  mfc1      $v1, $f2
/* 6A2FE4 8021BDE4 00000000 */  nop       
/* 6A2FE8 8021BDE8 00721825 */  or        $v1, $v1, $s2
/* 6A2FEC 8021BDEC A0430000 */  sb        $v1, ($v0)
.L8021BDF0:
/* 6A2FF0 8021BDF0 96640076 */  lhu       $a0, 0x76($s3)
/* 6A2FF4 8021BDF4 00902021 */  addu      $a0, $a0, $s0
/* 6A2FF8 8021BDF8 2484003C */  addiu     $a0, $a0, 0x3c
/* 6A2FFC 8021BDFC 00042400 */  sll       $a0, $a0, 0x10
/* 6A3000 8021BE00 0C00A4F5 */  jal       cosine
/* 6A3004 8021BE04 00042403 */   sra      $a0, $a0, 0x10
/* 6A3008 8021BE08 46000021 */  cvt.d.s   $f0, $f0
/* 6A300C 8021BE0C 46380000 */  add.d     $f0, $f0, $f24
/* 6A3010 8021BE10 46360002 */  mul.d     $f0, $f0, $f22
/* 6A3014 8021BE14 00000000 */  nop       
/* 6A3018 8021BE18 27A20038 */  addiu     $v0, $sp, 0x38
/* 6A301C 8021BE1C 4620A03E */  c.le.d    $f20, $f0
/* 6A3020 8021BE20 00000000 */  nop       
/* 6A3024 8021BE24 45010005 */  bc1t      .L8021BE3C
/* 6A3028 8021BE28 00511021 */   addu     $v0, $v0, $s1
/* 6A302C 8021BE2C 4620008D */  trunc.w.d $f2, $f0
/* 6A3030 8021BE30 44031000 */  mfc1      $v1, $f2
/* 6A3034 8021BE34 08086F95 */  j         .L8021BE54
/* 6A3038 8021BE38 A0430000 */   sb       $v1, ($v0)
.L8021BE3C:
/* 6A303C 8021BE3C 46340001 */  sub.d     $f0, $f0, $f20
/* 6A3040 8021BE40 4620008D */  trunc.w.d $f2, $f0
/* 6A3044 8021BE44 44031000 */  mfc1      $v1, $f2
/* 6A3048 8021BE48 00000000 */  nop       
/* 6A304C 8021BE4C 00721825 */  or        $v1, $v1, $s2
/* 6A3050 8021BE50 A0430000 */  sb        $v1, ($v0)
.L8021BE54:
/* 6A3054 8021BE54 96640076 */  lhu       $a0, 0x76($s3)
/* 6A3058 8021BE58 00902021 */  addu      $a0, $a0, $s0
/* 6A305C 8021BE5C 248400B4 */  addiu     $a0, $a0, 0xb4
/* 6A3060 8021BE60 00042400 */  sll       $a0, $a0, 0x10
/* 6A3064 8021BE64 0C00A4F5 */  jal       cosine
/* 6A3068 8021BE68 00042403 */   sra      $a0, $a0, 0x10
/* 6A306C 8021BE6C 46000021 */  cvt.d.s   $f0, $f0
/* 6A3070 8021BE70 46380000 */  add.d     $f0, $f0, $f24
/* 6A3074 8021BE74 46360002 */  mul.d     $f0, $f0, $f22
/* 6A3078 8021BE78 00000000 */  nop       
/* 6A307C 8021BE7C 27A20050 */  addiu     $v0, $sp, 0x50
/* 6A3080 8021BE80 4620A03E */  c.le.d    $f20, $f0
/* 6A3084 8021BE84 00000000 */  nop       
/* 6A3088 8021BE88 45010005 */  bc1t      .L8021BEA0
/* 6A308C 8021BE8C 00511021 */   addu     $v0, $v0, $s1
/* 6A3090 8021BE90 4620008D */  trunc.w.d $f2, $f0
/* 6A3094 8021BE94 44031000 */  mfc1      $v1, $f2
/* 6A3098 8021BE98 08086FAE */  j         .L8021BEB8
/* 6A309C 8021BE9C A0430000 */   sb       $v1, ($v0)
.L8021BEA0:
/* 6A30A0 8021BEA0 46340001 */  sub.d     $f0, $f0, $f20
/* 6A30A4 8021BEA4 4620008D */  trunc.w.d $f2, $f0
/* 6A30A8 8021BEA8 44031000 */  mfc1      $v1, $f2
/* 6A30AC 8021BEAC 00000000 */  nop       
/* 6A30B0 8021BEB0 00721825 */  or        $v1, $v1, $s2
/* 6A30B4 8021BEB4 A0430000 */  sb        $v1, ($v0)
.L8021BEB8:
/* 6A30B8 8021BEB8 26310001 */  addiu     $s1, $s1, 1
/* 6A30BC 8021BEBC 2A220014 */  slti      $v0, $s1, 0x14
/* 6A30C0 8021BEC0 1440FFB2 */  bnez      $v0, .L8021BD8C
/* 6A30C4 8021BEC4 26100019 */   addiu    $s0, $s0, 0x19
/* 6A30C8 8021BEC8 8EA2007C */  lw        $v0, 0x7c($s5)
/* 6A30CC 8021BECC 3C030008 */  lui       $v1, 8
/* 6A30D0 8021BED0 00431024 */  and       $v0, $v0, $v1
/* 6A30D4 8021BED4 10400025 */  beqz      $v0, .L8021BF6C
/* 6A30D8 8021BED8 0000882D */   daddu    $s1, $zero, $zero
/* 6A30DC 8021BEDC 27B70020 */  addiu     $s7, $sp, 0x20
/* 6A30E0 8021BEE0 27B60038 */  addiu     $s6, $sp, 0x38
/* 6A30E4 8021BEE4 27B40050 */  addiu     $s4, $sp, 0x50
/* 6A30E8 8021BEE8 241300FF */  addiu     $s3, $zero, 0xff
/* 6A30EC 8021BEEC 0000802D */  daddu     $s0, $zero, $zero
.L8021BEF0:
/* 6A30F0 8021BEF0 02F11021 */  addu      $v0, $s7, $s1
/* 6A30F4 8021BEF4 02D12021 */  addu      $a0, $s6, $s1
/* 6A30F8 8021BEF8 90430000 */  lbu       $v1, ($v0)
/* 6A30FC 8021BEFC 02911021 */  addu      $v0, $s4, $s1
/* 6A3100 8021BF00 90840000 */  lbu       $a0, ($a0)
/* 6A3104 8021BF04 90420000 */  lbu       $v0, ($v0)
/* 6A3108 8021BF08 00031E00 */  sll       $v1, $v1, 0x18
/* 6A310C 8021BF0C 00042400 */  sll       $a0, $a0, 0x10
/* 6A3110 8021BF10 00641825 */  or        $v1, $v1, $a0
/* 6A3114 8021BF14 00021200 */  sll       $v0, $v0, 8
/* 6A3118 8021BF18 00621825 */  or        $v1, $v1, $v0
/* 6A311C 8021BF1C 347200FF */  ori       $s2, $v1, 0xff
/* 6A3120 8021BF20 0200282D */  daddu     $a1, $s0, $zero
.L8021BF24:
/* 6A3124 8021BF24 2406000C */  addiu     $a2, $zero, 0xc
/* 6A3128 8021BF28 0220382D */  daddu     $a3, $s1, $zero
/* 6A312C 8021BF2C AFB20010 */  sw        $s2, 0x10($sp)
/* 6A3130 8021BF30 AFA00014 */  sw        $zero, 0x14($sp)
/* 6A3134 8021BF34 AFB30018 */  sw        $s3, 0x18($sp)
/* 6A3138 8021BF38 AFA0001C */  sw        $zero, 0x1c($sp)
/* 6A313C 8021BF3C 8EA40084 */  lw        $a0, 0x84($s5)
/* 6A3140 8021BF40 0C0B79E0 */  jal       func_802DE780
/* 6A3144 8021BF44 26100001 */   addiu    $s0, $s0, 1
/* 6A3148 8021BF48 2A02000A */  slti      $v0, $s0, 0xa
/* 6A314C 8021BF4C 1440FFF5 */  bnez      $v0, .L8021BF24
/* 6A3150 8021BF50 0200282D */   daddu    $a1, $s0, $zero
/* 6A3154 8021BF54 26310001 */  addiu     $s1, $s1, 1
/* 6A3158 8021BF58 2A220014 */  slti      $v0, $s1, 0x14
/* 6A315C 8021BF5C 1440FFE4 */  bnez      $v0, .L8021BEF0
/* 6A3160 8021BF60 0000802D */   daddu    $s0, $zero, $zero
/* 6A3164 8021BF64 08086FF3 */  j         .L8021BFCC
/* 6A3168 8021BF68 0000102D */   daddu    $v0, $zero, $zero
.L8021BF6C:
/* 6A316C 8021BF6C 241200FF */  addiu     $s2, $zero, 0xff
/* 6A3170 8021BF70 0240A02D */  daddu     $s4, $s2, $zero
/* 6A3174 8021BF74 0000802D */  daddu     $s0, $zero, $zero
.L8021BF78:
/* 6A3178 8021BF78 0200282D */  daddu     $a1, $s0, $zero
.L8021BF7C:
/* 6A317C 8021BF7C 2406000C */  addiu     $a2, $zero, 0xc
/* 6A3180 8021BF80 0220382D */  daddu     $a3, $s1, $zero
/* 6A3184 8021BF84 AFB20010 */  sw        $s2, 0x10($sp)
/* 6A3188 8021BF88 AFA00014 */  sw        $zero, 0x14($sp)
/* 6A318C 8021BF8C AFB40018 */  sw        $s4, 0x18($sp)
/* 6A3190 8021BF90 AFA0001C */  sw        $zero, 0x1c($sp)
/* 6A3194 8021BF94 8EA40084 */  lw        $a0, 0x84($s5)
/* 6A3198 8021BF98 0C0B79E0 */  jal       func_802DE780
/* 6A319C 8021BF9C 26100001 */   addiu    $s0, $s0, 1
/* 6A31A0 8021BFA0 2A02000A */  slti      $v0, $s0, 0xa
/* 6A31A4 8021BFA4 1440FFF5 */  bnez      $v0, .L8021BF7C
/* 6A31A8 8021BFA8 0200282D */   daddu    $a1, $s0, $zero
/* 6A31AC 8021BFAC 26310001 */  addiu     $s1, $s1, 1
/* 6A31B0 8021BFB0 2A220014 */  slti      $v0, $s1, 0x14
/* 6A31B4 8021BFB4 1440FFF0 */  bnez      $v0, .L8021BF78
/* 6A31B8 8021BFB8 0000802D */   daddu    $s0, $zero, $zero
/* 6A31BC 8021BFBC 0000102D */  daddu     $v0, $zero, $zero
/* 6A31C0 8021BFC0 AE600074 */  sw        $zero, 0x74($s3)
/* 6A31C4 8021BFC4 AE600078 */  sw        $zero, 0x78($s3)
/* 6A31C8 8021BFC8 AE600070 */  sw        $zero, 0x70($s3)
.L8021BFCC:
/* 6A31CC 8021BFCC 8FBF0088 */  lw        $ra, 0x88($sp)
/* 6A31D0 8021BFD0 8FB70084 */  lw        $s7, 0x84($sp)
/* 6A31D4 8021BFD4 8FB60080 */  lw        $s6, 0x80($sp)
/* 6A31D8 8021BFD8 8FB5007C */  lw        $s5, 0x7c($sp)
/* 6A31DC 8021BFDC 8FB40078 */  lw        $s4, 0x78($sp)
/* 6A31E0 8021BFE0 8FB30074 */  lw        $s3, 0x74($sp)
/* 6A31E4 8021BFE4 8FB20070 */  lw        $s2, 0x70($sp)
/* 6A31E8 8021BFE8 8FB1006C */  lw        $s1, 0x6c($sp)
/* 6A31EC 8021BFEC 8FB00068 */  lw        $s0, 0x68($sp)
/* 6A31F0 8021BFF0 D7B800A0 */  ldc1      $f24, 0xa0($sp)
/* 6A31F4 8021BFF4 D7B60098 */  ldc1      $f22, 0x98($sp)
/* 6A31F8 8021BFF8 D7B40090 */  ldc1      $f20, 0x90($sp)
/* 6A31FC 8021BFFC 03E00008 */  jr        $ra
/* 6A3200 8021C000 27BD00A8 */   addiu    $sp, $sp, 0xa8
