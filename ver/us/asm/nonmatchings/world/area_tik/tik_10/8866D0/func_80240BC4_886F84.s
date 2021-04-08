.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel tik_10_UnkFunc21
/* 886F84 80240BC4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 886F88 80240BC8 AFBF0018 */  sw        $ra, 0x18($sp)
/* 886F8C 80240BCC 8C82000C */  lw        $v0, 0xc($a0)
/* 886F90 80240BD0 0C0B1EAF */  jal       get_variable
/* 886F94 80240BD4 8C450000 */   lw       $a1, ($v0)
/* 886F98 80240BD8 0C04417A */  jal       get_entity_by_index
/* 886F9C 80240BDC 0040202D */   daddu    $a0, $v0, $zero
/* 886FA0 80240BE0 3C013F80 */  lui       $at, 0x3f80
/* 886FA4 80240BE4 44810000 */  mtc1      $at, $f0
/* 886FA8 80240BE8 C442004C */  lwc1      $f2, 0x4c($v0)
/* 886FAC 80240BEC E7A00010 */  swc1      $f0, 0x10($sp)
/* 886FB0 80240BF0 3C014148 */  lui       $at, 0x4148
/* 886FB4 80240BF4 44810000 */  mtc1      $at, $f0
/* 886FB8 80240BF8 2403004B */  addiu     $v1, $zero, 0x4b
/* 886FBC 80240BFC AFA30014 */  sw        $v1, 0x14($sp)
/* 886FC0 80240C00 46001080 */  add.s     $f2, $f2, $f0
/* 886FC4 80240C04 8C450048 */  lw        $a1, 0x48($v0)
/* 886FC8 80240C08 8C470050 */  lw        $a3, 0x50($v0)
/* 886FCC 80240C0C 44061000 */  mfc1      $a2, $f2
/* 886FD0 80240C10 0C01C2EC */  jal       func_80070BB0
/* 886FD4 80240C14 24040004 */   addiu    $a0, $zero, 4
/* 886FD8 80240C18 8FBF0018 */  lw        $ra, 0x18($sp)
/* 886FDC 80240C1C 24020002 */  addiu     $v0, $zero, 2
/* 886FE0 80240C20 03E00008 */  jr        $ra
/* 886FE4 80240C24 27BD0020 */   addiu    $sp, $sp, 0x20
