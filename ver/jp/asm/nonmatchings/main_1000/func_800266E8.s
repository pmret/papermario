.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800266E8
/* 1AE8 800266E8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1AEC 800266EC 24020001 */  addiu     $v0, $zero, 1
/* 1AF0 800266F0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 1AF4 800266F4 3C018007 */  lui       $at, %hi(D_80073DE0)
/* 1AF8 800266F8 AC223DE0 */  sw        $v0, %lo(D_80073DE0)($at)
/* 1AFC 800266FC 0C017F54 */  jal       func_8005FD50
/* 1B00 80026700 00000000 */   nop
/* 1B04 80026704 8FBF0010 */  lw        $ra, 0x10($sp)
/* 1B08 80026708 03E00008 */  jr        $ra
/* 1B0C 8002670C 27BD0018 */   addiu    $sp, $sp, 0x18
