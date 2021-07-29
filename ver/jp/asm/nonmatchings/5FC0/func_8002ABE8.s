.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002ABE8
/* 5FE8 8002ABE8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 5FEC 8002ABEC 0080282D */  daddu     $a1, $a0, $zero
/* 5FF0 8002ABF0 3C048030 */  lui       $a0, %hi(D_802FB800)
/* 5FF4 8002ABF4 2484B800 */  addiu     $a0, $a0, %lo(D_802FB800)
/* 5FF8 8002ABF8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 5FFC 8002ABFC 0C00A40B */  jal       func_8002902C
/* 6000 8002AC00 00000000 */   nop
/* 6004 8002AC04 8FBF0010 */  lw        $ra, 0x10($sp)
/* 6008 8002AC08 03E00008 */  jr        $ra
/* 600C 8002AC0C 27BD0018 */   addiu    $sp, $sp, 0x18
