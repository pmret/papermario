.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_114_main
/* 3DE000 E00E4000 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 3DE004 E00E4004 F7B40040 */  sdc1      $f20, 0x40($sp)
/* 3DE008 E00E4008 4485A000 */  mtc1      $a1, $f20
/* 3DE00C E00E400C F7B60048 */  sdc1      $f22, 0x48($sp)
/* 3DE010 E00E4010 4486B000 */  mtc1      $a2, $f22
/* 3DE014 E00E4014 F7B80050 */  sdc1      $f24, 0x50($sp)
/* 3DE018 E00E4018 4487C000 */  mtc1      $a3, $f24
/* 3DE01C E00E401C AFB20030 */  sw        $s2, 0x30($sp)
/* 3DE020 E00E4020 0080902D */  daddu     $s2, $a0, $zero
/* 3DE024 E00E4024 AFB1002C */  sw        $s1, 0x2c($sp)
/* 3DE028 E00E4028 8FB10074 */  lw        $s1, 0x74($sp)
/* 3DE02C E00E402C 27A40010 */  addiu     $a0, $sp, 0x10
/* 3DE030 E00E4030 AFB40038 */  sw        $s4, 0x38($sp)
/* 3DE034 E00E4034 8FB40078 */  lw        $s4, 0x78($sp)
/* 3DE038 E00E4038 3C02E00E */  lui       $v0, %hi(func_E00E4288)
/* 3DE03C E00E403C 24424288 */  addiu     $v0, $v0, %lo(func_E00E4288)
/* 3DE040 E00E4040 AFA20018 */  sw        $v0, 0x18($sp)
/* 3DE044 E00E4044 3C02E00E */  lui       $v0, %hi(func_E00E4290)
/* 3DE048 E00E4048 24424290 */  addiu     $v0, $v0, %lo(func_E00E4290)
/* 3DE04C E00E404C AFA2001C */  sw        $v0, 0x1c($sp)
/* 3DE050 E00E4050 3C02E00E */  lui       $v0, %hi(func_E00E490C)
/* 3DE054 E00E4054 2442490C */  addiu     $v0, $v0, %lo(func_E00E490C)
/* 3DE058 E00E4058 AFA20020 */  sw        $v0, 0x20($sp)
/* 3DE05C E00E405C 24020072 */  addiu     $v0, $zero, 0x72
/* 3DE060 E00E4060 AFBF003C */  sw        $ra, 0x3c($sp)
/* 3DE064 E00E4064 AFB30034 */  sw        $s3, 0x34($sp)
/* 3DE068 E00E4068 AFB00028 */  sw        $s0, 0x28($sp)
/* 3DE06C E00E406C AFA00010 */  sw        $zero, 0x10($sp)
/* 3DE070 E00E4070 AFA00024 */  sw        $zero, 0x24($sp)
/* 3DE074 E00E4074 AFA20014 */  sw        $v0, 0x14($sp)
/* 3DE078 E00E4078 0C080124 */  jal       shim_create_effect_instance
/* 3DE07C E00E407C 26310001 */   addiu    $s1, $s1, 1
/* 3DE080 E00E4080 00112040 */  sll       $a0, $s1, 1
/* 3DE084 E00E4084 00912021 */  addu      $a0, $a0, $s1
/* 3DE088 E00E4088 000420C0 */  sll       $a0, $a0, 3
/* 3DE08C E00E408C 00912021 */  addu      $a0, $a0, $s1
/* 3DE090 E00E4090 00042080 */  sll       $a0, $a0, 2
/* 3DE094 E00E4094 0040982D */  daddu     $s3, $v0, $zero
/* 3DE098 E00E4098 0C08012C */  jal       shim_general_heap_malloc
/* 3DE09C E00E409C AE710008 */   sw       $s1, 8($s3)
/* 3DE0A0 E00E40A0 0040802D */  daddu     $s0, $v0, $zero
/* 3DE0A4 E00E40A4 16000003 */  bnez      $s0, .LE00E40B4
/* 3DE0A8 E00E40A8 AE70000C */   sw       $s0, 0xc($s3)
.LE00E40AC:
/* 3DE0AC E00E40AC 0803902B */  j         .LE00E40AC
/* 3DE0B0 E00E40B0 00000000 */   nop
.LE00E40B4:
/* 3DE0B4 E00E40B4 AE120000 */  sw        $s2, ($s0)
/* 3DE0B8 E00E40B8 1E800004 */  bgtz      $s4, .LE00E40CC
/* 3DE0BC E00E40BC AE000034 */   sw       $zero, 0x34($s0)
/* 3DE0C0 E00E40C0 240203E8 */  addiu     $v0, $zero, 0x3e8
/* 3DE0C4 E00E40C4 08039034 */  j         .LE00E40D0
/* 3DE0C8 E00E40C8 AE020030 */   sw       $v0, 0x30($s0)
.LE00E40CC:
/* 3DE0CC E00E40CC AE140030 */  sw        $s4, 0x30($s0)
.LE00E40D0:
/* 3DE0D0 E00E40D0 240300FF */  addiu     $v1, $zero, 0xff
/* 3DE0D4 E00E40D4 AE030044 */  sw        $v1, 0x44($s0)
/* 3DE0D8 E00E40D8 E6140004 */  swc1      $f20, 4($s0)
/* 3DE0DC E00E40DC E6160008 */  swc1      $f22, 8($s0)
/* 3DE0E0 E00E40E0 E618000C */  swc1      $f24, 0xc($s0)
/* 3DE0E4 E00E40E4 C7A00070 */  lwc1      $f0, 0x70($sp)
/* 3DE0E8 E00E40E8 E6000058 */  swc1      $f0, 0x58($s0)
/* 3DE0EC E00E40EC C7A00068 */  lwc1      $f0, 0x68($sp)
/* 3DE0F0 E00E40F0 E6000010 */  swc1      $f0, 0x10($s0)
/* 3DE0F4 E00E40F4 C7A0006C */  lwc1      $f0, 0x6c($sp)
/* 3DE0F8 E00E40F8 24020001 */  addiu     $v0, $zero, 1
/* 3DE0FC E00E40FC AE030038 */  sw        $v1, 0x38($s0)
/* 3DE100 E00E4100 AE03003C */  sw        $v1, 0x3c($s0)
/* 3DE104 E00E4104 AE030040 */  sw        $v1, 0x40($s0)
/* 3DE108 E00E4108 1242000E */  beq       $s2, $v0, .LE00E4144
/* 3DE10C E00E410C E6000014 */   swc1     $f0, 0x14($s0)
/* 3DE110 E00E4110 2A420002 */  slti      $v0, $s2, 2
/* 3DE114 E00E4114 10400005 */  beqz      $v0, .LE00E412C
/* 3DE118 E00E4118 2A420004 */   slti     $v0, $s2, 4
/* 3DE11C E00E411C 52400007 */  beql      $s2, $zero, .LE00E413C
/* 3DE120 E00E4120 AE030048 */   sw       $v1, 0x48($s0)
/* 3DE124 E00E4124 0803905C */  j         .LE00E4170
/* 3DE128 E00E4128 00000000 */   nop
.LE00E412C:
/* 3DE12C E00E412C 10400010 */  beqz      $v0, .LE00E4170
/* 3DE130 E00E4130 240300FF */   addiu    $v1, $zero, 0xff
/* 3DE134 E00E4134 08039057 */  j         .LE00E415C
/* 3DE138 E00E4138 24020080 */   addiu    $v0, $zero, 0x80
.LE00E413C:
/* 3DE13C E00E413C 08039054 */  j         .LE00E4150
/* 3DE140 E00E4140 AE03004C */   sw       $v1, 0x4c($s0)
.LE00E4144:
/* 3DE144 E00E4144 2402007F */  addiu     $v0, $zero, 0x7f
/* 3DE148 E00E4148 AE000048 */  sw        $zero, 0x48($s0)
/* 3DE14C E00E414C AE02004C */  sw        $v0, 0x4c($s0)
.LE00E4150:
/* 3DE150 E00E4150 AE030050 */  sw        $v1, 0x50($s0)
/* 3DE154 E00E4154 08039071 */  j         .LE00E41C4
/* 3DE158 E00E4158 AE030054 */   sw       $v1, 0x54($s0)
.LE00E415C:
/* 3DE15C E00E415C AE030048 */  sw        $v1, 0x48($s0)
/* 3DE160 E00E4160 AE03004C */  sw        $v1, 0x4c($s0)
/* 3DE164 E00E4164 AE020050 */  sw        $v0, 0x50($s0)
/* 3DE168 E00E4168 08039071 */  j         .LE00E41C4
/* 3DE16C E00E416C AE030054 */   sw       $v1, 0x54($s0)
.LE00E4170:
/* 3DE170 E00E4170 0C080138 */  jal       shim_rand_int
/* 3DE174 E00E4174 2404007F */   addiu    $a0, $zero, 0x7f
/* 3DE178 E00E4178 24420080 */  addiu     $v0, $v0, 0x80
/* 3DE17C E00E417C 240400FF */  addiu     $a0, $zero, 0xff
/* 3DE180 E00E4180 00822023 */  subu      $a0, $a0, $v0
/* 3DE184 E00E4184 0C080138 */  jal       shim_rand_int
/* 3DE188 E00E4188 AE020038 */   sw       $v0, 0x38($s0)
/* 3DE18C E00E418C 24420080 */  addiu     $v0, $v0, 0x80
/* 3DE190 E00E4190 2404017F */  addiu     $a0, $zero, 0x17f
/* 3DE194 E00E4194 8E030038 */  lw        $v1, 0x38($s0)
/* 3DE198 E00E4198 00822023 */  subu      $a0, $a0, $v0
/* 3DE19C E00E419C AE02003C */  sw        $v0, 0x3c($s0)
/* 3DE1A0 E00E41A0 0C080138 */  jal       shim_rand_int
/* 3DE1A4 E00E41A4 00832023 */   subu     $a0, $a0, $v1
/* 3DE1A8 E00E41A8 24420080 */  addiu     $v0, $v0, 0x80
/* 3DE1AC E00E41AC AE020040 */  sw        $v0, 0x40($s0)
/* 3DE1B0 E00E41B0 2402007F */  addiu     $v0, $zero, 0x7f
/* 3DE1B4 E00E41B4 AE020048 */  sw        $v0, 0x48($s0)
/* 3DE1B8 E00E41B8 AE02004C */  sw        $v0, 0x4c($s0)
/* 3DE1BC E00E41BC AE020050 */  sw        $v0, 0x50($s0)
/* 3DE1C0 E00E41C0 AE020054 */  sw        $v0, 0x54($s0)
.LE00E41C4:
/* 3DE1C4 E00E41C4 8E030030 */  lw        $v1, 0x30($s0)
/* 3DE1C8 E00E41C8 2862001E */  slti      $v0, $v1, 0x1e
/* 3DE1CC E00E41CC 10400009 */  beqz      $v0, .LE00E41F4
/* 3DE1D0 E00E41D0 2622FFFF */   addiu    $v0, $s1, -1
/* 3DE1D4 E00E41D4 44830000 */  mtc1      $v1, $f0
/* 3DE1D8 E00E41D8 00000000 */  nop
/* 3DE1DC E00E41DC 46800020 */  cvt.s.w   $f0, $f0
/* 3DE1E0 E00E41E0 44821000 */  mtc1      $v0, $f2
/* 3DE1E4 E00E41E4 00000000 */  nop
/* 3DE1E8 E00E41E8 468010A0 */  cvt.s.w   $f2, $f2
/* 3DE1EC E00E41EC 08039083 */  j         .LE00E420C
/* 3DE1F0 E00E41F0 46020083 */   div.s    $f2, $f0, $f2
.LE00E41F4:
/* 3DE1F4 E00E41F4 3C0141F0 */  lui       $at, 0x41f0
/* 3DE1F8 E00E41F8 44811000 */  mtc1      $at, $f2
/* 3DE1FC E00E41FC 44820000 */  mtc1      $v0, $f0
/* 3DE200 E00E4200 00000000 */  nop
/* 3DE204 E00E4204 46800020 */  cvt.s.w   $f0, $f0
/* 3DE208 E00E4208 46001083 */  div.s     $f2, $f2, $f0
.LE00E420C:
/* 3DE20C E00E420C 24030001 */  addiu     $v1, $zero, 1
/* 3DE210 E00E4210 0071102A */  slt       $v0, $v1, $s1
/* 3DE214 E00E4214 10400010 */  beqz      $v0, .LE00E4258
/* 3DE218 E00E4218 26100064 */   addiu    $s0, $s0, 0x64
.LE00E421C:
/* 3DE21C E00E421C 44830000 */  mtc1      $v1, $f0
/* 3DE220 E00E4220 00000000 */  nop
/* 3DE224 E00E4224 46800020 */  cvt.s.w   $f0, $f0
/* 3DE228 E00E4228 46000007 */  neg.s     $f0, $f0
/* 3DE22C E00E422C 46020002 */  mul.s     $f0, $f0, $f2
/* 3DE230 E00E4230 00000000 */  nop
/* 3DE234 E00E4234 24630001 */  addiu     $v1, $v1, 1
/* 3DE238 E00E4238 4600010D */  trunc.w.s $f4, $f0
/* 3DE23C E00E423C 44022000 */  mfc1      $v0, $f4
/* 3DE240 E00E4240 00000000 */  nop
/* 3DE244 E00E4244 2442FFFF */  addiu     $v0, $v0, -1
/* 3DE248 E00E4248 AE02002C */  sw        $v0, 0x2c($s0)
/* 3DE24C E00E424C 0071102A */  slt       $v0, $v1, $s1
/* 3DE250 E00E4250 1440FFF2 */  bnez      $v0, .LE00E421C
/* 3DE254 E00E4254 26100064 */   addiu    $s0, $s0, 0x64
.LE00E4258:
/* 3DE258 E00E4258 0260102D */  daddu     $v0, $s3, $zero
/* 3DE25C E00E425C 8FBF003C */  lw        $ra, 0x3c($sp)
/* 3DE260 E00E4260 8FB40038 */  lw        $s4, 0x38($sp)
/* 3DE264 E00E4264 8FB30034 */  lw        $s3, 0x34($sp)
/* 3DE268 E00E4268 8FB20030 */  lw        $s2, 0x30($sp)
/* 3DE26C E00E426C 8FB1002C */  lw        $s1, 0x2c($sp)
/* 3DE270 E00E4270 8FB00028 */  lw        $s0, 0x28($sp)
/* 3DE274 E00E4274 D7B80050 */  ldc1      $f24, 0x50($sp)
/* 3DE278 E00E4278 D7B60048 */  ldc1      $f22, 0x48($sp)
/* 3DE27C E00E427C D7B40040 */  ldc1      $f20, 0x40($sp)
/* 3DE280 E00E4280 03E00008 */  jr        $ra
/* 3DE284 E00E4284 27BD0058 */   addiu    $sp, $sp, 0x58
