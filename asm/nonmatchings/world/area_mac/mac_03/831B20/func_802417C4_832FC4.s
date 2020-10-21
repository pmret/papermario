.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802417C4_832FC4
/* 832FC4 802417C4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 832FC8 802417C8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 832FCC 802417CC 8C82000C */  lw        $v0, 0xc($a0)
/* 832FD0 802417D0 0C0B1EAF */  jal       get_variable
/* 832FD4 802417D4 8C450000 */   lw       $a1, ($v0)
/* 832FD8 802417D8 3C018025 */  lui       $at, 0x8025
/* 832FDC 802417DC AC228C70 */  sw        $v0, -0x7390($at)
/* 832FE0 802417E0 24020002 */  addiu     $v0, $zero, 2
/* 832FE4 802417E4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 832FE8 802417E8 24030001 */  addiu     $v1, $zero, 1
/* 832FEC 802417EC 3C018025 */  lui       $at, 0x8025
/* 832FF0 802417F0 AC238C6C */  sw        $v1, -0x7394($at)
/* 832FF4 802417F4 03E00008 */  jr        $ra
/* 832FF8 802417F8 27BD0018 */   addiu    $sp, $sp, 0x18
