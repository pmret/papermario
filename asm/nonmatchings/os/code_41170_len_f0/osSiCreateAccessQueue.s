.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osSiCreateAccessQueue
/* 41170 80065D70 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 41174 80065D74 24020001 */  addiu     $v0, $zero, 1
/* 41178 80065D78 AFB00010 */  sw        $s0, 0x10($sp)
/* 4117C 80065D7C 3C10800E */  lui       $s0, %hi(D_800DACA8)
/* 41180 80065D80 2610ACA8 */  addiu     $s0, $s0, %lo(D_800DACA8)
/* 41184 80065D84 02002021 */  addu      $a0, $s0, $zero
/* 41188 80065D88 3C05800B */  lui       $a1, %hi(D_800AF900)
/* 4118C 80065D8C 24A5F900 */  addiu     $a1, $a1, %lo(D_800AF900)
/* 41190 80065D90 AFBF0014 */  sw        $ra, 0x14($sp)
/* 41194 80065D94 3C018009 */  lui       $at, %hi(D_80094640)
/* 41198 80065D98 AC224640 */  sw        $v0, %lo(D_80094640)($at)
/* 4119C 80065D9C 0C019560 */  jal       osCreateMesgQueue
/* 411A0 80065DA0 24060001 */   addiu    $a2, $zero, 1
/* 411A4 80065DA4 02002021 */  addu      $a0, $s0, $zero
/* 411A8 80065DA8 00002821 */  addu      $a1, $zero, $zero
/* 411AC 80065DAC 0C019608 */  jal       osSendMesg
/* 411B0 80065DB0 00003021 */   addu     $a2, $zero, $zero
/* 411B4 80065DB4 8FBF0014 */  lw        $ra, 0x14($sp)
/* 411B8 80065DB8 8FB00010 */  lw        $s0, 0x10($sp)
/* 411BC 80065DBC 03E00008 */  jr        $ra
/* 411C0 80065DC0 27BD0018 */   addiu    $sp, $sp, 0x18
