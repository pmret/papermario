.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel proutSprintf
/* 40948 80065548 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4094C 8006554C AFB10014 */  sw        $s1, 0x14($sp)
/* 40950 80065550 00808821 */  addu      $s1, $a0, $zero
/* 40954 80065554 AFB00010 */  sw        $s0, 0x10($sp)
/* 40958 80065558 AFBF0018 */  sw        $ra, 0x18($sp)
/* 4095C 8006555C 0C01929D */  jal       memcpy
/* 40960 80065560 00C08021 */   addu     $s0, $a2, $zero
/* 40964 80065564 02301021 */  addu      $v0, $s1, $s0
/* 40968 80065568 8FBF0018 */  lw        $ra, 0x18($sp)
/* 4096C 8006556C 8FB10014 */  lw        $s1, 0x14($sp)
/* 40970 80065570 8FB00010 */  lw        $s0, 0x10($sp)
/* 40974 80065574 03E00008 */  jr        $ra
/* 40978 80065578 27BD0020 */   addiu    $sp, $sp, 0x20
/* 4097C 8006557C 00000000 */  nop       
