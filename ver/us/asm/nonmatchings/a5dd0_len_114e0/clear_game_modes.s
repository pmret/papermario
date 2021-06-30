.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel clear_game_modes
/* A9298 80112B98 3C038015 */  lui       $v1, %hi(gMainGameState)
/* A929C 80112B9C 24631700 */  addiu     $v1, $v1, %lo(gMainGameState)
/* A92A0 80112BA0 24020001 */  addiu     $v0, $zero, 1
.L80112BA4:
/* A92A4 80112BA4 A4600000 */  sh        $zero, ($v1)
/* A92A8 80112BA8 2442FFFF */  addiu     $v0, $v0, -1
/* A92AC 80112BAC 0441FFFD */  bgez      $v0, .L80112BA4
/* A92B0 80112BB0 24630018 */   addiu    $v1, $v1, 0x18
/* A92B4 80112BB4 03E00008 */  jr        $ra
/* A92B8 80112BB8 00000000 */   nop
