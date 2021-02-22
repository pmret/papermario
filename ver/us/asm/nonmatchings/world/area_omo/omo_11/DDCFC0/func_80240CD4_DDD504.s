.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240CD4_DDD504
/* DDD504 80240CD4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DDD508 80240CD8 AFBF0018 */  sw        $ra, 0x18($sp)
/* DDD50C 80240CDC 8C82000C */  lw        $v0, 0xc($a0)
/* DDD510 80240CE0 0C0B1EAF */  jal       get_variable
/* DDD514 80240CE4 8C450000 */   lw       $a1, ($v0)
/* DDD518 80240CE8 0C04417A */  jal       get_entity_by_index
/* DDD51C 80240CEC 0040202D */   daddu    $a0, $v0, $zero
/* DDD520 80240CF0 3C013F80 */  lui       $at, 0x3f80
/* DDD524 80240CF4 44810000 */  mtc1      $at, $f0
/* DDD528 80240CF8 C442004C */  lwc1      $f2, 0x4c($v0)
/* DDD52C 80240CFC E7A00010 */  swc1      $f0, 0x10($sp)
/* DDD530 80240D00 3C014148 */  lui       $at, 0x4148
/* DDD534 80240D04 44810000 */  mtc1      $at, $f0
/* DDD538 80240D08 2403004B */  addiu     $v1, $zero, 0x4b
/* DDD53C 80240D0C AFA30014 */  sw        $v1, 0x14($sp)
/* DDD540 80240D10 46001080 */  add.s     $f2, $f2, $f0
/* DDD544 80240D14 8C450048 */  lw        $a1, 0x48($v0)
/* DDD548 80240D18 8C470050 */  lw        $a3, 0x50($v0)
/* DDD54C 80240D1C 44061000 */  mfc1      $a2, $f2
/* DDD550 80240D20 0C01C2EC */  jal       func_80070BB0
/* DDD554 80240D24 24040004 */   addiu    $a0, $zero, 4
/* DDD558 80240D28 8FBF0018 */  lw        $ra, 0x18($sp)
/* DDD55C 80240D2C 24020002 */  addiu     $v0, $zero, 2
/* DDD560 80240D30 03E00008 */  jr        $ra
/* DDD564 80240D34 27BD0020 */   addiu    $sp, $sp, 0x20
