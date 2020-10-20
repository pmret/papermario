.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802417A4_9C6B84
/* 9C6B84 802417A4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9C6B88 802417A8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 9C6B8C 802417AC 8C82000C */  lw        $v0, 0xc($a0)
/* 9C6B90 802417B0 0C0B1EAF */  jal       get_variable
/* 9C6B94 802417B4 8C450000 */   lw       $a1, ($v0)
/* 9C6B98 802417B8 3C038025 */  lui       $v1, 0x8025
/* 9C6B9C 802417BC 8C631C60 */  lw        $v1, 0x1c60($v1)
/* 9C6BA0 802417C0 8C63000C */  lw        $v1, 0xc($v1)
/* 9C6BA4 802417C4 AC620034 */  sw        $v0, 0x34($v1)
/* 9C6BA8 802417C8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9C6BAC 802417CC 24020002 */  addiu     $v0, $zero, 2
/* 9C6BB0 802417D0 03E00008 */  jr        $ra
/* 9C6BB4 802417D4 27BD0018 */   addiu    $sp, $sp, 0x18
