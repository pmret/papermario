.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802409D4_A48F94
/* A48F94 802409D4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A48F98 802409D8 0080102D */  daddu     $v0, $a0, $zero
/* A48F9C 802409DC AFB00010 */  sw        $s0, 0x10($sp)
/* A48FA0 802409E0 AFBF0018 */  sw        $ra, 0x18($sp)
/* A48FA4 802409E4 AFB10014 */  sw        $s1, 0x14($sp)
/* A48FA8 802409E8 8C44014C */  lw        $a0, 0x14c($v0)
/* A48FAC 802409EC 8C510148 */  lw        $s1, 0x148($v0)
/* A48FB0 802409F0 0C00EAD2 */  jal       get_npc_safe
/* A48FB4 802409F4 00A0802D */   daddu    $s0, $a1, $zero
/* A48FB8 802409F8 56000001 */  bnel      $s0, $zero, .L80240A00
/* A48FBC 802409FC A04000AB */   sb       $zero, 0xab($v0)
.L80240A00:
/* A48FC0 80240A00 8C420000 */  lw        $v0, ($v0)
/* A48FC4 80240A04 30421000 */  andi      $v0, $v0, 0x1000
/* A48FC8 80240A08 1040000A */  beqz      $v0, .L80240A34
/* A48FCC 80240A0C 0000102D */   daddu    $v0, $zero, $zero
/* A48FD0 80240A10 82220004 */  lb        $v0, 4($s1)
/* A48FD4 80240A14 3C03800B */  lui       $v1, %hi(gCurrentEncounter)
/* A48FD8 80240A18 24630F10 */  addiu     $v1, $v1, %lo(gCurrentEncounter)
/* A48FDC 80240A1C 00021080 */  sll       $v0, $v0, 2
/* A48FE0 80240A20 00431021 */  addu      $v0, $v0, $v1
/* A48FE4 80240A24 8C440028 */  lw        $a0, 0x28($v0)
/* A48FE8 80240A28 9623006E */  lhu       $v1, 0x6e($s1)
/* A48FEC 80240A2C 24020002 */  addiu     $v0, $zero, 2
/* A48FF0 80240A30 A4830044 */  sh        $v1, 0x44($a0)
.L80240A34:
/* A48FF4 80240A34 8FBF0018 */  lw        $ra, 0x18($sp)
/* A48FF8 80240A38 8FB10014 */  lw        $s1, 0x14($sp)
/* A48FFC 80240A3C 8FB00010 */  lw        $s0, 0x10($sp)
/* A49000 80240A40 03E00008 */  jr        $ra
/* A49004 80240A44 27BD0020 */   addiu    $sp, $sp, 0x20
