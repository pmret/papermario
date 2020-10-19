.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242014
/* 8B2084 80242014 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8B2088 80242018 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8B208C 8024201C 0C00EABB */  jal       get_npc_unsafe
/* 8B2090 80242020 2404FFFC */   addiu    $a0, $zero, -4
/* 8B2094 80242024 8C420000 */  lw        $v0, ($v0)
/* 8B2098 80242028 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8B209C 8024202C 30421000 */  andi      $v0, $v0, 0x1000
/* 8B20A0 80242030 0002102B */  sltu      $v0, $zero, $v0
/* 8B20A4 80242034 00021040 */  sll       $v0, $v0, 1
/* 8B20A8 80242038 03E00008 */  jr        $ra
/* 8B20AC 8024203C 27BD0018 */   addiu    $sp, $sp, 0x18
