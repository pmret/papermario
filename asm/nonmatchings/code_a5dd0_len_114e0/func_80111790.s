.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80111790
/* A7E90 80111790 0000282D */  daddu     $a1, $zero, $zero
/* A7E94 80111794 3C048015 */  lui       $a0, 0x8015
/* A7E98 80111798 8C841470 */  lw        $a0, 0x1470($a0)
.L8011179C:
/* A7E9C 8011179C 8C820000 */  lw        $v0, ($a0)
/* A7EA0 801117A0 10400009 */  beqz      $v0, .L801117C8
/* A7EA4 801117A4 24A50001 */   addiu    $a1, $a1, 1
/* A7EA8 801117A8 8C430038 */  lw        $v1, 0x38($v0)
/* A7EAC 801117AC 8C620018 */  lw        $v0, 0x18($v1)
/* A7EB0 801117B0 10400005 */  beqz      $v0, .L801117C8
/* A7EB4 801117B4 00000000 */   nop      
/* A7EB8 801117B8 14430004 */  bne       $v0, $v1, .L801117CC
/* A7EBC 801117BC 28A2001E */   slti     $v0, $a1, 0x1e
/* A7EC0 801117C0 03E00008 */  jr        $ra
/* A7EC4 801117C4 24020001 */   addiu    $v0, $zero, 1
.L801117C8:
/* A7EC8 801117C8 28A2001E */  slti      $v0, $a1, 0x1e
.L801117CC:
/* A7ECC 801117CC 1440FFF3 */  bnez      $v0, .L8011179C
/* A7ED0 801117D0 24840004 */   addiu    $a0, $a0, 4
/* A7ED4 801117D4 03E00008 */  jr        $ra
/* A7ED8 801117D8 0000102D */   daddu    $v0, $zero, $zero
