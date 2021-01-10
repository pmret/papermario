.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80238A20_6F1B00
/* 6F1B00 80238A20 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 6F1B04 80238A24 AFB00018 */  sw        $s0, 0x18($sp)
/* 6F1B08 80238A28 3C10800E */  lui       $s0, %hi(gBattleStatus+0xDC)
/* 6F1B0C 80238A2C 8E10C14C */  lw        $s0, %lo(gBattleStatus+0xDC)($s0)
/* 6F1B10 80238A30 AFBF0020 */  sw        $ra, 0x20($sp)
/* 6F1B14 80238A34 AFB1001C */  sw        $s1, 0x1c($sp)
/* 6F1B18 80238A38 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 6F1B1C 80238A3C 10A00002 */  beqz      $a1, .L80238A48
/* 6F1B20 80238A40 2611000C */   addiu    $s1, $s0, 0xc
/* 6F1B24 80238A44 AC800070 */  sw        $zero, 0x70($a0)
.L80238A48:
/* 6F1B28 80238A48 8C820070 */  lw        $v0, 0x70($a0)
/* 6F1B2C 80238A4C 14400008 */  bnez      $v0, .L80238A70
/* 6F1B30 80238A50 24020001 */   addiu    $v0, $zero, 1
/* 6F1B34 80238A54 C6000144 */  lwc1      $f0, 0x144($s0)
/* 6F1B38 80238A58 C6020148 */  lwc1      $f2, 0x148($s0)
/* 6F1B3C 80238A5C C604014C */  lwc1      $f4, 0x14c($s0)
/* 6F1B40 80238A60 E600000C */  swc1      $f0, 0xc($s0)
/* 6F1B44 80238A64 E6020010 */  swc1      $f2, 0x10($s0)
/* 6F1B48 80238A68 E6040014 */  swc1      $f4, 0x14($s0)
/* 6F1B4C 80238A6C AC820070 */  sw        $v0, 0x70($a0)
.L80238A70:
/* 6F1B50 80238A70 C6000050 */  lwc1      $f0, 0x50($s0)
/* 6F1B54 80238A74 4480A000 */  mtc1      $zero, $f20
/* 6F1B58 80238A78 00000000 */  nop       
/* 6F1B5C 80238A7C 4600A03C */  c.lt.s    $f20, $f0
/* 6F1B60 80238A80 00000000 */  nop       
/* 6F1B64 80238A84 45000005 */  bc1f      .L80238A9C
/* 6F1B68 80238A88 24040100 */   addiu    $a0, $zero, 0x100
/* 6F1B6C 80238A8C 8E060064 */  lw        $a2, 0x64($s0)
/* 6F1B70 80238A90 0C098F3F */  jal       set_animation
/* 6F1B74 80238A94 0000282D */   daddu    $a1, $zero, $zero
/* 6F1B78 80238A98 C6000050 */  lwc1      $f0, 0x50($s0)
.L80238A9C:
/* 6F1B7C 80238A9C 4614003C */  c.lt.s    $f0, $f20
/* 6F1B80 80238AA0 00000000 */  nop       
/* 6F1B84 80238AA4 45000004 */  bc1f      .L80238AB8
/* 6F1B88 80238AA8 24040100 */   addiu    $a0, $zero, 0x100
/* 6F1B8C 80238AAC 8E060068 */  lw        $a2, 0x68($s0)
/* 6F1B90 80238AB0 0C098F3F */  jal       set_animation
/* 6F1B94 80238AB4 0000282D */   daddu    $a1, $zero, $zero
.L80238AB8:
/* 6F1B98 80238AB8 C6040010 */  lwc1      $f4, 0x10($s0)
/* 6F1B9C 80238ABC C6000050 */  lwc1      $f0, 0x50($s0)
/* 6F1BA0 80238AC0 8E05004C */  lw        $a1, 0x4c($s0)
/* 6F1BA4 80238AC4 46002100 */  add.s     $f4, $f4, $f0
/* 6F1BA8 80238AC8 C6020048 */  lwc1      $f2, 0x48($s0)
/* 6F1BAC 80238ACC 8E060054 */  lw        $a2, 0x54($s0)
/* 6F1BB0 80238AD0 46020001 */  sub.s     $f0, $f0, $f2
/* 6F1BB4 80238AD4 0220202D */  daddu     $a0, $s1, $zero
/* 6F1BB8 80238AD8 E6040010 */  swc1      $f4, 0x10($s0)
/* 6F1BBC 80238ADC 0C09904A */  jal       add_xz_vec3f
/* 6F1BC0 80238AE0 E6000050 */   swc1     $f0, 0x50($s0)
/* 6F1BC4 80238AE4 C6000010 */  lwc1      $f0, 0x10($s0)
/* 6F1BC8 80238AE8 C6020014 */  lwc1      $f2, 0x14($s0)
/* 6F1BCC 80238AEC 3C014120 */  lui       $at, 0x4120
/* 6F1BD0 80238AF0 44813000 */  mtc1      $at, $f6
/* 6F1BD4 80238AF4 E6000148 */  swc1      $f0, 0x148($s0)
/* 6F1BD8 80238AF8 C600000C */  lwc1      $f0, 0xc($s0)
/* 6F1BDC 80238AFC C6040148 */  lwc1      $f4, 0x148($s0)
/* 6F1BE0 80238B00 E602014C */  swc1      $f2, 0x14c($s0)
/* 6F1BE4 80238B04 4606203C */  c.lt.s    $f4, $f6
/* 6F1BE8 80238B08 00000000 */  nop       
/* 6F1BEC 80238B0C 45010003 */  bc1t      .L80238B1C
/* 6F1BF0 80238B10 E6000144 */   swc1     $f0, 0x144($s0)
/* 6F1BF4 80238B14 0808E2D2 */  j         .L80238B48
/* 6F1BF8 80238B18 0000102D */   daddu    $v0, $zero, $zero
.L80238B1C:
/* 6F1BFC 80238B1C C600018C */  lwc1      $f0, 0x18c($s0)
/* 6F1C00 80238B20 E6060148 */  swc1      $f6, 0x148($s0)
/* 6F1C04 80238B24 E7A00010 */  swc1      $f0, 0x10($sp)
/* 6F1C08 80238B28 8E050144 */  lw        $a1, 0x144($s0)
/* 6F1C0C 80238B2C 8E060148 */  lw        $a2, 0x148($s0)
/* 6F1C10 80238B30 8E07014C */  lw        $a3, 0x14c($s0)
/* 6F1C14 80238B34 0C0990BC */  jal       play_movement_dust_effects
/* 6F1C18 80238B38 24040002 */   addiu    $a0, $zero, 2
/* 6F1C1C 80238B3C 0C05272D */  jal       play_sound
/* 6F1C20 80238B40 24040148 */   addiu    $a0, $zero, 0x148
/* 6F1C24 80238B44 24020001 */  addiu     $v0, $zero, 1
.L80238B48:
/* 6F1C28 80238B48 8FBF0020 */  lw        $ra, 0x20($sp)
/* 6F1C2C 80238B4C 8FB1001C */  lw        $s1, 0x1c($sp)
/* 6F1C30 80238B50 8FB00018 */  lw        $s0, 0x18($sp)
/* 6F1C34 80238B54 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 6F1C38 80238B58 03E00008 */  jr        $ra
/* 6F1C3C 80238B5C 27BD0030 */   addiu    $sp, $sp, 0x30
