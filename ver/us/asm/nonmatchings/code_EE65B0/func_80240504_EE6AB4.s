.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240504_EE6AB4
/* EE6AB4 80240504 27BDFF88 */  addiu     $sp, $sp, -0x78
/* EE6AB8 80240508 AFBF0064 */  sw        $ra, 0x64($sp)
/* EE6ABC 8024050C AFB00060 */  sw        $s0, 0x60($sp)
/* EE6AC0 80240510 F7B60070 */  sdc1      $f22, 0x70($sp)
/* EE6AC4 80240514 F7B40068 */  sdc1      $f20, 0x68($sp)
/* EE6AC8 80240518 0C01B198 */  jal       __osGetCause
/* EE6ACC 8024051C 27A40010 */   addiu    $a0, $sp, 0x10
/* EE6AD0 80240520 3C108024 */  lui       $s0, %hi(D_80243B44_EEA0F4)
/* EE6AD4 80240524 26103B44 */  addiu     $s0, $s0, %lo(D_80243B44_EEA0F4)
/* EE6AD8 80240528 C6000000 */  lwc1      $f0, ($s0)
/* EE6ADC 8024052C 3C014130 */  lui       $at, 0x4130
/* EE6AE0 80240530 44816000 */  mtc1      $at, $f12
/* EE6AE4 80240534 0C00AD17 */  jal       func_8002B45C
/* EE6AE8 80240538 460C0303 */   div.s    $f12, $f0, $f12
/* EE6AEC 8024053C 3C018024 */  lui       $at, %hi(D_80245350_EEB900)
/* EE6AF0 80240540 D4345350 */  ldc1      $f20, %lo(D_80245350_EEB900)($at)
/* EE6AF4 80240544 46000021 */  cvt.d.s   $f0, $f0
/* EE6AF8 80240548 46340002 */  mul.d     $f0, $f0, $f20
/* EE6AFC 8024054C 00000000 */  nop
/* EE6B00 80240550 3C018024 */  lui       $at, %hi(D_80245358_EEB908)
/* EE6B04 80240554 D4365358 */  ldc1      $f22, %lo(D_80245358_EEB908)($at)
/* EE6B08 80240558 C6020000 */  lwc1      $f2, ($s0)
/* EE6B0C 8024055C 3C014140 */  lui       $at, 0x4140
/* EE6B10 80240560 44816000 */  mtc1      $at, $f12
/* EE6B14 80240564 46360000 */  add.d     $f0, $f0, $f22
/* EE6B18 80240568 460C1303 */  div.s     $f12, $f2, $f12
/* EE6B1C 8024056C 46200020 */  cvt.s.d   $f0, $f0
/* EE6B20 80240570 0C00AD17 */  jal       func_8002B45C
/* EE6B24 80240574 E7A00010 */   swc1     $f0, 0x10($sp)
/* EE6B28 80240578 46000021 */  cvt.d.s   $f0, $f0
/* EE6B2C 8024057C 46340002 */  mul.d     $f0, $f0, $f20
/* EE6B30 80240580 00000000 */  nop
/* EE6B34 80240584 C6020000 */  lwc1      $f2, ($s0)
/* EE6B38 80240588 3C014150 */  lui       $at, 0x4150
/* EE6B3C 8024058C 44816000 */  mtc1      $at, $f12
/* EE6B40 80240590 00000000 */  nop
/* EE6B44 80240594 460C1303 */  div.s     $f12, $f2, $f12
/* EE6B48 80240598 46200020 */  cvt.s.d   $f0, $f0
/* EE6B4C 8024059C 0C00AD30 */  jal       dead_cos_rad
/* EE6B50 802405A0 E7A00014 */   swc1     $f0, 0x14($sp)
/* EE6B54 802405A4 46000021 */  cvt.d.s   $f0, $f0
/* EE6B58 802405A8 46340002 */  mul.d     $f0, $f0, $f20
/* EE6B5C 802405AC 00000000 */  nop
/* EE6B60 802405B0 C60C0000 */  lwc1      $f12, ($s0)
/* EE6B64 802405B4 3C0140E0 */  lui       $at, 0x40e0
/* EE6B68 802405B8 44811000 */  mtc1      $at, $f2
/* EE6B6C 802405BC 3C013F80 */  lui       $at, 0x3f80
/* EE6B70 802405C0 44812000 */  mtc1      $at, $f4
/* EE6B74 802405C4 46026303 */  div.s     $f12, $f12, $f2
/* EE6B78 802405C8 46046300 */  add.s     $f12, $f12, $f4
/* EE6B7C 802405CC 46200020 */  cvt.s.d   $f0, $f0
/* EE6B80 802405D0 0C00AD17 */  jal       func_8002B45C
/* EE6B84 802405D4 E7A00018 */   swc1     $f0, 0x18($sp)
/* EE6B88 802405D8 46000021 */  cvt.d.s   $f0, $f0
/* EE6B8C 802405DC 46340002 */  mul.d     $f0, $f0, $f20
/* EE6B90 802405E0 00000000 */  nop
/* EE6B94 802405E4 C6020000 */  lwc1      $f2, ($s0)
/* EE6B98 802405E8 3C014160 */  lui       $at, 0x4160
/* EE6B9C 802405EC 44816000 */  mtc1      $at, $f12
/* EE6BA0 802405F0 46360000 */  add.d     $f0, $f0, $f22
/* EE6BA4 802405F4 460C1303 */  div.s     $f12, $f2, $f12
/* EE6BA8 802405F8 46200020 */  cvt.s.d   $f0, $f0
/* EE6BAC 802405FC 0C00AD17 */  jal       func_8002B45C
/* EE6BB0 80240600 E7A00024 */   swc1     $f0, 0x24($sp)
/* EE6BB4 80240604 46000021 */  cvt.d.s   $f0, $f0
/* EE6BB8 80240608 46340002 */  mul.d     $f0, $f0, $f20
/* EE6BBC 8024060C 00000000 */  nop
/* EE6BC0 80240610 C6020000 */  lwc1      $f2, ($s0)
/* EE6BC4 80240614 3C014170 */  lui       $at, 0x4170
/* EE6BC8 80240618 44816000 */  mtc1      $at, $f12
/* EE6BCC 8024061C 00000000 */  nop
/* EE6BD0 80240620 460C1303 */  div.s     $f12, $f2, $f12
/* EE6BD4 80240624 46200020 */  cvt.s.d   $f0, $f0
/* EE6BD8 80240628 0C00AD30 */  jal       dead_cos_rad
/* EE6BDC 8024062C E7A00020 */   swc1     $f0, 0x20($sp)
/* EE6BE0 80240630 46000021 */  cvt.d.s   $f0, $f0
/* EE6BE4 80240634 46340002 */  mul.d     $f0, $f0, $f20
/* EE6BE8 80240638 00000000 */  nop
/* EE6BEC 8024063C C60C0000 */  lwc1      $f12, ($s0)
/* EE6BF0 80240640 3C013E80 */  lui       $at, 0x3e80
/* EE6BF4 80240644 44811000 */  mtc1      $at, $f2
/* EE6BF8 80240648 00000000 */  nop
/* EE6BFC 8024064C 46026302 */  mul.s     $f12, $f12, $f2
/* EE6C00 80240650 00000000 */  nop
/* EE6C04 80240654 3C014000 */  lui       $at, 0x4000
/* EE6C08 80240658 44811000 */  mtc1      $at, $f2
/* EE6C0C 8024065C 00000000 */  nop
/* EE6C10 80240660 46026300 */  add.s     $f12, $f12, $f2
/* EE6C14 80240664 46200020 */  cvt.s.d   $f0, $f0
/* EE6C18 80240668 0C00AD17 */  jal       func_8002B45C
/* EE6C1C 8024066C E7A00028 */   swc1     $f0, 0x28($sp)
/* EE6C20 80240670 46000021 */  cvt.d.s   $f0, $f0
/* EE6C24 80240674 46340002 */  mul.d     $f0, $f0, $f20
/* EE6C28 80240678 00000000 */  nop
/* EE6C2C 8024067C C6020000 */  lwc1      $f2, ($s0)
/* EE6C30 80240680 3C013D80 */  lui       $at, 0x3d80
/* EE6C34 80240684 44816000 */  mtc1      $at, $f12
/* EE6C38 80240688 00000000 */  nop
/* EE6C3C 8024068C 460C1302 */  mul.s     $f12, $f2, $f12
/* EE6C40 80240690 00000000 */  nop
/* EE6C44 80240694 46360000 */  add.d     $f0, $f0, $f22
/* EE6C48 80240698 46200020 */  cvt.s.d   $f0, $f0
/* EE6C4C 8024069C 0C00AD17 */  jal       func_8002B45C
/* EE6C50 802406A0 E7A00038 */   swc1     $f0, 0x38($sp)
/* EE6C54 802406A4 46000021 */  cvt.d.s   $f0, $f0
/* EE6C58 802406A8 46340002 */  mul.d     $f0, $f0, $f20
/* EE6C5C 802406AC 00000000 */  nop
/* EE6C60 802406B0 C6020000 */  lwc1      $f2, ($s0)
/* EE6C64 802406B4 3C014188 */  lui       $at, 0x4188
/* EE6C68 802406B8 44816000 */  mtc1      $at, $f12
/* EE6C6C 802406BC 00000000 */  nop
/* EE6C70 802406C0 460C1303 */  div.s     $f12, $f2, $f12
/* EE6C74 802406C4 46200020 */  cvt.s.d   $f0, $f0
/* EE6C78 802406C8 0C00AD30 */  jal       dead_cos_rad
/* EE6C7C 802406CC E7A00030 */   swc1     $f0, 0x30($sp)
/* EE6C80 802406D0 3C030001 */  lui       $v1, 1
/* EE6C84 802406D4 46000021 */  cvt.d.s   $f0, $f0
/* EE6C88 802406D8 46340002 */  mul.d     $f0, $f0, $f20
/* EE6C8C 802406DC 00000000 */  nop
/* EE6C90 802406E0 34631630 */  ori       $v1, $v1, 0x1630
/* EE6C94 802406E4 27A40010 */  addiu     $a0, $sp, 0x10
/* EE6C98 802406E8 3C058008 */  lui       $a1, %hi(D_80079540)
/* EE6C9C 802406EC 94A59540 */  lhu       $a1, %lo(D_80079540)($a1)
/* EE6CA0 802406F0 3C02800A */  lui       $v0, %hi(D_800A15CC)
/* EE6CA4 802406F4 8C4215CC */  lw        $v0, %lo(D_800A15CC)($v0)
/* EE6CA8 802406F8 00052980 */  sll       $a1, $a1, 6
/* EE6CAC 802406FC 00A32821 */  addu      $a1, $a1, $v1
/* EE6CB0 80240700 00452821 */  addu      $a1, $v0, $a1
/* EE6CB4 80240704 46200020 */  cvt.s.d   $f0, $f0
/* EE6CB8 80240708 0C01B1B0 */  jal       osSpDeviceBusy
/* EE6CBC 8024070C E7A00034 */   swc1     $f0, 0x34($sp)
/* EE6CC0 80240710 0000202D */  daddu     $a0, $zero, $zero
/* EE6CC4 80240714 27A50050 */  addiu     $a1, $sp, 0x50
/* EE6CC8 80240718 27A60054 */  addiu     $a2, $sp, 0x54
/* EE6CCC 8024071C 0C0499BE */  jal       func_801266F8
/* EE6CD0 80240720 27A70058 */   addiu    $a3, $sp, 0x58
/* EE6CD4 80240724 3C03DA38 */  lui       $v1, 0xda38
/* EE6CD8 80240728 34630001 */  ori       $v1, $v1, 1
/* EE6CDC 8024072C 3C080001 */  lui       $t0, 1
/* EE6CE0 80240730 35081630 */  ori       $t0, $t0, 0x1630
/* EE6CE4 80240734 3C06800A */  lui       $a2, %hi(D_800A15C4)
/* EE6CE8 80240738 24C615C4 */  addiu     $a2, $a2, %lo(D_800A15C4)
/* EE6CEC 8024073C 0000202D */  daddu     $a0, $zero, $zero
/* EE6CF0 80240740 3C058008 */  lui       $a1, %hi(D_80079540)
/* EE6CF4 80240744 24A59540 */  addiu     $a1, $a1, %lo(D_80079540)
/* EE6CF8 80240748 8CD00000 */  lw        $s0, ($a2)
/* EE6CFC 8024074C 94A20000 */  lhu       $v0, ($a1)
/* EE6D00 80240750 0200382D */  daddu     $a3, $s0, $zero
/* EE6D04 80240754 26100008 */  addiu     $s0, $s0, 8
/* EE6D08 80240758 ACD00000 */  sw        $s0, ($a2)
/* EE6D0C 8024075C ACE30000 */  sw        $v1, ($a3)
/* EE6D10 80240760 24430001 */  addiu     $v1, $v0, 1
/* EE6D14 80240764 3042FFFF */  andi      $v0, $v0, 0xffff
/* EE6D18 80240768 00021180 */  sll       $v0, $v0, 6
/* EE6D1C 8024076C A4A30000 */  sh        $v1, ($a1)
/* EE6D20 80240770 3C03800A */  lui       $v1, %hi(D_800A15CC)
/* EE6D24 80240774 8C6315CC */  lw        $v1, %lo(D_800A15CC)($v1)
/* EE6D28 80240778 00481021 */  addu      $v0, $v0, $t0
/* EE6D2C 8024077C 00621821 */  addu      $v1, $v1, $v0
/* EE6D30 80240780 26020008 */  addiu     $v0, $s0, 8
/* EE6D34 80240784 ACE30004 */  sw        $v1, 4($a3)
/* EE6D38 80240788 ACC20000 */  sw        $v0, ($a2)
/* EE6D3C 8024078C 3C02DE00 */  lui       $v0, 0xde00
/* EE6D40 80240790 0C0499CD */  jal       func_80126734
/* EE6D44 80240794 AE020000 */   sw       $v0, ($s0)
/* EE6D48 80240798 3C038024 */  lui       $v1, %hi(D_80243B44_EEA0F4)
/* EE6D4C 8024079C 24633B44 */  addiu     $v1, $v1, %lo(D_80243B44_EEA0F4)
/* EE6D50 802407A0 C4600000 */  lwc1      $f0, ($v1)
/* EE6D54 802407A4 3C013F80 */  lui       $at, 0x3f80
/* EE6D58 802407A8 44811000 */  mtc1      $at, $f2
/* EE6D5C 802407AC 00000000 */  nop
/* EE6D60 802407B0 46020000 */  add.s     $f0, $f0, $f2
/* EE6D64 802407B4 AE020004 */  sw        $v0, 4($s0)
/* EE6D68 802407B8 E4600000 */  swc1      $f0, ($v1)
/* EE6D6C 802407BC 8FBF0064 */  lw        $ra, 0x64($sp)
/* EE6D70 802407C0 8FB00060 */  lw        $s0, 0x60($sp)
/* EE6D74 802407C4 D7B60070 */  ldc1      $f22, 0x70($sp)
/* EE6D78 802407C8 D7B40068 */  ldc1      $f20, 0x68($sp)
/* EE6D7C 802407CC 03E00008 */  jr        $ra
/* EE6D80 802407D0 27BD0078 */   addiu    $sp, $sp, 0x78
