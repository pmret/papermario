.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80283BB0
/* 7E4A30 80283BB0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7E4A34 80283BB4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 7E4A38 80283BB8 0C03BCE9 */  jal       func_800EF3A4
/* 7E4A3C 80283BBC 00000000 */   nop      
/* 7E4A40 80283BC0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 7E4A44 80283BC4 24020002 */  addiu     $v0, $zero, 2
/* 7E4A48 80283BC8 03E00008 */  jr        $ra
/* 7E4A4C 80283BCC 27BD0018 */   addiu    $sp, $sp, 0x18
