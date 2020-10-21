.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242FAC_A1E0AC
/* A1E0AC 80242FAC 3C028025 */  lui       $v0, 0x8025
/* A1E0B0 80242FB0 8C42BDF8 */  lw        $v0, -0x4208($v0)
/* A1E0B4 80242FB4 8C43000C */  lw        $v1, 0xc($v0)
/* A1E0B8 80242FB8 24020001 */  addiu     $v0, $zero, 1
/* A1E0BC 80242FBC AC62001C */  sw        $v0, 0x1c($v1)
/* A1E0C0 80242FC0 03E00008 */  jr        $ra
/* A1E0C4 80242FC4 24020002 */   addiu    $v0, $zero, 2
