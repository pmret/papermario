.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242314_E18094
/* E18094 80242314 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E18098 80242318 3C05FE36 */  lui       $a1, 0xfe36
/* E1809C 8024231C 3C068011 */  lui       $a2, %hi(gPlayerData+0xC)
/* E180A0 80242320 84C6F29C */  lh        $a2, %lo(gPlayerData+0xC)($a2)
/* E180A4 80242324 AFBF0010 */  sw        $ra, 0x10($sp)
/* E180A8 80242328 0C0B2026 */  jal       set_variable
/* E180AC 8024232C 34A53C8A */   ori      $a1, $a1, 0x3c8a
/* E180B0 80242330 8FBF0010 */  lw        $ra, 0x10($sp)
/* E180B4 80242334 24020002 */  addiu     $v0, $zero, 2
/* E180B8 80242338 03E00008 */  jr        $ra
/* E180BC 8024233C 27BD0018 */   addiu    $sp, $sp, 0x18
