.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E001E000
/* 331940 E001E000 27BDFF98 */  addiu     $sp, $sp, -0x68
/* 331944 E001E004 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 331948 E001E008 4485A000 */  mtc1      $a1, $f20
/* 33194C E001E00C F7B60040 */  sdc1      $f22, 0x40($sp)
/* 331950 E001E010 4486B000 */  mtc1      $a2, $f22
/* 331954 E001E014 AFB00028 */  sw        $s0, 0x28($sp)
/* 331958 E001E018 0080802D */  daddu     $s0, $a0, $zero
/* 33195C E001E01C F7BA0050 */  sdc1      $f26, 0x50($sp)
/* 331960 E001E020 4487D000 */  mtc1      $a3, $f26
/* 331964 E001E024 27A40010 */  addiu     $a0, $sp, 0x10
/* 331968 E001E028 F7BE0060 */  sdc1      $f30, 0x60($sp)
/* 33196C E001E02C C7BE0084 */  lwc1      $f30, 0x84($sp)
/* 331970 E001E030 3C02E002 */  lui       $v0, %hi(D_E001E370)
/* 331974 E001E034 2442E370 */  addiu     $v0, $v0, %lo(D_E001E370)
/* 331978 E001E038 AFA20018 */  sw        $v0, 0x18($sp)
/* 33197C E001E03C 3C02E002 */  lui       $v0, %hi(D_E001E378)
/* 331980 E001E040 2442E378 */  addiu     $v0, $v0, %lo(D_E001E378)
/* 331984 E001E044 AFA2001C */  sw        $v0, 0x1c($sp)
/* 331988 E001E048 3C02E002 */  lui       $v0, %hi(D_E001E6E8)
/* 33198C E001E04C 2442E6E8 */  addiu     $v0, $v0, %lo(D_E001E6E8)
/* 331990 E001E050 AFA20020 */  sw        $v0, 0x20($sp)
/* 331994 E001E054 2402000F */  addiu     $v0, $zero, 0xf
/* 331998 E001E058 AFBF0034 */  sw        $ra, 0x34($sp)
/* 33199C E001E05C AFB20030 */  sw        $s2, 0x30($sp)
/* 3319A0 E001E060 AFB1002C */  sw        $s1, 0x2c($sp)
/* 3319A4 E001E064 F7BC0058 */  sdc1      $f28, 0x58($sp)
/* 3319A8 E001E068 F7B80048 */  sdc1      $f24, 0x48($sp)
/* 3319AC E001E06C AFA00010 */  sw        $zero, 0x10($sp)
/* 3319B0 E001E070 AFA00024 */  sw        $zero, 0x24($sp)
/* 3319B4 E001E074 0C080124 */  jal       func_E0200490
/* 3319B8 E001E078 AFA20014 */   sw       $v0, 0x14($sp)
/* 3319BC E001E07C 24040250 */  addiu     $a0, $zero, 0x250
/* 3319C0 E001E080 24030001 */  addiu     $v1, $zero, 1
/* 3319C4 E001E084 0040902D */  daddu     $s2, $v0, $zero
/* 3319C8 E001E088 0C08012C */  jal       func_E02004B0
/* 3319CC E001E08C AE430008 */   sw       $v1, 8($s2)
/* 3319D0 E001E090 0040882D */  daddu     $s1, $v0, $zero
/* 3319D4 E001E094 16200003 */  bnez      $s1, .LE001E0A4
/* 3319D8 E001E098 AE42000C */   sw       $v0, 0xc($s2)
.LE001E09C:
/* 3319DC E001E09C 08007827 */  j         .LE001E09C
/* 3319E0 E001E0A0 00000000 */   nop      
.LE001E0A4:
/* 3319E4 E001E0A4 24020001 */  addiu     $v0, $zero, 1
/* 3319E8 E001E0A8 AE220000 */  sw        $v0, ($s1)
/* 3319EC E001E0AC 24020003 */  addiu     $v0, $zero, 3
/* 3319F0 E001E0B0 E6340004 */  swc1      $f20, 4($s1)
/* 3319F4 E001E0B4 E6360008 */  swc1      $f22, 8($s1)
/* 3319F8 E001E0B8 E63A000C */  swc1      $f26, 0xc($s1)
/* 3319FC E001E0BC AE20001C */  sw        $zero, 0x1c($s1)
/* 331A00 E001E0C0 AE200024 */  sw        $zero, 0x24($s1)
/* 331A04 E001E0C4 AE200028 */  sw        $zero, 0x28($s1)
/* 331A08 E001E0C8 16020011 */  bne       $s0, $v0, .LE001E110
/* 331A0C E001E0CC AE300038 */   sw       $s0, 0x38($s1)
/* 331A10 E001E0D0 3C013E4C */  lui       $at, 0x3e4c
/* 331A14 E001E0D4 3421CCCD */  ori       $at, $at, 0xcccd
/* 331A18 E001E0D8 44810000 */  mtc1      $at, $f0
/* 331A1C E001E0DC 240400FF */  addiu     $a0, $zero, 0xff
/* 331A20 E001E0E0 0C080138 */  jal       func_E02004E0
/* 331A24 E001E0E4 E6200240 */   swc1     $f0, 0x240($s1)
/* 331A28 E001E0E8 241000FF */  addiu     $s0, $zero, 0xff
/* 331A2C E001E0EC 02022023 */  subu      $a0, $s0, $v0
/* 331A30 E001E0F0 0C080138 */  jal       func_E02004E0
/* 331A34 E001E0F4 AE220244 */   sw       $v0, 0x244($s1)
/* 331A38 E001E0F8 8E230244 */  lw        $v1, 0x244($s1)
/* 331A3C E001E0FC 02028023 */  subu      $s0, $s0, $v0
/* 331A40 E001E100 AE220248 */  sw        $v0, 0x248($s1)
/* 331A44 E001E104 02038023 */  subu      $s0, $s0, $v1
/* 331A48 E001E108 0800784D */  j         .LE001E134
/* 331A4C E001E10C AE30024C */   sw       $s0, 0x24c($s1)
.LE001E110:
/* 331A50 E001E110 3C013F00 */  lui       $at, 0x3f00
/* 331A54 E001E114 44810000 */  mtc1      $at, $f0
/* 331A58 E001E118 240200D2 */  addiu     $v0, $zero, 0xd2
/* 331A5C E001E11C AE220244 */  sw        $v0, 0x244($s1)
/* 331A60 E001E120 240200BA */  addiu     $v0, $zero, 0xba
/* 331A64 E001E124 AE220248 */  sw        $v0, 0x248($s1)
/* 331A68 E001E128 2402005A */  addiu     $v0, $zero, 0x5a
/* 331A6C E001E12C AE22024C */  sw        $v0, 0x24c($s1)
/* 331A70 E001E130 E6200240 */  swc1      $f0, 0x240($s1)
.LE001E134:
/* 331A74 E001E134 C7A00078 */  lwc1      $f0, 0x78($sp)
/* 331A78 E001E138 46140601 */  sub.s     $f24, $f0, $f20
/* 331A7C E001E13C 4618C082 */  mul.s     $f2, $f24, $f24
/* 331A80 E001E140 00000000 */  nop       
/* 331A84 E001E144 C7A0007C */  lwc1      $f0, 0x7c($sp)
/* 331A88 E001E148 46160581 */  sub.s     $f22, $f0, $f22
/* 331A8C E001E14C 4616B102 */  mul.s     $f4, $f22, $f22
/* 331A90 E001E150 00000000 */  nop       
/* 331A94 E001E154 C7A00080 */  lwc1      $f0, 0x80($sp)
/* 331A98 E001E158 461A0501 */  sub.s     $f20, $f0, $f26
/* 331A9C E001E15C 4614A002 */  mul.s     $f0, $f20, $f20
/* 331AA0 E001E160 00000000 */  nop       
/* 331AA4 E001E164 46041080 */  add.s     $f2, $f2, $f4
/* 331AA8 E001E168 46001680 */  add.s     $f26, $f2, $f0
/* 331AAC E001E16C 4480E000 */  mtc1      $zero, $f28
/* 331AB0 E001E170 00000000 */  nop       
/* 331AB4 E001E174 461CD032 */  c.eq.s    $f26, $f28
/* 331AB8 E001E178 00000000 */  nop       
/* 331ABC E001E17C 45010005 */  bc1t      .LE001E194
/* 331AC0 E001E180 4600D106 */   mov.s    $f4, $f26
/* 331AC4 E001E184 0C080154 */  jal       func_E0200550
/* 331AC8 E001E188 4600D306 */   mov.s    $f12, $f26
/* 331ACC E001E18C 46000686 */  mov.s     $f26, $f0
/* 331AD0 E001E190 461AF103 */  div.s     $f4, $f30, $f26
.LE001E194:
/* 331AD4 E001E194 4604C002 */  mul.s     $f0, $f24, $f4
/* 331AD8 E001E198 00000000 */  nop       
/* 331ADC E001E19C 4604B082 */  mul.s     $f2, $f22, $f4
/* 331AE0 E001E1A0 00000000 */  nop       
/* 331AE4 E001E1A4 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 331AE8 E001E1A8 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 331AEC E001E1AC 4604A102 */  mul.s     $f4, $f20, $f4
/* 331AF0 E001E1B0 00000000 */  nop       
/* 331AF4 E001E1B4 00031080 */  sll       $v0, $v1, 2
/* 331AF8 E001E1B8 00431021 */  addu      $v0, $v0, $v1
/* 331AFC E001E1BC 00021080 */  sll       $v0, $v0, 2
/* 331B00 E001E1C0 00431023 */  subu      $v0, $v0, $v1
/* 331B04 E001E1C4 000218C0 */  sll       $v1, $v0, 3
/* 331B08 E001E1C8 00431021 */  addu      $v0, $v0, $v1
/* 331B0C E001E1CC 000210C0 */  sll       $v0, $v0, 3
/* 331B10 E001E1D0 E6200010 */  swc1      $f0, 0x10($s1)
/* 331B14 E001E1D4 E6220014 */  swc1      $f2, 0x14($s1)
/* 331B18 E001E1D8 E6240018 */  swc1      $f4, 0x18($s1)
/* 331B1C E001E1DC 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* 331B20 E001E1E0 00220821 */  addu      $at, $at, $v0
/* 331B24 E001E1E4 C4341DEC */  lwc1      $f20, %lo(D_800B1DEC)($at)
/* 331B28 E001E1E8 0C080144 */  jal       func_E0200510
/* 331B2C E001E1EC 4600A306 */   mov.s    $f12, $f20
/* 331B30 E001E1F0 4600A306 */  mov.s     $f12, $f20
/* 331B34 E001E1F4 0C080140 */  jal       func_E0200500
/* 331B38 E001E1F8 46000587 */   neg.s    $f22, $f0
/* 331B3C E001E1FC C6240010 */  lwc1      $f4, 0x10($s1)
/* 331B40 E001E200 4604B102 */  mul.s     $f4, $f22, $f4
/* 331B44 E001E204 00000000 */  nop       
/* 331B48 E001E208 C6220018 */  lwc1      $f2, 0x18($s1)
/* 331B4C E001E20C 46000507 */  neg.s     $f20, $f0
/* 331B50 E001E210 4602A082 */  mul.s     $f2, $f20, $f2
/* 331B54 E001E214 00000000 */  nop       
/* 331B58 E001E218 46042102 */  mul.s     $f4, $f4, $f4
/* 331B5C E001E21C 00000000 */  nop       
/* 331B60 E001E220 46021082 */  mul.s     $f2, $f2, $f2
/* 331B64 E001E224 00000000 */  nop       
/* 331B68 E001E228 46022300 */  add.s     $f12, $f4, $f2
/* 331B6C E001E22C 461C6032 */  c.eq.s    $f12, $f28
/* 331B70 E001E230 00000000 */  nop       
/* 331B74 E001E234 45010004 */  bc1t      .LE001E248
/* 331B78 E001E238 00000000 */   nop      
/* 331B7C E001E23C 0C080154 */  jal       func_E0200550
/* 331B80 E001E240 00000000 */   nop      
/* 331B84 E001E244 46000306 */  mov.s     $f12, $f0
.LE001E248:
/* 331B88 E001E248 C6220010 */  lwc1      $f2, 0x10($s1)
/* 331B8C E001E24C 4602B082 */  mul.s     $f2, $f22, $f2
/* 331B90 E001E250 00000000 */  nop       
/* 331B94 E001E254 C6200018 */  lwc1      $f0, 0x18($s1)
/* 331B98 E001E258 4600A002 */  mul.s     $f0, $f20, $f0
/* 331B9C E001E25C 00000000 */  nop       
/* 331BA0 E001E260 46001080 */  add.s     $f2, $f2, $f0
/* 331BA4 E001E264 461C103C */  c.lt.s    $f2, $f28
/* 331BA8 E001E268 00000000 */  nop       
/* 331BAC E001E26C 45000005 */  bc1f      .LE001E284
/* 331BB0 E001E270 00000000 */   nop      
/* 331BB4 E001E274 3C01C1A0 */  lui       $at, 0xc1a0
/* 331BB8 E001E278 44810000 */  mtc1      $at, $f0
/* 331BBC E001E27C 080078A4 */  j         .LE001E290
/* 331BC0 E001E280 46006307 */   neg.s    $f12, $f12
.LE001E284:
/* 331BC4 E001E284 3C0141A0 */  lui       $at, 0x41a0
/* 331BC8 E001E288 44810000 */  mtc1      $at, $f0
/* 331BCC E001E28C 00000000 */  nop       
.LE001E290:
/* 331BD0 E001E290 E620002C */  swc1      $f0, 0x2c($s1)
/* 331BD4 E001E294 46006507 */  neg.s     $f20, $f12
/* 331BD8 E001E298 4407A000 */  mfc1      $a3, $f20
/* 331BDC E001E29C C6200014 */  lwc1      $f0, 0x14($s1)
/* 331BE0 E001E2A0 44806000 */  mtc1      $zero, $f12
/* 331BE4 E001E2A4 46000007 */  neg.s     $f0, $f0
/* 331BE8 E001E2A8 44060000 */  mfc1      $a2, $f0
/* 331BEC E001E2AC 0C080148 */  jal       func_E0200520
/* 331BF0 E001E2B0 46006386 */   mov.s    $f14, $f12
/* 331BF4 E001E2B4 461ED083 */  div.s     $f2, $f26, $f30
/* 331BF8 E001E2B8 4600118D */  trunc.w.s $f6, $f2
/* 331BFC E001E2BC E6260030 */  swc1      $f6, 0x30($s1)
/* 331C00 E001E2C0 26300040 */  addiu     $s0, $s1, 0x40
/* 331C04 E001E2C4 8E260008 */  lw        $a2, 8($s1)
/* 331C08 E001E2C8 8E27000C */  lw        $a3, 0xc($s1)
/* 331C0C E001E2CC 8E250004 */  lw        $a1, 4($s1)
/* 331C10 E001E2D0 0200202D */  daddu     $a0, $s0, $zero
/* 331C14 E001E2D4 E6200024 */  swc1      $f0, 0x24($s1)
/* 331C18 E001E2D8 E6200020 */  swc1      $f0, 0x20($s1)
/* 331C1C E001E2DC 0C08010C */  jal       func_E0200430
/* 331C20 E001E2E0 E6340034 */   swc1     $f20, 0x34($s1)
/* 331C24 E001E2E4 24050001 */  addiu     $a1, $zero, 1
/* 331C28 E001E2E8 26260080 */  addiu     $a2, $s1, 0x80
/* 331C2C E001E2EC 0200202D */  daddu     $a0, $s0, $zero
.LE001E2F0:
/* 331C30 E001E2F0 24830040 */  addiu     $v1, $a0, 0x40
/* 331C34 E001E2F4 0200102D */  daddu     $v0, $s0, $zero
.LE001E2F8:
/* 331C38 E001E2F8 8C490000 */  lw        $t1, ($v0)
/* 331C3C E001E2FC 8C4A0004 */  lw        $t2, 4($v0)
/* 331C40 E001E300 8C4B0008 */  lw        $t3, 8($v0)
/* 331C44 E001E304 8C48000C */  lw        $t0, 0xc($v0)
/* 331C48 E001E308 AC690000 */  sw        $t1, ($v1)
/* 331C4C E001E30C AC6A0004 */  sw        $t2, 4($v1)
/* 331C50 E001E310 AC6B0008 */  sw        $t3, 8($v1)
/* 331C54 E001E314 AC68000C */  sw        $t0, 0xc($v1)
/* 331C58 E001E318 24420010 */  addiu     $v0, $v0, 0x10
/* 331C5C E001E31C 1446FFF6 */  bne       $v0, $a2, .LE001E2F8
/* 331C60 E001E320 24630010 */   addiu    $v1, $v1, 0x10
/* 331C64 E001E324 24A50001 */  addiu     $a1, $a1, 1
/* 331C68 E001E328 28A20008 */  slti      $v0, $a1, 8
/* 331C6C E001E32C 1440FFF0 */  bnez      $v0, .LE001E2F0
/* 331C70 E001E330 24840040 */   addiu    $a0, $a0, 0x40
/* 331C74 E001E334 2402FFFF */  addiu     $v0, $zero, -1
/* 331C78 E001E338 AE22003C */  sw        $v0, 0x3c($s1)
/* 331C7C E001E33C 0240102D */  daddu     $v0, $s2, $zero
/* 331C80 E001E340 8FBF0034 */  lw        $ra, 0x34($sp)
/* 331C84 E001E344 8FB20030 */  lw        $s2, 0x30($sp)
/* 331C88 E001E348 8FB1002C */  lw        $s1, 0x2c($sp)
/* 331C8C E001E34C 8FB00028 */  lw        $s0, 0x28($sp)
/* 331C90 E001E350 D7BE0060 */  ldc1      $f30, 0x60($sp)
/* 331C94 E001E354 D7BC0058 */  ldc1      $f28, 0x58($sp)
/* 331C98 E001E358 D7BA0050 */  ldc1      $f26, 0x50($sp)
/* 331C9C E001E35C D7B80048 */  ldc1      $f24, 0x48($sp)
/* 331CA0 E001E360 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 331CA4 E001E364 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 331CA8 E001E368 03E00008 */  jr        $ra
/* 331CAC E001E36C 27BD0068 */   addiu    $sp, $sp, 0x68
