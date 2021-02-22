.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80045888
/* 20C88 80045888 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 20C8C 8004588C AFB10014 */  sw        $s1, 0x14($sp)
/* 20C90 80045890 0000882D */  daddu     $s1, $zero, $zero
/* 20C94 80045894 AFB00010 */  sw        $s0, 0x10($sp)
/* 20C98 80045898 3C10800A */  lui       $s0, %hi(D_8009E9D0)
/* 20C9C 8004589C 2610E9D0 */  addiu     $s0, $s0, %lo(D_8009E9D0)
/* 20CA0 800458A0 AFBF0018 */  sw        $ra, 0x18($sp)
.L800458A4:
/* 20CA4 800458A4 86020010 */  lh        $v0, 0x10($s0)
/* 20CA8 800458A8 50400007 */  beql      $v0, $zero, .L800458C8
/* 20CAC 800458AC 26310001 */   addiu    $s1, $s1, 1
/* 20CB0 800458B0 8E020008 */  lw        $v0, 8($s0)
/* 20CB4 800458B4 50400004 */  beql      $v0, $zero, .L800458C8
/* 20CB8 800458B8 26310001 */   addiu    $s1, $s1, 1
/* 20CBC 800458BC 0040F809 */  jalr      $v0
/* 20CC0 800458C0 0200202D */   daddu    $a0, $s0, $zero
/* 20CC4 800458C4 26310001 */  addiu     $s1, $s1, 1
.L800458C8:
/* 20CC8 800458C8 2A220020 */  slti      $v0, $s1, 0x20
/* 20CCC 800458CC 1440FFF5 */  bnez      $v0, .L800458A4
/* 20CD0 800458D0 2610001C */   addiu    $s0, $s0, 0x1c
/* 20CD4 800458D4 8FBF0018 */  lw        $ra, 0x18($sp)
/* 20CD8 800458D8 8FB10014 */  lw        $s1, 0x14($sp)
/* 20CDC 800458DC 8FB00010 */  lw        $s0, 0x10($sp)
/* 20CE0 800458E0 03E00008 */  jr        $ra
/* 20CE4 800458E4 27BD0020 */   addiu    $sp, $sp, 0x20
