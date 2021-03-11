.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel star_SetNpcCollision32
/* 794208 802A14E8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 79420C 802A14EC AFBF0010 */  sw        $ra, 0x10($sp)
/* 794210 802A14F0 0C00EABB */  jal       get_npc_unsafe
/* 794214 802A14F4 24040064 */   addiu    $a0, $zero, 0x64
/* 794218 802A14F8 0040202D */  daddu     $a0, $v0, $zero
/* 79421C 802A14FC 24030020 */  addiu     $v1, $zero, 0x20
/* 794220 802A1500 A48300A8 */  sh        $v1, 0xa8($a0)
/* 794224 802A1504 A48300A6 */  sh        $v1, 0xa6($a0)
/* 794228 802A1508 8FBF0010 */  lw        $ra, 0x10($sp)
/* 79422C 802A150C 24020002 */  addiu     $v0, $zero, 2
/* 794230 802A1510 03E00008 */  jr        $ra
/* 794234 802A1514 27BD0018 */   addiu    $sp, $sp, 0x18
/* 794238 802A1518 00000000 */  nop
/* 79423C 802A151C 00000000 */  nop
