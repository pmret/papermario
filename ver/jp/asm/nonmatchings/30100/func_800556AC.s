.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800556AC
/* 30AAC 800556AC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 30AB0 800556B0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 30AB4 800556B4 0C0135E4 */  jal       func_8004D790
/* 30AB8 800556B8 00000000 */   nop
/* 30ABC 800556BC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 30AC0 800556C0 03E00008 */  jr        $ra
/* 30AC4 800556C4 27BD0018 */   addiu    $sp, $sp, 0x18
