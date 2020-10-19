.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C2C_CEEE8C
/* CEEE8C 80240C2C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CEEE90 80240C30 AFB00010 */  sw        $s0, 0x10($sp)
/* CEEE94 80240C34 0080802D */  daddu     $s0, $a0, $zero
/* CEEE98 80240C38 AFBF0014 */  sw        $ra, 0x14($sp)
/* CEEE9C 80240C3C 8E02000C */  lw        $v0, 0xc($s0)
/* CEEEA0 80240C40 0C0B1EAF */  jal       get_variable
/* CEEEA4 80240C44 8C450000 */   lw       $a1, ($v0)
/* CEEEA8 80240C48 3C048008 */  lui       $a0, %hi(gItemTable)
/* CEEEAC 80240C4C 248478E0 */  addiu     $a0, $a0, %lo(gItemTable)
/* CEEEB0 80240C50 00021940 */  sll       $v1, $v0, 5
/* CEEEB4 80240C54 00642021 */  addu      $a0, $v1, $a0
/* CEEEB8 80240C58 240300BB */  addiu     $v1, $zero, 0xbb
/* CEEEBC 80240C5C 14430003 */  bne       $v0, $v1, .L80240C6C
/* CEEEC0 80240C60 24020002 */   addiu    $v0, $zero, 2
/* CEEEC4 80240C64 08090322 */  j         .L80240C88
/* CEEEC8 80240C68 AE0200A8 */   sw       $v0, 0xa8($s0)
.L80240C6C:
/* CEEECC 80240C6C 94820018 */  lhu       $v0, 0x18($a0)
/* CEEED0 80240C70 30420080 */  andi      $v0, $v0, 0x80
/* CEEED4 80240C74 10400003 */  beqz      $v0, .L80240C84
/* CEEED8 80240C78 24020001 */   addiu    $v0, $zero, 1
/* CEEEDC 80240C7C 08090322 */  j         .L80240C88
/* CEEEE0 80240C80 AE0200A8 */   sw       $v0, 0xa8($s0)
.L80240C84:
/* CEEEE4 80240C84 AE0000A8 */  sw        $zero, 0xa8($s0)
.L80240C88:
/* CEEEE8 80240C88 8FBF0014 */  lw        $ra, 0x14($sp)
/* CEEEEC 80240C8C 8FB00010 */  lw        $s0, 0x10($sp)
/* CEEEF0 80240C90 24020002 */  addiu     $v0, $zero, 2
/* CEEEF4 80240C94 03E00008 */  jr        $ra
/* CEEEF8 80240C98 27BD0018 */   addiu    $sp, $sp, 0x18
