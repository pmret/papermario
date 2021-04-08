.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80244B00
/* 165360 80244B00 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 165364 80244B04 AFB00010 */  sw        $s0, 0x10($sp)
/* 165368 80244B08 0000802D */  daddu     $s0, $zero, $zero
/* 16536C 80244B0C AFB10014 */  sw        $s1, 0x14($sp)
/* 165370 80244B10 3C118025 */  lui       $s1, %hi(pause_partners_draw_movelist_flower)
/* 165374 80244B14 2631C0A0 */  addiu     $s1, $s1, %lo(pause_partners_draw_movelist_flower)
/* 165378 80244B18 AFBF0018 */  sw        $ra, 0x18($sp)
.L80244B1C:
/* 16537C 80244B1C 8E240000 */  lw        $a0, ($s1)
/* 165380 80244B20 26310004 */  addiu     $s1, $s1, 4
/* 165384 80244B24 0C05123D */  jal       free_icon
/* 165388 80244B28 26100001 */   addiu    $s0, $s0, 1
/* 16538C 80244B2C 1A00FFFB */  blez      $s0, .L80244B1C
/* 165390 80244B30 00000000 */   nop
/* 165394 80244B34 3C118025 */  lui       $s1, %hi(D_80249B84)
/* 165398 80244B38 26319B84 */  addiu     $s1, $s1, %lo(D_80249B84)
/* 16539C 80244B3C 0000802D */  daddu     $s0, $zero, $zero
.L80244B40:
/* 1653A0 80244B40 8E240000 */  lw        $a0, ($s1)
/* 1653A4 80244B44 90820000 */  lbu       $v0, ($a0)
/* 1653A8 80244B48 10400006 */  beqz      $v0, .L80244B64
/* 1653AC 80244B4C 26100001 */   addiu    $s0, $s0, 1
/* 1653B0 80244B50 8C820018 */  lw        $v0, 0x18($a0)
/* 1653B4 80244B54 10400003 */  beqz      $v0, .L80244B64
/* 1653B8 80244B58 00000000 */   nop
/* 1653BC 80244B5C 0040F809 */  jalr      $v0
/* 1653C0 80244B60 00000000 */   nop
.L80244B64:
/* 1653C4 80244B64 2A020004 */  slti      $v0, $s0, 4
/* 1653C8 80244B68 1440FFF5 */  bnez      $v0, .L80244B40
/* 1653CC 80244B6C 26310004 */   addiu    $s1, $s1, 4
/* 1653D0 80244B70 2410002C */  addiu     $s0, $zero, 0x2c
/* 1653D4 80244B74 0200202D */  daddu     $a0, $s0, $zero
.L80244B78:
/* 1653D8 80244B78 0C051F9F */  jal       set_window_update
/* 1653DC 80244B7C 24050002 */   addiu    $a1, $zero, 2
/* 1653E0 80244B80 26100001 */  addiu     $s0, $s0, 1
/* 1653E4 80244B84 2A020040 */  slti      $v0, $s0, 0x40
/* 1653E8 80244B88 1440FFFB */  bnez      $v0, .L80244B78
/* 1653EC 80244B8C 0200202D */   daddu    $a0, $s0, $zero
/* 1653F0 80244B90 24040018 */  addiu     $a0, $zero, 0x18
/* 1653F4 80244B94 0C051F9F */  jal       set_window_update
/* 1653F8 80244B98 24050002 */   addiu    $a1, $zero, 2
/* 1653FC 80244B9C 24040017 */  addiu     $a0, $zero, 0x17
/* 165400 80244BA0 0C051F9F */  jal       set_window_update
/* 165404 80244BA4 24050002 */   addiu    $a1, $zero, 2
/* 165408 80244BA8 0C0912F1 */  jal       func_80244BC4
/* 16540C 80244BAC 00000000 */   nop
/* 165410 80244BB0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 165414 80244BB4 8FB10014 */  lw        $s1, 0x14($sp)
/* 165418 80244BB8 8FB00010 */  lw        $s0, 0x10($sp)
/* 16541C 80244BBC 03E00008 */  jr        $ra
/* 165420 80244BC0 27BD0020 */   addiu    $sp, $sp, 0x20
