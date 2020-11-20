.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel UnkSetDurationFunc
/* A4F4D4 802404D4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A4F4D8 802404D8 AFB10014 */  sw        $s1, 0x14($sp)
/* A4F4DC 802404DC 0080882D */  daddu     $s1, $a0, $zero
/* A4F4E0 802404E0 AFBF0018 */  sw        $ra, 0x18($sp)
/* A4F4E4 802404E4 AFB00010 */  sw        $s0, 0x10($sp)
/* A4F4E8 802404E8 8E300148 */  lw        $s0, 0x148($s1)
/* A4F4EC 802404EC 0C00EABB */  jal       get_npc_unsafe
/* A4F4F0 802404F0 86040008 */   lh       $a0, 8($s0)
/* A4F4F4 802404F4 96030076 */  lhu       $v1, 0x76($s0)
/* A4F4F8 802404F8 A443008E */  sh        $v1, 0x8e($v0)
/* A4F4FC 802404FC 24020021 */  addiu     $v0, $zero, 0x21
/* A4F500 80240500 AE220070 */  sw        $v0, 0x70($s1)
/* A4F504 80240504 8FBF0018 */  lw        $ra, 0x18($sp)
/* A4F508 80240508 8FB10014 */  lw        $s1, 0x14($sp)
/* A4F50C 8024050C 8FB00010 */  lw        $s0, 0x10($sp)
/* A4F510 80240510 03E00008 */  jr        $ra
/* A4F514 80240514 27BD0020 */   addiu    $sp, $sp, 0x20
