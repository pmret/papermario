.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802196F0_465B80
/* 465B80 802196F0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 465B84 802196F4 AFB00010 */  sw        $s0, 0x10($sp)
/* 465B88 802196F8 0080802D */  daddu     $s0, $a0, $zero
/* 465B8C 802196FC AFBF0018 */  sw        $ra, 0x18($sp)
/* 465B90 80219700 AFB10014 */  sw        $s1, 0x14($sp)
/* 465B94 80219704 8E040148 */  lw        $a0, 0x148($s0)
/* 465B98 80219708 0C09A75B */  jal       get_actor
/* 465B9C 8021970C 8E11000C */   lw       $s1, 0xc($s0)
/* 465BA0 80219710 0200202D */  daddu     $a0, $s0, $zero
/* 465BA4 80219714 8E250000 */  lw        $a1, ($s1)
/* 465BA8 80219718 0C0B1EAF */  jal       get_variable
/* 465BAC 8021971C 8C500094 */   lw       $s0, 0x94($v0)
/* 465BB0 80219720 AE020010 */  sw        $v0, 0x10($s0)
/* 465BB4 80219724 8FBF0018 */  lw        $ra, 0x18($sp)
/* 465BB8 80219728 8FB10014 */  lw        $s1, 0x14($sp)
/* 465BBC 8021972C 8FB00010 */  lw        $s0, 0x10($sp)
/* 465BC0 80219730 24020002 */  addiu     $v0, $zero, 2
/* 465BC4 80219734 03E00008 */  jr        $ra
/* 465BC8 80219738 27BD0020 */   addiu    $sp, $sp, 0x20
