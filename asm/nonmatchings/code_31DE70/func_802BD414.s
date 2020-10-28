.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD414
/* 31E184 802BD414 27BDFF80 */  addiu     $sp, $sp, -0x80
/* 31E188 802BD418 AFB00040 */  sw        $s0, 0x40($sp)
/* 31E18C 802BD41C 0080802D */  daddu     $s0, $a0, $zero
/* 31E190 802BD420 27A40020 */  addiu     $a0, $sp, 0x20
/* 31E194 802BD424 AFBF0058 */  sw        $ra, 0x58($sp)
/* 31E198 802BD428 AFB50054 */  sw        $s5, 0x54($sp)
/* 31E19C 802BD42C AFB40050 */  sw        $s4, 0x50($sp)
/* 31E1A0 802BD430 AFB3004C */  sw        $s3, 0x4c($sp)
/* 31E1A4 802BD434 AFB20048 */  sw        $s2, 0x48($sp)
/* 31E1A8 802BD438 AFB10044 */  sw        $s1, 0x44($sp)
/* 31E1AC 802BD43C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* 31E1B0 802BD440 F7B80070 */  sdc1      $f24, 0x70($sp)
/* 31E1B4 802BD444 F7B60068 */  sdc1      $f22, 0x68($sp)
/* 31E1B8 802BD448 F7B40060 */  sdc1      $f20, 0x60($sp)
/* 31E1BC 802BD44C 0C0AF483 */  jal       func_802BD20C
/* 31E1C0 802BD450 27A50024 */   addiu    $a1, $sp, 0x24
/* 31E1C4 802BD454 3C148011 */  lui       $s4, %hi(gPlayerStatus)
/* 31E1C8 802BD458 2694EFC8 */  addiu     $s4, $s4, %lo(gPlayerStatus)
/* 31E1CC 802BD45C 3C158011 */  lui       $s5, %hi(D_8010EBB0)
/* 31E1D0 802BD460 26B5EBB0 */  addiu     $s5, $s5, %lo(D_8010EBB0)
/* 31E1D4 802BD464 3C118016 */  lui       $s1, %hi(gCollisionStatus)
/* 31E1D8 802BD468 2631A550 */  addiu     $s1, $s1, %lo(gCollisionStatus)
/* 31E1DC 802BD46C 3C02802C */  lui       $v0, 0x802c
/* 31E1E0 802BD470 8C42FEE4 */  lw        $v0, -0x11c($v0)
/* 31E1E4 802BD474 3C014200 */  lui       $at, 0x4200
/* 31E1E8 802BD478 4481A000 */  mtc1      $at, $f20
/* 31E1EC 802BD47C 10400003 */  beqz      $v0, .L802BD48C
/* 31E1F0 802BD480 00000000 */   nop      
/* 31E1F4 802BD484 3C0142A0 */  lui       $at, 0x42a0
/* 31E1F8 802BD488 4481A000 */  mtc1      $at, $f20
.L802BD48C:
/* 31E1FC 802BD48C C7A00024 */  lwc1      $f0, 0x24($sp)
/* 31E200 802BD490 44803000 */  mtc1      $zero, $f6
/* 31E204 802BD494 00000000 */  nop       
/* 31E208 802BD498 46060032 */  c.eq.s    $f0, $f6
/* 31E20C 802BD49C 00000000 */  nop       
/* 31E210 802BD4A0 45010095 */  bc1t      .L802BD6F8
/* 31E214 802BD4A4 00000000 */   nop      
/* 31E218 802BD4A8 3C02802C */  lui       $v0, 0x802c
/* 31E21C 802BD4AC 2442FDB8 */  addiu     $v0, $v0, -0x248
/* 31E220 802BD4B0 3C01802C */  lui       $at, 0x802c
/* 31E224 802BD4B4 C422FDB0 */  lwc1      $f2, -0x250($at)
/* 31E228 802BD4B8 C4440000 */  lwc1      $f4, ($v0)
/* 31E22C 802BD4BC 46041002 */  mul.s     $f0, $f2, $f4
/* 31E230 802BD4C0 00000000 */  nop       
/* 31E234 802BD4C4 3C014100 */  lui       $at, 0x4100
/* 31E238 802BD4C8 44815000 */  mtc1      $at, $f10
/* 31E23C 802BD4CC 3C014200 */  lui       $at, 0x4200
/* 31E240 802BD4D0 44814000 */  mtc1      $at, $f8
/* 31E244 802BD4D4 4600303C */  c.lt.s    $f6, $f0
/* 31E248 802BD4D8 00000000 */  nop       
/* 31E24C 802BD4DC 45020002 */  bc1fl     .L802BD4E8
/* 31E250 802BD4E0 460A1003 */   div.s    $f0, $f2, $f10
/* 31E254 802BD4E4 46081003 */  div.s     $f0, $f2, $f8
.L802BD4E8:
/* 31E258 802BD4E8 46002000 */  add.s     $f0, $f4, $f0
/* 31E25C 802BD4EC E4400000 */  swc1      $f0, ($v0)
/* 31E260 802BD4F0 3C01802C */  lui       $at, 0x802c
/* 31E264 802BD4F4 C422FDB0 */  lwc1      $f2, -0x250($at)
/* 31E268 802BD4F8 44800000 */  mtc1      $zero, $f0
/* 31E26C 802BD4FC 00000000 */  nop       
/* 31E270 802BD500 4602003C */  c.lt.s    $f0, $f2
/* 31E274 802BD504 00000000 */  nop       
/* 31E278 802BD508 45000007 */  bc1f      .L802BD528
/* 31E27C 802BD50C 00000000 */   nop      
/* 31E280 802BD510 3C02802C */  lui       $v0, 0x802c
/* 31E284 802BD514 2442FDB8 */  addiu     $v0, $v0, -0x248
/* 31E288 802BD518 C4400000 */  lwc1      $f0, ($v0)
/* 31E28C 802BD51C 4600103C */  c.lt.s    $f2, $f0
/* 31E290 802BD520 080AF54F */  j         .L802BD53C
/* 31E294 802BD524 00000000 */   nop      
.L802BD528:
/* 31E298 802BD528 3C02802C */  lui       $v0, 0x802c
/* 31E29C 802BD52C 2442FDB8 */  addiu     $v0, $v0, -0x248
/* 31E2A0 802BD530 C4400000 */  lwc1      $f0, ($v0)
/* 31E2A4 802BD534 4602003C */  c.lt.s    $f0, $f2
/* 31E2A8 802BD538 00000000 */  nop       
.L802BD53C:
/* 31E2AC 802BD53C 45030001 */  bc1tl     .L802BD544
/* 31E2B0 802BD540 E4420000 */   swc1     $f2, ($v0)
.L802BD544:
/* 31E2B4 802BD544 3C02802C */  lui       $v0, 0x802c
/* 31E2B8 802BD548 2442FDBC */  addiu     $v0, $v0, -0x244
/* 31E2BC 802BD54C 3C01802C */  lui       $at, 0x802c
/* 31E2C0 802BD550 C424FDB4 */  lwc1      $f4, -0x24c($at)
/* 31E2C4 802BD554 C4460000 */  lwc1      $f6, ($v0)
/* 31E2C8 802BD558 46062082 */  mul.s     $f2, $f4, $f6
/* 31E2CC 802BD55C 00000000 */  nop       
/* 31E2D0 802BD560 44800000 */  mtc1      $zero, $f0
/* 31E2D4 802BD564 00000000 */  nop       
/* 31E2D8 802BD568 4602003C */  c.lt.s    $f0, $f2
/* 31E2DC 802BD56C 00000000 */  nop       
/* 31E2E0 802BD570 45020002 */  bc1fl     .L802BD57C
/* 31E2E4 802BD574 460A2003 */   div.s    $f0, $f4, $f10
/* 31E2E8 802BD578 46082003 */  div.s     $f0, $f4, $f8
.L802BD57C:
/* 31E2EC 802BD57C 46003000 */  add.s     $f0, $f6, $f0
/* 31E2F0 802BD580 E4400000 */  swc1      $f0, ($v0)
/* 31E2F4 802BD584 3C01802C */  lui       $at, 0x802c
/* 31E2F8 802BD588 C422FDB4 */  lwc1      $f2, -0x24c($at)
/* 31E2FC 802BD58C 44800000 */  mtc1      $zero, $f0
/* 31E300 802BD590 00000000 */  nop       
/* 31E304 802BD594 4602003C */  c.lt.s    $f0, $f2
/* 31E308 802BD598 00000000 */  nop       
/* 31E30C 802BD59C 45000007 */  bc1f      .L802BD5BC
/* 31E310 802BD5A0 00000000 */   nop      
/* 31E314 802BD5A4 3C02802C */  lui       $v0, 0x802c
/* 31E318 802BD5A8 2442FDBC */  addiu     $v0, $v0, -0x244
/* 31E31C 802BD5AC C4400000 */  lwc1      $f0, ($v0)
/* 31E320 802BD5B0 4600103C */  c.lt.s    $f2, $f0
/* 31E324 802BD5B4 080AF574 */  j         .L802BD5D0
/* 31E328 802BD5B8 00000000 */   nop      
.L802BD5BC:
/* 31E32C 802BD5BC 3C02802C */  lui       $v0, 0x802c
/* 31E330 802BD5C0 2442FDBC */  addiu     $v0, $v0, -0x244
/* 31E334 802BD5C4 C4400000 */  lwc1      $f0, ($v0)
/* 31E338 802BD5C8 4602003C */  c.lt.s    $f0, $f2
/* 31E33C 802BD5CC 00000000 */  nop       
.L802BD5D0:
/* 31E340 802BD5D0 45030001 */  bc1tl     .L802BD5D8
/* 31E344 802BD5D4 E4420000 */   swc1     $f2, ($v0)
.L802BD5D8:
/* 31E348 802BD5D8 3C06802C */  lui       $a2, 0x802c
/* 31E34C 802BD5DC 8CC6FDB8 */  lw        $a2, -0x248($a2)
/* 31E350 802BD5E0 3C01802C */  lui       $at, 0x802c
/* 31E354 802BD5E4 C420FDBC */  lwc1      $f0, -0x244($at)
/* 31E358 802BD5E8 44806000 */  mtc1      $zero, $f12
/* 31E35C 802BD5EC 46000007 */  neg.s     $f0, $f0
/* 31E360 802BD5F0 44070000 */  mfc1      $a3, $f0
/* 31E364 802BD5F4 0C00A720 */  jal       atan2
/* 31E368 802BD5F8 46006386 */   mov.s    $f14, $f12
/* 31E36C 802BD5FC 3C01800B */  lui       $at, 0x800b
/* 31E370 802BD600 C42C1DEC */  lwc1      $f12, 0x1dec($at)
/* 31E374 802BD604 0C00A6C9 */  jal       clamp_angle
/* 31E378 802BD608 460C0300 */   add.s    $f12, $f0, $f12
/* 31E37C 802BD60C 3C02802C */  lui       $v0, 0x802c
/* 31E380 802BD610 2442FEF8 */  addiu     $v0, $v0, -0x108
/* 31E384 802BD614 C4420000 */  lwc1      $f2, ($v0)
/* 31E388 802BD618 C7A40024 */  lwc1      $f4, 0x24($sp)
/* 31E38C 802BD61C 4604103E */  c.le.s    $f2, $f4
/* 31E390 802BD620 00000000 */  nop       
/* 31E394 802BD624 4500000A */  bc1f      .L802BD650
/* 31E398 802BD628 E7A00020 */   swc1     $f0, 0x20($sp)
/* 31E39C 802BD62C 46022001 */  sub.s     $f0, $f4, $f2
/* 31E3A0 802BD630 46140003 */  div.s     $f0, $f0, $f20
/* 31E3A4 802BD634 46001000 */  add.s     $f0, $f2, $f0
/* 31E3A8 802BD638 4600203C */  c.lt.s    $f4, $f0
/* 31E3AC 802BD63C 00000000 */  nop       
/* 31E3B0 802BD640 45000007 */  bc1f      .L802BD660
/* 31E3B4 802BD644 E4400000 */   swc1     $f0, ($v0)
/* 31E3B8 802BD648 080AF598 */  j         .L802BD660
/* 31E3BC 802BD64C E4440000 */   swc1     $f4, ($v0)
.L802BD650:
/* 31E3C0 802BD650 46022001 */  sub.s     $f0, $f4, $f2
/* 31E3C4 802BD654 46140003 */  div.s     $f0, $f0, $f20
/* 31E3C8 802BD658 46001000 */  add.s     $f0, $f2, $f0
/* 31E3CC 802BD65C E4400000 */  swc1      $f0, ($v0)
.L802BD660:
/* 31E3D0 802BD660 27A50028 */  addiu     $a1, $sp, 0x28
/* 31E3D4 802BD664 C7A40020 */  lwc1      $f4, 0x20($sp)
/* 31E3D8 802BD668 3C0140C9 */  lui       $at, 0x40c9
/* 31E3DC 802BD66C 34210FD0 */  ori       $at, $at, 0xfd0
/* 31E3E0 802BD670 44816000 */  mtc1      $at, $f12
/* 31E3E4 802BD674 3C01802C */  lui       $at, 0x802c
/* 31E3E8 802BD678 C420FEF8 */  lwc1      $f0, -0x108($at)
/* 31E3EC 802BD67C 460C2302 */  mul.s     $f12, $f4, $f12
/* 31E3F0 802BD680 00000000 */  nop       
/* 31E3F4 802BD684 3C0143B4 */  lui       $at, 0x43b4
/* 31E3F8 802BD688 44811000 */  mtc1      $at, $f2
/* 31E3FC 802BD68C 27A6002C */  addiu     $a2, $sp, 0x2c
/* 31E400 802BD690 E7A00024 */  swc1      $f0, 0x24($sp)
/* 31E404 802BD694 3C01802C */  lui       $at, 0x802c
/* 31E408 802BD698 E424FEFC */  swc1      $f4, -0x104($at)
/* 31E40C 802BD69C 0C00A82D */  jal       sin_cos_rad
/* 31E410 802BD6A0 46026303 */   div.s    $f12, $f12, $f2
/* 31E414 802BD6A4 C7A00024 */  lwc1      $f0, 0x24($sp)
/* 31E418 802BD6A8 C7A20028 */  lwc1      $f2, 0x28($sp)
/* 31E41C 802BD6AC 46020082 */  mul.s     $f2, $f0, $f2
/* 31E420 802BD6B0 00000000 */  nop       
/* 31E424 802BD6B4 C7A4002C */  lwc1      $f4, 0x2c($sp)
/* 31E428 802BD6B8 46000007 */  neg.s     $f0, $f0
/* 31E42C 802BD6BC 46040002 */  mul.s     $f0, $f0, $f4
/* 31E430 802BD6C0 00000000 */  nop       
/* 31E434 802BD6C4 3C03802C */  lui       $v1, 0x802c
/* 31E438 802BD6C8 2463FF00 */  addiu     $v1, $v1, -0x100
/* 31E43C 802BD6CC 3C02802C */  lui       $v0, 0x802c
/* 31E440 802BD6D0 2442FF04 */  addiu     $v0, $v0, -0xfc
/* 31E444 802BD6D4 C4640000 */  lwc1      $f4, ($v1)
/* 31E448 802BD6D8 46141083 */  div.s     $f2, $f2, $f20
/* 31E44C 802BD6DC 46022100 */  add.s     $f4, $f4, $f2
/* 31E450 802BD6E0 C4420000 */  lwc1      $f2, ($v0)
/* 31E454 802BD6E4 46140003 */  div.s     $f0, $f0, $f20
/* 31E458 802BD6E8 46001080 */  add.s     $f2, $f2, $f0
/* 31E45C 802BD6EC E4640000 */  swc1      $f4, ($v1)
/* 31E460 802BD6F0 080AF5EB */  j         .L802BD7AC
/* 31E464 802BD6F4 E4420000 */   swc1     $f2, ($v0)
.L802BD6F8:
/* 31E468 802BD6F8 3C02802C */  lui       $v0, 0x802c
/* 31E46C 802BD6FC 2442FEF8 */  addiu     $v0, $v0, -0x108
/* 31E470 802BD700 C4400000 */  lwc1      $f0, ($v0)
/* 31E474 802BD704 3C01802C */  lui       $at, 0x802c
/* 31E478 802BD708 D422FE50 */  ldc1      $f2, -0x1b0($at)
/* 31E47C 802BD70C 46000021 */  cvt.d.s   $f0, $f0
/* 31E480 802BD710 46220001 */  sub.d     $f0, $f0, $f2
/* 31E484 802BD714 46200020 */  cvt.s.d   $f0, $f0
/* 31E488 802BD718 4606003C */  c.lt.s    $f0, $f6
/* 31E48C 802BD71C 00000000 */  nop       
/* 31E490 802BD720 45000006 */  bc1f      .L802BD73C
/* 31E494 802BD724 E4400000 */   swc1     $f0, ($v0)
/* 31E498 802BD728 E4460000 */  swc1      $f6, ($v0)
/* 31E49C 802BD72C 3C01802C */  lui       $at, 0x802c
/* 31E4A0 802BD730 E426FDBC */  swc1      $f6, -0x244($at)
/* 31E4A4 802BD734 3C01802C */  lui       $at, 0x802c
/* 31E4A8 802BD738 E426FDB8 */  swc1      $f6, -0x248($at)
.L802BD73C:
/* 31E4AC 802BD73C 27A50028 */  addiu     $a1, $sp, 0x28
/* 31E4B0 802BD740 3C01802C */  lui       $at, 0x802c
/* 31E4B4 802BD744 C424FEFC */  lwc1      $f4, -0x104($at)
/* 31E4B8 802BD748 3C0140C9 */  lui       $at, 0x40c9
/* 31E4BC 802BD74C 34210FD0 */  ori       $at, $at, 0xfd0
/* 31E4C0 802BD750 44816000 */  mtc1      $at, $f12
/* 31E4C4 802BD754 C4400000 */  lwc1      $f0, ($v0)
/* 31E4C8 802BD758 460C2302 */  mul.s     $f12, $f4, $f12
/* 31E4CC 802BD75C 00000000 */  nop       
/* 31E4D0 802BD760 3C0143B4 */  lui       $at, 0x43b4
/* 31E4D4 802BD764 44811000 */  mtc1      $at, $f2
/* 31E4D8 802BD768 27A6002C */  addiu     $a2, $sp, 0x2c
/* 31E4DC 802BD76C E7A00024 */  swc1      $f0, 0x24($sp)
/* 31E4E0 802BD770 E7A40020 */  swc1      $f4, 0x20($sp)
/* 31E4E4 802BD774 0C00A82D */  jal       sin_cos_rad
/* 31E4E8 802BD778 46026303 */   div.s    $f12, $f12, $f2
/* 31E4EC 802BD77C C7A00024 */  lwc1      $f0, 0x24($sp)
/* 31E4F0 802BD780 C7A20028 */  lwc1      $f2, 0x28($sp)
/* 31E4F4 802BD784 46020082 */  mul.s     $f2, $f0, $f2
/* 31E4F8 802BD788 00000000 */  nop       
/* 31E4FC 802BD78C C7A4002C */  lwc1      $f4, 0x2c($sp)
/* 31E500 802BD790 46000007 */  neg.s     $f0, $f0
/* 31E504 802BD794 46040002 */  mul.s     $f0, $f0, $f4
/* 31E508 802BD798 00000000 */  nop       
/* 31E50C 802BD79C 3C01802C */  lui       $at, 0x802c
/* 31E510 802BD7A0 E422FF00 */  swc1      $f2, -0x100($at)
/* 31E514 802BD7A4 3C01802C */  lui       $at, 0x802c
/* 31E518 802BD7A8 E420FF04 */  swc1      $f0, -0xfc($at)
.L802BD7AC:
/* 31E51C 802BD7AC C7A20024 */  lwc1      $f2, 0x24($sp)
/* 31E520 802BD7B0 44800000 */  mtc1      $zero, $f0
/* 31E524 802BD7B4 00000000 */  nop       
/* 31E528 802BD7B8 46001032 */  c.eq.s    $f2, $f0
/* 31E52C 802BD7BC 00000000 */  nop       
/* 31E530 802BD7C0 450100D6 */  bc1t      .L802BDB1C
/* 31E534 802BD7C4 E6020018 */   swc1     $f2, 0x18($s0)
/* 31E538 802BD7C8 860200A8 */  lh        $v0, 0xa8($s0)
/* 31E53C 802BD7CC 3C013F00 */  lui       $at, 0x3f00
/* 31E540 802BD7D0 44810000 */  mtc1      $at, $f0
/* 31E544 802BD7D4 C7AA0020 */  lwc1      $f10, 0x20($sp)
/* 31E548 802BD7D8 C6080038 */  lwc1      $f8, 0x38($s0)
/* 31E54C 802BD7DC 44823000 */  mtc1      $v0, $f6
/* 31E550 802BD7E0 00000000 */  nop       
/* 31E554 802BD7E4 468031A0 */  cvt.s.w   $f6, $f6
/* 31E558 802BD7E8 46003182 */  mul.s     $f6, $f6, $f0
/* 31E55C 802BD7EC 00000000 */  nop       
/* 31E560 802BD7F0 E60A000C */  swc1      $f10, 0xc($s0)
/* 31E564 802BD7F4 868200B0 */  lh        $v0, 0xb0($s4)
/* 31E568 802BD7F8 3C013F4C */  lui       $at, 0x3f4c
/* 31E56C 802BD7FC 3421CCCD */  ori       $at, $at, 0xcccd
/* 31E570 802BD800 44810000 */  mtc1      $at, $f0
/* 31E574 802BD804 44821000 */  mtc1      $v0, $f2
/* 31E578 802BD808 00000000 */  nop       
/* 31E57C 802BD80C 468010A0 */  cvt.s.w   $f2, $f2
/* 31E580 802BD810 46001082 */  mul.s     $f2, $f2, $f0
/* 31E584 802BD814 00000000 */  nop       
/* 31E588 802BD818 3C01C0C0 */  lui       $at, 0xc0c0
/* 31E58C 802BD81C 44812000 */  mtc1      $at, $f4
/* 31E590 802BD820 C6000064 */  lwc1      $f0, 0x64($s0)
/* 31E594 802BD824 27A50030 */  addiu     $a1, $sp, 0x30
/* 31E598 802BD828 E7A80030 */  swc1      $f8, 0x30($sp)
/* 31E59C 802BD82C 46040000 */  add.s     $f0, $f0, $f4
/* 31E5A0 802BD830 C6080018 */  lwc1      $f8, 0x18($s0)
/* 31E5A4 802BD834 C6040040 */  lwc1      $f4, 0x40($s0)
/* 31E5A8 802BD838 46023180 */  add.s     $f6, $f6, $f2
/* 31E5AC 802BD83C E7A40038 */  swc1      $f4, 0x38($sp)
/* 31E5B0 802BD840 E7A00034 */  swc1      $f0, 0x34($sp)
/* 31E5B4 802BD844 E7A6003C */  swc1      $f6, 0x3c($sp)
/* 31E5B8 802BD848 E7A80010 */  swc1      $f8, 0x10($sp)
/* 31E5BC 802BD84C E7AA0014 */  swc1      $f10, 0x14($sp)
/* 31E5C0 802BD850 E7A60018 */  swc1      $f6, 0x18($sp)
/* 31E5C4 802BD854 860200A6 */  lh        $v0, 0xa6($s0)
/* 31E5C8 802BD858 27A60034 */  addiu     $a2, $sp, 0x34
/* 31E5CC 802BD85C 44820000 */  mtc1      $v0, $f0
/* 31E5D0 802BD860 00000000 */  nop       
/* 31E5D4 802BD864 46800020 */  cvt.s.w   $f0, $f0
/* 31E5D8 802BD868 E7A0001C */  swc1      $f0, 0x1c($sp)
/* 31E5DC 802BD86C 8E040080 */  lw        $a0, 0x80($s0)
/* 31E5E0 802BD870 0C0376B9 */  jal       func_800DDAE4
/* 31E5E4 802BD874 27A70038 */   addiu    $a3, $sp, 0x38
/* 31E5E8 802BD878 10400025 */  beqz      $v0, .L802BD910
/* 31E5EC 802BD87C 00000000 */   nop      
/* 31E5F0 802BD880 3C028011 */  lui       $v0, 0x8011
/* 31E5F4 802BD884 2442C978 */  addiu     $v0, $v0, -0x3688
/* 31E5F8 802BD888 8C440000 */  lw        $a0, ($v0)
/* 31E5FC 802BD88C 94420002 */  lhu       $v0, 2($v0)
/* 31E600 802BD890 0C016F6A */  jal       get_collider_type_by_id
/* 31E604 802BD894 A6220000 */   sh       $v0, ($s1)
/* 31E608 802BD898 304200FF */  andi      $v0, $v0, 0xff
/* 31E60C 802BD89C 24030004 */  addiu     $v1, $zero, 4
/* 31E610 802BD8A0 14430007 */  bne       $v0, $v1, .L802BD8C0
/* 31E614 802BD8A4 00000000 */   nop      
/* 31E618 802BD8A8 3C03802C */  lui       $v1, 0x802c
/* 31E61C 802BD8AC 2463FEF0 */  addiu     $v1, $v1, -0x110
/* 31E620 802BD8B0 8C620000 */  lw        $v0, ($v1)
/* 31E624 802BD8B4 24420001 */  addiu     $v0, $v0, 1
/* 31E628 802BD8B8 080AF632 */  j         .L802BD8C8
/* 31E62C 802BD8BC AC620000 */   sw       $v0, ($v1)
.L802BD8C0:
/* 31E630 802BD8C0 3C01802C */  lui       $at, 0x802c
/* 31E634 802BD8C4 AC20FEF0 */  sw        $zero, -0x110($at)
.L802BD8C8:
/* 31E638 802BD8C8 C7A40030 */  lwc1      $f4, 0x30($sp)
/* 31E63C 802BD8CC C6060038 */  lwc1      $f6, 0x38($s0)
/* 31E640 802BD8D0 46062101 */  sub.s     $f4, $f4, $f6
/* 31E644 802BD8D4 3C013F00 */  lui       $at, 0x3f00
/* 31E648 802BD8D8 44814000 */  mtc1      $at, $f8
/* 31E64C 802BD8DC 00000000 */  nop       
/* 31E650 802BD8E0 46082102 */  mul.s     $f4, $f4, $f8
/* 31E654 802BD8E4 00000000 */  nop       
/* 31E658 802BD8E8 C7A00038 */  lwc1      $f0, 0x38($sp)
/* 31E65C 802BD8EC C6020040 */  lwc1      $f2, 0x40($s0)
/* 31E660 802BD8F0 46020001 */  sub.s     $f0, $f0, $f2
/* 31E664 802BD8F4 46080002 */  mul.s     $f0, $f0, $f8
/* 31E668 802BD8F8 00000000 */  nop       
/* 31E66C 802BD8FC 46043180 */  add.s     $f6, $f6, $f4
/* 31E670 802BD900 46001080 */  add.s     $f2, $f2, $f0
/* 31E674 802BD904 E6060038 */  swc1      $f6, 0x38($s0)
/* 31E678 802BD908 080AF64A */  j         .L802BD928
/* 31E67C 802BD90C E6020040 */   swc1     $f2, 0x40($s0)
.L802BD910:
/* 31E680 802BD910 8FA50024 */  lw        $a1, 0x24($sp)
/* 31E684 802BD914 8FA60020 */  lw        $a2, 0x20($sp)
/* 31E688 802BD918 0C00EA95 */  jal       npc_move_heading
/* 31E68C 802BD91C 0200202D */   daddu    $a0, $s0, $zero
/* 31E690 802BD920 2402FFFF */  addiu     $v0, $zero, -1
/* 31E694 802BD924 A6220000 */  sh        $v0, ($s1)
.L802BD928:
/* 31E698 802BD928 C60C000C */  lwc1      $f12, 0xc($s0)
/* 31E69C 802BD92C 3C0141F0 */  lui       $at, 0x41f0
/* 31E6A0 802BD930 4481D000 */  mtc1      $at, $f26
/* 31E6A4 802BD934 3C014000 */  lui       $at, 0x4000
/* 31E6A8 802BD938 44810000 */  mtc1      $at, $f0
/* 31E6AC 802BD93C 461A6301 */  sub.s     $f12, $f12, $f26
/* 31E6B0 802BD940 0C00A6C9 */  jal       clamp_angle
/* 31E6B4 802BD944 E7A00024 */   swc1     $f0, 0x24($sp)
/* 31E6B8 802BD948 27B30030 */  addiu     $s3, $sp, 0x30
/* 31E6BC 802BD94C 0260282D */  daddu     $a1, $s3, $zero
/* 31E6C0 802BD950 27B20034 */  addiu     $s2, $sp, 0x34
/* 31E6C4 802BD954 860200A8 */  lh        $v0, 0xa8($s0)
/* 31E6C8 802BD958 3C013F00 */  lui       $at, 0x3f00
/* 31E6CC 802BD95C 4481C000 */  mtc1      $at, $f24
/* 31E6D0 802BD960 44824000 */  mtc1      $v0, $f8
/* 31E6D4 802BD964 00000000 */  nop       
/* 31E6D8 802BD968 46804220 */  cvt.s.w   $f8, $f8
/* 31E6DC 802BD96C 46184202 */  mul.s     $f8, $f8, $f24
/* 31E6E0 802BD970 00000000 */  nop       
/* 31E6E4 802BD974 0240302D */  daddu     $a2, $s2, $zero
/* 31E6E8 802BD978 868200B0 */  lh        $v0, 0xb0($s4)
/* 31E6EC 802BD97C 3C013F4C */  lui       $at, 0x3f4c
/* 31E6F0 802BD980 3421CCCD */  ori       $at, $at, 0xcccd
/* 31E6F4 802BD984 4481A000 */  mtc1      $at, $f20
/* 31E6F8 802BD988 44822000 */  mtc1      $v0, $f4
/* 31E6FC 802BD98C 00000000 */  nop       
/* 31E700 802BD990 46802120 */  cvt.s.w   $f4, $f4
/* 31E704 802BD994 46142102 */  mul.s     $f4, $f4, $f20
/* 31E708 802BD998 00000000 */  nop       
/* 31E70C 802BD99C C6060038 */  lwc1      $f6, 0x38($s0)
/* 31E710 802BD9A0 C6020064 */  lwc1      $f2, 0x64($s0)
/* 31E714 802BD9A4 3C01C0C0 */  lui       $at, 0xc0c0
/* 31E718 802BD9A8 4481B000 */  mtc1      $at, $f22
/* 31E71C 802BD9AC C7AA0024 */  lwc1      $f10, 0x24($sp)
/* 31E720 802BD9B0 46161080 */  add.s     $f2, $f2, $f22
/* 31E724 802BD9B4 E7A00020 */  swc1      $f0, 0x20($sp)
/* 31E728 802BD9B8 E7A60030 */  swc1      $f6, 0x30($sp)
/* 31E72C 802BD9BC C6060040 */  lwc1      $f6, 0x40($s0)
/* 31E730 802BD9C0 46044200 */  add.s     $f8, $f8, $f4
/* 31E734 802BD9C4 E7A60038 */  swc1      $f6, 0x38($sp)
/* 31E738 802BD9C8 E7A20034 */  swc1      $f2, 0x34($sp)
/* 31E73C 802BD9CC E7A8003C */  swc1      $f8, 0x3c($sp)
/* 31E740 802BD9D0 E7AA0010 */  swc1      $f10, 0x10($sp)
/* 31E744 802BD9D4 E7A00014 */  swc1      $f0, 0x14($sp)
/* 31E748 802BD9D8 E7A80018 */  swc1      $f8, 0x18($sp)
/* 31E74C 802BD9DC 860200A6 */  lh        $v0, 0xa6($s0)
/* 31E750 802BD9E0 27B10038 */  addiu     $s1, $sp, 0x38
/* 31E754 802BD9E4 44820000 */  mtc1      $v0, $f0
/* 31E758 802BD9E8 00000000 */  nop       
/* 31E75C 802BD9EC 46800020 */  cvt.s.w   $f0, $f0
/* 31E760 802BD9F0 E7A0001C */  swc1      $f0, 0x1c($sp)
/* 31E764 802BD9F4 8E040080 */  lw        $a0, 0x80($s0)
/* 31E768 802BD9F8 0C0376B9 */  jal       func_800DDAE4
/* 31E76C 802BD9FC 0220382D */   daddu    $a3, $s1, $zero
/* 31E770 802BDA00 1040000F */  beqz      $v0, .L802BDA40
/* 31E774 802BDA04 00000000 */   nop      
/* 31E778 802BDA08 C7A00030 */  lwc1      $f0, 0x30($sp)
/* 31E77C 802BDA0C C6060038 */  lwc1      $f6, 0x38($s0)
/* 31E780 802BDA10 C7A20038 */  lwc1      $f2, 0x38($sp)
/* 31E784 802BDA14 46060001 */  sub.s     $f0, $f0, $f6
/* 31E788 802BDA18 C6040040 */  lwc1      $f4, 0x40($s0)
/* 31E78C 802BDA1C 3C0140A0 */  lui       $at, 0x40a0
/* 31E790 802BDA20 44814000 */  mtc1      $at, $f8
/* 31E794 802BDA24 46041081 */  sub.s     $f2, $f2, $f4
/* 31E798 802BDA28 46080003 */  div.s     $f0, $f0, $f8
/* 31E79C 802BDA2C 46003180 */  add.s     $f6, $f6, $f0
/* 31E7A0 802BDA30 46081083 */  div.s     $f2, $f2, $f8
/* 31E7A4 802BDA34 46022100 */  add.s     $f4, $f4, $f2
/* 31E7A8 802BDA38 E6060038 */  swc1      $f6, 0x38($s0)
/* 31E7AC 802BDA3C E6040040 */  swc1      $f4, 0x40($s0)
.L802BDA40:
/* 31E7B0 802BDA40 C60C000C */  lwc1      $f12, 0xc($s0)
/* 31E7B4 802BDA44 0C00A6C9 */  jal       clamp_angle
/* 31E7B8 802BDA48 461A6300 */   add.s    $f12, $f12, $f26
/* 31E7BC 802BDA4C 860200A8 */  lh        $v0, 0xa8($s0)
/* 31E7C0 802BDA50 44823000 */  mtc1      $v0, $f6
/* 31E7C4 802BDA54 00000000 */  nop       
/* 31E7C8 802BDA58 468031A0 */  cvt.s.w   $f6, $f6
/* 31E7CC 802BDA5C 46183182 */  mul.s     $f6, $f6, $f24
/* 31E7D0 802BDA60 00000000 */  nop       
/* 31E7D4 802BDA64 868200B0 */  lh        $v0, 0xb0($s4)
/* 31E7D8 802BDA68 44822000 */  mtc1      $v0, $f4
/* 31E7DC 802BDA6C 00000000 */  nop       
/* 31E7E0 802BDA70 46802120 */  cvt.s.w   $f4, $f4
/* 31E7E4 802BDA74 46142102 */  mul.s     $f4, $f4, $f20
/* 31E7E8 802BDA78 00000000 */  nop       
/* 31E7EC 802BDA7C 0260282D */  daddu     $a1, $s3, $zero
/* 31E7F0 802BDA80 C6080038 */  lwc1      $f8, 0x38($s0)
/* 31E7F4 802BDA84 C6020064 */  lwc1      $f2, 0x64($s0)
/* 31E7F8 802BDA88 C7AA0024 */  lwc1      $f10, 0x24($sp)
/* 31E7FC 802BDA8C 46161080 */  add.s     $f2, $f2, $f22
/* 31E800 802BDA90 E7A00020 */  swc1      $f0, 0x20($sp)
/* 31E804 802BDA94 E7A80030 */  swc1      $f8, 0x30($sp)
/* 31E808 802BDA98 C6080040 */  lwc1      $f8, 0x40($s0)
/* 31E80C 802BDA9C 46043180 */  add.s     $f6, $f6, $f4
/* 31E810 802BDAA0 E7A80038 */  swc1      $f8, 0x38($sp)
/* 31E814 802BDAA4 E7A20034 */  swc1      $f2, 0x34($sp)
/* 31E818 802BDAA8 E7A6003C */  swc1      $f6, 0x3c($sp)
/* 31E81C 802BDAAC E7AA0010 */  swc1      $f10, 0x10($sp)
/* 31E820 802BDAB0 E7A00014 */  swc1      $f0, 0x14($sp)
/* 31E824 802BDAB4 E7A60018 */  swc1      $f6, 0x18($sp)
/* 31E828 802BDAB8 860200A6 */  lh        $v0, 0xa6($s0)
/* 31E82C 802BDABC 0240302D */  daddu     $a2, $s2, $zero
/* 31E830 802BDAC0 44820000 */  mtc1      $v0, $f0
/* 31E834 802BDAC4 00000000 */  nop       
/* 31E838 802BDAC8 46800020 */  cvt.s.w   $f0, $f0
/* 31E83C 802BDACC E7A0001C */  swc1      $f0, 0x1c($sp)
/* 31E840 802BDAD0 8E040080 */  lw        $a0, 0x80($s0)
/* 31E844 802BDAD4 0C0376B9 */  jal       func_800DDAE4
/* 31E848 802BDAD8 0220382D */   daddu    $a3, $s1, $zero
/* 31E84C 802BDADC 1040000F */  beqz      $v0, .L802BDB1C
/* 31E850 802BDAE0 00000000 */   nop      
/* 31E854 802BDAE4 C7A00030 */  lwc1      $f0, 0x30($sp)
/* 31E858 802BDAE8 C6060038 */  lwc1      $f6, 0x38($s0)
/* 31E85C 802BDAEC C7A20038 */  lwc1      $f2, 0x38($sp)
/* 31E860 802BDAF0 46060001 */  sub.s     $f0, $f0, $f6
/* 31E864 802BDAF4 C6040040 */  lwc1      $f4, 0x40($s0)
/* 31E868 802BDAF8 3C0140A0 */  lui       $at, 0x40a0
/* 31E86C 802BDAFC 44814000 */  mtc1      $at, $f8
/* 31E870 802BDB00 46041081 */  sub.s     $f2, $f2, $f4
/* 31E874 802BDB04 46080003 */  div.s     $f0, $f0, $f8
/* 31E878 802BDB08 46003180 */  add.s     $f6, $f6, $f0
/* 31E87C 802BDB0C 46081083 */  div.s     $f2, $f2, $f8
/* 31E880 802BDB10 46022100 */  add.s     $f4, $f4, $f2
/* 31E884 802BDB14 E6060038 */  swc1      $f6, 0x38($s0)
/* 31E888 802BDB18 E6040040 */  swc1      $f4, 0x40($s0)
.L802BDB1C:
/* 31E88C 802BDB1C 3C11802C */  lui       $s1, 0x802c
/* 31E890 802BDB20 2631FEE4 */  addiu     $s1, $s1, -0x11c
/* 31E894 802BDB24 8E220000 */  lw        $v0, ($s1)
/* 31E898 802BDB28 1440002C */  bnez      $v0, .L802BDBDC
/* 31E89C 802BDB2C 00000000 */   nop      
/* 31E8A0 802BDB30 C600000C */  lwc1      $f0, 0xc($s0)
/* 31E8A4 802BDB34 E7A00010 */  swc1      $f0, 0x10($sp)
/* 31E8A8 802BDB38 860200A6 */  lh        $v0, 0xa6($s0)
/* 31E8AC 802BDB3C 3C013F00 */  lui       $at, 0x3f00
/* 31E8B0 802BDB40 4481A000 */  mtc1      $at, $f20
/* 31E8B4 802BDB44 44820000 */  mtc1      $v0, $f0
/* 31E8B8 802BDB48 00000000 */  nop       
/* 31E8BC 802BDB4C 46800020 */  cvt.s.w   $f0, $f0
/* 31E8C0 802BDB50 46140002 */  mul.s     $f0, $f0, $f20
/* 31E8C4 802BDB54 00000000 */  nop       
/* 31E8C8 802BDB58 E7A00014 */  swc1      $f0, 0x14($sp)
/* 31E8CC 802BDB5C 8E040080 */  lw        $a0, 0x80($s0)
/* 31E8D0 802BDB60 8E050038 */  lw        $a1, 0x38($s0)
/* 31E8D4 802BDB64 8E06003C */  lw        $a2, 0x3c($s0)
/* 31E8D8 802BDB68 0C0AF4DA */  jal       func_802BD368
/* 31E8DC 802BDB6C 8E070040 */   lw       $a3, 0x40($s0)
/* 31E8E0 802BDB70 8E220000 */  lw        $v0, ($s1)
/* 31E8E4 802BDB74 14400019 */  bnez      $v0, .L802BDBDC
/* 31E8E8 802BDB78 00000000 */   nop      
/* 31E8EC 802BDB7C 860200A8 */  lh        $v0, 0xa8($s0)
/* 31E8F0 802BDB80 44820000 */  mtc1      $v0, $f0
/* 31E8F4 802BDB84 00000000 */  nop       
/* 31E8F8 802BDB88 46800020 */  cvt.s.w   $f0, $f0
/* 31E8FC 802BDB8C 46140002 */  mul.s     $f0, $f0, $f20
/* 31E900 802BDB90 00000000 */  nop       
/* 31E904 802BDB94 3C01802C */  lui       $at, 0x802c
/* 31E908 802BDB98 C422FEE0 */  lwc1      $f2, -0x120($at)
/* 31E90C 802BDB9C 46001081 */  sub.s     $f2, $f2, $f0
/* 31E910 802BDBA0 3C014040 */  lui       $at, 0x4040
/* 31E914 802BDBA4 44810000 */  mtc1      $at, $f0
/* 31E918 802BDBA8 00000000 */  nop       
/* 31E91C 802BDBAC E6000018 */  swc1      $f0, 0x18($s0)
/* 31E920 802BDBB0 E6020064 */  swc1      $f2, 0x64($s0)
/* 31E924 802BDBB4 8EA2000C */  lw        $v0, 0xc($s5)
/* 31E928 802BDBB8 3C01802C */  lui       $at, 0x802c
/* 31E92C 802BDBBC AC20FEE8 */  sw        $zero, -0x118($at)
/* 31E930 802BDBC0 30420004 */  andi      $v0, $v0, 4
/* 31E934 802BDBC4 104001A1 */  beqz      $v0, .L802BE24C
/* 31E938 802BDBC8 24020001 */   addiu    $v0, $zero, 1
/* 31E93C 802BDBCC 3C014000 */  lui       $at, 0x4000
/* 31E940 802BDBD0 44810000 */  mtc1      $at, $f0
/* 31E944 802BDBD4 AE220000 */  sw        $v0, ($s1)
/* 31E948 802BDBD8 E6000018 */  swc1      $f0, 0x18($s0)
.L802BDBDC:
/* 31E94C 802BDBDC 3C04802C */  lui       $a0, 0x802c
/* 31E950 802BDBE0 2484FEE4 */  addiu     $a0, $a0, -0x11c
/* 31E954 802BDBE4 8C830000 */  lw        $v1, ($a0)
/* 31E958 802BDBE8 24020001 */  addiu     $v0, $zero, 1
/* 31E95C 802BDBEC 1462000A */  bne       $v1, $v0, .L802BDC18
/* 31E960 802BDBF0 00000000 */   nop      
/* 31E964 802BDBF4 8EA20008 */  lw        $v0, 8($s5)
/* 31E968 802BDBF8 30420004 */  andi      $v0, $v0, 4
/* 31E96C 802BDBFC 10400006 */  beqz      $v0, .L802BDC18
/* 31E970 802BDC00 00000000 */   nop      
/* 31E974 802BDC04 3C02802C */  lui       $v0, 0x802c
/* 31E978 802BDC08 8C42FEE8 */  lw        $v0, -0x118($v0)
/* 31E97C 802BDC0C 14400002 */  bnez      $v0, .L802BDC18
/* 31E980 802BDC10 24020002 */   addiu    $v0, $zero, 2
/* 31E984 802BDC14 AC820000 */  sw        $v0, ($a0)
.L802BDC18:
/* 31E988 802BDC18 3C03802C */  lui       $v1, 0x802c
/* 31E98C 802BDC1C 2463FEE8 */  addiu     $v1, $v1, -0x118
/* 31E990 802BDC20 8C620000 */  lw        $v0, ($v1)
/* 31E994 802BDC24 24420001 */  addiu     $v0, $v0, 1
/* 31E998 802BDC28 AC620000 */  sw        $v0, ($v1)
/* 31E99C 802BDC2C 3C03802C */  lui       $v1, 0x802c
/* 31E9A0 802BDC30 8C63FEE4 */  lw        $v1, -0x11c($v1)
/* 31E9A4 802BDC34 24020002 */  addiu     $v0, $zero, 2
/* 31E9A8 802BDC38 146200B1 */  bne       $v1, $v0, .L802BDF00
/* 31E9AC 802BDC3C 27A50030 */   addiu    $a1, $sp, 0x30
/* 31E9B0 802BDC40 C6000038 */  lwc1      $f0, 0x38($s0)
/* 31E9B4 802BDC44 C602003C */  lwc1      $f2, 0x3c($s0)
/* 31E9B8 802BDC48 C6040040 */  lwc1      $f4, 0x40($s0)
/* 31E9BC 802BDC4C 860200A8 */  lh        $v0, 0xa8($s0)
/* 31E9C0 802BDC50 E7A00030 */  swc1      $f0, 0x30($sp)
/* 31E9C4 802BDC54 44820000 */  mtc1      $v0, $f0
/* 31E9C8 802BDC58 00000000 */  nop       
/* 31E9CC 802BDC5C 46800020 */  cvt.s.w   $f0, $f0
/* 31E9D0 802BDC60 27A2003C */  addiu     $v0, $sp, 0x3c
/* 31E9D4 802BDC64 E7A20034 */  swc1      $f2, 0x34($sp)
/* 31E9D8 802BDC68 E7A40038 */  swc1      $f4, 0x38($sp)
/* 31E9DC 802BDC6C E7A0003C */  swc1      $f0, 0x3c($sp)
/* 31E9E0 802BDC70 AFA20010 */  sw        $v0, 0x10($sp)
/* 31E9E4 802BDC74 C600000C */  lwc1      $f0, 0xc($s0)
/* 31E9E8 802BDC78 E7A00014 */  swc1      $f0, 0x14($sp)
/* 31E9EC 802BDC7C 860200A6 */  lh        $v0, 0xa6($s0)
/* 31E9F0 802BDC80 27A60034 */  addiu     $a2, $sp, 0x34
/* 31E9F4 802BDC84 44820000 */  mtc1      $v0, $f0
/* 31E9F8 802BDC88 00000000 */  nop       
/* 31E9FC 802BDC8C 46800020 */  cvt.s.w   $f0, $f0
/* 31EA00 802BDC90 E7A00018 */  swc1      $f0, 0x18($sp)
/* 31EA04 802BDC94 8E040080 */  lw        $a0, 0x80($s0)
/* 31EA08 802BDC98 0C0371DE */  jal       func_800DC778
/* 31EA0C 802BDC9C 27A70038 */   addiu    $a3, $sp, 0x38
/* 31EA10 802BDCA0 1040001D */  beqz      $v0, .L802BDD18
/* 31EA14 802BDCA4 00000000 */   nop      
/* 31EA18 802BDCA8 868200B0 */  lh        $v0, 0xb0($s4)
/* 31EA1C 802BDCAC 3C01802C */  lui       $at, 0x802c
/* 31EA20 802BDCB0 C420FEE0 */  lwc1      $f0, -0x120($at)
/* 31EA24 802BDCB4 00021040 */  sll       $v0, $v0, 1
/* 31EA28 802BDCB8 44821000 */  mtc1      $v0, $f2
/* 31EA2C 802BDCBC 00000000 */  nop       
/* 31EA30 802BDCC0 468010A0 */  cvt.s.w   $f2, $f2
/* 31EA34 802BDCC4 46020001 */  sub.s     $f0, $f0, $f2
/* 31EA38 802BDCC8 C6040064 */  lwc1      $f4, 0x64($s0)
/* 31EA3C 802BDCCC 46040001 */  sub.s     $f0, $f0, $f4
/* 31EA40 802BDCD0 3C013DCC */  lui       $at, 0x3dcc
/* 31EA44 802BDCD4 3421CCCD */  ori       $at, $at, 0xcccd
/* 31EA48 802BDCD8 44811000 */  mtc1      $at, $f2
/* 31EA4C 802BDCDC 00000000 */  nop       
/* 31EA50 802BDCE0 46020502 */  mul.s     $f20, $f0, $f2
/* 31EA54 802BDCE4 00000000 */  nop       
/* 31EA58 802BDCE8 C7A20034 */  lwc1      $f2, 0x34($sp)
/* 31EA5C 802BDCEC 46142100 */  add.s     $f4, $f4, $f20
/* 31EA60 802BDCF0 3C0140A0 */  lui       $at, 0x40a0
/* 31EA64 802BDCF4 44810000 */  mtc1      $at, $f0
/* 31EA68 802BDCF8 00000000 */  nop       
/* 31EA6C 802BDCFC 46001080 */  add.s     $f2, $f2, $f0
/* 31EA70 802BDD00 4602203C */  c.lt.s    $f4, $f2
/* 31EA74 802BDD04 00000000 */  nop       
/* 31EA78 802BDD08 45000015 */  bc1f      .L802BDD60
/* 31EA7C 802BDD0C E6040064 */   swc1     $f4, 0x64($s0)
/* 31EA80 802BDD10 080AF758 */  j         .L802BDD60
/* 31EA84 802BDD14 E6020064 */   swc1     $f2, 0x64($s0)
.L802BDD18:
/* 31EA88 802BDD18 868200B0 */  lh        $v0, 0xb0($s4)
/* 31EA8C 802BDD1C 3C01802C */  lui       $at, 0x802c
/* 31EA90 802BDD20 C420FEE0 */  lwc1      $f0, -0x120($at)
/* 31EA94 802BDD24 00021040 */  sll       $v0, $v0, 1
/* 31EA98 802BDD28 44821000 */  mtc1      $v0, $f2
/* 31EA9C 802BDD2C 00000000 */  nop       
/* 31EAA0 802BDD30 468010A0 */  cvt.s.w   $f2, $f2
/* 31EAA4 802BDD34 46020001 */  sub.s     $f0, $f0, $f2
/* 31EAA8 802BDD38 C6020064 */  lwc1      $f2, 0x64($s0)
/* 31EAAC 802BDD3C 46020001 */  sub.s     $f0, $f0, $f2
/* 31EAB0 802BDD40 3C013DCC */  lui       $at, 0x3dcc
/* 31EAB4 802BDD44 3421CCCD */  ori       $at, $at, 0xcccd
/* 31EAB8 802BDD48 44812000 */  mtc1      $at, $f4
/* 31EABC 802BDD4C 00000000 */  nop       
/* 31EAC0 802BDD50 46040502 */  mul.s     $f20, $f0, $f4
/* 31EAC4 802BDD54 00000000 */  nop       
/* 31EAC8 802BDD58 46141080 */  add.s     $f2, $f2, $f20
/* 31EACC 802BDD5C E6020064 */  swc1      $f2, 0x64($s0)
.L802BDD60:
/* 31EAD0 802BDD60 3C022AAA */  lui       $v0, 0x2aaa
/* 31EAD4 802BDD64 3C11802C */  lui       $s1, 0x802c
/* 31EAD8 802BDD68 2631FEE8 */  addiu     $s1, $s1, -0x118
/* 31EADC 802BDD6C 8E240000 */  lw        $a0, ($s1)
/* 31EAE0 802BDD70 3442AAAB */  ori       $v0, $v0, 0xaaab
/* 31EAE4 802BDD74 00820018 */  mult      $a0, $v0
/* 31EAE8 802BDD78 00041FC3 */  sra       $v1, $a0, 0x1f
/* 31EAEC 802BDD7C 00004010 */  mfhi      $t0
/* 31EAF0 802BDD80 01031823 */  subu      $v1, $t0, $v1
/* 31EAF4 802BDD84 00031040 */  sll       $v0, $v1, 1
/* 31EAF8 802BDD88 00431021 */  addu      $v0, $v0, $v1
/* 31EAFC 802BDD8C 00021040 */  sll       $v0, $v0, 1
/* 31EB00 802BDD90 14820015 */  bne       $a0, $v0, .L802BDDE8
/* 31EB04 802BDD94 00000000 */   nop      
/* 31EB08 802BDD98 860200A8 */  lh        $v0, 0xa8($s0)
/* 31EB0C 802BDD9C 3C013F00 */  lui       $at, 0x3f00
/* 31EB10 802BDDA0 44810000 */  mtc1      $at, $f0
/* 31EB14 802BDDA4 44821000 */  mtc1      $v0, $f2
/* 31EB18 802BDDA8 00000000 */  nop       
/* 31EB1C 802BDDAC 468010A0 */  cvt.s.w   $f2, $f2
/* 31EB20 802BDDB0 46001082 */  mul.s     $f2, $f2, $f0
/* 31EB24 802BDDB4 00000000 */  nop       
/* 31EB28 802BDDB8 C6040064 */  lwc1      $f4, 0x64($s0)
/* 31EB2C 802BDDBC 3C01802C */  lui       $at, 0x802c
/* 31EB30 802BDDC0 C420FEE0 */  lwc1      $f0, -0x120($at)
/* 31EB34 802BDDC4 46040001 */  sub.s     $f0, $f0, $f4
/* 31EB38 802BDDC8 46022100 */  add.s     $f4, $f4, $f2
/* 31EB3C 802BDDCC 46020001 */  sub.s     $f0, $f0, $f2
/* 31EB40 802BDDD0 44062000 */  mfc1      $a2, $f4
/* 31EB44 802BDDD4 E7A00010 */  swc1      $f0, 0x10($sp)
/* 31EB48 802BDDD8 8E050038 */  lw        $a1, 0x38($s0)
/* 31EB4C 802BDDDC 8E070040 */  lw        $a3, 0x40($s0)
/* 31EB50 802BDDE0 0C01C16C */  jal       func_800705B0
/* 31EB54 802BDDE4 0000202D */   daddu    $a0, $zero, $zero
.L802BDDE8:
/* 31EB58 802BDDE8 8E220000 */  lw        $v0, ($s1)
/* 31EB5C 802BDDEC 24110001 */  addiu     $s1, $zero, 1
/* 31EB60 802BDDF0 14510007 */  bne       $v0, $s1, .L802BDE10
/* 31EB64 802BDDF4 00000000 */   nop      
/* 31EB68 802BDDF8 3C040008 */  lui       $a0, 8
/* 31EB6C 802BDDFC 0C037FDE */  jal       func_800DFF78
/* 31EB70 802BDE00 34840010 */   ori      $a0, $a0, 0x10
/* 31EB74 802BDE04 3C020007 */  lui       $v0, 7
/* 31EB78 802BDE08 3442000A */  ori       $v0, $v0, 0xa
/* 31EB7C 802BDE0C AE020028 */  sw        $v0, 0x28($s0)
.L802BDE10:
/* 31EB80 802BDE10 3C03802C */  lui       $v1, 0x802c
/* 31EB84 802BDE14 2463FEF4 */  addiu     $v1, $v1, -0x10c
/* 31EB88 802BDE18 8C620000 */  lw        $v0, ($v1)
/* 31EB8C 802BDE1C 14400023 */  bnez      $v0, .L802BDEAC
/* 31EB90 802BDE20 00000000 */   nop      
/* 31EB94 802BDE24 868200B0 */  lh        $v0, 0xb0($s4)
/* 31EB98 802BDE28 3C013F00 */  lui       $at, 0x3f00
/* 31EB9C 802BDE2C 44811000 */  mtc1      $at, $f2
/* 31EBA0 802BDE30 44820000 */  mtc1      $v0, $f0
/* 31EBA4 802BDE34 00000000 */  nop       
/* 31EBA8 802BDE38 46800020 */  cvt.s.w   $f0, $f0
/* 31EBAC 802BDE3C 46020002 */  mul.s     $f0, $f0, $f2
/* 31EBB0 802BDE40 00000000 */  nop       
/* 31EBB4 802BDE44 C682002C */  lwc1      $f2, 0x2c($s4)
/* 31EBB8 802BDE48 46001080 */  add.s     $f2, $f2, $f0
/* 31EBBC 802BDE4C 3C01802C */  lui       $at, 0x802c
/* 31EBC0 802BDE50 C420FEE0 */  lwc1      $f0, -0x120($at)
/* 31EBC4 802BDE54 4600103C */  c.lt.s    $f2, $f0
/* 31EBC8 802BDE58 00000000 */  nop       
/* 31EBCC 802BDE5C 45000013 */  bc1f      .L802BDEAC
/* 31EBD0 802BDE60 24050004 */   addiu    $a1, $zero, 4
/* 31EBD4 802BDE64 24060002 */  addiu     $a2, $zero, 2
/* 31EBD8 802BDE68 0000382D */  daddu     $a3, $zero, $zero
/* 31EBDC 802BDE6C 8E8400A4 */  lw        $a0, 0xa4($s4)
/* 31EBE0 802BDE70 2402000D */  addiu     $v0, $zero, 0xd
/* 31EBE4 802BDE74 AC710000 */  sw        $s1, ($v1)
/* 31EBE8 802BDE78 A28200BE */  sb        $v0, 0xbe($s4)
/* 31EBEC 802BDE7C AFA00010 */  sw        $zero, 0x10($sp)
/* 31EBF0 802BDE80 AFA00014 */  sw        $zero, 0x14($sp)
/* 31EBF4 802BDE84 0C0B77FE */  jal       func_802DDFF8
/* 31EBF8 802BDE88 AFA00018 */   sw       $zero, 0x18($sp)
/* 31EBFC 802BDE8C 0200202D */  daddu     $a0, $s0, $zero
/* 31EC00 802BDE90 24050004 */  addiu     $a1, $zero, 4
/* 31EC04 802BDE94 24060002 */  addiu     $a2, $zero, 2
/* 31EC08 802BDE98 0000382D */  daddu     $a3, $zero, $zero
/* 31EC0C 802BDE9C AFA00010 */  sw        $zero, 0x10($sp)
/* 31EC10 802BDEA0 AFA00014 */  sw        $zero, 0x14($sp)
/* 31EC14 802BDEA4 0C00F589 */  jal       func_8003D624
/* 31EC18 802BDEA8 AFA00018 */   sw       $zero, 0x18($sp)
.L802BDEAC:
/* 31EC1C 802BDEAC 3C03802C */  lui       $v1, 0x802c
/* 31EC20 802BDEB0 8C63FEE8 */  lw        $v1, -0x118($v1)
/* 31EC24 802BDEB4 2862000A */  slti      $v0, $v1, 0xa
/* 31EC28 802BDEB8 14400011 */  bnez      $v0, .L802BDF00
/* 31EC2C 802BDEBC 00000000 */   nop      
/* 31EC30 802BDEC0 8EA20008 */  lw        $v0, 8($s5)
/* 31EC34 802BDEC4 30420004 */  andi      $v0, $v0, 4
/* 31EC38 802BDEC8 10400003 */  beqz      $v0, .L802BDED8
/* 31EC3C 802BDECC 2862001E */   slti     $v0, $v1, 0x1e
/* 31EC40 802BDED0 1440000B */  bnez      $v0, .L802BDF00
/* 31EC44 802BDED4 00000000 */   nop      
.L802BDED8:
/* 31EC48 802BDED8 3C020007 */  lui       $v0, 7
/* 31EC4C 802BDEDC 3442000C */  ori       $v0, $v0, 0xc
/* 31EC50 802BDEE0 24040694 */  addiu     $a0, $zero, 0x694
/* 31EC54 802BDEE4 0000282D */  daddu     $a1, $zero, $zero
/* 31EC58 802BDEE8 2406FFFC */  addiu     $a2, $zero, -4
/* 31EC5C 802BDEEC 0C052742 */  jal       play_sound_at_npc
/* 31EC60 802BDEF0 AE020028 */   sw       $v0, 0x28($s0)
/* 31EC64 802BDEF4 24020003 */  addiu     $v0, $zero, 3
/* 31EC68 802BDEF8 3C01802C */  lui       $at, 0x802c
/* 31EC6C 802BDEFC AC22FEE4 */  sw        $v0, -0x11c($at)
.L802BDF00:
/* 31EC70 802BDF00 860200A8 */  lh        $v0, 0xa8($s0)
/* 31EC74 802BDF04 C6020038 */  lwc1      $f2, 0x38($s0)
/* 31EC78 802BDF08 3C013F00 */  lui       $at, 0x3f00
/* 31EC7C 802BDF0C 4481A000 */  mtc1      $at, $f20
/* 31EC80 802BDF10 44820000 */  mtc1      $v0, $f0
/* 31EC84 802BDF14 00000000 */  nop       
/* 31EC88 802BDF18 46800020 */  cvt.s.w   $f0, $f0
/* 31EC8C 802BDF1C 868200B0 */  lh        $v0, 0xb0($s4)
/* 31EC90 802BDF20 46140002 */  mul.s     $f0, $f0, $f20
/* 31EC94 802BDF24 00000000 */  nop       
/* 31EC98 802BDF28 E7A20030 */  swc1      $f2, 0x30($sp)
/* 31EC9C 802BDF2C C6040064 */  lwc1      $f4, 0x64($s0)
/* 31ECA0 802BDF30 C6060040 */  lwc1      $f6, 0x40($s0)
/* 31ECA4 802BDF34 44821000 */  mtc1      $v0, $f2
/* 31ECA8 802BDF38 00000000 */  nop       
/* 31ECAC 802BDF3C 468010A0 */  cvt.s.w   $f2, $f2
/* 31ECB0 802BDF40 27A2003C */  addiu     $v0, $sp, 0x3c
/* 31ECB4 802BDF44 46020000 */  add.s     $f0, $f0, $f2
/* 31ECB8 802BDF48 E7A40034 */  swc1      $f4, 0x34($sp)
/* 31ECBC 802BDF4C E7A60038 */  swc1      $f6, 0x38($sp)
/* 31ECC0 802BDF50 E7A0003C */  swc1      $f0, 0x3c($sp)
/* 31ECC4 802BDF54 AFA20010 */  sw        $v0, 0x10($sp)
/* 31ECC8 802BDF58 C600000C */  lwc1      $f0, 0xc($s0)
/* 31ECCC 802BDF5C E7A00014 */  swc1      $f0, 0x14($sp)
/* 31ECD0 802BDF60 860200A6 */  lh        $v0, 0xa6($s0)
/* 31ECD4 802BDF64 3C013E99 */  lui       $at, 0x3e99
/* 31ECD8 802BDF68 3421999A */  ori       $at, $at, 0x999a
/* 31ECDC 802BDF6C 44811000 */  mtc1      $at, $f2
/* 31ECE0 802BDF70 44820000 */  mtc1      $v0, $f0
/* 31ECE4 802BDF74 00000000 */  nop       
/* 31ECE8 802BDF78 46800020 */  cvt.s.w   $f0, $f0
/* 31ECEC 802BDF7C 46020002 */  mul.s     $f0, $f0, $f2
/* 31ECF0 802BDF80 00000000 */  nop       
/* 31ECF4 802BDF84 27A50030 */  addiu     $a1, $sp, 0x30
/* 31ECF8 802BDF88 27A60034 */  addiu     $a2, $sp, 0x34
/* 31ECFC 802BDF8C E7A00018 */  swc1      $f0, 0x18($sp)
/* 31ED00 802BDF90 8E040080 */  lw        $a0, 0x80($s0)
/* 31ED04 802BDF94 0C03748A */  jal       func_800DD228
/* 31ED08 802BDF98 27A70038 */   addiu    $a3, $sp, 0x38
/* 31ED0C 802BDF9C 04400039 */  bltz      $v0, .L802BE084
/* 31ED10 802BDFA0 24020003 */   addiu    $v0, $zero, 3
/* 31ED14 802BDFA4 860200A8 */  lh        $v0, 0xa8($s0)
/* 31ED18 802BDFA8 44822000 */  mtc1      $v0, $f4
/* 31ED1C 802BDFAC 00000000 */  nop       
/* 31ED20 802BDFB0 46802120 */  cvt.s.w   $f4, $f4
/* 31ED24 802BDFB4 46142102 */  mul.s     $f4, $f4, $f20
/* 31ED28 802BDFB8 00000000 */  nop       
/* 31ED2C 802BDFBC C6060064 */  lwc1      $f6, 0x64($s0)
/* 31ED30 802BDFC0 C7A00034 */  lwc1      $f0, 0x34($sp)
/* 31ED34 802BDFC4 C7A2003C */  lwc1      $f2, 0x3c($sp)
/* 31ED38 802BDFC8 46003001 */  sub.s     $f0, $f6, $f0
/* 31ED3C 802BDFCC 3C04802C */  lui       $a0, 0x802c
/* 31ED40 802BDFD0 8C84FEE8 */  lw        $a0, -0x118($a0)
/* 31ED44 802BDFD4 868200B0 */  lh        $v0, 0xb0($s4)
/* 31ED48 802BDFD8 46020000 */  add.s     $f0, $f0, $f2
/* 31ED4C 802BDFDC 44821000 */  mtc1      $v0, $f2
/* 31ED50 802BDFE0 00000000 */  nop       
/* 31ED54 802BDFE4 468010A0 */  cvt.s.w   $f2, $f2
/* 31ED58 802BDFE8 3C0238E3 */  lui       $v0, 0x38e3
/* 31ED5C 802BDFEC 34428E39 */  ori       $v0, $v0, 0x8e39
/* 31ED60 802BDFF0 00820018 */  mult      $a0, $v0
/* 31ED64 802BDFF4 46022100 */  add.s     $f4, $f4, $f2
/* 31ED68 802BDFF8 46040001 */  sub.s     $f0, $f0, $f4
/* 31ED6C 802BDFFC 3C013E4C */  lui       $at, 0x3e4c
/* 31ED70 802BE000 3421CCCD */  ori       $at, $at, 0xcccd
/* 31ED74 802BE004 44811000 */  mtc1      $at, $f2
/* 31ED78 802BE008 00000000 */  nop       
/* 31ED7C 802BE00C 46020002 */  mul.s     $f0, $f0, $f2
/* 31ED80 802BE010 00000000 */  nop       
/* 31ED84 802BE014 000417C3 */  sra       $v0, $a0, 0x1f
/* 31ED88 802BE018 00004010 */  mfhi      $t0
/* 31ED8C 802BE01C 00081843 */  sra       $v1, $t0, 1
/* 31ED90 802BE020 00621823 */  subu      $v1, $v1, $v0
/* 31ED94 802BE024 46003180 */  add.s     $f6, $f6, $f0
/* 31ED98 802BE028 000310C0 */  sll       $v0, $v1, 3
/* 31ED9C 802BE02C 00431021 */  addu      $v0, $v0, $v1
/* 31EDA0 802BE030 14820086 */  bne       $a0, $v0, .L802BE24C
/* 31EDA4 802BE034 E6060064 */   swc1     $f6, 0x64($s0)
/* 31EDA8 802BE038 860200A8 */  lh        $v0, 0xa8($s0)
/* 31EDAC 802BE03C 44821000 */  mtc1      $v0, $f2
/* 31EDB0 802BE040 00000000 */  nop       
/* 31EDB4 802BE044 468010A0 */  cvt.s.w   $f2, $f2
/* 31EDB8 802BE048 46141082 */  mul.s     $f2, $f2, $f20
/* 31EDBC 802BE04C 00000000 */  nop       
/* 31EDC0 802BE050 3C01802C */  lui       $at, 0x802c
/* 31EDC4 802BE054 C420FEE0 */  lwc1      $f0, -0x120($at)
/* 31EDC8 802BE058 46060001 */  sub.s     $f0, $f0, $f6
/* 31EDCC 802BE05C 46023180 */  add.s     $f6, $f6, $f2
/* 31EDD0 802BE060 46020001 */  sub.s     $f0, $f0, $f2
/* 31EDD4 802BE064 44063000 */  mfc1      $a2, $f6
/* 31EDD8 802BE068 E7A00010 */  swc1      $f0, 0x10($sp)
/* 31EDDC 802BE06C 8E050038 */  lw        $a1, 0x38($s0)
/* 31EDE0 802BE070 8E070040 */  lw        $a3, 0x40($s0)
/* 31EDE4 802BE074 0C01C16C */  jal       func_800705B0
/* 31EDE8 802BE078 0000202D */   daddu    $a0, $zero, $zero
/* 31EDEC 802BE07C 080AF893 */  j         .L802BE24C
/* 31EDF0 802BE080 00000000 */   nop      
.L802BE084:
/* 31EDF4 802BE084 3C12802C */  lui       $s2, 0x802c
/* 31EDF8 802BE088 2652FEE4 */  addiu     $s2, $s2, -0x11c
/* 31EDFC 802BE08C 8E430000 */  lw        $v1, ($s2)
/* 31EE00 802BE090 1462006E */  bne       $v1, $v0, .L802BE24C
/* 31EE04 802BE094 00000000 */   nop      
/* 31EE08 802BE098 3C03802C */  lui       $v1, 0x802c
/* 31EE0C 802BE09C 2463FF08 */  addiu     $v1, $v1, -0xf8
/* 31EE10 802BE0A0 C4600000 */  lwc1      $f0, ($v1)
/* 31EE14 802BE0A4 3C01802C */  lui       $at, 0x802c
/* 31EE18 802BE0A8 D422FE58 */  ldc1      $f2, -0x1a8($at)
/* 31EE1C 802BE0AC 46000021 */  cvt.d.s   $f0, $f0
/* 31EE20 802BE0B0 46220000 */  add.d     $f0, $f0, $f2
/* 31EE24 802BE0B4 3C01802C */  lui       $at, 0x802c
/* 31EE28 802BE0B8 D424FE60 */  ldc1      $f4, -0x1a0($at)
/* 31EE2C 802BE0BC 46200020 */  cvt.s.d   $f0, $f0
/* 31EE30 802BE0C0 460000A1 */  cvt.d.s   $f2, $f0
/* 31EE34 802BE0C4 4622203C */  c.lt.d    $f4, $f2
/* 31EE38 802BE0C8 00000000 */  nop       
/* 31EE3C 802BE0CC 45000006 */  bc1f      .L802BE0E8
/* 31EE40 802BE0D0 E4600000 */   swc1     $f0, ($v1)
/* 31EE44 802BE0D4 3C013FE6 */  lui       $at, 0x3fe6
/* 31EE48 802BE0D8 34216666 */  ori       $at, $at, 0x6666
/* 31EE4C 802BE0DC 44810000 */  mtc1      $at, $f0
/* 31EE50 802BE0E0 00000000 */  nop       
/* 31EE54 802BE0E4 E4600000 */  swc1      $f0, ($v1)
.L802BE0E8:
/* 31EE58 802BE0E8 3C0238E3 */  lui       $v0, 0x38e3
/* 31EE5C 802BE0EC 3C04802C */  lui       $a0, 0x802c
/* 31EE60 802BE0F0 8C84FEE8 */  lw        $a0, -0x118($a0)
/* 31EE64 802BE0F4 34428E39 */  ori       $v0, $v0, 0x8e39
/* 31EE68 802BE0F8 00820018 */  mult      $a0, $v0
/* 31EE6C 802BE0FC C6020064 */  lwc1      $f2, 0x64($s0)
/* 31EE70 802BE100 C4600000 */  lwc1      $f0, ($v1)
/* 31EE74 802BE104 46001100 */  add.s     $f4, $f2, $f0
/* 31EE78 802BE108 000417C3 */  sra       $v0, $a0, 0x1f
/* 31EE7C 802BE10C 00004010 */  mfhi      $t0
/* 31EE80 802BE110 00081843 */  sra       $v1, $t0, 1
/* 31EE84 802BE114 00621823 */  subu      $v1, $v1, $v0
/* 31EE88 802BE118 000310C0 */  sll       $v0, $v1, 3
/* 31EE8C 802BE11C 00431021 */  addu      $v0, $v0, $v1
/* 31EE90 802BE120 14820012 */  bne       $a0, $v0, .L802BE16C
/* 31EE94 802BE124 E6040064 */   swc1     $f4, 0x64($s0)
/* 31EE98 802BE128 860200A8 */  lh        $v0, 0xa8($s0)
/* 31EE9C 802BE12C 44821000 */  mtc1      $v0, $f2
/* 31EEA0 802BE130 00000000 */  nop       
/* 31EEA4 802BE134 468010A0 */  cvt.s.w   $f2, $f2
/* 31EEA8 802BE138 46141082 */  mul.s     $f2, $f2, $f20
/* 31EEAC 802BE13C 00000000 */  nop       
/* 31EEB0 802BE140 3C01802C */  lui       $at, 0x802c
/* 31EEB4 802BE144 C420FEE0 */  lwc1      $f0, -0x120($at)
/* 31EEB8 802BE148 46040001 */  sub.s     $f0, $f0, $f4
/* 31EEBC 802BE14C 46022100 */  add.s     $f4, $f4, $f2
/* 31EEC0 802BE150 46020001 */  sub.s     $f0, $f0, $f2
/* 31EEC4 802BE154 44062000 */  mfc1      $a2, $f4
/* 31EEC8 802BE158 E7A00010 */  swc1      $f0, 0x10($sp)
/* 31EECC 802BE15C 8E050038 */  lw        $a1, 0x38($s0)
/* 31EED0 802BE160 8E070040 */  lw        $a3, 0x40($s0)
/* 31EED4 802BE164 0C01C16C */  jal       func_800705B0
/* 31EED8 802BE168 0000202D */   daddu    $a0, $zero, $zero
.L802BE16C:
/* 31EEDC 802BE16C 860200A8 */  lh        $v0, 0xa8($s0)
/* 31EEE0 802BE170 44822000 */  mtc1      $v0, $f4
/* 31EEE4 802BE174 00000000 */  nop       
/* 31EEE8 802BE178 46802120 */  cvt.s.w   $f4, $f4
/* 31EEEC 802BE17C 46142102 */  mul.s     $f4, $f4, $f20
/* 31EEF0 802BE180 00000000 */  nop       
/* 31EEF4 802BE184 3C11802C */  lui       $s1, 0x802c
/* 31EEF8 802BE188 2631FEE0 */  addiu     $s1, $s1, -0x120
/* 31EEFC 802BE18C C6200000 */  lwc1      $f0, ($s1)
/* 31EF00 802BE190 C6020064 */  lwc1      $f2, 0x64($s0)
/* 31EF04 802BE194 46020001 */  sub.s     $f0, $f0, $f2
/* 31EF08 802BE198 46040001 */  sub.s     $f0, $f0, $f4
/* 31EF0C 802BE19C 44801000 */  mtc1      $zero, $f2
/* 31EF10 802BE1A0 00000000 */  nop       
/* 31EF14 802BE1A4 4602003E */  c.le.s    $f0, $f2
/* 31EF18 802BE1A8 00000000 */  nop       
/* 31EF1C 802BE1AC 45000027 */  bc1f      .L802BE24C
/* 31EF20 802BE1B0 00000000 */   nop      
/* 31EF24 802BE1B4 3C03802C */  lui       $v1, 0x802c
/* 31EF28 802BE1B8 2463FEF4 */  addiu     $v1, $v1, -0x10c
/* 31EF2C 802BE1BC 8C620000 */  lw        $v0, ($v1)
/* 31EF30 802BE1C0 10400012 */  beqz      $v0, .L802BE20C
/* 31EF34 802BE1C4 3C040001 */   lui      $a0, 1
/* 31EF38 802BE1C8 34840002 */  ori       $a0, $a0, 2
/* 31EF3C 802BE1CC 0000282D */  daddu     $a1, $zero, $zero
/* 31EF40 802BE1D0 00A0302D */  daddu     $a2, $a1, $zero
/* 31EF44 802BE1D4 00A0382D */  daddu     $a3, $a1, $zero
/* 31EF48 802BE1D8 AC600000 */  sw        $zero, ($v1)
/* 31EF4C 802BE1DC AFA00010 */  sw        $zero, 0x10($sp)
/* 31EF50 802BE1E0 AFA00014 */  sw        $zero, 0x14($sp)
/* 31EF54 802BE1E4 0C0B77FE */  jal       func_802DDFF8
/* 31EF58 802BE1E8 AFA00018 */   sw       $zero, 0x18($sp)
/* 31EF5C 802BE1EC 0200202D */  daddu     $a0, $s0, $zero
/* 31EF60 802BE1F0 0000282D */  daddu     $a1, $zero, $zero
/* 31EF64 802BE1F4 00A0302D */  daddu     $a2, $a1, $zero
/* 31EF68 802BE1F8 00A0382D */  daddu     $a3, $a1, $zero
/* 31EF6C 802BE1FC AFA00010 */  sw        $zero, 0x10($sp)
/* 31EF70 802BE200 AFA00014 */  sw        $zero, 0x14($sp)
/* 31EF74 802BE204 0C00F589 */  jal       func_8003D624
/* 31EF78 802BE208 AFA00018 */   sw       $zero, 0x18($sp)
.L802BE20C:
/* 31EF7C 802BE20C 860200A8 */  lh        $v0, 0xa8($s0)
/* 31EF80 802BE210 3C030007 */  lui       $v1, 7
/* 31EF84 802BE214 44821000 */  mtc1      $v0, $f2
/* 31EF88 802BE218 00000000 */  nop       
/* 31EF8C 802BE21C 468010A0 */  cvt.s.w   $f2, $f2
/* 31EF90 802BE220 46141082 */  mul.s     $f2, $f2, $f20
/* 31EF94 802BE224 00000000 */  nop       
/* 31EF98 802BE228 3463000A */  ori       $v1, $v1, 0xa
/* 31EF9C 802BE22C 3C040008 */  lui       $a0, 8
/* 31EFA0 802BE230 C6200000 */  lwc1      $f0, ($s1)
/* 31EFA4 802BE234 3484000F */  ori       $a0, $a0, 0xf
/* 31EFA8 802BE238 46020001 */  sub.s     $f0, $f0, $f2
/* 31EFAC 802BE23C AE400000 */  sw        $zero, ($s2)
/* 31EFB0 802BE240 AE030028 */  sw        $v1, 0x28($s0)
/* 31EFB4 802BE244 0C037FDE */  jal       func_800DFF78
/* 31EFB8 802BE248 E6000064 */   swc1     $f0, 0x64($s0)
.L802BE24C:
/* 31EFBC 802BE24C 8FBF0058 */  lw        $ra, 0x58($sp)
/* 31EFC0 802BE250 8FB50054 */  lw        $s5, 0x54($sp)
/* 31EFC4 802BE254 8FB40050 */  lw        $s4, 0x50($sp)
/* 31EFC8 802BE258 8FB3004C */  lw        $s3, 0x4c($sp)
/* 31EFCC 802BE25C 8FB20048 */  lw        $s2, 0x48($sp)
/* 31EFD0 802BE260 8FB10044 */  lw        $s1, 0x44($sp)
/* 31EFD4 802BE264 8FB00040 */  lw        $s0, 0x40($sp)
/* 31EFD8 802BE268 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* 31EFDC 802BE26C D7B80070 */  ldc1      $f24, 0x70($sp)
/* 31EFE0 802BE270 D7B60068 */  ldc1      $f22, 0x68($sp)
/* 31EFE4 802BE274 D7B40060 */  ldc1      $f20, 0x60($sp)
/* 31EFE8 802BE278 03E00008 */  jr        $ra
/* 31EFEC 802BE27C 27BD0080 */   addiu    $sp, $sp, 0x80
