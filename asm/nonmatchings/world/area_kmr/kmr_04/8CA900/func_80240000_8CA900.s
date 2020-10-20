.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_8CA900
/* 8CA900 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8CA904 80240004 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8CA908 80240008 0C00EABB */  jal       get_npc_unsafe
/* 8CA90C 8024000C 2404FFFC */   addiu    $a0, $zero, -4
/* 8CA910 80240010 8C420000 */  lw        $v0, ($v0)
/* 8CA914 80240014 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8CA918 80240018 30421000 */  andi      $v0, $v0, 0x1000
/* 8CA91C 8024001C 0002102B */  sltu      $v0, $zero, $v0
/* 8CA920 80240020 00021040 */  sll       $v0, $v0, 1
/* 8CA924 80240024 03E00008 */  jr        $ra
/* 8CA928 80240028 27BD0018 */   addiu    $sp, $sp, 0x18
