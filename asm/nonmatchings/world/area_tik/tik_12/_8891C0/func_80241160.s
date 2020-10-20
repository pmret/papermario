.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241160
/* 889D30 80241160 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 889D34 80241164 AFBF0018 */  sw        $ra, 0x18($sp)
/* 889D38 80241168 8C82000C */  lw        $v0, 0xc($a0)
/* 889D3C 8024116C 0C0B1EAF */  jal       get_variable
/* 889D40 80241170 8C450000 */   lw       $a1, ($v0)
/* 889D44 80241174 0C04417A */  jal       get_entity_by_index
/* 889D48 80241178 0040202D */   daddu    $a0, $v0, $zero
/* 889D4C 8024117C 3C013F80 */  lui       $at, 0x3f80
/* 889D50 80241180 44810000 */  mtc1      $at, $f0
/* 889D54 80241184 C442004C */  lwc1      $f2, 0x4c($v0)
/* 889D58 80241188 E7A00010 */  swc1      $f0, 0x10($sp)
/* 889D5C 8024118C 3C014148 */  lui       $at, 0x4148
/* 889D60 80241190 44810000 */  mtc1      $at, $f0
/* 889D64 80241194 2403004B */  addiu     $v1, $zero, 0x4b
/* 889D68 80241198 AFA30014 */  sw        $v1, 0x14($sp)
/* 889D6C 8024119C 46001080 */  add.s     $f2, $f2, $f0
/* 889D70 802411A0 8C450048 */  lw        $a1, 0x48($v0)
/* 889D74 802411A4 8C470050 */  lw        $a3, 0x50($v0)
/* 889D78 802411A8 44061000 */  mfc1      $a2, $f2
/* 889D7C 802411AC 0C01C2EC */  jal       func_80070BB0
/* 889D80 802411B0 24040004 */   addiu    $a0, $zero, 4
/* 889D84 802411B4 8FBF0018 */  lw        $ra, 0x18($sp)
/* 889D88 802411B8 24020002 */  addiu     $v0, $zero, 2
/* 889D8C 802411BC 03E00008 */  jr        $ra
/* 889D90 802411C0 27BD0020 */   addiu    $sp, $sp, 0x20
