.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241438_8535A8
/* 8535A8 80241438 24020001 */  addiu     $v0, $zero, 1
/* 8535AC 8024143C 3C018015 */  lui       $at, %hi(D_80151310)
/* 8535B0 80241440 AC221310 */  sw        $v0, %lo(D_80151310)($at)
/* 8535B4 80241444 03E00008 */  jr        $ra
/* 8535B8 80241448 24020002 */   addiu    $v0, $zero, 2
