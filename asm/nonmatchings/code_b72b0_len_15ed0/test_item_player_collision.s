.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel test_item_player_collision
/* CA20C 80133B0C 27BDFF90 */  addiu     $sp, $sp, -0x70
/* CA210 80133B10 AFB30034 */  sw        $s3, 0x34($sp)
/* CA214 80133B14 0080982D */  daddu     $s3, $a0, $zero
/* CA218 80133B18 AFB1002C */  sw        $s1, 0x2c($sp)
/* CA21C 80133B1C 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* CA220 80133B20 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* CA224 80133B24 AFB40038 */  sw        $s4, 0x38($sp)
/* CA228 80133B28 3C148011 */  lui       $s4, %hi(D_8010EBB0)
/* CA22C 80133B2C 2694EBB0 */  addiu     $s4, $s4, %lo(D_8010EBB0)
/* CA230 80133B30 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* CA234 80133B34 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* CA238 80133B38 3C04800B */  lui       $a0, %hi(gCameras)
/* CA23C 80133B3C 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* CA240 80133B40 AFBF003C */  sw        $ra, 0x3c($sp)
/* CA244 80133B44 AFB20030 */  sw        $s2, 0x30($sp)
/* CA248 80133B48 AFB00028 */  sw        $s0, 0x28($sp)
/* CA24C 80133B4C F7BE0068 */  sdc1      $f30, 0x68($sp)
/* CA250 80133B50 F7BC0060 */  sdc1      $f28, 0x60($sp)
/* CA254 80133B54 F7BA0058 */  sdc1      $f26, 0x58($sp)
/* CA258 80133B58 F7B80050 */  sdc1      $f24, 0x50($sp)
/* CA25C 80133B5C F7B60048 */  sdc1      $f22, 0x48($sp)
/* CA260 80133B60 F7B40040 */  sdc1      $f20, 0x40($sp)
/* CA264 80133B64 823200B4 */  lb        $s2, 0xb4($s1)
/* CA268 80133B68 00031080 */  sll       $v0, $v1, 2
/* CA26C 80133B6C 00431021 */  addu      $v0, $v0, $v1
/* CA270 80133B70 00021080 */  sll       $v0, $v0, 2
/* CA274 80133B74 00431023 */  subu      $v0, $v0, $v1
/* CA278 80133B78 000218C0 */  sll       $v1, $v0, 3
/* CA27C 80133B7C 00431021 */  addu      $v0, $v0, $v1
/* CA280 80133B80 000210C0 */  sll       $v0, $v0, 3
/* CA284 80133B84 8E630000 */  lw        $v1, ($s3)
/* CA288 80133B88 00448021 */  addu      $s0, $v0, $a0
/* CA28C 80133B8C 30620100 */  andi      $v0, $v1, 0x100
/* CA290 80133B90 10400003 */  beqz      $v0, .L80133BA0
/* CA294 80133B94 2402FEFF */   addiu    $v0, $zero, -0x101
/* CA298 80133B98 0804CFDA */  j         .L80133F68
/* CA29C 80133B9C 00621024 */   and      $v0, $v1, $v0
.L80133BA0:
/* CA2A0 80133BA0 3C03800A */  lui       $v1, %hi(gGameState)
/* CA2A4 80133BA4 8C63A600 */  lw        $v1, %lo(gGameState)($v1)
/* CA2A8 80133BA8 24020002 */  addiu     $v0, $zero, 2
/* CA2AC 80133BAC 10620003 */  beq       $v1, $v0, .L80133BBC
/* CA2B0 80133BB0 00000000 */   nop      
/* CA2B4 80133BB4 146000F6 */  bnez      $v1, .L80133F90
/* CA2B8 80133BB8 0000102D */   daddu    $v0, $zero, $zero
.L80133BBC:
/* CA2BC 80133BBC 3C02800B */  lui       $v0, %hi(gCurrentEncounter)
/* CA2C0 80133BC0 24420F10 */  addiu     $v0, $v0, %lo(gCurrentEncounter)
/* CA2C4 80133BC4 80430005 */  lb        $v1, 5($v0)
/* CA2C8 80133BC8 24020005 */  addiu     $v0, $zero, 5
/* CA2CC 80133BCC 106200EF */  beq       $v1, $v0, .L80133F8C
/* CA2D0 80133BD0 3C020020 */   lui      $v0, 0x20
/* CA2D4 80133BD4 8E630000 */  lw        $v1, ($s3)
/* CA2D8 80133BD8 00621024 */  and       $v0, $v1, $v0
/* CA2DC 80133BDC 144000EC */  bnez      $v0, .L80133F90
/* CA2E0 80133BE0 0000102D */   daddu    $v0, $zero, $zero
/* CA2E4 80133BE4 3C028015 */  lui       $v0, %hi(D_801565A4)
/* CA2E8 80133BE8 844265A4 */  lh        $v0, %lo(D_801565A4)($v0)
/* CA2EC 80133BEC 144000E8 */  bnez      $v0, .L80133F90
/* CA2F0 80133BF0 0000102D */   daddu    $v0, $zero, $zero
/* CA2F4 80133BF4 30620040 */  andi      $v0, $v1, 0x40
/* CA2F8 80133BF8 144000E5 */  bnez      $v0, .L80133F90
/* CA2FC 80133BFC 0000102D */   daddu    $v0, $zero, $zero
/* CA300 80133C00 0C009C64 */  jal       func_80027190
/* CA304 80133C04 00000000 */   nop      
/* CA308 80133C08 144000E1 */  bnez      $v0, .L80133F90
/* CA30C 80133C0C 0000102D */   daddu    $v0, $zero, $zero
/* CA310 80133C10 82820000 */  lb        $v0, ($s4)
/* CA314 80133C14 10400004 */  beqz      $v0, .L80133C28
/* CA318 80133C18 24020009 */   addiu    $v0, $zero, 9
/* CA31C 80133C1C 82830003 */  lb        $v1, 3($s4)
/* CA320 80133C20 106200DB */  beq       $v1, $v0, .L80133F90
/* CA324 80133C24 0000102D */   daddu    $v0, $zero, $zero
.L80133C28:
/* CA328 80133C28 2642FFE3 */  addiu     $v0, $s2, -0x1d
/* CA32C 80133C2C 2C420003 */  sltiu     $v0, $v0, 3
/* CA330 80133C30 10400004 */  beqz      $v0, .L80133C44
/* CA334 80133C34 24020157 */   addiu    $v0, $zero, 0x157
/* CA338 80133C38 86630018 */  lh        $v1, 0x18($s3)
/* CA33C 80133C3C 146200D4 */  bne       $v1, $v0, .L80133F90
/* CA340 80133C40 0000102D */   daddu    $v0, $zero, $zero
.L80133C44:
/* CA344 80133C44 3C02800A */  lui       $v0, %hi(D_8009A650)
/* CA348 80133C48 8C42A650 */  lw        $v0, %lo(D_8009A650)($v0)
/* CA34C 80133C4C 3C030020 */  lui       $v1, 0x20
/* CA350 80133C50 00431024 */  and       $v0, $v0, $v1
/* CA354 80133C54 144000CE */  bnez      $v0, .L80133F90
/* CA358 80133C58 0000102D */   daddu    $v0, $zero, $zero
/* CA35C 80133C5C 962300B0 */  lhu       $v1, 0xb0($s1)
/* CA360 80133C60 862400B2 */  lh        $a0, 0xb2($s1)
/* CA364 80133C64 00031C00 */  sll       $v1, $v1, 0x10
/* CA368 80133C68 00031403 */  sra       $v0, $v1, 0x10
/* CA36C 80133C6C 00031FC2 */  srl       $v1, $v1, 0x1f
/* CA370 80133C70 00431021 */  addu      $v0, $v0, $v1
/* CA374 80133C74 00021043 */  sra       $v0, $v0, 1
/* CA378 80133C78 44823000 */  mtc1      $v0, $f6
/* CA37C 80133C7C 00000000 */  nop       
/* CA380 80133C80 468031A0 */  cvt.s.w   $f6, $f6
/* CA384 80133C84 E7A6001C */  swc1      $f6, 0x1c($sp)
/* CA388 80133C88 C63E0028 */  lwc1      $f30, 0x28($s1)
/* CA38C 80133C8C C63A002C */  lwc1      $f26, 0x2c($s1)
/* CA390 80133C90 C6280030 */  lwc1      $f8, 0x30($s1)
/* CA394 80133C94 0000902D */  daddu     $s2, $zero, $zero
/* CA398 80133C98 04810002 */  bgez      $a0, .L80133CA4
/* CA39C 80133C9C E7A80018 */   swc1     $f8, 0x18($sp)
/* CA3A0 80133CA0 24840003 */  addiu     $a0, $a0, 3
.L80133CA4:
/* CA3A4 80133CA4 00041083 */  sra       $v0, $a0, 2
/* CA3A8 80133CA8 C62E00A8 */  lwc1      $f14, 0xa8($s1)
/* CA3AC 80133CAC 3C014334 */  lui       $at, 0x4334
/* CA3B0 80133CB0 44810000 */  mtc1      $at, $f0
/* CA3B4 80133CB4 44823000 */  mtc1      $v0, $f6
/* CA3B8 80133CB8 00000000 */  nop       
/* CA3BC 80133CBC 468031A0 */  cvt.s.w   $f6, $f6
/* CA3C0 80133CC0 4600703C */  c.lt.s    $f14, $f0
/* CA3C4 80133CC4 00000000 */  nop       
/* CA3C8 80133CC8 45000006 */  bc1f      .L80133CE4
/* CA3CC 80133CCC E7A60020 */   swc1     $f6, 0x20($sp)
/* CA3D0 80133CD0 C600006C */  lwc1      $f0, 0x6c($s0)
/* CA3D4 80133CD4 3C0142B4 */  lui       $at, 0x42b4
/* CA3D8 80133CD8 44816000 */  mtc1      $at, $f12
/* CA3DC 80133CDC 0804CF3E */  j         .L80133CF8
/* CA3E0 80133CE0 460C0301 */   sub.s    $f12, $f0, $f12
.L80133CE4:
/* CA3E4 80133CE4 C600006C */  lwc1      $f0, 0x6c($s0)
/* CA3E8 80133CE8 3C0142B4 */  lui       $at, 0x42b4
/* CA3EC 80133CEC 44816000 */  mtc1      $at, $f12
/* CA3F0 80133CF0 00000000 */  nop       
/* CA3F4 80133CF4 460C0300 */  add.s     $f12, $f0, $f12
.L80133CF8:
/* CA3F8 80133CF8 0C00A6C9 */  jal       clamp_angle
/* CA3FC 80133CFC 00000000 */   nop      
/* CA400 80133D00 46000386 */  mov.s     $f14, $f0
/* CA404 80133D04 C60C006C */  lwc1      $f12, 0x6c($s0)
/* CA408 80133D08 C7A80018 */  lwc1      $f8, 0x18($sp)
/* CA40C 80133D0C E7BE0010 */  swc1      $f30, 0x10($sp)
/* CA410 80133D10 0C00A70A */  jal       get_clamped_angle_diff
/* CA414 80133D14 E7A80014 */   swc1     $f8, 0x14($sp)
/* CA418 80133D18 44801000 */  mtc1      $zero, $f2
/* CA41C 80133D1C 00000000 */  nop       
/* CA420 80133D20 4602003C */  c.lt.s    $f0, $f2
/* CA424 80133D24 00000000 */  nop       
/* CA428 80133D28 4500000F */  bc1f      .L80133D68
/* CA42C 80133D2C E7BA0024 */   swc1     $f26, 0x24($sp)
/* CA430 80133D30 C600006C */  lwc1      $f0, 0x6c($s0)
/* CA434 80133D34 3C0142B4 */  lui       $at, 0x42b4
/* CA438 80133D38 44816000 */  mtc1      $at, $f12
/* CA43C 80133D3C 0C00A6C9 */  jal       clamp_angle
/* CA440 80133D40 460C0301 */   sub.s    $f12, $f0, $f12
/* CA444 80133D44 8E2200A4 */  lw        $v0, 0xa4($s1)
/* CA448 80133D48 3C030100 */  lui       $v1, 0x100
/* CA44C 80133D4C 00431024 */  and       $v0, $v0, $v1
/* CA450 80133D50 10400016 */  beqz      $v0, .L80133DAC
/* CA454 80133D54 27A40010 */   addiu    $a0, $sp, 0x10
/* CA458 80133D58 3C0141F0 */  lui       $at, 0x41f0
/* CA45C 80133D5C 44816000 */  mtc1      $at, $f12
/* CA460 80133D60 0804CF68 */  j         .L80133DA0
/* CA464 80133D64 460C0300 */   add.s    $f12, $f0, $f12
.L80133D68:
/* CA468 80133D68 C600006C */  lwc1      $f0, 0x6c($s0)
/* CA46C 80133D6C 3C0142B4 */  lui       $at, 0x42b4
/* CA470 80133D70 44816000 */  mtc1      $at, $f12
/* CA474 80133D74 0C00A6C9 */  jal       clamp_angle
/* CA478 80133D78 460C0300 */   add.s    $f12, $f0, $f12
/* CA47C 80133D7C 8E2200A4 */  lw        $v0, 0xa4($s1)
/* CA480 80133D80 3C030100 */  lui       $v1, 0x100
/* CA484 80133D84 00431024 */  and       $v0, $v0, $v1
/* CA488 80133D88 10400008 */  beqz      $v0, .L80133DAC
/* CA48C 80133D8C 27A40010 */   addiu    $a0, $sp, 0x10
/* CA490 80133D90 3C0141F0 */  lui       $at, 0x41f0
/* CA494 80133D94 44816000 */  mtc1      $at, $f12
/* CA498 80133D98 00000000 */  nop       
/* CA49C 80133D9C 460C0301 */  sub.s     $f12, $f0, $f12
.L80133DA0:
/* CA4A0 80133DA0 0C00A6C9 */  jal       clamp_angle
/* CA4A4 80133DA4 00000000 */   nop      
/* CA4A8 80133DA8 27A40010 */  addiu     $a0, $sp, 0x10
.L80133DAC:
/* CA4AC 80133DAC 3C0641C0 */  lui       $a2, 0x41c0
/* CA4B0 80133DB0 44070000 */  mfc1      $a3, $f0
/* CA4B4 80133DB4 0C00A7E7 */  jal       add_vec2D_polar
/* CA4B8 80133DB8 27A50014 */   addiu    $a1, $sp, 0x14
/* CA4BC 80133DBC C6760008 */  lwc1      $f22, 8($s3)
/* CA4C0 80133DC0 C674000C */  lwc1      $f20, 0xc($s3)
/* CA4C4 80133DC4 C6780010 */  lwc1      $f24, 0x10($s3)
/* CA4C8 80133DC8 3C014158 */  lui       $at, 0x4158
/* CA4CC 80133DCC 4481E000 */  mtc1      $at, $f28
/* CA4D0 80133DD0 461EB081 */  sub.s     $f2, $f22, $f30
/* CA4D4 80133DD4 46021082 */  mul.s     $f2, $f2, $f2
/* CA4D8 80133DD8 00000000 */  nop       
/* CA4DC 80133DDC C7A60018 */  lwc1      $f6, 0x18($sp)
/* CA4E0 80133DE0 4606C001 */  sub.s     $f0, $f24, $f6
/* CA4E4 80133DE4 46000002 */  mul.s     $f0, $f0, $f0
/* CA4E8 80133DE8 00000000 */  nop       
/* CA4EC 80133DEC 46001300 */  add.s     $f12, $f2, $f0
/* CA4F0 80133DF0 46006104 */  sqrt.s    $f4, $f12
/* CA4F4 80133DF4 46042032 */  c.eq.s    $f4, $f4
/* CA4F8 80133DF8 00000000 */  nop       
/* CA4FC 80133DFC 45010004 */  bc1t      .L80133E10
/* CA500 80133E00 00000000 */   nop      
/* CA504 80133E04 0C0187BC */  jal       sqrtf
/* CA508 80133E08 00000000 */   nop      
/* CA50C 80133E0C 46000106 */  mov.s     $f4, $f0
.L80133E10:
/* CA510 80133E10 C7A80020 */  lwc1      $f8, 0x20($sp)
/* CA514 80133E14 461C4000 */  add.s     $f0, $f8, $f28
/* CA518 80133E18 4604003E */  c.le.s    $f0, $f4
/* CA51C 80133E1C 00000000 */  nop       
/* CA520 80133E20 4501000F */  bc1t      .L80133E60
/* CA524 80133E24 00000000 */   nop      
/* CA528 80133E28 3C0141D8 */  lui       $at, 0x41d8
/* CA52C 80133E2C 44813000 */  mtc1      $at, $f6
/* CA530 80133E30 00000000 */  nop       
/* CA534 80133E34 4606A000 */  add.s     $f0, $f20, $f6
/* CA538 80133E38 461A003C */  c.lt.s    $f0, $f26
/* CA53C 80133E3C 00000000 */  nop       
/* CA540 80133E40 45010007 */  bc1t      .L80133E60
/* CA544 80133E44 00000000 */   nop      
/* CA548 80133E48 C7A8001C */  lwc1      $f8, 0x1c($sp)
/* CA54C 80133E4C 4608D000 */  add.s     $f0, $f26, $f8
/* CA550 80133E50 4614003C */  c.lt.s    $f0, $f20
/* CA554 80133E54 00000000 */  nop       
/* CA558 80133E58 45020001 */  bc1fl     .L80133E60
/* CA55C 80133E5C 24120001 */   addiu    $s2, $zero, 1
.L80133E60:
/* CA560 80133E60 822300B4 */  lb        $v1, 0xb4($s1)
/* CA564 80133E64 24020012 */  addiu     $v0, $zero, 0x12
/* CA568 80133E68 1462002F */  bne       $v1, $v0, .L80133F28
/* CA56C 80133E6C 3C030100 */   lui      $v1, 0x100
/* CA570 80133E70 8E220000 */  lw        $v0, ($s1)
/* CA574 80133E74 00431024 */  and       $v0, $v0, $v1
/* CA578 80133E78 1040002B */  beqz      $v0, .L80133F28
/* CA57C 80133E7C 00000000 */   nop      
/* CA580 80133E80 C7A00010 */  lwc1      $f0, 0x10($sp)
/* CA584 80133E84 4600B081 */  sub.s     $f2, $f22, $f0
/* CA588 80133E88 46021082 */  mul.s     $f2, $f2, $f2
/* CA58C 80133E8C 00000000 */  nop       
/* CA590 80133E90 C7A00014 */  lwc1      $f0, 0x14($sp)
/* CA594 80133E94 4600C001 */  sub.s     $f0, $f24, $f0
/* CA598 80133E98 46000002 */  mul.s     $f0, $f0, $f0
/* CA59C 80133E9C 00000000 */  nop       
/* CA5A0 80133EA0 46001300 */  add.s     $f12, $f2, $f0
/* CA5A4 80133EA4 46006104 */  sqrt.s    $f4, $f12
/* CA5A8 80133EA8 46042032 */  c.eq.s    $f4, $f4
/* CA5AC 80133EAC 00000000 */  nop       
/* CA5B0 80133EB0 45010004 */  bc1t      .L80133EC4
/* CA5B4 80133EB4 00000000 */   nop      
/* CA5B8 80133EB8 0C0187BC */  jal       sqrtf
/* CA5BC 80133EBC 00000000 */   nop      
/* CA5C0 80133EC0 46000106 */  mov.s     $f4, $f0
.L80133EC4:
/* CA5C4 80133EC4 3C014160 */  lui       $at, 0x4160
/* CA5C8 80133EC8 44813000 */  mtc1      $at, $f6
/* CA5CC 80133ECC 00000000 */  nop       
/* CA5D0 80133ED0 461C3000 */  add.s     $f0, $f6, $f28
/* CA5D4 80133ED4 4604003E */  c.le.s    $f0, $f4
/* CA5D8 80133ED8 00000000 */  nop       
/* CA5DC 80133EDC 45010012 */  bc1t      .L80133F28
/* CA5E0 80133EE0 00000000 */   nop      
/* CA5E4 80133EE4 3C0141D8 */  lui       $at, 0x41d8
/* CA5E8 80133EE8 44814000 */  mtc1      $at, $f8
/* CA5EC 80133EEC 00000000 */  nop       
/* CA5F0 80133EF0 4608A000 */  add.s     $f0, $f20, $f8
/* CA5F4 80133EF4 C7A60024 */  lwc1      $f6, 0x24($sp)
/* CA5F8 80133EF8 4606003C */  c.lt.s    $f0, $f6
/* CA5FC 80133EFC 00000000 */  nop       
/* CA600 80133F00 45010009 */  bc1t      .L80133F28
/* CA604 80133F04 00000000 */   nop      
/* CA608 80133F08 3C014190 */  lui       $at, 0x4190
/* CA60C 80133F0C 44814000 */  mtc1      $at, $f8
/* CA610 80133F10 00000000 */  nop       
/* CA614 80133F14 46083000 */  add.s     $f0, $f6, $f8
/* CA618 80133F18 4614003C */  c.lt.s    $f0, $f20
/* CA61C 80133F1C 00000000 */  nop       
/* CA620 80133F20 45020001 */  bc1fl     .L80133F28
/* CA624 80133F24 24120001 */   addiu    $s2, $zero, 1
.L80133F28:
/* CA628 80133F28 12400012 */  beqz      $s2, .L80133F74
/* CA62C 80133F2C 00000000 */   nop      
/* CA630 80133F30 8E640000 */  lw        $a0, ($s3)
/* CA634 80133F34 30820080 */  andi      $v0, $a0, 0x80
/* CA638 80133F38 10400015 */  beqz      $v0, .L80133F90
/* CA63C 80133F3C 24020001 */   addiu    $v0, $zero, 1
/* CA640 80133F40 3C058015 */  lui       $a1, %hi(D_801565A6)
/* CA644 80133F44 24A565A6 */  addiu     $a1, $a1, %lo(D_801565A6)
/* CA648 80133F48 84A20000 */  lh        $v0, ($a1)
/* CA64C 80133F4C 94A30000 */  lhu       $v1, ($a1)
/* CA650 80133F50 10400004 */  beqz      $v0, .L80133F64
/* CA654 80133F54 2402FF7F */   addiu    $v0, $zero, -0x81
/* CA658 80133F58 2462FFFF */  addiu     $v0, $v1, -1
/* CA65C 80133F5C 0804CFE3 */  j         .L80133F8C
/* CA660 80133F60 A4A20000 */   sh       $v0, ($a1)
.L80133F64:
/* CA664 80133F64 00821024 */  and       $v0, $a0, $v0
.L80133F68:
/* CA668 80133F68 AE620000 */  sw        $v0, ($s3)
/* CA66C 80133F6C 0804CFE4 */  j         .L80133F90
/* CA670 80133F70 24020001 */   addiu    $v0, $zero, 1
.L80133F74:
/* CA674 80133F74 8E630000 */  lw        $v1, ($s3)
/* CA678 80133F78 30620080 */  andi      $v0, $v1, 0x80
/* CA67C 80133F7C 10400003 */  beqz      $v0, .L80133F8C
/* CA680 80133F80 2402FF7F */   addiu    $v0, $zero, -0x81
/* CA684 80133F84 00621024 */  and       $v0, $v1, $v0
/* CA688 80133F88 AE620000 */  sw        $v0, ($s3)
.L80133F8C:
/* CA68C 80133F8C 0000102D */  daddu     $v0, $zero, $zero
.L80133F90:
/* CA690 80133F90 8FBF003C */  lw        $ra, 0x3c($sp)
/* CA694 80133F94 8FB40038 */  lw        $s4, 0x38($sp)
/* CA698 80133F98 8FB30034 */  lw        $s3, 0x34($sp)
/* CA69C 80133F9C 8FB20030 */  lw        $s2, 0x30($sp)
/* CA6A0 80133FA0 8FB1002C */  lw        $s1, 0x2c($sp)
/* CA6A4 80133FA4 8FB00028 */  lw        $s0, 0x28($sp)
/* CA6A8 80133FA8 D7BE0068 */  ldc1      $f30, 0x68($sp)
/* CA6AC 80133FAC D7BC0060 */  ldc1      $f28, 0x60($sp)
/* CA6B0 80133FB0 D7BA0058 */  ldc1      $f26, 0x58($sp)
/* CA6B4 80133FB4 D7B80050 */  ldc1      $f24, 0x50($sp)
/* CA6B8 80133FB8 D7B60048 */  ldc1      $f22, 0x48($sp)
/* CA6BC 80133FBC D7B40040 */  ldc1      $f20, 0x40($sp)
/* CA6C0 80133FC0 03E00008 */  jr        $ra
/* CA6C4 80133FC4 27BD0070 */   addiu    $sp, $sp, 0x70
