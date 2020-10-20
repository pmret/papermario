.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240500_D7D050
/* D7D050 80240500 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* D7D054 80240504 AFB00040 */  sw        $s0, 0x40($sp)
/* D7D058 80240508 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* D7D05C 8024050C 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* D7D060 80240510 AFB10044 */  sw        $s1, 0x44($sp)
/* D7D064 80240514 AFBF004C */  sw        $ra, 0x4c($sp)
/* D7D068 80240518 AFB20048 */  sw        $s2, 0x48($sp)
/* D7D06C 8024051C 8E020000 */  lw        $v0, ($s0)
/* D7D070 80240520 821200BE */  lb        $s2, 0xbe($s0)
/* D7D074 80240524 30420001 */  andi      $v0, $v0, 1
/* D7D078 80240528 10400052 */  beqz      $v0, .L80240674
/* D7D07C 8024052C 27B10020 */   addiu    $s1, $sp, 0x20
/* D7D080 80240530 8E0400CC */  lw        $a0, 0xcc($s0)
/* D7D084 80240534 0C044181 */  jal       get_shadow_by_index
/* D7D088 80240538 00000000 */   nop      
/* D7D08C 8024053C 0C048B77 */  jal       func_80122DDC
/* D7D090 80240540 84440008 */   lh       $a0, 8($v0)
/* D7D094 80240544 8E050028 */  lw        $a1, 0x28($s0)
/* D7D098 80240548 8E070030 */  lw        $a3, 0x30($s0)
/* D7D09C 8024054C 27A20030 */  addiu     $v0, $sp, 0x30
/* D7D0A0 80240550 AFA20010 */  sw        $v0, 0x10($sp)
/* D7D0A4 80240554 27A20034 */  addiu     $v0, $sp, 0x34
/* D7D0A8 80240558 AFA20014 */  sw        $v0, 0x14($sp)
/* D7D0AC 8024055C 27A20038 */  addiu     $v0, $sp, 0x38
/* D7D0B0 80240560 AFA20018 */  sw        $v0, 0x18($sp)
/* D7D0B4 80240564 C600002C */  lwc1      $f0, 0x2c($s0)
/* D7D0B8 80240568 3C04800A */  lui       $a0, 0x800a
/* D7D0BC 8024056C 8484A634 */  lh        $a0, -0x59cc($a0)
/* D7D0C0 80240570 46000007 */  neg.s     $f0, $f0
/* D7D0C4 80240574 44060000 */  mfc1      $a2, $f0
/* D7D0C8 80240578 0C00B94E */  jal       get_screen_coords
/* D7D0CC 8024057C 00000000 */   nop      
/* D7D0D0 80240580 8E0500A4 */  lw        $a1, 0xa4($s0)
/* D7D0D4 80240584 3C063F80 */  lui       $a2, 0x3f80
/* D7D0D8 80240588 0C0B76A3 */  jal       func_802DDA8C
/* D7D0DC 8024058C 24040001 */   addiu    $a0, $zero, 1
/* D7D0E0 80240590 8E020000 */  lw        $v0, ($s0)
/* D7D0E4 80240594 3C030002 */  lui       $v1, 2
/* D7D0E8 80240598 00431024 */  and       $v0, $v0, $v1
/* D7D0EC 8024059C 54400022 */  bnel      $v0, $zero, .L80240628
/* D7D0F0 802405A0 24120011 */   addiu    $s2, $zero, 0x11
/* D7D0F4 802405A4 9203000E */  lbu       $v1, 0xe($s0)
/* D7D0F8 802405A8 3C02802E */  lui       $v0, 0x802e
/* D7D0FC 802405AC 90429D71 */  lbu       $v0, -0x628f($v0)
/* D7D100 802405B0 10620018 */  beq       $v1, $v0, .L80240614
/* D7D104 802405B4 2C6200FE */   sltiu    $v0, $v1, 0xfe
/* D7D108 802405B8 1040000B */  beqz      $v0, .L802405E8
/* D7D10C 802405BC 24120011 */   addiu    $s2, $zero, 0x11
/* D7D110 802405C0 24040001 */  addiu     $a0, $zero, 1
/* D7D114 802405C4 2405FFFF */  addiu     $a1, $zero, -1
/* D7D118 802405C8 24060007 */  addiu     $a2, $zero, 7
/* D7D11C 802405CC 0060102D */  daddu     $v0, $v1, $zero
/* D7D120 802405D0 0000382D */  daddu     $a3, $zero, $zero
/* D7D124 802405D4 AFA00010 */  sw        $zero, 0x10($sp)
/* D7D128 802405D8 AFA00014 */  sw        $zero, 0x14($sp)
/* D7D12C 802405DC AFA0001C */  sw        $zero, 0x1c($sp)
/* D7D130 802405E0 08090183 */  j         .L8024060C
/* D7D134 802405E4 AFA20018 */   sw       $v0, 0x18($sp)
.L802405E8:
/* D7D138 802405E8 2412000D */  addiu     $s2, $zero, 0xd
/* D7D13C 802405EC 24040001 */  addiu     $a0, $zero, 1
/* D7D140 802405F0 2405FFFF */  addiu     $a1, $zero, -1
/* D7D144 802405F4 0000302D */  daddu     $a2, $zero, $zero
/* D7D148 802405F8 00C0382D */  daddu     $a3, $a2, $zero
/* D7D14C 802405FC AFA00010 */  sw        $zero, 0x10($sp)
/* D7D150 80240600 AFA00014 */  sw        $zero, 0x14($sp)
/* D7D154 80240604 AFA00018 */  sw        $zero, 0x18($sp)
/* D7D158 80240608 AFA0001C */  sw        $zero, 0x1c($sp)
.L8024060C:
/* D7D15C 8024060C 0C0B77B9 */  jal       func_802DDEE4
/* D7D160 80240610 00000000 */   nop      
.L80240614:
/* D7D164 80240614 9202000E */  lbu       $v0, 0xe($s0)
/* D7D168 80240618 3C01802E */  lui       $at, 0x802e
/* D7D16C 8024061C A0229D71 */  sb        $v0, -0x628f($at)
/* D7D170 80240620 0809018C */  j         .L80240630
/* D7D174 80240624 00000000 */   nop      
.L80240628:
/* D7D178 80240628 3C01802E */  lui       $at, 0x802e
/* D7D17C 8024062C A0209D71 */  sb        $zero, -0x628f($at)
.L80240630:
/* D7D180 80240630 8FA20038 */  lw        $v0, 0x38($sp)
/* D7D184 80240634 3C048024 */  lui       $a0, 0x8024
/* D7D188 80240638 24840870 */  addiu     $a0, $a0, 0x870
/* D7D18C 8024063C AE320000 */  sw        $s2, ($s1)
/* D7D190 80240640 AE300008 */  sw        $s0, 8($s1)
/* D7D194 80240644 00021023 */  negu      $v0, $v0
/* D7D198 80240648 AE220004 */  sw        $v0, 4($s1)
/* D7D19C 8024064C 8E020000 */  lw        $v0, ($s0)
/* D7D1A0 80240650 3C030002 */  lui       $v1, 2
/* D7D1A4 80240654 00431024 */  and       $v0, $v0, $v1
/* D7D1A8 80240658 54400004 */  bnel      $v0, $zero, .L8024066C
/* D7D1AC 8024065C AE24000C */   sw       $a0, 0xc($s1)
/* D7D1B0 80240660 3C048024 */  lui       $a0, 0x8024
/* D7D1B4 80240664 2484068C */  addiu     $a0, $a0, 0x68c
/* D7D1B8 80240668 AE24000C */  sw        $a0, 0xc($s1)
.L8024066C:
/* D7D1BC 8024066C 0C047644 */  jal       queue_render_task
/* D7D1C0 80240670 0220202D */   daddu    $a0, $s1, $zero
.L80240674:
/* D7D1C4 80240674 8FBF004C */  lw        $ra, 0x4c($sp)
/* D7D1C8 80240678 8FB20048 */  lw        $s2, 0x48($sp)
/* D7D1CC 8024067C 8FB10044 */  lw        $s1, 0x44($sp)
/* D7D1D0 80240680 8FB00040 */  lw        $s0, 0x40($sp)
/* D7D1D4 80240684 03E00008 */  jr        $ra
/* D7D1D8 80240688 27BD0050 */   addiu    $sp, $sp, 0x50
