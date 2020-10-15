.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetBattleCamYaw
/* 17D3C4 8024EAE4 3C028028 */  lui       $v0, 0x8028
/* 17D3C8 8024EAE8 80420CE0 */  lb        $v0, 0xce0($v0)
/* 17D3CC 8024EAEC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 17D3D0 8024EAF0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 17D3D4 8024EAF4 8C85000C */  lw        $a1, 0xc($a0)
/* 17D3D8 8024EAF8 14400007 */  bnez      $v0, .L8024EB18
/* 17D3DC 8024EAFC 24020002 */   addiu    $v0, $zero, 2
/* 17D3E0 8024EB00 8CA50000 */  lw        $a1, ($a1)
/* 17D3E4 8024EB04 0C0B1EAF */  jal       get_variable
/* 17D3E8 8024EB08 00000000 */   nop      
/* 17D3EC 8024EB0C 3C01802A */  lui       $at, 0x802a
/* 17D3F0 8024EB10 A422F282 */  sh        $v0, -0xd7e($at)
/* 17D3F4 8024EB14 24020002 */  addiu     $v0, $zero, 2
.L8024EB18:
/* 17D3F8 8024EB18 8FBF0010 */  lw        $ra, 0x10($sp)
/* 17D3FC 8024EB1C 03E00008 */  jr        $ra
/* 17D400 8024EB20 27BD0018 */   addiu    $sp, $sp, 0x18
