.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E006C000
/* 36E1D0 E006C000 27BDFF98 */  addiu     $sp, $sp, -0x68
/* 36E1D4 E006C004 F7B60050 */  sdc1      $f22, 0x50($sp)
/* 36E1D8 E006C008 4485B000 */  mtc1      $a1, $f22
/* 36E1DC E006C00C AFB40040 */  sw        $s4, 0x40($sp)
/* 36E1E0 E006C010 0080A02D */  daddu     $s4, $a0, $zero
/* 36E1E4 E006C014 F7B80058 */  sdc1      $f24, 0x58($sp)
/* 36E1E8 E006C018 4486C000 */  mtc1      $a2, $f24
/* 36E1EC E006C01C 27A40018 */  addiu     $a0, $sp, 0x18
/* 36E1F0 E006C020 F7BA0060 */  sdc1      $f26, 0x60($sp)
/* 36E1F4 E006C024 4487D000 */  mtc1      $a3, $f26
/* 36E1F8 E006C028 3C02E007 */  lui       $v0, %hi(func_E006C298)
/* 36E1FC E006C02C 2442C298 */  addiu     $v0, $v0, %lo(func_E006C298)
/* 36E200 E006C030 AFA20020 */  sw        $v0, 0x20($sp)
/* 36E204 E006C034 3C02E007 */  lui       $v0, %hi(func_E006C2A0)
/* 36E208 E006C038 2442C2A0 */  addiu     $v0, $v0, %lo(func_E006C2A0)
/* 36E20C E006C03C AFA20024 */  sw        $v0, 0x24($sp)
/* 36E210 E006C040 3C02E007 */  lui       $v0, %hi(func_E006C5A0)
/* 36E214 E006C044 2442C5A0 */  addiu     $v0, $v0, %lo(func_E006C5A0)
/* 36E218 E006C048 AFA20028 */  sw        $v0, 0x28($sp)
/* 36E21C E006C04C 24020036 */  addiu     $v0, $zero, 0x36
/* 36E220 E006C050 AFBF0044 */  sw        $ra, 0x44($sp)
/* 36E224 E006C054 AFB3003C */  sw        $s3, 0x3c($sp)
/* 36E228 E006C058 AFB20038 */  sw        $s2, 0x38($sp)
/* 36E22C E006C05C AFB10034 */  sw        $s1, 0x34($sp)
/* 36E230 E006C060 AFB00030 */  sw        $s0, 0x30($sp)
/* 36E234 E006C064 F7B40048 */  sdc1      $f20, 0x48($sp)
/* 36E238 E006C068 AFA00018 */  sw        $zero, 0x18($sp)
/* 36E23C E006C06C AFA0002C */  sw        $zero, 0x2c($sp)
/* 36E240 E006C070 0C080124 */  jal       func_E0200490
/* 36E244 E006C074 AFA2001C */   sw       $v0, 0x1c($sp)
/* 36E248 E006C078 2404004C */  addiu     $a0, $zero, 0x4c
/* 36E24C E006C07C 24030001 */  addiu     $v1, $zero, 1
/* 36E250 E006C080 0040982D */  daddu     $s3, $v0, $zero
/* 36E254 E006C084 0C08012C */  jal       func_E02004B0
/* 36E258 E006C088 AE630008 */   sw       $v1, 8($s3)
/* 36E25C E006C08C 0040802D */  daddu     $s0, $v0, $zero
/* 36E260 E006C090 16000003 */  bnez      $s0, .LE006C0A0
/* 36E264 E006C094 AE62000C */   sw       $v0, 0xc($s3)
.LE006C098:
/* 36E268 E006C098 0801B026 */  j         .LE006C098
/* 36E26C E006C09C 00000000 */   nop
.LE006C0A0:
/* 36E270 E006C0A0 2A820003 */  slti      $v0, $s4, 3
/* 36E274 E006C0A4 AE140000 */  sw        $s4, ($s0)
/* 36E278 E006C0A8 14400003 */  bnez      $v0, .LE006C0B8
/* 36E27C E006C0AC AE000018 */   sw       $zero, 0x18($s0)
/* 36E280 E006C0B0 0801B02F */  j         .LE006C0BC
/* 36E284 E006C0B4 2402001E */   addiu    $v0, $zero, 0x1e
.LE006C0B8:
/* 36E288 E006C0B8 24020064 */  addiu     $v0, $zero, 0x64
.LE006C0BC:
/* 36E28C E006C0BC AE020014 */  sw        $v0, 0x14($s0)
/* 36E290 E006C0C0 241100FF */  addiu     $s1, $zero, 0xff
/* 36E294 E006C0C4 24020004 */  addiu     $v0, $zero, 4
/* 36E298 E006C0C8 AE02003C */  sw        $v0, 0x3c($s0)
/* 36E29C E006C0CC 24020002 */  addiu     $v0, $zero, 2
/* 36E2A0 E006C0D0 26120048 */  addiu     $s2, $s0, 0x48
/* 36E2A4 E006C0D4 AE020040 */  sw        $v0, 0x40($s0)
/* 36E2A8 E006C0D8 2682FFFF */  addiu     $v0, $s4, -1
/* 36E2AC E006C0DC 44800000 */  mtc1      $zero, $f0
/* 36E2B0 E006C0E0 3C014240 */  lui       $at, 0x4240
/* 36E2B4 E006C0E4 44812000 */  mtc1      $at, $f4
/* 36E2B8 E006C0E8 3C014200 */  lui       $at, 0x4200
/* 36E2BC E006C0EC 44811000 */  mtc1      $at, $f2
/* 36E2C0 E006C0F0 3C014100 */  lui       $at, 0x4100
/* 36E2C4 E006C0F4 44813000 */  mtc1      $at, $f6
/* 36E2C8 E006C0F8 2C420002 */  sltiu     $v0, $v0, 2
/* 36E2CC E006C0FC AE110010 */  sw        $s1, 0x10($s0)
/* 36E2D0 E006C100 E6160004 */  swc1      $f22, 4($s0)
/* 36E2D4 E006C104 E6180008 */  swc1      $f24, 8($s0)
/* 36E2D8 E006C108 E61A000C */  swc1      $f26, 0xc($s0)
/* 36E2DC E006C10C AE000048 */  sw        $zero, 0x48($s0)
/* 36E2E0 E006C110 AE000044 */  sw        $zero, 0x44($s0)
/* 36E2E4 E006C114 E6000020 */  swc1      $f0, 0x20($s0)
/* 36E2E8 E006C118 E600001C */  swc1      $f0, 0x1c($s0)
/* 36E2EC E006C11C E604002C */  swc1      $f4, 0x2c($s0)
/* 36E2F0 E006C120 E6020030 */  swc1      $f2, 0x30($s0)
/* 36E2F4 E006C124 E6000028 */  swc1      $f0, 0x28($s0)
/* 36E2F8 E006C128 E6000024 */  swc1      $f0, 0x24($s0)
/* 36E2FC E006C12C E6060034 */  swc1      $f6, 0x34($s0)
/* 36E300 E006C130 10400039 */  beqz      $v0, .LE006C218
/* 36E304 E006C134 E6020038 */   swc1     $f2, 0x38($s0)
/* 36E308 E006C138 24020001 */  addiu     $v0, $zero, 1
/* 36E30C E006C13C 16820019 */  bne       $s4, $v0, .LE006C1A4
/* 36E310 E006C140 00000000 */   nop
/* 36E314 E006C144 0C080150 */  jal       func_E0200540
/* 36E318 E006C148 24040047 */   addiu    $a0, $zero, 0x47
/* 36E31C E006C14C 0000202D */  daddu     $a0, $zero, $zero
/* 36E320 E006C150 3C05C2EC */  lui       $a1, 0xc2ec
/* 36E324 E006C154 3C064338 */  lui       $a2, 0x4338
/* 36E328 E006C158 3C07429E */  lui       $a3, 0x429e
/* 36E32C E006C15C 3C013F80 */  lui       $at, 0x3f80
/* 36E330 E006C160 4481A000 */  mtc1      $at, $f20
/* 36E334 E006C164 2402FFFF */  addiu     $v0, $zero, -1
/* 36E338 E006C168 AFA20014 */  sw        $v0, 0x14($sp)
/* 36E33C E006C16C 0C023800 */  jal       func_E008E000
/* 36E340 E006C170 E7B40010 */   swc1     $f20, 0x10($sp)
/* 36E344 E006C174 2404003C */  addiu     $a0, $zero, 0x3c
/* 36E348 E006C178 0C080150 */  jal       func_E0200540
/* 36E34C E006C17C AE020044 */   sw       $v0, 0x44($s0)
/* 36E350 E006C180 3C05C2F0 */  lui       $a1, 0xc2f0
/* 36E354 E006C184 3C06433D */  lui       $a2, 0x433d
/* 36E358 E006C188 3C07429A */  lui       $a3, 0x429a
/* 36E35C E006C18C 0000202D */  daddu     $a0, $zero, $zero
/* 36E360 E006C190 E7B40010 */  swc1      $f20, 0x10($sp)
/* 36E364 E006C194 0C01E000 */  jal       func_E0078000
/* 36E368 E006C198 AFB20014 */   sw       $s2, 0x14($sp)
/* 36E36C E006C19C 0801B087 */  j         .LE006C21C
/* 36E370 E006C1A0 2A820003 */   slti     $v0, $s4, 3
.LE006C1A4:
/* 36E374 E006C1A4 0C080150 */  jal       func_E0200540
/* 36E378 E006C1A8 24040057 */   addiu    $a0, $zero, 0x57
/* 36E37C E006C1AC 3C05C2F0 */  lui       $a1, 0xc2f0
/* 36E380 E006C1B0 3C06433D */  lui       $a2, 0x433d
/* 36E384 E006C1B4 3C074290 */  lui       $a3, 0x4290
/* 36E388 E006C1B8 3C013F80 */  lui       $at, 0x3f80
/* 36E38C E006C1BC 44810000 */  mtc1      $at, $f0
/* 36E390 E006C1C0 0000202D */  daddu     $a0, $zero, $zero
/* 36E394 E006C1C4 AFA00014 */  sw        $zero, 0x14($sp)
/* 36E398 E006C1C8 0C02B800 */  jal       func_E00AE000
/* 36E39C E006C1CC E7A00010 */   swc1     $f0, 0x10($sp)
/* 36E3A0 E006C1D0 AE020048 */  sw        $v0, 0x48($s0)
/* 36E3A4 E006C1D4 8C42000C */  lw        $v0, 0xc($v0)
/* 36E3A8 E006C1D8 AC510028 */  sw        $s1, 0x28($v0)
/* 36E3AC E006C1DC 8E020048 */  lw        $v0, 0x48($s0)
/* 36E3B0 E006C1E0 8C42000C */  lw        $v0, 0xc($v0)
/* 36E3B4 E006C1E4 AC51002C */  sw        $s1, 0x2c($v0)
/* 36E3B8 E006C1E8 8E020048 */  lw        $v0, 0x48($s0)
/* 36E3BC E006C1EC 8C42000C */  lw        $v0, 0xc($v0)
/* 36E3C0 E006C1F0 AC510030 */  sw        $s1, 0x30($v0)
/* 36E3C4 E006C1F4 8E020048 */  lw        $v0, 0x48($s0)
/* 36E3C8 E006C1F8 8C42000C */  lw        $v0, 0xc($v0)
/* 36E3CC E006C1FC AC510018 */  sw        $s1, 0x18($v0)
/* 36E3D0 E006C200 8E020048 */  lw        $v0, 0x48($s0)
/* 36E3D4 E006C204 8C42000C */  lw        $v0, 0xc($v0)
/* 36E3D8 E006C208 AC40001C */  sw        $zero, 0x1c($v0)
/* 36E3DC E006C20C 8E020048 */  lw        $v0, 0x48($s0)
/* 36E3E0 E006C210 8C42000C */  lw        $v0, 0xc($v0)
/* 36E3E4 E006C214 AC510020 */  sw        $s1, 0x20($v0)
.LE006C218:
/* 36E3E8 E006C218 2A820003 */  slti      $v0, $s4, 3
.LE006C21C:
/* 36E3EC E006C21C 14400012 */  bnez      $v0, .LE006C268
/* 36E3F0 E006C220 0260102D */   daddu    $v0, $s3, $zero
/* 36E3F4 E006C224 0C080150 */  jal       func_E0200540
/* 36E3F8 E006C228 2404004A */   addiu    $a0, $zero, 0x4a
/* 36E3FC E006C22C 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 36E400 E006C230 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 36E404 E006C234 80420070 */  lb        $v0, 0x70($v0)
/* 36E408 E006C238 24040001 */  addiu     $a0, $zero, 1
/* 36E40C E006C23C 50440001 */  beql      $v0, $a0, .LE006C244
/* 36E410 E006C240 24040003 */   addiu    $a0, $zero, 3
.LE006C244:
/* 36E414 E006C244 C7A00078 */  lwc1      $f0, 0x78($sp)
/* 36E418 E006C248 4405B000 */  mfc1      $a1, $f22
/* 36E41C E006C24C 4406C000 */  mfc1      $a2, $f24
/* 36E420 E006C250 4407D000 */  mfc1      $a3, $f26
/* 36E424 E006C254 E7A00010 */  swc1      $f0, 0x10($sp)
/* 36E428 E006C258 C7A0007C */  lwc1      $f0, 0x7c($sp)
/* 36E42C E006C25C 0C025000 */  jal       func_E0094000
/* 36E430 E006C260 E7A00014 */   swc1     $f0, 0x14($sp)
/* 36E434 E006C264 0260102D */  daddu     $v0, $s3, $zero
.LE006C268:
/* 36E438 E006C268 8FBF0044 */  lw        $ra, 0x44($sp)
/* 36E43C E006C26C 8FB40040 */  lw        $s4, 0x40($sp)
/* 36E440 E006C270 8FB3003C */  lw        $s3, 0x3c($sp)
/* 36E444 E006C274 8FB20038 */  lw        $s2, 0x38($sp)
/* 36E448 E006C278 8FB10034 */  lw        $s1, 0x34($sp)
/* 36E44C E006C27C 8FB00030 */  lw        $s0, 0x30($sp)
/* 36E450 E006C280 D7BA0060 */  ldc1      $f26, 0x60($sp)
/* 36E454 E006C284 D7B80058 */  ldc1      $f24, 0x58($sp)
/* 36E458 E006C288 D7B60050 */  ldc1      $f22, 0x50($sp)
/* 36E45C E006C28C D7B40048 */  ldc1      $f20, 0x48($sp)
/* 36E460 E006C290 03E00008 */  jr        $ra
/* 36E464 E006C294 27BD0068 */   addiu    $sp, $sp, 0x68
