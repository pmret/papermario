.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80243250_A9C7E0
.double 180.0

glabel D_80243258_A9C7E8
.double 90.0

glabel D_80243260_A9C7F0
.double 1.2

.section .text

glabel func_80240C08_A9A198
/* A9A198 80240C08 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* A9A19C 80240C0C AFB3003C */  sw        $s3, 0x3c($sp)
/* A9A1A0 80240C10 0080982D */  daddu     $s3, $a0, $zero
/* A9A1A4 80240C14 AFB40040 */  sw        $s4, 0x40($sp)
/* A9A1A8 80240C18 0000A02D */  daddu     $s4, $zero, $zero
/* A9A1AC 80240C1C 3C03800A */  lui       $v1, %hi(gCurrentCamID)
/* A9A1B0 80240C20 8463A634 */  lh        $v1, %lo(gCurrentCamID)($v1)
/* A9A1B4 80240C24 3C04800B */  lui       $a0, %hi(gCameras)
/* A9A1B8 80240C28 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* A9A1BC 80240C2C AFBF0044 */  sw        $ra, 0x44($sp)
/* A9A1C0 80240C30 AFB20038 */  sw        $s2, 0x38($sp)
/* A9A1C4 80240C34 AFB10034 */  sw        $s1, 0x34($sp)
/* A9A1C8 80240C38 AFB00030 */  sw        $s0, 0x30($sp)
/* A9A1CC 80240C3C F7B80058 */  sdc1      $f24, 0x58($sp)
/* A9A1D0 80240C40 F7B60050 */  sdc1      $f22, 0x50($sp)
/* A9A1D4 80240C44 F7B40048 */  sdc1      $f20, 0x48($sp)
/* A9A1D8 80240C48 8E710148 */  lw        $s1, 0x148($s3)
/* A9A1DC 80240C4C 00031080 */  sll       $v0, $v1, 2
/* A9A1E0 80240C50 00431021 */  addu      $v0, $v0, $v1
/* A9A1E4 80240C54 00021080 */  sll       $v0, $v0, 2
/* A9A1E8 80240C58 00431023 */  subu      $v0, $v0, $v1
/* A9A1EC 80240C5C 000218C0 */  sll       $v1, $v0, 3
/* A9A1F0 80240C60 00431021 */  addu      $v0, $v0, $v1
/* A9A1F4 80240C64 000210C0 */  sll       $v0, $v0, 3
/* A9A1F8 80240C68 10A00002 */  beqz      $a1, .L80240C74
/* A9A1FC 80240C6C 00449021 */   addu     $s2, $v0, $a0
/* A9A200 80240C70 AE600070 */  sw        $zero, 0x70($s3)
.L80240C74:
/* A9A204 80240C74 0C00FB5A */  jal       get_enemy_safe
/* A9A208 80240C78 86240008 */   lh       $a0, 8($s1)
/* A9A20C 80240C7C 14400006 */  bnez      $v0, .L80240C98
/* A9A210 80240C80 24020005 */   addiu    $v0, $zero, 5
/* A9A214 80240C84 0260202D */  daddu     $a0, $s3, $zero
/* A9A218 80240C88 3C05FE36 */  lui       $a1, 0xfe36
/* A9A21C 80240C8C 34A53C80 */  ori       $a1, $a1, 0x3c80
/* A9A220 80240C90 080903FE */  j         .L80240FF8
/* A9A224 80240C94 0000302D */   daddu    $a2, $zero, $zero
.L80240C98:
/* A9A228 80240C98 8E23006C */  lw        $v1, 0x6c($s1)
/* A9A22C 80240C9C 14620005 */  bne       $v1, $v0, .L80240CB4
/* A9A230 80240CA0 0260202D */   daddu    $a0, $s3, $zero
/* A9A234 80240CA4 3C05FE36 */  lui       $a1, 0xfe36
/* A9A238 80240CA8 34A53C80 */  ori       $a1, $a1, 0x3c80
/* A9A23C 80240CAC 080903FE */  j         .L80240FF8
/* A9A240 80240CB0 0000302D */   daddu    $a2, $zero, $zero
.L80240CB4:
/* A9A244 80240CB4 86240008 */  lh        $a0, 8($s1)
/* A9A248 80240CB8 0C00FB5A */  jal       get_enemy_safe
/* A9A24C 80240CBC 00000000 */   nop
/* A9A250 80240CC0 14400005 */  bnez      $v0, .L80240CD8
/* A9A254 80240CC4 0260202D */   daddu    $a0, $s3, $zero
/* A9A258 80240CC8 3C05FE36 */  lui       $a1, 0xfe36
/* A9A25C 80240CCC 34A53C80 */  ori       $a1, $a1, 0x3c80
/* A9A260 80240CD0 080903FE */  j         .L80240FF8
/* A9A264 80240CD4 0000302D */   daddu    $a2, $zero, $zero
.L80240CD8:
/* A9A268 80240CD8 86240008 */  lh        $a0, 8($s1)
/* A9A26C 80240CDC 0C00EABB */  jal       get_npc_unsafe
/* A9A270 80240CE0 00000000 */   nop
/* A9A274 80240CE4 8E630070 */  lw        $v1, 0x70($s3)
/* A9A278 80240CE8 10600006 */  beqz      $v1, .L80240D04
/* A9A27C 80240CEC 0040802D */   daddu    $s0, $v0, $zero
/* A9A280 80240CF0 24020001 */  addiu     $v0, $zero, 1
/* A9A284 80240CF4 1062003F */  beq       $v1, $v0, .L80240DF4
/* A9A288 80240CF8 0000102D */   daddu    $v0, $zero, $zero
/* A9A28C 80240CFC 0809040E */  j         .L80241038
/* A9A290 80240D00 00000000 */   nop
.L80240D04:
/* A9A294 80240D04 AFA00010 */  sw        $zero, 0x10($sp)
/* A9A298 80240D08 AFA00014 */  sw        $zero, 0x14($sp)
/* A9A29C 80240D0C 8E050038 */  lw        $a1, 0x38($s0)
/* A9A2A0 80240D10 8E06003C */  lw        $a2, 0x3c($s0)
/* A9A2A4 80240D14 8E070040 */  lw        $a3, 0x40($s0)
/* A9A2A8 80240D18 0C01BECC */  jal       fx_walk
/* A9A2AC 80240D1C 24040002 */   addiu    $a0, $zero, 2
/* A9A2B0 80240D20 C64C006C */  lwc1      $f12, 0x6c($s2)
/* A9A2B4 80240D24 0C00A6C9 */  jal       clamp_angle
/* A9A2B8 80240D28 00000000 */   nop
/* A9A2BC 80240D2C 3C018024 */  lui       $at, %hi(D_80243250_A9C7E0)
/* A9A2C0 80240D30 D4383250 */  ldc1      $f24, %lo(D_80243250_A9C7E0)($at)
/* A9A2C4 80240D34 46000521 */  cvt.d.s   $f20, $f0
/* A9A2C8 80240D38 4638A300 */  add.d     $f12, $f20, $f24
/* A9A2CC 80240D3C 3C018024 */  lui       $at, %hi(D_80243258_A9C7E8)
/* A9A2D0 80240D40 D4363258 */  ldc1      $f22, %lo(D_80243258_A9C7E8)($at)
/* A9A2D4 80240D44 0C00A6C9 */  jal       clamp_angle
/* A9A2D8 80240D48 46206320 */   cvt.s.d  $f12, $f12
/* A9A2DC 80240D4C 4636A500 */  add.d     $f20, $f20, $f22
/* A9A2E0 80240D50 4620A320 */  cvt.s.d   $f12, $f20
/* A9A2E4 80240D54 0C00A6C9 */  jal       clamp_angle
/* A9A2E8 80240D58 46000506 */   mov.s    $f20, $f0
/* A9A2EC 80240D5C 4600A521 */  cvt.d.s   $f20, $f20
/* A9A2F0 80240D60 4636A500 */  add.d     $f20, $f20, $f22
/* A9A2F4 80240D64 46000586 */  mov.s     $f22, $f0
/* A9A2F8 80240D68 0C00A6C9 */  jal       clamp_angle
/* A9A2FC 80240D6C 4620A320 */   cvt.s.d  $f12, $f20
/* A9A300 80240D70 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* A9A304 80240D74 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* A9A308 80240D78 C64C006C */  lwc1      $f12, 0x6c($s2)
/* A9A30C 80240D7C C44E0084 */  lwc1      $f14, 0x84($v0)
/* A9A310 80240D80 0C00A70A */  jal       get_clamped_angle_diff
/* A9A314 80240D84 46000506 */   mov.s    $f20, $f0
/* A9A318 80240D88 0C00A6C9 */  jal       clamp_angle
/* A9A31C 80240D8C 46000306 */   mov.s    $f12, $f0
/* A9A320 80240D90 46000021 */  cvt.d.s   $f0, $f0
/* A9A324 80240D94 4638003C */  c.lt.d    $f0, $f24
/* A9A328 80240D98 00000000 */  nop
/* A9A32C 80240D9C 45020002 */  bc1fl     .L80240DA8
/* A9A330 80240DA0 E614000C */   swc1     $f20, 0xc($s0)
/* A9A334 80240DA4 E616000C */  swc1      $f22, 0xc($s0)
.L80240DA8:
/* A9A338 80240DA8 C6000018 */  lwc1      $f0, 0x18($s0)
/* A9A33C 80240DAC 3C018024 */  lui       $at, %hi(D_80243260_A9C7F0)
/* A9A340 80240DB0 D4223260 */  ldc1      $f2, %lo(D_80243260_A9C7F0)($at)
/* A9A344 80240DB4 46000021 */  cvt.d.s   $f0, $f0
/* A9A348 80240DB8 46220002 */  mul.d     $f0, $f0, $f2
/* A9A34C 80240DBC 00000000 */  nop
/* A9A350 80240DC0 3C013F66 */  lui       $at, 0x3f66
/* A9A354 80240DC4 34216666 */  ori       $at, $at, 0x6666
/* A9A358 80240DC8 44812000 */  mtc1      $at, $f4
/* A9A35C 80240DCC 2402001E */  addiu     $v0, $zero, 0x1e
/* A9A360 80240DD0 A602008E */  sh        $v0, 0x8e($s0)
/* A9A364 80240DD4 3C014120 */  lui       $at, 0x4120
/* A9A368 80240DD8 44811000 */  mtc1      $at, $f2
/* A9A36C 80240DDC 24020001 */  addiu     $v0, $zero, 1
/* A9A370 80240DE0 E6040014 */  swc1      $f4, 0x14($s0)
/* A9A374 80240DE4 E602001C */  swc1      $f2, 0x1c($s0)
/* A9A378 80240DE8 46200020 */  cvt.s.d   $f0, $f0
/* A9A37C 80240DEC E6000018 */  swc1      $f0, 0x18($s0)
/* A9A380 80240DF0 AE620070 */  sw        $v0, 0x70($s3)
.L80240DF4:
/* A9A384 80240DF4 C6000038 */  lwc1      $f0, 0x38($s0)
/* A9A388 80240DF8 C602003C */  lwc1      $f2, 0x3c($s0)
/* A9A38C 80240DFC C6040040 */  lwc1      $f4, 0x40($s0)
/* A9A390 80240E00 C6060018 */  lwc1      $f6, 0x18($s0)
/* A9A394 80240E04 0000202D */  daddu     $a0, $zero, $zero
/* A9A398 80240E08 E7A00020 */  swc1      $f0, 0x20($sp)
/* A9A39C 80240E0C E7A20024 */  swc1      $f2, 0x24($sp)
/* A9A3A0 80240E10 E7A40028 */  swc1      $f4, 0x28($sp)
/* A9A3A4 80240E14 E7A60010 */  swc1      $f6, 0x10($sp)
/* A9A3A8 80240E18 C600000C */  lwc1      $f0, 0xc($s0)
/* A9A3AC 80240E1C 27A50020 */  addiu     $a1, $sp, 0x20
/* A9A3B0 80240E20 E7A00014 */  swc1      $f0, 0x14($sp)
/* A9A3B4 80240E24 860200A6 */  lh        $v0, 0xa6($s0)
/* A9A3B8 80240E28 27A60024 */  addiu     $a2, $sp, 0x24
/* A9A3BC 80240E2C 44820000 */  mtc1      $v0, $f0
/* A9A3C0 80240E30 00000000 */  nop
/* A9A3C4 80240E34 46800020 */  cvt.s.w   $f0, $f0
/* A9A3C8 80240E38 E7A00018 */  swc1      $f0, 0x18($sp)
/* A9A3CC 80240E3C 860200A8 */  lh        $v0, 0xa8($s0)
/* A9A3D0 80240E40 27A70028 */  addiu     $a3, $sp, 0x28
/* A9A3D4 80240E44 44820000 */  mtc1      $v0, $f0
/* A9A3D8 80240E48 00000000 */  nop
/* A9A3DC 80240E4C 46800020 */  cvt.s.w   $f0, $f0
/* A9A3E0 80240E50 0C037711 */  jal       npc_test_move_simple_with_slipping
/* A9A3E4 80240E54 E7A0001C */   swc1     $f0, 0x1c($sp)
/* A9A3E8 80240E58 54400007 */  bnel      $v0, $zero, .L80240E78
/* A9A3EC 80240E5C 24140001 */   addiu    $s4, $zero, 1
/* A9A3F0 80240E60 8E050018 */  lw        $a1, 0x18($s0)
/* A9A3F4 80240E64 8E06000C */  lw        $a2, 0xc($s0)
/* A9A3F8 80240E68 0C00EA95 */  jal       npc_move_heading
/* A9A3FC 80240E6C 0200202D */   daddu    $a0, $s0, $zero
/* A9A400 80240E70 0809039F */  j         .L80240E7C
/* A9A404 80240E74 0000902D */   daddu    $s2, $zero, $zero
.L80240E78:
/* A9A408 80240E78 0000902D */  daddu     $s2, $zero, $zero
.L80240E7C:
/* A9A40C 80240E7C C600001C */  lwc1      $f0, 0x1c($s0)
/* A9A410 80240E80 44801000 */  mtc1      $zero, $f2
/* A9A414 80240E84 44801800 */  mtc1      $zero, $f3
/* A9A418 80240E88 46000021 */  cvt.d.s   $f0, $f0
/* A9A41C 80240E8C 4622003C */  c.lt.d    $f0, $f2
/* A9A420 80240E90 00000000 */  nop
/* A9A424 80240E94 45000028 */  bc1f      .L80240F38
/* A9A428 80240E98 27A50020 */   addiu    $a1, $sp, 0x20
/* A9A42C 80240E9C 27A60024 */  addiu     $a2, $sp, 0x24
/* A9A430 80240EA0 27A2002C */  addiu     $v0, $sp, 0x2c
/* A9A434 80240EA4 C602003C */  lwc1      $f2, 0x3c($s0)
/* A9A438 80240EA8 C6060038 */  lwc1      $f6, 0x38($s0)
/* A9A43C 80240EAC 3C01402A */  lui       $at, 0x402a
/* A9A440 80240EB0 4481A800 */  mtc1      $at, $f21
/* A9A444 80240EB4 4480A000 */  mtc1      $zero, $f20
/* A9A448 80240EB8 460010A1 */  cvt.d.s   $f2, $f2
/* A9A44C 80240EBC 46341080 */  add.d     $f2, $f2, $f20
/* A9A450 80240EC0 C600001C */  lwc1      $f0, 0x1c($s0)
/* A9A454 80240EC4 C6040040 */  lwc1      $f4, 0x40($s0)
/* A9A458 80240EC8 46000005 */  abs.s     $f0, $f0
/* A9A45C 80240ECC E7A40028 */  swc1      $f4, 0x28($sp)
/* A9A460 80240ED0 3C014030 */  lui       $at, 0x4030
/* A9A464 80240ED4 44812800 */  mtc1      $at, $f5
/* A9A468 80240ED8 44802000 */  mtc1      $zero, $f4
/* A9A46C 80240EDC 46000021 */  cvt.d.s   $f0, $f0
/* A9A470 80240EE0 E7A60020 */  swc1      $f6, 0x20($sp)
/* A9A474 80240EE4 46240000 */  add.d     $f0, $f0, $f4
/* A9A478 80240EE8 462010A0 */  cvt.s.d   $f2, $f2
/* A9A47C 80240EEC E7A20024 */  swc1      $f2, 0x24($sp)
/* A9A480 80240EF0 46200020 */  cvt.s.d   $f0, $f0
/* A9A484 80240EF4 E7A0002C */  swc1      $f0, 0x2c($sp)
/* A9A488 80240EF8 AFA20010 */  sw        $v0, 0x10($sp)
/* A9A48C 80240EFC 8E040080 */  lw        $a0, 0x80($s0)
/* A9A490 80240F00 0C0372DF */  jal       npc_raycast_down_sides
/* A9A494 80240F04 27A70028 */   addiu    $a3, $sp, 0x28
/* A9A498 80240F08 1040000B */  beqz      $v0, .L80240F38
/* A9A49C 80240F0C 00000000 */   nop
/* A9A4A0 80240F10 C600001C */  lwc1      $f0, 0x1c($s0)
/* A9A4A4 80240F14 C7A2002C */  lwc1      $f2, 0x2c($sp)
/* A9A4A8 80240F18 46000005 */  abs.s     $f0, $f0
/* A9A4AC 80240F1C 46000021 */  cvt.d.s   $f0, $f0
/* A9A4B0 80240F20 46340000 */  add.d     $f0, $f0, $f20
/* A9A4B4 80240F24 460010A1 */  cvt.d.s   $f2, $f2
/* A9A4B8 80240F28 4620103E */  c.le.d    $f2, $f0
/* A9A4BC 80240F2C 00000000 */  nop
/* A9A4C0 80240F30 45030001 */  bc1tl     .L80240F38
/* A9A4C4 80240F34 24120001 */   addiu    $s2, $zero, 1
.L80240F38:
/* A9A4C8 80240F38 56400008 */  bnel      $s2, $zero, .L80240F5C
/* A9A4CC 80240F3C 2414000A */   addiu    $s4, $zero, 0xa
/* A9A4D0 80240F40 C604003C */  lwc1      $f4, 0x3c($s0)
/* A9A4D4 80240F44 C600001C */  lwc1      $f0, 0x1c($s0)
/* A9A4D8 80240F48 46002100 */  add.s     $f4, $f4, $f0
/* A9A4DC 80240F4C C6020014 */  lwc1      $f2, 0x14($s0)
/* A9A4E0 80240F50 46020001 */  sub.s     $f0, $f0, $f2
/* A9A4E4 80240F54 E604003C */  swc1      $f4, 0x3c($s0)
/* A9A4E8 80240F58 E600001C */  swc1      $f0, 0x1c($s0)
.L80240F5C:
/* A9A4EC 80240F5C 9602008E */  lhu       $v0, 0x8e($s0)
/* A9A4F0 80240F60 2442FFFF */  addiu     $v0, $v0, -1
/* A9A4F4 80240F64 A602008E */  sh        $v0, 0x8e($s0)
/* A9A4F8 80240F68 00021400 */  sll       $v0, $v0, 0x10
/* A9A4FC 80240F6C 58400001 */  blezl     $v0, .L80240F74
/* A9A500 80240F70 2414000B */   addiu    $s4, $zero, 0xb
.L80240F74:
/* A9A504 80240F74 12800024 */  beqz      $s4, .L80241008
/* A9A508 80240F78 00000000 */   nop
/* A9A50C 80240F7C AFA00010 */  sw        $zero, 0x10($sp)
/* A9A510 80240F80 AFA00014 */  sw        $zero, 0x14($sp)
/* A9A514 80240F84 8E050038 */  lw        $a1, 0x38($s0)
/* A9A518 80240F88 8E06003C */  lw        $a2, 0x3c($s0)
/* A9A51C 80240F8C 8E070040 */  lw        $a3, 0x40($s0)
/* A9A520 80240F90 0C01BECC */  jal       fx_walk
/* A9A524 80240F94 24040002 */   addiu    $a0, $zero, 2
/* A9A528 80240F98 3C01C47A */  lui       $at, 0xc47a
/* A9A52C 80240F9C 44810000 */  mtc1      $at, $f0
/* A9A530 80240FA0 AE20006C */  sw        $zero, 0x6c($s1)
/* A9A534 80240FA4 8E020000 */  lw        $v0, ($s0)
/* A9A538 80240FA8 0200202D */  daddu     $a0, $s0, $zero
/* A9A53C 80240FAC AE000038 */  sw        $zero, 0x38($s0)
/* A9A540 80240FB0 AE000040 */  sw        $zero, 0x40($s0)
/* A9A544 80240FB4 34420002 */  ori       $v0, $v0, 2
/* A9A548 80240FB8 E600003C */  swc1      $f0, 0x3c($s0)
/* A9A54C 80240FBC 0C00EAFF */  jal       disable_npc_shadow
/* A9A550 80240FC0 AE020000 */   sw       $v0, ($s0)
/* A9A554 80240FC4 0260202D */  daddu     $a0, $s3, $zero
/* A9A558 80240FC8 3C05FE36 */  lui       $a1, 0xfe36
/* A9A55C 80240FCC 34A53C80 */  ori       $a1, $a1, 0x3c80
/* A9A560 80240FD0 24060001 */  addiu     $a2, $zero, 1
/* A9A564 80240FD4 8E020000 */  lw        $v0, ($s0)
/* A9A568 80240FD8 2403F7FF */  addiu     $v1, $zero, -0x801
/* A9A56C 80240FDC 00431024 */  and       $v0, $v0, $v1
/* A9A570 80240FE0 AE020000 */  sw        $v0, ($s0)
/* A9A574 80240FE4 8E220000 */  lw        $v0, ($s1)
/* A9A578 80240FE8 3C031F00 */  lui       $v1, 0x1f00
/* A9A57C 80240FEC 00431025 */  or        $v0, $v0, $v1
/* A9A580 80240FF0 AE220000 */  sw        $v0, ($s1)
/* A9A584 80240FF4 AC800070 */  sw        $zero, 0x70($a0)
.L80240FF8:
/* A9A588 80240FF8 0C0B2026 */  jal       evt_set_variable
/* A9A58C 80240FFC 00000000 */   nop
/* A9A590 80241000 0809040E */  j         .L80241038
/* A9A594 80241004 24020002 */   addiu    $v0, $zero, 2
.L80241008:
/* A9A598 80241008 8E220070 */  lw        $v0, 0x70($s1)
/* A9A59C 8024100C 30420001 */  andi      $v0, $v0, 1
/* A9A5A0 80241010 10400009 */  beqz      $v0, .L80241038
/* A9A5A4 80241014 0000102D */   daddu    $v0, $zero, $zero
/* A9A5A8 80241018 C600004C */  lwc1      $f0, 0x4c($s0)
/* A9A5AC 8024101C 3C01404E */  lui       $at, 0x404e
/* A9A5B0 80241020 44811800 */  mtc1      $at, $f3
/* A9A5B4 80241024 44801000 */  mtc1      $zero, $f2
/* A9A5B8 80241028 46000021 */  cvt.d.s   $f0, $f0
/* A9A5BC 8024102C 46220000 */  add.d     $f0, $f0, $f2
/* A9A5C0 80241030 46200020 */  cvt.s.d   $f0, $f0
/* A9A5C4 80241034 E600004C */  swc1      $f0, 0x4c($s0)
.L80241038:
/* A9A5C8 80241038 8FBF0044 */  lw        $ra, 0x44($sp)
/* A9A5CC 8024103C 8FB40040 */  lw        $s4, 0x40($sp)
/* A9A5D0 80241040 8FB3003C */  lw        $s3, 0x3c($sp)
/* A9A5D4 80241044 8FB20038 */  lw        $s2, 0x38($sp)
/* A9A5D8 80241048 8FB10034 */  lw        $s1, 0x34($sp)
/* A9A5DC 8024104C 8FB00030 */  lw        $s0, 0x30($sp)
/* A9A5E0 80241050 D7B80058 */  ldc1      $f24, 0x58($sp)
/* A9A5E4 80241054 D7B60050 */  ldc1      $f22, 0x50($sp)
/* A9A5E8 80241058 D7B40048 */  ldc1      $f20, 0x48($sp)
/* A9A5EC 8024105C 03E00008 */  jr        $ra
/* A9A5F0 80241060 27BD0060 */   addiu    $sp, $sp, 0x60
