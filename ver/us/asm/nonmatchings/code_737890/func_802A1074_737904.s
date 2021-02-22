.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1074_737904
/* 737904 802A1074 3C02800E */  lui       $v0, %hi(gBattleStatus+0xD8)
/* 737908 802A1078 8C42C148 */  lw        $v0, %lo(gBattleStatus+0xD8)($v0)
/* 73790C 802A107C 3C0141A0 */  lui       $at, 0x41a0
/* 737910 802A1080 44810000 */  mtc1      $at, $f0
/* 737914 802A1084 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 737918 802A1088 AFBF0018 */  sw        $ra, 0x18($sp)
/* 73791C 802A108C C4420144 */  lwc1      $f2, 0x144($v0)
/* 737920 802A1090 C4440148 */  lwc1      $f4, 0x148($v0)
/* 737924 802A1094 46001080 */  add.s     $f2, $f2, $f0
/* 737928 802A1098 3C014170 */  lui       $at, 0x4170
/* 73792C 802A109C 44810000 */  mtc1      $at, $f0
/* 737930 802A10A0 C446014C */  lwc1      $f6, 0x14c($v0)
/* 737934 802A10A4 46002100 */  add.s     $f4, $f4, $f0
/* 737938 802A10A8 3C0140A0 */  lui       $at, 0x40a0
/* 73793C 802A10AC 44810000 */  mtc1      $at, $f0
/* 737940 802A10B0 0000202D */  daddu     $a0, $zero, $zero
/* 737944 802A10B4 46003180 */  add.s     $f6, $f6, $f0
/* 737948 802A10B8 44051000 */  mfc1      $a1, $f2
/* 73794C 802A10BC 3C013F80 */  lui       $at, 0x3f80
/* 737950 802A10C0 44811000 */  mtc1      $at, $f2
/* 737954 802A10C4 44062000 */  mfc1      $a2, $f4
/* 737958 802A10C8 44073000 */  mfc1      $a3, $f6
/* 73795C 802A10CC 24020014 */  addiu     $v0, $zero, 0x14
/* 737960 802A10D0 AFA20014 */  sw        $v0, 0x14($sp)
/* 737964 802A10D4 0C01C274 */  jal       func_800709D0
/* 737968 802A10D8 E7A20010 */   swc1     $f2, 0x10($sp)
/* 73796C 802A10DC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 737970 802A10E0 24020002 */  addiu     $v0, $zero, 2
/* 737974 802A10E4 03E00008 */  jr        $ra
/* 737978 802A10E8 27BD0020 */   addiu    $sp, $sp, 0x20
