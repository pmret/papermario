.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004DA74
/* 28E74 8004DA74 3C04800A */  lui       $a0, %hi(D_8009A664)
/* 28E78 8004DA78 8C84A664 */  lw        $a0, %lo(D_8009A664)($a0)
/* 28E7C 8004DA7C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 28E80 8004DA80 AFBF0010 */  sw        $ra, 0x10($sp)
/* 28E84 8004DA84 0C0136AA */  jal       func_8004DAA8
/* 28E88 8004DA88 00000000 */   nop
/* 28E8C 8004DA8C 3C04800A */  lui       $a0, %hi(D_8009A5FC)
/* 28E90 8004DA90 8C84A5FC */  lw        $a0, %lo(D_8009A5FC)($a0)
/* 28E94 8004DA94 0C0136AA */  jal       func_8004DAA8
/* 28E98 8004DA98 00000000 */   nop
/* 28E9C 8004DA9C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 28EA0 8004DAA0 03E00008 */  jr        $ra
/* 28EA4 8004DAA4 27BD0018 */   addiu    $sp, $sp, 0x18
