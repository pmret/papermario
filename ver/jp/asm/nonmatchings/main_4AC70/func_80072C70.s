.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80072C70
/* 4E070 80072C70 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4E074 80072C74 3C01800E */  lui       $at, %hi(D_800DC4C8)
/* 4E078 80072C78 AC24C4C8 */  sw        $a0, %lo(D_800DC4C8)($at)
/* 4E07C 80072C7C AFBF0010 */  sw        $ra, 0x10($sp)
/* 4E080 80072C80 0C00CC60 */  jal       func_80033180
/* 4E084 80072C84 24040008 */   addiu    $a0, $zero, 8
/* 4E088 80072C88 8FBF0010 */  lw        $ra, 0x10($sp)
/* 4E08C 80072C8C 3C01800E */  lui       $at, %hi(D_800DC048)
/* 4E090 80072C90 AC20C048 */  sw        $zero, %lo(D_800DC048)($at)
/* 4E094 80072C94 3C01800E */  lui       $at, %hi(D_800DC4B0)
/* 4E098 80072C98 AC20C4B0 */  sw        $zero, %lo(D_800DC4B0)($at)
/* 4E09C 80072C9C 3C01800E */  lui       $at, %hi(D_800DC4BC)
/* 4E0A0 80072CA0 AC20C4BC */  sw        $zero, %lo(D_800DC4BC)($at)
/* 4E0A4 80072CA4 03E00008 */  jr        $ra
/* 4E0A8 80072CA8 27BD0018 */   addiu    $sp, $sp, 0x18
