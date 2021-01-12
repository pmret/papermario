.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800E4BB8
/* 7E068 800E4BB8 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 7E06C 800E4BBC 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* 7E070 800E4BC0 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* 7E074 800E4BC4 AFBF0040 */  sw        $ra, 0x40($sp)
/* 7E078 800E4BC8 AFB3003C */  sw        $s3, 0x3c($sp)
/* 7E07C 800E4BCC AFB20038 */  sw        $s2, 0x38($sp)
/* 7E080 800E4BD0 AFB10034 */  sw        $s1, 0x34($sp)
/* 7E084 800E4BD4 AFB00030 */  sw        $s0, 0x30($sp)
/* 7E088 800E4BD8 F7B60050 */  sdc1      $f22, 0x50($sp)
/* 7E08C 800E4BDC F7B40048 */  sdc1      $f20, 0x48($sp)
/* 7E090 800E4BE0 8C620004 */  lw        $v0, 4($v1)
/* 7E094 800E4BE4 30421000 */  andi      $v0, $v0, 0x1000
/* 7E098 800E4BE8 10400005 */  beqz      $v0, .L800E4C00
/* 7E09C 800E4BEC 0060982D */   daddu    $s3, $v1, $zero
/* 7E0A0 800E4BF0 0C0393C4 */  jal       func_800E4F10
/* 7E0A4 800E4BF4 00000000 */   nop
/* 7E0A8 800E4BF8 080393BB */  j         .L800E4EEC
/* 7E0AC 800E4BFC 00000000 */   nop
.L800E4C00:
/* 7E0B0 800E4C00 C66C0080 */  lwc1      $f12, 0x80($s3)
/* 7E0B4 800E4C04 3C01403E */  lui       $at, 0x403e
/* 7E0B8 800E4C08 4481A800 */  mtc1      $at, $f21
/* 7E0BC 800E4C0C 4480A000 */  mtc1      $zero, $f20
/* 7E0C0 800E4C10 46006321 */  cvt.d.s   $f12, $f12
/* 7E0C4 800E4C14 46346301 */  sub.d     $f12, $f12, $f20
/* 7E0C8 800E4C18 0C00A6C9 */  jal       clamp_angle
/* 7E0CC 800E4C1C 46206320 */   cvt.s.d  $f12, $f12
/* 7E0D0 800E4C20 0000202D */  daddu     $a0, $zero, $zero
/* 7E0D4 800E4C24 0260282D */  daddu     $a1, $s3, $zero
/* 7E0D8 800E4C28 27B20020 */  addiu     $s2, $sp, 0x20
/* 7E0DC 800E4C2C 0240302D */  daddu     $a2, $s2, $zero
/* 7E0E0 800E4C30 27B10024 */  addiu     $s1, $sp, 0x24
/* 7E0E4 800E4C34 0220382D */  daddu     $a3, $s1, $zero
/* 7E0E8 800E4C38 866200B0 */  lh        $v0, 0xb0($s3)
/* 7E0EC 800E4C3C 3C013F40 */  lui       $at, 0x3f40
/* 7E0F0 800E4C40 4481B000 */  mtc1      $at, $f22
/* 7E0F4 800E4C44 44822000 */  mtc1      $v0, $f4
/* 7E0F8 800E4C48 00000000 */  nop
/* 7E0FC 800E4C4C 46802120 */  cvt.s.w   $f4, $f4
/* 7E100 800E4C50 46162102 */  mul.s     $f4, $f4, $f22
/* 7E104 800E4C54 00000000 */  nop
/* 7E108 800E4C58 27B00028 */  addiu     $s0, $sp, 0x28
/* 7E10C 800E4C5C C662002C */  lwc1      $f2, 0x2c($s3)
/* 7E110 800E4C60 C6660028 */  lwc1      $f6, 0x28($s3)
/* 7E114 800E4C64 C6680030 */  lwc1      $f8, 0x30($s3)
/* 7E118 800E4C68 46041080 */  add.s     $f2, $f2, $f4
/* 7E11C 800E4C6C E7A60020 */  swc1      $f6, 0x20($sp)
/* 7E120 800E4C70 E7A80028 */  swc1      $f8, 0x28($sp)
/* 7E124 800E4C74 E7A20024 */  swc1      $f2, 0x24($sp)
/* 7E128 800E4C78 AFB00010 */  sw        $s0, 0x10($sp)
/* 7E12C 800E4C7C AFA00014 */  sw        $zero, 0x14($sp)
/* 7E130 800E4C80 0C037B01 */  jal       do_lateral_collision
/* 7E134 800E4C84 E7A00018 */   swc1     $f0, 0x18($sp)
/* 7E138 800E4C88 C66C0080 */  lwc1      $f12, 0x80($s3)
/* 7E13C 800E4C8C C7A00020 */  lwc1      $f0, 0x20($sp)
/* 7E140 800E4C90 C7A20028 */  lwc1      $f2, 0x28($sp)
/* 7E144 800E4C94 46006321 */  cvt.d.s   $f12, $f12
/* 7E148 800E4C98 46346300 */  add.d     $f12, $f12, $f20
/* 7E14C 800E4C9C E6600028 */  swc1      $f0, 0x28($s3)
/* 7E150 800E4CA0 E6620030 */  swc1      $f2, 0x30($s3)
/* 7E154 800E4CA4 0C00A6C9 */  jal       clamp_angle
/* 7E158 800E4CA8 46206320 */   cvt.s.d  $f12, $f12
/* 7E15C 800E4CAC 0000202D */  daddu     $a0, $zero, $zero
/* 7E160 800E4CB0 0260282D */  daddu     $a1, $s3, $zero
/* 7E164 800E4CB4 866200B0 */  lh        $v0, 0xb0($s3)
/* 7E168 800E4CB8 0240302D */  daddu     $a2, $s2, $zero
/* 7E16C 800E4CBC 44821000 */  mtc1      $v0, $f2
/* 7E170 800E4CC0 00000000 */  nop
/* 7E174 800E4CC4 468010A0 */  cvt.s.w   $f2, $f2
/* 7E178 800E4CC8 46161082 */  mul.s     $f2, $f2, $f22
/* 7E17C 800E4CCC 00000000 */  nop
/* 7E180 800E4CD0 0220382D */  daddu     $a3, $s1, $zero
/* 7E184 800E4CD4 C664002C */  lwc1      $f4, 0x2c($s3)
/* 7E188 800E4CD8 C6660028 */  lwc1      $f6, 0x28($s3)
/* 7E18C 800E4CDC C6680030 */  lwc1      $f8, 0x30($s3)
/* 7E190 800E4CE0 46022100 */  add.s     $f4, $f4, $f2
/* 7E194 800E4CE4 E7A60020 */  swc1      $f6, 0x20($sp)
/* 7E198 800E4CE8 E7A80028 */  swc1      $f8, 0x28($sp)
/* 7E19C 800E4CEC E7A40024 */  swc1      $f4, 0x24($sp)
/* 7E1A0 800E4CF0 AFB00010 */  sw        $s0, 0x10($sp)
/* 7E1A4 800E4CF4 AFA00014 */  sw        $zero, 0x14($sp)
/* 7E1A8 800E4CF8 0C037B01 */  jal       do_lateral_collision
/* 7E1AC 800E4CFC E7A00018 */   swc1     $f0, 0x18($sp)
/* 7E1B0 800E4D00 C66C0080 */  lwc1      $f12, 0x80($s3)
/* 7E1B4 800E4D04 C7A00020 */  lwc1      $f0, 0x20($sp)
/* 7E1B8 800E4D08 C7A20028 */  lwc1      $f2, 0x28($sp)
/* 7E1BC 800E4D0C 46006321 */  cvt.d.s   $f12, $f12
/* 7E1C0 800E4D10 46346301 */  sub.d     $f12, $f12, $f20
/* 7E1C4 800E4D14 E6600028 */  swc1      $f0, 0x28($s3)
/* 7E1C8 800E4D18 E6620030 */  swc1      $f2, 0x30($s3)
/* 7E1CC 800E4D1C 0C00A6C9 */  jal       clamp_angle
/* 7E1D0 800E4D20 46206320 */   cvt.s.d  $f12, $f12
/* 7E1D4 800E4D24 0000202D */  daddu     $a0, $zero, $zero
/* 7E1D8 800E4D28 0260282D */  daddu     $a1, $s3, $zero
/* 7E1DC 800E4D2C 0240302D */  daddu     $a2, $s2, $zero
/* 7E1E0 800E4D30 C6620028 */  lwc1      $f2, 0x28($s3)
/* 7E1E4 800E4D34 C664002C */  lwc1      $f4, 0x2c($s3)
/* 7E1E8 800E4D38 C6660030 */  lwc1      $f6, 0x30($s3)
/* 7E1EC 800E4D3C 0220382D */  daddu     $a3, $s1, $zero
/* 7E1F0 800E4D40 E7A20020 */  swc1      $f2, 0x20($sp)
/* 7E1F4 800E4D44 E7A40024 */  swc1      $f4, 0x24($sp)
/* 7E1F8 800E4D48 E7A60028 */  swc1      $f6, 0x28($sp)
/* 7E1FC 800E4D4C AFB00010 */  sw        $s0, 0x10($sp)
/* 7E200 800E4D50 AFA00014 */  sw        $zero, 0x14($sp)
/* 7E204 800E4D54 0C037B01 */  jal       do_lateral_collision
/* 7E208 800E4D58 E7A00018 */   swc1     $f0, 0x18($sp)
/* 7E20C 800E4D5C C66C0080 */  lwc1      $f12, 0x80($s3)
/* 7E210 800E4D60 C7A00020 */  lwc1      $f0, 0x20($sp)
/* 7E214 800E4D64 C7A20028 */  lwc1      $f2, 0x28($sp)
/* 7E218 800E4D68 46006321 */  cvt.d.s   $f12, $f12
/* 7E21C 800E4D6C 46346300 */  add.d     $f12, $f12, $f20
/* 7E220 800E4D70 E6600028 */  swc1      $f0, 0x28($s3)
/* 7E224 800E4D74 E6620030 */  swc1      $f2, 0x30($s3)
/* 7E228 800E4D78 0C00A6C9 */  jal       clamp_angle
/* 7E22C 800E4D7C 46206320 */   cvt.s.d  $f12, $f12
/* 7E230 800E4D80 0000202D */  daddu     $a0, $zero, $zero
/* 7E234 800E4D84 0260282D */  daddu     $a1, $s3, $zero
/* 7E238 800E4D88 0240302D */  daddu     $a2, $s2, $zero
/* 7E23C 800E4D8C C6620028 */  lwc1      $f2, 0x28($s3)
/* 7E240 800E4D90 C664002C */  lwc1      $f4, 0x2c($s3)
/* 7E244 800E4D94 C6660030 */  lwc1      $f6, 0x30($s3)
/* 7E248 800E4D98 0220382D */  daddu     $a3, $s1, $zero
/* 7E24C 800E4D9C E7A20020 */  swc1      $f2, 0x20($sp)
/* 7E250 800E4DA0 E7A40024 */  swc1      $f4, 0x24($sp)
/* 7E254 800E4DA4 E7A60028 */  swc1      $f6, 0x28($sp)
/* 7E258 800E4DA8 AFB00010 */  sw        $s0, 0x10($sp)
/* 7E25C 800E4DAC AFA00014 */  sw        $zero, 0x14($sp)
/* 7E260 800E4DB0 0C037B01 */  jal       do_lateral_collision
/* 7E264 800E4DB4 E7A00018 */   swc1     $f0, 0x18($sp)
/* 7E268 800E4DB8 C66C0080 */  lwc1      $f12, 0x80($s3)
/* 7E26C 800E4DBC C7A20020 */  lwc1      $f2, 0x20($sp)
/* 7E270 800E4DC0 3C018011 */  lui       $at, %hi(D_8010BEF0)
/* 7E274 800E4DC4 D434BEF0 */  ldc1      $f20, %lo(D_8010BEF0)($at)
/* 7E278 800E4DC8 C7A00028 */  lwc1      $f0, 0x28($sp)
/* 7E27C 800E4DCC 46006321 */  cvt.d.s   $f12, $f12
/* 7E280 800E4DD0 46346300 */  add.d     $f12, $f12, $f20
/* 7E284 800E4DD4 E6620028 */  swc1      $f2, 0x28($s3)
/* 7E288 800E4DD8 E6600030 */  swc1      $f0, 0x30($s3)
/* 7E28C 800E4DDC 0C00A6C9 */  jal       clamp_angle
/* 7E290 800E4DE0 46206320 */   cvt.s.d  $f12, $f12
/* 7E294 800E4DE4 0000202D */  daddu     $a0, $zero, $zero
/* 7E298 800E4DE8 0260282D */  daddu     $a1, $s3, $zero
/* 7E29C 800E4DEC 0240302D */  daddu     $a2, $s2, $zero
/* 7E2A0 800E4DF0 C6620028 */  lwc1      $f2, 0x28($s3)
/* 7E2A4 800E4DF4 C664002C */  lwc1      $f4, 0x2c($s3)
/* 7E2A8 800E4DF8 C6660030 */  lwc1      $f6, 0x30($s3)
/* 7E2AC 800E4DFC 0220382D */  daddu     $a3, $s1, $zero
/* 7E2B0 800E4E00 E7A20020 */  swc1      $f2, 0x20($sp)
/* 7E2B4 800E4E04 E7A40024 */  swc1      $f4, 0x24($sp)
/* 7E2B8 800E4E08 E7A60028 */  swc1      $f6, 0x28($sp)
/* 7E2BC 800E4E0C AFB00010 */  sw        $s0, 0x10($sp)
/* 7E2C0 800E4E10 AFA00014 */  sw        $zero, 0x14($sp)
/* 7E2C4 800E4E14 0C037B01 */  jal       do_lateral_collision
/* 7E2C8 800E4E18 E7A00018 */   swc1     $f0, 0x18($sp)
/* 7E2CC 800E4E1C C66C0080 */  lwc1      $f12, 0x80($s3)
/* 7E2D0 800E4E20 C7A00020 */  lwc1      $f0, 0x20($sp)
/* 7E2D4 800E4E24 C7A20028 */  lwc1      $f2, 0x28($sp)
/* 7E2D8 800E4E28 46006321 */  cvt.d.s   $f12, $f12
/* 7E2DC 800E4E2C 46346301 */  sub.d     $f12, $f12, $f20
/* 7E2E0 800E4E30 E6600028 */  swc1      $f0, 0x28($s3)
/* 7E2E4 800E4E34 E6620030 */  swc1      $f2, 0x30($s3)
/* 7E2E8 800E4E38 0C00A6C9 */  jal       clamp_angle
/* 7E2EC 800E4E3C 46206320 */   cvt.s.d  $f12, $f12
/* 7E2F0 800E4E40 0000202D */  daddu     $a0, $zero, $zero
/* 7E2F4 800E4E44 0260282D */  daddu     $a1, $s3, $zero
/* 7E2F8 800E4E48 0240302D */  daddu     $a2, $s2, $zero
/* 7E2FC 800E4E4C C6620028 */  lwc1      $f2, 0x28($s3)
/* 7E300 800E4E50 C664002C */  lwc1      $f4, 0x2c($s3)
/* 7E304 800E4E54 C6660030 */  lwc1      $f6, 0x30($s3)
/* 7E308 800E4E58 0220382D */  daddu     $a3, $s1, $zero
/* 7E30C 800E4E5C E7A20020 */  swc1      $f2, 0x20($sp)
/* 7E310 800E4E60 E7A40024 */  swc1      $f4, 0x24($sp)
/* 7E314 800E4E64 E7A60028 */  swc1      $f6, 0x28($sp)
/* 7E318 800E4E68 AFB00010 */  sw        $s0, 0x10($sp)
/* 7E31C 800E4E6C AFA00014 */  sw        $zero, 0x14($sp)
/* 7E320 800E4E70 0C037B01 */  jal       do_lateral_collision
/* 7E324 800E4E74 E7A00018 */   swc1     $f0, 0x18($sp)
/* 7E328 800E4E78 C66C0080 */  lwc1      $f12, 0x80($s3)
/* 7E32C 800E4E7C C7A40020 */  lwc1      $f4, 0x20($sp)
/* 7E330 800E4E80 3C018011 */  lui       $at, %hi(D_8010BEF8)
/* 7E334 800E4E84 D420BEF8 */  ldc1      $f0, %lo(D_8010BEF8)($at)
/* 7E338 800E4E88 C7A20028 */  lwc1      $f2, 0x28($sp)
/* 7E33C 800E4E8C 46006321 */  cvt.d.s   $f12, $f12
/* 7E340 800E4E90 46206300 */  add.d     $f12, $f12, $f0
/* 7E344 800E4E94 E6640028 */  swc1      $f4, 0x28($s3)
/* 7E348 800E4E98 E6620030 */  swc1      $f2, 0x30($s3)
/* 7E34C 800E4E9C 0C00A6C9 */  jal       clamp_angle
/* 7E350 800E4EA0 46206320 */   cvt.s.d  $f12, $f12
/* 7E354 800E4EA4 0000202D */  daddu     $a0, $zero, $zero
/* 7E358 800E4EA8 0260282D */  daddu     $a1, $s3, $zero
/* 7E35C 800E4EAC 0240302D */  daddu     $a2, $s2, $zero
/* 7E360 800E4EB0 C6620028 */  lwc1      $f2, 0x28($s3)
/* 7E364 800E4EB4 C664002C */  lwc1      $f4, 0x2c($s3)
/* 7E368 800E4EB8 C6660030 */  lwc1      $f6, 0x30($s3)
/* 7E36C 800E4EBC 0220382D */  daddu     $a3, $s1, $zero
/* 7E370 800E4EC0 E7A20020 */  swc1      $f2, 0x20($sp)
/* 7E374 800E4EC4 E7A40024 */  swc1      $f4, 0x24($sp)
/* 7E378 800E4EC8 E7A60028 */  swc1      $f6, 0x28($sp)
/* 7E37C 800E4ECC AFB00010 */  sw        $s0, 0x10($sp)
/* 7E380 800E4ED0 AFA00014 */  sw        $zero, 0x14($sp)
/* 7E384 800E4ED4 0C037B01 */  jal       do_lateral_collision
/* 7E388 800E4ED8 E7A00018 */   swc1     $f0, 0x18($sp)
/* 7E38C 800E4EDC C7A00020 */  lwc1      $f0, 0x20($sp)
/* 7E390 800E4EE0 C7A20028 */  lwc1      $f2, 0x28($sp)
/* 7E394 800E4EE4 E6600028 */  swc1      $f0, 0x28($s3)
/* 7E398 800E4EE8 E6620030 */  swc1      $f2, 0x30($s3)
.L800E4EEC:
/* 7E39C 800E4EEC 8FBF0040 */  lw        $ra, 0x40($sp)
/* 7E3A0 800E4EF0 8FB3003C */  lw        $s3, 0x3c($sp)
/* 7E3A4 800E4EF4 8FB20038 */  lw        $s2, 0x38($sp)
/* 7E3A8 800E4EF8 8FB10034 */  lw        $s1, 0x34($sp)
/* 7E3AC 800E4EFC 8FB00030 */  lw        $s0, 0x30($sp)
/* 7E3B0 800E4F00 D7B60050 */  ldc1      $f22, 0x50($sp)
/* 7E3B4 800E4F04 D7B40048 */  ldc1      $f20, 0x48($sp)
/* 7E3B8 800E4F08 03E00008 */  jr        $ra
/* 7E3BC 800E4F0C 27BD0058 */   addiu    $sp, $sp, 0x58
