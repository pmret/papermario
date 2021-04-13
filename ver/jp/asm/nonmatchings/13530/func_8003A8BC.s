.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003A8BC
/* 15CBC 8003A8BC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 15CC0 8003A8C0 AFB00010 */  sw        $s0, 0x10($sp)
/* 15CC4 8003A8C4 0080802D */  daddu     $s0, $a0, $zero
/* 15CC8 8003A8C8 AFBF0014 */  sw        $ra, 0x14($sp)
/* 15CCC 8003A8CC 8E020000 */  lw        $v0, ($s0)
/* 15CD0 8003A8D0 30420010 */  andi      $v0, $v0, 0x10
/* 15CD4 8003A8D4 1040000D */  beqz      $v0, .L8003A90C
/* 15CD8 8003A8D8 00000000 */   nop
/* 15CDC 8003A8DC 0C045605 */  jal       func_80115814
/* 15CE0 8003A8E0 8E040078 */   lw       $a0, 0x78($s0)
/* 15CE4 8003A8E4 3C04FFFE */  lui       $a0, 0xfffe
/* 15CE8 8003A8E8 8C430000 */  lw        $v1, ($v0)
/* 15CEC 8003A8EC 3484FFFF */  ori       $a0, $a0, 0xffff
/* 15CF0 8003A8F0 34630001 */  ori       $v1, $v1, 1
/* 15CF4 8003A8F4 AC430000 */  sw        $v1, ($v0)
/* 15CF8 8003A8F8 8E020000 */  lw        $v0, ($s0)
/* 15CFC 8003A8FC 2403FFEF */  addiu     $v1, $zero, -0x11
/* 15D00 8003A900 00431024 */  and       $v0, $v0, $v1
/* 15D04 8003A904 00441024 */  and       $v0, $v0, $a0
/* 15D08 8003A908 AE020000 */  sw        $v0, ($s0)
.L8003A90C:
/* 15D0C 8003A90C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 15D10 8003A910 8FB00010 */  lw        $s0, 0x10($sp)
/* 15D14 8003A914 03E00008 */  jr        $ra
/* 15D18 8003A918 27BD0018 */   addiu    $sp, $sp, 0x18
