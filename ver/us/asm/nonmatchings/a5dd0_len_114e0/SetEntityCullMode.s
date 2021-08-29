.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetEntityCullMode
/* A859C 80111E9C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A85A0 80111EA0 AFB00010 */  sw        $s0, 0x10($sp)
/* A85A4 80111EA4 0080802D */  daddu     $s0, $a0, $zero
/* A85A8 80111EA8 3C048015 */  lui       $a0, %hi(gLastCreatedEntityIndex)
/* A85AC 80111EAC 8C8412EC */  lw        $a0, %lo(gLastCreatedEntityIndex)($a0)
/* A85B0 80111EB0 AFBF0014 */  sw        $ra, 0x14($sp)
/* A85B4 80111EB4 0C04417A */  jal       get_entity_by_index
/* A85B8 80111EB8 00000000 */   nop
/* A85BC 80111EBC 8E03000C */  lw        $v1, 0xc($s0)
/* A85C0 80111EC0 0200202D */  daddu     $a0, $s0, $zero
/* A85C4 80111EC4 8C650000 */  lw        $a1, ($v1)
/* A85C8 80111EC8 0C0B1EAF */  jal       evt_get_variable
/* A85CC 80111ECC 0040802D */   daddu    $s0, $v0, $zero
/* A85D0 80111ED0 0040182D */  daddu     $v1, $v0, $zero
/* A85D4 80111ED4 54600004 */  bnel      $v1, $zero, .L80111EE8
/* A85D8 80111ED8 24020001 */   addiu    $v0, $zero, 1
/* A85DC 80111EDC 8E020000 */  lw        $v0, ($s0)
/* A85E0 80111EE0 080447C5 */  j         .L80111F14
/* A85E4 80111EE4 34420002 */   ori      $v0, $v0, 2
.L80111EE8:
/* A85E8 80111EE8 14620004 */  bne       $v1, $v0, .L80111EFC
/* A85EC 80111EEC 24020002 */   addiu    $v0, $zero, 2
/* A85F0 80111EF0 8E020000 */  lw        $v0, ($s0)
/* A85F4 80111EF4 080447C4 */  j         .L80111F10
/* A85F8 80111EF8 3C030004 */   lui      $v1, 4
.L80111EFC:
/* A85FC 80111EFC 14620002 */  bne       $v1, $v0, .L80111F08
/* A8600 80111F00 3C03000C */   lui      $v1, 0xc
/* A8604 80111F04 3C030004 */  lui       $v1, 4
.L80111F08:
/* A8608 80111F08 8E020000 */  lw        $v0, ($s0)
/* A860C 80111F0C 34630002 */  ori       $v1, $v1, 2
.L80111F10:
/* A8610 80111F10 00431025 */  or        $v0, $v0, $v1
.L80111F14:
/* A8614 80111F14 AE020000 */  sw        $v0, ($s0)
/* A8618 80111F18 8FBF0014 */  lw        $ra, 0x14($sp)
/* A861C 80111F1C 8FB00010 */  lw        $s0, 0x10($sp)
/* A8620 80111F20 24020002 */  addiu     $v0, $zero, 2
/* A8624 80111F24 03E00008 */  jr        $ra
/* A8628 80111F28 27BD0018 */   addiu    $sp, $sp, 0x18
