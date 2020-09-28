.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80052E18
/* 2E218 80052E18 9082003D */  lbu       $v0, 0x3d($a0)
/* 2E21C 80052E1C 34420020 */  ori       $v0, $v0, 0x20
/* 2E220 80052E20 03E00008 */  jr        $ra
/* 2E224 80052E24 A082003D */   sb       $v0, 0x3d($a0)
/* 2E228 80052E28 00000000 */  nop       
/* 2E22C 80052E2C 00000000 */  nop       
