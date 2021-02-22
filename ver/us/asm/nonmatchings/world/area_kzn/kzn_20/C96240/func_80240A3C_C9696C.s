.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A3C_C9696C
/* C9696C 80240A3C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C96970 80240A40 AFBF0010 */  sw        $ra, 0x10($sp)
/* C96974 80240A44 0C00EABB */  jal       get_npc_unsafe
/* C96978 80240A48 8C84008C */   lw       $a0, 0x8c($a0)
/* C9697C 80240A4C 3C038024 */  lui       $v1, %hi(D_80244494)
/* C96980 80240A50 8C634494 */  lw        $v1, %lo(D_80244494)($v1)
/* C96984 80240A54 AC430028 */  sw        $v1, 0x28($v0)
/* C96988 80240A58 8FBF0010 */  lw        $ra, 0x10($sp)
/* C9698C 80240A5C 24020002 */  addiu     $v0, $zero, 2
/* C96990 80240A60 03E00008 */  jr        $ra
/* C96994 80240A64 27BD0018 */   addiu    $sp, $sp, 0x18
