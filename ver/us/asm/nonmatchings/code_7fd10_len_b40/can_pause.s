.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel can_pause
/* 7FE8C 800E69DC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7FE90 800E69E0 AFB20018 */  sw        $s2, 0x18($sp)
/* 7FE94 800E69E4 3C128011 */  lui       $s2, %hi(D_8010EBB0)
/* 7FE98 800E69E8 2652EBB0 */  addiu     $s2, $s2, %lo(D_8010EBB0)
/* 7FE9C 800E69EC AFB10014 */  sw        $s1, 0x14($sp)
/* 7FEA0 800E69F0 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* 7FEA4 800E69F4 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* 7FEA8 800E69F8 3C030010 */  lui       $v1, 0x10
/* 7FEAC 800E69FC AFBF001C */  sw        $ra, 0x1c($sp)
/* 7FEB0 800E6A00 AFB00010 */  sw        $s0, 0x10($sp)
/* 7FEB4 800E6A04 8E220004 */  lw        $v0, 4($s1)
/* 7FEB8 800E6A08 823000B4 */  lb        $s0, 0xb4($s1)
/* 7FEBC 800E6A0C 00431024 */  and       $v0, $v0, $v1
/* 7FEC0 800E6A10 1440004F */  bnez      $v0, .L800E6B50
/* 7FEC4 800E6A14 0000102D */   daddu    $v0, $zero, $zero
/* 7FEC8 800E6A18 8E220000 */  lw        $v0, ($s1)
/* 7FECC 800E6A1C 30420100 */  andi      $v0, $v0, 0x100
/* 7FED0 800E6A20 1440004B */  bnez      $v0, .L800E6B50
/* 7FED4 800E6A24 0000102D */   daddu    $v0, $zero, $zero
/* 7FED8 800E6A28 30822010 */  andi      $v0, $a0, 0x2010
/* 7FEDC 800E6A2C 14400048 */  bnez      $v0, .L800E6B50
/* 7FEE0 800E6A30 0000102D */   daddu    $v0, $zero, $zero
/* 7FEE4 800E6A34 30A21003 */  andi      $v0, $a1, 0x1003
/* 7FEE8 800E6A38 10400045 */  beqz      $v0, .L800E6B50
/* 7FEEC 800E6A3C 0000102D */   daddu    $v0, $zero, $zero
/* 7FEF0 800E6A40 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 7FEF4 800E6A44 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 7FEF8 800E6A48 8C420144 */  lw        $v0, 0x144($v0)
/* 7FEFC 800E6A4C 10400005 */  beqz      $v0, .L800E6A64
/* 7FF00 800E6A50 00000000 */   nop
/* 7FF04 800E6A54 94420000 */  lhu       $v0, ($v0)
/* 7FF08 800E6A58 30420001 */  andi      $v0, $v0, 1
/* 7FF0C 800E6A5C 1440003C */  bnez      $v0, .L800E6B50
/* 7FF10 800E6A60 0000102D */   daddu    $v0, $zero, $zero
.L800E6A64:
/* 7FF14 800E6A64 3C02800A */  lui       $v0, %hi(gOverrideFlags)
/* 7FF18 800E6A68 8C42A650 */  lw        $v0, %lo(gOverrideFlags)($v0)
/* 7FF1C 800E6A6C 3C030004 */  lui       $v1, 4
/* 7FF20 800E6A70 00431024 */  and       $v0, $v0, $v1
/* 7FF24 800E6A74 14400036 */  bnez      $v0, .L800E6B50
/* 7FF28 800E6A78 0000102D */   daddu    $v0, $zero, $zero
/* 7FF2C 800E6A7C 0C04D07A */  jal       is_picking_up_item
/* 7FF30 800E6A80 00000000 */   nop
/* 7FF34 800E6A84 14400032 */  bnez      $v0, .L800E6B50
/* 7FF38 800E6A88 0000102D */   daddu    $v0, $zero, $zero
/* 7FF3C 800E6A8C 8E220004 */  lw        $v0, 4($s1)
/* 7FF40 800E6A90 30424000 */  andi      $v0, $v0, 0x4000
/* 7FF44 800E6A94 1440002B */  bnez      $v0, .L800E6B44
/* 7FF48 800E6A98 00000000 */   nop
/* 7FF4C 800E6A9C 82420000 */  lb        $v0, ($s2)
/* 7FF50 800E6AA0 1440000A */  bnez      $v0, .L800E6ACC
/* 7FF54 800E6AA4 00000000 */   nop
/* 7FF58 800E6AA8 8E220000 */  lw        $v0, ($s1)
/* 7FF5C 800E6AAC 30421000 */  andi      $v0, $v0, 0x1000
/* 7FF60 800E6AB0 14400027 */  bnez      $v0, .L800E6B50
/* 7FF64 800E6AB4 0000102D */   daddu    $v0, $zero, $zero
/* 7FF68 800E6AB8 2E020003 */  sltiu     $v0, $s0, 3
/* 7FF6C 800E6ABC 10400023 */  beqz      $v0, .L800E6B4C
/* 7FF70 800E6AC0 24020001 */   addiu    $v0, $zero, 1
/* 7FF74 800E6AC4 08039AD4 */  j         .L800E6B50
/* 7FF78 800E6AC8 00000000 */   nop
.L800E6ACC:
/* 7FF7C 800E6ACC 0C03ACF8 */  jal       partner_player_can_pause
/* 7FF80 800E6AD0 00000000 */   nop
/* 7FF84 800E6AD4 1040001D */  beqz      $v0, .L800E6B4C
/* 7FF88 800E6AD8 24020006 */   addiu    $v0, $zero, 6
/* 7FF8C 800E6ADC 82430003 */  lb        $v1, 3($s2)
/* 7FF90 800E6AE0 14620003 */  bne       $v1, $v0, .L800E6AF0
/* 7FF94 800E6AE4 24020009 */   addiu    $v0, $zero, 9
/* 7FF98 800E6AE8 08039AD4 */  j         .L800E6B50
/* 7FF9C 800E6AEC 2E020003 */   sltiu    $v0, $s0, 3
.L800E6AF0:
/* 7FFA0 800E6AF0 14620007 */  bne       $v1, $v0, .L800E6B10
/* 7FFA4 800E6AF4 24020008 */   addiu    $v0, $zero, 8
/* 7FFA8 800E6AF8 24020021 */  addiu     $v0, $zero, 0x21
/* 7FFAC 800E6AFC 16020014 */  bne       $s0, $v0, .L800E6B50
/* 7FFB0 800E6B00 0000102D */   daddu    $v0, $zero, $zero
/* 7FFB4 800E6B04 A220000F */  sb        $zero, 0xf($s1)
/* 7FFB8 800E6B08 08039AD4 */  j         .L800E6B50
/* 7FFBC 800E6B0C 24020001 */   addiu    $v0, $zero, 1
.L800E6B10:
/* 7FFC0 800E6B10 1462000A */  bne       $v1, $v0, .L800E6B3C
/* 7FFC4 800E6B14 24020007 */   addiu    $v0, $zero, 7
/* 7FFC8 800E6B18 24020021 */  addiu     $v0, $zero, 0x21
/* 7FFCC 800E6B1C 1602000C */  bne       $s0, $v0, .L800E6B50
/* 7FFD0 800E6B20 0000102D */   daddu    $v0, $zero, $zero
/* 7FFD4 800E6B24 0C0AF5F7 */  jal       func_802BD7DC
/* 7FFD8 800E6B28 00000000 */   nop
/* 7FFDC 800E6B2C 14400008 */  bnez      $v0, .L800E6B50
/* 7FFE0 800E6B30 24020001 */   addiu    $v0, $zero, 1
/* 7FFE4 800E6B34 08039AD1 */  j         .L800E6B44
/* 7FFE8 800E6B38 00000000 */   nop
.L800E6B3C:
/* 7FFEC 800E6B3C 14620004 */  bne       $v1, $v0, .L800E6B50
/* 7FFF0 800E6B40 0000102D */   daddu    $v0, $zero, $zero
.L800E6B44:
/* 7FFF4 800E6B44 0C05272D */  jal       play_sound
/* 7FFF8 800E6B48 2404021D */   addiu    $a0, $zero, 0x21d
.L800E6B4C:
/* 7FFFC 800E6B4C 0000102D */  daddu     $v0, $zero, $zero
.L800E6B50:
/* 80000 800E6B50 8FBF001C */  lw        $ra, 0x1c($sp)
/* 80004 800E6B54 8FB20018 */  lw        $s2, 0x18($sp)
/* 80008 800E6B58 8FB10014 */  lw        $s1, 0x14($sp)
/* 8000C 800E6B5C 8FB00010 */  lw        $s0, 0x10($sp)
/* 80010 800E6B60 03E00008 */  jr        $ra
/* 80014 800E6B64 27BD0020 */   addiu    $sp, $sp, 0x20
