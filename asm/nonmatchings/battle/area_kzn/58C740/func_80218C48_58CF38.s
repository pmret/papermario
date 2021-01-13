.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218C48_58CF38
/* 58CF38 80218C48 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 58CF3C 80218C4C AFB10014 */  sw        $s1, 0x14($sp)
/* 58CF40 80218C50 0080882D */  daddu     $s1, $a0, $zero
/* 58CF44 80218C54 AFBF0018 */  sw        $ra, 0x18($sp)
/* 58CF48 80218C58 AFB00010 */  sw        $s0, 0x10($sp)
/* 58CF4C 80218C5C 8E30000C */  lw        $s0, 0xc($s1)
/* 58CF50 80218C60 8E050000 */  lw        $a1, ($s0)
/* 58CF54 80218C64 0C0B1EAF */  jal       get_variable
/* 58CF58 80218C68 26100004 */   addiu    $s0, $s0, 4
/* 58CF5C 80218C6C 0040202D */  daddu     $a0, $v0, $zero
/* 58CF60 80218C70 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 58CF64 80218C74 14820002 */  bne       $a0, $v0, .L80218C80
/* 58CF68 80218C78 00000000 */   nop
/* 58CF6C 80218C7C 8E240148 */  lw        $a0, 0x148($s1)
.L80218C80:
/* 58CF70 80218C80 0C09A75B */  jal       get_actor
/* 58CF74 80218C84 00000000 */   nop
/* 58CF78 80218C88 0040202D */  daddu     $a0, $v0, $zero
/* 58CF7C 80218C8C 90830136 */  lbu       $v1, 0x136($a0)
/* 58CF80 80218C90 24020047 */  addiu     $v0, $zero, 0x47
/* 58CF84 80218C94 1062000B */  beq       $v1, $v0, .L80218CC4
/* 58CF88 80218C98 0062102A */   slt      $v0, $v1, $v0
/* 58CF8C 80218C9C 54400011 */  bnel      $v0, $zero, .L80218CE4
/* 58CF90 80218CA0 0220202D */   daddu    $a0, $s1, $zero
/* 58CF94 80218CA4 28620065 */  slti      $v0, $v1, 0x65
/* 58CF98 80218CA8 1040000D */  beqz      $v0, .L80218CE0
/* 58CF9C 80218CAC 2862004D */   slti     $v0, $v1, 0x4d
/* 58CFA0 80218CB0 1440000C */  bnez      $v0, .L80218CE4
/* 58CFA4 80218CB4 0220202D */   daddu    $a0, $s1, $zero
/* 58CFA8 80218CB8 8E050000 */  lw        $a1, ($s0)
/* 58CFAC 80218CBC 0808633B */  j         .L80218CEC
/* 58CFB0 80218CC0 2406FFFF */   addiu    $a2, $zero, -1
.L80218CC4:
/* 58CFB4 80218CC4 8C8300A8 */  lw        $v1, 0xa8($a0)
/* 58CFB8 80218CC8 24020001 */  addiu     $v0, $zero, 1
/* 58CFBC 80218CCC 14620005 */  bne       $v1, $v0, .L80218CE4
/* 58CFC0 80218CD0 0220202D */   daddu    $a0, $s1, $zero
/* 58CFC4 80218CD4 8E050000 */  lw        $a1, ($s0)
/* 58CFC8 80218CD8 0808633B */  j         .L80218CEC
/* 58CFCC 80218CDC 2406FFFF */   addiu    $a2, $zero, -1
.L80218CE0:
/* 58CFD0 80218CE0 0220202D */  daddu     $a0, $s1, $zero
.L80218CE4:
/* 58CFD4 80218CE4 8E050000 */  lw        $a1, ($s0)
/* 58CFD8 80218CE8 0000302D */  daddu     $a2, $zero, $zero
.L80218CEC:
/* 58CFDC 80218CEC 0C0B2026 */  jal       set_variable
/* 58CFE0 80218CF0 00000000 */   nop
/* 58CFE4 80218CF4 8FBF0018 */  lw        $ra, 0x18($sp)
/* 58CFE8 80218CF8 8FB10014 */  lw        $s1, 0x14($sp)
/* 58CFEC 80218CFC 8FB00010 */  lw        $s0, 0x10($sp)
/* 58CFF0 80218D00 24020002 */  addiu     $v0, $zero, 2
/* 58CFF4 80218D04 03E00008 */  jr        $ra
/* 58CFF8 80218D08 27BD0020 */   addiu    $sp, $sp, 0x20
