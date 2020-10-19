.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240134
/* CB9334 80240134 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CB9338 80240138 AFB00010 */  sw        $s0, 0x10($sp)
/* CB933C 8024013C 0080802D */  daddu     $s0, $a0, $zero
/* CB9340 80240140 AFBF0018 */  sw        $ra, 0x18($sp)
/* CB9344 80240144 AFB10014 */  sw        $s1, 0x14($sp)
/* CB9348 80240148 8E02000C */  lw        $v0, 0xc($s0)
/* CB934C 8024014C 8C510000 */  lw        $s1, ($v0)
/* CB9350 80240150 0C0B1EAF */  jal       get_variable
/* CB9354 80240154 0220282D */   daddu    $a1, $s1, $zero
/* CB9358 80240158 3C03FFF0 */  lui       $v1, 0xfff0
/* CB935C 8024015C 3463FFFF */  ori       $v1, $v1, 0xffff
/* CB9360 80240160 0200202D */  daddu     $a0, $s0, $zero
/* CB9364 80240164 00431024 */  and       $v0, $v0, $v1
/* CB9368 80240168 00021140 */  sll       $v0, $v0, 5
/* CB936C 8024016C 3C068008 */  lui       $a2, %hi(gItemTable)
/* CB9370 80240170 00C23021 */  addu      $a2, $a2, $v0
/* CB9374 80240174 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* CB9378 80240178 0C0B2026 */  jal       set_variable
/* CB937C 8024017C 0220282D */   daddu    $a1, $s1, $zero
/* CB9380 80240180 8FBF0018 */  lw        $ra, 0x18($sp)
/* CB9384 80240184 8FB10014 */  lw        $s1, 0x14($sp)
/* CB9388 80240188 8FB00010 */  lw        $s0, 0x10($sp)
/* CB938C 8024018C 24020002 */  addiu     $v0, $zero, 2
/* CB9390 80240190 03E00008 */  jr        $ra
/* CB9394 80240194 27BD0020 */   addiu    $sp, $sp, 0x20
