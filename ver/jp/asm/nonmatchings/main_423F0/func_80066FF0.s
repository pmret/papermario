.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80066FF0
/* 423F0 80066FF0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 423F4 80066FF4 AFB00010 */  sw        $s0, 0x10($sp)
/* 423F8 80066FF8 AFBF0014 */  sw        $ra, 0x14($sp)
/* 423FC 80066FFC 0C01ACD0 */  jal       func_8006B340
/* 42400 80067000 00808021 */   addu     $s0, $a0, $zero
/* 42404 80067004 3C048009 */  lui       $a0, %hi(D_80095964)
/* 42408 80067008 8C845964 */  lw        $a0, %lo(D_80095964)($a0)
/* 4240C 8006700C 94830000 */  lhu       $v1, ($a0)
/* 42410 80067010 AC900004 */  sw        $s0, 4($a0)
/* 42414 80067014 34630010 */  ori       $v1, $v1, 0x10
/* 42418 80067018 A4830000 */  sh        $v1, ($a0)
/* 4241C 8006701C 0C01ACEC */  jal       func_8006B3B0
/* 42420 80067020 00402021 */   addu     $a0, $v0, $zero
/* 42424 80067024 8FBF0014 */  lw        $ra, 0x14($sp)
/* 42428 80067028 8FB00010 */  lw        $s0, 0x10($sp)
/* 4242C 8006702C 03E00008 */  jr        $ra
/* 42430 80067030 27BD0018 */   addiu    $sp, $sp, 0x18
/* 42434 80067034 00000000 */  nop
/* 42438 80067038 00000000 */  nop
/* 4243C 8006703C 00000000 */  nop
