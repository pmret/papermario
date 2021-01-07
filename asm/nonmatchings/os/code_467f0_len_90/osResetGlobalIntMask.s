.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osResetGlobalIntMask
/* 46830 8006B430 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 46834 8006B434 AFB00010 */  sw        $s0, 0x10($sp)
/* 46838 8006B438 AFBF0014 */  sw        $ra, 0x14($sp)
/* 4683C 8006B43C 0C01ACD8 */  jal       __osDisableInt
/* 46840 8006B440 00808021 */   addu     $s0, $a0, $zero
/* 46844 8006B444 3C038009 */  lui       $v1, %hi(D_80095900)
/* 46848 8006B448 8C635900 */  lw        $v1, %lo(D_80095900)($v1)
/* 4684C 8006B44C 00108027 */  nor       $s0, $zero, $s0
/* 46850 8006B450 36100401 */  ori       $s0, $s0, 0x401
/* 46854 8006B454 00701824 */  and       $v1, $v1, $s0
/* 46858 8006B458 3C018009 */  lui       $at, %hi(D_80095900)
/* 4685C 8006B45C AC235900 */  sw        $v1, %lo(D_80095900)($at)
/* 46860 8006B460 0C01ACF4 */  jal       __osRestoreInt
/* 46864 8006B464 00402021 */   addu     $a0, $v0, $zero
/* 46868 8006B468 8FBF0014 */  lw        $ra, 0x14($sp)
/* 4686C 8006B46C 8FB00010 */  lw        $s0, 0x10($sp)
/* 46870 8006B470 03E00008 */  jr        $ra
/* 46874 8006B474 27BD0018 */   addiu    $sp, $sp, 0x18
/* 46878 8006B478 00000000 */  nop       
/* 4687C 8006B47C 00000000 */  nop       
