.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00BE000
/* 3BBF60 E00BE000 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 3BBF64 E00BE004 F7B40040 */  sdc1      $f20, 0x40($sp)
/* 3BBF68 E00BE008 4485A000 */  mtc1      $a1, $f20
/* 3BBF6C E00BE00C F7B60048 */  sdc1      $f22, 0x48($sp)
/* 3BBF70 E00BE010 4486B000 */  mtc1      $a2, $f22
/* 3BBF74 E00BE014 F7B80050 */  sdc1      $f24, 0x50($sp)
/* 3BBF78 E00BE018 4487C000 */  mtc1      $a3, $f24
/* 3BBF7C E00BE01C AFB20030 */  sw        $s2, 0x30($sp)
/* 3BBF80 E00BE020 0080902D */  daddu     $s2, $a0, $zero
/* 3BBF84 E00BE024 AFB1002C */  sw        $s1, 0x2c($sp)
/* 3BBF88 E00BE028 8FB1006C */  lw        $s1, 0x6c($sp)
/* 3BBF8C E00BE02C 27A40010 */  addiu     $a0, $sp, 0x10
/* 3BBF90 E00BE030 AFBF003C */  sw        $ra, 0x3c($sp)
/* 3BBF94 E00BE034 AFB40038 */  sw        $s4, 0x38($sp)
/* 3BBF98 E00BE038 AFB30034 */  sw        $s3, 0x34($sp)
/* 3BBF9C E00BE03C 06400009 */  bltz      $s2, .LE00BE064
/* 3BBFA0 E00BE040 AFB00028 */   sw       $s0, 0x28($sp)
/* 3BBFA4 E00BE044 2A420002 */  slti      $v0, $s2, 2
/* 3BBFA8 E00BE048 14400007 */  bnez      $v0, .LE00BE068
/* 3BBFAC E00BE04C 24100015 */   addiu    $s0, $zero, 0x15
/* 3BBFB0 E00BE050 24020002 */  addiu     $v0, $zero, 2
/* 3BBFB4 E00BE054 16420004 */  bne       $s2, $v0, .LE00BE068
/* 3BBFB8 E00BE058 2410000B */   addiu    $s0, $zero, 0xb
/* 3BBFBC E00BE05C 0802F81A */  j         .LE00BE068
/* 3BBFC0 E00BE060 24100029 */   addiu    $s0, $zero, 0x29
.LE00BE064:
/* 3BBFC4 E00BE064 2410000B */  addiu     $s0, $zero, 0xb
.LE00BE068:
/* 3BBFC8 E00BE068 3C02E00C */  lui       $v0, %hi(func_E00BE39C)
/* 3BBFCC E00BE06C 2442E39C */  addiu     $v0, $v0, %lo(func_E00BE39C)
/* 3BBFD0 E00BE070 AC820008 */  sw        $v0, 8($a0)
/* 3BBFD4 E00BE074 3C02E00C */  lui       $v0, %hi(func_E00BE3A4)
/* 3BBFD8 E00BE078 2442E3A4 */  addiu     $v0, $v0, %lo(func_E00BE3A4)
/* 3BBFDC E00BE07C AC82000C */  sw        $v0, 0xc($a0)
/* 3BBFE0 E00BE080 3C02E00C */  lui       $v0, %hi(func_E00BE578)
/* 3BBFE4 E00BE084 2442E578 */  addiu     $v0, $v0, %lo(func_E00BE578)
/* 3BBFE8 E00BE088 AC820010 */  sw        $v0, 0x10($a0)
/* 3BBFEC E00BE08C 2402005F */  addiu     $v0, $zero, 0x5f
/* 3BBFF0 E00BE090 AC800000 */  sw        $zero, ($a0)
/* 3BBFF4 E00BE094 AC800014 */  sw        $zero, 0x14($a0)
/* 3BBFF8 E00BE098 0C080124 */  jal       func_E0200490
/* 3BBFFC E00BE09C AC820004 */   sw       $v0, 4($a0)
/* 3BC000 E00BE0A0 001020C0 */  sll       $a0, $s0, 3
/* 3BC004 E00BE0A4 00902023 */  subu      $a0, $a0, $s0
/* 3BC008 E00BE0A8 000420C0 */  sll       $a0, $a0, 3
/* 3BC00C E00BE0AC 0040982D */  daddu     $s3, $v0, $zero
/* 3BC010 E00BE0B0 0C08012C */  jal       func_E02004B0
/* 3BC014 E00BE0B4 AE700008 */   sw       $s0, 8($s3)
/* 3BC018 E00BE0B8 0040202D */  daddu     $a0, $v0, $zero
/* 3BC01C E00BE0BC 14800003 */  bnez      $a0, .LE00BE0CC
/* 3BC020 E00BE0C0 AE64000C */   sw       $a0, 0xc($s3)
.LE00BE0C4:
/* 3BC024 E00BE0C4 0802F831 */  j         .LE00BE0C4
/* 3BC028 E00BE0C8 00000000 */   nop      
.LE00BE0CC:
/* 3BC02C E00BE0CC AC920000 */  sw        $s2, ($a0)
/* 3BC030 E00BE0D0 1E200004 */  bgtz      $s1, .LE00BE0E4
/* 3BC034 E00BE0D4 AC800020 */   sw       $zero, 0x20($a0)
/* 3BC038 E00BE0D8 240203E8 */  addiu     $v0, $zero, 0x3e8
/* 3BC03C E00BE0DC 0802F83A */  j         .LE00BE0E8
/* 3BC040 E00BE0E0 AC82001C */   sw       $v0, 0x1c($a0)
.LE00BE0E4:
/* 3BC044 E00BE0E4 AC91001C */  sw        $s1, 0x1c($a0)
.LE00BE0E8:
/* 3BC048 E00BE0E8 240300FF */  addiu     $v1, $zero, 0xff
/* 3BC04C E00BE0EC AC830030 */  sw        $v1, 0x30($a0)
/* 3BC050 E00BE0F0 E4940004 */  swc1      $f20, 4($a0)
/* 3BC054 E00BE0F4 E4960008 */  swc1      $f22, 8($a0)
/* 3BC058 E00BE0F8 E498000C */  swc1      $f24, 0xc($a0)
/* 3BC05C E00BE0FC C7A00068 */  lwc1      $f0, 0x68($sp)
/* 3BC060 E00BE100 24020046 */  addiu     $v0, $zero, 0x46
/* 3BC064 E00BE104 AC820024 */  sw        $v0, 0x24($a0)
/* 3BC068 E00BE108 240200B4 */  addiu     $v0, $zero, 0xb4
/* 3BC06C E00BE10C 24110001 */  addiu     $s1, $zero, 1
/* 3BC070 E00BE110 AC820028 */  sw        $v0, 0x28($a0)
/* 3BC074 E00BE114 AC83002C */  sw        $v1, 0x2c($a0)
/* 3BC078 E00BE118 E4800034 */  swc1      $f0, 0x34($a0)
/* 3BC07C E00BE11C 8E620008 */  lw        $v0, 8($s3)
/* 3BC080 E00BE120 0222102A */  slt       $v0, $s1, $v0
/* 3BC084 E00BE124 10400091 */  beqz      $v0, .LE00BE36C
/* 3BC088 E00BE128 24840038 */   addiu    $a0, $a0, 0x38
/* 3BC08C E00BE12C 24140002 */  addiu     $s4, $zero, 2
/* 3BC090 E00BE130 24900030 */  addiu     $s0, $a0, 0x30
/* 3BC094 E00BE134 3C013D8F */  lui       $at, 0x3d8f
/* 3BC098 E00BE138 34215C29 */  ori       $at, $at, 0x5c29
/* 3BC09C E00BE13C 4481B000 */  mtc1      $at, $f22
/* 3BC0A0 E00BE140 3C013FE0 */  lui       $at, 0x3fe0
/* 3BC0A4 E00BE144 4481A800 */  mtc1      $at, $f21
/* 3BC0A8 E00BE148 4480A000 */  mtc1      $zero, $f20
.LE00BE14C:
/* 3BC0AC E00BE14C 3C014000 */  lui       $at, 0x4000
/* 3BC0B0 E00BE150 44810000 */  mtc1      $at, $f0
/* 3BC0B4 E00BE154 24020001 */  addiu     $v0, $zero, 1
/* 3BC0B8 E00BE158 AE00FFD4 */  sw        $zero, -0x2c($s0)
/* 3BC0BC E00BE15C AE00FFD8 */  sw        $zero, -0x28($s0)
/* 3BC0C0 E00BE160 AE00FFDC */  sw        $zero, -0x24($s0)
/* 3BC0C4 E00BE164 12420022 */  beq       $s2, $v0, .LE00BE1F0
/* 3BC0C8 E00BE168 E6000004 */   swc1     $f0, 4($s0)
/* 3BC0CC E00BE16C 2A420002 */  slti      $v0, $s2, 2
/* 3BC0D0 E00BE170 10400005 */  beqz      $v0, .LE00BE188
/* 3BC0D4 E00BE174 00000000 */   nop      
/* 3BC0D8 E00BE178 12400007 */  beqz      $s2, .LE00BE198
/* 3BC0DC E00BE17C 00000000 */   nop      
/* 3BC0E0 E00BE180 0802F8B1 */  j         .LE00BE2C4
/* 3BC0E4 E00BE184 00000000 */   nop      
.LE00BE188:
/* 3BC0E8 E00BE188 1254002F */  beq       $s2, $s4, .LE00BE248
/* 3BC0EC E00BE18C 00000000 */   nop      
/* 3BC0F0 E00BE190 0802F8B1 */  j         .LE00BE2C4
/* 3BC0F4 E00BE194 00000000 */   nop      
.LE00BE198:
/* 3BC0F8 E00BE198 0C080138 */  jal       func_E02004E0
/* 3BC0FC E00BE19C 2404000A */   addiu    $a0, $zero, 0xa
/* 3BC100 E00BE1A0 2404000A */  addiu     $a0, $zero, 0xa
/* 3BC104 E00BE1A4 2442FFFE */  addiu     $v0, $v0, -2
/* 3BC108 E00BE1A8 44820000 */  mtc1      $v0, $f0
/* 3BC10C E00BE1AC 00000000 */  nop       
/* 3BC110 E00BE1B0 46800020 */  cvt.s.w   $f0, $f0
/* 3BC114 E00BE1B4 0C080138 */  jal       func_E02004E0
/* 3BC118 E00BE1B8 E600FFE0 */   swc1     $f0, -0x20($s0)
/* 3BC11C E00BE1BC 2404000A */  addiu     $a0, $zero, 0xa
/* 3BC120 E00BE1C0 2442FFFB */  addiu     $v0, $v0, -5
/* 3BC124 E00BE1C4 44820000 */  mtc1      $v0, $f0
/* 3BC128 E00BE1C8 00000000 */  nop       
/* 3BC12C E00BE1CC 46800020 */  cvt.s.w   $f0, $f0
/* 3BC130 E00BE1D0 0C080138 */  jal       func_E02004E0
/* 3BC134 E00BE1D4 E600FFE4 */   swc1     $f0, -0x1c($s0)
/* 3BC138 E00BE1D8 2442FFFB */  addiu     $v0, $v0, -5
/* 3BC13C E00BE1DC 44820000 */  mtc1      $v0, $f0
/* 3BC140 E00BE1E0 00000000 */  nop       
/* 3BC144 E00BE1E4 46800020 */  cvt.s.w   $f0, $f0
/* 3BC148 E00BE1E8 0802F8D4 */  j         .LE00BE350
/* 3BC14C E00BE1EC E600FFE8 */   swc1     $f0, -0x18($s0)
.LE00BE1F0:
/* 3BC150 E00BE1F0 0C080138 */  jal       func_E02004E0
/* 3BC154 E00BE1F4 2404000A */   addiu    $a0, $zero, 0xa
/* 3BC158 E00BE1F8 2404000A */  addiu     $a0, $zero, 0xa
/* 3BC15C E00BE1FC 02821023 */  subu      $v0, $s4, $v0
/* 3BC160 E00BE200 44820000 */  mtc1      $v0, $f0
/* 3BC164 E00BE204 00000000 */  nop       
/* 3BC168 E00BE208 46800020 */  cvt.s.w   $f0, $f0
/* 3BC16C E00BE20C 0C080138 */  jal       func_E02004E0
/* 3BC170 E00BE210 E600FFE0 */   swc1     $f0, -0x20($s0)
/* 3BC174 E00BE214 2404000A */  addiu     $a0, $zero, 0xa
/* 3BC178 E00BE218 2442FFFB */  addiu     $v0, $v0, -5
/* 3BC17C E00BE21C 44820000 */  mtc1      $v0, $f0
/* 3BC180 E00BE220 00000000 */  nop       
/* 3BC184 E00BE224 46800020 */  cvt.s.w   $f0, $f0
/* 3BC188 E00BE228 0C080138 */  jal       func_E02004E0
/* 3BC18C E00BE22C E600FFE4 */   swc1     $f0, -0x1c($s0)
/* 3BC190 E00BE230 2442FFFB */  addiu     $v0, $v0, -5
/* 3BC194 E00BE234 44820000 */  mtc1      $v0, $f0
/* 3BC198 E00BE238 00000000 */  nop       
/* 3BC19C E00BE23C 46800020 */  cvt.s.w   $f0, $f0
/* 3BC1A0 E00BE240 0802F8D4 */  j         .LE00BE350
/* 3BC1A4 E00BE244 E600FFE8 */   swc1     $f0, -0x18($s0)
.LE00BE248:
/* 3BC1A8 E00BE248 0C080138 */  jal       func_E02004E0
/* 3BC1AC E00BE24C 24040064 */   addiu    $a0, $zero, 0x64
/* 3BC1B0 E00BE250 2442FFCE */  addiu     $v0, $v0, -0x32
/* 3BC1B4 E00BE254 44820000 */  mtc1      $v0, $f0
/* 3BC1B8 E00BE258 00000000 */  nop       
/* 3BC1BC E00BE25C 46800020 */  cvt.s.w   $f0, $f0
/* 3BC1C0 E00BE260 46160002 */  mul.s     $f0, $f0, $f22
/* 3BC1C4 E00BE264 00000000 */  nop       
/* 3BC1C8 E00BE268 24040064 */  addiu     $a0, $zero, 0x64
/* 3BC1CC E00BE26C 0C080138 */  jal       func_E02004E0
/* 3BC1D0 E00BE270 E600FFE0 */   swc1     $f0, -0x20($s0)
/* 3BC1D4 E00BE274 2442000A */  addiu     $v0, $v0, 0xa
/* 3BC1D8 E00BE278 3C013E4C */  lui       $at, 0x3e4c
/* 3BC1DC E00BE27C 3421CCCD */  ori       $at, $at, 0xcccd
/* 3BC1E0 E00BE280 44811000 */  mtc1      $at, $f2
/* 3BC1E4 E00BE284 44820000 */  mtc1      $v0, $f0
/* 3BC1E8 E00BE288 00000000 */  nop       
/* 3BC1EC E00BE28C 46800020 */  cvt.s.w   $f0, $f0
/* 3BC1F0 E00BE290 46020002 */  mul.s     $f0, $f0, $f2
/* 3BC1F4 E00BE294 00000000 */  nop       
/* 3BC1F8 E00BE298 24040064 */  addiu     $a0, $zero, 0x64
/* 3BC1FC E00BE29C 0C080138 */  jal       func_E02004E0
/* 3BC200 E00BE2A0 E600FFE4 */   swc1     $f0, -0x1c($s0)
/* 3BC204 E00BE2A4 2442FFCE */  addiu     $v0, $v0, -0x32
/* 3BC208 E00BE2A8 44820000 */  mtc1      $v0, $f0
/* 3BC20C E00BE2AC 00000000 */  nop       
/* 3BC210 E00BE2B0 46800020 */  cvt.s.w   $f0, $f0
/* 3BC214 E00BE2B4 46160002 */  mul.s     $f0, $f0, $f22
/* 3BC218 E00BE2B8 00000000 */  nop       
/* 3BC21C E00BE2BC 0802F8D4 */  j         .LE00BE350
/* 3BC220 E00BE2C0 E600FFE8 */   swc1     $f0, -0x18($s0)
.LE00BE2C4:
/* 3BC224 E00BE2C4 0C080138 */  jal       func_E02004E0
/* 3BC228 E00BE2C8 2404000A */   addiu    $a0, $zero, 0xa
/* 3BC22C E00BE2CC 2442FFFB */  addiu     $v0, $v0, -5
/* 3BC230 E00BE2D0 44820000 */  mtc1      $v0, $f0
/* 3BC234 E00BE2D4 00000000 */  nop       
/* 3BC238 E00BE2D8 46800021 */  cvt.d.w   $f0, $f0
/* 3BC23C E00BE2DC 46340002 */  mul.d     $f0, $f0, $f20
/* 3BC240 E00BE2E0 00000000 */  nop       
/* 3BC244 E00BE2E4 2404000A */  addiu     $a0, $zero, 0xa
/* 3BC248 E00BE2E8 46200020 */  cvt.s.d   $f0, $f0
/* 3BC24C E00BE2EC 0C080138 */  jal       func_E02004E0
/* 3BC250 E00BE2F0 E600FFE0 */   swc1     $f0, -0x20($s0)
/* 3BC254 E00BE2F4 2442FFFB */  addiu     $v0, $v0, -5
/* 3BC258 E00BE2F8 44820000 */  mtc1      $v0, $f0
/* 3BC25C E00BE2FC 00000000 */  nop       
/* 3BC260 E00BE300 46800021 */  cvt.d.w   $f0, $f0
/* 3BC264 E00BE304 46340002 */  mul.d     $f0, $f0, $f20
/* 3BC268 E00BE308 00000000 */  nop       
/* 3BC26C E00BE30C 2404000A */  addiu     $a0, $zero, 0xa
/* 3BC270 E00BE310 46200020 */  cvt.s.d   $f0, $f0
/* 3BC274 E00BE314 0C080138 */  jal       func_E02004E0
/* 3BC278 E00BE318 E600FFE4 */   swc1     $f0, -0x1c($s0)
/* 3BC27C E00BE31C 2442FFFB */  addiu     $v0, $v0, -5
/* 3BC280 E00BE320 44820000 */  mtc1      $v0, $f0
/* 3BC284 E00BE324 00000000 */  nop       
/* 3BC288 E00BE328 46800021 */  cvt.d.w   $f0, $f0
/* 3BC28C E00BE32C 46340002 */  mul.d     $f0, $f0, $f20
/* 3BC290 E00BE330 00000000 */  nop       
/* 3BC294 E00BE334 3C013ECC */  lui       $at, 0x3ecc
/* 3BC298 E00BE338 3421CCCD */  ori       $at, $at, 0xcccd
/* 3BC29C E00BE33C 44811000 */  mtc1      $at, $f2
/* 3BC2A0 E00BE340 AE11FFEC */  sw        $s1, -0x14($s0)
/* 3BC2A4 E00BE344 E6020004 */  swc1      $f2, 4($s0)
/* 3BC2A8 E00BE348 46200020 */  cvt.s.d   $f0, $f0
/* 3BC2AC E00BE34C E600FFE8 */  swc1      $f0, -0x18($s0)
.LE00BE350:
/* 3BC2B0 E00BE350 26310001 */  addiu     $s1, $s1, 1
/* 3BC2B4 E00BE354 240200FF */  addiu     $v0, $zero, 0xff
/* 3BC2B8 E00BE358 AE020000 */  sw        $v0, ($s0)
/* 3BC2BC E00BE35C 8E620008 */  lw        $v0, 8($s3)
/* 3BC2C0 E00BE360 0222102A */  slt       $v0, $s1, $v0
/* 3BC2C4 E00BE364 1440FF79 */  bnez      $v0, .LE00BE14C
/* 3BC2C8 E00BE368 26100038 */   addiu    $s0, $s0, 0x38
.LE00BE36C:
/* 3BC2CC E00BE36C 0260102D */  daddu     $v0, $s3, $zero
/* 3BC2D0 E00BE370 8FBF003C */  lw        $ra, 0x3c($sp)
/* 3BC2D4 E00BE374 8FB40038 */  lw        $s4, 0x38($sp)
/* 3BC2D8 E00BE378 8FB30034 */  lw        $s3, 0x34($sp)
/* 3BC2DC E00BE37C 8FB20030 */  lw        $s2, 0x30($sp)
/* 3BC2E0 E00BE380 8FB1002C */  lw        $s1, 0x2c($sp)
/* 3BC2E4 E00BE384 8FB00028 */  lw        $s0, 0x28($sp)
/* 3BC2E8 E00BE388 D7B80050 */  ldc1      $f24, 0x50($sp)
/* 3BC2EC E00BE38C D7B60048 */  ldc1      $f22, 0x48($sp)
/* 3BC2F0 E00BE390 D7B40040 */  ldc1      $f20, 0x40($sp)
/* 3BC2F4 E00BE394 03E00008 */  jr        $ra
/* 3BC2F8 E00BE398 27BD0058 */   addiu    $sp, $sp, 0x58
