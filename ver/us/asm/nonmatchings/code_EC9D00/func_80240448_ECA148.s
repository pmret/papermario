.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240448_ECA148
/* ECA148 80240448 3C028011 */  lui       $v0, %hi(D_80117852)
/* ECA14C 8024044C 80427852 */  lb        $v0, %lo(D_80117852)($v0)
/* ECA150 80240450 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* ECA154 80240454 AFBF0010 */  sw        $ra, 0x10($sp)
/* ECA158 80240458 00021100 */  sll       $v0, $v0, 4
/* ECA15C 8024045C 3C048009 */  lui       $a0, %hi(D_80094900)
/* ECA160 80240460 00822021 */  addu      $a0, $a0, $v0
/* ECA164 80240464 8C844900 */  lw        $a0, %lo(D_80094900)($a0)
/* ECA168 80240468 0C04C31D */  jal       func_80130C74
/* ECA16C 8024046C 0000282D */   daddu    $a1, $zero, $zero
/* ECA170 80240470 8FBF0010 */  lw        $ra, 0x10($sp)
/* ECA174 80240474 24020002 */  addiu     $v0, $zero, 2
/* ECA178 80240478 03E00008 */  jr        $ra
/* ECA17C 8024047C 27BD0018 */   addiu    $sp, $sp, 0x18
