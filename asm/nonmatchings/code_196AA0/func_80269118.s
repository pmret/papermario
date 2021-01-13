.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80269118
/* 1979F8 80269118 3C058011 */  lui       $a1, %hi(gPlayerData)
/* 1979FC 8026911C 24A5F290 */  addiu     $a1, $a1, %lo(gPlayerData)
/* 197A00 80269120 3C04802A */  lui       $a0, %hi(D_8029FBE0)
/* 197A04 80269124 2484FBE0 */  addiu     $a0, $a0, %lo(D_8029FBE0)
/* 197A08 80269128 8082005E */  lb        $v0, 0x5e($a0)
/* 197A0C 8026912C 1440000A */  bnez      $v0, .L80269158
/* 197A10 80269130 0080302D */   daddu    $a2, $a0, $zero
/* 197A14 80269134 94A30294 */  lhu       $v1, 0x294($a1)
/* 197A18 80269138 2C62270F */  sltiu     $v0, $v1, 0x270f
/* 197A1C 8026913C 10400005 */  beqz      $v0, .L80269154
/* 197A20 80269140 24020001 */   addiu    $v0, $zero, 1
/* 197A24 80269144 24620001 */  addiu     $v0, $v1, 1
/* 197A28 80269148 A4A20294 */  sh        $v0, 0x294($a1)
/* 197A2C 8026914C 03E00008 */  jr        $ra
/* 197A30 80269150 A480006E */   sh       $zero, 0x6e($a0)
.L80269154:
/* 197A34 80269154 A4C2006E */  sh        $v0, 0x6e($a2)
.L80269158:
/* 197A38 80269158 03E00008 */  jr        $ra
/* 197A3C 8026915C 00000000 */   nop
