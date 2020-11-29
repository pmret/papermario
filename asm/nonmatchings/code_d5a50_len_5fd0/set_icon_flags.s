.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel set_icon_flags
/* DB100 80144A00 2402F7FF */  addiu     $v0, $zero, -0x801
/* DB104 80144A04 00822024 */  and       $a0, $a0, $v0
/* DB108 80144A08 3C028015 */  lui       $v0, %hi(D_80157960)
/* DB10C 80144A0C 8C427960 */  lw        $v0, %lo(D_80157960)($v0)
/* DB110 80144A10 00042080 */  sll       $a0, $a0, 2
/* DB114 80144A14 00822021 */  addu      $a0, $a0, $v0
/* DB118 80144A18 8C830000 */  lw        $v1, ($a0)
/* DB11C 80144A1C 8C620000 */  lw        $v0, ($v1)
/* DB120 80144A20 00451025 */  or        $v0, $v0, $a1
/* DB124 80144A24 03E00008 */  jr        $ra
/* DB128 80144A28 AC620000 */   sw       $v0, ($v1)
