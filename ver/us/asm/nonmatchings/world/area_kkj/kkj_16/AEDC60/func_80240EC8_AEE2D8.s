.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EC8_AEE2D8
/* AEE2D8 80240EC8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AEE2DC 80240ECC AFBF0010 */  sw        $ra, 0x10($sp)
/* AEE2E0 80240ED0 8C82000C */  lw        $v0, 0xc($a0)
/* AEE2E4 80240ED4 3C068011 */  lui       $a2, %hi(gPlayerStatus+0xC)
/* AEE2E8 80240ED8 80C6EFD4 */  lb        $a2, %lo(gPlayerStatus+0xC)($a2)
/* AEE2EC 80240EDC 0C0B2026 */  jal       evt_set_variable
/* AEE2F0 80240EE0 8C450000 */   lw       $a1, ($v0)
/* AEE2F4 80240EE4 8FBF0010 */  lw        $ra, 0x10($sp)
/* AEE2F8 80240EE8 24020002 */  addiu     $v0, $zero, 2
/* AEE2FC 80240EEC 03E00008 */  jr        $ra
/* AEE300 80240EF0 27BD0018 */   addiu    $sp, $sp, 0x18
