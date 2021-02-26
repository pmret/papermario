.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80066450
/* 41850 80066450 3C028009 */  lui       $v0, %hi(D_80094650)
/* 41854 80066454 8C424650 */  lw        $v0, %lo(D_80094650)($v0)
/* 41858 80066458 00002021 */  addu      $a0, $zero, $zero
/* 4185C 8006645C 00002821 */  addu      $a1, $zero, $zero
/* 41860 80066460 3C01800A */  lui       $at, %hi(D_8009A5E8)
/* 41864 80066464 AC24A5E8 */  sw        $a0, %lo(D_8009A5E8)($at)
/* 41868 80066468 3C01800A */  lui       $at, %hi(D_8009A5EC)
/* 4186C 8006646C AC25A5EC */  sw        $a1, %lo(D_8009A5EC)($at)
/* 41870 80066470 3C01800A */  lui       $at, %hi(D_8009A5A8)
/* 41874 80066474 AC20A5A8 */  sw        $zero, %lo(D_8009A5A8)($at)
/* 41878 80066478 3C01800A */  lui       $at, %hi(D_8009A5C4)
/* 4187C 8006647C AC20A5C4 */  sw        $zero, %lo(D_8009A5C4)($at)
/* 41880 80066480 AC440010 */  sw        $a0, 0x10($v0)
/* 41884 80066484 AC450014 */  sw        $a1, 0x14($v0)
/* 41888 80066488 AC440008 */  sw        $a0, 8($v0)
/* 4188C 8006648C AC45000C */  sw        $a1, 0xc($v0)
/* 41890 80066490 AC420004 */  sw        $v0, 4($v0)
/* 41894 80066494 AC420000 */  sw        $v0, ($v0)
/* 41898 80066498 AC400018 */  sw        $zero, 0x18($v0)
/* 4189C 8006649C 03E00008 */  jr        $ra
/* 418A0 800664A0 AC40001C */   sw       $zero, 0x1c($v0)
