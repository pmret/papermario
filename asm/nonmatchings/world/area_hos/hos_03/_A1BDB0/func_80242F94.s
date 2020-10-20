.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242F94
/* A1E094 80242F94 3C028025 */  lui       $v0, 0x8025
/* A1E098 80242F98 8C42BDF8 */  lw        $v0, -0x4208($v0)
/* A1E09C 80242F9C 8C42000C */  lw        $v0, 0xc($v0)
/* A1E0A0 80242FA0 AC40001C */  sw        $zero, 0x1c($v0)
/* A1E0A4 80242FA4 03E00008 */  jr        $ra
/* A1E0A8 80242FA8 24020002 */   addiu    $v0, $zero, 2
