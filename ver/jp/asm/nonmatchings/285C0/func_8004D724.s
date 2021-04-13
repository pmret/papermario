.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004D724
/* 28B24 8004D724 3C04800A */  lui       $a0, %hi(D_8009A644)
/* 28B28 8004D728 8C84A644 */  lw        $a0, %lo(D_8009A644)($a0)
/* 28B2C 8004D72C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 28B30 8004D730 AFBF0010 */  sw        $ra, 0x10($sp)
/* 28B34 8004D734 0C0135D6 */  jal       func_8004D758
/* 28B38 8004D738 00000000 */   nop
/* 28B3C 8004D73C 3C04800A */  lui       $a0, %hi(D_8009A5DC)
/* 28B40 8004D740 8C84A5DC */  lw        $a0, %lo(D_8009A5DC)($a0)
/* 28B44 8004D744 0C0135D6 */  jal       func_8004D758
/* 28B48 8004D748 00000000 */   nop
/* 28B4C 8004D74C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 28B50 8004D750 03E00008 */  jr        $ra
/* 28B54 8004D754 27BD0018 */   addiu    $sp, $sp, 0x18
