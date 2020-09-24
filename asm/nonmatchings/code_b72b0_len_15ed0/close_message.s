.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel close_message
/* BC370 80125C70 8C8204FC */  lw        $v0, 0x4fc($a0)
/* BC374 80125C74 2403FFBF */  addiu     $v1, $zero, -0x41
/* BC378 80125C78 00431024 */  and       $v0, $v0, $v1
/* BC37C 80125C7C 03E00008 */  jr        $ra
/* BC380 80125C80 AC8204FC */   sw       $v0, 0x4fc($a0)
