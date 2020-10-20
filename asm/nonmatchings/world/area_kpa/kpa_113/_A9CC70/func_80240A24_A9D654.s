.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A24_A9D654
/* A9D654 80240A24 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A9D658 80240A28 0080102D */  daddu     $v0, $a0, $zero
/* A9D65C 80240A2C AFB00010 */  sw        $s0, 0x10($sp)
/* A9D660 80240A30 AFBF0018 */  sw        $ra, 0x18($sp)
/* A9D664 80240A34 AFB10014 */  sw        $s1, 0x14($sp)
/* A9D668 80240A38 8C44014C */  lw        $a0, 0x14c($v0)
/* A9D66C 80240A3C 8C510148 */  lw        $s1, 0x148($v0)
/* A9D670 80240A40 0C00EAD2 */  jal       get_npc_safe
/* A9D674 80240A44 00A0802D */   daddu    $s0, $a1, $zero
/* A9D678 80240A48 56000001 */  bnel      $s0, $zero, .L80240A50
/* A9D67C 80240A4C A04000AB */   sb       $zero, 0xab($v0)
.L80240A50:
/* A9D680 80240A50 8C420000 */  lw        $v0, ($v0)
/* A9D684 80240A54 30421000 */  andi      $v0, $v0, 0x1000
/* A9D688 80240A58 1040000A */  beqz      $v0, .L80240A84
/* A9D68C 80240A5C 0000102D */   daddu    $v0, $zero, $zero
/* A9D690 80240A60 82220004 */  lb        $v0, 4($s1)
/* A9D694 80240A64 3C03800B */  lui       $v1, %hi(gCurrentEncounter)
/* A9D698 80240A68 24630F10 */  addiu     $v1, $v1, %lo(gCurrentEncounter)
/* A9D69C 80240A6C 00021080 */  sll       $v0, $v0, 2
/* A9D6A0 80240A70 00431021 */  addu      $v0, $v0, $v1
/* A9D6A4 80240A74 8C440028 */  lw        $a0, 0x28($v0)
/* A9D6A8 80240A78 9623006E */  lhu       $v1, 0x6e($s1)
/* A9D6AC 80240A7C 24020002 */  addiu     $v0, $zero, 2
/* A9D6B0 80240A80 A4830044 */  sh        $v1, 0x44($a0)
.L80240A84:
/* A9D6B4 80240A84 8FBF0018 */  lw        $ra, 0x18($sp)
/* A9D6B8 80240A88 8FB10014 */  lw        $s1, 0x14($sp)
/* A9D6BC 80240A8C 8FB00010 */  lw        $s0, 0x10($sp)
/* A9D6C0 80240A90 03E00008 */  jr        $ra
/* A9D6C4 80240A94 27BD0020 */   addiu    $sp, $sp, 0x20
/* A9D6C8 80240A98 00000000 */  nop       
/* A9D6CC 80240A9C 00000000 */  nop       
