.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80145108
/* DB808 80145108 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DB80C 8014510C 2402F7FF */  addiu     $v0, $zero, -0x801
/* DB810 80145110 00822024 */  and       $a0, $a0, $v0
/* DB814 80145114 3C028015 */  lui       $v0, %hi(D_80157960)
/* DB818 80145118 8C427960 */  lw        $v0, %lo(D_80157960)($v0)
/* DB81C 8014511C 00042080 */  sll       $a0, $a0, 2
/* DB820 80145120 AFBF0014 */  sw        $ra, 0x14($sp)
/* DB824 80145124 AFB00010 */  sw        $s0, 0x10($sp)
/* DB828 80145128 00822021 */  addu      $a0, $a0, $v0
/* DB82C 8014512C 8C900000 */  lw        $s0, ($a0)
/* DB830 80145130 3C030002 */  lui       $v1, 2
/* DB834 80145134 8E020000 */  lw        $v0, ($s0)
/* DB838 80145138 8E04001C */  lw        $a0, 0x1c($s0)
/* DB83C 8014513C 00431024 */  and       $v0, $v0, $v1
/* DB840 80145140 14400004 */  bnez      $v0, .L80145154
/* DB844 80145144 00000000 */   nop
/* DB848 80145148 0C04EA15 */  jal       func_8013A854
/* DB84C 8014514C 8C840000 */   lw       $a0, ($a0)
/* DB850 80145150 8E04001C */  lw        $a0, 0x1c($s0)
.L80145154:
/* DB854 80145154 0C00AB4B */  jal       heap_free
/* DB858 80145158 00000000 */   nop
/* DB85C 8014515C 3C03BFFC */  lui       $v1, 0xbffc
/* DB860 80145160 8E020000 */  lw        $v0, ($s0)
/* DB864 80145164 3463FFFF */  ori       $v1, $v1, 0xffff
/* DB868 80145168 AE00001C */  sw        $zero, 0x1c($s0)
/* DB86C 8014516C 00431024 */  and       $v0, $v0, $v1
/* DB870 80145170 AE020000 */  sw        $v0, ($s0)
/* DB874 80145174 8FBF0014 */  lw        $ra, 0x14($sp)
/* DB878 80145178 8FB00010 */  lw        $s0, 0x10($sp)
/* DB87C 8014517C 03E00008 */  jr        $ra
/* DB880 80145180 27BD0018 */   addiu    $sp, $sp, 0x18
