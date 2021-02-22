.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403D8_9462A8
/* 9462A8 802403D8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9462AC 802403DC AFBF0010 */  sw        $ra, 0x10($sp)
/* 9462B0 802403E0 8C82000C */  lw        $v0, 0xc($a0)
/* 9462B4 802403E4 0C0B1EAF */  jal       get_variable
/* 9462B8 802403E8 8C450000 */   lw       $a1, ($v0)
/* 9462BC 802403EC 3C018024 */  lui       $at, %hi(D_80240E04_946CD4)
/* 9462C0 802403F0 AC220E04 */  sw        $v0, %lo(D_80240E04_946CD4)($at)
/* 9462C4 802403F4 24020002 */  addiu     $v0, $zero, 2
/* 9462C8 802403F8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9462CC 802403FC 24030001 */  addiu     $v1, $zero, 1
/* 9462D0 80240400 3C018024 */  lui       $at, %hi(D_80240E00_946CD0)
/* 9462D4 80240404 AC230E00 */  sw        $v1, %lo(D_80240E00_946CD0)($at)
/* 9462D8 80240408 03E00008 */  jr        $ra
/* 9462DC 8024040C 27BD0018 */   addiu    $sp, $sp, 0x18
