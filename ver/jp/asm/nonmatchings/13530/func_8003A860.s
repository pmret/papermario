.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003A860
/* 15C60 8003A860 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 15C64 8003A864 AFB00010 */  sw        $s0, 0x10($sp)
/* 15C68 8003A868 0080802D */  daddu     $s0, $a0, $zero
/* 15C6C 8003A86C AFBF0014 */  sw        $ra, 0x14($sp)
/* 15C70 8003A870 8E020000 */  lw        $v0, ($s0)
/* 15C74 8003A874 30420010 */  andi      $v0, $v0, 0x10
/* 15C78 8003A878 1440000C */  bnez      $v0, .L8003A8AC
/* 15C7C 8003A87C 00000000 */   nop
/* 15C80 8003A880 0C045605 */  jal       func_80115814
/* 15C84 8003A884 8E040078 */   lw       $a0, 0x78($s0)
/* 15C88 8003A888 3C050001 */  lui       $a1, 1
/* 15C8C 8003A88C 8C430000 */  lw        $v1, ($v0)
/* 15C90 8003A890 2404FFFE */  addiu     $a0, $zero, -2
/* 15C94 8003A894 00641824 */  and       $v1, $v1, $a0
/* 15C98 8003A898 AC430000 */  sw        $v1, ($v0)
/* 15C9C 8003A89C 8E020000 */  lw        $v0, ($s0)
/* 15CA0 8003A8A0 34A50010 */  ori       $a1, $a1, 0x10
/* 15CA4 8003A8A4 00451025 */  or        $v0, $v0, $a1
/* 15CA8 8003A8A8 AE020000 */  sw        $v0, ($s0)
.L8003A8AC:
/* 15CAC 8003A8AC 8FBF0014 */  lw        $ra, 0x14($sp)
/* 15CB0 8003A8B0 8FB00010 */  lw        $s0, 0x10($sp)
/* 15CB4 8003A8B4 03E00008 */  jr        $ra
/* 15CB8 8003A8B8 27BD0018 */   addiu    $sp, $sp, 0x18
