.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80038138
/* 13538 80038138 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1353C 8003813C AFB00010 */  sw        $s0, 0x10($sp)
/* 13540 80038140 AFBF0014 */  sw        $ra, 0x14($sp)
/* 13544 80038144 0C019D20 */  jal       func_80067480
/* 13548 80038148 0080802D */   daddu    $s0, $a0, $zero
/* 1354C 8003814C 3C013F80 */  lui       $at, 0x3f80
/* 13550 80038150 44810000 */  mtc1      $at, $f0
/* 13554 80038154 3C01BF80 */  lui       $at, 0xbf80
/* 13558 80038158 44811000 */  mtc1      $at, $f2
/* 1355C 8003815C E6000000 */  swc1      $f0, ($s0)
/* 13560 80038160 E6020014 */  swc1      $f2, 0x14($s0)
/* 13564 80038164 E6000028 */  swc1      $f0, 0x28($s0)
/* 13568 80038168 E600003C */  swc1      $f0, 0x3c($s0)
/* 1356C 8003816C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 13570 80038170 8FB00010 */  lw        $s0, 0x10($sp)
/* 13574 80038174 03E00008 */  jr        $ra
/* 13578 80038178 27BD0018 */   addiu    $sp, $sp, 0x18
