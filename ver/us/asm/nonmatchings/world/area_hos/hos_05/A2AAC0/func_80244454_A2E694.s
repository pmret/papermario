.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80244454_A2E694
/* A2E694 80244454 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A2E698 80244458 3C058025 */  lui       $a1, %hi(D_8024ACB8_A34EF8)
/* A2E69C 8024445C 24A5ACB8 */  addiu     $a1, $a1, %lo(D_8024ACB8_A34EF8)
/* A2E6A0 80244460 AFBF0014 */  sw        $ra, 0x14($sp)
/* A2E6A4 80244464 AFB00010 */  sw        $s0, 0x10($sp)
/* A2E6A8 80244468 8CA40000 */  lw        $a0, ($a1)
/* A2E6AC 8024446C 1480000B */  bnez      $a0, .L8024449C
/* A2E6B0 80244470 3C028888 */   lui      $v0, 0x8888
/* A2E6B4 80244474 3C108025 */  lui       $s0, %hi(D_8024AA20_A34C60)
/* A2E6B8 80244478 2610AA20 */  addiu     $s0, $s0, %lo(D_8024AA20_A34C60)
/* A2E6BC 8024447C 8E020000 */  lw        $v0, ($s0)
/* A2E6C0 80244480 8C440000 */  lw        $a0, ($v0)
/* A2E6C4 80244484 0C048D70 */  jal       free_generic_entity
/* A2E6C8 80244488 A440005C */   sh       $zero, 0x5c($v0)
/* A2E6CC 8024448C 8E030000 */  lw        $v1, ($s0)
/* A2E6D0 80244490 24020001 */  addiu     $v0, $zero, 1
/* A2E6D4 80244494 08091136 */  j         .L802444D8
/* A2E6D8 80244498 AC600000 */   sw       $zero, ($v1)
.L8024449C:
/* A2E6DC 8024449C 34428889 */  ori       $v0, $v0, 0x8889
/* A2E6E0 802444A0 2484FFFF */  addiu     $a0, $a0, -1
/* A2E6E4 802444A4 00041A00 */  sll       $v1, $a0, 8
/* A2E6E8 802444A8 00641823 */  subu      $v1, $v1, $a0
/* A2E6EC 802444AC 00620018 */  mult      $v1, $v0
/* A2E6F0 802444B0 0000102D */  daddu     $v0, $zero, $zero
/* A2E6F4 802444B4 ACA40000 */  sw        $a0, ($a1)
/* A2E6F8 802444B8 3C058025 */  lui       $a1, %hi(D_8024AA20_A34C60)
/* A2E6FC 802444BC 8CA5AA20 */  lw        $a1, %lo(D_8024AA20_A34C60)($a1)
/* A2E700 802444C0 00003010 */  mfhi      $a2
/* A2E704 802444C4 00C32021 */  addu      $a0, $a2, $v1
/* A2E708 802444C8 00042103 */  sra       $a0, $a0, 4
/* A2E70C 802444CC 00031FC3 */  sra       $v1, $v1, 0x1f
/* A2E710 802444D0 00832023 */  subu      $a0, $a0, $v1
/* A2E714 802444D4 A4A4005C */  sh        $a0, 0x5c($a1)
.L802444D8:
/* A2E718 802444D8 8FBF0014 */  lw        $ra, 0x14($sp)
/* A2E71C 802444DC 8FB00010 */  lw        $s0, 0x10($sp)
/* A2E720 802444E0 03E00008 */  jr        $ra
/* A2E724 802444E4 27BD0018 */   addiu    $sp, $sp, 0x18
