.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242784_95D984
/* 95D984 80242784 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 95D988 80242788 AFBF0010 */  sw        $ra, 0x10($sp)
/* 95D98C 8024278C 8C82000C */  lw        $v0, 0xc($a0)
/* 95D990 80242790 0C0B1EAF */  jal       get_variable
/* 95D994 80242794 8C450000 */   lw       $a1, ($v0)
/* 95D998 80242798 3C018024 */  lui       $at, %hi(D_802477E4_9629E4)
/* 95D99C 8024279C AC2277E4 */  sw        $v0, %lo(D_802477E4_9629E4)($at)
/* 95D9A0 802427A0 24020002 */  addiu     $v0, $zero, 2
/* 95D9A4 802427A4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 95D9A8 802427A8 24030001 */  addiu     $v1, $zero, 1
/* 95D9AC 802427AC 3C018024 */  lui       $at, %hi(D_802477E0_9629E0)
/* 95D9B0 802427B0 AC2377E0 */  sw        $v1, %lo(D_802477E0_9629E0)($at)
/* 95D9B4 802427B4 03E00008 */  jr        $ra
/* 95D9B8 802427B8 27BD0018 */   addiu    $sp, $sp, 0x18
