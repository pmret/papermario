.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel clear_icon_flags
/* DB12C 80144A2C 2402F7FF */  addiu     $v0, $zero, -0x801
/* DB130 80144A30 00822024 */  and       $a0, $a0, $v0
/* DB134 80144A34 3C028015 */  lui       $v0, %hi(gHudElementList)
/* DB138 80144A38 8C427960 */  lw        $v0, %lo(gHudElementList)($v0)
/* DB13C 80144A3C 00042080 */  sll       $a0, $a0, 2
/* DB140 80144A40 00822021 */  addu      $a0, $a0, $v0
/* DB144 80144A44 8C830000 */  lw        $v1, ($a0)
/* DB148 80144A48 8C620000 */  lw        $v0, ($v1)
/* DB14C 80144A4C 00052827 */  nor       $a1, $zero, $a1
/* DB150 80144A50 00451024 */  and       $v0, $v0, $a1
/* DB154 80144A54 03E00008 */  jr        $ra
/* DB158 80144A58 AC620000 */   sw       $v0, ($v1)
