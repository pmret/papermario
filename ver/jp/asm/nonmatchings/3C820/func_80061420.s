.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80061420
/* 3C820 80061420 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3C824 80061424 24020001 */  addiu     $v0, $zero, 1
/* 3C828 80061428 AFB00010 */  sw        $s0, 0x10($sp)
/* 3C82C 8006142C 3C10800B */  lui       $s0, %hi(D_800B4360)
/* 3C830 80061430 26104360 */  addiu     $s0, $s0, %lo(D_800B4360)
/* 3C834 80061434 02002021 */  addu      $a0, $s0, $zero
/* 3C838 80061438 3C05800B */  lui       $a1, %hi(D_800AF890)
/* 3C83C 8006143C 24A5F890 */  addiu     $a1, $a1, %lo(D_800AF890)
/* 3C840 80061440 AFBF0014 */  sw        $ra, 0x14($sp)
/* 3C844 80061444 3C018009 */  lui       $at, %hi(D_80093D70)
/* 3C848 80061448 AC223D70 */  sw        $v0, %lo(D_80093D70)($at)
/* 3C84C 8006144C 0C019554 */  jal       func_80065550
/* 3C850 80061450 24060001 */   addiu    $a2, $zero, 1
/* 3C854 80061454 02002021 */  addu      $a0, $s0, $zero
/* 3C858 80061458 00002821 */  addu      $a1, $zero, $zero
/* 3C85C 8006145C 0C0195FC */  jal       func_800657F0
/* 3C860 80061460 00003021 */   addu     $a2, $zero, $zero
/* 3C864 80061464 8FBF0014 */  lw        $ra, 0x14($sp)
/* 3C868 80061468 8FB00010 */  lw        $s0, 0x10($sp)
/* 3C86C 8006146C 03E00008 */  jr        $ra
/* 3C870 80061470 27BD0018 */   addiu    $sp, $sp, 0x18
