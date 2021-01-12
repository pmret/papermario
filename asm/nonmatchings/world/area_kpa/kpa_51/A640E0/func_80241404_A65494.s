.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241404_A65494
/* A65494 80241404 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A65498 80241408 AFBF0014 */  sw        $ra, 0x14($sp)
/* A6549C 8024140C AFB00010 */  sw        $s0, 0x10($sp)
/* A654A0 80241410 8C900148 */  lw        $s0, 0x148($a0)
/* A654A4 80241414 0C00EABB */  jal       get_npc_unsafe
/* A654A8 80241418 86040008 */   lh       $a0, 8($s0)
/* A654AC 8024141C 0040202D */  daddu     $a0, $v0, $zero
/* A654B0 80241420 8E03006C */  lw        $v1, 0x6c($s0)
/* A654B4 80241424 24020002 */  addiu     $v0, $zero, 2
/* A654B8 80241428 14620003 */  bne       $v1, $v0, .L80241438
/* A654BC 8024142C 00000000 */   nop
/* A654C0 80241430 AC80001C */  sw        $zero, 0x1c($a0)
/* A654C4 80241434 AC800018 */  sw        $zero, 0x18($a0)
.L80241438:
/* A654C8 80241438 8FBF0014 */  lw        $ra, 0x14($sp)
/* A654CC 8024143C 8FB00010 */  lw        $s0, 0x10($sp)
/* A654D0 80241440 24020002 */  addiu     $v0, $zero, 2
/* A654D4 80241444 03E00008 */  jr        $ra
/* A654D8 80241448 27BD0018 */   addiu    $sp, $sp, 0x18
