.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel nuGfxPreNMIFuncSet
/* 3A340 8005EF40 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3A344 8005EF44 AFB00010 */  sw        $s0, 0x10($sp)
/* 3A348 8005EF48 0080802D */  daddu     $s0, $a0, $zero
/* 3A34C 8005EF4C AFBF0014 */  sw        $ra, 0x14($sp)
/* 3A350 8005EF50 0C018244 */  jal       func_80060910
/* 3A354 8005EF54 24040001 */   addiu    $a0, $zero, 1
/* 3A358 8005EF58 3C018009 */  lui       $at, %hi(D_80093CE4)
/* 3A35C 8005EF5C AC303CE4 */  sw        $s0, %lo(D_80093CE4)($at)
/* 3A360 8005EF60 0C018244 */  jal       func_80060910
/* 3A364 8005EF64 0040202D */   daddu    $a0, $v0, $zero
/* 3A368 8005EF68 8FBF0014 */  lw        $ra, 0x14($sp)
/* 3A36C 8005EF6C 8FB00010 */  lw        $s0, 0x10($sp)
/* 3A370 8005EF70 03E00008 */  jr        $ra
/* 3A374 8005EF74 27BD0018 */   addiu    $sp, $sp, 0x18
/* 3A378 8005EF78 00000000 */  nop
/* 3A37C 8005EF7C 00000000 */  nop
