.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_79_update
/* 3A0104 E009E1E4 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 3A0108 E009E1E8 AFB20018 */  sw        $s2, 0x18($sp)
/* 3A010C E009E1EC 0080902D */  daddu     $s2, $a0, $zero
/* 3A0110 E009E1F0 AFBF001C */  sw        $ra, 0x1c($sp)
/* 3A0114 E009E1F4 AFB10014 */  sw        $s1, 0x14($sp)
/* 3A0118 E009E1F8 AFB00010 */  sw        $s0, 0x10($sp)
/* 3A011C E009E1FC F7BC0040 */  sdc1      $f28, 0x40($sp)
/* 3A0120 E009E200 F7BA0038 */  sdc1      $f26, 0x38($sp)
/* 3A0124 E009E204 F7B80030 */  sdc1      $f24, 0x30($sp)
/* 3A0128 E009E208 F7B60028 */  sdc1      $f22, 0x28($sp)
/* 3A012C E009E20C F7B40020 */  sdc1      $f20, 0x20($sp)
/* 3A0130 E009E210 8E430000 */  lw        $v1, ($s2)
/* 3A0134 E009E214 8E45000C */  lw        $a1, 0xc($s2)
/* 3A0138 E009E218 30620010 */  andi      $v0, $v1, 0x10
/* 3A013C E009E21C 10400005 */  beqz      $v0, .LE009E234
/* 3A0140 E009E220 2402FFEF */   addiu    $v0, $zero, -0x11
/* 3A0144 E009E224 00621024 */  and       $v0, $v1, $v0
/* 3A0148 E009E228 AE420000 */  sw        $v0, ($s2)
/* 3A014C E009E22C 2402001E */  addiu     $v0, $zero, 0x1e
/* 3A0150 E009E230 ACA20018 */  sw        $v0, 0x18($a1)
.LE009E234:
/* 3A0154 E009E234 8CA30018 */  lw        $v1, 0x18($a1)
/* 3A0158 E009E238 28620064 */  slti      $v0, $v1, 0x64
/* 3A015C E009E23C 10400002 */  beqz      $v0, .LE009E248
/* 3A0160 E009E240 2462FFFF */   addiu    $v0, $v1, -1
/* 3A0164 E009E244 ACA20018 */  sw        $v0, 0x18($a1)
.LE009E248:
/* 3A0168 E009E248 8CA2001C */  lw        $v0, 0x1c($a1)
/* 3A016C E009E24C 8CA40018 */  lw        $a0, 0x18($a1)
/* 3A0170 E009E250 24430001 */  addiu     $v1, $v0, 1
/* 3A0174 E009E254 04810005 */  bgez      $a0, .LE009E26C
/* 3A0178 E009E258 ACA3001C */   sw       $v1, 0x1c($a1)
/* 3A017C E009E25C 0C080128 */  jal       shim_remove_effect
/* 3A0180 E009E260 0240202D */   daddu    $a0, $s2, $zero
/* 3A0184 E009E264 080278EC */  j         .LE009E3B0
/* 3A0188 E009E268 00000000 */   nop
.LE009E26C:
/* 3A018C E009E26C 28620015 */  slti      $v0, $v1, 0x15
/* 3A0190 E009E270 10400003 */  beqz      $v0, .LE009E280
/* 3A0194 E009E274 00031040 */   sll      $v0, $v1, 1
/* 3A0198 E009E278 080278A4 */  j         .LE009E290
/* 3A019C E009E27C 00431021 */   addu     $v0, $v0, $v1
.LE009E280:
/* 3A01A0 E009E280 28820014 */  slti      $v0, $a0, 0x14
/* 3A01A4 E009E284 10400004 */  beqz      $v0, .LE009E298
/* 3A01A8 E009E288 00041040 */   sll      $v0, $a0, 1
/* 3A01AC E009E28C 00441021 */  addu      $v0, $v0, $a0
.LE009E290:
/* 3A01B0 E009E290 00021080 */  sll       $v0, $v0, 2
/* 3A01B4 E009E294 ACA20014 */  sw        $v0, 0x14($a1)
.LE009E298:
/* 3A01B8 E009E298 8E420008 */  lw        $v0, 8($s2)
/* 3A01BC E009E29C 24110001 */  addiu     $s1, $zero, 1
/* 3A01C0 E009E2A0 0222102A */  slt       $v0, $s1, $v0
/* 3A01C4 E009E2A4 10400042 */  beqz      $v0, .LE009E3B0
/* 3A01C8 E009E2A8 24A50034 */   addiu    $a1, $a1, 0x34
/* 3A01CC E009E2AC 24B00020 */  addiu     $s0, $a1, 0x20
/* 3A01D0 E009E2B0 3C01428C */  lui       $at, 0x428c
/* 3A01D4 E009E2B4 4481E000 */  mtc1      $at, $f28
/* 3A01D8 E009E2B8 3C0142B4 */  lui       $at, 0x42b4
/* 3A01DC E009E2BC 4481D000 */  mtc1      $at, $f26
/* 3A01E0 E009E2C0 3C014120 */  lui       $at, 0x4120
/* 3A01E4 E009E2C4 4481C000 */  mtc1      $at, $f24
/* 3A01E8 E009E2C8 3C01437F */  lui       $at, 0x437f
/* 3A01EC E009E2CC 4481B000 */  mtc1      $at, $f22
/* 3A01F0 E009E2D0 3C01E00A */  lui       $at, %hi(D_E009EE10)
/* 3A01F4 E009E2D4 D434EE10 */  ldc1      $f20, %lo(D_E009EE10)($at)
.LE009E2D8:
/* 3A01F8 E009E2D8 C60C000C */  lwc1      $f12, 0xc($s0)
/* 3A01FC E009E2DC 461C6301 */  sub.s     $f12, $f12, $f28
/* 3A0200 E009E2E0 461A6302 */  mul.s     $f12, $f12, $f26
/* 3A0204 E009E2E4 00000000 */  nop
/* 3A0208 E009E2E8 0C080144 */  jal       shim_cos_deg
/* 3A020C E009E2EC 46186303 */   div.s    $f12, $f12, $f24
/* 3A0210 E009E2F0 46160002 */  mul.s     $f0, $f0, $f22
/* 3A0214 E009E2F4 00000000 */  nop
/* 3A0218 E009E2F8 C604000C */  lwc1      $f4, 0xc($s0)
/* 3A021C E009E2FC C6020010 */  lwc1      $f2, 0x10($s0)
/* 3A0220 E009E300 46022100 */  add.s     $f4, $f4, $f2
/* 3A0224 E009E304 3C0142A0 */  lui       $at, 0x42a0
/* 3A0228 E009E308 44811000 */  mtc1      $at, $f2
/* 3A022C E009E30C E604000C */  swc1      $f4, 0xc($s0)
/* 3A0230 E009E310 4604103C */  c.lt.s    $f2, $f4
/* 3A0234 E009E314 4600018D */  trunc.w.s $f6, $f0
/* 3A0238 E009E318 E606FFF4 */  swc1      $f6, -0xc($s0)
/* 3A023C E009E31C 4500001F */  bc1f      .LE009E39C
/* 3A0240 E009E320 2404000F */   addiu    $a0, $zero, 0xf
/* 3A0244 E009E324 3C014270 */  lui       $at, 0x4270
/* 3A0248 E009E328 44810000 */  mtc1      $at, $f0
/* 3A024C E009E32C 0C080138 */  jal       shim_rand_int
/* 3A0250 E009E330 E600000C */   swc1     $f0, 0xc($s0)
/* 3A0254 E009E334 44820000 */  mtc1      $v0, $f0
/* 3A0258 E009E338 00000000 */  nop
/* 3A025C E009E33C 46800021 */  cvt.d.w   $f0, $f0
/* 3A0260 E009E340 46340002 */  mul.d     $f0, $f0, $f20
/* 3A0264 E009E344 00000000 */  nop
/* 3A0268 E009E348 3C01E00A */  lui       $at, %hi(D_E009EE18)
/* 3A026C E009E34C D422EE18 */  ldc1      $f2, %lo(D_E009EE18)($at)
/* 3A0270 E009E350 46220000 */  add.d     $f0, $f0, $f2
/* 3A0274 E009E354 2404000A */  addiu     $a0, $zero, 0xa
/* 3A0278 E009E358 46200020 */  cvt.s.d   $f0, $f0
/* 3A027C E009E35C 0C080138 */  jal       shim_rand_int
/* 3A0280 E009E360 E6000008 */   swc1     $f0, 8($s0)
/* 3A0284 E009E364 44820000 */  mtc1      $v0, $f0
/* 3A0288 E009E368 00000000 */  nop
/* 3A028C E009E36C 46800021 */  cvt.d.w   $f0, $f0
/* 3A0290 E009E370 46340002 */  mul.d     $f0, $f0, $f20
/* 3A0294 E009E374 00000000 */  nop
/* 3A0298 E009E378 46340000 */  add.d     $f0, $f0, $f20
/* 3A029C E009E37C 24040168 */  addiu     $a0, $zero, 0x168
/* 3A02A0 E009E380 46200020 */  cvt.s.d   $f0, $f0
/* 3A02A4 E009E384 0C080138 */  jal       shim_rand_int
/* 3A02A8 E009E388 E6000010 */   swc1     $f0, 0x10($s0)
/* 3A02AC E009E38C 44820000 */  mtc1      $v0, $f0
/* 3A02B0 E009E390 00000000 */  nop
/* 3A02B4 E009E394 46800020 */  cvt.s.w   $f0, $f0
/* 3A02B8 E009E398 E6000000 */  swc1      $f0, ($s0)
.LE009E39C:
/* 3A02BC E009E39C 26310001 */  addiu     $s1, $s1, 1
/* 3A02C0 E009E3A0 8E420008 */  lw        $v0, 8($s2)
/* 3A02C4 E009E3A4 0222102A */  slt       $v0, $s1, $v0
/* 3A02C8 E009E3A8 1440FFCB */  bnez      $v0, .LE009E2D8
/* 3A02CC E009E3AC 26100034 */   addiu    $s0, $s0, 0x34
.LE009E3B0:
/* 3A02D0 E009E3B0 8FBF001C */  lw        $ra, 0x1c($sp)
/* 3A02D4 E009E3B4 8FB20018 */  lw        $s2, 0x18($sp)
/* 3A02D8 E009E3B8 8FB10014 */  lw        $s1, 0x14($sp)
/* 3A02DC E009E3BC 8FB00010 */  lw        $s0, 0x10($sp)
/* 3A02E0 E009E3C0 D7BC0040 */  ldc1      $f28, 0x40($sp)
/* 3A02E4 E009E3C4 D7BA0038 */  ldc1      $f26, 0x38($sp)
/* 3A02E8 E009E3C8 D7B80030 */  ldc1      $f24, 0x30($sp)
/* 3A02EC E009E3CC D7B60028 */  ldc1      $f22, 0x28($sp)
/* 3A02F0 E009E3D0 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 3A02F4 E009E3D4 03E00008 */  jr        $ra
/* 3A02F8 E009E3D8 27BD0048 */   addiu    $sp, $sp, 0x48
