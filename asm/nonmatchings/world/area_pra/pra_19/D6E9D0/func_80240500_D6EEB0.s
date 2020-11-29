.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240500_D6EEB0
/* D6EEB0 80240500 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* D6EEB4 80240504 AFB00040 */  sw        $s0, 0x40($sp)
/* D6EEB8 80240508 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* D6EEBC 8024050C 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* D6EEC0 80240510 AFB10044 */  sw        $s1, 0x44($sp)
/* D6EEC4 80240514 AFBF004C */  sw        $ra, 0x4c($sp)
/* D6EEC8 80240518 AFB20048 */  sw        $s2, 0x48($sp)
/* D6EECC 8024051C 8E020000 */  lw        $v0, ($s0)
/* D6EED0 80240520 821200BE */  lb        $s2, 0xbe($s0)
/* D6EED4 80240524 30420001 */  andi      $v0, $v0, 1
/* D6EED8 80240528 10400052 */  beqz      $v0, .L80240674
/* D6EEDC 8024052C 27B10020 */   addiu    $s1, $sp, 0x20
/* D6EEE0 80240530 8E0400CC */  lw        $a0, 0xcc($s0)
/* D6EEE4 80240534 0C044181 */  jal       get_shadow_by_index
/* D6EEE8 80240538 00000000 */   nop      
/* D6EEEC 8024053C 0C048B77 */  jal       func_80122DDC
/* D6EEF0 80240540 84440008 */   lh       $a0, 8($v0)
/* D6EEF4 80240544 8E050028 */  lw        $a1, 0x28($s0)
/* D6EEF8 80240548 8E070030 */  lw        $a3, 0x30($s0)
/* D6EEFC 8024054C 27A20030 */  addiu     $v0, $sp, 0x30
/* D6EF00 80240550 AFA20010 */  sw        $v0, 0x10($sp)
/* D6EF04 80240554 27A20034 */  addiu     $v0, $sp, 0x34
/* D6EF08 80240558 AFA20014 */  sw        $v0, 0x14($sp)
/* D6EF0C 8024055C 27A20038 */  addiu     $v0, $sp, 0x38
/* D6EF10 80240560 AFA20018 */  sw        $v0, 0x18($sp)
/* D6EF14 80240564 C600002C */  lwc1      $f0, 0x2c($s0)
/* D6EF18 80240568 3C04800A */  lui       $a0, %hi(D_8009A634)
/* D6EF1C 8024056C 8484A634 */  lh        $a0, %lo(D_8009A634)($a0)
/* D6EF20 80240570 46000007 */  neg.s     $f0, $f0
/* D6EF24 80240574 44060000 */  mfc1      $a2, $f0
/* D6EF28 80240578 0C00B94E */  jal       get_screen_coords
/* D6EF2C 8024057C 00000000 */   nop      
/* D6EF30 80240580 8E0500A4 */  lw        $a1, 0xa4($s0)
/* D6EF34 80240584 3C063F80 */  lui       $a2, 0x3f80
/* D6EF38 80240588 0C0B76A3 */  jal       func_802DDA8C
/* D6EF3C 8024058C 24040001 */   addiu    $a0, $zero, 1
/* D6EF40 80240590 8E020000 */  lw        $v0, ($s0)
/* D6EF44 80240594 3C030002 */  lui       $v1, 2
/* D6EF48 80240598 00431024 */  and       $v0, $v0, $v1
/* D6EF4C 8024059C 54400022 */  bnel      $v0, $zero, .L80240628
/* D6EF50 802405A0 24120011 */   addiu    $s2, $zero, 0x11
/* D6EF54 802405A4 9203000E */  lbu       $v1, 0xe($s0)
/* D6EF58 802405A8 3C02802E */  lui       $v0, %hi(D_802D9D71)
/* D6EF5C 802405AC 90429D71 */  lbu       $v0, %lo(D_802D9D71)($v0)
/* D6EF60 802405B0 10620018 */  beq       $v1, $v0, .L80240614
/* D6EF64 802405B4 2C6200FE */   sltiu    $v0, $v1, 0xfe
/* D6EF68 802405B8 1040000B */  beqz      $v0, .L802405E8
/* D6EF6C 802405BC 24120011 */   addiu    $s2, $zero, 0x11
/* D6EF70 802405C0 24040001 */  addiu     $a0, $zero, 1
/* D6EF74 802405C4 2405FFFF */  addiu     $a1, $zero, -1
/* D6EF78 802405C8 24060007 */  addiu     $a2, $zero, 7
/* D6EF7C 802405CC 0060102D */  daddu     $v0, $v1, $zero
/* D6EF80 802405D0 0000382D */  daddu     $a3, $zero, $zero
/* D6EF84 802405D4 AFA00010 */  sw        $zero, 0x10($sp)
/* D6EF88 802405D8 AFA00014 */  sw        $zero, 0x14($sp)
/* D6EF8C 802405DC AFA0001C */  sw        $zero, 0x1c($sp)
/* D6EF90 802405E0 08090183 */  j         .L8024060C
/* D6EF94 802405E4 AFA20018 */   sw       $v0, 0x18($sp)
.L802405E8:
/* D6EF98 802405E8 2412000D */  addiu     $s2, $zero, 0xd
/* D6EF9C 802405EC 24040001 */  addiu     $a0, $zero, 1
/* D6EFA0 802405F0 2405FFFF */  addiu     $a1, $zero, -1
/* D6EFA4 802405F4 0000302D */  daddu     $a2, $zero, $zero
/* D6EFA8 802405F8 00C0382D */  daddu     $a3, $a2, $zero
/* D6EFAC 802405FC AFA00010 */  sw        $zero, 0x10($sp)
/* D6EFB0 80240600 AFA00014 */  sw        $zero, 0x14($sp)
/* D6EFB4 80240604 AFA00018 */  sw        $zero, 0x18($sp)
/* D6EFB8 80240608 AFA0001C */  sw        $zero, 0x1c($sp)
.L8024060C:
/* D6EFBC 8024060C 0C0B77B9 */  jal       func_802DDEE4
/* D6EFC0 80240610 00000000 */   nop      
.L80240614:
/* D6EFC4 80240614 9202000E */  lbu       $v0, 0xe($s0)
/* D6EFC8 80240618 3C01802E */  lui       $at, %hi(D_802D9D71)
/* D6EFCC 8024061C A0229D71 */  sb        $v0, %lo(D_802D9D71)($at)
/* D6EFD0 80240620 0809018C */  j         .L80240630
/* D6EFD4 80240624 00000000 */   nop      
.L80240628:
/* D6EFD8 80240628 3C01802E */  lui       $at, %hi(D_802D9D71)
/* D6EFDC 8024062C A0209D71 */  sb        $zero, %lo(D_802D9D71)($at)
.L80240630:
/* D6EFE0 80240630 8FA20038 */  lw        $v0, 0x38($sp)
/* D6EFE4 80240634 3C048024 */  lui       $a0, %hi(D_80240870)
/* D6EFE8 80240638 24840870 */  addiu     $a0, $a0, %lo(D_80240870)
/* D6EFEC 8024063C AE320000 */  sw        $s2, ($s1)
/* D6EFF0 80240640 AE300008 */  sw        $s0, 8($s1)
/* D6EFF4 80240644 00021023 */  negu      $v0, $v0
/* D6EFF8 80240648 AE220004 */  sw        $v0, 4($s1)
/* D6EFFC 8024064C 8E020000 */  lw        $v0, ($s0)
/* D6F000 80240650 3C030002 */  lui       $v1, 2
/* D6F004 80240654 00431024 */  and       $v0, $v0, $v1
/* D6F008 80240658 54400004 */  bnel      $v0, $zero, .L8024066C
/* D6F00C 8024065C AE24000C */   sw       $a0, 0xc($s1)
/* D6F010 80240660 3C048024 */  lui       $a0, %hi(D_8024068C)
/* D6F014 80240664 2484068C */  addiu     $a0, $a0, %lo(D_8024068C)
/* D6F018 80240668 AE24000C */  sw        $a0, 0xc($s1)
.L8024066C:
/* D6F01C 8024066C 0C047644 */  jal       queue_render_task
/* D6F020 80240670 0220202D */   daddu    $a0, $s1, $zero
.L80240674:
/* D6F024 80240674 8FBF004C */  lw        $ra, 0x4c($sp)
/* D6F028 80240678 8FB20048 */  lw        $s2, 0x48($sp)
/* D6F02C 8024067C 8FB10044 */  lw        $s1, 0x44($sp)
/* D6F030 80240680 8FB00040 */  lw        $s0, 0x40($sp)
/* D6F034 80240684 03E00008 */  jr        $ra
/* D6F038 80240688 27BD0050 */   addiu    $sp, $sp, 0x50
