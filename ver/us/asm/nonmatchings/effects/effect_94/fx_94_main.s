.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_94_main
/* 3BA030 E00BC000 27BDFF90 */  addiu     $sp, $sp, -0x70
/* 3BA034 E00BC004 F7B40040 */  sdc1      $f20, 0x40($sp)
/* 3BA038 E00BC008 4485A000 */  mtc1      $a1, $f20
/* 3BA03C E00BC00C F7B60048 */  sdc1      $f22, 0x48($sp)
/* 3BA040 E00BC010 4486B000 */  mtc1      $a2, $f22
/* 3BA044 E00BC014 F7B80050 */  sdc1      $f24, 0x50($sp)
/* 3BA048 E00BC018 4487C000 */  mtc1      $a3, $f24
/* 3BA04C E00BC01C F7BA0058 */  sdc1      $f26, 0x58($sp)
/* 3BA050 E00BC020 C7BA0080 */  lwc1      $f26, 0x80($sp)
/* 3BA054 E00BC024 F7BC0060 */  sdc1      $f28, 0x60($sp)
/* 3BA058 E00BC028 C7BC0084 */  lwc1      $f28, 0x84($sp)
/* 3BA05C E00BC02C AFB30034 */  sw        $s3, 0x34($sp)
/* 3BA060 E00BC030 0080982D */  daddu     $s3, $a0, $zero
/* 3BA064 E00BC034 F7BE0068 */  sdc1      $f30, 0x68($sp)
/* 3BA068 E00BC038 C7BE0088 */  lwc1      $f30, 0x88($sp)
/* 3BA06C E00BC03C 27A40010 */  addiu     $a0, $sp, 0x10
/* 3BA070 E00BC040 AFB1002C */  sw        $s1, 0x2c($sp)
/* 3BA074 E00BC044 8FB10090 */  lw        $s1, 0x90($sp)
/* 3BA078 E00BC048 3C02E00C */  lui       $v0, %hi(fx_94_init)
/* 3BA07C E00BC04C 2442C1D0 */  addiu     $v0, $v0, %lo(fx_94_init)
/* 3BA080 E00BC050 AFA20018 */  sw        $v0, 0x18($sp)
/* 3BA084 E00BC054 3C02E00C */  lui       $v0, %hi(fx_94_update)
/* 3BA088 E00BC058 2442C238 */  addiu     $v0, $v0, %lo(fx_94_update)
/* 3BA08C E00BC05C AFA2001C */  sw        $v0, 0x1c($sp)
/* 3BA090 E00BC060 3C02E00C */  lui       $v0, %hi(fx_94_render)
/* 3BA094 E00BC064 2442C2E8 */  addiu     $v0, $v0, %lo(fx_94_render)
/* 3BA098 E00BC068 AFA20020 */  sw        $v0, 0x20($sp)
/* 3BA09C E00BC06C 2402005E */  addiu     $v0, $zero, 0x5e
/* 3BA0A0 E00BC070 AFBF0038 */  sw        $ra, 0x38($sp)
/* 3BA0A4 E00BC074 AFB20030 */  sw        $s2, 0x30($sp)
/* 3BA0A8 E00BC078 AFB00028 */  sw        $s0, 0x28($sp)
/* 3BA0AC E00BC07C AFA00010 */  sw        $zero, 0x10($sp)
/* 3BA0B0 E00BC080 AFA00024 */  sw        $zero, 0x24($sp)
/* 3BA0B4 E00BC084 0C080124 */  jal       shim_create_effect_instance
/* 3BA0B8 E00BC088 AFA20014 */   sw       $v0, 0x14($sp)
/* 3BA0BC E00BC08C 24040118 */  addiu     $a0, $zero, 0x118
/* 3BA0C0 E00BC090 24030001 */  addiu     $v1, $zero, 1
/* 3BA0C4 E00BC094 0040902D */  daddu     $s2, $v0, $zero
/* 3BA0C8 E00BC098 0C08012C */  jal       shim_general_heap_malloc
/* 3BA0CC E00BC09C AE430008 */   sw       $v1, 8($s2)
/* 3BA0D0 E00BC0A0 0040802D */  daddu     $s0, $v0, $zero
/* 3BA0D4 E00BC0A4 16000003 */  bnez      $s0, .LE00BC0B4
/* 3BA0D8 E00BC0A8 AE42000C */   sw       $v0, 0xc($s2)
.LE00BC0AC:
/* 3BA0DC E00BC0AC 0802F02B */  j         .LE00BC0AC
/* 3BA0E0 E00BC0B0 00000000 */   nop
.LE00BC0B4:
/* 3BA0E4 E00BC0B4 AE130000 */  sw        $s3, ($s0)
/* 3BA0E8 E00BC0B8 1E200004 */  bgtz      $s1, .LE00BC0CC
/* 3BA0EC E00BC0BC AE00002C */   sw       $zero, 0x2c($s0)
/* 3BA0F0 E00BC0C0 240203E8 */  addiu     $v0, $zero, 0x3e8
/* 3BA0F4 E00BC0C4 0802F034 */  j         .LE00BC0D0
/* 3BA0F8 E00BC0C8 AE020028 */   sw       $v0, 0x28($s0)
.LE00BC0CC:
/* 3BA0FC E00BC0CC AE110028 */  sw        $s1, 0x28($s0)
.LE00BC0D0:
/* 3BA100 E00BC0D0 461AA081 */  sub.s     $f2, $f20, $f26
/* 3BA104 E00BC0D4 46021082 */  mul.s     $f2, $f2, $f2
/* 3BA108 E00BC0D8 00000000 */  nop
/* 3BA10C E00BC0DC 461CB101 */  sub.s     $f4, $f22, $f28
/* 3BA110 E00BC0E0 46042102 */  mul.s     $f4, $f4, $f4
/* 3BA114 E00BC0E4 00000000 */  nop
/* 3BA118 E00BC0E8 241100FF */  addiu     $s1, $zero, 0xff
/* 3BA11C E00BC0EC AE11003C */  sw        $s1, 0x3c($s0)
/* 3BA120 E00BC0F0 E6140010 */  swc1      $f20, 0x10($s0)
/* 3BA124 E00BC0F4 E6160014 */  swc1      $f22, 0x14($s0)
/* 3BA128 E00BC0F8 461EC001 */  sub.s     $f0, $f24, $f30
/* 3BA12C E00BC0FC E6180018 */  swc1      $f24, 0x18($s0)
/* 3BA130 E00BC100 E61A001C */  swc1      $f26, 0x1c($s0)
/* 3BA134 E00BC104 46000002 */  mul.s     $f0, $f0, $f0
/* 3BA138 E00BC108 00000000 */  nop
/* 3BA13C E00BC10C E61C0020 */  swc1      $f28, 0x20($s0)
/* 3BA140 E00BC110 E61E0024 */  swc1      $f30, 0x24($s0)
/* 3BA144 E00BC114 E6140004 */  swc1      $f20, 4($s0)
/* 3BA148 E00BC118 E6160008 */  swc1      $f22, 8($s0)
/* 3BA14C E00BC11C 46041080 */  add.s     $f2, $f2, $f4
/* 3BA150 E00BC120 E618000C */  swc1      $f24, 0xc($s0)
/* 3BA154 E00BC124 44802000 */  mtc1      $zero, $f4
/* 3BA158 E00BC128 46001300 */  add.s     $f12, $f2, $f0
/* 3BA15C E00BC12C C7A0008C */  lwc1      $f0, 0x8c($sp)
/* 3BA160 E00BC130 46046032 */  c.eq.s    $f12, $f4
/* 3BA164 E00BC134 00000000 */  nop
/* 3BA168 E00BC138 45000003 */  bc1f      .LE00BC148
/* 3BA16C E00BC13C E600004C */   swc1     $f0, 0x4c($s0)
/* 3BA170 E00BC140 0802F067 */  j         .LE00BC19C
/* 3BA174 E00BC144 0000102D */   daddu    $v0, $zero, $zero
.LE00BC148:
/* 3BA178 E00BC148 0C080154 */  jal       shim_sqrtf
/* 3BA17C E00BC14C 00000000 */   nop
/* 3BA180 E00BC150 24040167 */  addiu     $a0, $zero, 0x167
/* 3BA184 E00BC154 46000021 */  cvt.d.s   $f0, $f0
/* 3BA188 E00BC158 3C01E00C */  lui       $at, %hi(D_E00BCE50)
/* 3BA18C E00BC15C D422CE50 */  ldc1      $f2, %lo(D_E00BCE50)($at)
/* 3BA190 E00BC160 240200DC */  addiu     $v0, $zero, 0xdc
/* 3BA194 E00BC164 46220002 */  mul.d     $f0, $f0, $f2
/* 3BA198 E00BC168 00000000 */  nop
/* 3BA19C E00BC16C AE020034 */  sw        $v0, 0x34($s0)
/* 3BA1A0 E00BC170 24020014 */  addiu     $v0, $zero, 0x14
/* 3BA1A4 E00BC174 AE110030 */  sw        $s1, 0x30($s0)
/* 3BA1A8 E00BC178 AE020038 */  sw        $v0, 0x38($s0)
/* 3BA1AC E00BC17C AE110040 */  sw        $s1, 0x40($s0)
/* 3BA1B0 E00BC180 AE110044 */  sw        $s1, 0x44($s0)
/* 3BA1B4 E00BC184 AE110048 */  sw        $s1, 0x48($s0)
/* 3BA1B8 E00BC188 46200020 */  cvt.s.d   $f0, $f0
/* 3BA1BC E00BC18C 0C080138 */  jal       shim_rand_int
/* 3BA1C0 E00BC190 E6000114 */   swc1     $f0, 0x114($s0)
/* 3BA1C4 E00BC194 AE020110 */  sw        $v0, 0x110($s0)
/* 3BA1C8 E00BC198 0240102D */  daddu     $v0, $s2, $zero
.LE00BC19C:
/* 3BA1CC E00BC19C 8FBF0038 */  lw        $ra, 0x38($sp)
/* 3BA1D0 E00BC1A0 8FB30034 */  lw        $s3, 0x34($sp)
/* 3BA1D4 E00BC1A4 8FB20030 */  lw        $s2, 0x30($sp)
/* 3BA1D8 E00BC1A8 8FB1002C */  lw        $s1, 0x2c($sp)
/* 3BA1DC E00BC1AC 8FB00028 */  lw        $s0, 0x28($sp)
/* 3BA1E0 E00BC1B0 D7BE0068 */  ldc1      $f30, 0x68($sp)
/* 3BA1E4 E00BC1B4 D7BC0060 */  ldc1      $f28, 0x60($sp)
/* 3BA1E8 E00BC1B8 D7BA0058 */  ldc1      $f26, 0x58($sp)
/* 3BA1EC E00BC1BC D7B80050 */  ldc1      $f24, 0x50($sp)
/* 3BA1F0 E00BC1C0 D7B60048 */  ldc1      $f22, 0x48($sp)
/* 3BA1F4 E00BC1C4 D7B40040 */  ldc1      $f20, 0x40($sp)
/* 3BA1F8 E00BC1C8 03E00008 */  jr        $ra
/* 3BA1FC E00BC1CC 27BD0070 */   addiu    $sp, $sp, 0x70
