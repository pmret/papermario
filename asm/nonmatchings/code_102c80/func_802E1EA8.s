.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E1EA8
/* 103728 802E1EA8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 10372C 802E1EAC AFB00010 */  sw        $s0, 0x10($sp)
/* 103730 802E1EB0 0080802D */  daddu     $s0, $a0, $zero
/* 103734 802E1EB4 AFBF0014 */  sw        $ra, 0x14($sp)
/* 103738 802E1EB8 8E020040 */  lw        $v0, 0x40($s0)
/* 10373C 802E1EBC 0C051568 */  jal       set_area_flag
/* 103740 802E1EC0 94440020 */   lhu      $a0, 0x20($v0)
/* 103744 802E1EC4 0C04419E */  jal       func_80110678
/* 103748 802E1EC8 0200202D */   daddu    $a0, $s0, $zero
/* 10374C 802E1ECC 8FBF0014 */  lw        $ra, 0x14($sp)
/* 103750 802E1ED0 8FB00010 */  lw        $s0, 0x10($sp)
/* 103754 802E1ED4 03E00008 */  jr        $ra
/* 103758 802E1ED8 27BD0018 */   addiu    $sp, $sp, 0x18
