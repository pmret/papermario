.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024294C
/* 8031CC 8024294C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8031D0 80242950 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8031D4 80242954 8C82000C */  lw        $v0, 0xc($a0)
/* 8031D8 80242958 0C0B1EAF */  jal       get_variable
/* 8031DC 8024295C 8C450000 */   lw       $a1, ($v0)
/* 8031E0 80242960 3C038026 */  lui       $v1, 0x8026
/* 8031E4 80242964 8C632A60 */  lw        $v1, 0x2a60($v1)
/* 8031E8 80242968 8C63000C */  lw        $v1, 0xc($v1)
/* 8031EC 8024296C AC620034 */  sw        $v0, 0x34($v1)
/* 8031F0 80242970 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8031F4 80242974 24020002 */  addiu     $v0, $zero, 2
/* 8031F8 80242978 03E00008 */  jr        $ra
/* 8031FC 8024297C 27BD0018 */   addiu    $sp, $sp, 0x18
