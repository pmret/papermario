.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800696B0
/* 44AB0 800696B0 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 44AB4 800696B4 AFB00038 */  sw        $s0, 0x38($sp)
/* 44AB8 800696B8 00808021 */  addu      $s0, $a0, $zero
/* 44ABC 800696BC AFB1003C */  sw        $s1, 0x3c($sp)
/* 44AC0 800696C0 00A08821 */  addu      $s1, $a1, $zero
/* 44AC4 800696C4 2403001F */  addiu     $v1, $zero, 0x1f
/* 44AC8 800696C8 27A20037 */  addiu     $v0, $sp, 0x37
/* 44ACC 800696CC AFBF0040 */  sw        $ra, 0x40($sp)
.L800696D0:
/* 44AD0 800696D0 A0510000 */  sb        $s1, ($v0)
/* 44AD4 800696D4 2463FFFF */  addiu     $v1, $v1, -1
/* 44AD8 800696D8 0461FFFD */  bgez      $v1, .L800696D0
/* 44ADC 800696DC 2442FFFF */   addiu    $v0, $v0, -1
/* 44AE0 800696E0 AFA00010 */  sw        $zero, 0x10($sp)
/* 44AE4 800696E4 8E040004 */  lw        $a0, 4($s0)
/* 44AE8 800696E8 8E050008 */  lw        $a1, 8($s0)
/* 44AEC 800696EC 24060400 */  addiu     $a2, $zero, 0x400
/* 44AF0 800696F0 0C01A8E8 */  jal       func_8006A3A0
/* 44AF4 800696F4 27A70018 */   addiu    $a3, $sp, 0x18
/* 44AF8 800696F8 50400001 */  beql      $v0, $zero, .L80069700
/* 44AFC 800696FC A2110065 */   sb       $s1, 0x65($s0)
.L80069700:
/* 44B00 80069700 8FBF0040 */  lw        $ra, 0x40($sp)
/* 44B04 80069704 8FB1003C */  lw        $s1, 0x3c($sp)
/* 44B08 80069708 8FB00038 */  lw        $s0, 0x38($sp)
/* 44B0C 8006970C 03E00008 */  jr        $ra
/* 44B10 80069710 27BD0048 */   addiu    $sp, $sp, 0x48
/* 44B14 80069714 00000000 */  nop
/* 44B18 80069718 00000000 */  nop
/* 44B1C 8006971C 00000000 */  nop
