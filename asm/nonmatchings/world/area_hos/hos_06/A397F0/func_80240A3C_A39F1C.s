.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A3C_A39F1C
/* A39F1C 80240A3C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A39F20 80240A40 AFBF0010 */  sw        $ra, 0x10($sp)
/* A39F24 80240A44 0C00EABB */  jal       get_npc_unsafe
/* A39F28 80240A48 8C84008C */   lw       $a0, 0x8c($a0)
/* A39F2C 80240A4C 3C038024 */  lui       $v1, %hi(D_80246424)
/* A39F30 80240A50 8C636424 */  lw        $v1, %lo(D_80246424)($v1)
/* A39F34 80240A54 AC430028 */  sw        $v1, 0x28($v0)
/* A39F38 80240A58 8FBF0010 */  lw        $ra, 0x10($sp)
/* A39F3C 80240A5C 24020002 */  addiu     $v0, $zero, 2
/* A39F40 80240A60 03E00008 */  jr        $ra
/* A39F44 80240A64 27BD0018 */   addiu    $sp, $sp, 0x18
