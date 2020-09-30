.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80283B88
/* 7E4A08 80283B88 3C0141A0 */  lui       $at, 0x41a0
/* 7E4A0C 80283B8C 44816000 */  mtc1      $at, $f12
/* 7E4A10 80283B90 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7E4A14 80283B94 AFBF0010 */  sw        $ra, 0x10($sp)
/* 7E4A18 80283B98 0C03BCE5 */  jal       func_800EF394
/* 7E4A1C 80283B9C 00000000 */   nop      
/* 7E4A20 80283BA0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 7E4A24 80283BA4 24020002 */  addiu     $v0, $zero, 2
/* 7E4A28 80283BA8 03E00008 */  jr        $ra
/* 7E4A2C 80283BAC 27BD0018 */   addiu    $sp, $sp, 0x18
