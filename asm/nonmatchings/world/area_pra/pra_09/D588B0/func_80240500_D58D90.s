.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240500_D58D90
/* D58D90 80240500 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* D58D94 80240504 AFB00040 */  sw        $s0, 0x40($sp)
/* D58D98 80240508 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* D58D9C 8024050C 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* D58DA0 80240510 AFB10044 */  sw        $s1, 0x44($sp)
/* D58DA4 80240514 AFBF004C */  sw        $ra, 0x4c($sp)
/* D58DA8 80240518 AFB20048 */  sw        $s2, 0x48($sp)
/* D58DAC 8024051C 8E020000 */  lw        $v0, ($s0)
/* D58DB0 80240520 821200BE */  lb        $s2, 0xbe($s0)
/* D58DB4 80240524 30420001 */  andi      $v0, $v0, 1
/* D58DB8 80240528 10400052 */  beqz      $v0, .L80240674
/* D58DBC 8024052C 27B10020 */   addiu    $s1, $sp, 0x20
/* D58DC0 80240530 8E0400CC */  lw        $a0, 0xcc($s0)
/* D58DC4 80240534 0C044181 */  jal       get_shadow_by_index
/* D58DC8 80240538 00000000 */   nop      
/* D58DCC 8024053C 0C048B77 */  jal       func_80122DDC
/* D58DD0 80240540 84440008 */   lh       $a0, 8($v0)
/* D58DD4 80240544 8E050028 */  lw        $a1, 0x28($s0)
/* D58DD8 80240548 8E070030 */  lw        $a3, 0x30($s0)
/* D58DDC 8024054C 27A20030 */  addiu     $v0, $sp, 0x30
/* D58DE0 80240550 AFA20010 */  sw        $v0, 0x10($sp)
/* D58DE4 80240554 27A20034 */  addiu     $v0, $sp, 0x34
/* D58DE8 80240558 AFA20014 */  sw        $v0, 0x14($sp)
/* D58DEC 8024055C 27A20038 */  addiu     $v0, $sp, 0x38
/* D58DF0 80240560 AFA20018 */  sw        $v0, 0x18($sp)
/* D58DF4 80240564 C600002C */  lwc1      $f0, 0x2c($s0)
/* D58DF8 80240568 3C04800A */  lui       $a0, %hi(D_8009A634)
/* D58DFC 8024056C 8484A634 */  lh        $a0, %lo(D_8009A634)($a0)
/* D58E00 80240570 46000007 */  neg.s     $f0, $f0
/* D58E04 80240574 44060000 */  mfc1      $a2, $f0
/* D58E08 80240578 0C00B94E */  jal       get_screen_coords
/* D58E0C 8024057C 00000000 */   nop      
/* D58E10 80240580 8E0500A4 */  lw        $a1, 0xa4($s0)
/* D58E14 80240584 3C063F80 */  lui       $a2, 0x3f80
/* D58E18 80240588 0C0B76A3 */  jal       func_802DDA8C
/* D58E1C 8024058C 24040001 */   addiu    $a0, $zero, 1
/* D58E20 80240590 8E020000 */  lw        $v0, ($s0)
/* D58E24 80240594 3C030002 */  lui       $v1, 2
/* D58E28 80240598 00431024 */  and       $v0, $v0, $v1
/* D58E2C 8024059C 54400022 */  bnel      $v0, $zero, .L80240628
/* D58E30 802405A0 24120011 */   addiu    $s2, $zero, 0x11
/* D58E34 802405A4 9203000E */  lbu       $v1, 0xe($s0)
/* D58E38 802405A8 3C02802E */  lui       $v0, %hi(D_802D9D71)
/* D58E3C 802405AC 90429D71 */  lbu       $v0, %lo(D_802D9D71)($v0)
/* D58E40 802405B0 10620018 */  beq       $v1, $v0, .L80240614
/* D58E44 802405B4 2C6200FE */   sltiu    $v0, $v1, 0xfe
/* D58E48 802405B8 1040000B */  beqz      $v0, .L802405E8
/* D58E4C 802405BC 24120011 */   addiu    $s2, $zero, 0x11
/* D58E50 802405C0 24040001 */  addiu     $a0, $zero, 1
/* D58E54 802405C4 2405FFFF */  addiu     $a1, $zero, -1
/* D58E58 802405C8 24060007 */  addiu     $a2, $zero, 7
/* D58E5C 802405CC 0060102D */  daddu     $v0, $v1, $zero
/* D58E60 802405D0 0000382D */  daddu     $a3, $zero, $zero
/* D58E64 802405D4 AFA00010 */  sw        $zero, 0x10($sp)
/* D58E68 802405D8 AFA00014 */  sw        $zero, 0x14($sp)
/* D58E6C 802405DC AFA0001C */  sw        $zero, 0x1c($sp)
/* D58E70 802405E0 08090183 */  j         .L8024060C
/* D58E74 802405E4 AFA20018 */   sw       $v0, 0x18($sp)
.L802405E8:
/* D58E78 802405E8 2412000D */  addiu     $s2, $zero, 0xd
/* D58E7C 802405EC 24040001 */  addiu     $a0, $zero, 1
/* D58E80 802405F0 2405FFFF */  addiu     $a1, $zero, -1
/* D58E84 802405F4 0000302D */  daddu     $a2, $zero, $zero
/* D58E88 802405F8 00C0382D */  daddu     $a3, $a2, $zero
/* D58E8C 802405FC AFA00010 */  sw        $zero, 0x10($sp)
/* D58E90 80240600 AFA00014 */  sw        $zero, 0x14($sp)
/* D58E94 80240604 AFA00018 */  sw        $zero, 0x18($sp)
/* D58E98 80240608 AFA0001C */  sw        $zero, 0x1c($sp)
.L8024060C:
/* D58E9C 8024060C 0C0B77B9 */  jal       func_802DDEE4
/* D58EA0 80240610 00000000 */   nop      
.L80240614:
/* D58EA4 80240614 9202000E */  lbu       $v0, 0xe($s0)
/* D58EA8 80240618 3C01802E */  lui       $at, %hi(D_802D9D71)
/* D58EAC 8024061C A0229D71 */  sb        $v0, %lo(D_802D9D71)($at)
/* D58EB0 80240620 0809018C */  j         .L80240630
/* D58EB4 80240624 00000000 */   nop      
.L80240628:
/* D58EB8 80240628 3C01802E */  lui       $at, %hi(D_802D9D71)
/* D58EBC 8024062C A0209D71 */  sb        $zero, %lo(D_802D9D71)($at)
.L80240630:
/* D58EC0 80240630 8FA20038 */  lw        $v0, 0x38($sp)
/* D58EC4 80240634 3C048024 */  lui       $a0, %hi(D_80240870)
/* D58EC8 80240638 24840870 */  addiu     $a0, $a0, %lo(D_80240870)
/* D58ECC 8024063C AE320000 */  sw        $s2, ($s1)
/* D58ED0 80240640 AE300008 */  sw        $s0, 8($s1)
/* D58ED4 80240644 00021023 */  negu      $v0, $v0
/* D58ED8 80240648 AE220004 */  sw        $v0, 4($s1)
/* D58EDC 8024064C 8E020000 */  lw        $v0, ($s0)
/* D58EE0 80240650 3C030002 */  lui       $v1, 2
/* D58EE4 80240654 00431024 */  and       $v0, $v0, $v1
/* D58EE8 80240658 54400004 */  bnel      $v0, $zero, .L8024066C
/* D58EEC 8024065C AE24000C */   sw       $a0, 0xc($s1)
/* D58EF0 80240660 3C048024 */  lui       $a0, %hi(D_8024068C)
/* D58EF4 80240664 2484068C */  addiu     $a0, $a0, %lo(D_8024068C)
/* D58EF8 80240668 AE24000C */  sw        $a0, 0xc($s1)
.L8024066C:
/* D58EFC 8024066C 0C047644 */  jal       queue_render_task
/* D58F00 80240670 0220202D */   daddu    $a0, $s1, $zero
.L80240674:
/* D58F04 80240674 8FBF004C */  lw        $ra, 0x4c($sp)
/* D58F08 80240678 8FB20048 */  lw        $s2, 0x48($sp)
/* D58F0C 8024067C 8FB10044 */  lw        $s1, 0x44($sp)
/* D58F10 80240680 8FB00040 */  lw        $s0, 0x40($sp)
/* D58F14 80240684 03E00008 */  jr        $ra
/* D58F18 80240688 27BD0050 */   addiu    $sp, $sp, 0x50
