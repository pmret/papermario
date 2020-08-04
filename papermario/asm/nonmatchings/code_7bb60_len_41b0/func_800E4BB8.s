.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800E4BB8
/* 07E068 800E4BB8 27BDFFA8 */  addiu $sp, $sp, -0x58
/* 07E06C 800E4BBC 3C038011 */  lui   $v1, 0x8011
/* 07E070 800E4BC0 2463EFC8 */  addiu $v1, $v1, -0x1038
/* 07E074 800E4BC4 AFBF0040 */  sw    $ra, 0x40($sp)
/* 07E078 800E4BC8 AFB3003C */  sw    $s3, 0x3c($sp)
/* 07E07C 800E4BCC AFB20038 */  sw    $s2, 0x38($sp)
/* 07E080 800E4BD0 AFB10034 */  sw    $s1, 0x34($sp)
/* 07E084 800E4BD4 AFB00030 */  sw    $s0, 0x30($sp)
/* 07E088 800E4BD8 F7B60050 */  sdc1  $f22, 0x50($sp)
/* 07E08C 800E4BDC F7B40048 */  sdc1  $f20, 0x48($sp)
/* 07E090 800E4BE0 8C620004 */  lw    $v0, 4($v1)
/* 07E094 800E4BE4 30421000 */  andi  $v0, $v0, 0x1000
/* 07E098 800E4BE8 10400005 */  beqz  $v0, .L800E4C00
/* 07E09C 800E4BEC 0060982D */   daddu $s3, $v1, $zero
/* 07E0A0 800E4BF0 0C0393C4 */  jal   func_800E4F10
/* 07E0A4 800E4BF4 00000000 */   nop   
/* 07E0A8 800E4BF8 080393BB */  j     .L800E4EEC
/* 07E0AC 800E4BFC 00000000 */   nop   

.L800E4C00:
/* 07E0B0 800E4C00 C66C0080 */  lwc1  $f12, 0x80($s3)
/* 07E0B4 800E4C04 3C01403E */  lui   $at, 0x403e
/* 07E0B8 800E4C08 4481A800 */  mtc1  $at, $f21
/* 07E0BC 800E4C0C 4480A000 */  mtc1  $zero, $f20
/* 07E0C0 800E4C10 46006321 */  cvt.d.s $f12, $f12
/* 07E0C4 800E4C14 46346301 */  sub.d $f12, $f12, $f20
/* 07E0C8 800E4C18 0C00A6C9 */  jal   clamp_angle
/* 07E0CC 800E4C1C 46206320 */   cvt.s.d $f12, $f12
/* 07E0D0 800E4C20 0000202D */  daddu $a0, $zero, $zero
/* 07E0D4 800E4C24 0260282D */  daddu $a1, $s3, $zero
/* 07E0D8 800E4C28 27B20020 */  addiu $s2, $sp, 0x20
/* 07E0DC 800E4C2C 0240302D */  daddu $a2, $s2, $zero
/* 07E0E0 800E4C30 27B10024 */  addiu $s1, $sp, 0x24
/* 07E0E4 800E4C34 0220382D */  daddu $a3, $s1, $zero
/* 07E0E8 800E4C38 866200B0 */  lh    $v0, 0xb0($s3)
/* 07E0EC 800E4C3C 3C013F40 */  lui   $at, 0x3f40
/* 07E0F0 800E4C40 4481B000 */  mtc1  $at, $f22
/* 07E0F4 800E4C44 44822000 */  mtc1  $v0, $f4
/* 07E0F8 800E4C48 00000000 */  nop   
/* 07E0FC 800E4C4C 46802120 */  cvt.s.w $f4, $f4
/* 07E100 800E4C50 46162102 */  mul.s $f4, $f4, $f22
/* 07E104 800E4C54 00000000 */  nop   
/* 07E108 800E4C58 27B00028 */  addiu $s0, $sp, 0x28
/* 07E10C 800E4C5C C662002C */  lwc1  $f2, 0x2c($s3)
/* 07E110 800E4C60 C6660028 */  lwc1  $f6, 0x28($s3)
/* 07E114 800E4C64 C6680030 */  lwc1  $f8, 0x30($s3)
/* 07E118 800E4C68 46041080 */  add.s $f2, $f2, $f4
/* 07E11C 800E4C6C E7A60020 */  swc1  $f6, 0x20($sp)
/* 07E120 800E4C70 E7A80028 */  swc1  $f8, 0x28($sp)
/* 07E124 800E4C74 E7A20024 */  swc1  $f2, 0x24($sp)
/* 07E128 800E4C78 AFB00010 */  sw    $s0, 0x10($sp)
/* 07E12C 800E4C7C AFA00014 */  sw    $zero, 0x14($sp)
/* 07E130 800E4C80 0C037B01 */  jal   func_800DEC04
/* 07E134 800E4C84 E7A00018 */   swc1  $f0, 0x18($sp)
/* 07E138 800E4C88 C66C0080 */  lwc1  $f12, 0x80($s3)
/* 07E13C 800E4C8C C7A00020 */  lwc1  $f0, 0x20($sp)
/* 07E140 800E4C90 C7A20028 */  lwc1  $f2, 0x28($sp)
/* 07E144 800E4C94 46006321 */  cvt.d.s $f12, $f12
/* 07E148 800E4C98 46346300 */  add.d $f12, $f12, $f20
/* 07E14C 800E4C9C E6600028 */  swc1  $f0, 0x28($s3)
/* 07E150 800E4CA0 E6620030 */  swc1  $f2, 0x30($s3)
/* 07E154 800E4CA4 0C00A6C9 */  jal   clamp_angle
/* 07E158 800E4CA8 46206320 */   cvt.s.d $f12, $f12
/* 07E15C 800E4CAC 0000202D */  daddu $a0, $zero, $zero
/* 07E160 800E4CB0 0260282D */  daddu $a1, $s3, $zero
/* 07E164 800E4CB4 866200B0 */  lh    $v0, 0xb0($s3)
/* 07E168 800E4CB8 0240302D */  daddu $a2, $s2, $zero
/* 07E16C 800E4CBC 44821000 */  mtc1  $v0, $f2
/* 07E170 800E4CC0 00000000 */  nop   
/* 07E174 800E4CC4 468010A0 */  cvt.s.w $f2, $f2
/* 07E178 800E4CC8 46161082 */  mul.s $f2, $f2, $f22
/* 07E17C 800E4CCC 00000000 */  nop   
/* 07E180 800E4CD0 0220382D */  daddu $a3, $s1, $zero
/* 07E184 800E4CD4 C664002C */  lwc1  $f4, 0x2c($s3)
/* 07E188 800E4CD8 C6660028 */  lwc1  $f6, 0x28($s3)
/* 07E18C 800E4CDC C6680030 */  lwc1  $f8, 0x30($s3)
/* 07E190 800E4CE0 46022100 */  add.s $f4, $f4, $f2
/* 07E194 800E4CE4 E7A60020 */  swc1  $f6, 0x20($sp)
/* 07E198 800E4CE8 E7A80028 */  swc1  $f8, 0x28($sp)
/* 07E19C 800E4CEC E7A40024 */  swc1  $f4, 0x24($sp)
/* 07E1A0 800E4CF0 AFB00010 */  sw    $s0, 0x10($sp)
/* 07E1A4 800E4CF4 AFA00014 */  sw    $zero, 0x14($sp)
/* 07E1A8 800E4CF8 0C037B01 */  jal   func_800DEC04
/* 07E1AC 800E4CFC E7A00018 */   swc1  $f0, 0x18($sp)
/* 07E1B0 800E4D00 C66C0080 */  lwc1  $f12, 0x80($s3)
/* 07E1B4 800E4D04 C7A00020 */  lwc1  $f0, 0x20($sp)
/* 07E1B8 800E4D08 C7A20028 */  lwc1  $f2, 0x28($sp)
/* 07E1BC 800E4D0C 46006321 */  cvt.d.s $f12, $f12
/* 07E1C0 800E4D10 46346301 */  sub.d $f12, $f12, $f20
/* 07E1C4 800E4D14 E6600028 */  swc1  $f0, 0x28($s3)
/* 07E1C8 800E4D18 E6620030 */  swc1  $f2, 0x30($s3)
/* 07E1CC 800E4D1C 0C00A6C9 */  jal   clamp_angle
/* 07E1D0 800E4D20 46206320 */   cvt.s.d $f12, $f12
/* 07E1D4 800E4D24 0000202D */  daddu $a0, $zero, $zero
/* 07E1D8 800E4D28 0260282D */  daddu $a1, $s3, $zero
/* 07E1DC 800E4D2C 0240302D */  daddu $a2, $s2, $zero
/* 07E1E0 800E4D30 C6620028 */  lwc1  $f2, 0x28($s3)
/* 07E1E4 800E4D34 C664002C */  lwc1  $f4, 0x2c($s3)
/* 07E1E8 800E4D38 C6660030 */  lwc1  $f6, 0x30($s3)
/* 07E1EC 800E4D3C 0220382D */  daddu $a3, $s1, $zero
/* 07E1F0 800E4D40 E7A20020 */  swc1  $f2, 0x20($sp)
/* 07E1F4 800E4D44 E7A40024 */  swc1  $f4, 0x24($sp)
/* 07E1F8 800E4D48 E7A60028 */  swc1  $f6, 0x28($sp)
/* 07E1FC 800E4D4C AFB00010 */  sw    $s0, 0x10($sp)
/* 07E200 800E4D50 AFA00014 */  sw    $zero, 0x14($sp)
/* 07E204 800E4D54 0C037B01 */  jal   func_800DEC04
/* 07E208 800E4D58 E7A00018 */   swc1  $f0, 0x18($sp)
/* 07E20C 800E4D5C C66C0080 */  lwc1  $f12, 0x80($s3)
/* 07E210 800E4D60 C7A00020 */  lwc1  $f0, 0x20($sp)
/* 07E214 800E4D64 C7A20028 */  lwc1  $f2, 0x28($sp)
/* 07E218 800E4D68 46006321 */  cvt.d.s $f12, $f12
/* 07E21C 800E4D6C 46346300 */  add.d $f12, $f12, $f20
/* 07E220 800E4D70 E6600028 */  swc1  $f0, 0x28($s3)
/* 07E224 800E4D74 E6620030 */  swc1  $f2, 0x30($s3)
/* 07E228 800E4D78 0C00A6C9 */  jal   clamp_angle
/* 07E22C 800E4D7C 46206320 */   cvt.s.d $f12, $f12
/* 07E230 800E4D80 0000202D */  daddu $a0, $zero, $zero
/* 07E234 800E4D84 0260282D */  daddu $a1, $s3, $zero
/* 07E238 800E4D88 0240302D */  daddu $a2, $s2, $zero
/* 07E23C 800E4D8C C6620028 */  lwc1  $f2, 0x28($s3)
/* 07E240 800E4D90 C664002C */  lwc1  $f4, 0x2c($s3)
/* 07E244 800E4D94 C6660030 */  lwc1  $f6, 0x30($s3)
/* 07E248 800E4D98 0220382D */  daddu $a3, $s1, $zero
/* 07E24C 800E4D9C E7A20020 */  swc1  $f2, 0x20($sp)
/* 07E250 800E4DA0 E7A40024 */  swc1  $f4, 0x24($sp)
/* 07E254 800E4DA4 E7A60028 */  swc1  $f6, 0x28($sp)
/* 07E258 800E4DA8 AFB00010 */  sw    $s0, 0x10($sp)
/* 07E25C 800E4DAC AFA00014 */  sw    $zero, 0x14($sp)
/* 07E260 800E4DB0 0C037B01 */  jal   func_800DEC04
/* 07E264 800E4DB4 E7A00018 */   swc1  $f0, 0x18($sp)
/* 07E268 800E4DB8 C66C0080 */  lwc1  $f12, 0x80($s3)
/* 07E26C 800E4DBC C7A20020 */  lwc1  $f2, 0x20($sp)
/* 07E270 800E4DC0 3C018011 */  lui   $at, 0x8011
/* 07E274 800E4DC4 D434BEF0 */  ldc1  $f20, -0x4110($at)
/* 07E278 800E4DC8 C7A00028 */  lwc1  $f0, 0x28($sp)
/* 07E27C 800E4DCC 46006321 */  cvt.d.s $f12, $f12
/* 07E280 800E4DD0 46346300 */  add.d $f12, $f12, $f20
/* 07E284 800E4DD4 E6620028 */  swc1  $f2, 0x28($s3)
/* 07E288 800E4DD8 E6600030 */  swc1  $f0, 0x30($s3)
/* 07E28C 800E4DDC 0C00A6C9 */  jal   clamp_angle
/* 07E290 800E4DE0 46206320 */   cvt.s.d $f12, $f12
/* 07E294 800E4DE4 0000202D */  daddu $a0, $zero, $zero
/* 07E298 800E4DE8 0260282D */  daddu $a1, $s3, $zero
/* 07E29C 800E4DEC 0240302D */  daddu $a2, $s2, $zero
/* 07E2A0 800E4DF0 C6620028 */  lwc1  $f2, 0x28($s3)
/* 07E2A4 800E4DF4 C664002C */  lwc1  $f4, 0x2c($s3)
/* 07E2A8 800E4DF8 C6660030 */  lwc1  $f6, 0x30($s3)
/* 07E2AC 800E4DFC 0220382D */  daddu $a3, $s1, $zero
/* 07E2B0 800E4E00 E7A20020 */  swc1  $f2, 0x20($sp)
/* 07E2B4 800E4E04 E7A40024 */  swc1  $f4, 0x24($sp)
/* 07E2B8 800E4E08 E7A60028 */  swc1  $f6, 0x28($sp)
/* 07E2BC 800E4E0C AFB00010 */  sw    $s0, 0x10($sp)
/* 07E2C0 800E4E10 AFA00014 */  sw    $zero, 0x14($sp)
/* 07E2C4 800E4E14 0C037B01 */  jal   func_800DEC04
/* 07E2C8 800E4E18 E7A00018 */   swc1  $f0, 0x18($sp)
/* 07E2CC 800E4E1C C66C0080 */  lwc1  $f12, 0x80($s3)
/* 07E2D0 800E4E20 C7A00020 */  lwc1  $f0, 0x20($sp)
/* 07E2D4 800E4E24 C7A20028 */  lwc1  $f2, 0x28($sp)
/* 07E2D8 800E4E28 46006321 */  cvt.d.s $f12, $f12
/* 07E2DC 800E4E2C 46346301 */  sub.d $f12, $f12, $f20
/* 07E2E0 800E4E30 E6600028 */  swc1  $f0, 0x28($s3)
/* 07E2E4 800E4E34 E6620030 */  swc1  $f2, 0x30($s3)
/* 07E2E8 800E4E38 0C00A6C9 */  jal   clamp_angle
/* 07E2EC 800E4E3C 46206320 */   cvt.s.d $f12, $f12
/* 07E2F0 800E4E40 0000202D */  daddu $a0, $zero, $zero
/* 07E2F4 800E4E44 0260282D */  daddu $a1, $s3, $zero
/* 07E2F8 800E4E48 0240302D */  daddu $a2, $s2, $zero
/* 07E2FC 800E4E4C C6620028 */  lwc1  $f2, 0x28($s3)
/* 07E300 800E4E50 C664002C */  lwc1  $f4, 0x2c($s3)
/* 07E304 800E4E54 C6660030 */  lwc1  $f6, 0x30($s3)
/* 07E308 800E4E58 0220382D */  daddu $a3, $s1, $zero
/* 07E30C 800E4E5C E7A20020 */  swc1  $f2, 0x20($sp)
/* 07E310 800E4E60 E7A40024 */  swc1  $f4, 0x24($sp)
/* 07E314 800E4E64 E7A60028 */  swc1  $f6, 0x28($sp)
/* 07E318 800E4E68 AFB00010 */  sw    $s0, 0x10($sp)
/* 07E31C 800E4E6C AFA00014 */  sw    $zero, 0x14($sp)
/* 07E320 800E4E70 0C037B01 */  jal   func_800DEC04
/* 07E324 800E4E74 E7A00018 */   swc1  $f0, 0x18($sp)
/* 07E328 800E4E78 C66C0080 */  lwc1  $f12, 0x80($s3)
/* 07E32C 800E4E7C C7A40020 */  lwc1  $f4, 0x20($sp)
/* 07E330 800E4E80 3C018011 */  lui   $at, 0x8011
/* 07E334 800E4E84 D420BEF8 */  ldc1  $f0, -0x4108($at)
/* 07E338 800E4E88 C7A20028 */  lwc1  $f2, 0x28($sp)
/* 07E33C 800E4E8C 46006321 */  cvt.d.s $f12, $f12
/* 07E340 800E4E90 46206300 */  add.d $f12, $f12, $f0
/* 07E344 800E4E94 E6640028 */  swc1  $f4, 0x28($s3)
/* 07E348 800E4E98 E6620030 */  swc1  $f2, 0x30($s3)
/* 07E34C 800E4E9C 0C00A6C9 */  jal   clamp_angle
/* 07E350 800E4EA0 46206320 */   cvt.s.d $f12, $f12
/* 07E354 800E4EA4 0000202D */  daddu $a0, $zero, $zero
/* 07E358 800E4EA8 0260282D */  daddu $a1, $s3, $zero
/* 07E35C 800E4EAC 0240302D */  daddu $a2, $s2, $zero
/* 07E360 800E4EB0 C6620028 */  lwc1  $f2, 0x28($s3)
/* 07E364 800E4EB4 C664002C */  lwc1  $f4, 0x2c($s3)
/* 07E368 800E4EB8 C6660030 */  lwc1  $f6, 0x30($s3)
/* 07E36C 800E4EBC 0220382D */  daddu $a3, $s1, $zero
/* 07E370 800E4EC0 E7A20020 */  swc1  $f2, 0x20($sp)
/* 07E374 800E4EC4 E7A40024 */  swc1  $f4, 0x24($sp)
/* 07E378 800E4EC8 E7A60028 */  swc1  $f6, 0x28($sp)
/* 07E37C 800E4ECC AFB00010 */  sw    $s0, 0x10($sp)
/* 07E380 800E4ED0 AFA00014 */  sw    $zero, 0x14($sp)
/* 07E384 800E4ED4 0C037B01 */  jal   func_800DEC04
/* 07E388 800E4ED8 E7A00018 */   swc1  $f0, 0x18($sp)
/* 07E38C 800E4EDC C7A00020 */  lwc1  $f0, 0x20($sp)
/* 07E390 800E4EE0 C7A20028 */  lwc1  $f2, 0x28($sp)
/* 07E394 800E4EE4 E6600028 */  swc1  $f0, 0x28($s3)
/* 07E398 800E4EE8 E6620030 */  swc1  $f2, 0x30($s3)
.L800E4EEC:
/* 07E39C 800E4EEC 8FBF0040 */  lw    $ra, 0x40($sp)
/* 07E3A0 800E4EF0 8FB3003C */  lw    $s3, 0x3c($sp)
/* 07E3A4 800E4EF4 8FB20038 */  lw    $s2, 0x38($sp)
/* 07E3A8 800E4EF8 8FB10034 */  lw    $s1, 0x34($sp)
/* 07E3AC 800E4EFC 8FB00030 */  lw    $s0, 0x30($sp)
/* 07E3B0 800E4F00 D7B60050 */  ldc1  $f22, 0x50($sp)
/* 07E3B4 800E4F04 D7B40048 */  ldc1  $f20, 0x48($sp)
/* 07E3B8 800E4F08 03E00008 */  jr    $ra
/* 07E3BC 800E4F0C 27BD0058 */   addiu $sp, $sp, 0x58

