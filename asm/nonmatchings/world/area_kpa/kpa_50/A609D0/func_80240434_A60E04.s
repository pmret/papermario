.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel UnkSetDurationFunc
/* A60E04 80240434 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A60E08 80240438 AFB10014 */  sw        $s1, 0x14($sp)
/* A60E0C 8024043C 0080882D */  daddu     $s1, $a0, $zero
/* A60E10 80240440 AFBF0018 */  sw        $ra, 0x18($sp)
/* A60E14 80240444 AFB00010 */  sw        $s0, 0x10($sp)
/* A60E18 80240448 8E300148 */  lw        $s0, 0x148($s1)
/* A60E1C 8024044C 0C00EABB */  jal       get_npc_unsafe
/* A60E20 80240450 86040008 */   lh       $a0, 8($s0)
/* A60E24 80240454 96030076 */  lhu       $v1, 0x76($s0)
/* A60E28 80240458 A443008E */  sh        $v1, 0x8e($v0)
/* A60E2C 8024045C 24020021 */  addiu     $v0, $zero, 0x21
/* A60E30 80240460 AE220070 */  sw        $v0, 0x70($s1)
/* A60E34 80240464 8FBF0018 */  lw        $ra, 0x18($sp)
/* A60E38 80240468 8FB10014 */  lw        $s1, 0x14($sp)
/* A60E3C 8024046C 8FB00010 */  lw        $s0, 0x10($sp)
/* A60E40 80240470 03E00008 */  jr        $ra
/* A60E44 80240474 27BD0020 */   addiu    $sp, $sp, 0x20
