.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_8029CD90
.double 0.8

.section .text

glabel func_8024F394
/* 17DC74 8024F394 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 17DC78 8024F398 AFB40020 */  sw        $s4, 0x20($sp)
/* 17DC7C 8024F39C 0080A02D */  daddu     $s4, $a0, $zero
/* 17DC80 8024F3A0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 17DC84 8024F3A4 0000982D */  daddu     $s3, $zero, $zero
/* 17DC88 8024F3A8 AFB50024 */  sw        $s5, 0x24($sp)
/* 17DC8C 8024F3AC AFBF0028 */  sw        $ra, 0x28($sp)
/* 17DC90 8024F3B0 AFB20018 */  sw        $s2, 0x18($sp)
/* 17DC94 8024F3B4 AFB10014 */  sw        $s1, 0x14($sp)
/* 17DC98 8024F3B8 AFB00010 */  sw        $s0, 0x10($sp)
/* 17DC9C 8024F3BC F7B40030 */  sdc1      $f20, 0x30($sp)
/* 17DCA0 8024F3C0 86820012 */  lh        $v0, 0x12($s4)
/* 17DCA4 8024F3C4 8E920018 */  lw        $s2, 0x18($s4)
/* 17DCA8 8024F3C8 18400067 */  blez      $v0, .L8024F568
/* 17DCAC 8024F3CC 0260A82D */   daddu    $s5, $s3, $zero
/* 17DCB0 8024F3D0 3C013FE0 */  lui       $at, 0x3fe0
/* 17DCB4 8024F3D4 4481A800 */  mtc1      $at, $f21
/* 17DCB8 8024F3D8 4480A000 */  mtc1      $zero, $f20
/* 17DCBC 8024F3DC 26500044 */  addiu     $s0, $s2, 0x44
.L8024F3E0:
/* 17DCC0 8024F3E0 8E420000 */  lw        $v0, ($s2)
/* 17DCC4 8024F3E4 5040005B */  beql      $v0, $zero, .L8024F554
/* 17DCC8 8024F3E8 26730001 */   addiu    $s3, $s3, 1
/* 17DCCC 8024F3EC 8E02FFE0 */  lw        $v0, -0x20($s0)
/* 17DCD0 8024F3F0 8E11FFC0 */  lw        $s1, -0x40($s0)
/* 17DCD4 8024F3F4 1040000B */  beqz      $v0, .L8024F424
/* 17DCD8 8024F3F8 24150001 */   addiu    $s5, $zero, 1
/* 17DCDC 8024F3FC 2442FFFF */  addiu     $v0, $v0, -1
/* 17DCE0 8024F400 14400004 */  bnez      $v0, .L8024F414
/* 17DCE4 8024F404 AE02FFE0 */   sw       $v0, -0x20($s0)
/* 17DCE8 8024F408 0220202D */  daddu     $a0, $s1, $zero
/* 17DCEC 8024F40C 0C048BC9 */  jal       clear_entity_model_flags
/* 17DCF0 8024F410 24050020 */   addiu    $a1, $zero, 0x20
.L8024F414:
/* 17DCF4 8024F414 0C0483C1 */  jal       exec_entity_model_commandlist
/* 17DCF8 8024F418 0220202D */   daddu    $a0, $s1, $zero
/* 17DCFC 8024F41C 08093D5A */  j         .L8024F568
/* 17DD00 8024F420 00000000 */   nop
.L8024F424:
/* 17DD04 8024F424 0C0483C1 */  jal       exec_entity_model_commandlist
/* 17DD08 8024F428 0220202D */   daddu    $a0, $s1, $zero
/* 17DD0C 8024F42C 8E02FFDC */  lw        $v0, -0x24($s0)
/* 17DD10 8024F430 0440000D */  bltz      $v0, .L8024F468
/* 17DD14 8024F434 00000000 */   nop
/* 17DD18 8024F438 C606FFF4 */  lwc1      $f6, -0xc($s0)
/* 17DD1C 8024F43C C600FFD0 */  lwc1      $f0, -0x30($s0)
/* 17DD20 8024F440 C604FFF8 */  lwc1      $f4, -8($s0)
/* 17DD24 8024F444 46003180 */  add.s     $f6, $f6, $f0
/* 17DD28 8024F448 C600FFD4 */  lwc1      $f0, -0x2c($s0)
/* 17DD2C 8024F44C C602FFFC */  lwc1      $f2, -4($s0)
/* 17DD30 8024F450 46002100 */  add.s     $f4, $f4, $f0
/* 17DD34 8024F454 C600FFD8 */  lwc1      $f0, -0x28($s0)
/* 17DD38 8024F458 46001080 */  add.s     $f2, $f2, $f0
/* 17DD3C 8024F45C E606FFF4 */  swc1      $f6, -0xc($s0)
/* 17DD40 8024F460 E604FFF8 */  swc1      $f4, -8($s0)
/* 17DD44 8024F464 E602FFFC */  swc1      $f2, -4($s0)
.L8024F468:
/* 17DD48 8024F468 3C01800B */  lui       $at, %hi(gCameras+0x5C4)
/* 17DD4C 8024F46C C4202344 */  lwc1      $f0, %lo(gCameras+0x5C4)($at)
/* 17DD50 8024F470 3C014334 */  lui       $at, 0x4334
/* 17DD54 8024F474 44816000 */  mtc1      $at, $f12
/* 17DD58 8024F478 0C00A6C9 */  jal       clamp_angle
/* 17DD5C 8024F47C 46006301 */   sub.s    $f12, $f12, $f0
/* 17DD60 8024F480 C60CFFE4 */  lwc1      $f12, -0x1c($s0)
/* 17DD64 8024F484 C602FFE8 */  lwc1      $f2, -0x18($s0)
/* 17DD68 8024F488 46026300 */  add.s     $f12, $f12, $f2
/* 17DD6C 8024F48C E600FFEC */  swc1      $f0, -0x14($s0)
/* 17DD70 8024F490 0C00A6C9 */  jal       clamp_angle
/* 17DD74 8024F494 E60CFFE4 */   swc1     $f12, -0x1c($s0)
/* 17DD78 8024F498 C602FFE8 */  lwc1      $f2, -0x18($s0)
/* 17DD7C 8024F49C 3C01802A */  lui       $at, %hi(D_8029CD90)
/* 17DD80 8024F4A0 D424CD90 */  ldc1      $f4, %lo(D_8029CD90)($at)
/* 17DD84 8024F4A4 460010A1 */  cvt.d.s   $f2, $f2
/* 17DD88 8024F4A8 46241082 */  mul.d     $f2, $f2, $f4
/* 17DD8C 8024F4AC 00000000 */  nop
/* 17DD90 8024F4B0 8E02FFDC */  lw        $v0, -0x24($s0)
/* 17DD94 8024F4B4 E600FFE4 */  swc1      $f0, -0x1c($s0)
/* 17DD98 8024F4B8 2842000A */  slti      $v0, $v0, 0xa
/* 17DD9C 8024F4BC 462010A0 */  cvt.s.d   $f2, $f2
/* 17DDA0 8024F4C0 10400018 */  beqz      $v0, .L8024F524
/* 17DDA4 8024F4C4 E602FFE8 */   swc1     $f2, -0x18($s0)
/* 17DDA8 8024F4C8 C604FFC4 */  lwc1      $f4, -0x3c($s0)
/* 17DDAC 8024F4CC 46002121 */  cvt.d.s   $f4, $f4
/* 17DDB0 8024F4D0 46342102 */  mul.d     $f4, $f4, $f20
/* 17DDB4 8024F4D4 00000000 */  nop
/* 17DDB8 8024F4D8 C600FFCC */  lwc1      $f0, -0x34($s0)
/* 17DDBC 8024F4DC 46000021 */  cvt.d.s   $f0, $f0
/* 17DDC0 8024F4E0 46340002 */  mul.d     $f0, $f0, $f20
/* 17DDC4 8024F4E4 00000000 */  nop
/* 17DDC8 8024F4E8 C602FFC8 */  lwc1      $f2, -0x38($s0)
/* 17DDCC 8024F4EC 460010A1 */  cvt.d.s   $f2, $f2
/* 17DDD0 8024F4F0 46341082 */  mul.d     $f2, $f2, $f20
/* 17DDD4 8024F4F4 00000000 */  nop
/* 17DDD8 8024F4F8 46202120 */  cvt.s.d   $f4, $f4
/* 17DDDC 8024F4FC 46200020 */  cvt.s.d   $f0, $f0
/* 17DDE0 8024F500 E604FFC4 */  swc1      $f4, -0x3c($s0)
/* 17DDE4 8024F504 E600FFCC */  swc1      $f0, -0x34($s0)
/* 17DDE8 8024F508 46002006 */  mov.s     $f0, $f4
/* 17DDEC 8024F50C C604FFCC */  lwc1      $f4, -0x34($s0)
/* 17DDF0 8024F510 462010A0 */  cvt.s.d   $f2, $f2
/* 17DDF4 8024F514 E602FFC8 */  swc1      $f2, -0x38($s0)
/* 17DDF8 8024F518 E600FFD0 */  swc1      $f0, -0x30($s0)
/* 17DDFC 8024F51C E602FFD4 */  swc1      $f2, -0x2c($s0)
/* 17DE00 8024F520 E604FFD8 */  swc1      $f4, -0x28($s0)
.L8024F524:
/* 17DE04 8024F524 8E02FFDC */  lw        $v0, -0x24($s0)
/* 17DE08 8024F528 2442FFFF */  addiu     $v0, $v0, -1
/* 17DE0C 8024F52C 04410008 */  bgez      $v0, .L8024F550
/* 17DE10 8024F530 AE02FFDC */   sw       $v0, -0x24($s0)
/* 17DE14 8024F534 8E020000 */  lw        $v0, ($s0)
/* 17DE18 8024F538 2442FFFF */  addiu     $v0, $v0, -1
/* 17DE1C 8024F53C 04410004 */  bgez      $v0, .L8024F550
/* 17DE20 8024F540 AE020000 */   sw       $v0, ($s0)
/* 17DE24 8024F544 0C048B7F */  jal       free_entity_model_by_index
/* 17DE28 8024F548 0220202D */   daddu    $a0, $s1, $zero
/* 17DE2C 8024F54C AE400000 */  sw        $zero, ($s2)
.L8024F550:
/* 17DE30 8024F550 26730001 */  addiu     $s3, $s3, 1
.L8024F554:
/* 17DE34 8024F554 2610004C */  addiu     $s0, $s0, 0x4c
/* 17DE38 8024F558 86820012 */  lh        $v0, 0x12($s4)
/* 17DE3C 8024F55C 0262102A */  slt       $v0, $s3, $v0
/* 17DE40 8024F560 1440FF9F */  bnez      $v0, .L8024F3E0
/* 17DE44 8024F564 2652004C */   addiu    $s2, $s2, 0x4c
.L8024F568:
/* 17DE48 8024F568 16A00006 */  bnez      $s5, .L8024F584
/* 17DE4C 8024F56C 00000000 */   nop
/* 17DE50 8024F570 0C00AB4B */  jal       heap_free
/* 17DE54 8024F574 8E840018 */   lw       $a0, 0x18($s4)
/* 17DE58 8024F578 0280202D */  daddu     $a0, $s4, $zero
/* 17DE5C 8024F57C 0C093BE9 */  jal       free_popup
/* 17DE60 8024F580 AC800018 */   sw       $zero, 0x18($a0)
.L8024F584:
/* 17DE64 8024F584 8FBF0028 */  lw        $ra, 0x28($sp)
/* 17DE68 8024F588 8FB50024 */  lw        $s5, 0x24($sp)
/* 17DE6C 8024F58C 8FB40020 */  lw        $s4, 0x20($sp)
/* 17DE70 8024F590 8FB3001C */  lw        $s3, 0x1c($sp)
/* 17DE74 8024F594 8FB20018 */  lw        $s2, 0x18($sp)
/* 17DE78 8024F598 8FB10014 */  lw        $s1, 0x14($sp)
/* 17DE7C 8024F59C 8FB00010 */  lw        $s0, 0x10($sp)
/* 17DE80 8024F5A0 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 17DE84 8024F5A4 03E00008 */  jr        $ra
/* 17DE88 8024F5A8 27BD0038 */   addiu    $sp, $sp, 0x38
