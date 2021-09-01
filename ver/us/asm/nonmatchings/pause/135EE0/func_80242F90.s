.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242F90
/* 1362D0 80242F90 240200A0 */  addiu     $v0, $zero, 0xa0
/* 1362D4 80242F94 8FA30028 */  lw        $v1, 0x28($sp)
/* 1362D8 80242F98 00042140 */  sll       $a0, $a0, 5
/* 1362DC 80242F9C AC620000 */  sw        $v0, ($v1)
/* 1362E0 80242FA0 3C028016 */  lui       $v0, %hi(gWindows)
/* 1362E4 80242FA4 24429D50 */  addiu     $v0, $v0, %lo(gWindows)
/* 1362E8 80242FA8 00822021 */  addu      $a0, $a0, $v0
/* 1362EC 80242FAC 90820000 */  lbu       $v0, ($a0)
/* 1362F0 80242FB0 304200F3 */  andi      $v0, $v0, 0xf3
/* 1362F4 80242FB4 03E00008 */  jr        $ra
/* 1362F8 80242FB8 A0820000 */   sb       $v0, ($a0)
