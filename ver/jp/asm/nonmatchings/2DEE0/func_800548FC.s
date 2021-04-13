.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800548FC
/* 2FCFC 800548FC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 2FD00 80054900 00051080 */  sll       $v0, $a1, 2
/* 2FD04 80054904 3C03800A */  lui       $v1, %hi(D_8009A5A0)
/* 2FD08 80054908 8C63A5A0 */  lw        $v1, %lo(D_8009A5A0)($v1)
/* 2FD0C 8005490C 00A0302D */  daddu     $a2, $a1, $zero
/* 2FD10 80054910 AFBF0010 */  sw        $ra, 0x10($sp)
/* 2FD14 80054914 00621821 */  addu      $v1, $v1, $v0
/* 2FD18 80054918 8C651310 */  lw        $a1, 0x1310($v1)
/* 2FD1C 8005491C 0C01511E */  jal       func_80054478
/* 2FD20 80054920 24070001 */   addiu    $a3, $zero, 1
/* 2FD24 80054924 8FBF0010 */  lw        $ra, 0x10($sp)
/* 2FD28 80054928 0000102D */  daddu     $v0, $zero, $zero
/* 2FD2C 8005492C 03E00008 */  jr        $ra
/* 2FD30 80054930 27BD0018 */   addiu    $sp, $sp, 0x18
