.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80283BD0
/* 7E4A50 80283BD0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7E4A54 80283BD4 AFB00010 */  sw        $s0, 0x10($sp)
/* 7E4A58 80283BD8 0080802D */  daddu     $s0, $a0, $zero
/* 7E4A5C 80283BDC AFB10014 */  sw        $s1, 0x14($sp)
/* 7E4A60 80283BE0 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* 7E4A64 80283BE4 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* 7E4A68 80283BE8 AFBF0018 */  sw        $ra, 0x18($sp)
/* 7E4A6C 80283BEC 10A00008 */  beqz      $a1, .L80283C10
/* 7E4A70 80283BF0 8E02000C */   lw       $v0, 0xc($s0)
/* 7E4A74 80283BF4 0C0B1EAF */  jal       get_variable
/* 7E4A78 80283BF8 8C450000 */   lw       $a1, ($v0)
/* 7E4A7C 80283BFC AE020070 */  sw        $v0, 0x70($s0)
/* 7E4A80 80283C00 8E250080 */  lw        $a1, 0x80($s1)
/* 7E4A84 80283C04 8E26005C */  lw        $a2, 0x5c($s1)
/* 7E4A88 80283C08 0C0389DE */  jal       move_player
/* 7E4A8C 80283C0C 0040202D */   daddu    $a0, $v0, $zero
.L80283C10:
/* 7E4A90 80283C10 8E030070 */  lw        $v1, 0x70($s0)
/* 7E4A94 80283C14 2463FFFF */  addiu     $v1, $v1, -1
/* 7E4A98 80283C18 AE030070 */  sw        $v1, 0x70($s0)
/* 7E4A9C 80283C1C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 7E4AA0 80283C20 8FB10014 */  lw        $s1, 0x14($sp)
/* 7E4AA4 80283C24 8FB00010 */  lw        $s0, 0x10($sp)
/* 7E4AA8 80283C28 000317C2 */  srl       $v0, $v1, 0x1f
/* 7E4AAC 80283C2C 03E00008 */  jr        $ra
/* 7E4AB0 80283C30 27BD0020 */   addiu    $sp, $sp, 0x20
