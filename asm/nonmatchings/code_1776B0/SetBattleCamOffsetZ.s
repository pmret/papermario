.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetBattleCamOffsetZ
/* 17D338 8024EA58 3C028028 */  lui       $v0, 0x8028
/* 17D33C 8024EA5C 80420CE0 */  lb        $v0, 0xce0($v0)
/* 17D340 8024EA60 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 17D344 8024EA64 AFBF0010 */  sw        $ra, 0x10($sp)
/* 17D348 8024EA68 8C85000C */  lw        $a1, 0xc($a0)
/* 17D34C 8024EA6C 14400007 */  bnez      $v0, .L8024EA8C
/* 17D350 8024EA70 24020002 */   addiu    $v0, $zero, 2
/* 17D354 8024EA74 8CA50000 */  lw        $a1, ($a1)
/* 17D358 8024EA78 0C0B1EAF */  jal       get_variable
/* 17D35C 8024EA7C 00000000 */   nop      
/* 17D360 8024EA80 3C01802A */  lui       $at, 0x802a
/* 17D364 8024EA84 A422F286 */  sh        $v0, -0xd7a($at)
/* 17D368 8024EA88 24020002 */  addiu     $v0, $zero, 2
.L8024EA8C:
/* 17D36C 8024EA8C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 17D370 8024EA90 03E00008 */  jr        $ra
/* 17D374 8024EA94 27BD0018 */   addiu    $sp, $sp, 0x18
