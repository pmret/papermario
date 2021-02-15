.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80238784_704274
/* 704274 80238784 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 704278 80238788 AFB00010 */  sw        $s0, 0x10($sp)
/* 70427C 8023878C 3C10800E */  lui       $s0, %hi(gBattleStatus+0xDC)
/* 704280 80238790 8E10C14C */  lw        $s0, %lo(gBattleStatus+0xDC)($s0)
/* 704284 80238794 AFB20018 */  sw        $s2, 0x18($sp)
/* 704288 80238798 0080902D */  daddu     $s2, $a0, $zero
/* 70428C 8023879C AFBF001C */  sw        $ra, 0x1c($sp)
/* 704290 802387A0 AFB10014 */  sw        $s1, 0x14($sp)
/* 704294 802387A4 0C09A75B */  jal       get_actor
/* 704298 802387A8 86040428 */   lh       $a0, 0x428($s0)
/* 70429C 802387AC 82050426 */  lb        $a1, 0x426($s0)
/* 7042A0 802387B0 0040802D */  daddu     $s0, $v0, $zero
/* 7042A4 802387B4 0C099117 */  jal       get_actor_part
/* 7042A8 802387B8 0200202D */   daddu    $a0, $s0, $zero
/* 7042AC 802387BC 24050005 */  addiu     $a1, $zero, 5
/* 7042B0 802387C0 8E04020C */  lw        $a0, 0x20c($s0)
/* 7042B4 802387C4 0C0997A6 */  jal       lookup_status_chance
/* 7042B8 802387C8 0040882D */   daddu    $s1, $v0, $zero
/* 7042BC 802387CC 0040202D */  daddu     $a0, $v0, $zero
/* 7042C0 802387D0 82030218 */  lb        $v1, 0x218($s0)
/* 7042C4 802387D4 2402000E */  addiu     $v0, $zero, 0xe
/* 7042C8 802387D8 50620001 */  beql      $v1, $v0, .L802387E0
/* 7042CC 802387DC 0000202D */   daddu    $a0, $zero, $zero
.L802387E0:
/* 7042D0 802387E0 8E22007C */  lw        $v0, 0x7c($s1)
/* 7042D4 802387E4 30420020 */  andi      $v0, $v0, 0x20
/* 7042D8 802387E8 54400001 */  bnel      $v0, $zero, .L802387F0
/* 7042DC 802387EC 0000202D */   daddu    $a0, $zero, $zero
.L802387F0:
/* 7042E0 802387F0 AE440084 */  sw        $a0, 0x84($s2)
/* 7042E4 802387F4 8FBF001C */  lw        $ra, 0x1c($sp)
/* 7042E8 802387F8 8FB20018 */  lw        $s2, 0x18($sp)
/* 7042EC 802387FC 8FB10014 */  lw        $s1, 0x14($sp)
/* 7042F0 80238800 8FB00010 */  lw        $s0, 0x10($sp)
/* 7042F4 80238804 24020002 */  addiu     $v0, $zero, 2
/* 7042F8 80238808 03E00008 */  jr        $ra
/* 7042FC 8023880C 27BD0020 */   addiu    $sp, $sp, 0x20
