.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80245C80_806500
/* 806500 80245C80 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 806504 80245C84 AFB10014 */  sw        $s1, 0x14($sp)
/* 806508 80245C88 0080882D */  daddu     $s1, $a0, $zero
/* 80650C 80245C8C AFBF0018 */  sw        $ra, 0x18($sp)
/* 806510 80245C90 AFB00010 */  sw        $s0, 0x10($sp)
/* 806514 80245C94 8E300148 */  lw        $s0, 0x148($s1)
/* 806518 80245C98 0C00EABB */  jal       get_npc_unsafe
/* 80651C 80245C9C 86040008 */   lh       $a0, 8($s0)
/* 806520 80245CA0 8E0300CC */  lw        $v1, 0xcc($s0)
/* 806524 80245CA4 3C014120 */  lui       $at, 0x4120
/* 806528 80245CA8 44812000 */  mtc1      $at, $f4
/* 80652C 80245CAC 3C014000 */  lui       $at, 0x4000
/* 806530 80245CB0 44810000 */  mtc1      $at, $f0
/* 806534 80245CB4 C442003C */  lwc1      $f2, 0x3c($v0)
/* 806538 80245CB8 8C640010 */  lw        $a0, 0x10($v1)
/* 80653C 80245CBC 8C430000 */  lw        $v1, ($v0)
/* 806540 80245CC0 E444001C */  swc1      $f4, 0x1c($v0)
/* 806544 80245CC4 E4400014 */  swc1      $f0, 0x14($v0)
/* 806548 80245CC8 E4420064 */  swc1      $f2, 0x64($v0)
/* 80654C 80245CCC 34630800 */  ori       $v1, $v1, 0x800
/* 806550 80245CD0 AC430000 */  sw        $v1, ($v0)
/* 806554 80245CD4 AC440028 */  sw        $a0, 0x28($v0)
/* 806558 80245CD8 2402000B */  addiu     $v0, $zero, 0xb
/* 80655C 80245CDC AE220070 */  sw        $v0, 0x70($s1)
/* 806560 80245CE0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 806564 80245CE4 8FB10014 */  lw        $s1, 0x14($sp)
/* 806568 80245CE8 8FB00010 */  lw        $s0, 0x10($sp)
/* 80656C 80245CEC 03E00008 */  jr        $ra
/* 806570 80245CF0 27BD0020 */   addiu    $sp, $sp, 0x20
