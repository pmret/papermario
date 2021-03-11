.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel star_SetNpcCollision32
/* 79C488 802A14E8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 79C48C 802A14EC AFBF0010 */  sw        $ra, 0x10($sp)
/* 79C490 802A14F0 0C00EABB */  jal       get_npc_unsafe
/* 79C494 802A14F4 24040064 */   addiu    $a0, $zero, 0x64
/* 79C498 802A14F8 0040202D */  daddu     $a0, $v0, $zero
/* 79C49C 802A14FC 24030020 */  addiu     $v1, $zero, 0x20
/* 79C4A0 802A1500 A48300A8 */  sh        $v1, 0xa8($a0)
/* 79C4A4 802A1504 A48300A6 */  sh        $v1, 0xa6($a0)
/* 79C4A8 802A1508 8FBF0010 */  lw        $ra, 0x10($sp)
/* 79C4AC 802A150C 24020002 */  addiu     $v0, $zero, 2
/* 79C4B0 802A1510 03E00008 */  jr        $ra
/* 79C4B4 802A1514 27BD0018 */   addiu    $sp, $sp, 0x18
