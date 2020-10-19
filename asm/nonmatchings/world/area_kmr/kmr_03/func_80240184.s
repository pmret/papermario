.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240184
/* 8C8114 80240184 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8C8118 80240188 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8C811C 8024018C 0C00EABB */  jal       get_npc_unsafe
/* 8C8120 80240190 2404FFFC */   addiu    $a0, $zero, -4
/* 8C8124 80240194 8C420000 */  lw        $v0, ($v0)
/* 8C8128 80240198 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8C812C 8024019C 30421000 */  andi      $v0, $v0, 0x1000
/* 8C8130 802401A0 0002102B */  sltu      $v0, $zero, $v0
/* 8C8134 802401A4 00021040 */  sll       $v0, $v0, 1
/* 8C8138 802401A8 03E00008 */  jr        $ra
/* 8C813C 802401AC 27BD0018 */   addiu    $sp, $sp, 0x18
