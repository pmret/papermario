.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242914_C38E44
/* C38E44 80242914 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C38E48 80242918 AFBF0018 */  sw        $ra, 0x18($sp)
/* C38E4C 8024291C 8C82000C */  lw        $v0, 0xc($a0)
/* C38E50 80242920 0C0B1EAF */  jal       get_variable
/* C38E54 80242924 8C450000 */   lw       $a1, ($v0)
/* C38E58 80242928 0C04417A */  jal       get_entity_by_index
/* C38E5C 8024292C 0040202D */   daddu    $a0, $v0, $zero
/* C38E60 80242930 3C013F80 */  lui       $at, 0x3f80
/* C38E64 80242934 44810000 */  mtc1      $at, $f0
/* C38E68 80242938 C442004C */  lwc1      $f2, 0x4c($v0)
/* C38E6C 8024293C E7A00010 */  swc1      $f0, 0x10($sp)
/* C38E70 80242940 3C014148 */  lui       $at, 0x4148
/* C38E74 80242944 44810000 */  mtc1      $at, $f0
/* C38E78 80242948 2403004B */  addiu     $v1, $zero, 0x4b
/* C38E7C 8024294C AFA30014 */  sw        $v1, 0x14($sp)
/* C38E80 80242950 46001080 */  add.s     $f2, $f2, $f0
/* C38E84 80242954 8C450048 */  lw        $a1, 0x48($v0)
/* C38E88 80242958 8C470050 */  lw        $a3, 0x50($v0)
/* C38E8C 8024295C 44061000 */  mfc1      $a2, $f2
/* C38E90 80242960 0C01C2EC */  jal       func_80070BB0
/* C38E94 80242964 24040004 */   addiu    $a0, $zero, 4
/* C38E98 80242968 8FBF0018 */  lw        $ra, 0x18($sp)
/* C38E9C 8024296C 24020002 */  addiu     $v0, $zero, 2
/* C38EA0 80242970 03E00008 */  jr        $ra
/* C38EA4 80242974 27BD0020 */   addiu    $sp, $sp, 0x20
