.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240678_9D7698
/* 9D7698 80240678 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9D769C 8024067C AFBF0010 */  sw        $ra, 0x10($sp)
/* 9D76A0 80240680 8C82000C */  lw        $v0, 0xc($a0)
/* 9D76A4 80240684 0C0B1EAF */  jal       get_variable
/* 9D76A8 80240688 8C450000 */   lw       $a1, ($v0)
/* 9D76AC 8024068C 3C018024 */  lui       $at, %hi(func_80245438)
/* 9D76B0 80240690 AC225438 */  sw        $v0, %lo(func_80245438)($at)
/* 9D76B4 80240694 24020002 */  addiu     $v0, $zero, 2
/* 9D76B8 80240698 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9D76BC 8024069C 24030001 */  addiu     $v1, $zero, 1
/* 9D76C0 802406A0 3C018024 */  lui       $at, %hi(D_80245434)
/* 9D76C4 802406A4 AC235434 */  sw        $v1, %lo(D_80245434)($at)
/* 9D76C8 802406A8 03E00008 */  jr        $ra
/* 9D76CC 802406AC 27BD0018 */   addiu    $sp, $sp, 0x18
