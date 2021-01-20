.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel free_entity_model_by_ref
/* B9594 80122E94 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B9598 80122E98 0080282D */  daddu     $a1, $a0, $zero
/* B959C 80122E9C 3C038015 */  lui       $v1, %hi(gCurrentEntityModelList)
/* B95A0 80122EA0 8C634370 */  lw        $v1, %lo(gCurrentEntityModelList)($v1)
/* B95A4 80122EA4 0000202D */  daddu     $a0, $zero, $zero
/* B95A8 80122EA8 AFBF0010 */  sw        $ra, 0x10($sp)
.L80122EAC:
/* B95AC 80122EAC 8C620000 */  lw        $v0, ($v1)
/* B95B0 80122EB0 10450006 */  beq       $v0, $a1, .L80122ECC
/* B95B4 80122EB4 28820100 */   slti     $v0, $a0, 0x100
/* B95B8 80122EB8 24840001 */  addiu     $a0, $a0, 1
/* B95BC 80122EBC 28820100 */  slti      $v0, $a0, 0x100
/* B95C0 80122EC0 1440FFFA */  bnez      $v0, .L80122EAC
/* B95C4 80122EC4 24630004 */   addiu    $v1, $v1, 4
/* B95C8 80122EC8 28820100 */  slti      $v0, $a0, 0x100
.L80122ECC:
/* B95CC 80122ECC 10400003 */  beqz      $v0, .L80122EDC
/* B95D0 80122ED0 00000000 */   nop
/* B95D4 80122ED4 0C048B7F */  jal       free_entity_model_by_index
/* B95D8 80122ED8 00000000 */   nop
.L80122EDC:
/* B95DC 80122EDC 8FBF0010 */  lw        $ra, 0x10($sp)
/* B95E0 80122EE0 03E00008 */  jr        $ra
/* B95E4 80122EE4 27BD0018 */   addiu    $sp, $sp, 0x18
