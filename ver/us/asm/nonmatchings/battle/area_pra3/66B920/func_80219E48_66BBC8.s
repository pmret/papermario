.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219E48_66BBC8
/* 66BBC8 80219E48 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 66BBCC 80219E4C AFB10014 */  sw        $s1, 0x14($sp)
/* 66BBD0 80219E50 0080882D */  daddu     $s1, $a0, $zero
/* 66BBD4 80219E54 AFBF0018 */  sw        $ra, 0x18($sp)
/* 66BBD8 80219E58 AFB00010 */  sw        $s0, 0x10($sp)
/* 66BBDC 80219E5C 8E30000C */  lw        $s0, 0xc($s1)
/* 66BBE0 80219E60 8E050000 */  lw        $a1, ($s0)
/* 66BBE4 80219E64 0C0B1EAF */  jal       get_variable
/* 66BBE8 80219E68 26100004 */   addiu    $s0, $s0, 4
/* 66BBEC 80219E6C 0040202D */  daddu     $a0, $v0, $zero
/* 66BBF0 80219E70 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 66BBF4 80219E74 14820002 */  bne       $a0, $v0, .L80219E80
/* 66BBF8 80219E78 00000000 */   nop
/* 66BBFC 80219E7C 8E240148 */  lw        $a0, 0x148($s1)
.L80219E80:
/* 66BC00 80219E80 0C09A75B */  jal       get_actor
/* 66BC04 80219E84 00000000 */   nop
/* 66BC08 80219E88 0040202D */  daddu     $a0, $v0, $zero
/* 66BC0C 80219E8C 90830136 */  lbu       $v1, 0x136($a0)
/* 66BC10 80219E90 24020047 */  addiu     $v0, $zero, 0x47
/* 66BC14 80219E94 1062000B */  beq       $v1, $v0, .L80219EC4
/* 66BC18 80219E98 0062102A */   slt      $v0, $v1, $v0
/* 66BC1C 80219E9C 54400011 */  bnel      $v0, $zero, .L80219EE4
/* 66BC20 80219EA0 0220202D */   daddu    $a0, $s1, $zero
/* 66BC24 80219EA4 28620065 */  slti      $v0, $v1, 0x65
/* 66BC28 80219EA8 1040000D */  beqz      $v0, .L80219EE0
/* 66BC2C 80219EAC 2862004D */   slti     $v0, $v1, 0x4d
/* 66BC30 80219EB0 1440000C */  bnez      $v0, .L80219EE4
/* 66BC34 80219EB4 0220202D */   daddu    $a0, $s1, $zero
/* 66BC38 80219EB8 8E050000 */  lw        $a1, ($s0)
/* 66BC3C 80219EBC 080867BB */  j         .L80219EEC
/* 66BC40 80219EC0 2406FFFF */   addiu    $a2, $zero, -1
.L80219EC4:
/* 66BC44 80219EC4 8C8300A8 */  lw        $v1, 0xa8($a0)
/* 66BC48 80219EC8 24020001 */  addiu     $v0, $zero, 1
/* 66BC4C 80219ECC 14620005 */  bne       $v1, $v0, .L80219EE4
/* 66BC50 80219ED0 0220202D */   daddu    $a0, $s1, $zero
/* 66BC54 80219ED4 8E050000 */  lw        $a1, ($s0)
/* 66BC58 80219ED8 080867BB */  j         .L80219EEC
/* 66BC5C 80219EDC 2406FFFF */   addiu    $a2, $zero, -1
.L80219EE0:
/* 66BC60 80219EE0 0220202D */  daddu     $a0, $s1, $zero
.L80219EE4:
/* 66BC64 80219EE4 8E050000 */  lw        $a1, ($s0)
/* 66BC68 80219EE8 0000302D */  daddu     $a2, $zero, $zero
.L80219EEC:
/* 66BC6C 80219EEC 0C0B2026 */  jal       set_variable
/* 66BC70 80219EF0 00000000 */   nop
/* 66BC74 80219EF4 8FBF0018 */  lw        $ra, 0x18($sp)
/* 66BC78 80219EF8 8FB10014 */  lw        $s1, 0x14($sp)
/* 66BC7C 80219EFC 8FB00010 */  lw        $s0, 0x10($sp)
/* 66BC80 80219F00 24020002 */  addiu     $v0, $zero, 2
/* 66BC84 80219F04 03E00008 */  jr        $ra
/* 66BC88 80219F08 27BD0020 */   addiu    $sp, $sp, 0x20
/* 66BC8C 80219F0C 00000000 */  nop
