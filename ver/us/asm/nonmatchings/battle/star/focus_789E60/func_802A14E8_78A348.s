.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A14E8_78A348
/* 78A348 802A14E8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 78A34C 802A14EC AFBF0010 */  sw        $ra, 0x10($sp)
/* 78A350 802A14F0 0C00EABB */  jal       get_npc_unsafe
/* 78A354 802A14F4 24040064 */   addiu    $a0, $zero, 0x64
/* 78A358 802A14F8 0040202D */  daddu     $a0, $v0, $zero
/* 78A35C 802A14FC 24030020 */  addiu     $v1, $zero, 0x20
/* 78A360 802A1500 A48300A8 */  sh        $v1, 0xa8($a0)
/* 78A364 802A1504 A48300A6 */  sh        $v1, 0xa6($a0)
/* 78A368 802A1508 8FBF0010 */  lw        $ra, 0x10($sp)
/* 78A36C 802A150C 24020002 */  addiu     $v0, $zero, 2
/* 78A370 802A1510 03E00008 */  jr        $ra
/* 78A374 802A1514 27BD0018 */   addiu    $sp, $sp, 0x18
