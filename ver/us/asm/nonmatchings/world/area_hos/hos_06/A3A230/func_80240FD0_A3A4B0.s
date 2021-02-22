.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240FD0_A3A4B0
/* A3A4B0 80240FD0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A3A4B4 80240FD4 AFBF0010 */  sw        $ra, 0x10($sp)
/* A3A4B8 80240FD8 8C82000C */  lw        $v0, 0xc($a0)
/* A3A4BC 80240FDC 0C0B1EAF */  jal       get_variable
/* A3A4C0 80240FE0 8C450000 */   lw       $a1, ($v0)
/* A3A4C4 80240FE4 3C018024 */  lui       $at, %hi(D_802445D4_A3DAB4)
/* A3A4C8 80240FE8 AC2245D4 */  sw        $v0, %lo(D_802445D4_A3DAB4)($at)
/* A3A4CC 80240FEC 24020002 */  addiu     $v0, $zero, 2
/* A3A4D0 80240FF0 8FBF0010 */  lw        $ra, 0x10($sp)
/* A3A4D4 80240FF4 24030001 */  addiu     $v1, $zero, 1
/* A3A4D8 80240FF8 3C018024 */  lui       $at, %hi(D_802445D0_A3DAB0)
/* A3A4DC 80240FFC AC2345D0 */  sw        $v1, %lo(D_802445D0_A3DAB0)($at)
/* A3A4E0 80241000 03E00008 */  jr        $ra
/* A3A4E4 80241004 27BD0018 */   addiu    $sp, $sp, 0x18
