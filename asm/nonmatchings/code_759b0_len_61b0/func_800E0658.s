.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800E0658
/* 79B08 800E0658 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 79B0C 800E065C 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 79B10 800E0660 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 79B14 800E0664 AFBF0010 */  sw        $ra, 0x10($sp)
/* 79B18 800E0668 8C420004 */  lw        $v0, 4($v0)
/* 79B1C 800E066C 30420020 */  andi      $v0, $v0, 0x20
/* 79B20 800E0670 10400007 */  beqz      $v0, .L800E0690
/* 79B24 800E0674 00000000 */   nop      
/* 79B28 800E0678 3C028011 */  lui       $v0, %hi(D_8010C940)
/* 79B2C 800E067C 8C42C940 */  lw        $v0, %lo(D_8010C940)($v0)
/* 79B30 800E0680 10400003 */  beqz      $v0, .L800E0690
/* 79B34 800E0684 00000000 */   nop      
/* 79B38 800E0688 0C0ADC72 */  jal       func_802B71C8
/* 79B3C 800E068C 00000000 */   nop      
.L800E0690:
/* 79B40 800E0690 8FBF0010 */  lw        $ra, 0x10($sp)
/* 79B44 800E0694 03E00008 */  jr        $ra
/* 79B48 800E0698 27BD0018 */   addiu    $sp, $sp, 0x18
