.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_23_main
/* 3419E0 E002E000 27BDFF90 */  addiu     $sp, $sp, -0x70
/* 3419E4 E002E004 F7B40040 */  sdc1      $f20, 0x40($sp)
/* 3419E8 E002E008 4485A000 */  mtc1      $a1, $f20
/* 3419EC E002E00C F7B80050 */  sdc1      $f24, 0x50($sp)
/* 3419F0 E002E010 4486C000 */  mtc1      $a2, $f24
/* 3419F4 E002E014 AFB20030 */  sw        $s2, 0x30($sp)
/* 3419F8 E002E018 0080902D */  daddu     $s2, $a0, $zero
/* 3419FC E002E01C F7BA0058 */  sdc1      $f26, 0x58($sp)
/* 341A00 E002E020 4487D000 */  mtc1      $a3, $f26
/* 341A04 E002E024 AFBF003C */  sw        $ra, 0x3c($sp)
/* 341A08 E002E028 AFB40038 */  sw        $s4, 0x38($sp)
/* 341A0C E002E02C AFB30034 */  sw        $s3, 0x34($sp)
/* 341A10 E002E030 AFB1002C */  sw        $s1, 0x2c($sp)
/* 341A14 E002E034 AFB00028 */  sw        $s0, 0x28($sp)
/* 341A18 E002E038 F7BE0068 */  sdc1      $f30, 0x68($sp)
/* 341A1C E002E03C F7BC0060 */  sdc1      $f28, 0x60($sp)
/* 341A20 E002E040 F7B60048 */  sdc1      $f22, 0x48($sp)
/* 341A24 E002E044 12400006 */  beqz      $s2, .LE002E060
/* 341A28 E002E048 27A40010 */   addiu    $a0, $sp, 0x10
/* 341A2C E002E04C 24020001 */  addiu     $v0, $zero, 1
/* 341A30 E002E050 12420007 */  beq       $s2, $v0, .LE002E070
/* 341A34 E002E054 2413000B */   addiu    $s3, $zero, 0xb
/* 341A38 E002E058 0800B820 */  j         .LE002E080
/* 341A3C E002E05C 00000000 */   nop
.LE002E060:
/* 341A40 E002E060 3C014160 */  lui       $at, 0x4160
/* 341A44 E002E064 4481B000 */  mtc1      $at, $f22
/* 341A48 E002E068 0800B822 */  j         .LE002E088
/* 341A4C E002E06C 24130007 */   addiu    $s3, $zero, 7
.LE002E070:
/* 341A50 E002E070 3C0141E0 */  lui       $at, 0x41e0
/* 341A54 E002E074 4481B000 */  mtc1      $at, $f22
/* 341A58 E002E078 0800B822 */  j         .LE002E088
/* 341A5C E002E07C 24130009 */   addiu    $s3, $zero, 9
.LE002E080:
/* 341A60 E002E080 3C014228 */  lui       $at, 0x4228
/* 341A64 E002E084 4481B000 */  mtc1      $at, $f22
.LE002E088:
/* 341A68 E002E088 3C02E003 */  lui       $v0, %hi(fx_23_init)
/* 341A6C E002E08C 2442E248 */  addiu     $v0, $v0, %lo(fx_23_init)
/* 341A70 E002E090 AC820008 */  sw        $v0, 8($a0)
/* 341A74 E002E094 3C02E003 */  lui       $v0, %hi(fx_23_update)
/* 341A78 E002E098 2442E250 */  addiu     $v0, $v0, %lo(fx_23_update)
/* 341A7C E002E09C AC82000C */  sw        $v0, 0xc($a0)
/* 341A80 E002E0A0 3C02E003 */  lui       $v0, %hi(fx_23_render)
/* 341A84 E002E0A4 2442E330 */  addiu     $v0, $v0, %lo(fx_23_render)
/* 341A88 E002E0A8 AC820010 */  sw        $v0, 0x10($a0)
/* 341A8C E002E0AC 24020017 */  addiu     $v0, $zero, 0x17
/* 341A90 E002E0B0 AC800000 */  sw        $zero, ($a0)
/* 341A94 E002E0B4 AC800014 */  sw        $zero, 0x14($a0)
/* 341A98 E002E0B8 0C080124 */  jal       shim_create_effect_instance
/* 341A9C E002E0BC AC820004 */   sw       $v0, 4($a0)
/* 341AA0 E002E0C0 00132100 */  sll       $a0, $s3, 4
/* 341AA4 E002E0C4 00932021 */  addu      $a0, $a0, $s3
/* 341AA8 E002E0C8 00042080 */  sll       $a0, $a0, 2
/* 341AAC E002E0CC 0040802D */  daddu     $s0, $v0, $zero
/* 341AB0 E002E0D0 0C08012C */  jal       shim_general_heap_malloc
/* 341AB4 E002E0D4 AE130008 */   sw       $s3, 8($s0)
/* 341AB8 E002E0D8 0040882D */  daddu     $s1, $v0, $zero
/* 341ABC E002E0DC 16200003 */  bnez      $s1, .LE002E0EC
/* 341AC0 E002E0E0 AE11000C */   sw       $s1, 0xc($s0)
.LE002E0E4:
/* 341AC4 E002E0E4 0800B839 */  j         .LE002E0E4
/* 341AC8 E002E0E8 00000000 */   nop
.LE002E0EC:
/* 341ACC E002E0EC 0220202D */  daddu     $a0, $s1, $zero
/* 341AD0 E002E0F0 00132900 */  sll       $a1, $s3, 4
/* 341AD4 E002E0F4 00B32821 */  addu      $a1, $a1, $s3
/* 341AD8 E002E0F8 0C080130 */  jal       shim_mem_clear
/* 341ADC E002E0FC 00052880 */   sll      $a1, $a1, 2
/* 341AE0 E002E100 AE200038 */  sw        $zero, 0x38($s1)
/* 341AE4 E002E104 AE20003C */  sw        $zero, 0x3c($s1)
/* 341AE8 E002E108 A6320000 */  sh        $s2, ($s1)
/* 341AEC E002E10C E6340004 */  swc1      $f20, 4($s1)
/* 341AF0 E002E110 E6380008 */  swc1      $f24, 8($s1)
/* 341AF4 E002E114 E63A000C */  swc1      $f26, 0xc($s1)
/* 341AF8 E002E118 24120001 */  addiu     $s2, $zero, 1
/* 341AFC E002E11C 0253102A */  slt       $v0, $s2, $s3
/* 341B00 E002E120 1040003B */  beqz      $v0, .LE002E210
/* 341B04 E002E124 26310044 */   addiu    $s1, $s1, 0x44
/* 341B08 E002E128 2674FFFF */  addiu     $s4, $s3, -1
/* 341B0C E002E12C 26300034 */  addiu     $s0, $s1, 0x34
/* 341B10 E002E130 0000882D */  daddu     $s1, $zero, $zero
/* 341B14 E002E134 3C01C040 */  lui       $at, 0xc040
/* 341B18 E002E138 4481F000 */  mtc1      $at, $f30
/* 341B1C E002E13C 3C013E4C */  lui       $at, 0x3e4c
/* 341B20 E002E140 3421CCCC */  ori       $at, $at, 0xcccc
/* 341B24 E002E144 4481E000 */  mtc1      $at, $f28
/* 341B28 E002E148 3C013FE0 */  lui       $at, 0x3fe0
/* 341B2C E002E14C 4481D000 */  mtc1      $at, $f26
/* 341B30 E002E150 3C01BE23 */  lui       $at, 0xbe23
/* 341B34 E002E154 3421D70A */  ori       $at, $at, 0xd70a
/* 341B38 E002E158 4481C000 */  mtc1      $at, $f24
.LE002E15C:
/* 341B3C E002E15C 16800002 */  bnez      $s4, .LE002E168
/* 341B40 E002E160 0234001A */   div      $zero, $s1, $s4
/* 341B44 E002E164 0007000D */  break     7
.LE002E168:
/* 341B48 E002E168 2401FFFF */   addiu    $at, $zero, -1
/* 341B4C E002E16C 16810004 */  bne       $s4, $at, .LE002E180
/* 341B50 E002E170 3C018000 */   lui      $at, 0x8000
/* 341B54 E002E174 16210002 */  bne       $s1, $at, .LE002E180
/* 341B58 E002E178 00000000 */   nop
/* 341B5C E002E17C 0006000D */  break     6
.LE002E180:
/* 341B60 E002E180 00001812 */   mflo     $v1
/* 341B64 E002E184 E61EFFDC */  swc1      $f30, -0x24($s0)
/* 341B68 E002E188 E61CFFE0 */  swc1      $f28, -0x20($s0)
/* 341B6C E002E18C AE00FFE4 */  sw        $zero, -0x1c($s0)
/* 341B70 E002E190 AE00FFE8 */  sw        $zero, -0x18($s0)
/* 341B74 E002E194 E61AFFEC */  swc1      $f26, -0x14($s0)
/* 341B78 E002E198 E618FFF0 */  swc1      $f24, -0x10($s0)
/* 341B7C E002E19C AE00FFF4 */  sw        $zero, -0xc($s0)
/* 341B80 E002E1A0 AE00FFF8 */  sw        $zero, -8($s0)
/* 341B84 E002E1A4 4483A000 */  mtc1      $v1, $f20
/* 341B88 E002E1A8 00000000 */  nop
/* 341B8C E002E1AC 4680A520 */  cvt.s.w   $f20, $f20
/* 341B90 E002E1B0 0C080140 */  jal       shim_sin_deg
/* 341B94 E002E1B4 4600A306 */   mov.s    $f12, $f20
/* 341B98 E002E1B8 46000007 */  neg.s     $f0, $f0
/* 341B9C E002E1BC 46160002 */  mul.s     $f0, $f0, $f22
/* 341BA0 E002E1C0 00000000 */  nop
/* 341BA4 E002E1C4 4600A306 */  mov.s     $f12, $f20
/* 341BA8 E002E1C8 0C080144 */  jal       shim_cos_deg
/* 341BAC E002E1CC E600FFD0 */   swc1     $f0, -0x30($s0)
/* 341BB0 E002E1D0 46000007 */  neg.s     $f0, $f0
/* 341BB4 E002E1D4 46160002 */  mul.s     $f0, $f0, $f22
/* 341BB8 E002E1D8 00000000 */  nop
/* 341BBC E002E1DC 26310168 */  addiu     $s1, $s1, 0x168
/* 341BC0 E002E1E0 26520001 */  addiu     $s2, $s2, 1
/* 341BC4 E002E1E4 4600A306 */  mov.s     $f12, $f20
/* 341BC8 E002E1E8 AE00FFD8 */  sw        $zero, -0x28($s0)
/* 341BCC E002E1EC 0C080140 */  jal       shim_sin_deg
/* 341BD0 E002E1F0 E600FFD4 */   swc1     $f0, -0x2c($s0)
/* 341BD4 E002E1F4 4600A306 */  mov.s     $f12, $f20
/* 341BD8 E002E1F8 0C080144 */  jal       shim_cos_deg
/* 341BDC E002E1FC E600FFFC */   swc1     $f0, -4($s0)
/* 341BE0 E002E200 E6000000 */  swc1      $f0, ($s0)
/* 341BE4 E002E204 0253102A */  slt       $v0, $s2, $s3
/* 341BE8 E002E208 1440FFD4 */  bnez      $v0, .LE002E15C
/* 341BEC E002E20C 26100044 */   addiu    $s0, $s0, 0x44
.LE002E210:
/* 341BF0 E002E210 8FBF003C */  lw        $ra, 0x3c($sp)
/* 341BF4 E002E214 8FB40038 */  lw        $s4, 0x38($sp)
/* 341BF8 E002E218 8FB30034 */  lw        $s3, 0x34($sp)
/* 341BFC E002E21C 8FB20030 */  lw        $s2, 0x30($sp)
/* 341C00 E002E220 8FB1002C */  lw        $s1, 0x2c($sp)
/* 341C04 E002E224 8FB00028 */  lw        $s0, 0x28($sp)
/* 341C08 E002E228 D7BE0068 */  ldc1      $f30, 0x68($sp)
/* 341C0C E002E22C D7BC0060 */  ldc1      $f28, 0x60($sp)
/* 341C10 E002E230 D7BA0058 */  ldc1      $f26, 0x58($sp)
/* 341C14 E002E234 D7B80050 */  ldc1      $f24, 0x50($sp)
/* 341C18 E002E238 D7B60048 */  ldc1      $f22, 0x48($sp)
/* 341C1C E002E23C D7B40040 */  ldc1      $f20, 0x40($sp)
/* 341C20 E002E240 03E00008 */  jr        $ra
/* 341C24 E002E244 27BD0070 */   addiu    $sp, $sp, 0x70
