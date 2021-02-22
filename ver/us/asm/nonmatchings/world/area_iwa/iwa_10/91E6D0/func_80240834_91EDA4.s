.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240834_91EDA4
/* 91EDA4 80240834 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 91EDA8 80240838 AFBF0018 */  sw        $ra, 0x18($sp)
/* 91EDAC 8024083C 8C82000C */  lw        $v0, 0xc($a0)
/* 91EDB0 80240840 0C0B1EAF */  jal       get_variable
/* 91EDB4 80240844 8C450000 */   lw       $a1, ($v0)
/* 91EDB8 80240848 0C04417A */  jal       get_entity_by_index
/* 91EDBC 8024084C 0040202D */   daddu    $a0, $v0, $zero
/* 91EDC0 80240850 3C013F80 */  lui       $at, 0x3f80
/* 91EDC4 80240854 44810000 */  mtc1      $at, $f0
/* 91EDC8 80240858 C442004C */  lwc1      $f2, 0x4c($v0)
/* 91EDCC 8024085C E7A00010 */  swc1      $f0, 0x10($sp)
/* 91EDD0 80240860 3C014148 */  lui       $at, 0x4148
/* 91EDD4 80240864 44810000 */  mtc1      $at, $f0
/* 91EDD8 80240868 2403004B */  addiu     $v1, $zero, 0x4b
/* 91EDDC 8024086C AFA30014 */  sw        $v1, 0x14($sp)
/* 91EDE0 80240870 46001080 */  add.s     $f2, $f2, $f0
/* 91EDE4 80240874 8C450048 */  lw        $a1, 0x48($v0)
/* 91EDE8 80240878 8C470050 */  lw        $a3, 0x50($v0)
/* 91EDEC 8024087C 44061000 */  mfc1      $a2, $f2
/* 91EDF0 80240880 0C01C2EC */  jal       func_80070BB0
/* 91EDF4 80240884 24040004 */   addiu    $a0, $zero, 4
/* 91EDF8 80240888 8FBF0018 */  lw        $ra, 0x18($sp)
/* 91EDFC 8024088C 24020002 */  addiu     $v0, $zero, 2
/* 91EE00 80240890 03E00008 */  jr        $ra
/* 91EE04 80240894 27BD0020 */   addiu    $sp, $sp, 0x20
