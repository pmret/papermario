.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osPiCreateAccessQueue
/* 3C850 80061450 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3C854 80061454 24020001 */  addiu     $v0, $zero, 1
/* 3C858 80061458 AFB00010 */  sw        $s0, 0x10($sp)
/* 3C85C 8006145C 3C10800B */  lui       $s0, 0x800b
/* 3C860 80061460 26104380 */  addiu     $s0, $s0, 0x4380
/* 3C864 80061464 02002021 */  addu      $a0, $s0, $zero
/* 3C868 80061468 3C05800B */  lui       $a1, 0x800b
/* 3C86C 8006146C 24A5F8B0 */  addiu     $a1, $a1, -0x750
/* 3C870 80061470 AFBF0014 */  sw        $ra, 0x14($sp)
/* 3C874 80061474 3C018009 */  lui       $at, 0x8009
/* 3C878 80061478 AC223D90 */  sw        $v0, 0x3d90($at)
/* 3C87C 8006147C 0C019560 */  jal       osCreateMesgQueue
/* 3C880 80061480 24060001 */   addiu    $a2, $zero, 1
/* 3C884 80061484 02002021 */  addu      $a0, $s0, $zero
/* 3C888 80061488 00002821 */  addu      $a1, $zero, $zero
/* 3C88C 8006148C 0C019608 */  jal       osSendMesg
/* 3C890 80061490 00003021 */   addu     $a2, $zero, $zero
/* 3C894 80061494 8FBF0014 */  lw        $ra, 0x14($sp)
/* 3C898 80061498 8FB00010 */  lw        $s0, 0x10($sp)
/* 3C89C 8006149C 03E00008 */  jr        $ra
/* 3C8A0 800614A0 27BD0018 */   addiu    $sp, $sp, 0x18
