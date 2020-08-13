.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_802D4164
/* 0F8B14 802D4164 3C02802E */  lui   $v0, 0x802e
/* 0F8B18 802D4168 8C42B7C0 */  lw    $v0, -0x4840($v0)
/* 0F8B1C 802D416C 00042080 */  sll   $a0, $a0, 2
/* 0F8B20 802D4170 00822021 */  addu  $a0, $a0, $v0
/* 0F8B24 802D4174 03E00008 */  jr    $ra
/* 0F8B28 802D4178 8C820000 */   lw    $v0, ($a0)

/* 0F8B2C 802D417C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F8B30 802D4180 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F8B34 802D4184 3C12802E */  lui   $s2, 0x802e
/* 0F8B38 802D4188 2652B7C0 */  addiu $s2, $s2, -0x4840
/* 0F8B3C 802D418C AFB10014 */  sw    $s1, 0x14($sp)
/* 0F8B40 802D4190 00048880 */  sll   $s1, $a0, 2
/* 0F8B44 802D4194 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F8B48 802D4198 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F8B4C 802D419C 8E420000 */  lw    $v0, ($s2)
/* 0F8B50 802D41A0 02221021 */  addu  $v0, $s1, $v0
/* 0F8B54 802D41A4 8C500000 */  lw    $s0, ($v0)
/* 0F8B58 802D41A8 0C048338 */  jal   func_80120CE0
/* 0F8B5C 802D41AC 00A0202D */   daddu $a0, $a1, $zero
/* 0F8B60 802D41B0 3C013F80 */  lui   $at, 0x3f80
/* 0F8B64 802D41B4 44810000 */  mtc1  $at, $f0
/* 0F8B68 802D41B8 AE020000 */  sw    $v0, ($s0)
/* 0F8B6C 802D41BC 0040202D */  daddu $a0, $v0, $zero
/* 0F8B70 802D41C0 AE000004 */  sw    $zero, 4($s0)
/* 0F8B74 802D41C4 AE000008 */  sw    $zero, 8($s0)
/* 0F8B78 802D41C8 AE00000C */  sw    $zero, 0xc($s0)
/* 0F8B7C 802D41CC AE000010 */  sw    $zero, 0x10($s0)
/* 0F8B80 802D41D0 AE000014 */  sw    $zero, 0x14($s0)
/* 0F8B84 802D41D4 AE000018 */  sw    $zero, 0x18($s0)
/* 0F8B88 802D41D8 E600001C */  swc1  $f0, 0x1c($s0)
/* 0F8B8C 802D41DC E6000020 */  swc1  $f0, 0x20($s0)
/* 0F8B90 802D41E0 0C0483C1 */  jal   func_80120F04
/* 0F8B94 802D41E4 E6000024 */   swc1  $f0, 0x24($s0)
/* 0F8B98 802D41E8 8E420000 */  lw    $v0, ($s2)
/* 0F8B9C 802D41EC 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F8BA0 802D41F0 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F8BA4 802D41F4 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F8BA8 802D41F8 02228821 */  addu  $s1, $s1, $v0
/* 0F8BAC 802D41FC 8E220000 */  lw    $v0, ($s1)
/* 0F8BB0 802D4200 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F8BB4 802D4204 03E00008 */  jr    $ra
/* 0F8BB8 802D4208 27BD0020 */   addiu $sp, $sp, 0x20

/* 0F8BBC 802D420C 3C03802E */  lui   $v1, 0x802e
/* 0F8BC0 802D4210 8C63B7C0 */  lw    $v1, -0x4840($v1)
/* 0F8BC4 802D4214 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F8BC8 802D4218 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F8BCC 802D421C 0000882D */  daddu $s1, $zero, $zero
/* 0F8BD0 802D4220 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F8BD4 802D4224 AFB00010 */  sw    $s0, 0x10($sp)
.L802D4228:
/* 0F8BD8 802D4228 8C700000 */  lw    $s0, ($v1)
/* 0F8BDC 802D422C 8E020000 */  lw    $v0, ($s0)
/* 0F8BE0 802D4230 04400006 */  bltz  $v0, .L802D424C
/* 0F8BE4 802D4234 2A220040 */   slti  $v0, $s1, 0x40
/* 0F8BE8 802D4238 26310001 */  addiu $s1, $s1, 1
/* 0F8BEC 802D423C 2A220040 */  slti  $v0, $s1, 0x40
/* 0F8BF0 802D4240 1440FFF9 */  bnez  $v0, .L802D4228
/* 0F8BF4 802D4244 24630004 */   addiu $v1, $v1, 4
/* 0F8BF8 802D4248 2A220040 */  slti  $v0, $s1, 0x40
.L802D424C:
/* 0F8BFC 802D424C 50400012 */  beql  $v0, $zero, .L802D4298
/* 0F8C00 802D4250 0000102D */   daddu $v0, $zero, $zero
/* 0F8C04 802D4254 0C048338 */  jal   func_80120CE0
/* 0F8C08 802D4258 00000000 */   nop   
/* 0F8C0C 802D425C 3C013F80 */  lui   $at, 0x3f80
/* 0F8C10 802D4260 44810000 */  mtc1  $at, $f0
/* 0F8C14 802D4264 AE020000 */  sw    $v0, ($s0)
/* 0F8C18 802D4268 0040202D */  daddu $a0, $v0, $zero
/* 0F8C1C 802D426C AE000004 */  sw    $zero, 4($s0)
/* 0F8C20 802D4270 AE000008 */  sw    $zero, 8($s0)
/* 0F8C24 802D4274 AE00000C */  sw    $zero, 0xc($s0)
/* 0F8C28 802D4278 AE000010 */  sw    $zero, 0x10($s0)
/* 0F8C2C 802D427C AE000014 */  sw    $zero, 0x14($s0)
/* 0F8C30 802D4280 AE000018 */  sw    $zero, 0x18($s0)
/* 0F8C34 802D4284 E600001C */  swc1  $f0, 0x1c($s0)
/* 0F8C38 802D4288 E6000020 */  swc1  $f0, 0x20($s0)
/* 0F8C3C 802D428C 0C0483C1 */  jal   func_80120F04
/* 0F8C40 802D4290 E6000024 */   swc1  $f0, 0x24($s0)
/* 0F8C44 802D4294 0220102D */  daddu $v0, $s1, $zero
.L802D4298:
/* 0F8C48 802D4298 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F8C4C 802D429C 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F8C50 802D42A0 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F8C54 802D42A4 03E00008 */  jr    $ra
/* 0F8C58 802D42A8 27BD0020 */   addiu $sp, $sp, 0x20

/* 0F8C5C 802D42AC 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F8C60 802D42B0 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F8C64 802D42B4 0000882D */  daddu $s1, $zero, $zero
/* 0F8C68 802D42B8 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F8C6C 802D42BC 3C12802E */  lui   $s2, 0x802e
/* 0F8C70 802D42C0 2652B7C0 */  addiu $s2, $s2, -0x4840
/* 0F8C74 802D42C4 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F8C78 802D42C8 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F8C7C 802D42CC 8E430000 */  lw    $v1, ($s2)
.L802D42D0:
/* 0F8C80 802D42D0 8C700000 */  lw    $s0, ($v1)
/* 0F8C84 802D42D4 8E020000 */  lw    $v0, ($s0)
/* 0F8C88 802D42D8 04400006 */  bltz  $v0, .L802D42F4
/* 0F8C8C 802D42DC 2A220040 */   slti  $v0, $s1, 0x40
/* 0F8C90 802D42E0 26310001 */  addiu $s1, $s1, 1
/* 0F8C94 802D42E4 2A220040 */  slti  $v0, $s1, 0x40
/* 0F8C98 802D42E8 1440FFF9 */  bnez  $v0, .L802D42D0
/* 0F8C9C 802D42EC 24630004 */   addiu $v1, $v1, 4
/* 0F8CA0 802D42F0 2A220040 */  slti  $v0, $s1, 0x40
.L802D42F4:
/* 0F8CA4 802D42F4 10400015 */  beqz  $v0, .L802D434C
/* 0F8CA8 802D42F8 0000102D */   daddu $v0, $zero, $zero
/* 0F8CAC 802D42FC 0C048379 */  jal   func_80120DE4
/* 0F8CB0 802D4300 00000000 */   nop   
/* 0F8CB4 802D4304 3C013F80 */  lui   $at, 0x3f80
/* 0F8CB8 802D4308 44810000 */  mtc1  $at, $f0
/* 0F8CBC 802D430C AE020000 */  sw    $v0, ($s0)
/* 0F8CC0 802D4310 0040202D */  daddu $a0, $v0, $zero
/* 0F8CC4 802D4314 AE000004 */  sw    $zero, 4($s0)
/* 0F8CC8 802D4318 AE000008 */  sw    $zero, 8($s0)
/* 0F8CCC 802D431C AE00000C */  sw    $zero, 0xc($s0)
/* 0F8CD0 802D4320 AE000010 */  sw    $zero, 0x10($s0)
/* 0F8CD4 802D4324 AE000014 */  sw    $zero, 0x14($s0)
/* 0F8CD8 802D4328 AE000018 */  sw    $zero, 0x18($s0)
/* 0F8CDC 802D432C E600001C */  swc1  $f0, 0x1c($s0)
/* 0F8CE0 802D4330 E6000020 */  swc1  $f0, 0x20($s0)
/* 0F8CE4 802D4334 0C0483C1 */  jal   func_80120F04
/* 0F8CE8 802D4338 E6000024 */   swc1  $f0, 0x24($s0)
/* 0F8CEC 802D433C 8E430000 */  lw    $v1, ($s2)
/* 0F8CF0 802D4340 00111080 */  sll   $v0, $s1, 2
/* 0F8CF4 802D4344 00431021 */  addu  $v0, $v0, $v1
/* 0F8CF8 802D4348 8C420000 */  lw    $v0, ($v0)
.L802D434C:
/* 0F8CFC 802D434C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F8D00 802D4350 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F8D04 802D4354 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F8D08 802D4358 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F8D0C 802D435C 03E00008 */  jr    $ra
/* 0F8D10 802D4360 27BD0020 */   addiu $sp, $sp, 0x20

/* 0F8D14 802D4364 3C02802E */  lui   $v0, 0x802e
/* 0F8D18 802D4368 8C42B7C0 */  lw    $v0, -0x4840($v0)
/* 0F8D1C 802D436C 00042080 */  sll   $a0, $a0, 2
/* 0F8D20 802D4370 00822021 */  addu  $a0, $a0, $v0
/* 0F8D24 802D4374 8C820000 */  lw    $v0, ($a0)
/* 0F8D28 802D4378 44850000 */  mtc1  $a1, $f0
/* 0F8D2C 802D437C 00000000 */  nop   
/* 0F8D30 802D4380 46800020 */  cvt.s.w $f0, $f0
/* 0F8D34 802D4384 E4400004 */  swc1  $f0, 4($v0)
/* 0F8D38 802D4388 44860000 */  mtc1  $a2, $f0
/* 0F8D3C 802D438C 00000000 */  nop   
/* 0F8D40 802D4390 46800020 */  cvt.s.w $f0, $f0
/* 0F8D44 802D4394 E4400008 */  swc1  $f0, 8($v0)
/* 0F8D48 802D4398 44870000 */  mtc1  $a3, $f0
/* 0F8D4C 802D439C 00000000 */  nop   
/* 0F8D50 802D43A0 46800020 */  cvt.s.w $f0, $f0
/* 0F8D54 802D43A4 03E00008 */  jr    $ra
/* 0F8D58 802D43A8 E440000C */   swc1  $f0, 0xc($v0)

/* 0F8D5C 802D43AC 3C02802E */  lui   $v0, 0x802e
/* 0F8D60 802D43B0 8C42B7C0 */  lw    $v0, -0x4840($v0)
/* 0F8D64 802D43B4 00042080 */  sll   $a0, $a0, 2
/* 0F8D68 802D43B8 00822021 */  addu  $a0, $a0, $v0
/* 0F8D6C 802D43BC 8C820000 */  lw    $v0, ($a0)
/* 0F8D70 802D43C0 AC45001C */  sw    $a1, 0x1c($v0)
/* 0F8D74 802D43C4 AC460020 */  sw    $a2, 0x20($v0)
/* 0F8D78 802D43C8 03E00008 */  jr    $ra
/* 0F8D7C 802D43CC AC470024 */   sw    $a3, 0x24($v0)

/* 0F8D80 802D43D0 3C02802E */  lui   $v0, 0x802e
/* 0F8D84 802D43D4 8C42B7C0 */  lw    $v0, -0x4840($v0)
/* 0F8D88 802D43D8 00042080 */  sll   $a0, $a0, 2
/* 0F8D8C 802D43DC 00822021 */  addu  $a0, $a0, $v0
/* 0F8D90 802D43E0 8C820000 */  lw    $v0, ($a0)
/* 0F8D94 802D43E4 AC450010 */  sw    $a1, 0x10($v0)
/* 0F8D98 802D43E8 AC460014 */  sw    $a2, 0x14($v0)
/* 0F8D9C 802D43EC 03E00008 */  jr    $ra
/* 0F8DA0 802D43F0 AC470018 */   sw    $a3, 0x18($v0)

