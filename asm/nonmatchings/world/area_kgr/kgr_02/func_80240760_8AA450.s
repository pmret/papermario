.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240760_8AABB0
/* 8AABB0 80240760 3C028016 */  lui       $v0, 0x8016
/* 8AABB4 80240764 8442A568 */  lh        $v0, -0x5a98($v0)
/* 8AABB8 80240768 04400002 */  bltz      $v0, .L80240774
/* 8AABBC 8024076C 24020001 */   addiu    $v0, $zero, 1
/* 8AABC0 80240770 AC820088 */  sw        $v0, 0x88($a0)
.L80240774:
/* 8AABC4 80240774 03E00008 */  jr        $ra
/* 8AABC8 80240778 24020002 */   addiu    $v0, $zero, 2
/* 8AABCC 8024077C 00000000 */  nop       
