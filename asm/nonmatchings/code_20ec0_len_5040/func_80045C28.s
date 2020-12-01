.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80045C28
/* 21028 80045C28 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 2102C 80045C2C AFB10014 */  sw        $s1, 0x14($sp)
/* 21030 80045C30 0000882D */  daddu     $s1, $zero, $zero
/* 21034 80045C34 AFB00010 */  sw        $s0, 0x10($sp)
/* 21038 80045C38 3C10800A */  lui       $s0, %hi(D_800A0BC0)
/* 2103C 80045C3C 26100BC0 */  addiu     $s0, $s0, %lo(D_800A0BC0)
/* 21040 80045C40 AFBF0018 */  sw        $ra, 0x18($sp)
.L80045C44:
/* 21044 80045C44 86020010 */  lh        $v0, 0x10($s0)
/* 21048 80045C48 50400007 */  beql      $v0, $zero, .L80045C68
/* 2104C 80045C4C 26310001 */   addiu    $s1, $s1, 1
/* 21050 80045C50 8E02000C */  lw        $v0, 0xc($s0)
/* 21054 80045C54 50400004 */  beql      $v0, $zero, .L80045C68
/* 21058 80045C58 26310001 */   addiu    $s1, $s1, 1
/* 2105C 80045C5C 0040F809 */  jalr      $v0
/* 21060 80045C60 0200202D */   daddu    $a0, $s0, $zero
/* 21064 80045C64 26310001 */  addiu     $s1, $s1, 1
.L80045C68:
/* 21068 80045C68 2A220020 */  slti      $v0, $s1, 0x20
/* 2106C 80045C6C 1440FFF5 */  bnez      $v0, .L80045C44
/* 21070 80045C70 2610001C */   addiu    $s0, $s0, 0x1c
/* 21074 80045C74 8FBF0018 */  lw        $ra, 0x18($sp)
/* 21078 80045C78 8FB10014 */  lw        $s1, 0x14($sp)
/* 2107C 80045C7C 8FB00010 */  lw        $s0, 0x10($sp)
/* 21080 80045C80 03E00008 */  jr        $ra
/* 21084 80045C84 27BD0020 */   addiu    $sp, $sp, 0x20
