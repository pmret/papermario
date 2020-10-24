.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240824_87A404
/* 87A404 80240824 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 87A408 80240828 AFBF0018 */  sw        $ra, 0x18($sp)
/* 87A40C 8024082C 8C82000C */  lw        $v0, 0xc($a0)
/* 87A410 80240830 0C0B1EAF */  jal       get_variable
/* 87A414 80240834 8C450000 */   lw       $a1, ($v0)
/* 87A418 80240838 0C04417A */  jal       get_entity_by_index
/* 87A41C 8024083C 0040202D */   daddu    $a0, $v0, $zero
/* 87A420 80240840 3C013F80 */  lui       $at, 0x3f80
/* 87A424 80240844 44810000 */  mtc1      $at, $f0
/* 87A428 80240848 C442004C */  lwc1      $f2, 0x4c($v0)
/* 87A42C 8024084C E7A00010 */  swc1      $f0, 0x10($sp)
/* 87A430 80240850 3C014148 */  lui       $at, 0x4148
/* 87A434 80240854 44810000 */  mtc1      $at, $f0
/* 87A438 80240858 2403004B */  addiu     $v1, $zero, 0x4b
/* 87A43C 8024085C AFA30014 */  sw        $v1, 0x14($sp)
/* 87A440 80240860 46001080 */  add.s     $f2, $f2, $f0
/* 87A444 80240864 8C450048 */  lw        $a1, 0x48($v0)
/* 87A448 80240868 8C470050 */  lw        $a3, 0x50($v0)
/* 87A44C 8024086C 44061000 */  mfc1      $a2, $f2
/* 87A450 80240870 0C01C2EC */  jal       func_80070BB0
/* 87A454 80240874 24040004 */   addiu    $a0, $zero, 4
/* 87A458 80240878 8FBF0018 */  lw        $ra, 0x18($sp)
/* 87A45C 8024087C 24020002 */  addiu     $v0, $zero, 2
/* 87A460 80240880 03E00008 */  jr        $ra
/* 87A464 80240884 27BD0020 */   addiu    $sp, $sp, 0x20
