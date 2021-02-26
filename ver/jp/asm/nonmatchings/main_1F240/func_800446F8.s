.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800446F8
/* 1FAF8 800446F8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1FAFC 800446FC AFBF0010 */  sw        $ra, 0x10($sp)
/* 1FB00 80044700 8C82000C */  lw        $v0, 0xc($a0)
/* 1FB04 80044704 0C0B1EAF */  jal       func_802C7ABC
/* 1FB08 80044708 8C450000 */   lw       $a1, ($v0)
/* 1FB0C 8004470C 3C04800B */  lui       $a0, %hi(D_800B0EF0)
/* 1FB10 80044710 24840EF0 */  addiu     $a0, $a0, %lo(D_800B0EF0)
/* 1FB14 80044714 24030001 */  addiu     $v1, $zero, 1
/* 1FB18 80044718 A0830011 */  sb        $v1, 0x11($a0)
/* 1FB1C 8004471C 2403FFFF */  addiu     $v1, $zero, -1
/* 1FB20 80044720 AC820014 */  sw        $v0, 0x14($a0)
/* 1FB24 80044724 AC830018 */  sw        $v1, 0x18($a0)
/* 1FB28 80044728 8FBF0010 */  lw        $ra, 0x10($sp)
/* 1FB2C 8004472C 24020002 */  addiu     $v0, $zero, 2
/* 1FB30 80044730 03E00008 */  jr        $ra
/* 1FB34 80044734 27BD0018 */   addiu    $sp, $sp, 0x18
