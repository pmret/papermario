.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240500_D61A00
/* D61A00 80240500 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* D61A04 80240504 AFB00040 */  sw        $s0, 0x40($sp)
/* D61A08 80240508 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* D61A0C 8024050C 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* D61A10 80240510 AFB10044 */  sw        $s1, 0x44($sp)
/* D61A14 80240514 AFBF004C */  sw        $ra, 0x4c($sp)
/* D61A18 80240518 AFB20048 */  sw        $s2, 0x48($sp)
/* D61A1C 8024051C 8E020000 */  lw        $v0, ($s0)
/* D61A20 80240520 821200BE */  lb        $s2, 0xbe($s0)
/* D61A24 80240524 30420001 */  andi      $v0, $v0, 1
/* D61A28 80240528 10400052 */  beqz      $v0, .L80240674
/* D61A2C 8024052C 27B10020 */   addiu    $s1, $sp, 0x20
/* D61A30 80240530 8E0400CC */  lw        $a0, 0xcc($s0)
/* D61A34 80240534 0C044181 */  jal       get_shadow_by_index
/* D61A38 80240538 00000000 */   nop
/* D61A3C 8024053C 0C048B77 */  jal       get_entity_model
/* D61A40 80240540 84440008 */   lh       $a0, 8($v0)
/* D61A44 80240544 8E050028 */  lw        $a1, 0x28($s0)
/* D61A48 80240548 8E070030 */  lw        $a3, 0x30($s0)
/* D61A4C 8024054C 27A20030 */  addiu     $v0, $sp, 0x30
/* D61A50 80240550 AFA20010 */  sw        $v0, 0x10($sp)
/* D61A54 80240554 27A20034 */  addiu     $v0, $sp, 0x34
/* D61A58 80240558 AFA20014 */  sw        $v0, 0x14($sp)
/* D61A5C 8024055C 27A20038 */  addiu     $v0, $sp, 0x38
/* D61A60 80240560 AFA20018 */  sw        $v0, 0x18($sp)
/* D61A64 80240564 C600002C */  lwc1      $f0, 0x2c($s0)
/* D61A68 80240568 3C04800A */  lui       $a0, %hi(gCurrentCamID)
/* D61A6C 8024056C 8484A634 */  lh        $a0, %lo(gCurrentCamID)($a0)
/* D61A70 80240570 46000007 */  neg.s     $f0, $f0
/* D61A74 80240574 44060000 */  mfc1      $a2, $f0
/* D61A78 80240578 0C00B94E */  jal       get_screen_coords
/* D61A7C 8024057C 00000000 */   nop
/* D61A80 80240580 8E0500A4 */  lw        $a1, 0xa4($s0)
/* D61A84 80240584 3C063F80 */  lui       $a2, 0x3f80
/* D61A88 80240588 0C0B76A3 */  jal       func_802DDA8C
/* D61A8C 8024058C 24040001 */   addiu    $a0, $zero, 1
/* D61A90 80240590 8E020000 */  lw        $v0, ($s0)
/* D61A94 80240594 3C030002 */  lui       $v1, 2
/* D61A98 80240598 00431024 */  and       $v0, $v0, $v1
/* D61A9C 8024059C 54400022 */  bnel      $v0, $zero, .L80240628
/* D61AA0 802405A0 24120011 */   addiu    $s2, $zero, 0x11
/* D61AA4 802405A4 9203000E */  lbu       $v1, 0xe($s0)
/* D61AA8 802405A8 3C02802E */  lui       $v0, %hi(D_802D9D71)
/* D61AAC 802405AC 90429D71 */  lbu       $v0, %lo(D_802D9D71)($v0)
/* D61AB0 802405B0 10620018 */  beq       $v1, $v0, .L80240614
/* D61AB4 802405B4 2C6200FE */   sltiu    $v0, $v1, 0xfe
/* D61AB8 802405B8 1040000B */  beqz      $v0, .L802405E8
/* D61ABC 802405BC 24120011 */   addiu    $s2, $zero, 0x11
/* D61AC0 802405C0 24040001 */  addiu     $a0, $zero, 1
/* D61AC4 802405C4 2405FFFF */  addiu     $a1, $zero, -1
/* D61AC8 802405C8 24060007 */  addiu     $a2, $zero, 7
/* D61ACC 802405CC 0060102D */  daddu     $v0, $v1, $zero
/* D61AD0 802405D0 0000382D */  daddu     $a3, $zero, $zero
/* D61AD4 802405D4 AFA00010 */  sw        $zero, 0x10($sp)
/* D61AD8 802405D8 AFA00014 */  sw        $zero, 0x14($sp)
/* D61ADC 802405DC AFA0001C */  sw        $zero, 0x1c($sp)
/* D61AE0 802405E0 08090183 */  j         .L8024060C
/* D61AE4 802405E4 AFA20018 */   sw       $v0, 0x18($sp)
.L802405E8:
/* D61AE8 802405E8 2412000D */  addiu     $s2, $zero, 0xd
/* D61AEC 802405EC 24040001 */  addiu     $a0, $zero, 1
/* D61AF0 802405F0 2405FFFF */  addiu     $a1, $zero, -1
/* D61AF4 802405F4 0000302D */  daddu     $a2, $zero, $zero
/* D61AF8 802405F8 00C0382D */  daddu     $a3, $a2, $zero
/* D61AFC 802405FC AFA00010 */  sw        $zero, 0x10($sp)
/* D61B00 80240600 AFA00014 */  sw        $zero, 0x14($sp)
/* D61B04 80240604 AFA00018 */  sw        $zero, 0x18($sp)
/* D61B08 80240608 AFA0001C */  sw        $zero, 0x1c($sp)
.L8024060C:
/* D61B0C 8024060C 0C0B77B9 */  jal       func_802DDEE4
/* D61B10 80240610 00000000 */   nop
.L80240614:
/* D61B14 80240614 9202000E */  lbu       $v0, 0xe($s0)
/* D61B18 80240618 3C01802E */  lui       $at, %hi(D_802D9D71)
/* D61B1C 8024061C A0229D71 */  sb        $v0, %lo(D_802D9D71)($at)
/* D61B20 80240620 0809018C */  j         .L80240630
/* D61B24 80240624 00000000 */   nop
.L80240628:
/* D61B28 80240628 3C01802E */  lui       $at, %hi(D_802D9D71)
/* D61B2C 8024062C A0209D71 */  sb        $zero, %lo(D_802D9D71)($at)
.L80240630:
/* D61B30 80240630 8FA20038 */  lw        $v0, 0x38($sp)
/* D61B34 80240634 3C048024 */  lui       $a0, %hi(func_80240870_D61D70)
/* D61B38 80240638 24840870 */  addiu     $a0, $a0, %lo(func_80240870_D61D70)
/* D61B3C 8024063C AE320000 */  sw        $s2, ($s1)
/* D61B40 80240640 AE300008 */  sw        $s0, 8($s1)
/* D61B44 80240644 00021023 */  negu      $v0, $v0
/* D61B48 80240648 AE220004 */  sw        $v0, 4($s1)
/* D61B4C 8024064C 8E020000 */  lw        $v0, ($s0)
/* D61B50 80240650 3C030002 */  lui       $v1, 2
/* D61B54 80240654 00431024 */  and       $v0, $v0, $v1
/* D61B58 80240658 54400004 */  bnel      $v0, $zero, .L8024066C
/* D61B5C 8024065C AE24000C */   sw       $a0, 0xc($s1)
/* D61B60 80240660 3C048024 */  lui       $a0, %hi(func_8024068C_D61B8C)
/* D61B64 80240664 2484068C */  addiu     $a0, $a0, %lo(func_8024068C_D61B8C)
/* D61B68 80240668 AE24000C */  sw        $a0, 0xc($s1)
.L8024066C:
/* D61B6C 8024066C 0C047644 */  jal       queue_render_task
/* D61B70 80240670 0220202D */   daddu    $a0, $s1, $zero
.L80240674:
/* D61B74 80240674 8FBF004C */  lw        $ra, 0x4c($sp)
/* D61B78 80240678 8FB20048 */  lw        $s2, 0x48($sp)
/* D61B7C 8024067C 8FB10044 */  lw        $s1, 0x44($sp)
/* D61B80 80240680 8FB00040 */  lw        $s0, 0x40($sp)
/* D61B84 80240684 03E00008 */  jr        $ra
/* D61B88 80240688 27BD0050 */   addiu    $sp, $sp, 0x50
