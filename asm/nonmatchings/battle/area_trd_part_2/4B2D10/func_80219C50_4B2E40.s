.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219C50_4B2E40
/* 4B2E40 80219C50 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4B2E44 80219C54 AFB00010 */  sw        $s0, 0x10($sp)
/* 4B2E48 80219C58 0080802D */  daddu     $s0, $a0, $zero
/* 4B2E4C 80219C5C AFBF0014 */  sw        $ra, 0x14($sp)
/* 4B2E50 80219C60 0C09A75B */  jal       get_actor
/* 4B2E54 80219C64 24040200 */   addiu    $a0, $zero, 0x200
/* 4B2E58 80219C68 0040202D */  daddu     $a0, $v0, $zero
/* 4B2E5C 80219C6C 10800004 */  beqz      $a0, .L80219C80
/* 4B2E60 80219C70 00000000 */   nop
/* 4B2E64 80219C74 8C82008C */  lw        $v0, 0x8c($a0)
/* 4B2E68 80219C78 10500019 */  beq       $v0, $s0, .L80219CE0
/* 4B2E6C 80219C7C 0080102D */   daddu    $v0, $a0, $zero
.L80219C80:
/* 4B2E70 80219C80 0C09A75B */  jal       get_actor
/* 4B2E74 80219C84 24040201 */   addiu    $a0, $zero, 0x201
/* 4B2E78 80219C88 0040202D */  daddu     $a0, $v0, $zero
/* 4B2E7C 80219C8C 10800004 */  beqz      $a0, .L80219CA0
/* 4B2E80 80219C90 00000000 */   nop
/* 4B2E84 80219C94 8C82008C */  lw        $v0, 0x8c($a0)
/* 4B2E88 80219C98 10500011 */  beq       $v0, $s0, .L80219CE0
/* 4B2E8C 80219C9C 0080102D */   daddu    $v0, $a0, $zero
.L80219CA0:
/* 4B2E90 80219CA0 0C09A75B */  jal       get_actor
/* 4B2E94 80219CA4 24040202 */   addiu    $a0, $zero, 0x202
/* 4B2E98 80219CA8 0040202D */  daddu     $a0, $v0, $zero
/* 4B2E9C 80219CAC 10800004 */  beqz      $a0, .L80219CC0
/* 4B2EA0 80219CB0 00000000 */   nop
/* 4B2EA4 80219CB4 8C82008C */  lw        $v0, 0x8c($a0)
/* 4B2EA8 80219CB8 10500009 */  beq       $v0, $s0, .L80219CE0
/* 4B2EAC 80219CBC 0080102D */   daddu    $v0, $a0, $zero
.L80219CC0:
/* 4B2EB0 80219CC0 0C09A75B */  jal       get_actor
/* 4B2EB4 80219CC4 24040203 */   addiu    $a0, $zero, 0x203
/* 4B2EB8 80219CC8 0040202D */  daddu     $a0, $v0, $zero
/* 4B2EBC 80219CCC 50800004 */  beql      $a0, $zero, .L80219CE0
/* 4B2EC0 80219CD0 0000102D */   daddu    $v0, $zero, $zero
/* 4B2EC4 80219CD4 8C83008C */  lw        $v1, 0x8c($a0)
/* 4B2EC8 80219CD8 54700001 */  bnel      $v1, $s0, .L80219CE0
/* 4B2ECC 80219CDC 0000102D */   daddu    $v0, $zero, $zero
.L80219CE0:
/* 4B2ED0 80219CE0 8FBF0014 */  lw        $ra, 0x14($sp)
/* 4B2ED4 80219CE4 8FB00010 */  lw        $s0, 0x10($sp)
/* 4B2ED8 80219CE8 03E00008 */  jr        $ra
/* 4B2EDC 80219CEC 27BD0018 */   addiu    $sp, $sp, 0x18
