.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802409D4_A47934
/* A47934 802409D4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A47938 802409D8 0080102D */  daddu     $v0, $a0, $zero
/* A4793C 802409DC AFB00010 */  sw        $s0, 0x10($sp)
/* A47940 802409E0 AFBF0018 */  sw        $ra, 0x18($sp)
/* A47944 802409E4 AFB10014 */  sw        $s1, 0x14($sp)
/* A47948 802409E8 8C44014C */  lw        $a0, 0x14c($v0)
/* A4794C 802409EC 8C510148 */  lw        $s1, 0x148($v0)
/* A47950 802409F0 0C00EAD2 */  jal       get_npc_safe
/* A47954 802409F4 00A0802D */   daddu    $s0, $a1, $zero
/* A47958 802409F8 56000001 */  bnel      $s0, $zero, .L80240A00
/* A4795C 802409FC A04000AB */   sb       $zero, 0xab($v0)
.L80240A00:
/* A47960 80240A00 8C420000 */  lw        $v0, ($v0)
/* A47964 80240A04 30421000 */  andi      $v0, $v0, 0x1000
/* A47968 80240A08 1040000A */  beqz      $v0, .L80240A34
/* A4796C 80240A0C 0000102D */   daddu    $v0, $zero, $zero
/* A47970 80240A10 82220004 */  lb        $v0, 4($s1)
/* A47974 80240A14 3C03800B */  lui       $v1, %hi(gCurrentEncounter)
/* A47978 80240A18 24630F10 */  addiu     $v1, $v1, %lo(gCurrentEncounter)
/* A4797C 80240A1C 00021080 */  sll       $v0, $v0, 2
/* A47980 80240A20 00431021 */  addu      $v0, $v0, $v1
/* A47984 80240A24 8C440028 */  lw        $a0, 0x28($v0)
/* A47988 80240A28 9623006E */  lhu       $v1, 0x6e($s1)
/* A4798C 80240A2C 24020002 */  addiu     $v0, $zero, 2
/* A47990 80240A30 A4830044 */  sh        $v1, 0x44($a0)
.L80240A34:
/* A47994 80240A34 8FBF0018 */  lw        $ra, 0x18($sp)
/* A47998 80240A38 8FB10014 */  lw        $s1, 0x14($sp)
/* A4799C 80240A3C 8FB00010 */  lw        $s0, 0x10($sp)
/* A479A0 80240A40 03E00008 */  jr        $ra
/* A479A4 80240A44 27BD0020 */   addiu    $sp, $sp, 0x20
/* A479A8 80240A48 00000000 */  nop       
/* A479AC 80240A4C 00000000 */  nop       
