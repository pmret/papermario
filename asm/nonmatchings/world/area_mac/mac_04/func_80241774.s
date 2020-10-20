.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241774
/* 844344 80241774 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 844348 80241778 AFBF0010 */  sw        $ra, 0x10($sp)
/* 84434C 8024177C 8C82000C */  lw        $v0, 0xc($a0)
/* 844350 80241780 0C0B1EAF */  jal       get_variable
/* 844354 80241784 8C450000 */   lw       $a1, ($v0)
/* 844358 80241788 3C018024 */  lui       $at, 0x8024
/* 84435C 8024178C AC226614 */  sw        $v0, 0x6614($at)
/* 844360 80241790 24020002 */  addiu     $v0, $zero, 2
/* 844364 80241794 8FBF0010 */  lw        $ra, 0x10($sp)
/* 844368 80241798 24030001 */  addiu     $v1, $zero, 1
/* 84436C 8024179C 3C018024 */  lui       $at, 0x8024
/* 844370 802417A0 AC236610 */  sw        $v1, 0x6610($at)
/* 844374 802417A4 03E00008 */  jr        $ra
/* 844378 802417A8 27BD0018 */   addiu    $sp, $sp, 0x18
