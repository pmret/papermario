.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80049550
/* 24950 80049550 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 24954 80049554 AFB00010 */  sw        $s0, 0x10($sp)
/* 24958 80049558 0080802D */  daddu     $s0, $a0, $zero
/* 2495C 8004955C AFBF0018 */  sw        $ra, 0x18($sp)
/* 24960 80049560 AFB10014 */  sw        $s1, 0x14($sp)
/* 24964 80049564 8E020148 */  lw        $v0, 0x148($s0)
/* 24968 80049568 84440008 */  lh        $a0, 8($v0)
/* 2496C 8004956C 0C00EABB */  jal       get_npc_unsafe
/* 24970 80049570 00A0882D */   daddu    $s1, $a1, $zero
/* 24974 80049574 9443008E */  lhu       $v1, 0x8e($v0)
/* 24978 80049578 2463FFFF */  addiu     $v1, $v1, -1
/* 2497C 8004957C A443008E */  sh        $v1, 0x8e($v0)
/* 24980 80049580 00031C00 */  sll       $v1, $v1, 0x10
/* 24984 80049584 58600001 */  blezl     $v1, .L8004958C
/* 24988 80049588 AE110070 */   sw       $s1, 0x70($s0)
.L8004958C:
/* 2498C 8004958C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 24990 80049590 8FB10014 */  lw        $s1, 0x14($sp)
/* 24994 80049594 8FB00010 */  lw        $s0, 0x10($sp)
/* 24998 80049598 03E00008 */  jr        $ra
/* 2499C 8004959C 27BD0020 */   addiu    $sp, $sp, 0x20
