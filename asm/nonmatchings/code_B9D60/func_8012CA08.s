.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8012CA08
/* C3108 8012CA08 0080502D */  daddu     $t2, $a0, $zero
/* C310C 8012CA0C 00A0582D */  daddu     $t3, $a1, $zero
/* C3110 8012CA10 3C09800A */  lui       $t1, %hi(D_8009A66C)
/* C3114 8012CA14 2529A66C */  addiu     $t1, $t1, %lo(D_8009A66C)
/* C3118 8012CA18 3C02E700 */  lui       $v0, 0xe700
/* C311C 8012CA1C 8D280000 */  lw        $t0, ($t1)
/* C3120 8012CA20 97AF0012 */  lhu       $t7, 0x12($sp)
/* C3124 8012CA24 97B80016 */  lhu       $t8, 0x16($sp)
/* C3128 8012CA28 97AD001A */  lhu       $t5, 0x1a($sp)
/* C312C 8012CA2C 97AE001E */  lhu       $t6, 0x1e($sp)
/* C3130 8012CA30 0100182D */  daddu     $v1, $t0, $zero
/* C3134 8012CA34 25080008 */  addiu     $t0, $t0, 8
/* C3138 8012CA38 AD280000 */  sw        $t0, ($t1)
/* C313C 8012CA3C AC620000 */  sw        $v0, ($v1)
/* C3140 8012CA40 AC600004 */  sw        $zero, 4($v1)
/* C3144 8012CA44 30E300FF */  andi      $v1, $a3, 0xff
/* C3148 8012CA48 240200FF */  addiu     $v0, $zero, 0xff
/* C314C 8012CA4C 1462000A */  bne       $v1, $v0, .L8012CA78
/* C3150 8012CA50 00C0602D */   daddu    $t4, $a2, $zero
/* C3154 8012CA54 3C04FCFF */  lui       $a0, 0xfcff
/* C3158 8012CA58 3484FFFF */  ori       $a0, $a0, 0xffff
/* C315C 8012CA5C 3C03FFFD */  lui       $v1, 0xfffd
/* C3160 8012CA60 3463FCFE */  ori       $v1, $v1, 0xfcfe
/* C3164 8012CA64 25020008 */  addiu     $v0, $t0, 8
/* C3168 8012CA68 AD220000 */  sw        $v0, ($t1)
/* C316C 8012CA6C AD040000 */  sw        $a0, ($t0)
/* C3170 8012CA70 0804B2AE */  j         .L8012CAB8
/* C3174 8012CA74 AD030004 */   sw       $v1, 4($t0)
.L8012CA78:
/* C3178 8012CA78 3C05E200 */  lui       $a1, 0xe200
/* C317C 8012CA7C 34A5001C */  ori       $a1, $a1, 0x1c
/* C3180 8012CA80 3C030050 */  lui       $v1, 0x50
/* C3184 8012CA84 34634240 */  ori       $v1, $v1, 0x4240
/* C3188 8012CA88 3C06FCFF */  lui       $a2, 0xfcff
/* C318C 8012CA8C 34C6FFFF */  ori       $a2, $a2, 0xffff
/* C3190 8012CA90 3C04FFFD */  lui       $a0, 0xfffd
/* C3194 8012CA94 3484F6FB */  ori       $a0, $a0, 0xf6fb
/* C3198 8012CA98 25020008 */  addiu     $v0, $t0, 8
/* C319C 8012CA9C AD220000 */  sw        $v0, ($t1)
/* C31A0 8012CAA0 25020010 */  addiu     $v0, $t0, 0x10
/* C31A4 8012CAA4 AD050000 */  sw        $a1, ($t0)
/* C31A8 8012CAA8 AD030004 */  sw        $v1, 4($t0)
/* C31AC 8012CAAC AD220000 */  sw        $v0, ($t1)
/* C31B0 8012CAB0 AD060008 */  sw        $a2, 8($t0)
/* C31B4 8012CAB4 AD04000C */  sw        $a0, 0xc($t0)
.L8012CAB8:
/* C31B8 8012CAB8 3C06E200 */  lui       $a2, 0xe200
/* C31BC 8012CABC 34C6001C */  ori       $a2, $a2, 0x1c
/* C31C0 8012CAC0 3C050F0A */  lui       $a1, 0xf0a
/* C31C4 8012CAC4 3C09800A */  lui       $t1, %hi(D_8009A66C)
/* C31C8 8012CAC8 2529A66C */  addiu     $t1, $t1, %lo(D_8009A66C)
/* C31CC 8012CACC 34A57008 */  ori       $a1, $a1, 0x7008
/* C31D0 8012CAD0 3C02FA00 */  lui       $v0, 0xfa00
/* C31D4 8012CAD4 8D280000 */  lw        $t0, ($t1)
/* C31D8 8012CAD8 000A1E00 */  sll       $v1, $t2, 0x18
/* C31DC 8012CADC 0100202D */  daddu     $a0, $t0, $zero
/* C31E0 8012CAE0 25080008 */  addiu     $t0, $t0, 8
/* C31E4 8012CAE4 AD280000 */  sw        $t0, ($t1)
/* C31E8 8012CAE8 AC820000 */  sw        $v0, ($a0)
/* C31EC 8012CAEC 316200FF */  andi      $v0, $t3, 0xff
/* C31F0 8012CAF0 00021400 */  sll       $v0, $v0, 0x10
/* C31F4 8012CAF4 00621825 */  or        $v1, $v1, $v0
/* C31F8 8012CAF8 318200FF */  andi      $v0, $t4, 0xff
/* C31FC 8012CAFC 00021200 */  sll       $v0, $v0, 8
/* C3200 8012CB00 00621825 */  or        $v1, $v1, $v0
/* C3204 8012CB04 30E200FF */  andi      $v0, $a3, 0xff
/* C3208 8012CB08 00621825 */  or        $v1, $v1, $v0
/* C320C 8012CB0C 25020008 */  addiu     $v0, $t0, 8
/* C3210 8012CB10 AC830004 */  sw        $v1, 4($a0)
/* C3214 8012CB14 31A403FF */  andi      $a0, $t5, 0x3ff
/* C3218 8012CB18 00042380 */  sll       $a0, $a0, 0xe
/* C321C 8012CB1C AD220000 */  sw        $v0, ($t1)
/* C3220 8012CB20 31C203FF */  andi      $v0, $t6, 0x3ff
/* C3224 8012CB24 00021080 */  sll       $v0, $v0, 2
/* C3228 8012CB28 3C03F600 */  lui       $v1, 0xf600
/* C322C 8012CB2C 00431025 */  or        $v0, $v0, $v1
/* C3230 8012CB30 00822025 */  or        $a0, $a0, $v0
/* C3234 8012CB34 31E303FF */  andi      $v1, $t7, 0x3ff
/* C3238 8012CB38 00031B80 */  sll       $v1, $v1, 0xe
/* C323C 8012CB3C 330203FF */  andi      $v0, $t8, 0x3ff
/* C3240 8012CB40 00021080 */  sll       $v0, $v0, 2
/* C3244 8012CB44 00621825 */  or        $v1, $v1, $v0
/* C3248 8012CB48 25020010 */  addiu     $v0, $t0, 0x10
/* C324C 8012CB4C AD040000 */  sw        $a0, ($t0)
/* C3250 8012CB50 AD030004 */  sw        $v1, 4($t0)
/* C3254 8012CB54 AD220000 */  sw        $v0, ($t1)
/* C3258 8012CB58 3C038015 */  lui       $v1, %hi(D_80155D74)
/* C325C 8012CB5C 8C635D74 */  lw        $v1, %lo(D_80155D74)($v1)
/* C3260 8012CB60 3C02E700 */  lui       $v0, 0xe700
/* C3264 8012CB64 AD020008 */  sw        $v0, 8($t0)
/* C3268 8012CB68 25020018 */  addiu     $v0, $t0, 0x18
/* C326C 8012CB6C AD00000C */  sw        $zero, 0xc($t0)
/* C3270 8012CB70 AD220000 */  sw        $v0, ($t1)
/* C3274 8012CB74 AD060010 */  sw        $a2, 0x10($t0)
/* C3278 8012CB78 AD050014 */  sw        $a1, 0x14($t0)
/* C327C 8012CB7C 90630029 */  lbu       $v1, 0x29($v1)
/* C3280 8012CB80 10600005 */  beqz      $v1, .L8012CB98
/* C3284 8012CB84 24020001 */   addiu    $v0, $zero, 1
/* C3288 8012CB88 1062000C */  beq       $v1, $v0, .L8012CBBC
/* C328C 8012CB8C 3C06FCFF */   lui      $a2, 0xfcff
/* C3290 8012CB90 0804B2F7 */  j         .L8012CBDC
/* C3294 8012CB94 34C6FFFF */   ori      $a2, $a2, 0xffff
.L8012CB98:
/* C3298 8012CB98 3C04FCFF */  lui       $a0, 0xfcff
/* C329C 8012CB9C 3484FFFF */  ori       $a0, $a0, 0xffff
/* C32A0 8012CBA0 3C03FFFC */  lui       $v1, 0xfffc
/* C32A4 8012CBA4 3463F279 */  ori       $v1, $v1, 0xf279
/* C32A8 8012CBA8 25020020 */  addiu     $v0, $t0, 0x20
/* C32AC 8012CBAC AD220000 */  sw        $v0, ($t1)
/* C32B0 8012CBB0 AD040018 */  sw        $a0, 0x18($t0)
/* C32B4 8012CBB4 03E00008 */  jr        $ra
/* C32B8 8012CBB8 AD03001C */   sw       $v1, 0x1c($t0)
.L8012CBBC:
/* C32BC 8012CBBC 3C02FC11 */  lui       $v0, 0xfc11
/* C32C0 8012CBC0 3442FE23 */  ori       $v0, $v0, 0xfe23
/* C32C4 8012CBC4 25030020 */  addiu     $v1, $t0, 0x20
/* C32C8 8012CBC8 AD230000 */  sw        $v1, ($t1)
/* C32CC 8012CBCC AD020018 */  sw        $v0, 0x18($t0)
/* C32D0 8012CBD0 2402F3F9 */  addiu     $v0, $zero, -0xc07
/* C32D4 8012CBD4 03E00008 */  jr        $ra
/* C32D8 8012CBD8 AD02001C */   sw       $v0, 0x1c($t0)
.L8012CBDC:
/* C32DC 8012CBDC 3C05FFFC */  lui       $a1, 0xfffc
/* C32E0 8012CBE0 3C04800A */  lui       $a0, %hi(D_8009A66C)
/* C32E4 8012CBE4 2484A66C */  addiu     $a0, $a0, %lo(D_8009A66C)
/* C32E8 8012CBE8 8C820000 */  lw        $v0, ($a0)
/* C32EC 8012CBEC 34A5F279 */  ori       $a1, $a1, 0xf279
/* C32F0 8012CBF0 0040182D */  daddu     $v1, $v0, $zero
/* C32F4 8012CBF4 24420008 */  addiu     $v0, $v0, 8
/* C32F8 8012CBF8 AC820000 */  sw        $v0, ($a0)
/* C32FC 8012CBFC AC660000 */  sw        $a2, ($v1)
/* C3300 8012CC00 03E00008 */  jr        $ra
/* C3304 8012CC04 AC650004 */   sw       $a1, 4($v1)
