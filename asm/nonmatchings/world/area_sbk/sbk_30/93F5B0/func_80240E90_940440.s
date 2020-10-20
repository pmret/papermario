.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E90_940440
/* 940440 80240E90 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 940444 80240E94 AFB00010 */  sw        $s0, 0x10($sp)
/* 940448 80240E98 0080802D */  daddu     $s0, $a0, $zero
/* 94044C 80240E9C AFBF0018 */  sw        $ra, 0x18($sp)
/* 940450 80240EA0 AFB10014 */  sw        $s1, 0x14($sp)
/* 940454 80240EA4 8E02000C */  lw        $v0, 0xc($s0)
/* 940458 80240EA8 8C510000 */  lw        $s1, ($v0)
/* 94045C 80240EAC 0C0B1EAF */  jal       get_variable
/* 940460 80240EB0 0220282D */   daddu    $a1, $s1, $zero
/* 940464 80240EB4 3C03FFF0 */  lui       $v1, 0xfff0
/* 940468 80240EB8 3463FFFF */  ori       $v1, $v1, 0xffff
/* 94046C 80240EBC 0200202D */  daddu     $a0, $s0, $zero
/* 940470 80240EC0 00431024 */  and       $v0, $v0, $v1
/* 940474 80240EC4 00021140 */  sll       $v0, $v0, 5
/* 940478 80240EC8 3C068008 */  lui       $a2, %hi(gItemTable)
/* 94047C 80240ECC 00C23021 */  addu      $a2, $a2, $v0
/* 940480 80240ED0 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* 940484 80240ED4 0C0B2026 */  jal       set_variable
/* 940488 80240ED8 0220282D */   daddu    $a1, $s1, $zero
/* 94048C 80240EDC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 940490 80240EE0 8FB10014 */  lw        $s1, 0x14($sp)
/* 940494 80240EE4 8FB00010 */  lw        $s0, 0x10($sp)
/* 940498 80240EE8 24020002 */  addiu     $v0, $zero, 2
/* 94049C 80240EEC 03E00008 */  jr        $ra
/* 9404A0 80240EF0 27BD0020 */   addiu    $sp, $sp, 0x20
