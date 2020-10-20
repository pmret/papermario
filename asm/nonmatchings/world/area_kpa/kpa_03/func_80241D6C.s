.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241D6C
/* A4A32C 80241D6C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A4A330 80241D70 AFB10014 */  sw        $s1, 0x14($sp)
/* A4A334 80241D74 0080882D */  daddu     $s1, $a0, $zero
/* A4A338 80241D78 AFBF0018 */  sw        $ra, 0x18($sp)
/* A4A33C 80241D7C AFB00010 */  sw        $s0, 0x10($sp)
/* A4A340 80241D80 8E300148 */  lw        $s0, 0x148($s1)
/* A4A344 80241D84 0C00EABB */  jal       get_npc_unsafe
/* A4A348 80241D88 86040008 */   lh       $a0, 8($s0)
/* A4A34C 80241D8C 0040182D */  daddu     $v1, $v0, $zero
/* A4A350 80241D90 240200FF */  addiu     $v0, $zero, 0xff
/* A4A354 80241D94 A06200AC */  sb        $v0, 0xac($v1)
/* A4A358 80241D98 8E0200CC */  lw        $v0, 0xcc($s0)
/* A4A35C 80241D9C 8C440008 */  lw        $a0, 8($v0)
/* A4A360 80241DA0 A460008E */  sh        $zero, 0x8e($v1)
/* A4A364 80241DA4 AC640028 */  sw        $a0, 0x28($v1)
/* A4A368 80241DA8 AE200070 */  sw        $zero, 0x70($s1)
/* A4A36C 80241DAC 8FBF0018 */  lw        $ra, 0x18($sp)
/* A4A370 80241DB0 8FB10014 */  lw        $s1, 0x14($sp)
/* A4A374 80241DB4 8FB00010 */  lw        $s0, 0x10($sp)
/* A4A378 80241DB8 24020002 */  addiu     $v0, $zero, 2
/* A4A37C 80241DBC 03E00008 */  jr        $ra
/* A4A380 80241DC0 27BD0020 */   addiu    $sp, $sp, 0x20
