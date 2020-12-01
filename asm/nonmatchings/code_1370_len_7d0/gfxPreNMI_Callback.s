.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel gfxPreNMI_Callback
/* 1B0C 8002670C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1B10 80026710 24020001 */  addiu     $v0, $zero, 1
/* 1B14 80026714 AFBF0010 */  sw        $ra, 0x10($sp)
/* 1B18 80026718 3C018007 */  lui       $at, %hi(D_80073E00)
/* 1B1C 8002671C AC223E00 */  sw        $v0, %lo(D_80073E00)($at)
/* 1B20 80026720 0C018028 */  jal       nuContRmbForceStop
/* 1B24 80026724 00000000 */   nop      
/* 1B28 80026728 8FBF0010 */  lw        $ra, 0x10($sp)
/* 1B2C 8002672C 03E00008 */  jr        $ra
/* 1B30 80026730 27BD0018 */   addiu    $sp, $sp, 0x18
/* 1B34 80026734 00000000 */  nop       
/* 1B38 80026738 00000000 */  nop       
/* 1B3C 8002673C 00000000 */  nop       
