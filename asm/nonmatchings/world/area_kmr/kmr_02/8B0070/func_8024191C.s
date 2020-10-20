.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024191C
/* 8B198C 8024191C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8B1990 80241920 AFB00010 */  sw        $s0, 0x10($sp)
/* 8B1994 80241924 0080802D */  daddu     $s0, $a0, $zero
/* 8B1998 80241928 AFBF0014 */  sw        $ra, 0x14($sp)
/* 8B199C 8024192C 8E020148 */  lw        $v0, 0x148($s0)
/* 8B19A0 80241930 0C00EABB */  jal       get_npc_unsafe
/* 8B19A4 80241934 84440008 */   lh       $a0, 8($v0)
/* 8B19A8 80241938 9443008E */  lhu       $v1, 0x8e($v0)
/* 8B19AC 8024193C 2463FFFF */  addiu     $v1, $v1, -1
/* 8B19B0 80241940 A443008E */  sh        $v1, 0x8e($v0)
/* 8B19B4 80241944 00031C00 */  sll       $v1, $v1, 0x10
/* 8B19B8 80241948 14600002 */  bnez      $v1, .L80241954
/* 8B19BC 8024194C 2402000F */   addiu    $v0, $zero, 0xf
/* 8B19C0 80241950 AE020070 */  sw        $v0, 0x70($s0)
.L80241954:
/* 8B19C4 80241954 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8B19C8 80241958 8FB00010 */  lw        $s0, 0x10($sp)
/* 8B19CC 8024195C 03E00008 */  jr        $ra
/* 8B19D0 80241960 27BD0018 */   addiu    $sp, $sp, 0x18
