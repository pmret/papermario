.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80072B10
/* 4DF10 80072B10 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 4DF14 80072B14 8C42417C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 4DF18 80072B18 A04000AA */  sb        $zero, 0xaa($v0)
/* 4DF1C 80072B1C 24020001 */  addiu     $v0, $zero, 1
/* 4DF20 80072B20 3C01800E */  lui       $at, %hi(D_800DC048)
/* 4DF24 80072B24 AC20C048 */  sw        $zero, %lo(D_800DC048)($at)
/* 4DF28 80072B28 3C01800E */  lui       $at, %hi(D_800DC4C0)
/* 4DF2C 80072B2C AC22C4C0 */  sw        $v0, %lo(D_800DC4C0)($at)
/* 4DF30 80072B30 3C01800E */  lui       $at, %hi(D_800DC4BC)
/* 4DF34 80072B34 AC20C4BC */  sw        $zero, %lo(D_800DC4BC)($at)
/* 4DF38 80072B38 3C01800E */  lui       $at, %hi(D_800DC4B0)
/* 4DF3C 80072B3C AC20C4B0 */  sw        $zero, %lo(D_800DC4B0)($at)
/* 4DF40 80072B40 3C01800E */  lui       $at, %hi(D_800DC4D0)
/* 4DF44 80072B44 AC20C4D0 */  sw        $zero, %lo(D_800DC4D0)($at)
/* 4DF48 80072B48 3C01800E */  lui       $at, %hi(D_800DC4B4)
/* 4DF4C 80072B4C AC20C4B4 */  sw        $zero, %lo(D_800DC4B4)($at)
/* 4DF50 80072B50 3C01800E */  lui       $at, %hi(D_800DC4DC)
/* 4DF54 80072B54 AC20C4DC */  sw        $zero, %lo(D_800DC4DC)($at)
/* 4DF58 80072B58 3C01800E */  lui       $at, %hi(D_800DC4D8)
/* 4DF5C 80072B5C AC20C4D8 */  sw        $zero, %lo(D_800DC4D8)($at)
/* 4DF60 80072B60 3C01800E */  lui       $at, %hi(D_800DC4C8)
/* 4DF64 80072B64 AC20C4C8 */  sw        $zero, %lo(D_800DC4C8)($at)
/* 4DF68 80072B68 3C01800E */  lui       $at, %hi(D_800DC044)
/* 4DF6C 80072B6C AC20C044 */  sw        $zero, %lo(D_800DC044)($at)
/* 4DF70 80072B70 3C01800E */  lui       $at, %hi(D_800DC040)
/* 4DF74 80072B74 AC20C040 */  sw        $zero, %lo(D_800DC040)($at)
/* 4DF78 80072B78 3C01800E */  lui       $at, %hi(D_800DC4CC)
/* 4DF7C 80072B7C AC20C4CC */  sw        $zero, %lo(D_800DC4CC)($at)
/* 4DF80 80072B80 3C01800E */  lui       $at, %hi(D_800DC4D4)
/* 4DF84 80072B84 AC20C4D4 */  sw        $zero, %lo(D_800DC4D4)($at)
/* 4DF88 80072B88 03E00008 */  jr        $ra
/* 4DF8C 80072B8C 00000000 */   nop
