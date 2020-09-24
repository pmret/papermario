.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80282774
/* 7E35F4 80282774 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7E35F8 80282778 AFBF0014 */  sw        $ra, 0x14($sp)
/* 7E35FC 8028277C AFB00010 */  sw        $s0, 0x10($sp)
/* 7E3600 80282780 0C04D090 */  jal       func_80134240
/* 7E3604 80282784 8C900074 */   lw       $s0, 0x74($a0)
/* 7E3608 80282788 86040008 */  lh        $a0, 8($s0)
/* 7E360C 8028278C 0C04D08C */  jal       func_80134230
/* 7E3610 80282790 A602000A */   sh       $v0, 0xa($s0)
/* 7E3614 80282794 8FBF0014 */  lw        $ra, 0x14($sp)
/* 7E3618 80282798 8FB00010 */  lw        $s0, 0x10($sp)
/* 7E361C 8028279C 24020002 */  addiu     $v0, $zero, 2
/* 7E3620 802827A0 03E00008 */  jr        $ra
/* 7E3624 802827A4 27BD0018 */   addiu    $sp, $sp, 0x18
