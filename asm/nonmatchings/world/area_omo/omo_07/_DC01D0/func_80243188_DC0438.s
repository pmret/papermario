.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243188_DC0438
/* DC0438 80243188 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DC043C 8024318C AFB00010 */  sw        $s0, 0x10($sp)
/* DC0440 80243190 0080802D */  daddu     $s0, $a0, $zero
/* DC0444 80243194 AFBF0014 */  sw        $ra, 0x14($sp)
/* DC0448 80243198 8E02000C */  lw        $v0, 0xc($s0)
/* DC044C 8024319C 0C0B1EAF */  jal       get_variable
/* DC0450 802431A0 8C450000 */   lw       $a1, ($v0)
/* DC0454 802431A4 00021140 */  sll       $v0, $v0, 5
/* DC0458 802431A8 AE000084 */  sw        $zero, 0x84($s0)
/* DC045C 802431AC 3C018008 */  lui       $at, 0x8008
/* DC0460 802431B0 00220821 */  addu      $at, $at, $v0
/* DC0464 802431B4 942278F8 */  lhu       $v0, 0x78f8($at)
/* DC0468 802431B8 30420040 */  andi      $v0, $v0, 0x40
/* DC046C 802431BC 10400002 */  beqz      $v0, .L802431C8
/* DC0470 802431C0 24020001 */   addiu    $v0, $zero, 1
/* DC0474 802431C4 AE020084 */  sw        $v0, 0x84($s0)
.L802431C8:
/* DC0478 802431C8 8FBF0014 */  lw        $ra, 0x14($sp)
/* DC047C 802431CC 8FB00010 */  lw        $s0, 0x10($sp)
/* DC0480 802431D0 24020002 */  addiu     $v0, $zero, 2
/* DC0484 802431D4 03E00008 */  jr        $ra
/* DC0488 802431D8 27BD0018 */   addiu    $sp, $sp, 0x18
