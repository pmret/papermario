.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80054C4C
/* 3004C 80054C4C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 30050 80054C50 00051080 */  sll       $v0, $a1, 2
/* 30054 80054C54 3C03800A */  lui       $v1, 0x800a
/* 30058 80054C58 8C63A5C0 */  lw        $v1, -0x5a40($v1)
/* 3005C 80054C5C 00A0302D */  daddu     $a2, $a1, $zero
/* 30060 80054C60 AFBF0010 */  sw        $ra, 0x10($sp)
/* 30064 80054C64 00621821 */  addu      $v1, $v1, $v0
/* 30068 80054C68 8C651310 */  lw        $a1, 0x1310($v1)
/* 3006C 80054C6C 0C0151F2 */  jal       al_LoadBank
/* 30070 80054C70 24070001 */   addiu    $a3, $zero, 1
/* 30074 80054C74 8FBF0010 */  lw        $ra, 0x10($sp)
/* 30078 80054C78 0000102D */  daddu     $v0, $zero, $zero
/* 3007C 80054C7C 03E00008 */  jr        $ra
/* 30080 80054C80 27BD0018 */   addiu    $sp, $sp, 0x18
