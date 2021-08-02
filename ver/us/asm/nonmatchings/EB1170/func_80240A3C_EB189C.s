.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A3C_EB189C
/* EB189C 80240A3C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EB18A0 80240A40 AFBF0010 */  sw        $ra, 0x10($sp)
/* EB18A4 80240A44 0C00F92F */  jal       dead_get_npc_unsafe
/* EB18A8 80240A48 8C84008C */   lw       $a0, 0x8c($a0)
/* EB18AC 80240A4C 3C038024 */  lui       $v1, %hi(D_80244494)
/* EB18B0 80240A50 8C634494 */  lw        $v1, %lo(D_80244494)($v1)
/* EB18B4 80240A54 AC430028 */  sw        $v1, 0x28($v0)
/* EB18B8 80240A58 8FBF0010 */  lw        $ra, 0x10($sp)
/* EB18BC 80240A5C 24020002 */  addiu     $v0, $zero, 2
/* EB18C0 80240A60 03E00008 */  jr        $ra
/* EB18C4 80240A64 27BD0018 */   addiu    $sp, $sp, 0x18
