.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80245018_805898
/* 805898 80245018 3C018026 */  lui       $at, 0x8026
/* 80589C 8024501C AC202F68 */  sw        $zero, 0x2f68($at)
/* 8058A0 80245020 03E00008 */  jr        $ra
/* 8058A4 80245024 24020002 */   addiu    $v0, $zero, 2
