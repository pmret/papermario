.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024029C
/* 8CAB9C 8024029C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8CABA0 802402A0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8CABA4 802402A4 0C00EABB */  jal       get_npc_unsafe
/* 8CABA8 802402A8 2404FFFC */   addiu    $a0, $zero, -4
/* 8CABAC 802402AC 8C420000 */  lw        $v0, ($v0)
/* 8CABB0 802402B0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8CABB4 802402B4 30421000 */  andi      $v0, $v0, 0x1000
/* 8CABB8 802402B8 0002102B */  sltu      $v0, $zero, $v0
/* 8CABBC 802402BC 00021040 */  sll       $v0, $v0, 1
/* 8CABC0 802402C0 03E00008 */  jr        $ra
/* 8CABC4 802402C4 27BD0018 */   addiu    $sp, $sp, 0x18
