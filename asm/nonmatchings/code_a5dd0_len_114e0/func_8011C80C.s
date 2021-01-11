.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8011C80C
/* B2F0C 8011C80C 27BDFF88 */  addiu     $sp, $sp, -0x78
/* B2F10 8011C810 AFB00040 */  sw        $s0, 0x40($sp)
/* B2F14 8011C814 00C0802D */  daddu     $s0, $a2, $zero
/* B2F18 8011C818 AFB10044 */  sw        $s1, 0x44($sp)
/* B2F1C 8011C81C 00E0882D */  daddu     $s1, $a3, $zero
/* B2F20 8011C820 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* B2F24 8011C824 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* B2F28 8011C828 3084FFFF */  andi      $a0, $a0, 0xffff
/* B2F2C 8011C82C AFA5007C */  sw        $a1, 0x7c($sp)
/* B2F30 8011C830 3C05800B */  lui       $a1, %hi(gCameras)
/* B2F34 8011C834 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* B2F38 8011C838 AFBF0064 */  sw        $ra, 0x64($sp)
/* B2F3C 8011C83C AFBE0060 */  sw        $fp, 0x60($sp)
/* B2F40 8011C840 AFB7005C */  sw        $s7, 0x5c($sp)
/* B2F44 8011C844 AFB60058 */  sw        $s6, 0x58($sp)
/* B2F48 8011C848 AFB50054 */  sw        $s5, 0x54($sp)
/* B2F4C 8011C84C AFB40050 */  sw        $s4, 0x50($sp)
/* B2F50 8011C850 AFB3004C */  sw        $s3, 0x4c($sp)
/* B2F54 8011C854 AFB20048 */  sw        $s2, 0x48($sp)
/* B2F58 8011C858 F7B60070 */  sdc1      $f22, 0x70($sp)
/* B2F5C 8011C85C F7B40068 */  sdc1      $f20, 0x68($sp)
/* B2F60 8011C860 00031080 */  sll       $v0, $v1, 2
/* B2F64 8011C864 00431021 */  addu      $v0, $v0, $v1
/* B2F68 8011C868 00021080 */  sll       $v0, $v0, 2
/* B2F6C 8011C86C 00431023 */  subu      $v0, $v0, $v1
/* B2F70 8011C870 000218C0 */  sll       $v1, $v0, 3
/* B2F74 8011C874 00431021 */  addu      $v0, $v0, $v1
/* B2F78 8011C878 000210C0 */  sll       $v0, $v0, 3
/* B2F7C 8011C87C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* B2F80 8011C880 0045F021 */   addu     $fp, $v0, $a1
/* B2F84 8011C884 0C046B4C */  jal       get_model_from_list_index
/* B2F88 8011C888 0040202D */   daddu    $a0, $v0, $zero
/* B2F8C 8011C88C 8FA8007C */  lw        $t0, 0x7c($sp)
/* B2F90 8011C890 0040182D */  daddu     $v1, $v0, $zero
/* B2F94 8011C894 29020010 */  slti      $v0, $t0, 0x10
/* B2F98 8011C898 104001B9 */  beqz      $v0, .L8011CF80
/* B2F9C 8011C89C 27A20028 */   addiu    $v0, $sp, 0x28
/* B2FA0 8011C8A0 3C013F80 */  lui       $at, 0x3f80
/* B2FA4 8011C8A4 4481A000 */  mtc1      $at, $f20
/* B2FA8 8011C8A8 AFA20014 */  sw        $v0, 0x14($sp)
/* B2FAC 8011C8AC 27A2002C */  addiu     $v0, $sp, 0x2c
/* B2FB0 8011C8B0 AFA20018 */  sw        $v0, 0x18($sp)
/* B2FB4 8011C8B4 27A20030 */  addiu     $v0, $sp, 0x30
/* B2FB8 8011C8B8 AFA2001C */  sw        $v0, 0x1c($sp)
/* B2FBC 8011C8BC 27A20034 */  addiu     $v0, $sp, 0x34
/* B2FC0 8011C8C0 AFA20020 */  sw        $v0, 0x20($sp)
/* B2FC4 8011C8C4 E7B40010 */  swc1      $f20, 0x10($sp)
/* B2FC8 8011C8C8 8C650098 */  lw        $a1, 0x98($v1)
/* B2FCC 8011C8CC 8C66009C */  lw        $a2, 0x9c($v1)
/* B2FD0 8011C8D0 8C6700A0 */  lw        $a3, 0xa0($v1)
/* B2FD4 8011C8D4 0C00A588 */  jal       transform_point
/* B2FD8 8011C8D8 27C400D4 */   addiu    $a0, $fp, 0xd4
/* B2FDC 8011C8DC C7A00034 */  lwc1      $f0, 0x34($sp)
/* B2FE0 8011C8E0 44809000 */  mtc1      $zero, $f18
/* B2FE4 8011C8E4 00000000 */  nop       
/* B2FE8 8011C8E8 46120032 */  c.eq.s    $f0, $f18
/* B2FEC 8011C8EC 00000000 */  nop       
/* B2FF0 8011C8F0 45000004 */  bc1f      .L8011C904
/* B2FF4 8011C8F4 24020001 */   addiu    $v0, $zero, 1
/* B2FF8 8011C8F8 E6120000 */  swc1      $f18, ($s0)
/* B2FFC 8011C8FC 080473E1 */  j         .L8011CF84
/* B3000 8011C900 E6320000 */   swc1     $f18, ($s1)
.L8011C904:
/* B3004 8011C904 C7AC0030 */  lwc1      $f12, 0x30($sp)
/* B3008 8011C908 4600A383 */  div.s     $f14, $f20, $f0
/* B300C 8011C90C 460E6302 */  mul.s     $f12, $f12, $f14
/* B3010 8011C910 00000000 */  nop       
/* B3014 8011C914 46146080 */  add.s     $f2, $f12, $f20
/* B3018 8011C918 3C013FE0 */  lui       $at, 0x3fe0
/* B301C 8011C91C 44814800 */  mtc1      $at, $f9
/* B3020 8011C920 44804000 */  mtc1      $zero, $f8
/* B3024 8011C924 460010A1 */  cvt.d.s   $f2, $f2
/* B3028 8011C928 46281082 */  mul.d     $f2, $f2, $f8
/* B302C 8011C92C 00000000 */  nop       
/* B3030 8011C930 C7B00028 */  lwc1      $f16, 0x28($sp)
/* B3034 8011C934 460E8402 */  mul.s     $f16, $f16, $f14
/* B3038 8011C938 00000000 */  nop       
/* B303C 8011C93C 87C2000A */  lh        $v0, 0xa($fp)
/* B3040 8011C940 44820000 */  mtc1      $v0, $f0
/* B3044 8011C944 00000000 */  nop       
/* B3048 8011C948 46800020 */  cvt.s.w   $f0, $f0
/* B304C 8011C94C 46008102 */  mul.s     $f4, $f16, $f0
/* B3050 8011C950 00000000 */  nop       
/* B3054 8011C954 46002100 */  add.s     $f4, $f4, $f0
/* B3058 8011C958 46002121 */  cvt.d.s   $f4, $f4
/* B305C 8011C95C 46282102 */  mul.d     $f4, $f4, $f8
/* B3060 8011C960 00000000 */  nop       
/* B3064 8011C964 C7A6002C */  lwc1      $f6, 0x2c($sp)
/* B3068 8011C968 46007007 */  neg.s     $f0, $f14
/* B306C 8011C96C 46003182 */  mul.s     $f6, $f6, $f0
/* B3070 8011C970 00000000 */  nop       
/* B3074 8011C974 87C2000C */  lh        $v0, 0xc($fp)
/* B3078 8011C978 44825000 */  mtc1      $v0, $f10
/* B307C 8011C97C 00000000 */  nop       
/* B3080 8011C980 468052A0 */  cvt.s.w   $f10, $f10
/* B3084 8011C984 460A3002 */  mul.s     $f0, $f6, $f10
/* B3088 8011C988 00000000 */  nop       
/* B308C 8011C98C E7AE0034 */  swc1      $f14, 0x34($sp)
/* B3090 8011C990 E7B00028 */  swc1      $f16, 0x28($sp)
/* B3094 8011C994 E7AC0030 */  swc1      $f12, 0x30($sp)
/* B3098 8011C998 460A0000 */  add.s     $f0, $f0, $f10
/* B309C 8011C99C E7A6002C */  swc1      $f6, 0x2c($sp)
/* B30A0 8011C9A0 462010A0 */  cvt.s.d   $f2, $f2
/* B30A4 8011C9A4 46000021 */  cvt.d.s   $f0, $f0
/* B30A8 8011C9A8 46280002 */  mul.d     $f0, $f0, $f8
/* B30AC 8011C9AC 00000000 */  nop       
/* B30B0 8011C9B0 E7A20030 */  swc1      $f2, 0x30($sp)
/* B30B4 8011C9B4 87C2000E */  lh        $v0, 0xe($fp)
/* B30B8 8011C9B8 44821000 */  mtc1      $v0, $f2
/* B30BC 8011C9BC 00000000 */  nop       
/* B30C0 8011C9C0 468010A0 */  cvt.s.w   $f2, $f2
/* B30C4 8011C9C4 46202120 */  cvt.s.d   $f4, $f4
/* B30C8 8011C9C8 E7A40028 */  swc1      $f4, 0x28($sp)
/* B30CC 8011C9CC 87C20010 */  lh        $v0, 0x10($fp)
/* B30D0 8011C9D0 46022100 */  add.s     $f4, $f4, $f2
/* B30D4 8011C9D4 44821000 */  mtc1      $v0, $f2
/* B30D8 8011C9D8 00000000 */  nop       
/* B30DC 8011C9DC 468010A0 */  cvt.s.w   $f2, $f2
/* B30E0 8011C9E0 4600258D */  trunc.w.s $f22, $f4
/* B30E4 8011C9E4 4402B000 */  mfc1      $v0, $f22
/* B30E8 8011C9E8 E7A40028 */  swc1      $f4, 0x28($sp)
/* B30EC 8011C9EC 46200020 */  cvt.s.d   $f0, $f0
/* B30F0 8011C9F0 46020080 */  add.s     $f2, $f0, $f2
/* B30F4 8011C9F4 E7A0002C */  swc1      $f0, 0x2c($sp)
/* B30F8 8011C9F8 44820000 */  mtc1      $v0, $f0
/* B30FC 8011C9FC 00000000 */  nop       
/* B3100 8011CA00 46800020 */  cvt.s.w   $f0, $f0
/* B3104 8011CA04 E7A2002C */  swc1      $f2, 0x2c($sp)
/* B3108 8011CA08 E6000000 */  swc1      $f0, ($s0)
/* B310C 8011CA0C C7A0002C */  lwc1      $f0, 0x2c($sp)
/* B3110 8011CA10 4600058D */  trunc.w.s $f22, $f0
/* B3114 8011CA14 4402B000 */  mfc1      $v0, $f22
/* B3118 8011CA18 00000000 */  nop       
/* B311C 8011CA1C 44820000 */  mtc1      $v0, $f0
/* B3120 8011CA20 00000000 */  nop       
/* B3124 8011CA24 46800020 */  cvt.s.w   $f0, $f0
/* B3128 8011CA28 E6200000 */  swc1      $f0, ($s1)
/* B312C 8011CA2C 8FA8007C */  lw        $t0, 0x7c($sp)
/* B3130 8011CA30 05010008 */  bgez      $t0, .L8011CA54
/* B3134 8011CA34 00000000 */   nop      
/* B3138 8011CA38 C7A00030 */  lwc1      $f0, 0x30($sp)
/* B313C 8011CA3C 4600903C */  c.lt.s    $f18, $f0
/* B3140 8011CA40 00000000 */  nop       
/* B3144 8011CA44 4501014F */  bc1t      .L8011CF84
/* B3148 8011CA48 0000102D */   daddu    $v0, $zero, $zero
/* B314C 8011CA4C 080473E1 */  j         .L8011CF84
/* B3150 8011CA50 24020001 */   addiu    $v0, $zero, 1
.L8011CA54:
/* B3154 8011CA54 C7A40028 */  lwc1      $f4, 0x28($sp)
/* B3158 8011CA58 4604903E */  c.le.s    $f18, $f4
/* B315C 8011CA5C 00000000 */  nop       
/* B3160 8011CA60 45000140 */  bc1f      .L8011CF64
/* B3164 8011CA64 00000000 */   nop      
/* B3168 8011CA68 C7A2002C */  lwc1      $f2, 0x2c($sp)
/* B316C 8011CA6C 4602903E */  c.le.s    $f18, $f2
/* B3170 8011CA70 00000000 */  nop       
/* B3174 8011CA74 4500013B */  bc1f      .L8011CF64
/* B3178 8011CA78 00000000 */   nop      
/* B317C 8011CA7C 3C0143A0 */  lui       $at, 0x43a0
/* B3180 8011CA80 44810000 */  mtc1      $at, $f0
/* B3184 8011CA84 00000000 */  nop       
/* B3188 8011CA88 4600203C */  c.lt.s    $f4, $f0
/* B318C 8011CA8C 00000000 */  nop       
/* B3190 8011CA90 45000134 */  bc1f      .L8011CF64
/* B3194 8011CA94 00000000 */   nop      
/* B3198 8011CA98 3C014370 */  lui       $at, 0x4370
/* B319C 8011CA9C 44810000 */  mtc1      $at, $f0
/* B31A0 8011CAA0 00000000 */  nop       
/* B31A4 8011CAA4 4600103C */  c.lt.s    $f2, $f0
/* B31A8 8011CAA8 00000000 */  nop       
/* B31AC 8011CAAC 4500012D */  bc1f      .L8011CF64
/* B31B0 8011CAB0 3C05FD10 */   lui      $a1, 0xfd10
/* B31B4 8011CAB4 3C11800A */  lui       $s1, %hi(gMasterGfxPos)
/* B31B8 8011CAB8 2631A66C */  addiu     $s1, $s1, %lo(gMasterGfxPos)
/* B31BC 8011CABC 34A5013F */  ori       $a1, $a1, 0x13f
/* B31C0 8011CAC0 4600158D */  trunc.w.s $f22, $f2
/* B31C4 8011CAC4 4402B000 */  mfc1      $v0, $f22
/* B31C8 8011CAC8 00000000 */  nop       
/* B31CC 8011CACC 00022080 */  sll       $a0, $v0, 2
/* B31D0 8011CAD0 00822021 */  addu      $a0, $a0, $v0
/* B31D4 8011CAD4 000421C0 */  sll       $a0, $a0, 7
/* B31D8 8011CAD8 3C13E700 */  lui       $s3, 0xe700
/* B31DC 8011CADC 8E320000 */  lw        $s2, ($s1)
/* B31E0 8011CAE0 3C02800A */  lui       $v0, %hi(nuGfxZBuffer)
/* B31E4 8011CAE4 8C42A5DC */  lw        $v0, %lo(nuGfxZBuffer)($v0)
/* B31E8 8011CAE8 0240182D */  daddu     $v1, $s2, $zero
/* B31EC 8011CAEC 26520008 */  addiu     $s2, $s2, 8
/* B31F0 8011CAF0 00442021 */  addu      $a0, $v0, $a0
/* B31F4 8011CAF4 26420008 */  addiu     $v0, $s2, 8
/* B31F8 8011CAF8 AE320000 */  sw        $s2, ($s1)
/* B31FC 8011CAFC AC730000 */  sw        $s3, ($v1)
/* B3200 8011CB00 AC600004 */  sw        $zero, 4($v1)
/* B3204 8011CB04 AE220000 */  sw        $v0, ($s1)
/* B3208 8011CB08 0C0187A4 */  jal       osVirtualToPhysical
/* B320C 8011CB0C AE450000 */   sw       $a1, ($s2)
/* B3210 8011CB10 3C06F510 */  lui       $a2, 0xf510
/* B3214 8011CB14 34C60200 */  ori       $a2, $a2, 0x200
/* B3218 8011CB18 3C030700 */  lui       $v1, 0x700
/* B321C 8011CB1C 34630090 */  ori       $v1, $v1, 0x90
/* B3220 8011CB20 3C18FF10 */  lui       $t8, 0xff10
/* B3224 8011CB24 3718013F */  ori       $t8, $t8, 0x13f
/* B3228 8011CB28 3C07E300 */  lui       $a3, 0xe300
/* B322C 8011CB2C 34E70A01 */  ori       $a3, $a3, 0xa01
/* B3230 8011CB30 3C0AE200 */  lui       $t2, 0xe200
/* B3234 8011CB34 354A001C */  ori       $t2, $t2, 0x1c
/* B3238 8011CB38 3C080F0A */  lui       $t0, 0xf0a
/* B323C 8011CB3C 35084000 */  ori       $t0, $t0, 0x4000
/* B3240 8011CB40 3C0BFCFF */  lui       $t3, 0xfcff
/* B3244 8011CB44 356BFFFF */  ori       $t3, $t3, 0xffff
/* B3248 8011CB48 3C09FFFC */  lui       $t1, 0xfffc
/* B324C 8011CB4C 3529F279 */  ori       $t1, $t1, 0xf279
/* B3250 8011CB50 3C0CE300 */  lui       $t4, 0xe300
/* B3254 8011CB54 358C1201 */  ori       $t4, $t4, 0x1201
/* B3258 8011CB58 3C0DE300 */  lui       $t5, 0xe300
/* B325C 8011CB5C 35AD0C00 */  ori       $t5, $t5, 0xc00
/* B3260 8011CB60 3C0ED700 */  lui       $t6, 0xd700
/* B3264 8011CB64 35CE0002 */  ori       $t6, $t6, 2
/* B3268 8011CB68 3C0FE300 */  lui       $t7, 0xe300
/* B326C 8011CB6C 35EF1001 */  ori       $t7, $t7, 0x1001
/* B3270 8011CB70 3C15E300 */  lui       $s5, 0xe300
/* B3274 8011CB74 36B50D01 */  ori       $s5, $s5, 0xd01
/* B3278 8011CB78 3C16E300 */  lui       $s6, 0xe300
/* B327C 8011CB7C 36D60F00 */  ori       $s6, $s6, 0xf00
/* B3280 8011CB80 3C17E401 */  lui       $s7, 0xe401
/* B3284 8011CB84 36F70004 */  ori       $s7, $s7, 4
/* B3288 8011CB88 3C190400 */  lui       $t9, 0x400
/* B328C 8011CB8C AFA80038 */  sw        $t0, 0x38($sp)
/* B3290 8011CB90 8E300000 */  lw        $s0, ($s1)
/* B3294 8011CB94 3C148015 */  lui       $s4, %hi(D_80153380)
/* B3298 8011CB98 26943380 */  addiu     $s4, $s4, %lo(D_80153380)
/* B329C 8011CB9C AE420004 */  sw        $v0, 4($s2)
/* B32A0 8011CBA0 3C12ED00 */  lui       $s2, 0xed00
/* B32A4 8011CBA4 0200102D */  daddu     $v0, $s0, $zero
/* B32A8 8011CBA8 26100008 */  addiu     $s0, $s0, 8
/* B32AC 8011CBAC AE300000 */  sw        $s0, ($s1)
/* B32B0 8011CBB0 AC460000 */  sw        $a2, ($v0)
/* B32B4 8011CBB4 AC430004 */  sw        $v1, 4($v0)
/* B32B8 8011CBB8 26020008 */  addiu     $v0, $s0, 8
/* B32BC 8011CBBC AE220000 */  sw        $v0, ($s1)
/* B32C0 8011CBC0 3C02E600 */  lui       $v0, 0xe600
/* B32C4 8011CBC4 AE020000 */  sw        $v0, ($s0)
/* B32C8 8011CBC8 AE000004 */  sw        $zero, 4($s0)
/* B32CC 8011CBCC C7A00028 */  lwc1      $f0, 0x28($sp)
/* B32D0 8011CBD0 26020010 */  addiu     $v0, $s0, 0x10
/* B32D4 8011CBD4 AE220000 */  sw        $v0, ($s1)
/* B32D8 8011CBD8 3C02F400 */  lui       $v0, 0xf400
/* B32DC 8011CBDC 4600058D */  trunc.w.s $f22, $f0
/* B32E0 8011CBE0 4405B000 */  mfc1      $a1, $f22
/* B32E4 8011CBE4 00000000 */  nop       
/* B32E8 8011CBE8 00052080 */  sll       $a0, $a1, 2
/* B32EC 8011CBEC 30840FFF */  andi      $a0, $a0, 0xfff
/* B32F0 8011CBF0 00042300 */  sll       $a0, $a0, 0xc
/* B32F4 8011CBF4 00821025 */  or        $v0, $a0, $v0
/* B32F8 8011CBF8 24A30003 */  addiu     $v1, $a1, 3
/* B32FC 8011CBFC 00031880 */  sll       $v1, $v1, 2
/* B3300 8011CC00 30630FFF */  andi      $v1, $v1, 0xfff
/* B3304 8011CC04 00031B00 */  sll       $v1, $v1, 0xc
/* B3308 8011CC08 AE020008 */  sw        $v0, 8($s0)
/* B330C 8011CC0C 3C020700 */  lui       $v0, 0x700
/* B3310 8011CC10 00621025 */  or        $v0, $v1, $v0
/* B3314 8011CC14 AE02000C */  sw        $v0, 0xc($s0)
/* B3318 8011CC18 26020018 */  addiu     $v0, $s0, 0x18
/* B331C 8011CC1C AE220000 */  sw        $v0, ($s1)
/* B3320 8011CC20 26020020 */  addiu     $v0, $s0, 0x20
/* B3324 8011CC24 AE130010 */  sw        $s3, 0x10($s0)
/* B3328 8011CC28 AE000014 */  sw        $zero, 0x14($s0)
/* B332C 8011CC2C AE220000 */  sw        $v0, ($s1)
/* B3330 8011CC30 24020090 */  addiu     $v0, $zero, 0x90
/* B3334 8011CC34 AE02001C */  sw        $v0, 0x1c($s0)
/* B3338 8011CC38 26020028 */  addiu     $v0, $s0, 0x28
/* B333C 8011CC3C AE060018 */  sw        $a2, 0x18($s0)
/* B3340 8011CC40 AE220000 */  sw        $v0, ($s1)
/* B3344 8011CC44 3C02F200 */  lui       $v0, 0xf200
/* B3348 8011CC48 00822025 */  or        $a0, $a0, $v0
/* B334C 8011CC4C 26020030 */  addiu     $v0, $s0, 0x30
/* B3350 8011CC50 AE040020 */  sw        $a0, 0x20($s0)
/* B3354 8011CC54 AE030024 */  sw        $v1, 0x24($s0)
/* B3358 8011CC58 AE220000 */  sw        $v0, ($s1)
/* B335C 8011CC5C 26020038 */  addiu     $v0, $s0, 0x38
/* B3360 8011CC60 AE130028 */  sw        $s3, 0x28($s0)
/* B3364 8011CC64 AE00002C */  sw        $zero, 0x2c($s0)
/* B3368 8011CC68 AE220000 */  sw        $v0, ($s1)
/* B336C 8011CC6C 26020040 */  addiu     $v0, $s0, 0x40
/* B3370 8011CC70 AE180030 */  sw        $t8, 0x30($s0)
/* B3374 8011CC74 AE140034 */  sw        $s4, 0x34($s0)
/* B3378 8011CC78 AE220000 */  sw        $v0, ($s1)
/* B337C 8011CC7C 26020048 */  addiu     $v0, $s0, 0x48
/* B3380 8011CC80 AE130038 */  sw        $s3, 0x38($s0)
/* B3384 8011CC84 AE00003C */  sw        $zero, 0x3c($s0)
/* B3388 8011CC88 AE220000 */  sw        $v0, ($s1)
/* B338C 8011CC8C 26020050 */  addiu     $v0, $s0, 0x50
/* B3390 8011CC90 AE070040 */  sw        $a3, 0x40($s0)
/* B3394 8011CC94 AE000044 */  sw        $zero, 0x44($s0)
/* B3398 8011CC98 AE220000 */  sw        $v0, ($s1)
/* B339C 8011CC9C AE0A0048 */  sw        $t2, 0x48($s0)
/* B33A0 8011CCA0 8FA80038 */  lw        $t0, 0x38($sp)
/* B33A4 8011CCA4 26020058 */  addiu     $v0, $s0, 0x58
/* B33A8 8011CCA8 AE08004C */  sw        $t0, 0x4c($s0)
/* B33AC 8011CCAC AE220000 */  sw        $v0, ($s1)
/* B33B0 8011CCB0 26020060 */  addiu     $v0, $s0, 0x60
/* B33B4 8011CCB4 AE0B0050 */  sw        $t3, 0x50($s0)
/* B33B8 8011CCB8 AE090054 */  sw        $t1, 0x54($s0)
/* B33BC 8011CCBC AE220000 */  sw        $v0, ($s1)
/* B33C0 8011CCC0 26020068 */  addiu     $v0, $s0, 0x68
/* B33C4 8011CCC4 AE0C0058 */  sw        $t4, 0x58($s0)
/* B33C8 8011CCC8 AE00005C */  sw        $zero, 0x5c($s0)
/* B33CC 8011CCCC AE220000 */  sw        $v0, ($s1)
/* B33D0 8011CCD0 26020070 */  addiu     $v0, $s0, 0x70
/* B33D4 8011CCD4 AE0D0060 */  sw        $t5, 0x60($s0)
/* B33D8 8011CCD8 AE000064 */  sw        $zero, 0x64($s0)
/* B33DC 8011CCDC AE220000 */  sw        $v0, ($s1)
/* B33E0 8011CCE0 2402FFFF */  addiu     $v0, $zero, -1
/* B33E4 8011CCE4 AE02006C */  sw        $v0, 0x6c($s0)
/* B33E8 8011CCE8 26020078 */  addiu     $v0, $s0, 0x78
/* B33EC 8011CCEC AE0E0068 */  sw        $t6, 0x68($s0)
/* B33F0 8011CCF0 AE220000 */  sw        $v0, ($s1)
/* B33F4 8011CCF4 26020080 */  addiu     $v0, $s0, 0x80
/* B33F8 8011CCF8 AE0F0070 */  sw        $t7, 0x70($s0)
/* B33FC 8011CCFC AE000074 */  sw        $zero, 0x74($s0)
/* B3400 8011CD00 AE220000 */  sw        $v0, ($s1)
/* B3404 8011CD04 26020088 */  addiu     $v0, $s0, 0x88
/* B3408 8011CD08 AE150078 */  sw        $s5, 0x78($s0)
/* B340C 8011CD0C AE00007C */  sw        $zero, 0x7c($s0)
/* B3410 8011CD10 AE220000 */  sw        $v0, ($s1)
/* B3414 8011CD14 26020090 */  addiu     $v0, $s0, 0x90
/* B3418 8011CD18 AE160080 */  sw        $s6, 0x80($s0)
/* B341C 8011CD1C AE000084 */  sw        $zero, 0x84($s0)
/* B3420 8011CD20 AE220000 */  sw        $v0, ($s1)
/* B3424 8011CD24 26020098 */  addiu     $v0, $s0, 0x98
/* B3428 8011CD28 AE220000 */  sw        $v0, ($s1)
/* B342C 8011CD2C AE170090 */  sw        $s7, 0x90($s0)
/* B3430 8011CD30 8FA8007C */  lw        $t0, 0x7c($sp)
/* B3434 8011CD34 3C014080 */  lui       $at, 0x4080
/* B3438 8011CD38 4481A000 */  mtc1      $at, $f20
/* B343C 8011CD3C 00081080 */  sll       $v0, $t0, 2
/* B3440 8011CD40 30420FFF */  andi      $v0, $v0, 0xfff
/* B3444 8011CD44 00021300 */  sll       $v0, $v0, 0xc
/* B3448 8011CD48 AE020094 */  sw        $v0, 0x94($s0)
/* B344C 8011CD4C 260200A0 */  addiu     $v0, $s0, 0xa0
/* B3450 8011CD50 AE220000 */  sw        $v0, ($s1)
/* B3454 8011CD54 3C02E100 */  lui       $v0, 0xe100
/* B3458 8011CD58 AE020098 */  sw        $v0, 0x98($s0)
/* B345C 8011CD5C C7A0007C */  lwc1      $f0, 0x7c($sp)
/* B3460 8011CD60 46800020 */  cvt.s.w   $f0, $f0
/* B3464 8011CD64 46140002 */  mul.s     $f0, $f0, $f20
/* B3468 8011CD68 00000000 */  nop       
/* B346C 8011CD6C 00052D40 */  sll       $a1, $a1, 0x15
/* B3470 8011CD70 260200A8 */  addiu     $v0, $s0, 0xa8
/* B3474 8011CD74 AE05009C */  sw        $a1, 0x9c($s0)
/* B3478 8011CD78 AE220000 */  sw        $v0, ($s1)
/* B347C 8011CD7C 4600058D */  trunc.w.s $f22, $f0
/* B3480 8011CD80 4402B000 */  mfc1      $v0, $f22
/* B3484 8011CD84 8FA8007C */  lw        $t0, 0x7c($sp)
/* B3488 8011CD88 37390400 */  ori       $t9, $t9, 0x400
/* B348C 8011CD8C 25030001 */  addiu     $v1, $t0, 1
/* B3490 8011CD90 44830000 */  mtc1      $v1, $f0
/* B3494 8011CD94 00000000 */  nop       
/* B3498 8011CD98 46800020 */  cvt.s.w   $f0, $f0
/* B349C 8011CD9C 46140002 */  mul.s     $f0, $f0, $f20
/* B34A0 8011CDA0 00000000 */  nop       
/* B34A4 8011CDA4 30420FFF */  andi      $v0, $v0, 0xfff
/* B34A8 8011CDA8 00021300 */  sll       $v0, $v0, 0xc
/* B34AC 8011CDAC 00521025 */  or        $v0, $v0, $s2
/* B34B0 8011CDB0 AE020088 */  sw        $v0, 0x88($s0)
/* B34B4 8011CDB4 4600058D */  trunc.w.s $f22, $f0
/* B34B8 8011CDB8 4402B000 */  mfc1      $v0, $f22
/* B34BC 8011CDBC 00000000 */  nop       
/* B34C0 8011CDC0 30420FFF */  andi      $v0, $v0, 0xfff
/* B34C4 8011CDC4 00021300 */  sll       $v0, $v0, 0xc
/* B34C8 8011CDC8 34420004 */  ori       $v0, $v0, 4
/* B34CC 8011CDCC AE02008C */  sw        $v0, 0x8c($s0)
/* B34D0 8011CDD0 3C02F100 */  lui       $v0, 0xf100
/* B34D4 8011CDD4 AE0200A0 */  sw        $v0, 0xa0($s0)
/* B34D8 8011CDD8 3C04800A */  lui       $a0, %hi(D_8009A64C)
/* B34DC 8011CDDC 8C84A64C */  lw        $a0, %lo(D_8009A64C)($a0)
/* B34E0 8011CDE0 260200B0 */  addiu     $v0, $s0, 0xb0
/* B34E4 8011CDE4 AE1900A4 */  sw        $t9, 0xa4($s0)
/* B34E8 8011CDE8 AE220000 */  sw        $v0, ($s1)
/* B34EC 8011CDEC 260200B8 */  addiu     $v0, $s0, 0xb8
/* B34F0 8011CDF0 AE1300A8 */  sw        $s3, 0xa8($s0)
/* B34F4 8011CDF4 AE0000AC */  sw        $zero, 0xac($s0)
/* B34F8 8011CDF8 AE220000 */  sw        $v0, ($s1)
/* B34FC 8011CDFC 0C0187A4 */  jal       osVirtualToPhysical
/* B3500 8011CE00 AE1800B0 */   sw       $t8, 0xb0($s0)
/* B3504 8011CE04 8E240000 */  lw        $a0, ($s1)
/* B3508 8011CE08 AE0200B4 */  sw        $v0, 0xb4($s0)
/* B350C 8011CE0C 0080102D */  daddu     $v0, $a0, $zero
/* B3510 8011CE10 AC530000 */  sw        $s3, ($v0)
/* B3514 8011CE14 AC400004 */  sw        $zero, 4($v0)
/* B3518 8011CE18 87C2000E */  lh        $v0, 0xe($fp)
/* B351C 8011CE1C 44820000 */  mtc1      $v0, $f0
/* B3520 8011CE20 00000000 */  nop       
/* B3524 8011CE24 46800020 */  cvt.s.w   $f0, $f0
/* B3528 8011CE28 46140002 */  mul.s     $f0, $f0, $f20
/* B352C 8011CE2C 00000000 */  nop       
/* B3530 8011CE30 87C20010 */  lh        $v0, 0x10($fp)
/* B3534 8011CE34 44821000 */  mtc1      $v0, $f2
/* B3538 8011CE38 00000000 */  nop       
/* B353C 8011CE3C 468010A0 */  cvt.s.w   $f2, $f2
/* B3540 8011CE40 46141082 */  mul.s     $f2, $f2, $f20
/* B3544 8011CE44 00000000 */  nop       
/* B3548 8011CE48 24840008 */  addiu     $a0, $a0, 8
/* B354C 8011CE4C 4600058D */  trunc.w.s $f22, $f0
/* B3550 8011CE50 4403B000 */  mfc1      $v1, $f22
/* B3554 8011CE54 00000000 */  nop       
/* B3558 8011CE58 30630FFF */  andi      $v1, $v1, 0xfff
/* B355C 8011CE5C 00031B00 */  sll       $v1, $v1, 0xc
/* B3560 8011CE60 4600158D */  trunc.w.s $f22, $f2
/* B3564 8011CE64 4402B000 */  mfc1      $v0, $f22
/* B3568 8011CE68 00000000 */  nop       
/* B356C 8011CE6C 30420FFF */  andi      $v0, $v0, 0xfff
/* B3570 8011CE70 00521025 */  or        $v0, $v0, $s2
/* B3574 8011CE74 00621825 */  or        $v1, $v1, $v0
/* B3578 8011CE78 AC830000 */  sw        $v1, ($a0)
/* B357C 8011CE7C 87C2000E */  lh        $v0, 0xe($fp)
/* B3580 8011CE80 87C3000A */  lh        $v1, 0xa($fp)
/* B3584 8011CE84 00431021 */  addu      $v0, $v0, $v1
/* B3588 8011CE88 44821000 */  mtc1      $v0, $f2
/* B358C 8011CE8C 00000000 */  nop       
/* B3590 8011CE90 468010A0 */  cvt.s.w   $f2, $f2
/* B3594 8011CE94 46141082 */  mul.s     $f2, $f2, $f20
/* B3598 8011CE98 00000000 */  nop       
/* B359C 8011CE9C 87C20010 */  lh        $v0, 0x10($fp)
/* B35A0 8011CEA0 87C3000C */  lh        $v1, 0xc($fp)
/* B35A4 8011CEA4 00431021 */  addu      $v0, $v0, $v1
/* B35A8 8011CEA8 44820000 */  mtc1      $v0, $f0
/* B35AC 8011CEAC 00000000 */  nop       
/* B35B0 8011CEB0 46800020 */  cvt.s.w   $f0, $f0
/* B35B4 8011CEB4 46140002 */  mul.s     $f0, $f0, $f20
/* B35B8 8011CEB8 00000000 */  nop       
/* B35BC 8011CEBC AE240000 */  sw        $a0, ($s1)
/* B35C0 8011CEC0 4600158D */  trunc.w.s $f22, $f2
/* B35C4 8011CEC4 4402B000 */  mfc1      $v0, $f22
/* B35C8 8011CEC8 00000000 */  nop       
/* B35CC 8011CECC 30420FFF */  andi      $v0, $v0, 0xfff
/* B35D0 8011CED0 00021300 */  sll       $v0, $v0, 0xc
/* B35D4 8011CED4 4600058D */  trunc.w.s $f22, $f0
/* B35D8 8011CED8 4403B000 */  mfc1      $v1, $f22
/* B35DC 8011CEDC 00000000 */  nop       
/* B35E0 8011CEE0 30630FFF */  andi      $v1, $v1, 0xfff
/* B35E4 8011CEE4 00431025 */  or        $v0, $v0, $v1
/* B35E8 8011CEE8 AC820004 */  sw        $v0, 4($a0)
/* B35EC 8011CEEC 8FA8007C */  lw        $t0, 0x7c($sp)
/* B35F0 8011CEF0 3C0146FF */  lui       $at, 0x46ff
/* B35F4 8011CEF4 34218000 */  ori       $at, $at, 0x8000
/* B35F8 8011CEF8 44810000 */  mtc1      $at, $f0
/* B35FC 8011CEFC 00081040 */  sll       $v0, $t0, 1
/* B3600 8011CF00 00541021 */  addu      $v0, $v0, $s4
/* B3604 8011CF04 94420000 */  lhu       $v0, ($v0)
/* B3608 8011CF08 24840008 */  addiu     $a0, $a0, 8
/* B360C 8011CF0C AE240000 */  sw        $a0, ($s1)
/* B3610 8011CF10 3C048015 */  lui       $a0, %hi(D_8014B7A8)
/* B3614 8011CF14 2484B7A8 */  addiu     $a0, $a0, %lo(D_8014B7A8)
/* B3618 8011CF18 C7A20030 */  lwc1      $f2, 0x30($sp)
/* B361C 8011CF1C 00021B42 */  srl       $v1, $v0, 0xd
/* B3620 8011CF20 30421FFF */  andi      $v0, $v0, 0x1fff
/* B3624 8011CF24 00021082 */  srl       $v0, $v0, 2
/* B3628 8011CF28 000318C0 */  sll       $v1, $v1, 3
/* B362C 8011CF2C 00641821 */  addu      $v1, $v1, $a0
/* B3630 8011CF30 46001082 */  mul.s     $f2, $f2, $f0
/* B3634 8011CF34 00000000 */  nop       
/* B3638 8011CF38 8C640000 */  lw        $a0, ($v1)
/* B363C 8011CF3C 8C630004 */  lw        $v1, 4($v1)
/* B3640 8011CF40 00821004 */  sllv      $v0, $v0, $a0
/* B3644 8011CF44 00431021 */  addu      $v0, $v0, $v1
/* B3648 8011CF48 000210C2 */  srl       $v0, $v0, 3
/* B364C 8011CF4C 4600158D */  trunc.w.s $f22, $f2
/* B3650 8011CF50 4403B000 */  mfc1      $v1, $f22
/* B3654 8011CF54 00000000 */  nop       
/* B3658 8011CF58 0043102B */  sltu      $v0, $v0, $v1
/* B365C 8011CF5C 14400009 */  bnez      $v0, .L8011CF84
/* B3660 8011CF60 0000102D */   daddu    $v0, $zero, $zero
.L8011CF64:
/* B3664 8011CF64 C7A20030 */  lwc1      $f2, 0x30($sp)
/* B3668 8011CF68 44800000 */  mtc1      $zero, $f0
/* B366C 8011CF6C 00000000 */  nop       
/* B3670 8011CF70 4602003C */  c.lt.s    $f0, $f2
/* B3674 8011CF74 00000000 */  nop       
/* B3678 8011CF78 45010002 */  bc1t      .L8011CF84
/* B367C 8011CF7C 24020001 */   addiu    $v0, $zero, 1
.L8011CF80:
/* B3680 8011CF80 0000102D */  daddu     $v0, $zero, $zero
.L8011CF84:
/* B3684 8011CF84 8FBF0064 */  lw        $ra, 0x64($sp)
/* B3688 8011CF88 8FBE0060 */  lw        $fp, 0x60($sp)
/* B368C 8011CF8C 8FB7005C */  lw        $s7, 0x5c($sp)
/* B3690 8011CF90 8FB60058 */  lw        $s6, 0x58($sp)
/* B3694 8011CF94 8FB50054 */  lw        $s5, 0x54($sp)
/* B3698 8011CF98 8FB40050 */  lw        $s4, 0x50($sp)
/* B369C 8011CF9C 8FB3004C */  lw        $s3, 0x4c($sp)
/* B36A0 8011CFA0 8FB20048 */  lw        $s2, 0x48($sp)
/* B36A4 8011CFA4 8FB10044 */  lw        $s1, 0x44($sp)
/* B36A8 8011CFA8 8FB00040 */  lw        $s0, 0x40($sp)
/* B36AC 8011CFAC D7B60070 */  ldc1      $f22, 0x70($sp)
/* B36B0 8011CFB0 D7B40068 */  ldc1      $f20, 0x68($sp)
/* B36B4 8011CFB4 03E00008 */  jr        $ra
/* B36B8 8011CFB8 27BD0078 */   addiu    $sp, $sp, 0x78
